/* Computes the diameter of binary tree with given root.  */
int dia(Node* node,int &ans)
{
    if(node==NULL)
     return 0;
    int lh=dia(node->left,ans);
    int rh=dia(node->right,ans);
    ans = max(ans,1+lh+rh);
    return 1+max(lh,rh);
}
int diameter(Node* node)
{
   // Your code here
   int ans = INT_MIN;
   dia(node,ans);
   return ans;
}

