#include<iostream>
#include<vector>
using namespace std;
class heap
{
public:
int count;
vector<int>v;
heap()
{
count=0;
}
void add(int value)
{
v.push_back(value);
count++;
minheapify();
}
void minheapify()
{
int i=count-1;
while(i>0&&v[i]<v[(i-1)/2])
{
swap(i,(i-1)/2);
i=(i-1)/2;
}
}
void swap(int a,int b)
{
int t=v[a];
v[a]=v[b];
v[b]=t;
}
bool remove(int value)
{
int i=findindex(value);
int left=0,right=0;
if(i<0)
{
return false;
}
count--;
v[i]=v[count];
right=(2*i+2);
left=(2*i+1);
while(left<count&&(v[i]>v[left]||v[i]>v[right]))
{
if(v[left]<v[right])
{
i=left;
right=(2*i+2);
left=(2*i+1);
}
else
{
swap(right,left);
}
}
return true;
}
void traverse()
{
for(int i=0;i<count;i++)cout<<v[i]<<"\n";
}
int findindex(int value)
{
	int u=count+1,l=0,mid;
	while(l<=u)
	{
		mid=(u+l)/2;
		if(value=v[mid])return mid;
		else if(value<v[mid])u=mid-1;
		else l=mid+1;
	}
	return -1;
}
bool search(int value)
{
int start=0,nodes=1;
while(start<count)
	{
		start=nodes-1;
		int end=nodes+start;
		int c=0;
		while(start<count&&start<end)
		{
			if(value==v[start])
			{
				return true;
			}
			else if(value>v[(start-1)/2]&&value<v[start])
			{
				c++;
			}
			start=start+1;
		}
		if(c==nodes)return false;
		nodes=nodes*2;
	}
	return false;
}
};
int main()
{
heap h;
h.add(5);
h.add(8);
h.add(1);
h.add(2);
h.add(3);
h.add(7);
h.add(9);
h.add(12);
cout<<h.findindex(12)<<"\n";
return 0;
}
