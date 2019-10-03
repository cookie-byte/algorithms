/*SEGMENT TREE : GET SUM OVER A RANGE*/
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define point(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

int getSegTreeSize(int arr[], int n){
	int t=0;
	int a = n;
	while(a){
		t++;
		a>>=1;
	}
	int size = 2*pow(2,t)-1;
	return size;
}

void build(int *st, int node, int start, int end, int arr[]){
	if(start==end){
		st[node] = arr[start];
	}
	else{
		int mid= (start+end)/2;
		build(st,2*node+1,start,mid,arr);
		build(st,2*node+2,mid+1,end,arr);
		st[node] = st[2*node+1] + st[2*node+2];
	}
	return;
}

int getSum(int *st, int node, int start, int end, int l, int r, int arr[]){
	if(r<start || end<l){
		return 0;
	}
	else if(start>=l && end<=r){
		return st[node];
	}
	else{
		int mid = (start+end)/2;
		int a = getSum(st,2*node+1,start, mid,l,r,arr);
		int b = getSum(st,2*node+2,mid+1, end,l,r,arr);
		return a+b;
	}
}
void update(int *st,int node, int index, int val, int start, int end, int arr[]){
	if(start==end){
		int diff= val-st[node];
		st[node] = st[node] + diff;
		arr[index] = arr[index] + diff;
	}
	else{
		int mid=(start+end)/2;
		if(index>=start && index<=mid){
			update(st,2*node+1,index,val,start, mid,arr);
		}
		else{
			update(st,2*node+2,index,val,mid+1, end,arr);	
		}
		st[node] = st[2*node+1]+st[2*node+2];
	}
}
int main(int argc, char const *argv[])
{
	int arr[]  ={1,3,5,7,9,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	int size = getSegTreeSize(arr,n);
	int *st = new int[size];
	build(st,0,0,n-1,arr);
	for(int i=0;i<size;++i)
		cout<<st[i]<<" ";
	cout<<endl;
	cout<<getSum(st, 0, 0, n-1, 1, 4, arr)<<endl;
	update(st,0,2,4,0,n-1,arr);
	for(auto i: arr){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<getSum(st, 0, 0, n-1, 1, 4, arr)<<endl;
	return 0;
}