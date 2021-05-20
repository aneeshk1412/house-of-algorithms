#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void
dijkstra_sssp(
	vector<vector<pair<ll, double>>>& adj,
	ll s, vector<double>& dist) {
	// Complexity : O((|E| + |V|)log(|V|))

	vector<bool> vis(dist.size(), false);
	for (auto& d: dist)
		d = numeric_limits<double>::max();

	dist[s]=0.0;

	priority_queue<pair<double, ll>,
	vector<pair<double, ll>>,
	greater<pair<double, ll>>> Q;

	Q.emplace(dist[s], s);

	while (!Q.empty()) {
		ll u=Q.top().second; Q.pop();
		if (vis[u]) continue;
		vis[u]=true;

		for (auto& [v, w]: adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				Q.emplace(dist[v], v);
			}
		}
	}

	for (auto d: dist) {
		cout << d << " ";
	}
	cout << "\n";
}

int
main(int argc, char const *argv[])
{
	/* code */
	return 0;
}