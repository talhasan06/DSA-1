#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node (int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
//traversing
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// length
int getLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
//insert at head
void insertAtHead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
}
//insert at tail
void insertAtTail(Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
        Node* temp=new Node (d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
     // insert end
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

/*** Delete element ***/
void deleteNode(int position,Node* &head){
    // first position
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else{
        //delete any middle node or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
    // last position
    /*coding missing*/
}
int main() {
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,11);
    insertAtTail(head,tail,8);
    insertAtPosition(head,tail,2,100);
    insertAtPosition(head,tail,1,101);
    insertAtPosition(head,tail,5,102);
    print(head);
    cout<<getLength(head)<<endl;
   return 0;
}