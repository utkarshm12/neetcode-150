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
    int n = 1, ans = 0;
public:
    int maxDepth(TreeNode* root) {
        return find(root, n);
    }
    int find(TreeNode* root, int n){
        if(!root) return ans;
        ans = max(n, ans);
        find(root->left, n+1);
        find(root->right, n+1);
        return ans;


    }
};
