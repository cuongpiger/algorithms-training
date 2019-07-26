#pragma warning(disable:4996)
#include <iostream>
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
#include <sstream>
using namespace std;

//=============================================================================================
const double pi = 3.14159265359;
#define p(a) ((a) * (a))
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

/**
** Comment **
**/

int defInput[5], vs[5];;
int res[4], variable[4];
p2ll minAns = { 1e10, 1 };

inline bool compare(p2ll &tmpAns){
	p2ll tmp = { tmpAns.first * minAns.second, tmpAns.second * minAns.first };
	return tmp.first < tmp.second;
}

inline void calc(){
	p2ll tmpAns = { abs(defInput[variable[0]] * defInput[variable[3]] - defInput[variable[1]] * defInput[variable[2]]), defInput[variable[1]] * defInput[variable[3]] };

	if (compare(tmpAns)){
		minAns = tmpAns;
		for (int i = 0; i < 4; ++i){
			res[i] = variable[i];
		}
	}
}

void solve(int c){
	for (int i = 0; i < 5; ++i){
		if (!vs[i]){
			variable[c] = i;
			vs[i] = true;

			if (c == 3){
				calc();
			}
			else{
				solve(c + 1);
			}

			vs[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 5; ++i){
		cin >> defInput[i];
	}

	solve(0);
	cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;

	return 0;
}
