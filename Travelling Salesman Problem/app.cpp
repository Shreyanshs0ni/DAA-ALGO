#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(int mask, int pos, vector<vector<int>> &dist, vector<vector<int>> &dp, int n)
{
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city, dist, dp, n);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << "Min cost = " << tsp(1, 0, dist, dp, n);
}