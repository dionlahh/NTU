#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99999999;

typedef struct listnode {
    int item;
    int weight;
    struct listnode *next;
} ListNode;

typedef struct linkedlist {
    int size;
    ListNode *head;
} LinkedList;

typedef struct queue {
    LinkedList ll;
} Queue;

typedef struct graph {
    int V;
    int E;
    int **matrix;
    ListNode **list;
}Graph;

typedef struct heap_element {
    int v,d;
} heap_element;

typedef struct MinHeap {
    int *position;     	    // Index positions in heap
    int heap_size;  		// Size of heap
    int noNodes;      	    // Total number of nodes
    heap_element **arr;
} MinHeap;

///Queue Functions
void enqueue(Queue *q, int item, int weight);
int dequeue(Queue *q, int vertex);

int isEmptyQueue(Queue *q);
int extractCheapest(Queue *q);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int vertex, int weight);
int removeNode(LinkedList *ll, int index);
void printList(ListNode *ll);

void AdjMatrixGenerator(Graph *g);
void minHeapify(int index,MinHeap* mh);
MinHeap* generateMinHeap(int total_vertices);
heap_element* newHeapElement(int ver, int dist);
void decreaseKey(MinHeap* mh, int v, int dist);
heap_element* extractMin(MinHeap* mh);

void createAdjList(Graph *g);
void printGraphList(Graph g);
double Dijkstra_Priority(Graph G, int source);
double Dijkstra_Heap2(Graph G, int source);


int main() {
    //todo: automate graph creation;
    //todo: automate time collection;
    double time = 0, timeHeap = 0;
    int *total_comparisons;
    int noOfRuns = 100;
    Graph g;
    for (int j = 0; j < noOfRuns; j++) {
        for (int i = 1000; i <= 1000; i++) {
//            printf("================== |V|: %d ==================\n", i);
            g.E = 0;
            g.V = i;
            AdjMatrixGenerator(&g); //todo: ensure that we are able to vary |E|
//            printf("|E|: %d\n", g.E);

///     Create Adj List
            createAdjList(&g);
            time += Dijkstra_Priority(g, 0);
            timeHeap += Dijkstra_Heap2(g, 0);
        }
    }
    printf("Average time taken for priority: %f seconds \n", time/noOfRuns);
    printf("Average time taken for heap: %f seconds \n\n", timeHeap/noOfRuns);
}

double Dijkstra_Priority(Graph G, int source) {
    clock_t begin = clock();
    double time = 0;
    int d[G.V], pi[G.V], S[G.V], u;
    Queue q;
    q.ll.size = 0;
    q.ll.head = NULL;
    for (int i = 0; i < G.V; i++) {
        d[i] = MAX
        pi[i] = 0;
        S[i] = 0;
    }
    d[source] = 0;
    for (int i = 0; i < G.V; i++) {
        enqueue(&q, i, d[i]);
    }
    while(!isEmptyQueue(&q)) {
        u = extractCheapest(&q);
        S[u] = 1;
        for (int i = 0; i < G.V; i++) {
            if (u == i) continue;
            if (G.matrix[u][i] > 0 && S[i] != 1 && (d[i] > d[u] + G.matrix[u][i])) {
                dequeue(&q, i);
                d[i] = d[u] + G.matrix[u][i];
                pi[i] = u;
                enqueue(&q, i, d[i]);
            }
        }
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    return time;
}

double Dijkstra_Heap2(Graph G, int source) {
    clock_t begin = clock();
    double time = 0;
    int d[G.V], pi[G.V], S[G.V];
    MinHeap* mh = generateMinHeap(G.V);
    mh->noNodes = G.V;
    for (int i = 0; i < G.V; ++i)
    {
        d[i] = MAX;
        pi[i] = 0;
        S[i] = 0;
        mh->arr[i] = newHeapElement(i, d[i]);
        mh->position[i] = i;
    }
    mh->arr[0] = newHeapElement(0, d[0]);
    mh->position[0]   = 0;
    d[0] = 0;
    decreaseKey(mh, 0, d[0]);
    while (mh->noNodes != 0) {
        heap_element *heap_element = extractMin(mh);
        int vertex = heap_element->v;
        S[vertex] = 1;
        ListNode *cur = G.list[vertex];
        while (cur) {
            int v = cur->item;
            if (S[v] != 1 && d[v] > d[vertex] + cur->weight) {
                d[v] = d[vertex] + cur->weight;
                decreaseKey(mh, v, d[v]);
            }
            cur = cur->next;
        }
    }
    clock_t end = clock();
    time += (double) (end - begin) / CLOCKS_PER_SEC;
    return time;
}

void enqueue(Queue *q, int item, int weight) {
    insertNode(&(q->ll), q->ll.size, item, weight);
}

int dequeue(Queue *q, int vertex) {
    int item;
    int index = 0;
    ListNode *cur = q->ll.head;

    if (!isEmptyQueue(q)) {
        while (cur->item != vertex){
            index++;
            cur = cur->next;
        }
        item = cur->item;
        removeNode(&(q->ll), index);
        return item;
    }
    return -1;
}

int extractCheapest(Queue *q) {
    int min_weight, index=0, vertex, i=1;
    ListNode *cur;

    if (!isEmptyQueue(q)) {
        cur = q->ll.head;
        min_weight = cur->weight;
        vertex = cur->item;
        cur = cur->next;
        while (cur) {
            if (cur->weight < min_weight) {
                index = i;
                min_weight = cur->weight;
                vertex = cur->item;
            }
            i++;
            cur = cur->next;
        }
        removeNode(&(q->ll), index);
        return vertex;
    }
    return -1;
}

int isEmptyQueue(Queue *q) {
    if ((q->ll).size == 0)
        return 1;
    return 0;
}

void printList(ListNode *ll){

    ListNode *cur;
    if (ll == NULL)
        return;
    cur = ll;
    if (cur == NULL)
        printf("Empty");
    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

    ListNode *temp;

    if (ll == NULL || index < 0 || index >= ll->size)
        return NULL;

    temp = ll->head;

    if (temp == NULL || index < 0)
        return NULL;

    while (index > 0){
        temp = temp->next;
        if (temp == NULL)
            return NULL;
        index--;
    }

    return temp;
}

int insertNode(LinkedList *ll, int index, int vertex, int weight){

    ListNode *pre, *cur;
    if (ll == NULL || index < 0 || index > ll->size + 1)
        return -1;

    // If empty list or inserting first node, need to update head pointer
    if (ll->head == NULL || index == 0){
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        if (ll->head == NULL)
        {
            exit(0);
        }
        ll->head->item = vertex;
        ll->head->next = cur;
        ll->head->weight = weight;
        ll->size++;
        return 0;
    }
    if ((pre = findNode(ll, index - 1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        if (pre->next == NULL)
        {
            exit(0);
        }
        pre->next->item = vertex;
        pre->next->weight = weight;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }
    return -1;
}

int removeNode(LinkedList *ll, int index){

    ListNode *pre, *cur;

    // Highest index we can remove is size-1
    if (ll == NULL || index < 0 || index >= ll->size)
        return -1;

    // If removing first node, need to update head pointer
    if (index == 0){
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        return 0;
    }
    // Find the nodes before and after the target position
    // Free the target node and reconnect the links
    if ((pre = findNode(ll, index - 1)) != NULL){

        if (pre->next == NULL)
            return -1;

        cur = pre->next;
        pre->next = cur->next;
        free(cur);
        ll->size--;
        return 0;
    }

    return -1;
}

void createAdjList(Graph *g)
{
    int i, j;
    ListNode **list;
    ListNode *temp;

    if (g->V <= 0)
    {
        printf("Empty Graph!\n");
        return;
    }

    list = (ListNode **) malloc(g->V*sizeof(ListNode *));
    for (i=0; i<g->V; i++)
    {
        list[i] = NULL;
    }

    for (i=0; i<g->V; i++)
    {
        for (j=0; j<g->V; j++)
        {
            if (g->matrix[i][j] != 0)
            {
                if (list[i] == NULL)
                {
                    list[i] = (ListNode *)malloc(sizeof(ListNode));
                    list[i]->item = j;
                    list[i]->weight = g->matrix[i][j];
                    list[i]->next = NULL;
                    temp = list[i];
                }
                else
                {
                    temp->next = (ListNode *)malloc(sizeof(ListNode));
                    temp->next->item = j;
                    temp->next->weight = g->matrix[i][j];
                    temp->next->next = NULL;
                    temp = temp->next;
                }
            }
        }
    }
    g->list = list;
}

void printGraphList(Graph g){
    ListNode* temp;
    for(int i=0;i<g.V;i++)
    {
        printf("%d:\t",i);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d (%d) -> ",temp->item, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void AdjMatrixGenerator(Graph *g) {
    g->matrix = (int **) malloc(g->V*sizeof(int*));

    for(int i=0;i<g->V;i++)
        g->matrix[i] = (int *)malloc(g->V*sizeof(int));

    srand(time(NULL));

    for(int i=0;i<g->V;i++)
        for(int j=0;j<g->V;j++) {
            if (i != j) {
                g->matrix[i][j] = rand();
                g->E++;
            }
        }
}

MinHeap* generateMinHeap(int total_vertices)
{
    // Allocate memory for Heap
    MinHeap* mh = (MinHeap*) malloc(sizeof(MinHeap));

    // Memory for nodes in heap
    mh->position = (int *)malloc(total_vertices * sizeof(int));

    // Assign total number of vertices as the size of heap
    mh->heap_size = total_vertices;

    // Initialize number of nodes to 0
    mh->noNodes = 0;

    mh->arr =(heap_element**) malloc(total_vertices * sizeof(heap_element*));
    return mh;
}

heap_element* newHeapElement(int ver, int dist)
{
    heap_element* heap_element =(struct heap_element*) malloc(sizeof(heap_element));
    heap_element->v = ver;
    heap_element->d = dist;
    return heap_element;
}

void decreaseKey(MinHeap* mh, int v, int dist)
{
    // Retrieve current index of node
    int id = mh->position[v];
    // update value of d of the node
    mh->arr[id]->d = dist;

    while (mh->arr[id]->d < mh->arr[(id - 1) / 2]->d && id)
    {
        mh->position[mh->arr[id]->v] = (id - 1) / 2;
        mh->position[mh->arr[(id - 1) / 2]->v] = id;

        //swap
        heap_element* t = mh->arr[id];
        mh->arr[id] = mh->arr[(id - 1) / 2];
        mh->arr[(id - 1) / 2] = t;

        // move to parent
        id = (id - 1) / 2;
    }
}

heap_element* extractMin(MinHeap* mh)
{
    heap_element* min_heap_root;

    // if number of nodes is 0 return null
    if (mh->noNodes == 0)
        return NULL;
    else
    {
        // store the value of arr[0] as the root of min heap
        min_heap_root = mh->arr[0];

        // Replace the root node with last node
        heap_element* lnode = mh->arr[mh->noNodes - 1];
        mh->arr[0] = lnode;

        // Update last node's positionIn heap
        mh->position[min_heap_root->v] = mh->noNodes - 1;
        mh->position[lnode->v] = 0;

        // Reduce heap number_of_nodes
        mh->noNodes= mh->noNodes-1;

        // Heapify
        minHeapify(0,mh);
    }
    return min_heap_root;
}

void minHeapify(int index,MinHeap* mh)
{
    int least;
    int l, r;
    heap_element *leastNode;
    heap_element *indNode;


    least = index;
    l = (2*(index)) + 1;  // left child
    r = (2*(index)) + 2;  // right child

    if (l < mh->noNodes)
    {
        if(mh->arr[l]->d < mh->arr[least]->d )
        {
            least = l;
        }
    }

    if (r < mh->noNodes)
    {
        if(mh->arr[r]->d < mh->arr[least]->d )
        {
            least = r;
        }
    }

    if (least != index)
    {

        leastNode = mh->arr[least];
        indNode = mh->arr[index];

        mh->position[leastNode->v] = index;
        mh->position[indNode->v] = least;

        // Swap nodes
        heap_element* t = mh->arr[least];
        mh->arr[least] = mh->arr[index];
        mh->arr[index] = t;

        //minheapify
        minHeapify(least,mh);
    }
}
