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

void solve(vector<int> &A, int B) {
	int n = A.size();

	vector<vector<bool>>dp(B + 1, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		dp[0][i] = true;
		// cout << dp[0][i] << " ";
	}
	// cout << nl;
	for (int i = 1; i < B + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0)
				dp[i][j] = dp[i][j - 1];
			if (A[j] == i) {

				dp[i][j] = true ;

			}
			else if (i >= A[j] && j > 0)
			{
				dp[i][j] = dp[i - A[j]][j - 1] || dp[i][j - 1];
			}

			// cout << dp[i][j] << " ";
		}
		// cout << "\n";

	}
	cout << (dp[B][n - 1] ? 1 : 0);
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
		int n, B; cin >> n;
		vector<int>A(n);
		read(A); cin >> B;
		solve(A, B);
	}
	return 0;

}
