﻿'''
https://www.hackerrank.com/challenges/dijkstrashortreach/problem
Comment
This is accepted code, but it will be running time error, have to convert this code to C++ to get AC
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

INF = 10**9
grp = [[] for i in range(3005)]
n = s = None

def dijkstra():
    dist = [INF]*(n + 5)
    dist[s] = 0
    pq = queue.PriorityQueue()
    pq.put((0, s))

    while not pq.empty():
        wu, u = pq.get()

        if wu != dist[u]:
            continue

        for v, wv in grp[u]:
            if dist[v] > wv + wu:
                dist[v] = wv + wu;
                pq.put((dist[v], v))

    return dist

#_____main_____
#FILE_IO()

tc = int(input())

for cs in range(tc):
    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        grp[u].append((v, w))
        grp[v].append((u, w))

    s = int(input())
    dist = dijkstra()

    for i in range(1, n + 1):
        grp[i].clear()
        if i == s:
            continue

        if dist[i] == INF:
            print(-1, end = ' ')
        else:
            print(dist[i], end = ' ')
    
    print()

# C++ source code
'''
#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
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
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define sortRev greater<int>()
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
/*__________________________________________________________________________________________________________________________
https://www.hackerrank.com/challenges/dijkstrashortreach/problem
____________________________________________________________________________________________________________________________*/

#define distance first
#define vertex second
const int INF = 1e9;

struct option {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		return a.first > b.first;
	}
};

int V;

inline vi dijkstra(int s, vpii grp[]) {
	vi dist(V + 5, INF);
	priority_queue<pii, vpii, option> pq;
	dist[s] = 0;
	pq.push(pii(0, s));

	while (!pq.empty()) {
		pii u = pq.top();
		pq.pop();

		if (u.distance != dist[u.vertex]) {
			continue;
		}

		for (int i = 0; i < grp[u.vertex].size(); ++i) {
			pii v = grp[u.vertex][i];

			if (dist[v.vertex] > u.distance + v.distance) {
				dist[v.vertex] = u.distance + v.distance;
				pq.push(pii(dist[v.vertex], v.vertex));
			}
		}
	}

	return dist;
}

int main() {
	FAST_IO;
	//FILE_IO;

	int tc, m, s;
	cin >> tc;

	while (tc--) {
		cin >> V >> m;
		vpii grp[3005];

		for (int u, v, w, i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			grp[u].push_back(pii(w, v));
			grp[v].push_back(pii(w, u));
		}

		cin >> s;

		vi dist = dijkstra(s, grp);
		for (int i = 1; i <= V; ++i) {
			if (i != s) {
				if (dist[i] == INF) {
					cout << -1 << " ";
				}
				else {
					cout << dist[i] << " ";
				}
			}
		}

		cout << endl;
		
	}

	return 0;
}
'''
