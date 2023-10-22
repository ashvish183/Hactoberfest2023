
#include <bits/stdc++.h>
 
using namespace std;
 
#define ar array
#define ll long long
 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
 
// f[i] = length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring
vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> f(n); 
    for (int i = 1; i < n; i++) {
        int j = f[i - 1];
        while (j && s[i] != s[j]) j = f[j - 1];
        f[i] = j + (s[i] == s[j]);
    }
    return f;
}
 
int cnt_occ(string s, string t) {
    string ts = t + "#" + s;
    int n = t.size(), m = s.size(), nm = ts.size();
    auto f = prefix_func(ts);
    int res = 0;
    for (int i = n + 1; i < nm; i++) res += (f[i] == n);
    return res;
}
 
void solve() {
    string s, t; cin >> s >> t;
    cout << cnt_occ(s, t) << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
