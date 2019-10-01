void verticalOrder(Node *root)
{
    //Your code here
    if(root==NULL)
     return;
    map<int,vector<int>> m;
    int hd=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp=q.front();
        q.pop();
        hd=temp.second;
        Node *node=temp.first;
        m[hd].push_back(node->data);
        if(node->left!=NULL)
          q.push({node->left,hd-1});
        if(node->right!=NULL)
          q.push({node->right,hd+1});
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
    }
}
