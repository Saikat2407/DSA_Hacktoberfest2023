#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fo(a,n) for(int i=a;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int mpow(int base, int exp) {
	base %= mod;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((int)result * base) % mod;
		base = ((int)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void build(int a[], int s, int e, int tree[], int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}
	int mid = (s + e) / 2;
	build(a, s, mid, tree, 2 * index);
	build(a, mid + 1, e, tree, 2 * index + 1);
	tree[index] = tree[2 * index] + tree[2 * index + 1];
	return;
}

int query(int tree[], int s, int e, int qs, int qe, int index) {
	if ((s >= qs) and (qe >= e)) {
		return tree[index];
	}
	if ((qe < s) or (qs > e)) {
		return 0;
	}
	int mid = (s + e) / 2;
	int left = query(tree, s, mid, qs, qe, 2 * index);
	int right = query(tree, mid + 1, e, qs, qe, (2 * index) + 1);
	return left + right;
}

void update(int tree[], int s, int e, int index, int key, int val) {
	if ((key > e) or (key < s)) return;
	if ((s == e) and (s == key)) {
		tree[index] = tree[index] + val;
		return;
	}
	int mid = (s + e) / 2;
	update(tree, s, mid, 2 * index, key, val);
	update(tree, mid + 1, e, 2 * index + 1, key, val);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	c_p_c();
	int n;
	cin >> n;
	int a[n];
	int tree[4 * n + 1];
	fo(0, n) cin >> a[i];
	build(a, 0, n - 1, tree, 1);
	// cout << query(tree, 1, n , 1, 2, 1) << " ";
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << query(tree, 1, n , x, y, 1) << "\n";
	}

	return 0;
}
