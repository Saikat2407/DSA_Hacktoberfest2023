// Codeforces Soltuion of Problem - 1242B, 0-1MST
// https://codeforces.com/contest/1242/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define endl '\n'
#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " " << x << "\n"
#define deb2(x, y) cout << "[ " << #x << "=" << x << "," << #y << "=" << y << " ]\n"
#define deba(x, n)              \
    cout << #x << ": [ ";       \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << x[i] << " ";    \
    }                           \
    cout << "]\n";
#define deba2(x, n, m)              \
    cout << #x << ":\n";            \
    for (int i = 0; i < n; i++)     \
    {                               \
        for (int j = 0; j < m; j++) \
            cout << x[i][j] << " "; \
        cout << "\n";               \
    };
#define debe(x)           \
    cout << #x << ":[ ";  \
    for (auto i : x)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << "]\n";
#else
#define deb(x)
#define deb2(x, y)
#define deba(x, n)
#define deba2(x, n, m)
#define debe(x)
#endif
const int MOD = 1000000007;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        map<pair<ll, ll>, bool> mp;
        rep(i, 0, m)
        {
            ll x, y;
            cin >> x >> y;
            mp[{min(x, y), max(x, y)}] = 1;
        }
        set<ll> st;
        vector<bool> vis(n + 1, 0);
        rep(i, 1, n + 1)
            st.insert(i);
        function<void(ll)> dfs = [&](ll node)
        {
            vis[node] = 1;
            st.erase(node);
            auto it = st.begin();
            while (1)
            {
                if (it == st.end())
                    break;
                ll child = *it;
                if (vis[child])
                    continue;
                pair<ll, ll> pr = {min(child, node), max(child, node)};
                if (mp[pr] == 0)
                {
                    dfs(child);
                }
                it = st.upper_bound(child);
            }
        };
        ll ct = 0;
        rep(i, 1, n + 1)
        {
            if (!vis[i])
                dfs(i), ct++;
        }
        cout << ct - 1 << endl;
    }
    return 0;
}