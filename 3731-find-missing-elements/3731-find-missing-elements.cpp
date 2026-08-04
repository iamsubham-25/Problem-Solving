class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> present(101, false);
        int minVal = 101, maxVal = 0;

        for (int num : nums) {
            present[num] = true;
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        vector<int> result;
        for (int i = minVal; i <= maxVal; ++i) {
            if (!present[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};