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
    bool res = false;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        ans(root, subRoot);
        return res;
    }

    void ans(TreeNode* root, TreeNode* sub){
        if(!root || !sub || res) return;
        if(root->val == sub->val){
            res = true;   
            check(root, sub);
        }
        ans(root->left, sub);
        ans(root->right, sub);
        
    }

    void check(TreeNode* root, TreeNode* sub){
        if(!root && !sub)  return;
        if(!root || !sub || root->val != sub->val) {
            res = false;
            return;
        }
        check(root->left, sub->left);
        check(root->right, sub->right);
    }
};
