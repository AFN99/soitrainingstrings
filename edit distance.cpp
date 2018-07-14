#include <bits/stdc++.h>

using namespace std;
int dp[1010][1010];
string s1, s2;
int edit(int n, int m) {
    if (n == -1) return m + 1;
    if (m == -1) return n + 1;
    if (dp[n][m] != -1) return dp[n][m];
    if (s1[n] == s2[m]) return dp[n][m] = edit(n - 1, m - 1);
    int mn = edit(n - 1, m);
    mn = min(mn, edit(n, m - 1));
    mn = min(mn, edit(n - 1, m - 1));
    return dp[n][m] = 1 + mn;
}
int main() {
    int n, m;
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    memset(dp, -1, sizeof dp);
    cout << edit(n - 1, m - 1) << '\n';
    return 0;
}
