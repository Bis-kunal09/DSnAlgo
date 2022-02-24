class Solution {
public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//          int sum=0;
//         int n=nums.size();
// 	    for(int i=0;i<n;i++){
// 	        sum+=nums[i];
// 	    }
//         if ((sum + target) % 2 == 1 || target > sum || target < -sum) return 0;
//         int s1=(sum+target)/2;
//         vector<vector<int>> dp(n,vector<int> (s1+1,0));
// 	    for(int i=0;i<n;i++){
// 	        dp[i][0]=1;
// 	    }
// 	    if(s1>nums[0]){
// 	        dp[0][nums[0]]=1;
// 	    }
// 	    for(int i=1;i<n;i++){
// 	        for(int j=1;j<=s1;j++){
// 	            int take=0;
// 	            if(nums[i]<=j){
// 	                take=dp[i-1][j-nums[i]];
// 	            }
// 	            int notake=dp[i-1][j];
// 	            dp[i][j]=take+notake;
	            
// 	        }
// 	    }
//         return dp[n-1][s1];
        
//     }
    int findTargetSumWays(vector<int>& nums, int S) {
	int sum = 0;
	for (auto n : nums) sum += n;
	if ((sum + S) % 2 == 1 || S > sum || S < -sum) return 0;
	int newS = (sum + S) / 2;
	vector<int> dp(newS + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = newS; j >= nums[i]; --j) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[newS];
}
};