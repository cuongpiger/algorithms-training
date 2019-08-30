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
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
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
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvint;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvint;
typedef vector<vector<vector<long long>>> vvvll;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
//=========================================================================================================================

//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
/**
** Comment **
**/

vint a, lazy, segtree;

int buildTree(int left, int right, int index) {
	if (left == right) {
		return segtree[index] = a[left];
	}

	int mid = (left + right) >> 1;
	return segtree[index] = min(buildTree(left, mid, 2 * index + 1),
		buildTree(mid + 1, right, 2 * index + 2));
}

void updateQuery(int left, int right, int index, int value) {
	if (left > right) {
		return;
	}

	if (lazy[index]) {
		segtree[index] -= lazy[index];
		
		if (left != right) {
			lazy[2 * index + 1] += lazy[index];
			lazy[2 * index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if (segtree[index] > value) {
		segtree[index] -= 1;

		if (left != right) {
			lazy[2 * index + 1] += 1;
			lazy[2 * index + 2] += 1;
		}
		return;
	}

	if (left == right) {
		return;
	}

	int mid = (left + right) >> 1;
	updateQuery(left, mid, 2 * index + 1, value);
	updateQuery(mid + 1, right, 2 * index + 2, value);
	segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}

void RMQ(int left, int right, int index) {
	if (left > right) {
		return;
	}

	if (lazy[index]) {
		segtree[index] -= lazy[index];

		if (left != right) {
			lazy[2 * index + 1] += lazy[index];
			lazy[2 * index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if (left == right) {
		cout << segtree[index] << " ";
		return;
	}

	int mid = (left + right) >> 1;
	RMQ(left, mid, 2 * index + 1);
	RMQ(mid + 1, right, 2 * index + 2);
}

int main() {
	FAST_IO;
	int n, m, x; cin >> n;
	a = vint(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int h = (int)ceil(log2(n));
	int sizeTree = 2 * (int)pow(2.0, h) - 1;
	segtree = vint(sizeTree);
	lazy = vint(sizeTree, 0);
	buildTree(0, n - 1, 0);

	cin >> m;
	while (m--) {
		cin >> x;
		updateQuery(0, n - 1, 0, x);
	}
	RMQ(0, n - 1, 0);

	return 0;
}