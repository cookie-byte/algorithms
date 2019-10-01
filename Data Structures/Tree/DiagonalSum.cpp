void func(Node* node,int d,map<int,int> &m)
{
    if(node==NULL)
     return;
    m[d]+=node->data;
     func(node->left,d+1,m);
     func(node->right,d,m);
}
void diagonalSum(Node* root)
{
 // Add your code here
 map<int,int> m;
 func(root,0,m);
 for(auto it=m.begin();it!=m.end();it++)
 {
    cout<<it->second<<" "; 
 }
 cout<<endl;
}
