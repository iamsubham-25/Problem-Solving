class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffMin(n);
        
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        
        int currMax = 0;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, nums[i]);
            if (currMax - suffMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};