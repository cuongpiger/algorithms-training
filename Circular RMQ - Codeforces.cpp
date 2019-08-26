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
#define _i(X) (int)(X)
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

//https://codeforces.com/problemset/problem/52/C
/**
** Comment **
**/

const ll INF = ((ll)2e11 + 100000);

void buildTree(vll& a, vll& segtree, int left, int right, int index) {
	if (left == right) {
		segtree[index] = a[left];
		return;
	}

	int mid = (left + right) >> 1;
	buildTree(a, segtree, left, mid, 2 * index + 1);
	buildTree(a, segtree, mid + 1, right, 2 * index + 2);
	segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}

void updateQuery(vll& segtree, vll& lazy, int left, int right, int from, int to, ll delta, int index) {
	if (left > right) {
		return;
	}

	if (lazy[index]) {
		segtree[index] += lazy[index];

		if (left != right) {
			lazy[2 * index + 1] += lazy[index];
			lazy[2 * index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if (from > right || to < left) {
		return;
	}

	if (from <= left && to >= right) {
		segtree[index] += delta;
		
		if (left != right) {
			lazy[2 * index + 1] += delta;
			lazy[2 * index + 2] += delta;
		}

		return;
	}

	int mid = (left + right) >> 1;
	updateQuery(segtree, lazy, left, mid, from, to, delta, 2 * index + 1);
	updateQuery(segtree, lazy, mid + 1, right, from, to, delta, 2 * index + 2);
	segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}

ll minRange(vll& segtree, vll& lazy, int left, int right, int from, int to, int index) {
	if (left > right) {
		return INF;
	}

	if (lazy[index]) {
		segtree[index] += lazy[index];

		if (left != right) {
			lazy[2 * index + 1] += lazy[index];
			lazy[2 * index + 2] += lazy[index];
		}

		lazy[index] = 0;
	}

	if (from > right || to < left) {
		return INF;
	}

	if (from <= left && to >= right) {
		return segtree[index];
	}

	int mid = (left + right) >> 1;
	return min(minRange(segtree, lazy, left, mid, from, to, 2 * index + 1),
		minRange(segtree, lazy, mid + 1, right, from, to, 2 * index + 2));
}

int main() {
	_FAST;

	_cin(n);
	vll a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int h = (int)ceil(log2(n));
	int sizeTree = 2 * (int)pow(2.0, h) - 1;
	vll segtree(sizeTree, INF), lazy(sizeTree, 0);
	buildTree(a, segtree, 0, n - 1, 0);

	_cin(m);
	string s;
	stringstream inStream;
	cin.ignore(256, '\n');

	for (int tmp, i = 0; i < m; ++i) {
		vll ques;
		ll res;
		getline(cin, s, '\n');
		inStream.clear();
		inStream << s;

		while (inStream >> tmp) {
			ques.push_back(tmp);
		}

		if (ques.size() == 2) {
			if (ques[0] > ques[1]) {
				res = min(minRange(segtree, lazy, 0, n - 1, ques[0], n - 1, 0),
					minRange(segtree, lazy, 0, n - 1, 0, ques[1], 0));
			}
			else {
				res = minRange(segtree, lazy, 0, n - 1, ques[0], ques[1], 0);
			}

			cout << res << endl;
		}
		else {
			if (ques[0] > ques[1]) {
				updateQuery(segtree, lazy, 0, n - 1, ques[0], n - 1, ques[2], 0);
				updateQuery(segtree, lazy, 0, n - 1, 0, ques[1], ques[2], 0);
			}
			else {
				updateQuery(segtree, lazy, 0, n - 1, ques[0], ques[1], ques[2], 0);
			}
		}
	}

	return 0;
}