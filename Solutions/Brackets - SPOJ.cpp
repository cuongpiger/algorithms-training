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

//https://www.spoj.com/problems/BRCKTS/
/**
** Comment **
**/

#define open first
#define close second

inline pii classify(char x) {
	pii rut = { 0, 0 };
	if (x == '(') rut.open = 1;
	else rut.close = 1;
	return rut;
}

void buildTree(string& a, vpii& segtree, int left, int right, int index) {
	if (left == right) {
		segtree[index] = classify(a[left]);
		return;
	}

	int mid = (left + right) >> 1;
	buildTree(a, segtree, left, mid, 2 * index + 1);
	buildTree(a, segtree, mid + 1, right, 2 * index + 2);
	int common = min(segtree[2 * index + 1].open, segtree[2 * index + 2].close);
	segtree[index].open = segtree[2 * index + 1].open + segtree[2 * index + 2].open - common;
	segtree[index].close = segtree[2 * index + 1].close + segtree[2 * index + 2].close - common;
}

void updateQuery(string& a, vpii& segtree, int left, int right, int index, int pos, char x) {
	if (pos < left || right < pos) {
		return;
	}

	if (left == right) {
		a[pos] = x;
		segtree[index] = classify(x);
		return;
	}

	int mid = (left + right) >> 1;
	if (pos <= mid) {
		updateQuery(a, segtree, left, mid, 2 * index + 1, pos, x);
	}
	else {
		updateQuery(a, segtree, mid + 1, right, 2 * index + 2, pos, x);
	}

	int common = min(segtree[2 * index + 1].open, segtree[2 * index + 2].close);
	segtree[index].open = segtree[2 * index + 1].open + segtree[2 * index + 2].open - common;
	segtree[index].close = segtree[2 * index + 1].close + segtree[2 * index + 2].close - common;
}

int main() {
	_FAST;

	for (int cs = 1; cs <= 10; ++cs) {
		_cin(n);
		string bw; cin >> bw;
		_cin(m);

		cout << "Test " << cs << ":" << endl;
		if (n & 1) {
			for (int p, i = 0; i < m; ++i) {
				cin >> p;

				if (!p) {
					cout << "NO" << endl;
				}
			}
		}
		else {
			int h = (int)ceil(log2(n));
			int sizeTree = 2 * (int)pow(2.0, h) - 1;
			vpii segtree(sizeTree);
			buildTree(bw, segtree, 0, n - 1, 0);

			for (int p, i = 0; i < m; ++i) {
				cin >> p;

				if (p) {
					char opposite = (bw[p - 1] == '(' ? ')' : '(');
					updateQuery(bw, segtree, 0, n - 1, 0, p - 1, opposite);
				}
				else {
					if (!segtree[0].open && !segtree[0].close) {
						cout << "YES" << endl;
					}
					else {
						cout << "NO" << endl;
					}
				}
			}
		}
	}

	return 0;
}