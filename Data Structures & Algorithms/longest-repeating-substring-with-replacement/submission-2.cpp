class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_set<char> ch;
        vector<int> freq(26);
        int id = 0, len = 0;

        for(int i = 0; i < n; i++){
            ch.insert(s[i]);
            freq[s[i]-'A']++;

            if(ch.size() > 1){
                int all = 0, mx = 0;
                for(auto c : ch) all += freq[c-'A'], mx = max(mx, freq[c-'A']);
                while(all - mx > k){
                    if(freq[s[id]-'A'] == 1) ch.erase(freq[s[id]-'A']);
                    freq[s[id++]-'A']--;
                    all = 0, mx = 0;
                    for(auto c : ch) all += freq[c-'A'], mx = max(mx, freq[c-'A']);
                }
            }

            len = max(len, i-id+1);
            // cout << id << " ";
        }

        return len;
    }
};
