#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    int left, right;   // indices of child nodes, -1 if none
};

vector<Node> nodes;
vector<string> codes;

// Walk the tree: a left edge adds '0', a right edge adds '1'
void assignCodes(int idx, const string& prefix) {
    Node& nd = nodes[idx];
    if (nd.left == -1 && nd.right == -1) {
        codes[idx] = prefix.empty() ? "0" : prefix;
        return;
    }
    if (nd.left != -1)  assignCodes(nd.left, prefix + "0");
    if (nd.right != -1) assignCodes(nd.right, prefix + "1");
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    if (n < 1) return 0;

    for (int i = 0; i < n; i++) {
        Node leaf;
        cout << "Enter character and frequency " << i + 1 << ": ";
        cin >> leaf.ch >> leaf.freq;
        leaf.left = leaf.right = -1;
        nodes.push_back(leaf);
    }

    // Min-heap of (frequency, node index); ties go to the older node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
        pq.push({nodes[i].freq, i});

    while (pq.size() > 1) {
        pair<int, int> a = pq.top(); pq.pop();
        pair<int, int> b = pq.top(); pq.pop();

        Node parent;
        parent.ch = '*';
        parent.freq = a.first + b.first;
        parent.left = a.second;
        parent.right = b.second;
        nodes.push_back(parent);
        pq.push({parent.freq, (int)nodes.size() - 1});
    }

    int root = pq.top().second;
    codes.assign(nodes.size(), "");
    assignCodes(root, "");

    cout << "\nHuffman codes:\n";
    long long totalBits = 0;
    for (int i = 0; i < n; i++) {
        cout << nodes[i].ch << " : freq " << nodes[i].freq
             << ", code " << codes[i] << "\n";
        totalBits += (long long)nodes[i].freq * codes[i].size();
    }
    cout << "\nTotal encoded length: " << totalBits << " bits\n";
    return 0;
}