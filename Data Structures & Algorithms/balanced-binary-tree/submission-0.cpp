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
    bool res = true;
    int h = 0;
public:
    bool isBalanced(TreeNode* root) {
        ans(root, h);
        return res;
    }

    int ans(TreeNode* root, int height){
        if(!root) return 0;

        int left = ans(root->left, height+1);
        int right = ans(root->right, height+1);

        if(abs(left-right) > 1) res = false;

        return 1 + max(left, right);

    }
};
