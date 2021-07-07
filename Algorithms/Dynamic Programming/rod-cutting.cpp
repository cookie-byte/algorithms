// A Dynamic Programming solution for Rod cutting problem 
#include<iostream>
  
using namespace std;

int max(int a, int b) { return (a > b)? a : b;} 
  
/* Returns the best obtainable price for a rod of length n and 
   price[] as prices of different pieces */
int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 
  
int main() 
{ 
    int i, n;
    cin >> n;
    int arr[n];
    for(i=0; i<n; i++)
      cin >> arr[i];
    cout << "Maximum Obtainable Value is " << cutRod(arr, n); 
    return 0; 
} 
