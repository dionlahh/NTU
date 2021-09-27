#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

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

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);

void expressionLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExpQ, int seed);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    expressionLL(infix, &inExpLL);

    int seed;
    //printf("Enter a seed: \n");
    scanf("%d",&seed);
    printExpLL(inExpLL,seed);

    removeAllNodes(&inExpLL);
    return 0;
}


void expressionLL(char* infix, LinkedList *inExpLL)
{
    //Write your code here
    int count=0, i= 0, j, count2, len;
    char revInfix[SIZE];
    char temp[2];
    int repeat, temp_val, tens_value;

    len = strlen(infix);

    while (len != 0)
    {
        revInfix[i] = infix[len-1];
        i++;
        len--;
    }
    revInfix[i] = '\0';

    while(revInfix[count] != '\0')
    {
        if (revInfix[count] == '*' || revInfix[count] == '/' || revInfix[count] == '+' || revInfix[count] == '-' || revInfix[count] == '(' || revInfix[count] == ')')
        {
            insertNode(inExpLL, revInfix[count], OPT);
            count++;
            continue;
        }

        else //digit
        {
            count2 = count+1;
            tens_value = 10;
            temp[0] = revInfix[count];
            temp[1] = '\0';
            repeat = 0;
            temp_val = atoi(temp);
            while (revInfix[count2] != '*' && revInfix[count2] != '/' && revInfix[count2] != '+' && revInfix[count2] != '-' && revInfix[count2] != '(' && revInfix[count2] != ')' && revInfix[count2] != '\0')
            {
                temp[0] = revInfix[count2];
                temp[1] = '\0';
                temp_val = atoi(temp) * tens_value + temp_val;
                tens_value = tens_value*10;
                repeat++;
                count2++;
            }
            insertNode(inExpLL, temp_val, OPERAND);
            count = count + 1 + repeat;
        }
    }

}

void printExpLL(LinkedList inExpLL, int seed)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item+ seed);
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
    if(LLPtr==NULL || LLPtr->size==0){ //Queue is empty or NULL pointer
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