class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int id = 0, len = 0;
        unordered_map<char, int> freq;

        for(int i = 0; i < n; i++){
            if(freq[s[i]] != 0){
                while(freq[s[i]] != 0){
                    freq[s[id]]--;
                    id++;
                }
            }
            freq[s[i]]++;
            len = max(len, i-id+1);
            cout << i << " " << id << " \n";
        }

        return len;
    }
};
