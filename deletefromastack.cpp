#include<iostream>
using namespace std;

class Stack{
    public:
    int top ;
    int size;
    int *arr;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    bool Isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsFull(){
        if(top==size-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int value){
        if(!IsFull()){
            top=top+1;
            arr[top] = value;
        }
        else{
            cout<<"Stack is Full."<<endl;
        }
    }

    int pop(){
        if(!Isempty()){
            int x =arr[top];
            top = top-1;
            return x;
        }
        else{
            cout<<"Stack is empty."<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty."<<endl;
        }
    }

    void solve(Stack& s , int size , int ctr){
        if(ctr==size/2){
            s.pop();
            return ;
        }
        int num = s.peek();
        s.pop();
        solve(s,size,ctr+1);
        s.push(num);
    }

    void deletemiddleval(Stack& s , int size){
        int ctr=0;
        solve(s,size,ctr);
    }
};

int main(){
    Stack s(5);
    s.push(15);
    s.push(25);
    s.push(35);
    s.push(45);
    s.push(55);
    s.deletemiddleval(s,5);
    
    while(!s.Isempty()){
        cout<<"The element in the stack is: "<<s.peek()<<endl;
        s.pop();
    }
}