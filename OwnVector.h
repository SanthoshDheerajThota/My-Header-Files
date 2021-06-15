#include <iostream>
using namespace std;
template <class T>
class nodehere{
    public :
        T data;
        nodehere<T> *nextnode;
};
template <class T>
class vector{
    private :
        nodehere<T> *head;
        int sizehere;
    public :
        vector(){
            sizehere=0;
        }
        void push_back(T data){
            if(sizehere==0){
                head=new nodehere<T>;
                head->data=data;
                head->nextnode=NULL;
                sizehere++;
                return;
            }
            nodehere<T> *newnode=new nodehere<T>;
            newnode->data=data;
            newnode->nextnode=head;
            head=newnode;
            sizehere++;
            return;
        }
        void pop_back(){
            head=head->nextnode;
            sizehere--;
            return;
        }
        T at(int index){
            nodehere<T> *temp=head;
            for(int i=0;i<index;i++){
                temp=temp->nextnode;
            }
            return temp->data;
        }
        void erase(int index){
            nodehere<T> *temp=head;
            nodehere<T> *previous=NULL;
            nodehere<T> *nextnode=NULL;
            if(index==0){
                head=head->nextnode;
            }
            for(int i=0;i<index;i++){
                previous=temp;
                temp=temp->nextnode;
                nextnode=temp->nextnode;
            }
            previous->nextnode=nextnode;
            return;
        }
        void print(){
            nodehere<T> *temp=head;
            while(temp->nextnode!=NULL){
                cout<<temp->data<<"   ";
                temp=temp->nextnode;
            }
            cout<<temp->data<<endl;
        }
        int size(){
            return sizehere;
        }
};
