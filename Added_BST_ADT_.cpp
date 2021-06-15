/*
     This is completely coded by santhosh and no one is given right to copy it
     This Header file is created by me to keep all the data Structures and all
     necessary member functions and operations under one My own header so I can 
     use them with ease
            The Data Structures include
        1.array
        2.node(linked list single node)
        3.linked list
        4.stack
        5.queue
        6.noder (single tree node)
        7.BST
        8.Create node function(To make a single node of a tree)
*/
#include <stdio.h>
#include<iostream>
using namespace std;
class array{
    private :
        int *arr;
        int sizeOfArray;
    public :
        array();
        void setData();
        int size();
        void printData();
        void removeDuplicates();
        void insert(int data,int index);
        void deleteTheValue(int data);
};
class node{
    public:
        int data;
        node *next;
        friend class queue;
        friend class stack;
        friend class linkedlist;
};
class linkedlist{
    private:
        node *head;
        int sizer;
    public :
        linkedlist();
        void insertBegin(int data);
        void insertENd(int data);
        void insertAT(int data , int index);
        void print();
        int size();
        void deleteAt(int index);
};
class queue{
    private:
        node *head;
        int size;
    public :
        queue();
        void enqueue(int data);
        void dequeue();
        void print();
        int sizeOfQ();
};
class stack{
    private :
        node *head;
        int *arr;
        int top;
    public :
        stack();                //constructot to initialize top=-1
        int size();             //To know the size of the stack
        void push(int data);    //To push a data into the stack by LIFO order
        void pop();             //To pop the last element as LIFO principle
        void peek();            //To print the element at the top of stack
        void print();           //To print the whole stack in the order top->bottom
};
class noder{                // I declared data public to keep it simple but can be private and 
    public :               //  all functions can be declared friend but this is just an example of implementation
        int data;
        noder *left,*right;
};
class BST{
    private :
        noder *root;
        int numberOfElements;
    public :
        BST();
        void insert(int data);
        void search(int data);
        void printLevel(int level);
};
void array:: deleteTheValue(int data){
    int temp[20]={0};
    int key=0;
    for(int i=0;i<sizeOfArray;i++){
        if(arr[i]==data){
            continue;
        }
        temp[key]=arr[i];
        key++;
    }
    for(int i=0;i<sizeOfArray-1;i++){
        arr[i]=temp[i];
    }
    this->sizeOfArray-=1;
    return;
}
array::array(){
    
}
int array::size(){
    return this->sizeOfArray;
}
void array:: setData(){
    cout<<"enter the size of the array :"<<endl;
    cin>>sizeOfArray;
    arr=new int[sizeOfArray];
    for(int i=0;i<sizeOfArray;i++){
        cout<<"enter the "<<i<<" index element :"<<endl;
        cin>>this->arr[i];
    }
    return;
}
void array:: printData(){
    for(int i=0;i<this->sizeOfArray;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
void array:: removeDuplicates(){
    int temp[20]={0};
    int realSize=0;
    for(int i=0;i<sizeOfArray;i++){
        int count=0;
        for(int j=0;j<realSize;j++){
            if(arr[i]==temp[j]){
                count++;
            }
        }
        if(count==0){
            temp[realSize]=arr[i];
            realSize++;
        }
    }
    for(int i=0;i<realSize;i++){
        arr[i]=temp[i];
    }
    sizeOfArray=realSize;
}
void array:: insert(int data,int index){
    int temp[20]={0};
    for(int i=0;i<sizeOfArray;i++){
        temp[i]=arr[i];
    }
    arr=new int[sizeOfArray+1];
    for(int i=0;i<sizeOfArray;i++){
        arr[i]=temp[i];
    }
    arr[sizeOfArray]=0;
   for(int i=sizeOfArray-1;i>=index;i--){
       int temp;
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
   }
   sizeOfArray++;
   arr[index]=data;
   return ;
}
queue::queue(){
    head=NULL;
    size=0;
}
void queue::enqueue(int data){
    if(size==0){
        head=new node;
        head->data=data;
        head->next=NULL;
        size++;
        return;
    }
    node *nodehere;
    nodehere=new node;
    nodehere->data=data;
    nodehere->next=head;
    head=nodehere;
    size++;
    return;
}
void queue::dequeue(){
    node *temp=head;
    node *previous;
    while(head->next!=NULL){
        previous=head;
        head=head->next;
    }
    previous->next=NULL;
    head=NULL;
    head=temp;
}
void queue::print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
int queue::sizeOfQ(){
    return this->size;
}
stack::stack(){
    top=-1;                
}
void stack::push(int data){
    if(top==-1){
        top++;
        head=new node;
        head->data=data;
        head->next=NULL;
        return;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    top++;
    return;
}
int stack::size(){                   //this is just to know the size of the linked list 
    return (this->top+1);
}
void stack::print(){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void stack::peek(){
    cout<<head->data<<endl;
}
void stack::pop(){
    top--;
    this->peek();
    head=head->next;
}
linkedlist::linkedlist(){
    sizer=0;
    head=NULL;
}
void linkedlist:: insertBegin(int data){
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    sizer++;
    return;
}
void linkedlist:: insertENd(int data){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    temp->next=newnode;
}
void linkedlist:: insertAT(int data , int index){
    node *temp=head;
    node *previous=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=temp;
    previous->next=newnode;
    return;
}
void linkedlist:: print(){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int linkedlist:: size(){
    return sizer;
}
void linkedlist::deleteAt(int index){
    if(index==0){
        head=head->next;
    }
    node *temp=head;
    node*previous=NULL;
    node *nextnode=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        nextnode=temp->next->next;
    }
    previous->next=nextnode;
    return;
}
void createnode(noder *&p,int data){
    p=new noder;
    p->data=data;
    p->left=NULL;
    p->right=NULL;
}
void printGivenLevel(noder *root,int level){
    noder *head=root;
    if (head == NULL)
        return;
    if (level == 1)
        printf("%d ", head->data);
    else if (level > 1)
    {
        printGivenLevel(head->left, level-1);
        printGivenLevel(head->right, level-1);
    }
}
BST::BST(){
    numberOfElements=0;
    root = NULL;
}
void BST::insert(int data){
    if(root==NULL){
        root=new noder;
        createnode(root,data);
        return;
    }
    noder *temp=root;
    noder *previous=NULL;
    while(temp!=NULL){
        previous=temp;
        if(temp->data==data){
            cout<<"the element is already present "<<endl;
            return;
        }
        else if(data<temp->data){
            temp=temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    noder *newnoder=new noder;
    createnode(newnoder,data);
    if(data<previous->data){
        previous->left=newnoder;
    }
    else{
        previous->right=newnoder;
    }
    return;
}
void BST::search(int data){
    noder *temp=root;
    while(temp!=NULL){
        if(temp->data==data){
            cout<<"the data is found"<<endl;
            return;
        }
        else if(data<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    cout<<"the "<<data<<" is not present in the BST"<<endl;
}
void BST::printLevel(int level){
    printGivenLevel(root,level);
    cout<<endl;
}
