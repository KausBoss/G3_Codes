#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const int INF = 1e9;
const int MOD = 1e9 + 7;
/*
1.  Make and write down observations before solving the problem.
2.  Solve the question mathematically in a note before coding the problem,
3.  Understand each line in the given. If not understood properly change to my native language.
4. For dp problems draw out the recurrence tree.
5. For hard problems work out the examples.
6. int vs ll
*/
 
void solve() {
    int a, b, q;
    cin >> a >> b >> q;
 
    vector<int> pref((a * b) + 1, 0), good(a * b + 1, 0);
    for (int i = 0; i < a * b; ++i) {
        if (((i % a) % b) != ((i % b) % a)) {
            good[i] = 1;
        }
    }
 
    for (int i = 0; i < a * b; ++i) {
        pref[i + 1] = pref[i] + good[i];
    }
 
    while (q--) {
        ll l, r;
        cin >> l >> r;
 
        ll lq = l / (ll)(a * b);
        ll rq = r / (ll)(a * b);
 
        ll r1 = l % (a * b);
        ll r2 = r % (a * b);
 
        if (lq == rq) {
            cout << pref[r2 + 1] - pref[r1] << " ";
        } else {
            ll ans = pref[r2 + 1] + pref[a * b] - pref[r1];
            ans += (ll)pref[a * b] * (rq - lq - 1);
            cout << ans << " ";
        }
    }
    cout << "\n";
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
/*
The main mistake I do is not undestanding the question completely. So avoid doing it.
*/