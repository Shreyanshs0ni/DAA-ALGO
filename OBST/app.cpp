#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int OBST(vector<int> &freq)
{
    int n = freq.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += freq[k];

            for (int r = i; r <= j; r++)
            {
                int cost = sum +
                           (r > i ? dp[i][r - 1] : 0) +
                           (r < j ? dp[r + 1][j] : 0);

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> freq = {34, 8, 50};
    cout << "Optimal cost = " << OBST(freq);
}