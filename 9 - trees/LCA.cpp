#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector <int> preOrder){
    idx++;

    if(preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);
    root -> left = buildTree(preOrder);
    root -> right = buildTree(preOrder);

    return root;
}
Node* findNode(Node* root, int val) {
    if(root == NULL) return NULL;
    if(root->val == val) return root;

    Node* leftSearch = findNode(root->left, val);
    if(leftSearch != NULL) return leftSearch;

    return findNode(root->right, val);
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL){
        return NULL;
    }
    if(root -> val == p -> val || root -> val == q -> val) return root;
    Node* leftLCA = lowestCommonAncestor(root -> left, p,q);
    Node* rightLCA = lowestCommonAncestor(root -> right, p,q);

    if(leftLCA && rightLCA) return root;
    else if(leftLCA != NULL) return leftLCA;
    else return rightLCA;
}

int main(){
    vector <int> p = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1
};
    Node* root = buildTree(p);
    Node* node1 = findNode(root, 5);
    Node* node2 = findNode(root, 4);

    Node* lca = lowestCommonAncestor(root, node1, node2);
    if(lca != NULL)
        cout << lca->val << endl;
    else
        cout << "Nodes not found in tree!" << endl;

    return 0;

}