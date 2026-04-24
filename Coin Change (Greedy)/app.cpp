#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    sort(coins.rbegin(), coins.rend());
    int count = 0;

    for (int c : coins)
    {
        count += amount / c;
        amount %= c;
    }
    return count;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10};
    int amount = 27;

    cout << "Min coins = " << coinChange(coins, amount);
}