class Solution { 
public: 
 
    int solve(int n, vector<int>& dp) { 
 
        if(n == 1) 
            return 1; 
 
        if(dp[n] != -1) 
            return dp[n]; 
 
        int answer = 0; 
 
        for(int i = 1; i < n; i++) { 
 
            answer = max(answer, max(i * (n - i), i * solve(n - i, dp))); 
        } 
 
        return dp[n] = answer; 
    } 
 
    int integerBreak(int n) { 
 
        vector<int> dp(n + 1, -1); 
 
        return solve(n, dp); 
    } 
}; 