class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size(), l = 0;
        if(l1 > l2) return false;

        vector<int> f1(26), f2(26);

        for(auto ch : s1) f1[ch-'a']++;

        for(int i = 0; i < l2; i++){
            f2[s2[i]-'a']++;
            if(i >= l1-1){
                if(f1 == f2) return true;
                f2[s2[l++]-'a']--;
            }
        }

        return false;


    }
};
