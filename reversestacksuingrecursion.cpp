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

    void insertatbottom(Stack& s , int x){
        if(s.Isempty()){
            s.push(x);
            return ;
        }
        int val = s.peek();
        s.pop();

        insertatbottom(s,x);

        s.push(val);
    }

    void reversestack(Stack& s ){
        if(s.Isempty()){
            return;
        }

        int num = s.peek();
        s.pop();
        reversestack(s);

        insertatbottom(s,num);
    }
    void display(){
        int i;
        for(i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    Stack s(5);
    s.push(15);
    s.push(25);
    s.push(35);
    s.push(45);
    s.push(55);
    
    s.display();

    s.reversestack(s);
    cout<<endl;
    s.display();
}
