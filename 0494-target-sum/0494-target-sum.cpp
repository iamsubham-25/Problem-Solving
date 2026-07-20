class Solution { 
public: 
    int solve(int i,int sum,vector<int>& nums,vector<vector<int>>& dp){ 
        if(i==nums.size()) return sum==0; 
        if(dp[i][sum]!=-1) return dp[i][sum]; 
 
        int notTake=solve(i+1,sum,nums,dp); 
        int take=0; 
        if(nums[i]<=sum) 
            take=solve(i+1,sum-nums[i],nums,dp); 
 
        return dp[i][sum]=take+notTake; 
    } 
 

 
    int findTargetSumWays(vector<int>& nums,int target){ 
        int total=accumulate(nums.begin(),nums.end(),0); 
 
        if(abs(target)>total) return 0; 
        if((total+target)&1) return 0; 
 
        int req=(total+target)/2; 
 
        vector<vector<int>> dp(nums.size(),vector<int>(req+1,-1)); 
 
        return solve(0,req,nums,dp); 
    } 
};