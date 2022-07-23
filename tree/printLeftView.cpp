/*void utilLeftView(Node  *root , vector<int> &v  , int maxlevel , int &level){
    if(root == NULL){
        return;
    }
    if(maxlevel == level){
    v.push_back(root->data);
    level++;
    }
    
    utilLeftView(root->left , v , maxlevel+1 , level);
    utilLeftView(root->right , v ,  maxlevel+1 , level);
    return;
    
}


vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> v;
   
   int level = 1;
   utilLeftView(root , v , 1 ,level);
   return v;
}*/