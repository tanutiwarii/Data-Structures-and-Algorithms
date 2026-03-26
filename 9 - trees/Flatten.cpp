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
Node* nextRight = NULL;
void flatten (Node* root){

    if(root == NULL) return;

    flatten(root -> right);
    flatten(root -> left);

    root -> left = NULL;
    root -> right = nextRight;
    nextRight = root;
}

int main(){
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    flatten(root);
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}