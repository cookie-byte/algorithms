#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};

bool Isempty(Node *head){
  if(head==nullptr)
    return true;
  return false;
}
Node* insert(Node *head, int x){
  Node *temp = new Node();
  temp->val = x;
  temp->next = nullptr;
  if(head==nullptr)
    head = temp;
  else{
    Node *cat = head;
    while(cat->next!=nullptr){
      cat = cat->next;
    }
    cat->next = temp;
  }
  return head;
}
Node *findValue(Node * head, int x){
  Node *cat = head;
  while(cat!=nullptr){
    if(cat->val==x)
      break;
    cat = cat->next;
  }
  return cat;
}
Node* findPosition(Node *head, int pos){
  int count  = 1;
  Node *cat = head;
  while(count<pos){
    cat = cat->next;
    count++;
  }
  return cat;
}
Node* deleteValue(Node *head, int x){
  if(head->val==x){
      Node *temp = head;
      head = head->next;
      delete temp;
  }
  else if(findValue(head, x)==nullptr)
    cout << "Not Found!" <<endl;
  else {
    Node *cat = head;
    while(cat!=nullptr && cat->next->val!=x)
      cat = cat->next;
      Node *temp = cat->next;
      cat->next = temp->next;
      delete temp;
  }
  return head;
}
int length(Node *head){
  if(head==nullptr)
    return 0;
  int count = 1;
  Node *cat = head;
  while(cat->next!=nullptr){
    cat = cat->next;
    count++;
  }
return count;
}
Node* deletePosition(Node *head, int pos){
  if(pos>length(head)){
      cout << "Position not found!" << endl;
  }
  else if(pos==1){
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  else{
    int count = 1;
    Node *cat = head;
    Node *prev;
    while(count<pos){
      prev = cat;
      cat = cat->next;
      count++;
    }
  prev->next = cat->next;
  delete cat;
  }
  return head;
}
void printList(Node *head){
  cout << "List : ";
  Node *cat = head;
  while(cat!=nullptr){
    cout << cat->val << " ";
    cat = cat->next;
  }
  cout << endl;
}
Node* reverseList(Node *head){
  Node *past  = nullptr, *present = head, *future = nullptr;
  while(present!=nullptr){
    future = present->next;
    present->next = past;
    past = present;
    present = future;
  }
  return past;
}

Node* reverseSubList(Node *head, int m, int n){
Node *start, *connectStart, *end, *connectEnd;
end = findPosition(head, n);
if(m==1){
  start = head;
  connectStart = head;
}
else{
  connectStart = findPosition(head, m-1);
  start = connectStart->next;
}
if(n==length(head))
    connectEnd = nullptr;
else
  connectEnd = end->next;
Node *tempHead = start;
end->next = nullptr;
tempHead = reverseList(tempHead);
printList(tempHead);
if(m==1)
  head = tempHead;
else
  connectStart->next = tempHead;
  while(tempHead->next!=nullptr)
       tempHead = tempHead->next;
    tempHead->next = connectEnd;
return head;
}


int main(){
Node *head = nullptr;
  return 0;
}
