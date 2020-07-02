int getsNthFromLast(Node* head,int n,int *level){
    if(!head) return -1;
    int r = getsNthFromLast(head->next,n,level);
    *level += 1;
    if(*level==n){
        return head->data;
    }
    return r;
}
int getNthFromLast(Node *head, int n)
{
        int level = 0; 
       return getsNthFromLast(head,n,&level);
}