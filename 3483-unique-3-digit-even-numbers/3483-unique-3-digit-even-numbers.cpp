#include <vector>
#include <string>

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count the frequency of each digit available in the input array
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int uniqueCount = 0;
        
        // Check all 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            
            // Create a temporary frequency count for the current number
            vector<int> tempCount(10, 0);
            tempCount[hundreds]++;
            tempCount[tens]++;
            tempCount[units]++;
            
            // Validate if the number can be formed using the available digits
            bool possible = true;
            for (int i = 0; i < 10; i++) {
                if (tempCount[i] > count[i]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                uniqueCount++;
            }
        }
        
        return uniqueCount;
    }
};