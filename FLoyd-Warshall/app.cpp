#include <iostream>
#include <vector>
using namespace std;

void floyd(vector<vector<int>> &g)
{
    int n = g.size();

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
}

int main()
{
    vector<vector<int>> g = {
        {0, 5, 999, 10},
        {999, 0, 3, 999},
        {999, 999, 0, 1},
        {999, 999, 999, 0}};

    floyd(g);

    for (auto row : g)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}