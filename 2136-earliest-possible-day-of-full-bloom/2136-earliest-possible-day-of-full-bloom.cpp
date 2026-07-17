
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> seeds(n);
        
        for (int i = 0; i < n; i++) {
            seeds[i] = {growTime[i], plantTime[i]};
        }
        
        // Sort by growTime in descending order
        sort(seeds.begin(), seeds.end(), greater<pair<int, int>>());
        
        int currentPlantTime = 0;
        int maxBloomDay = 0;
        
        for (int i = 0; i < n; i++) {
            int gTime = seeds[i].first;
            int pTime = seeds[i].second;
            
            // Add the time it takes to plant the current seed
            currentPlantTime += pTime;
            
            // This seed blooms on: currentPlantTime + growTime
            maxBloomDay = max(maxBloomDay, currentPlantTime + gTime);
        }
        
        return maxBloomDay;
    }
};