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

static int idx = -1;
Node* buildTree(vector <int> preOrder){
    idx++;
    if(preOrder[idx] == -1) return NULL;
    Node* root = new Node(preOrder[idx]);
    root -> left = buildTree(preOrder);
    root -> right = buildTree(preOrder);

    return root;
}

Node* helper(vector <int>& nums, int st, int end){
    if(st> end) return NULL;
    int mid = st +(end - st)/2;
    Node* root = new Node( nums[mid]);
    root -> left = helper(nums, st, mid -1);
    root -> right = helper(nums, mid +1, end);

    return root;
}

Node* sortedArrayTree(vector <int>& nums){
    return helper(nums, 0, nums.size() - 1);
}

// simple inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    vector <int> nums = {-10, 3, 0, 5, 9};
    Node* root = sortedArrayTree(nums);
    inorder(root);
    cout<<endl;
}