class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int r = -1, c = -1;

        int s = 0, e = rows-1;
        int md = e/2;

        while(s <= e){
            if(target > matrix[md][cols-1]) s = md+1;
            else if(target < matrix[md][0]) e = md-1;
            else break;
            md = (s+e)/2;
        }
        r = md;

        s = 0, e = cols-1;
        md = e/2;

        while(s <= e){
            if(target > matrix[r][md]) s = md+1;
            else if(target < matrix[r][md]) e = md-1;
            else break;
            md = (s+e)/2;
        }
        c = md;

        if(matrix[r][c] == target) return true;
        return false;
    }
};
