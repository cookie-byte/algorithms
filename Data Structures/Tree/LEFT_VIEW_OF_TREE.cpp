void leftViewUtil(Node *root,int lvl,int &maxlvl)
{
    if(root==NULL)
     return;
    if(lvl>maxlvl)
    {
        cout<<root->data<<" ";
        maxlvl=lvl;
    }
    leftViewUtil(root->left,lvl+1,maxlvl);
    leftViewUtil(root->right,lvl+1,maxlvl);
}
void leftView(Node *root)
{
   // Your code here
   int maxlvl=-1;
   leftViewUtil(root,0,maxlvl);
}
