#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MATCH = 1, MISMATCH = -1, GAP = -2;

int main() {
    string a, b;
    cout << "Enter first sequence: ";
    cin >> a;
    cout << "Enter second sequence: ";
    cin >> b;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i * GAP;
    for (int j = 0; j <= m; j++) dp[0][j] = j * GAP;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int s = (a[i - 1] == b[j - 1]) ? MATCH : MISMATCH;
            dp[i][j] = max({dp[i - 1][j - 1] + s,
                            dp[i - 1][j] + GAP,
                            dp[i][j - 1] + GAP});
        }
    }

    // Trace back from the bottom-right corner to build the alignment
    string alignA, alignB;
    int i = n, j = m;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 &&
            dp[i][j] == dp[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? MATCH : MISMATCH)) {
            alignA += a[i - 1];
            alignB += b[j - 1];
            i--; j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + GAP) {
            alignA += a[i - 1];
            alignB += '-';
            i--;
        } else {
            alignA += '-';
            alignB += b[j - 1];
            j--;
        }
    }
    reverse(alignA.begin(), alignA.end());
    reverse(alignB.begin(), alignB.end());

    cout << "\nAlignment score: " << dp[n][m] << "\n";
    cout << alignA << "\n";
    cout << alignB << "\n";
    return 0;
}