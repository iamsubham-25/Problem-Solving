class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for (int i = 1; i < n; ++i) {
            string next_res = "";
            int count = 1;
            
            for (int j = 0; j < res.length(); ++j) {
                if (j + 1 < res.length() && res[j] == res[j + 1]) {
                    count++;
                } else {
                    next_res += to_string(count) + res[j];
                    count = 1;
                }
            }
            res = next_res;
        }
        
        return res;
    }
};