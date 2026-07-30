class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicate elements at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Step 1: Sort the array so duplicates are adjacent
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        
        return result;
    }
};