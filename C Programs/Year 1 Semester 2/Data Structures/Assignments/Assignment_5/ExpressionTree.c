#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void createExpTree(BTNode** root,char* prefix)
{
    //Write your code here
    int len = strlen(prefix)-1, i=0, j, k;
    BTNode *temp_node;
    Stack s;
    char temp_char[2];
    int temp_value = 0, multiplier = 1;

    while (len >= 0)
    {
        if (isdigit(prefix[len]))
        {
            while(prefix[len] != ' ') //get ddigit
            {
                temp_char[0] = prefix[len];
                temp_char[1] = '\0';
                temp_value = temp_value + multiplier * atoi(temp_char);
                multiplier *= 10;
                len--;
            }
            temp_node = malloc(sizeof(BTNode));
            temp_node->item = temp_value;
            temp_node->left = NULL;
            temp_node->right = NULL;
            //printf("temp_value: %d\n", temp_value);
            temp_value = 0;
            multiplier = 1;
            //printf("temp_node->item: %d\n", temp_node->item);
            push(&s, temp_node);
        }

        if (prefix[len] == ' ')
        {
            len--;
            continue;
        }

        else //operator
        {
            temp_node = malloc(sizeof(BTNode));
            temp_node->item = prefix[len];
            //printf("temp_node->operator: %d\n", temp_node->item);
            temp_node->left = peek(s);
            pop(&s);
            temp_node->right = peek(s);
            pop(&s);
            push(&s, temp_node);
            len--;
            continue;
        }
    }

    (*root) = peek(s);
    pop(&s);
}

void printTree(BTNode *node){
    //Write your code here
    if (node == NULL)
        return;

    printTree(node->left);
    switch (node->item)
    {
    case 42: // *
        printf("* ");
        break;
    case 43:
        printf("+ ");
        break;
    case 45:
        printf("- ");
        break;
    case 47:
        printf("/ ");
        break;
    default:
        printf("%d ", node->item);
        break;
    }
    printTree(node->right);
    return;
}


void printTreePostfix(BTNode *node){
    //Write your code here
    if (node == NULL)
        return;

    printTreePostfix(node->left);
    printTreePostfix(node->right);
    switch (node->item)
    {
    case 42: // *
        printf("* ");
        break;
    case 43:
        printf("+ ");
        break;
    case 45:
        printf("- ");
        break;
    case 47:
        printf("/ ");
        break;
    default:
        printf("%d ", node->item);
        break;
    }
    return;
}

double computeTree(BTNode *node){
    //Write your code here
    BTNode *cur;
    double result = 0, temp1, temp2;

    if (node == NULL)
        return 0;

    temp1 = computeTree(node->left);
    temp2 = computeTree(node->right);

    switch (node->item)
    {
    case 42: // *
        result = temp1 * temp2;
        break;
    case 43:
        result = temp1 + temp2;
        break;
    case 45:
        result = temp1 - temp2;
        break;
    case 47:
        result = temp1 / temp2;
        break;
    default: 
        result = node->item;
        break;
    }
    return result;
}

void push(Stack *sPtr, BTNode *item){
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

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}