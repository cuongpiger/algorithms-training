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
#include <iomanip>
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define x first
#define y second
const double pi = 3.14159265359;
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

inline void kahn(vector<vector<int>> &grp, vector<int> &indegree, vector<bool> &vs){
	queue<int> zero_indegree;

	for (int i = 0; i < 26; ++i){
		if (!indegree[i] && vs[i]){
			zero_indegree.push(i);
		}
	}

	while (!zero_indegree.empty()){
		int u = zero_indegree.front();
		zero_indegree.pop();
		cout << (char)(u + 'A');

		for (vector<int>::iterator it = grp[u].begin(); it != grp[u].end(); ++it){
			--indegree[*it];

			if (!indegree[*it]){
				zero_indegree.push(*it);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (true)
	{
		string s;
		vector<string> senten;
		vector<bool> vs(26, false);
		vector<int> indegree(26, 0);
		vector<vector<int>> grp(26, vector<int>());

		while (cin >> s, s != "#"){
			if (s == "") return 0;
			senten.push_back(s);
		}

		s = "";
		for (int u, v, sameLength, k, j, i = 1; i < senten.size(); ++i){
			sameLength = min(senten[i].length(), senten[i - 1].length());
			j = 0;

			while (j < sameLength){
				u = senten[i - 1][j] - 'A';
				v = senten[i][j] - 'A';
				vs[u] = vs[v] = true;
				++j;

				if (u != v){
					grp[u].push_back(v);
					++indegree[v];
					break;
				}
			}

			k = j;

			while (k < senten[i - 1].length()){
				s += senten[i - 1][k];
				++k;
			}

			while (j < senten[i].length()){
				s += senten[i][j];
				++j;
			}
		}

		kahn(grp, indegree, vs);
		for (int i = 0; i < s.length(); ++i){
			if (!vs[(int)(s[i] - 'A')]){
				cout << s[i];
			}
		}
		cout << endl;
	}

	return 0;
}