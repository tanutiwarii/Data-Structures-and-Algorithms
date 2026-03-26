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
void KthLevel(Node* root, int k){
    if(root == NULL) return;
    if(k == 1){
        cout<< root -> data<< " ";
        return;
        
    }
    KthLevel(root -> left, k -1);
    KthLevel(root -> right, k -1);
}

int main(){
    vector <int> preorder = {1, 2, 7, -1, -1,-1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    KthLevel(root, 3);
    return 0; 
}