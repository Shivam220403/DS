#include<iostream>
#include<queue>
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

class BinaryTree{
    public:
        Node* root;

        BinaryTree(){
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

        void BFS(){
            queue<Node*> myQueue;
            myQueue.push(root);

            while(myQueue.size() > 0){
                Node* currentNode = myQueue.front();
                myQueue.pop();
                cout<<currentNode->value<<" ";
                if(currentNode->left != nullptr){
                    myQueue.push(currentNode->left);
                }
                if(currentNode->right != nullptr){
                    myQueue.push(currentNode->right);
                }
            }
        }

        void DFSPreOrder(Node* currentNode){
            cout<<currentNode->value<<" ";
            if(currentNode->left != nullptr){
                DFSPreOrder(currentNode->left);
            }
            if(currentNode->right != nullptr){
                DFSPreOrder(currentNode->right);
            }
        }
        void DFSPreOrder(){
            DFSPreOrder(root);
        }


        void DFSPostOrder(Node* currentNode){
            if(currentNode->left != nullptr){
                DFSPreOrder(currentNode->left);
            }
            if(currentNode->right != nullptr){
                DFSPreOrder(currentNode->right);
            }
            cout<<currentNode->value<<" ";
        }
        void DFSPostOrder(){
            DFSPostOrder(root);
        }


        void DFSInOrder(Node* currentNode){
            if(currentNode->left != nullptr){
                DFSPreOrder(currentNode->left);
            }
            cout<<currentNode->value<<" ";
            if(currentNode->right != nullptr){
                DFSPreOrder(currentNode->right);
            }
        }
        void DFSInOrder(){
            DFSInOrder(root);
        }
};



int main(){
    BinaryTree tree;

    // Inserting nodes into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "BFS Traversal: ";
    tree.BFS();
    cout << endl;

    // Checking if certain values are in the tree
    cout << "Contains 7: " << (tree.contains(7) ? "Yes" : "No") << endl;
    cout << "Contains 20: " << (tree.contains(20) ? "Yes" : "No") << endl;

    // DFS PreOrder Traversal
    cout << "DFS PreOrder Traversal: ";
    tree.DFSPreOrder();
    cout << endl;

    // DFS PostOrder Traversal
    cout << "DFS PostOrder Traversal: ";
    tree.DFSPostOrder();
    cout << endl;

    // DFS InOrder Traversal
    cout << "DFS InOrder Traversal: ";
    tree.DFSInOrder();
    cout << endl;

    return 0;
}