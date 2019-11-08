#include <iostream>
using namespace std;
int main()
{
    int n,min,loc,tmp;
    cout << "Enter No. of Elements:"; 
	cin >> n;
	int a[n];
    cout << "\nEnter Elements:\n";
    for (int i=0;i<n;i++) 
	{ 
		cin>>a[i];
    }
    for (int i=0; i<n-1;i++)
    {
        min = a[i];
        loc = i;
        for (int k=i+1;k<n;k++)
		{ 
			if (min > a[k]) 
			{
                min = a[k];
                loc = k;
        	}
        }
        tmp = a[i];
        a[i] = a[loc];
        a[loc] = tmp;
    }
    cout << "\nAfter Sorting: \n";
    for (int i = 0; i < n; i++) 
	{
        cout << a[i] << endl;
    }
}
