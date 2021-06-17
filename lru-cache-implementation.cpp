#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

template<class T>
class LRUCache {
private:
	list<pair<ll, T>> L;
	unordered_map<ll, typename list<pair<ll, T>>::iterator> M;
	ull capacity;

public:
	LRUCache(ll cap) {
		capacity = cap;
	}

	const T* get(ll key) {
		typename unordered_map<ll, typename list<pair<ll, T>>::iterator>::iterator iter = M.find(key);
		if (iter == M.end()) {
			return nullptr;
		}
		typename list<pair<ll, T>>::iterator page = iter->second;
		L.push_front(*page);
		L.erase(page);
		page = L.begin();
		M[page->first] = page;
		return &page->second;
	}

	void set(ll key, T value) {
		typename unordered_map<ll, typename list<pair<ll, T>>::iterator>::iterator iter = M.find(key);
		if (iter == M.end()) {
			L.push_front({key, value});
			M[key] = L.begin();
			while (L.size() > capacity) {
				M.erase(M.find(L.back().first));
				L.pop_back();
			}
		}
		else {
			typename list<pair<ll, T>>::iterator page = iter->second;
			page->second = value;
			L.push_front(*page);
			L.erase(page);
			page = L.begin();
			M[page->first] = page;
		}
	}

	void print() {
		cout << "Cache : [";
		for (auto& [u, v]: L) {
			cout << "(" << u << "," << v << ") ";
		}
		cout << "]\n";
	}

	void debug() {
		cout << "List : [";
		for (auto& [u, v]: L) {
			cout << "(" << u << "," << v << ") ";
		}
		cout << "]\n";

		cout << "Map : [";
		for (auto& [u, v]: M) {
			cout << "(" << u << "," << "(" << v->first << "," << v->second << ")) ";
		}
		cout << "]\n";
	}
};


int main(int argc, char const *argv[])
{
	/* code */
	LRUCache<ll> C(4);
	C.set(1, 1);
	C.print();
	C.set(2, 4);
	C.print();
	C.set(3, 9);
	C.print();
	C.set(4, 16);
	C.print();
	cout << *C.get(1) << "\n";
	C.print();
	C.set(5, 25);
	C.print();
	C.set(6, 36);
	C.print();
	return 0;
}