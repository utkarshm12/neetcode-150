class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = 1;

        for(auto i : piles) mx = max(mx, i);

        int s = 1, e = mx, md = (mx+1)/2, ans = h;

        while(s <= e){
            int hrs = 0;
            for(auto pile : piles) {
                hrs += ceil(1.0*pile / md);
            }
            cout << hrs << " " << endl;
            if(hrs > h) s = md+1;
            else if (hrs <= h) ans = md, e = md - 1;
            md = (s+e)/2;
        }

        return ans;
    }
};
