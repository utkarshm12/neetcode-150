/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int id = 0;
        return build(preorder, inorder, id, 0, preorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& id, int s, int e){
        if(s > e) return NULL;

        int i;
        for(i = 0; inorder[i] != preorder[id]; i++);
        TreeNode* root = new TreeNode(preorder[id++]);

        root->left = build(preorder, inorder, id, s, i-1);
        root->right = build(preorder, inorder, id, i+1, e);

        return root;
    }
};
