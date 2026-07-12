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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> v;
        string ans="";
        travel(root, v);
        for(int i = 0; i < v.size(); i++){
            ans += v[i];
        }

        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        int s = 0;
        string temp;

        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                v.push_back(temp);
                temp = "";
            }
            else temp += data[i];
        }
        return create(v, s);
    }
    
    void travel(TreeNode*& root, vector<string>& v){
        if(!root){
            v.push_back("n,");
            return;
        }

        v.push_back(to_string(root->val)+',');
        travel(root->left, v);
        travel(root->right, v);

    }

    TreeNode* create(vector<string>& data, int& i){
        if(data[i] == "n"){
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(data[i++]));
        root->left = create(data, i);
        root->right = create(data, i);
        return root;
    }
};
