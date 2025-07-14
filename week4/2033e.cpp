#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> chk(n + 1, 0);
    int ans = 0;
    vector<int> p(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (chk[i]) continue;

        int j = i;
        int count = 0;

        // Traverse the cycle starting at index i
        while (!chk[j]) {
            chk[j] = 1;
            j = p[j];
            count++;
        }

        if (count <= 2) continue;

        ans += (count - 1) / 2;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
