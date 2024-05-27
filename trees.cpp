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
    private:
        Node* root;

    public: 
        BinarySearchTrees(){
            root = nullptr;
        }

    void getRoot(){
        cout << "root: " << root->value << endl;
    }
};

int main(){
    BinarySearchTrees* MyBst = new BinarySearchTrees();

    MyBst->getRoot();


    return 0;
}