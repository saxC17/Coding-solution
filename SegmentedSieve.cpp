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

void solve() {
	ll n, m; cin >> m >> n;
	ll res = sqrt(n) + 1;
	vector<bool>sieve1(res + 1, true);
	for (int i = 2; i * i <= res; i++) {
		for (int j = i * i; j <= res; j += i) {
			sieve1[j] = false;
		}
	}
	vi sieve;
	for (int i = 2; i <= res; i++) {
		if (sieve1[i]) {
			sieve.pb(i);
		}
	}
	vector<bool>ans(n - m + 1, true);
	for (int i = 0; i < sz(sieve); i++) {
		int curr = sieve[i];
		ll start = (m / curr) * curr;
		if (m % curr != 0) {
			start += curr;
		}
		for (ll j = start; j <= n; j += curr) {
			ans[j - m] = false;
		}
		if (start == curr) {
			ans[start - m] = true;
		}
	}
	for (ll i = m; i <= n; i++) {
		if (ans[i - m] && i != 1) {
			cout << i << nl;
		}
	}
	cout << nl;

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
