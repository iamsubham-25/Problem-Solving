#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Store pairs of (element value, original index)
        std::vector<std::pair<int, int>> indexed_nums(n);
        for (int i = 0; i < n; ++i) {
            indexed_nums[i] = {nums[i], i};
        }
        
        // Sort based on element values
        std::sort(indexed_nums.begin(), indexed_nums.end());
        
        std::vector<std::vector<std::pair<int, int>>> groups;
        groups.push_back({indexed_nums[0]});
        
        // Group elements where adjacent sorted elements have a difference <= limit
        for (int i = 1; i < n; ++i) {
            if (indexed_nums[i].first - indexed_nums[i - 1].first <= limit) {
                groups.back().push_back(indexed_nums[i]);
            } else {
                groups.push_back({indexed_nums[i]});
            }
        }
        
        std::vector<int> result(n);
        
        // For each group, the original indices and sorted values can be reassigned
        for (const auto& group : groups) {
            std::vector<int> indices;
            for (const auto& p : group) {
                indices.push_back(p.second);
            }
            // Indices must be sorted to assign smaller values to smaller index positions
            std::sort(indices.begin(), indices.end());
            
            for (size_t i = 0; i < indices.size(); ++i) {
                result[indices[i]] = group[i].first;
            }
        }
        
        return result;
    }
};