#include<iostream>
using namespace std;

class Node{
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree{
    public:
        Node* root;

        BinarySearchTree(){
            root = nullptr;
        }

        bool insert(int value){
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                return true;
            }

            Node* temp = root;
            while(true){
                if(newNode->value == temp->value) return false;

                if(newNode->value < temp->value){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }     
            }
        }

        bool contains(int value){
            if(root == nullptr) return false;
            Node* temp = root;

            while(temp){
                if(value < temp->value){
                    temp = temp->left;
                }
                else if(value > temp->value){
                    temp = temp->right;
                }
                else{
                    return true;
                }
            }
            return false;
        }
};



int main(){


    return 0;
}