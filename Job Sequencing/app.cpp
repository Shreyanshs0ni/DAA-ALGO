#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id, deadline, profit;
};

bool cmp(const Job &a, const Job &b)
{
    return a.profit > b.profit;
}

int jobSeq(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);

    int maxD = 0;
    for (auto &j : jobs)
        maxD = max(maxD, j.deadline);

    vector<int> slot(maxD + 1, -1);
    int profit = 0;

    for (auto &j : jobs)
    {
        for (int d = j.deadline; d > 0; d--)
        {
            if (slot[d] == -1)
            {
                slot[d] = j.id;
                profit += j.profit;
                break;
            }
        }
    }
    return profit;
}

int main()
{
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}};

    cout << "Max profit = " << jobSeq(jobs);
}