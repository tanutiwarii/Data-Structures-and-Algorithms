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

int sumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = sumOfNodes(root -> left);
    int rightSum = sumOfNodes(root -> right);
    return leftSum + rightSum + root -> data;    //+ 1 for root 
}
int main(){
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout<<"Sum: "<<sumOfNodes(root) << endl;
    return 0; 
}