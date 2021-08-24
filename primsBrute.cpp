#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		vector<int>key(V, INT_MAX);
		vector<bool>included(V, false);
		vector<int>parent(V, -1);
		key[0] = 0;
		int sum = 0;
		int temp = V;

		while (temp--) {
			int mIndex = -1;
			int minEdge = INT_MAX;
			for (int i = 0; i < V; i++) {
				if (!included[i] && key[i] < minEdge) {
					minEdge = key[i];
					mIndex = i;
				}
			}
			sum += minEdge;
			included[mIndex] = true;
			for (auto x : adj[mIndex]) {
				if (key[x[0]] > x[1]) {
					key[x[0]] = x[1];
					parent[x[0]] = mIndex;
				}
			}
		}
		return sum;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int V, E;
		cin >> V >> E;
		vector<vector<int>> adj[V];
		int i = 0;
		while (i++ < E) {
			int u, v, w;
			cin >> u >> v >> w;
			vector<int> t1, t2;
			t1.push_back(v);
			t1.push_back(w);
			adj[u].push_back(t1);
			t2.push_back(u);
			t2.push_back(w);
			adj[v].push_back(t2);
		}

		Solution obj;
		cout << obj.spanningTree(V, adj) << "\n";
	}

	return 0;
}
