#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
        int value;
        Node* next;

        Node(int val){
            value = val;
            next = nullptr;
        }
};


class Stack{
    private:
        Node* top;
        int height;
    
    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack(){
            Node* temp = top;
            while (temp!=nullptr){
                cout<<temp->value<<" ";
                temp = temp->next;
            } 
            cout<<endl;
        }

        void getTop(){
            cout<<"Top: "<<top->value<<endl;
        }
        void getHeight(){
            cout<<"Height: "<<height<<endl;
        }

        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop(){
            if (height == 0) return INT_MIN;
            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;

            return poppedValue;
        }

};



int main(){
    Stack* myStack = new Stack(10);
    myStack->push(20);

    myStack->printStack();
    myStack->getTop();
    myStack->getHeight();
    cout<<"pop: "<<myStack->pop()<<endl;
    myStack->printStack();
    myStack->getTop();
    myStack->getHeight();
    return 0;
}