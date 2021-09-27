#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80 //The size of the array

enum ExpType
{
    OPT,
    OPERAND
};

typedef struct _stackNode
{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int item;
    enum ExpType type;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList(LinkedList ll);

void in2PreLL(char *infix, LinkedList *inExpLL);
char *reverse(char *string);
int precedence(char operator);
void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void in2PreLL(char *infix, LinkedList *inExpLL)
{
    Stack s;
    s.head = NULL;
    s.size = 0;
    char prefix[SIZE];
    int i, j = 0;
    infix = reverse(infix);
    for (i = 0; i < strlen(infix); i++)
    {
        if (precedence(infix[i]) == -2)
            prefix[j++] = infix[i];
        else
        {
            prefix[j++] = ' ';
            if (isEmptyStack(s))
                push(&s, infix[i]);
            else
            {
                if (precedence(infix[i]) == 0)
                    push(&s, infix[i]);
                else if (precedence(infix[i]) == -1)
                {
                    while (peek(s) != '(')
                    {
                        prefix[j++] = peek(s);
                        pop(&s);
                    }
                    pop(&s);
                }
                else
                {
                    while (!isEmptyStack(s) && peek(s) != '(' && precedence(peek(s)) > precedence(infix[i]))
                    {
                        prefix[j++] = peek(s);
                        pop(&s);
                    }
                    push(&s, infix[i]);
                }
            }
        }
    }
    while (!isEmptyStack(s))
    {
        prefix[j++] = peek(s);
        pop(&s);
    }
    prefix[j] = '\0';
    j = 0;
    char temp[SIZE];
    int magnitude, temp_value;
    while (prefix[j])
    {
        if (precedence((prefix[j])) >= 1)
            insertNode(inExpLL, prefix[j++], OPT);
        else if (isdigit(prefix[j]))
        {
            char temp2[2];
            magnitude = 10;
            temp2[0] = prefix[j++];
            temp2[1] = '\0';
            temp_value = atoi(temp2);
            while (isdigit(prefix[j]))
            {
                temp2[0] = prefix[j];
                temp2[1] = '\0';
                temp_value += atoi(temp2) * magnitude;
                magnitude *= 10;
                j++;
            }
            insertNode(inExpLL, temp_value, OPERAND);
        }
        else
            j++;
    }
}

char *reverse(char *string)
{
    char temp;
    int i = 0, j = strlen(string) - 1;
    while (i < j)
    {
        temp = string[i];
        if (temp == '(')
            temp = ')';
        else if (temp == ')')
            temp = '(';
        if (string[j] == '(')
            string[j] = ')';
        else if (string[j] == ')')
            string[j] = '(';
        string[i++] = string[j];
        string[j--] = temp;
    }
    return string;
}

int precedence(char operator)
{
    switch (operator)
    {
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    case '(':
        return 0;
    case ')':
        return -1;
    default:
        return -2;
    }
}

void printExpLL(LinkedList inExpLL)
{
    ListNode *temp = NULL;
    temp = inExpLL.head;
    while (temp != NULL)
    {
        if (temp->type == OPERAND)
            printf(" %d ", temp->item);
        else
            printf(" %c ", (char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type)
{
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
        exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head = newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr)
{
    if (LLPtr == NULL || LLPtr->size == 0)
    {
        return 0;
    }
    else
    {
        ListNode *temp = LLPtr->head;
        LLPtr->head = LLPtr->head->next;

        free(temp);
        LLPtr->size--;
        return 1;
    }
}

int isEmptyLinkedList(LinkedList ll)
{
    if (ll.size == 0)
        return 1;
    else
        return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
    while (deleteNode(LLPtr))
        ;
}

void push(Stack *sPtr, char item)
{
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if (sPtr == NULL || sPtr->head == NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

char peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}