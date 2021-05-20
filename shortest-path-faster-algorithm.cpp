#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void
shortest_path_faster(
	vector<vector<pair<ll, double>>>& adj,
	ll s, vector<double>& dist) {
	
	for (auto& d: dist)
		d = numeric_limits<double>::max();

	dist[s]=0.0;

	deque<ll> Q;
	vector<bool> inQ(dist.size(), false);
	Q.push_back(s);
	inQ[s]=true;
	
	while (!Q.empty()) {
		ll u=Q.front(); Q.pop_front(); inQ[u]=false;
		for (auto& [v, w]: adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (!inQ[v]) {
					Q.push_back(v);
					inQ[v]=true;

					if (dist[Q.back()] < dist[Q.front()]) {
						ll x=Q.back(); Q.pop_back();
						Q.push_front(x);
					}
				}
			}
		}
	}
}

int 
main(int argc, char const *argv[])
{
	return 0;
}