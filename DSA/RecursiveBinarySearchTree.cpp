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

    //Recursion

        Node* rInsert(Node* currentNode, int value){
            if(currentNode == nullptr) return new Node(value);
            if(value < currentNode->value){
                currentNode->left = rInsert(currentNode->left,value);
            }else if(value > currentNode->value){
                currentNode->right = rInsert(currentNode->right,value);
            }
            return currentNode;
        }

        void rInsert(int value){
            if(root == nullptr) root = new Node(value);
            rInsert(root, value);
        }

        bool rcontains(Node* currentNode, int value){
            if(currentNode == nullptr) return false;
            if(currentNode->value == value) return true;
            if(value < currentNode->value){
                return rcontains(currentNode->left, value);
            }else{
                return rcontains(currentNode->right,value);
            }
        }

        bool rcontains(int value){
            return rcontains(root, value);
        }

        int minValue(Node* currentNode){
            while(currentNode->left != nullptr){
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }

        Node* deleteNode(Node* currentNode, int value){
            if(currentNode == nullptr) return nullptr;
            if(value < currentNode->value){
                currentNode->left = deleteNode(currentNode->left, value);
            }else if(value > currentNode->value){
                currentNode->right = deleteNode(currentNode->left, value);
            }else{
                if(currentNode->left == nullptr && currentNode->right == nullptr){
                    delete(currentNode);
                    return nullptr;
                }else if(currentNode->left == nullptr){
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                }else if(currentNode->right == nullptr){
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                }else{
                    int subtreeMin = minValue(currentNode->right);
                    currentNode->value = subtreeMin;
                    currentNode->right = deleteNode(currentNode->right,subtreeMin);
                }
            }
            return currentNode;
        }

        void deleteNode(int value){
            root = deleteNode(root, value);
        }

        
};



int main(){


    return 0;
}