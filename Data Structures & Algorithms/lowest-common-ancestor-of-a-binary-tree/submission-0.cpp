/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ans(root, p, q);
    }

    TreeNode* ans(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q) return root;

        TreeNode* left = ans(root->left, p, q);
        TreeNode* right = ans(root->right, p, q);

        if(left != NULL && right != NULL) return root;
        if(left != NULL) return left;
        return right;
    }
};