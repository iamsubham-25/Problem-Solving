class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps = 0;
        
        // Work backwards from target to startValue
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
            steps++;
        }
        
        // If target is now less than startValue, we can only add 1s 
        // (which corresponds to subtracting 1s when moving forward)
        return steps + (startValue - target);
    }
};