#include<iostream>
#include<vector>
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

int static idx = -1;

Node* buildTree(vector <int> arr){
    idx++;
    if(arr[idx] == -1) return NULL;
    Node* root = new Node(arr[idx]);
    root -> left = buildTree(arr);
    root -> right = buildTree(arr);

    return root;
}
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<< root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

bool helper(Node* root, Node* min, Node* max){
    if(root == NULL) return true;
    if(min != NULL && root -> data <= min -> data) return false;
    if(max != NULL && root -> data >= max -> data) return false;

    return helper(root -> left, min, root) && helper(root -> right, root, max);
}

bool validateBST(Node* root){
    return helper(root, NULL, NULL);
}
int main(){
    vector <int> arr = {3, 2, -1, -1, 5, 4, -1, -1, 6, -1, -1};
    Node* root = buildTree(arr);
    preOrder(root);
    cout<<endl;
    if (validateBST(root))
        cout << "The tree is a valid BST" << endl;
    else
        cout << "The tree is NOT a valid BST" << endl;

}