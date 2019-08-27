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
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
typedef vector<vector<pii>> vvpii;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2176
/**
** Comment **
**/

#define start first
#define end second
const int add = 100000;

void buildTree(vint& segtree, vint& freq, int left, int right, int index) {
	if (left == right) {
		segtree[index] = freq[left];
		return;
	}

	int mid = (left + right) >> 1;
	buildTree(segtree, freq, left, mid, 2 * index + 1);
	buildTree(segtree, freq, mid + 1, right, 2 * index + 2);
	segtree[index] = max(segtree[2 * index + 1], segtree[2 * index + 2]);
}

int RMQ(vint& segtree, int left, int right, int from, int to, int index) {
	if (from <= left && to >= right) {
		return segtree[index];
	}

	if (from > right || to < left || from > to) {
		return 0;
	}

	int mid = (left + right) >> 1;
	return max(RMQ(segtree, left, mid, from, to, 2 * index + 1),
		RMQ(segtree, mid + 1, right, from, to, 2 * index + 2));
}

inline int findMaxOccur(unordered_map<int, pii>& range, vint& a, vint& segtree, int from, int to) {
	if (a[from] == a[to]) {
		return (to - from + 1);
	}
	else {
		int leftMost = range[a[from]].end + 1;
		int rightMost = range[a[to]].start - 1;
		int cntLeft = leftMost - from;
		int cntRight = to - rightMost;
		return max(max(cntLeft, cntRight), RMQ(segtree, 0, a.size() - 1, leftMost, rightMost, 0));
	}
}

int main() {
	_FAST;
	int n, q;

	while (cin >> n && n) {
		cin >> q;
		vint a(n), freq(n);
		vint cnt(200010, 0);
		unordered_map<int, pii> range;

		for (int from = 0, i = 0; i < n; ++i) {
			cin >> a[i];
			++cnt[a[i] + add];

			if (a[i] != a[from]) {
				range[a[from]] = make_pair(from, i - 1);
				from = i;
			}

			if (i == n - 1) {
				range[a[i]] = make_pair(from, i);
			}
		}

		for (int i = 0; i < n; ++i) {
			freq[i] = cnt[a[i] + add];
		}

		int h = (int)ceil(log2(n));
		int sizeTree = 2 * (int)pow(2.0, h) - 1;
		int from, to;
		vint segtree(sizeTree);
		buildTree(segtree, freq, 0, n - 1, 0);

		while (q--) {
			cin >> from >> to;
			cout << findMaxOccur(range, a, segtree, from - 1, to - 1) << "\n";
		}
	}

	return 0;
}