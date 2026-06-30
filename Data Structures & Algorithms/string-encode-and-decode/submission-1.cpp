class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(auto s : strs){
            int n = s.length();
            res += to_string(n) + '#' + s;
        }
        cout << res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        for(int i = 0; i < s.size(); i++){
            string val = "";
            while(s[i] != '#') val += s[i], i++;
            int sz = stoi(val);
            string temp = "";

            for(int j = i+1; j <= i+sz; j++) temp += s[j];
            i += sz;
            res.push_back(temp);
        }
        

        return res;
    }
};
