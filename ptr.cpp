#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* subTree(vector<int>& preorder, int plow, int phigh, vector<int>& inorder, int ilow, int ihigh) {
    cout << plow <<" "<< phigh <<" "<< ilow <<" "<< ihigh << endl;
    if(plow<phigh){
        return NULL; 
    }
    TreeNode *root = new TreeNode(preorder[plow]);
    int mid = ilow;
    while(inorder[mid]!=preorder[plow]){
        mid++;
    }
    
    cout << plow+1 <<" "<< plow+mid-ilow <<" "<< ilow <<" " << mid-1 << endl;
    cout << plow+mid-ilow+1 <<" "<< phigh <<" "<< mid+1 <<" "<< ihigh << endl;
    TreeNode*left = subTree(preorder, plow+1, plow+mid-ilow, inorder, ilow, mid-1);
    TreeNode*right = subTree(preorder,plow+mid-ilow+1, phigh, inorder, mid+1, ihigh);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int size = preorder.size();
    return subTree(preorder, 0, size-1, inorder, 0, size-1);
}

void print(TreeNode*root){
    if(root){
        cout << root->val<<" ";
        print(root->left);
        print(root->right);
    }
}

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode*root = buildTree(preorder, inorder);
    print(root);
}