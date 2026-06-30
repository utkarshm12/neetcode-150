class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> vals;
        for(auto i : nums) vals.insert(i);
        return vals.size() != nums.size();
    }
};