#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);
int precedence(char op);

void in2PreLL(char* infix, LinkedList *inExpLL);

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

void in2PreLL(char* infix, LinkedList *inExpLL)
{
    //Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;

    char revInfix[SIZE];
    char revPrefix[SIZE];
    char temp[2];
    int i=0, j = 0, count =0, count2, temp_value, tens_value, repeat;
    char c;


    //reverse the string
    while(infix[count] != '\0')
        count++;
        
    count2 = 0;

    while(count != 0)
    {
        if (infix[count] == '*' || infix[count] == '/' || infix[count] == '+' || infix[count] == '-')
        {
            revInfix[count2] = ' ';
            count2++;
        }
        revInfix[count2] = infix[count-1];
        count--;
        count2++;
    }
    revInfix[count2] = '\0';

    i = 0;
    while(i < SIZE && revInfix[i] != '\0')
        {
            c = revInfix[i++];
            switch(c)
            {
            case '*': //operators
            case '/':
            case '+':
            case '-':
                while(isEmptyStack(s)==0 && peek(s) != ')' && precedence(peek(s)) > precedence(c) ) //note the precedence comparison
                {
                    revPrefix[j++] = peek(s);
                    pop(&s);
                }
                push(&s,c);
                break;
            case ')':
                push(&s,c);
                break;
            case '(':
                while(isEmptyStack(s)==0)
                {
                    if(peek(s)!=')')
                    {
                        revPrefix[j++]=peek(s);
                        pop(&s);
                    }
                    else
                    {
                        pop(&s);
                        break;
                    }
                }
                break;
            default: //operand
                revPrefix[j++] = c;
            }
        }

        while(isEmptyStack(s)==0)
        {
            revPrefix[j++] = peek(s);
            pop(&s);
        }
        revPrefix[j] = '\0';
        //printf("revPrefix: %s\n", revPrefix);

    //reverse the string
    count = 0;
    while(revPrefix[count] != '\0')
    {
        if (revPrefix[count] == ' ')
        {
            count++;
        }

        else if(!isdigit(revPrefix[count]))
        {
            insertNode(inExpLL, revPrefix[count], OPT);
            count++;
        }

        else
        {
            tens_value = 10;
            temp[0] = revPrefix[count];
            temp[1] = '\0';
            count++;
            temp_value = atoi(temp);
            repeat = 0;
            while (isdigit(revPrefix[count]))
            {
                repeat++;
                temp[0] = revPrefix[count];
                temp[1] = '\0';
                //printf("atoi(temp): %d\n", atoi(temp));
                temp_value = temp_value + (tens_value * atoi(temp));
                tens_value = tens_value * 10;
                //printf("tens_value: %d\n", tens_value);
                //printf("temp_value: %d\n", temp_value);
                count++;
            }
            //printf("temp_value outside: %d\n", temp_value);
            //printf("repeat: %d\n", repeat);
            insertNode(inExpLL, temp_value, OPERAND);
        }
    }
}

int precedence(char op)
{
    if(op == '*' || op == '/')
        return 1;
    else return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}