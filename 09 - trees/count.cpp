#include <iostream>
#include <vector>
using namespace std;


//structure of the tree
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//building tree using pre-order sequence
static int idx = -1;
Node* buildTree(vector <int> preOrder){
    idx++;

    if(preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);
    root -> left = buildTree(preOrder);
    root -> right = buildTree(preOrder);

    return root;
}

int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount = count(root -> left);
    int rightCount = count(root -> right);
    return leftCount + rightCount + 1;    //+ 1 for root 
}
int main(){
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout<<"Count: "<<count(root) << endl;
    return 0; 
}