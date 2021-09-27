#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    int **matrix;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

typedef struct _stack
{
	int size;
	StackNode *head;
} Stack;

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);
int matching(Graph g, int *path);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
void printGraphMatrix(Graph g);
void DFS (Graph g, int source, int *visited);
int emptyArray(int *array, int array_len, int empty_value);
void resetArray(int *array, int array_len, int reset_value);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

int main()
{
    int Prj, Mtr; //Project, Student and Mentor;
    int maxMatch = 0;
    int ns,np,nm, total_nodes;
    int no_projects, no_mentors; //number of preferrence
    int i, j, k, temp;
    int base_student, base_mentor, source, sink, count =0;

	Graph g;
    //Write your code
    scanf("%d %d %d", &ns, &np, &nm); //no of each
    total_nodes = (2*ns) + np + nm + 2; //2 for source and sink
    base_student = np+1;
    base_mentor = np + (2*ns) +1;
    source = 0;
    sink = total_nodes -1;
	g.E = 0;
    g.V = total_nodes;
    int path[g.V];
    for (i=0; i<g.V;i++)
        path[i] = -1;
    g.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int));
    for(i=0;i<g.V;i++)
    {
        for(j=0;j<g.V;j++)
           g.matrix[i][j] = 0;
    }
    for (i=0; i<np; i++)//set up source
        {
            g.matrix[0][i+1] = 1;
            g.E++;
        }
    for (i=0; i<nm; i++)//set up sink
    {
        g.matrix[base_mentor+i][sink] = 1;
        g.E++;
    }
    for (i=base_student;i<base_student+ns;i++)
    {
        g.matrix[i][i+ns] = 1;
        g.E++;
    }
    for (i=0; i<ns; i++) //set up main graph
    {
        scanf("%d %d", &no_projects, &no_mentors);
        for (j=0; j<no_projects; j++)
        {
            scanf("%d", &Prj);
            g.matrix[Prj][base_student+i] = 1;
            g.E++;
        }
        for (j=0; j<no_mentors; j++)
        {
            scanf("%d", &Mtr);
            g.matrix[base_student+ns+i][base_mentor+Mtr-1] = 1;
            g.E++;
        }
    }
    //printGraphMatrix(g);

    resetArray(path, g.V, -1);
    temp = 1;
    for (i=1; i<=np; i++)
    {
        DFS(g, i, path);
        temp = matching(g, path);
        resetArray(path, g.V, -1);
        if (temp == 0)
            continue;
        count += temp;
    }
    printf("%d", count);

    return 0;
}

int matching(Graph g, int *path)
{
    //Write your code
    int i, temp;
    i = g.V-1;

    if (path[i] == -1)
    {
        return 0;
    }

    while (i!=0)
    {
        temp = i; //temp = sink
        i = path[i]; // i = mentor
        g.matrix[temp][i] = 1;
        g.matrix[i][temp] = 0;
    }

    return 1;
}

int emptyArray(int *array, int array_len, int empty_value)
{
    int i;
    for (i=0; i<array_len; i++)
    {
        if (array[i] != empty_value)
            return 0;
    }
    return 1;
}

void resetArray(int *array, int array_len, int reset_value)
{
    int i;
    for(i=0;i<array_len;i++)
    {
        array[i]=reset_value;
    }
}

void DFS (Graph g, int source, int *visited)
{
    //Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;
    int i, w, sink = g.V-1;

    push(&s, source);
    visited[source] = 0;

    while (!isEmptyStack(s))
    {
        w = peek(s);
        pop(&s);
        //printf("w: %d\n",w);
        for (i=0; i<g.V; i++)
        {
            if (g.matrix[w][i] == 1 && visited[i] == -1)
            {
                //printf("i: %d\n",i);
                push(&s, i);
                visited[i] = w;
                if (sink == i)
                {
                    removeAllItemsFromStack(&s);
                    return;
                }
            }
        }
    }
    return;
}

void printGraphMatrix(Graph g)
{
    int i,j;

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf(" %d ",g.matrix[i][j]);
        printf("\n");
    }

}

void removeAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp, *preTemp;
    if(*AdjList != NULL)
    {
        if((*AdjList)->vertex ==vertex){//first node
            temp = *AdjList;
            *AdjList = (*AdjList)->next;
            free(temp);
            return;
        }
        preTemp = *AdjList;
        temp = (*AdjList)->next;
        while(temp!=NULL && temp->vertex != vertex)
        {
            preTemp= temp;
            temp = temp->next;
        }
        preTemp->next = temp->next;
        free(temp);
    }

}
void insertAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp;
    if(*AdjList==NULL)
    {
        *AdjList = (ListNode *)malloc(sizeof(ListNode));
        (*AdjList)->vertex = vertex;
        (*AdjList)->next = NULL;
    }
    else{
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->vertex = vertex;
        temp->next = *AdjList;
        *AdjList = temp;
    }
}
void enqueue(Queue *qPtr, int vertex) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = vertex;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
	while(dequeue(qPtr));
}

void printQ(QueueNode *cur){
    if(cur==NULL) printf("Empty");

    while (cur != NULL){
        printf("%d ", cur->vertex);
        cur = cur->next;
    }
    printf("\n");
}

void push(Stack *sPtr, int vertex)
{
	StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
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

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
	while(pop(sPtr));
}