#include <iostream>
using namespace std;
class node
{
	public:
	int data;
	node *left,*right;
	node()
	{
		left=nullptr;
		right=nullptr;
		data=0;
	}
};
class bst
{
	public:
	node *root;
	int count;
	bst()
	{
		root=nullptr;
		count=0;
	}
	void insert(int v)
	{
		if(root==nullptr)
		{
			root=new node();
			(*root).data=v;
			count++;
		}
		else
		{
			insert(&(*root),v);
		}
	}
	void insert(node *current,int v)
	{
		if((*current).data>v)
		{
			if((*current).left==nullptr)
			{
				(*current).left=new node();
				(*((*current).left)).data=v;
				count++;
			}
			else
			{
				insert(&(*((*current).left)),v);
			}
		}
		else
		{
			if((*current).right==nullptr)
			{
				(*current).right=new node();
				(*((*current).right)).data=v;
				count++;
			}
			else
			{
				insert(&(*((*current).right)),v);
			}
		}
	}
	void preorder()
	{
		preorder(&(*root));
	}
	void preorder(node *current)
	{
		if(current!=nullptr)
		{
		cout<<(*current).data<<"\n";
		preorder(&(*((*current).left)));
		preorder(&(*((*current).right)));
		}
	}
	void inorder()
	{
		inorder(&(*root));
	}
	void inorder(node *current)
	{
		if(current!=nullptr)
		{
			inorder(&(*((*current).left)));
			cout<<(*current).data<<"\n";
			inorder(&(*((*current).right)));
		}
	}
	void postorder()
	{
		postorder(&(*root));
	}
	void postorder(node *current)
	{
		if(current!=nullptr)
		{
			postorder(&(*((*current).left)));
			postorder(&(*((*current).right)));
			cout<<(*current).data<<"\n";
		}
	}
	node* findparent(int value)
	{
		return findparent(value,&(*root));
	}
	node* findparent(int value,node *current)
	{
		if(current==nullptr)
		{
			return nullptr;
		}
		else if((*current).data>value)
		{
			if((*current).left==nullptr)return nullptr;
			else if((*((*current).left)).data==value)
			return &(*current);
			else return findparent(value,&(*((*current).left)));
		}
		else
		{
			if((*current).right==nullptr)return nullptr;
			else if((*((*current).right)).data==value)
			return &(*current);
			else return findparent(value,&(*((*current).right)));
		}
	}
	node* findnode(int value)
	{
		return findnode(&(*root),value);
	}
	node* findnode(node *current,int value)
	{
		if(current==nullptr)return nullptr;
		else if((*current).data==value)return &(*current);
		else if((*current).data>value)return findnode((*current).left,value);
		else return findnode((*current).right,value);
	}
	bool search(int value)
	{
		return search(&(*root),value);
	}
	bool search(node *current,int value)
	{
		if(current==nullptr)return false;
		else if((*current).data==value)return true;
		else if((*current).data>value)return findnode((*current).left,value);
		else return findnode((*current).right,value);
	}
	bool remove(int value)
	{
		node *rv=&(*findnode(value));
		if(rv==nullptr)
		return false;
		node *p=findparent(value);
		if(count==1)root=nullptr;
		else if((*rv).left==nullptr and (*rv).right==nullptr)
		{
			if((*rv).data<(*p).data)
			(*p).left=nullptr;
			else (*p).right=nullptr;
		}
		else if((*rv).left==nullptr and (*rv).right!=nullptr)
		{
			if((*rv).data<(*p).data)
			(*p).left=&(*((*rv).right));
			else (*p).right=&(*((*rv).right));
		}
		else if((*rv).left!=nullptr and (*rv).right==nullptr)
		{
			if((*rv).data<(*p).data)
			(*p).left=&(*((*rv).left));
			else (*p).right=&(*((*rv).left));
		}
		else
		{
			node *l=&(*((*rv).left));
			while((*l).right!=nullptr)
			{
				l=&(*((*l).right));
			}
			(*findparent((*l).data)).right=nullptr;
			(*rv).data=(*l).data;
		}
		count--;
		return true;
	}
};
int main()
{
	bst tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(2);
	tree.insert(8);
	tree.insert(6);
	tree.insert(3);
	tree.insert(4);
	tree.insert(1);
	tree.insert(10);
	tree.insert(9);
	tree.preorder();
	cout<<tree.remove(4)<<"\n";
	tree.preorder();
	return 0;
}
