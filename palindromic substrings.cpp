#include <bits/stdc++.h>

using namespace std;
int P[1010][1010];
string s;
int pal(int i, int j) {
    if (i == j - 1) return (s[i] == s[j]);
    if (P[i][j] != -1) return P[i][j];
    pal(i, j - 1);
    pal(i + 1, j);
    if (pal(i + 1, j - 1)) return P[i][j] = (s[i] == s[j]);
    return P[i][j] = 0;
}
int dp[1010][1010];
int cnt(int i, int j) {
    if (i == j - 1) return (s[i] == s[j]);
    if (dp[i][j] != -1) return dp[i][j];
    int c = cnt(i + 1, j);
    c += cnt(i, j - 1);
    c -= cnt(i + 1, j - 1);
    c += P[i][j];
    return dp[i][j] = c;
}
int main() {
    cin >> s;
    int n = s.size();
    memset(P, -1, sizeof P);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) P[i][i] = 1, dp[i][i] = 0;
    pal(0, n - 1);
    cout << cnt(0, n - 1) << '\n';
    return 0;
}
