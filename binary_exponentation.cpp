#include <bits/stdc++.h>
using namespace std;

#define INF (int)2e9
#define mod 1000000007
#define PI 3.141592653589793238
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define repd(i,a,b) for(int i=a; i>=b; --i)
#define repz(i,b) for(int i=0; i<b; ++i)
#define repdz(i,b) for(int i=b; i>=0; --i)
#define trav(i,a) for(auto i: a)
#define pb push_back
#define pf push_front
#define nl '\n'
#define sp ' '
#define sz(a) (int)a.size()
#define read(p) repz(i,sz(p)) cin>>p[i]

typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>>  vvl;
typedef pair<int, int> pii;

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res *= a; res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1; //b/=2;
	}
	return res;
}

void solve() {
	int a, b; cin >> a >> b ;
	cout << binpow(a, b) << nl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	int ts = 1;
	cin >> ts;
	while (ts--) {
		solve();
	}
	return 0;
}
