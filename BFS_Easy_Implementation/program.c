#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int u, v;
    int w;
    struct Node *next;
};
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");

    return 0;
}