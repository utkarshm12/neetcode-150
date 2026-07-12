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
    int c = 0;
public:
    int goodNodes(TreeNode* root) {
        find(root, root->val);
        return c;
    }

    void find(TreeNode* root, int mx){
        if(!root) return;
        if(root->val >= mx) c++;
        if(mx < root->val) mx = root->val;
        find(root->left, mx);
        find(root->right, mx);
    }
};
