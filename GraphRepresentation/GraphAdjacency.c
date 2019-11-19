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
//driver function
int main()
{
    //create graph
    int v = 5;
    struct Graph *graph = createGraph(v);
    printGraph(graph);
    return 0;
}