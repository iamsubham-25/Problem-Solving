class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map <int,int> mp; // key : player number , value : count of losses
        
        for(auto& x : matches) {
            int loser = x[1]; 
            mp[loser]++;
        }
        
        vector <int> notLost;
        vector <int> lostOnce;
        
        for(auto& x : matches) {
            int winner = x[0]; 
            int loser = x[1];  
            
            if(mp.find(winner) == mp.end()) {
                notLost.push_back(winner);
                mp[winner] = 2;
            }
            if(mp[loser] == 1) {
                lostOnce.push_back(loser);
            }
        }
        
        sort(begin(lostOnce) , end(lostOnce));
        sort(begin(notLost) , end(notLost));
        
        return {notLost, lostOnce};
    }
};