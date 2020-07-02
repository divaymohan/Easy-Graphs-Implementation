struct Node* reverseList(struct Node *head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *next=head->next;
    while(next!=NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    return curr;
}