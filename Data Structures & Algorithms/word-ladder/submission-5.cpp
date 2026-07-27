class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        vector<string> finds;
        q.push(beginWord);
        int ans = 1, id = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                string s = q.front();

                if(s == endWord) return ans;

                for(auto w : wordList){
                    if(match(s, w)){
                        q.push(w);
                        finds.push_back(w);
                    }
                }

                while(id < finds.size())
                    wordList.erase(find(wordList.begin(), wordList.end(), finds[id++]));
                q.pop();
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
