
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// a struct that can satisfy the requirement of a binary tree
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r), parent(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r, TreeNode* p) : val(x), left(l), right(r), parent(p) {}
};


// a function that can do the right rotation
void rightRotate(TreeNode* root)
{
    TreeNode* left = root->left;
    TreeNode* right = left->right;
    left->right = root;
    root->left = right;
    if (right != NULL)
        right->parent = root;
    if (root->parent != NULL)
    {
        if (root->parent->left == root)
            root->parent->left = left;
        else
            root->parent->right = left;
    }
    left->parent = root->parent;
    root->parent = left;
}
// a function that can print the tree in order traversal
void printTree(TreeNode* root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}


int main()
{

    //binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4, NULL, NULL, root->left);
    root->left->right = new TreeNode(5, NULL, NULL, root->left);
    root->right->left = new TreeNode(6, NULL, NULL, root->right);
    root->right->right = new TreeNode(7, NULL, NULL, root->right);
    printTree(root);
}