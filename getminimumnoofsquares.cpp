class Solution
{
public:
    int solve(int n)
    {
        if (n == 0)
            return 0;

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve(n - i * i));
        }

        return ans;
    }
    int MinSquares(int n)
    {
        return solve(n);
    }
};

// memoization
class Solution
{
public:
    int solve(int n)
    {
        if (n == 0)
            return 0;

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve(n - i * i));
        }

        return ans;
    }
    int MinSquares(int n)
    {
        return solve(n);
    }
};



//tabulation
int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
                dp[i] = min(dp[i], dp[i temp]);
        }
    }
    return dp[n];
}