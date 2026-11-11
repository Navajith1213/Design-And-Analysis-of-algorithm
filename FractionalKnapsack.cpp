#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int id;
    double value, weight;
    double ratio() const { return value / weight; }
};

int main() {
    cout << fixed << setprecision(2);

    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    if (n < 1) return 0;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    double capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    // Greedy: highest value-to-weight ratio first
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio() > b.ratio();
    });

    double totalValue = 0, remaining = capacity;
    cout << "\nItems taken:\n";
    for (const Item& it : items) {
        if (remaining <= 0) break;
        if (it.weight <= remaining) {
            totalValue += it.value;
            remaining -= it.weight;
            cout << "Item " << it.id << " : 100.00%\n";
        } else {
            double fraction = remaining / it.weight;
            totalValue += it.value * fraction;
            cout << "Item " << it.id << " : " << fraction * 100 << "%\n";
            remaining = 0;
        }
    }

    cout << "\nMaximum value: " << totalValue << "\n";
    return 0;
}