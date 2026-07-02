class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> f;
        int l = 0, mx = 0, ans = 0;

        for(int i = 0; i < s.length(); i++){
            f[s[i]]++;
            mx = max(mx, f[s[i]]);

            while((i-l+1) - mx > k) f[s[l++]]--;

            ans = max(ans, i-l+1);
        }

        return ans;
    }
};
