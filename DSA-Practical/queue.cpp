#include<bits/stdc++.h>
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

class Queue{
    private:
        Node* first;
        Node* last;
        int height;
    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            height = 1;
        }

        void printQueue(){
            Node* temp = first;
            while (temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void getTop(){
            cout<<"Top: "<<first->value<<endl;
        }

        void getBottom(){
            cout<<"Bottom: "<<last->value<<endl;
        }

        void getLength(){
            cout<<"length: "<<height<<endl;
        }

        void enQueue(int value){
            Node* newNode = new Node(value);
            if(height == 0){
                first = newNode;
                last = newNode;
            }else{
                last->next = newNode;
                last = newNode;
            }
        }

        int deQueue(){
            if(height == 0) return INT_MIN;
            Node* temp = first;
            int deQueuedValue = first->value;
            if(height == 1){
                first = nullptr;
                last = nullptr;
            }else{
                first = first->next;
            }
            delete temp;
            height--;
            return deQueuedValue;
        }
};



int main(){
    return 0;
}