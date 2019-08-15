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

//==============================================================================================
#define pw(a) ((a) * (a))
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
#define _FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define _FAST ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define _i(X) (int)(X)
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<vector<int>> vvint;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a % b); }
inline double _distance(const pii& a, const pii& b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//==============================================================================================

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=378
/**
** Comment **
**/

struct block {
	int x, y, z;
};

int main() {
	_FAST;
	int n, x, y, z, cs = 1;

	while (cin >> n && n){
		vector<block> blocks;
		int res = -1;

		for (int i = 0; i < n; ++i){
			cin >> x >> y >> z;
			blocks.push_back({ x, y, z }), blocks.push_back({ y, x, z });
			blocks.push_back({ x, z, y }), blocks.push_back({ z, x, y });
			blocks.push_back({ y, z, x }), blocks.push_back({ z, y, x });
		}
		
		vint lis(blocks.size());
		sort(blocks.begin(), blocks.end(), [](const block &a, const block &b){
			if (a.x > b.x || (a.x == b.x && a.y > b.y) || (a.x == b.x && a.y == b.y && a.z > b.z))
				return true;

			return false;
		});

		for (int i = 0; i < blocks.size(); ++i){
			lis[i] = blocks[i].z;

			for (int j = 0; j < i; ++j){
				if (blocks[j].x > blocks[i].x && blocks[j].y > blocks[i].y && lis[j] + blocks[i].z > lis[i]){
					lis[i] = lis[j] + blocks[i].z;
				}
			}
		}

		for (int i = 0; i < lis.size(); ++i){
			res = max(res, lis[i]);
		}

		cout << "Case " << cs++ << ": maximum height = " << res << "\n";
	}
	
	return 0;
}
