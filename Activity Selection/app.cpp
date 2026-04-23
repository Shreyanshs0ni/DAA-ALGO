#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity
{
    int start, finish;
};
bool cmp(Activity a, Activity b)
{
    return a.finish < b.finish;
};
int maxActivity(vector<Activity> &a)
{
    sort(a.begin(), a.end(), cmp);
    int count = 1,
        last = a[0].finish;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].start >= last)
        {
            count++;
            last = a[i].finish;
        }
    }
    return count;
}

int main()
{
    vector<Activity> arr = {
        {1, 3},
        {2, 5},
        {4, 7},
        {6, 9},
        {8, 10}};

    int ans = maxActivity(arr);

    cout << "Maximum activities = " << ans << endl;

    return 0;
}