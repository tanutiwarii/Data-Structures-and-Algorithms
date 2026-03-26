#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};
// Build BST
Node* build(vector<int>& preorder, int &i, int bound) {
    if (i >= preorder.size() || preorder[i] > bound)
        return NULL;
    Node* root = new Node(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);

    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

// Convert to level order (with nulls)
vector<string> levelOrder(Node* root) {
    vector<string> result;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr) {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing nulls
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    return result;
}

int main() {
    vector<int> preorder = {8,5,1,7,10,12};

    Node* root = bstFromPreorder(preorder);

    vector<string> output = levelOrder(root);

    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ",";
    }
    cout << "]"<<endl;

    return 0;
}