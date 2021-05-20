#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void
dijkstra_sssp(
	// Complexity : O((|E| + |V|)log(|V|))

	vector<vector<pair<ll, double>>>& adj,
	ll s, vector<double>& dist) {

	vector<bool> vis(dist.size(), false);
	for (auto& d: dist)
		d = numeric_limits<double>::max();

	dist[s]=0.0;

	priority_queue<pair<double, ll>,
	vector<pair<double, ll>>,
	greater<pair<double, ll>>> q;

	q.emplace(dist[s], s);

	while (!q.empty()) {
		ll u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=true;

		for (auto& [v, w]: adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.emplace(dist[v], v);
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