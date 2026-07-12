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
    bool ans = true;
public:
    bool isValidBST(TreeNode* root) {

        // check(root->left, root->val, INT_MIN);
        // check(root->right, INT_MAX, root->val);

        check(root, INT_MAX, INT_MIN);
        return ans;
    }

    void check(TreeNode* root, int mx, int mn){
        if(!root) return;
        // if((root->left && (root->left->val >= mx || root->left->val <= mn)) || (root->right && (root->right->val >= mx || root->right->val <= mn))){
        //     ans = false;
        //     return;
        // }
        if(root->val >= mx || root->val <= mn){
            ans = false;
            return;
        }
        check(root->left, root->val, mn);
        check(root->right, mx, root->val);
    }
};
