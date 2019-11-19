#include <stdio.h>
#include <stdlib.h>

//A data Structure to represent an adjacency list node
struct AdjListNode
{
    //to store destination of edge from source
    int dest;
    struct AdjListNode *next;
};
//A datastructure to represents an adjacency list
struct AdjList
{
    struct AdjListNode *head;
};
//A datastructure to represent a graph.
//A graph is an array of adjacency lists.
//size of the array is equal to the number of vertices in the graph
struct Graph
{
    //to store number of vertices
    int v;
    //to store whole graph nodes
    struct AdjList *array;
};
//utility to create a AdjListNode
struct AdjListNode *createAdjListNode(int dest)
{
    //allocating the memory for the node
    struct AdjListNode *retNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    retNode->dest = dest;
    retNode->next = NULL;
    return retNode;
}
//utility to create graph
struct Graph *createGraph(int v)
{
    //allocating memmory for the graph
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->v = v;
    //allocating memmory for the list array
    graph->array = (struct AdjList *)malloc(v * sizeof(struct AdjList));
    //initialize the list
    for (int i = 0; i < v; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}
struct Queue
{
    struct AdjListNode *head;
    struct AdjListNode *rare;
};
//utility to print the graph
void printGraph(struct Graph *graph)
{
    printf("\nYour Graph Look like:\n");
    for (int i = 0; i < graph->v; i++)
    {
        struct AdjListNode *temp = graph->array[i].head;
        printf("\n[%d]", i);
        while (temp)
        {
            printf("->(%d ,%d)", i, temp->dest);
            temp = temp->next;
        }
        printf("->NULL");
    }
    printf("\n");
}
//push function
void push(int node, struct Queue *queue)
{
    if (queue->head == NULL)
    {
        queue->head = createAdjListNode(node);
        queue->rare = queue->head;
    }
    else
    {
        queue->rare->next = createAdjListNode(node);
        queue->rare = queue->rare->next;
    }
    return;
}
//pop function
int pop(struct Queue *queue)
{
    int reNode;
    if (queue->head == NULL)
    {
        return -1;
    }
    else if (queue->head == queue->rare)
    {
        struct AdjListNode *temp = queue->head;
        reNode = temp->dest;
        free(temp);
        queue->head = NULL;
        queue->rare = NULL;
    }
    else
    {
        struct AdjListNode *temp = queue->head;
        queue->head = queue->head->next;
        reNode = temp->dest;
        free(temp);
    }
    return reNode;
}
//BFS function
void BFS(struct Graph *graph)
{
    int source = 0;
    int vertices = graph->v;
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->rare = NULL;
    push(source, queue);
    visited[source] = 1;
    while (queue->head != NULL)
    {
        source = pop(queue);
        printf("%d ", source);

        struct AdjListNode *temp = graph->array[source].head;
        while (temp != NULL)
        {
            if (visited[temp->dest] == 0)
            {
                visited[temp->dest] = 1;
                push(temp->dest, queue);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
//driver function
int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    int v;
    fscanf(fp, "%d", &v);
    //create graph
    struct Graph *graph = createGraph(v);
    printGraph(graph);
    int e;
    fscanf(fp, "%d", &e);
    for (int i = 0; i < e * 2; i++)
    {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        struct AdjListNode *node = createAdjListNode(v);
        node->next = graph->array[u].head;
        graph->array[u].head = node;
    }
    printGraph(graph);
    printf("\nBFS Ordering of the given graph :: \n");
    BFS(graph);

    return 0;
}