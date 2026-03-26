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

//pre-order traversal (root, left, right)
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<< root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

//in-order traversal (left, root, right)
void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root -> left);
    cout<< root -> data <<" ";
    inOrder(root -> right);
}

//post-order traversal (left, right, root)
void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout<< root -> data <<" ";
}

int main(){
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    cout << root -> data <<endl;
    cout << root -> left -> data <<endl;
    cout << root -> right -> data <<endl;

    preOrder(root);  //1 2 3 4 5 
    cout<<endl;

    inOrder(root);   //2 1 4 3 5 
    cout<<endl;

    postOrder(root); //2 4 5 3 1 
    cout<<endl;
    return 0; 
}