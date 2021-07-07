#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define io1 std::ifstream in("in.txt");std::cin.rdbuf(in.rdbuf());
#define io2 std::ofstream out("out.txt");std::cout.rdbuf(out.rdbuf());
#define time1 auto start = high_resolution_clock::now(); 
#define time2  auto stop = high_resolution_clock::now(); auto duration = duration_cast<microseconds>(stop - start); cout << "Time taken: "<< duration.count() << " microseconds" <<"\n"; 
  
using namespace std;
using namespace std::chrono; 
class BST
{
public:
    vector< pair<ll,ll> >arr;
   
    void insert(ll v)
    {
        if(arr.size()==0)
        {
            arr.push_back(make_pair(-1,0));
            arr.push_back(make_pair(v,1));
        }
        else
        {
            insert(1,v);
        }
    }
    
    void insert(ll p,ll v)
    {
        if(arr.size()<2*p+2)while(arr.size()<2*p+2)arr.push_back(make_pair(-1,0));
        if(arr[p].first<=v)
        {
            if(arr[2*p+1].second==1)
            {
                insert(2*p+1,v);
            }
            else
            {
                arr[2*p+1].first=v;
                arr[2*p+1].second=1;
            }
        }
        else
        {
            if(arr[2*p].second==1)
            {
                insert(2*p,v);
            }
            else
            {
                arr[2*p].first=v;
                arr[2*p].second=1;
            }
        }
    }
    
    ll search(ll v)
    {
        ll p=1;
        if(arr[p].first==v)return 1;
        return search(p,v);
    }
    
    ll search(ll p, ll v)
    {
        if(arr.size()<=p)return -1;
        if(arr[p].first==v)return p;
        else if(arr[p].first>v)
        {
           if(arr[2*p].second==1)return search(2*p,v);
           else return -1;
        }
        else
        {
             if(arr[2*p+1].second==1)return search(2*p+1,v);
             else return -1;
        }
    }
    
    ll remove(ll v)
    {
        ll p=search(v);
        if(arr[2*p].second==1)
        {
             arr[p].first=arr[2*p].first;
             if (arr[4*p].second==0&&arr[4*p+3].second==0)
             {
                 arr[2*p].first=-1;
                 arr[2*p].second=0;
            }
            else
            {
                    remove(2*p,p);
            }
               return p;
        }
        else if(arr[2*p+1].second==1)
        {
             arr[p].first=arr[2*p+1].first;
             if (arr[4*p].second==0&&arr[4*p+3].second==0)
             {
                  arr[2*p+1].first=-1;
                 arr[2*p+1].second=0;
            }
             else
             {
                    remove(2*p+1,p);
            }
               return p;
        }
        else
        {
            arr[p].first=-1;
            arr[p].second=0; 
            return p;
        }
        }
 
  void remove(ll p,ll pt)
  {
      if(arr[2*p].second==0&&arr[2*p+1].second==0)
      {
          return;
      }
       if(arr[2*p].second==1)
        {
           arr[2*pt].first=arr[2*p].first;
           arr[2*p].first=-1;
           arr[2*p].second=0;
           arr[2*pt].second=1;
           remove(2*p,2*pt);
        }
        if(arr[2*p+1].second==1)
        {
           arr[2*pt+1].first=arr[2*p+1].first;
           arr[2*p+1].first=-1;
           arr[2*p+1].second=0;
            arr[2*pt+1].second=1;
           remove(2*p+1,2*pt+1);
        }
 }
    void preorder()
    {
        int p;
        preorder(1);
    }
    
    void preorder(ll p)
    {
        if(arr[p].second)
        {
            cout<<arr[p].first<<" "<<p<<"\n";
            preorder(2*p);
            preorder(2*p+1);
        }
    }
};
int main()
{
    io1 io2
 	BST tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(8);
    tree.remove(7);
    tree.remove(6);
    tree.remove(8);
    tree.preorder();
    
return 0;
}
