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
    int mx = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {\
        d(root);
        return mx;
    }

    int d(TreeNode* root){
        if(!root) return 0;

        int mxl = d(root->left);
        int mxr = d(root->right);

        mx = max(mx, mxl+mxr);
        return 1 + max(mxl, mxr);

    }
};
