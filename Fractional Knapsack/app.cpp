#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item
{
    int value, weight;
};
bool cmp(Item a, Item b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}
double knapsack(int w, vector<Item> &arr)
{
    sort(arr.begin(), arr.end(), cmp);
    double res = 0;
    for (auto &i : arr)
    {
        if (w >= i.weight)
        {
            res += i.value;
            w -= i.weight;
        }
        else
        {
            res += i.value * ((double)w / i.weight);
            break;
        }
    }
    return res;
}
int main()
{
    int W = 50; // capacity

    vector<Item> arr = {
        {60, 10},
        {100, 20},
        {120, 30}};

    double ans = knapsack(W, arr);

    cout << "Maximum value = " << ans << endl;

    return 0;
}