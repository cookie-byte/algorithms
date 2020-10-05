#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    cout<<head->data<<"->"<<head->next->data<<endl;
    return 0;
}