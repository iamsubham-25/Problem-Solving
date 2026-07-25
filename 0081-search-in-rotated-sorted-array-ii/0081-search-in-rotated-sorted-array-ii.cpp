class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates: when low, mid, and high elements are equal,
            // we cannot determine which side is sorted.
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Check if the left side is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target is in the left sorted part
                } else {
                    low = mid + 1;  // Target is in the right part
                }
            } 
            // Otherwise, the right side must be sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Target is in the right sorted part
                } else {
                    high = mid - 1; // Target is in the left part
                }
            }
        }

        return false;
    }
};