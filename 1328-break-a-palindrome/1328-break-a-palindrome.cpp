class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        
        // A single character string cannot be broken into a non-palindrome
        if (n <= 1) {
            return "";
        }
        
        // Iterate through the first half of the string
        for (int i = 0; i < n / 2; ++i) {
            // Replace the first non-'a' character with 'a'
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        // If all characters in the first half were 'a' (e.g., "aba", "aaaa")
        // change the last character to 'b' to make it lexicographically smallest
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};