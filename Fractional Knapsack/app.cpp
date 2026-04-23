#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator to sort items by value/weight ratio (descending)
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items based on value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto &item : items) {
        if (W >= item.weight) {
            // Take full item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take fraction of item
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Knapsack capacity

    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}