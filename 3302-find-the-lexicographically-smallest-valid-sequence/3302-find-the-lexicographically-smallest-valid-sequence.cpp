#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last_idx[j] stores the largest index in word1 from which 
        // the suffix word2[j...] can form a subsequence.
        vector<int> last_idx(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                last_idx[j] = i;
                j--;
            }
        }

        vector<int> result;
        j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; ++i) {
            bool is_match = (word1[i] == word2[j]);
            
            if (is_match) {
                result.push_back(i);
                j++;
            } else if (!changed) {
                // Check if the remaining suffix word2[j+1...] can be matched starting after index i
                if (j == m - 1 || (last_idx[j + 1] > i)) {
                    result.push_back(i);
                    changed = true;
                    j++;
                }
            }
        }

        return (result.size() == m) ? result : vector<int>();
    }
};