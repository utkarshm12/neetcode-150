class Solution {
public:
    bool isValid(string s) {
        string temp = "";
        int sz = 0;

        for(auto ch : s){
            temp += ch;
            sz ++;

            if(sz > 1){
                if( temp[sz-2] == '(' && temp[sz-1] == ')' || 
                    temp[sz-2] == '[' && temp[sz-1] == ']' ||
                    temp[sz-2] == '{' && temp[sz-1] == '}'
                )
                temp.erase(sz-2, 2), sz -= 2;
            }

        }

        if(temp == "") return true;
        return false;
    }
};
