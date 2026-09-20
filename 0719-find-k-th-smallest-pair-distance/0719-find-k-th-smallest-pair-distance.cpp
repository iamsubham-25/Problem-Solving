class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int lo = 0, hi = nums[n - 1] - nums[0];

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (countPairsWithinDist(nums, mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

private:
    long long countPairsWithinDist(vector<int>& nums, int maxDist) {
        long long count = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            while (nums[j] - nums[i] > maxDist) {
                i++;
            }
            count += (j - i);  // every index in [i, j) pairs with j, distance <= maxDist
        }

        return count;
    }
};