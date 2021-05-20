#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void remove_element_from_average(double &avg, ll n, double e) {
	avg = (1.0 * (n + 1) / (n + n==0)) * avg - (e / (n + n==0));
}

inline void add_element_to_average(double &avg, ll n, double e) {
	avg = (1.0 * (n-1) / n) * avg - (e / n);
}


void
shortest_path_faster_simple(
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
	double avg=dist[s];

	while (!Q.empty()) {
		ll u=Q.front(); Q.pop_front(); inQ[u]=false;
		remove_element_from_average(avg, Q.size(), dist[u]);

		for (auto& [v, w]: adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (!inQ[v]) {
					Q.push_back(v);
					inQ[v]=true;
					add_element_to_average(avg, Q.size(), dist[v]);

					if (dist[Q.back()] < dist[Q.front()]) {
						ll x=Q.back(); Q.pop_back();
						Q.push_front(x);
					}

					while (dist[Q.front()] > avg) {
						ll x=Q.front(); Q.pop_front();
						Q.push_back(x);
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