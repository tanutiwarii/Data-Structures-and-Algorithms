#include <iostream>
#include <vector>
#include <queue>
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
int widthOfBinaryTree(Node* root) {
    queue <pair<Node*,unsigned long long>> q;
    q.push({root,0});
    int maxWidth = 0;

    while(q.size() > 0){
        int currLevelSize = q.size();
        unsigned long long stIdx = q.front().second;
        unsigned long long endIdx = q.back().second;

        maxWidth = max(maxWidth, (int)(endIdx - stIdx +1));

        for(int i = 0; i <currLevelSize; i++){
            auto curr = q.front();
            q.pop();

            if(curr.first -> left) q.push({curr.first -> left, curr.second*2 +1});
            if(curr.first -> right) q.push({curr.first -> right, curr.second*2 +2});
        }
    }
    return maxWidth;
}

// Helper function to print the tree (in-order traversal)
void printTree(Node* root) {
    if (root == NULL) {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// Main function
int main() {
    // Example 1: Simple binary tree
    vector<int> preOrder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    idx = -1; // Reset index
    Node* root1 = buildTree(preOrder1);
    
    cout << "Tree 1 (pre-order): ";
    printTree(root1);
    cout << endl;
    cout << "Width of tree 1: " << widthOfBinaryTree(root1) << endl;
    cout << endl;
    return 0;
}