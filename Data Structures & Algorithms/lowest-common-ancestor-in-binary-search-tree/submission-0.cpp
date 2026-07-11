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
    bool pf = false, qf = false;
    TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = min(p->val, q->val);
        int high = max(p->val, q->val);
        ans(root, low, high);
        return res; 
    }

    void ans(TreeNode* root, int p, int q){
        if(root == NULL) return;
        int val = root->val;
        if(val > p && val > q) ans(root->left, p, q);
        else if(val < p && val < q) ans(root->right, p, q);
        else res = root;
    }
};
