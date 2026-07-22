class Node{
public:
    unordered_map<char, Node*> links;
    string word;
};

class Solution {
    Node* root = new Node();
    int row, col;
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size(), col = board[0].size();

        for(auto word: words) form(root, word);
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(root->links[board[i][j]]){
                    check(board, root, i, j);
                }
            }
        }

        return ans;
    }

    void form(Node* root, string& word){
        Node* node = root;
        for(auto ch: word){
            if(!node->links[ch]) node->links[ch] = new Node();
            node = node->links[ch];
        }
        node->word = word;
    }

    void check(vector<vector<char>>& board, Node* root, int i, int j){
        char temp = board[i][j];
        Node* node = root;

        if(temp == '0' || !node->links[temp]) return;

        board[i][j] = '0';
        node = node->links[temp];
        
        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        if(i+1 < row) check(board, node, i+1, j);
        if(i > 0) check(board, node, i-1, j);
        if(j+1 < col)check(board, node, i, j+1);
        if(j > 0) check(board, node, i, j-1);

        board[i][j] = temp;
    }

};
