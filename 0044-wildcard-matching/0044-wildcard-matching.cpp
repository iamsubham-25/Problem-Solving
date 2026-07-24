#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            // Case 1: Characters match or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Pattern has '*', store the position of '*' and current sIdx
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++; // Assume '*' matches empty sequence initially
            }
            // Case 3: Mismatch occurs, but we previously saw a '*'
            else if (starIdx != -1) {
                pIdx = starIdx + 1; // Backtrack pattern to right after '*'
                sTmpIdx++;          // Let '*' match one more character in s
                sIdx = sTmpIdx;
            }
            // Case 4: Mismatch and no previous '*' to backtrack to
            else {
                return false;
            }
        }

        // Skip remaining '*' in pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};