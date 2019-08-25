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

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3977
/**
** Comment **
**/

void buildTree(vint& a, vint& segtree, int left, int right, int index) {
	if (left == right) {
		segtree[index] = a[left];
		return;
	}

	int mid = (left + right) >> 1;
	buildTree(a, segtree, left, mid, 2 * index + 1);
	buildTree(a, segtree, mid + 1, right, 2 * index + 2);
	segtree[index] = segtree[2 * index + 1] * segtree[2 * index + 2];
}

int multiRange(vint& segtree, int left, int right, int from, int to, int index) {
	if (from <= left && to >= right) {
		return segtree[index];
	}

	if (from > right || to < left) {
		return 1;
	}

	int mid = (left + right) >> 1;
	return multiRange(segtree, left, mid, from, to, 2 * index + 1) *
		multiRange(segtree, mid + 1, right, from, to, 2 * index + 2);
}

void updateQuery(vint& a, vint& segtree, int left, int right, int index, int pos, int value) {
	if (pos < left || right < pos) {
		return;
	}

	if (left == right) {
		a[pos] = value;
		segtree[index] = value;
		return;
	}

	int mid = (left + right) >> 1;
	if (pos <= mid) {
		updateQuery(a, segtree, left, mid, 2 * index + 1, pos, value);
	}
	else {
		updateQuery(a, segtree, mid + 1, right, 2 * index + 2, pos, value);
	}

	segtree[index] = segtree[2 * index + 1] * segtree[2 * index + 2];
}

inline void printSol(int &value) {
	if (!value) {
		cout << "0";
	}
	else if (value > 0) {
		cout << "+";
	}
	else {
		cout << "-";
	}
}

inline int updateValue(int value) {
	if (value > 0) return 1;
	if (value < 0) return -1;
	return 0;
}

int main() {
	_FAST;
	int n, k;
	char q;

	while (cin >> n >> k) {
		vint seq(n);
		for (int i = 0; i < n; ++i) {
			cin >> seq[i];
			seq[i] = updateValue(seq[i]);
		}

		int h = (int)ceil(log2(n));
		int sizeTree = 2 * (int)pow(2, h) - 1;
		vint segtree(sizeTree);
		buildTree(seq, segtree, 0, n - 1, 0);

		for (int tmp1, tmp2, i = 0; i < k; ++i) {
			cin >> q >> tmp1 >> tmp2;

			if (q == 'C') {
				updateQuery(seq, segtree, 0, n - 1, 0, tmp1 - 1, updateValue(tmp2));
			}
			else {
				int value = multiRange(segtree, 0, n - 1, tmp1 - 1, tmp2 - 1, 0);
				printSol(value);
			}
		}

		cout << endl;
	}
	
	return 0;
}