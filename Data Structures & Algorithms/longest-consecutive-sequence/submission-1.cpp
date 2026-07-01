class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num;
        vector<int> cp;

        for(auto i : nums) num.insert(i);
        for(auto i: num) cp.push_back(i);

        int mx = 1, c = 1;
        for(int i = 1; i < num.size(); i++){
            if(cp[i] - 1 == cp[i-1]){
                c++;
            }
            else c = 1;

            mx = max(mx, c);
        } 

        return nums.size() == 0 ? 0 : mx;
    }
};
