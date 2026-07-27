class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> list;
        unordered_map<string, bool> visited;

        vector<string> words;
        words.push_back(beginWord);
        int id = 0;

        while(id < words.size()){
            bool found = false;
            for(auto w : wordList){
                if(match(words[id], w)){
                    found = true;
                    words.push_back(w);
                    list[words[id]].push_back(w);
                    list[w].push_back(words[id]);
                }
            }
            auto it = find(wordList.begin(), wordList.end(), words[id]);

            if (it != wordList.end()) wordList.erase(it);
            // if(id>0) wordList.erase(find(wordList.begin(), wordList.end(), words[id]));
            id++;
        }

        queue<string> q;
        q.push(words[0]);
        int ans = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){

                string s = q.front();
                visited[s] = true;
                q.pop();

                for(auto word: list[s]){
                    if(!visited[word]) q.push(word);
                    if(word == endWord) return ans + 1;
                }

            }
            ans ++;
        }

        return 0;

    }

    bool match(string& s1, string& s2){
        int c = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) c++;
            if(c > 1) return false;
        }
        return c == 1;
    }
};
