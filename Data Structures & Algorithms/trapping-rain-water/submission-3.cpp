class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;

        for(int i = 0; i < n; i++){

            int j = i+1;
            int blocks = height[j];
            int mx = 0;
            int id = -1;
            int blocks_till = 0;

            while(j < n && height[j] < height[i]){
                if(mx <= height[j]){
                    mx = height[j];
                    id = j;
                    blocks_till = blocks;
                }
                j ++;
                blocks += j < n ? height[j] : 0;
            }

            if(j < n){
                sum += (height[i] * (j-i-1)) - blocks + height[j];
                i = j-1;
            }
            else if (id > 0){
                sum += (height[id] * (id-i-1)) - blocks_till + height[id];
                i = id-1;
            }
            else break;
            
        }

        return sum;
        
    }
};
