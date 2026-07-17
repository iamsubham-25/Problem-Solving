class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // 2D array to store frequencies of 2-letter words
        int count[26][26] = {0};
        
        for (const string& word : words) {
            count[word[0] - 'a'][word[1] - 'a']++;
        }
        
        int length = 0;
        bool centralUsed = false;
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i < j) {
                    // Case 1: Non-palindromic pairs like "ab" and "ba"
                    int pairs = min(count[i][j], count[j][i]);
                    length += pairs * 4;
                } else if (i == j) {
                    // Case 2: Palindromic words like "aa"
                    // Use them in pairs
                    length += (count[i][i] / 2) * 4;
                    
                    // Check if there's a leftover single word for the center
                    if (count[i][i] % 2 == 1) {
                        centralUsed = true;
                    }
                }
            }
        }
        
        // If there was at least one odd-frequency palindromic word, place it in the center
        if (centralUsed) {
            length += 2;
        }
        
        return length;
    }
};