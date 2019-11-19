#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *root;
struct Node *createNode(int data)
{
    struct Node *ReNode = (struct Node *)malloc(sizeof(struct Node));
    ReNode->data = data;
    ReNode->left = NULL;
    ReNode->right = NULL;
    return ReNode;
}
void insertBinarySearchTree(int data)
{
    struct Node *temp = root;
    if (temp == NULL)
    {
        root = createNode(data);
        return;
    }
    struct Node *preNode = temp;
    while (temp != NULL)
    {
        if (temp->data > data)
        {
            preNode = temp;
            temp = temp->left;
        }
        else
        {
            preNode = temp;
            temp = temp->right;
        }
    }
    if (preNode->data > data)
    {
        preNode->left = createNode(data);
    }
    else
    {
        preNode->right = createNode(data);
    }
}
void inorder(struct Node *rooot)
{
    if (rooot != NULL)
    {
        inorder(rooot->left);
        printf("%d ", rooot->data);
        inorder(rooot->right);
    }
}
int maxElement(int first, int last)
{
    struct Node *temp = root;
    while (temp)
    {
        if (temp->data > first && temp->data < last)
        {
            break;
        }
        else if (temp->data > first && temp->data > last)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    while (temp->data < last)
    {
        temp = temp->right;
    }
    return temp->data;
}
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int n;
    fscanf(fp, "%d", &n);
    root = NULL;
    //struct Node *temp =NULL;
    struct Node *trav = NULL;
    int temp;
    int count = 0;
    while (count < n)
    {
        fscanf(fp, "%d ", &temp);
        insertBinarySearchTree(temp);
        count++;
    }
    // printf("%d",root->data);
    inorder(root);
    int first, last;
    fscanf(fp, "%d", &first);
    fscanf(fp, "%d", &last);
    int max = maxElement(first, last);
    printf("\nMaximum element :: %d\n", max);
    return 0;
}