#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // destructor
    ~Node(){
        int value=this->data;
        // memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory free"<<endl;
    }
};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    // insert start
    if(position==1){ 
        insertAtHead(head,d);
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
        insertAtTail(tail,d);
        return;
    }
    // creating a node for d
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
// reverse
void reverseList(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
// remove duplicate
void removeDuplicate(Node* &head){
    Node* temp=head;
    if(!temp) cout<<"NULL"<<endl;
    while (temp->next!=NULL)
    {
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }else{
            temp=temp->next;
        }
    }
    
}
/*** Delete element ***/
void deleteNode(int position,Node* &head){
    // first position
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }else{
        //delete any position
        Node* curr=head;
        Node* prev=NULL;
        int pos=1;
        while(pos<=position){
            prev=curr;
            curr=curr->next;
            pos++;
        }
        // last position
        if(curr->next==NULL){
            prev->next=curr->next;
            delete curr;
            return;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    // create a new node
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl; 
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // head pointed to node1
    Node* head=node1;
    // print(head);
    // insertAtHead(head,12);
    // print(head);
    // insertAtHead(head,15);
    // print(head);

    // tail pointed to node1
    Node* tail=node1;
    // print(head);
    insertAtTail(tail,12);
    // print(head);
    insertAtTail(tail,15);
    insertAtTail(tail,5);
    // print(head);
    // if we add value in first positon we don't have any previous value
    insertAtPosition(head,tail,4,5);
    // insertAtPosition(head,3,22);
    // print(head);
    // deleteNode(2,head);
    // print(head);
    print(head);
    removeDuplicate(head);
    // reverseList(head);
    print(head);
    return 0;
}