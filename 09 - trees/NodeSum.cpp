#include <iostream>
#include <vector>
using namespace std;


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
//pre-order traversal (root, left, right)
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<< root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}


int sum(Node* root){
    if(root == NULL) return 0;
    int leftSum = sum(root -> left);
    int rightSum = sum(root -> right);
    return root -> data = leftSum + rightSum + root->data;
}
int main(){
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    preOrder(root);  //1 2 3 4 5 
    cout<<endl;
    sum(root);
    preOrder(root);  //1 2 3 4 5 
    cout<<endl;

    
}