class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> mp;
        vector<double> fleets;

        for(int i = 0; i < speed.size(); i++) mp.push_back({target - position[i], speed[i]});
        sort(mp.begin(), mp.end(), [] (auto a, auto b){
            return a.first < b.first;
        });

        for(auto i : mp){
            fleets.push_back((double)i.first/i.second);
        }

        int c = 1;
        double mx = fleets[0];

        for(int i = 1; i < fleets.size(); i++){
            if(fleets[i] > mx){
                mx = fleets[i];
                c++;
            }
        }

        return c;

    }
};
