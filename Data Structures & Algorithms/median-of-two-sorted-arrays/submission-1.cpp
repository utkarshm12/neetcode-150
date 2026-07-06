class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0, e1 = nums1.size(), e2 = nums2.size();
        int total = e1 + e2;
        int mid = (total+1)/2;

        if(e1 > e2) return findMedianSortedArrays(nums2, nums1);

        while(s1 <= e1){
            int m1 = (e1+s1)/2;
            int m2 = mid - m1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(m1 > 0) l1 = nums1[m1-1];
            if(m2 > 0) l2 = nums2[m2-1];
            if(m1 < e1) r1 = nums1[m1];
            if(m2 < e2) r2 = nums2[m2];

            if(l1 > r2 || l2 > r1){
                if(l1 > r2){
                    e1 = m1-1;
                }
                else{
                    s1 = m1+1;
                }
            }
            else{
                if(total%2) return max(l1, l2);
                else return (double)(((max(l1, l2) + min(r1, r2)))/2.0);
            }
        }

        return 0;
    }
};
