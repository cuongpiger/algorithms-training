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
#define sit set<int>::iterator
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
//==========================================================================================================================

//https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph/0
/**
** Comment **
**/

#define from first
#define to second

void dfs(pii pos, vvi& grp, vvb& vs) {
	vs[pos.from][pos.to] = true;

	for (int i = 0; i < grp[pos.to].size(); ++i) {
		pii next = { pos.from, grp[pos.to][i] };

		if (!vs[next.from][next.to]) {
			dfs(next, grp, vs);
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;

	while (tc--) {
		int V;
		cin >> V;

		vvb vs(V, vb(V, false));
		vvi grp(V);

		for (int i = 0; i < V; ++i) {
			for (int cnn, j = 0; j < V; ++j) {
				cin >> cnn;

				if (cnn) {
					grp[i].push_back(j);
				}
			}
		}

		for (int i = 0; i < V; ++i) {
			dfs({ i, i }, grp, vs);
		}

		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				cout << (int)vs[i][j] << " ";
			}
		}

		cout << endl;
	}

	return 0;
}