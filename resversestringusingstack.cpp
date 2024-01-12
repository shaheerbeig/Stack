#include<iostream>
#include<string>
using namespace std;

class Stack{
    public:
    int size;
    int top = -1;
    char *arr;

    Stack(int size){
        this->size = size;
        top = -1;
        arr = new char[size];
    }
    void push(char val){
        if(top<=size-1){
            top = top + 1;
            arr[top] = val;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    char pop(){
        if(top>=0){
            char val = arr[top];
            top--;
            return val;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string name = "shaheer";
    Stack s(name.length());
    int i;
    string reverse;
    char temp ;
    for(i=0;i<name.length();i++){
        s.push(name[i]);
    }
    while(!s.isempty()){
        reverse += s.pop();
    }
    cout<<reverse<<endl;
}