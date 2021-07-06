/*
An standard mathematical problem which is standard problem of stack

problem - https://en.wikipedia.org/wiki/Tower_of_Hanoi
useful link - https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
output - program will display order of movement of Disk 
*/

#include <iostream>
using namespace std;

void Tower(int N,int source,int aux,int destination)
{
    if(N==1)
    {
        cout<<"move disk 1 from "<<source<<" to"<<destination<<endl;
    }
    else
    {
        Tower(N-1,source,destination,aux);
             cout<<"move disk "<<N<<" from "<<source<<" to"<<destination<<endl;
        Tower(N-1,aux,source,destination);
    }   
}
int main() {

	int N;
	    cin>>N; //number of disk
        //total 2^N moves required
	    Tower(N,1,2,3);
	return 0;
}
