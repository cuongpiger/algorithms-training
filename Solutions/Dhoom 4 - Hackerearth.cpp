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

//=========================================================================================================================
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
//=========================================================================================================================

//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/description/
/**
** Comment **
**/

inline int BFS(int keySama, int keyLock, vi& keys, vi& times) {
	if (keySama == keyLock) {
		return 0;
	}
	else {
		qi q;
		q.push(keySama);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int i = 0; i < keys.size(); ++i) {
				int v = (u * (ll)keys[i]) % 100000;

				if (!times[v]) {
					times[v] = times[u] + 1;

					if (v == keyLock) {
						return times[v];
					}

					q.push(v);
				}
			}
		}

		return -1;
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);

	int keySama, keyLock, n;
	vi keys;
	vi times(100010);

	cin >> keySama >> keyLock >> n;
	keys = vi(n);
	for (int i = 0; i < n; ++i) {
		cin >> keys[i];
	}

	cout << BFS(keySama, keyLock, keys, times);

	return 0;
}