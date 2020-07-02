void removeLoop(Node* head)
{
    Node *sp=head,*fp=head;
    while(sp && fp && fp->next) 
    {
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp)
            break;
    }
    //loop detected
    //calculate the number of node into the loop
    
    if(sp==fp)
    {
        int k = 1;
        while(sp->next!=fp){
            k++;
            sp=sp->next;
        }
        //reset both
        sp = head;
        fp = head;
        for(int i=0;i<k;i++){
            sp=sp->next;
        }
        while(sp!=fp){
            fp=fp->next;
            sp=sp->next;
        }
        while(fp->next!=sp){
            fp=fp->next;
        }
        fp->next=NULL;
    }
}