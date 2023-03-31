1. Recursive Approach : [O(2^n) & O(n)]
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        if(n <= 1) return n;
        
        return nthFibonacci(n-1) + nthFibonacci(n-2);
    }
};

2. DP - Memoization : [O(n) & O(n)]

class Solution {
  public:
    long long int fib(long long int n, vector<long long int>&dp){
        if(n<=1)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
            
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n]%1000000007;
    }
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int>dp(n+1,-1);
        return fib(n,dp);
    }
};


3. DP - Tabulation : [O(n) & O(n)]

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        return dp[n];
    }
};


4. Optimized - Iterative : [O(n) & O(1)]


class Solution {
  public:
    long long int nthFibonacci(long long int n){
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i=2;i<=n;i++){
            int curr = (prev2 + prev1) % 1000000007;
            prev2  = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
