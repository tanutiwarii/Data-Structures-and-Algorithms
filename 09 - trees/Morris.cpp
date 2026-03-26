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
vector <int> inorder(Node* root){
    vector <int> ans;
    Node* curr = root;

    while(curr != NULL){
        if(curr -> left == NULL){
            ans.push_back(curr -> data);
            curr = curr->right;
        }else{
            Node* IP = curr -> left;
            while(IP -> right != NULL && IP -> right != curr){
                IP = IP -> right;
            }
            if(IP -> right == NULL){
                IP -> right = curr; //create
                curr = curr -> left;
            }else{
                IP -> right = NULL;
                ans.push_back(curr -> data);
                curr = curr -> right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, 8, 9, -1, -1, -1, -1};
    Node* root = buildTree(preorder);

    vector<int> ans = inorder(root);
    cout << "Inorder traversal (Morris): ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}