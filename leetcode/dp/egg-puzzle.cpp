/** soln
 
 k = 2  n = 5
 
 k=1, 2     2, 2 
 [1, 2 , 3, 4, 5]
 
 [f][k]
 
 2, 5
  (1, 2 )  3  (4 5)
 1, 
 
 **/

int solve(int k, int n, map<pair<int, int>, int>& dp){
	if(n == 0){
		return 0;
	}
	if(k == 1){
		return n;
	}
	if(n == 1){
		return 1;
	}
	
	if(dp.find({n,k}) != dp.end()){
		return dp[{n,k}];
	}
	
	int ans = INT_MAX;
	
	for(int i = 1; i<= n; ++i){
		ans = min(ans, max(1 + solve(k-1, i-1, dp), 1 +  solve(k, n-i, dp)));
	
	}
	
	dp[{n,k}] = ans;
	return ans;
}

int minimumMoves(int k, int n) {
    // add your logic here
	map<pair<int, int>, int> dp;
	return solve(k, n, dp);
	
}
