#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> w(k + 1);
    vector<int> len(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> w[i];
        len[i] = (int)w[i].size();
    }

    const int INF = 1e9;
    vector<int> dp(k + 1, INF);
    vector<int> parent(k + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= k; ++i) {
        int lineLen = 0;
        for (int j = i; j >= 1; --j) {
            lineLen += len[j];
            if (j < i) lineLen += 1; // one space between words

            int cost = abs(lineLen - n);
            int cand = max(dp[j - 1], cost);
            if (cand < dp[i]) {
                dp[i] = cand;
                parent[i] = j - 1;
            }
        }
    }

    // Reconstruct line breaks
    vector<pair<int,int>> lines;
    for (int i = k; i > 0; i = parent[i]) {
        lines.push_back({parent[i] + 1, i});
    }
    reverse(lines.begin(), lines.end());

    for (auto [l, r] : lines) {
        for (int i = l; i <= r; ++i) {
            if (i > l) cout << ' ';
            cout << w[i];
        }
        cout << '\n';
    }

    return 0;
}
