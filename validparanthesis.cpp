#include<iostream>
using namespace std;

class Stack{
    public:
    int top;
    char *arr;
    int size;

    Stack(int size){
        top = -1;
        arr = new char[size];
        this->size = size;
    }

    Stack(){
        top = -1;
    }

    void push(char val){
        if(top <= size-1){
            top++;
            arr[top] = val;
        }
        else{
            cout<<"stack is full "<<endl;
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

    char pop(){
        if(!isempty()){
            char val = arr[top];
            top--;
            return val;
        }
        else{
            cout<<"Stack is empty "<<endl;
        }
    }
    char peek(){
        if(!isempty()){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    bool matches(char topvalue , char closingbracket){
        if(topvalue == '(' && closingbracket == ')'){
            return true;
        }
        else if(topvalue == '[' && closingbracket == ']'){
            return true;
        }
        else if(topvalue == '{' && closingbracket == '}'){
            return true;
        }
        else{
            return false;
        }
    }

    bool checkparanthesis(string expression){
        int i;
        char c;
        Stack s(expression.length());
        for(i=0;i<expression.length();i++){
            c = expression[i];

            //checking for opening baracket
            if(c=='[' || c=='{' || c=='('){
                s.push(c);
            }
            //checking for closing baracket
            else{
                if(!s.isempty()){
                    char top = s.peek(); 
                    if(matches(top,c)){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(isempty()){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    string expression = "[{()}]";
    Stack s(expression.length());
    if(s.checkparanthesis(expression)){
        cout<<"Valid expression"<<endl;
    }
    else{
        cout<<"InValid expression"<<endl;
    }
}