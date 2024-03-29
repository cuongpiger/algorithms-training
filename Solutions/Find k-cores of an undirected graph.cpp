#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <list>
using namespace std;
class Graph {
	int V;
	list<int>* adjList;
	int* degree;
public:
	Graph(int v) {
		V = v;
		adjList = new list<int>[V + 1];
		degree = new int[V] {0};
	}
	void addEdge(int u, int v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir)
			adjList[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	void kcore(int k) {
		vector<pair<int, int> >v(V);
		for (int i = 0; i < V; i++) {
			v[i].first = degree[i];
			v[i].second = i;
		}
		auto result = *std::min_element(v.cbegin(), v.cend(), [](const auto& lhs, const auto& rhs) {
			return lhs.first < rhs.first;  });
		while (result.first < k) {
			int node = result.second;
			//cout<<node<<"\n";
			for (int neighbour : adjList[node]) {
				if (v[neighbour].first != INT_MAX) {
					v[neighbour].first--;
					//cout<<neighbour<<" "<<v[neighbour].first<<"\n";
				}
			}
			v[node].first = INT_MAX;
			result = *std::min_element(v.cbegin(), v.cend(), [](const auto& lhs, const auto& rhs) {
				return lhs.first < rhs.first;  });
		}
		for (int i = 0; i < V; i++) {
			if (v[i].first >= k && v[i].first != INT_MAX) {
				cout << i;
				for (int neighbour : adjList[i]) {
					if (v[neighbour].first >= k && v[neighbour].first != INT_MAX) {
						cout << "-> " << neighbour;
					}
				}
				cout << "\n";
			}
		}

		for (int i = 0; i < V; ++i) {
			cout << v[i].first << " ";
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph g1(7);
	g1.addEdge(0, 1);
	g1.addEdge(0, 3);
	g1.addEdge(1, 2);
	g1.addEdge(1, 5);
	g1.addEdge(1, 4);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	g1.addEdge(3, 6);
	g1.addEdge(4, 6);
	g1.addEdge(4, 5);
	g1.addEdge(5, 6);
	g1.kcore(3);
	return 0;
}

