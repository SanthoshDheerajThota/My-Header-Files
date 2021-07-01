//this code is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
typedef struct  node{
    int data;
    node *next;
};
class list{
    private :
        node *head;
        int sizer;
    public :
        list();
        int size();
        void insert(int data);
        void insertAtEnd(int data);
        void insertAt(int data,int index);
        void deleteAt(int index);
        void print();
        void reverse();
};
list::list(){
    this->sizer=0;
    this->head=NULL;
}
int list::size(){
    return this->sizer;
}
void list::insert(int data){
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    this->head=newnode;
    return;
}
void list::insertAtEnd(int data){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    temp->next=newnode;
}
void list::insertAt(int data,int index){
    node *temp=head;
    node *previous=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
    }
    node *newnode=newnode;
    newnode->data=data;
    newnode->next=temp;
    previous->next=newnode;
}
void list::deleteAt(int index){
    node *temp=head;
    node *previous=NULL;
    node *next=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        next=temp->next;
    }
    previous->next=next;
    return;
}
void list::print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
void list::reverse(){
    node *previous=NULL;
    node *temp=this->head;
    node *next=NULL;
    while(temp->next!=NULL){
        next=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next;
    }
    temp->next=previous;
    head=temp;
    return;
}
