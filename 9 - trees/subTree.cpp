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
Node* buildTree(vector<int>& preOrder, int& idx) {
    if (idx >= preOrder.size() || preOrder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preOrder[idx++]);
    root->left = buildTree(preOrder, idx);
    root->right = buildTree(preOrder, idx);

    return root;
}

bool isSameTree(Node* p, Node* q){
    if( p == NULL || q == NULL) return p ==q;

    bool isLeftSame = isSameTree(p -> left, q -> left);
    bool isRightSame = isSameTree(p -> right, q -> right);
    return isLeftSame && isRightSame && p -> data == q -> data;
}

bool isSubTree( Node* root, Node* subRoot){
    if(root == NULL || subRoot == NULL) return root == subRoot;

    if(root -> data == subRoot -> data && 
    isSameTree(root, subRoot)) return true;

    return isSubTree(root -> left, subRoot) || 
            isSubTree( root -> right, subRoot);
}
int main(){
    vector <int> p = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector <int> q = {3, 4, -1, -1, 5, -1, -1};
    int idx1 = 0, idx2 = 0;
    Node* root1 = buildTree(p, idx1);
    Node* root2 = buildTree(q, idx2);

    cout << (isSubTree(root1, root2) ? "true" : "false")<<endl;

    return 0; 
}