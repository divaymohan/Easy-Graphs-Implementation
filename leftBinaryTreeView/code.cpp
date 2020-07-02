void printLeftView(Node* root,int level,int *maxLevel){
    if(!root) return;
    if(level>*maxLevel){
        *maxLevel = level;
        cout<<root->data<<" ";
    }
    printLeftView(root->left,level+1,maxLevel);
    printLeftView(root->right,level+1,maxLevel);
}
// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   int maxLevel = 0;
   printLeftView(root,1,&maxLevel);
}