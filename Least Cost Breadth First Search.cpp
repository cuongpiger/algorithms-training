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

//==========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
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
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef deque<int> dqi;
typedef queue<int> qi;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//
/**
** Comment **
**/

#define to first
#define cost second

inline int LCBFS(int n, vector<vector<pair<int, int>>>& grp, int src, int dst) {
	int res = INT_MAX;
	queue<pair<int, int>> q;
	q.push(make_pair(src, 0));

	while (!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();

		if (u.to == dst) {
			res = min(res, u.cost);
		}

		for (int i = 0; i < grp[u.to].size(); ++i) {
			pair<int, int> v = grp[u.to][i];

			if (u.cost + v.cost <= res) {
				q.push(make_pair(v.to, u.cost + v.cost));
			}
		}
	}

	return res == INT_MAX ? -1 : res;
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int V, E;
	string src, dst;
	map<string, int> city;
	
	cin >> V >> E;
	vector<vector<pair<int, int>>> grp(V + 10);
	for (int w, i = 1; i <= E; ++i) {
		cin >> src >> dst >> w;

		if (city.count(src) <= 0) {
			city[src] = i;
		}

		if (city.count(dst) <= 0) {
			city[dst] = i;
		}

		grp[city[src]].push_back(make_pair(city[dst], w));
		grp[city[dst]].push_back(make_pair(city[src], w));
	}

	int res = LCBFS(V, grp, city["Arad"], city["Bucharest"]);
	cout << res << endl;

	return 0;
}

/*
Bộ test từ đề bài của thầy

Bộ test 1

19 20
Oradea Zerind 71
Zerind Arad 75
Arad Sibiu 140
Oradea Sibiu 151
Arad Timisoara 118
Timisoara Lugoj 111
Sibiu Fagaras 99
Fagaras Bucharest 211
Sibiu RimnicuVilcea 80
RimnicuVilcea Pitesti 97
RimnicuVilcea Craiova 146
Craiova Pitesti 138
Craiova Dobreta 120
Dobreta Mehadia 75
Pitesti Bucharest 101
Neamt Iasi 87
Iasi Vaslui 92
Vaslui Urziceni 142
Urziceni Hirsova 98
Hirsova Eforie 86

Bộ test 2

20 23
Oradea Zerind 71
Zerind Arad 75
Arad Sibiu 140
Oradea Sibiu 151
Arad Timisoara 118
Timisoara Lugoj 111
Sibiu Fagaras 99
Fagaras Bucharest 211
Sibiu RimnicuVilcea 80
RimnicuVilcea Pitesti 97
RimnicuVilcea Craiova 146
Craiova Pitesti 138
Craiova Dobreta 120
Dobreta Mehadia 75
Pitesti Bucharest 101
Neamt Iasi 87
Iasi Vaslui 92
Vaslui Urziceni 142
Urziceni Hirsova 98
Hirsova Eforie 86
Lugoj Mehadia 70
Bucharest Giurgiu 90
Bucharest Urziceni 85

*/
