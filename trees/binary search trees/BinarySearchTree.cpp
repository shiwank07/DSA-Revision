#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* right;
        Node* left;

        Node(int value){
            this->value = value;
            right = nullptr;
            left = nullptr;
        }
};

class BinarySearchTrees{
    public:
        Node* root;

    public: 
        BinarySearchTrees(){
            root = nullptr;
        }

    bool insert(int value){
        Node* newNode = new Node(value);
        if (root == nullptr){
                root  = newNode;
                return true;
        }

        Node* temp = root;
        while (true){
            if (newNode->value == temp->value) 
                return false;

            if (newNode->value < temp->value){
                if (temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool containes(int value){
        Node* temp = root;
        while (temp){
            if (value < temp->value){
                temp = temp->left;
            } else if (value > temp->value){
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;    
    }

    void inOrderPrint(Node* node) {
        if (node == nullptr) return;
        inOrderPrint(node->left);
        cout << node->value << " ";
        inOrderPrint(node->right);
    }

    void printTree() {
        inOrderPrint(root);
        cout << endl;
    }

};

int main(){
    BinarySearchTrees* MyBst = new BinarySearchTrees();

    MyBst->insert(45);
    MyBst->insert(21);
    MyBst->insert(76);
    MyBst->insert(15);
    MyBst->insert(89);
    MyBst->insert(10);
    MyBst->insert(48);
    MyBst->insert(9);

    cout << "Contains 10:" << MyBst->containes(10) << endl;
    cout << "Contains 11:" << MyBst->containes(11) << endl;

    MyBst->printTree();

    return 0;
}