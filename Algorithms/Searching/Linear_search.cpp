#include<bits/stdc++.h>
using namespace std;

//searching for a particular number(let say 7) 

int main()
{
    int arr[10]={1, 4,5,45,8,7,36,49 ,0,22};
    int length = sizeof(arr)/sizeof(arr[0]);
    int ans = 7 ;
    for( int i=0 ; i<length ; i++)
    {
        if(arr[i]==ans)
        {
            cout<<"element is present at position "<< i+1<<endl;
            break;
         }
    }
    if(i==length)
    cout<<"element is not present"<<endl;
} 
