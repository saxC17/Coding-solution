#include <bits/stdc++.h>
#include <iostream>
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
	while (b > 0)
	{	if (b & 1) {
			res = ( res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
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
	int size = 200001;
	vl fact(size, 0);
	fact[0] = 1;
	for (int i = 1; i < 200001; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	vl ifact(size, 0);
	ifact[200000] = binpow(fact[200000], mod - 2);
	for (int i = size - 2; i >= 0; i--) {
		ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
	}

	cin >> ts;
	while (ts--) {
		ll n, k; cin >> n >> k;
		if (n & 1) {
			vl dp(k + 1, 0);
			dp[0] = 1;
			ll x = 0;

			for (int i = 0; i < n; i += 2) {
				x += (((fact[n] * ifact[i]) % mod) * ifact[n - i]) % mod;
				x %= mod;
			}
			rep(i, 1, k + 1) {
				dp[i] = (dp[i - 1] + ((x * (dp[i - 1])) % mod)) % mod;
			}
			cout << dp[k] << nl;
		}
		else {
			vl dp(k + 1, 0);
			dp[0] = 1;
			ll x = 0;
			for (int i = 0; i < n; i += 2) {
				x += (((fact[n] * ifact[i]) % mod) * ifact[n - i]) % mod;
				x %= mod;
			}
			rep(i, 1, k + 1) {
				dp[i] = (binpow(2, n * (i - 1)) + ((x * dp[i - 1]) % mod)) % mod;
			}
			cout << dp[k] << nl;
		}
	}
	return 0;

}
