bool detectLoop(Node* head)
{
    Node *temp1 = head;
    Node *temp2 = head->next;
    while(temp1!=NULL && temp2 && temp2->next!=NULL){
        if(temp1==temp2) return true;
        temp1 = temp1->next;
        temp2 = temp2->next->next; 
        
    }
    return false;
}
