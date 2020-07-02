void inorder(vector<int> &arr,Node *root){
    if(root==NULL) return;
    inorder(arr,root->left);
    arr.push_back(root->data);
    inorder(arr,root->right);
    
}
// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    vector<int> arr;
    inorder(arr,root);
    for(int i=0;i<arr.size()-1;i++){
        if(arr.at(i)>=arr.at(i+1)) return false;
    }
    return true;
}