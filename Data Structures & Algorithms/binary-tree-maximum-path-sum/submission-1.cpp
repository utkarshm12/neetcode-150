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
    int sum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        calc(root);
        return sum;
    }

    int calc(TreeNode* root){
        if(!root) return INT_MIN;

        int left = max(0, calc(root->left));
        int right = max(0, calc(root->right));
        
        sum = max(sum, max(root->val+left, max(root->val+right, max(root->val+left+right, root->val))));
        return root->val + max(left, right);
    }
};
