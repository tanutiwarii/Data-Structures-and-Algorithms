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

// brute force approach O(n*n) Complexity
int height( Node* root){
    if (root == NULL) return 0;
     int leftHt = height( root -> left);
     int rightHt = height( root -> right);
     return max( leftHt, rightHt) + 1;
}

int diameterOfTree( Node* root){
    if (root == NULL) return 0;
    int leftDiam = diameterOfTree( root -> left);
    int rightDiam = diameterOfTree( root -> right);
    int currDiam = height(root -> left) + height(root -> right);
    
    return max( currDiam, max(leftDiam, rightDiam));
}

// optimized approach O(n) Complexity
int ans = 0;
int optimizedHeight( Node* root){
    if (root == NULL) return 0;
    int leftHt = optimizedHeight( root -> left);
    int rightHt = optimizedHeight( root -> right);
    ans = max(ans, leftHt +rightHt);
    return max( leftHt, rightHt) + 1;
}

int optimizedDiameterOfTree( Node* root){
    optimizedHeight(root);
    
    return ans;
}

int main(){
    vector <int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout<<"Diameter: "<<diameterOfTree(root) << endl;               // brute force approach O(n*n) Complexity
    cout<<"Optimized Diameter: "<<optimizedDiameterOfTree(root) << endl;      // optimized approach O(n) Complexity
    return 0; 
}