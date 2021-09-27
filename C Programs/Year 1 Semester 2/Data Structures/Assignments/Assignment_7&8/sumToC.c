#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
    int sizeArray;
    struct _arraynode *next;
}ArrayNode;

typedef struct _arraylist{
   int size; //the size of a possible sequence
   ArrayNode *head;
} ArrayList;

typedef struct _listnode
{
    int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int sum; //the number of possible sequences
   int size;
   ListNode *head;
} LinkedList;

// You should not change the prototypes of these functions
//////LinkedList///////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
void insertArray(ArrayList* al, LinkedList* ll);
void printList(LinkedList *ll);
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);
int main()
{
    int C;
    printf("Enter a number:\n");
    scanf("%d",&C);

    LinkedList ll;
    ll.head = NULL;
    ll.sum = 0;
    ll.size = 0;
    ArrayList al;
    al.head = NULL;
    al.size = 0;

    sumToC(&ll,C,&al);
    ArrayNode* temp;
    int i,j;
    temp = al.head;
    for(i=0;i<al.size;i++){
        for(j=0;j<temp->sizeArray;j++)
            printf(" %d ",temp->itemArray[j]);
        printf("\n");
        temp = temp->next;
    }

    return 0;
}

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
	// Write your code here
	int i, current, index = 0, base_current = 1, a = 0;
	ListNode *x;

	if (C<1 || C>50)
		return;

	while (base_current < C)
	{
		insertNode(ll, index++, base_current);
		current = base_current + 1;
		while (current <= C+1)
		{
			if (ll->sum < C)
			{
				insertNode(ll, index++, current++);
				continue;
			}

			if (ll->sum == C)
			{

				//printList(ll);
				insertArray(al, ll);
				index--;
				removeNode(ll, index);
				index--;
				x = findNode(*ll, index);
				if (x==NULL)
				{
					//printf("sum == c NULL\n");
					return;
				}
				current = x->item;
				current++;
				//printList(ll);
				a = removeNode(ll, index);
			}

			if (ll->sum > C)
			{
				index--;
				x = findNode(*ll, index);
				/*if (x == NULL)
					return;*/
				current = x->item;
				removeNode(ll, index);
				index--;
				removeNode(ll, index);
			}
		}
		base_current++;
		removeAllItems(ll);
		index = 0;
	}
}

void insertArray(ArrayList* al, LinkedList* ll)
{
	ListNode *cur_ll = ll->head;
	ArrayNode *cur;
	int i=0;

	if (cur_ll == NULL)
	{
		return;
	}

	if(al->size == 0)
	{
		al->head = malloc(sizeof(ArrayNode));
		al->head->next = NULL;
		al->head->sizeArray = ll->size;
		al->head->itemArray = malloc(sizeof(int) * ll->size);
		i = 0;
		while (cur_ll != NULL)
		{
			al->head->itemArray[i] = cur_ll->item;
			i++;
			cur_ll = cur_ll->next;
		}
		al->size++;
		return;
	}

	cur = al->head;
	if (al->size != 0)
	{
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = malloc(sizeof(ArrayNode));
		cur = cur->next;
		cur->sizeArray = ll->size;
		cur->next = NULL;
		cur->itemArray = malloc(sizeof(int) * ll->size);
		i = 0;
		while (cur_ll != NULL)
		{
			cur->itemArray[i] = cur_ll->item;
			i++;
			cur_ll = cur_ll->next;
		}
		al->size++;
		return;
	}
}
///////////////////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

        if (index == 0){
		cur = ll->head;
		ll->head = (ListNode*) malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}

	return 0;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		ll->sum -= ll->head->item;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 1;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return 0;

		cur = pre->next;
		ll->sum -= cur->item;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 1;
	}

	return 0;
}

ListNode *findNode(LinkedList ll, int index){

	ListNode *temp;

	if (index < 0 || index >= ll.size)
	{
		return NULL;
	}

	temp = ll.head;

	if (temp == NULL || index < 0)
	{
		return NULL;
	}

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
		{
			return NULL;
		}
			
		index--;
	}

	return temp;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
	ll->sum =0;
}

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;
	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}