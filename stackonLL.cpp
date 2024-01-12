#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    public:
    Node *top;

    Stack(){
        top=  NULL;
    }
    int getlength(){
        int ctr=0;
        Node *temp = top;
        while(temp!=NULL){
            ctr++;
            temp = temp->next;
        }   
        return ctr; 
    }

    void push(int data){
        Node *newnode = new Node(data);
        newnode->next = top;
        top=newnode;
    }
    void pop(){
        int val = getlength();
        if(val<=0){
            cout<<"The Stack is empty . "<<endl;
        }
        else{
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete[] temp;
        }
    }
    void display(){
        Node *temp = top;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
            pop();
        }
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.display();
}