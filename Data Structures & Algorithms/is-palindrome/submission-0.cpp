class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);


        while(i < j){
            while((s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9') && i < j) i++;
            while(j > i && (s[j] < 'a' || s[j] > 'z') && (s[j] < '0' || s[j] > '9')) j--;
            cout << s[i] << s[j] << endl;
            if(s[i] != s[j]) return false;
            i++, j--;
        }

        return true;
    }
};
