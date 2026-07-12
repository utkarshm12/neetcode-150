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
        unordered_map<int, int> mp;
        int id = 0, n = inorder.size();
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        return build(preorder, mp, id, 0, preorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder, int& id, int s, int e){
        if(s > e) return NULL;

        int i = inorder[preorder[id]];
        TreeNode* root = new TreeNode(preorder[id++]);

        root->left = build(preorder, inorder, id, s, i-1);
        root->right = build(preorder, inorder, id, i+1, e);

        return root;
    }
};
