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
#include <sstream>
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define x first
#define y second
#define vit vector<int>::iterator
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
https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/
**/

void allTopologicalSort(map<int, char> &vari, vector<vector<int>> &grp, vector<int> &indegree, vector<int> &res, vector<bool> &vs, int &numVertices){
	bool flag = false;

	for (int i = 0; i < numVertices; ++i){
		if (!indegree[i] && !vs[i]){
			for (vit it = grp[i].begin(); it != grp[i].end(); ++it){
				--indegree[*it];
			}

			res.push_back(i);
			vs[i] = true;
			allTopologicalSort(vari, grp, indegree, res, vs, numVertices);

			//reset
			res.erase(res.end() - 1);
			vs[i] = false;
			for (vit it = grp[i].begin(); it != grp[i].end(); ++it){
				++indegree[*it];
			}

			flag = true;
		}
	}

	if (!flag){
		for (int i = 0; i < res.size(); ++i){
			cout << vari[res[i]];
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	bool br = false;
	string line;
	stringstream inStream;

	while (getline(cin, line)){
		vector<char> letter;
		map<int, char> vari;
		int pos[26];
		char u, v;
		
		inStream.clear();
		inStream << line;
		while (inStream >> u){
			letter.push_back(u);
		}
		
		int numVertices = letter.size();
		sort(letter.begin(), letter.end());
		for (int i = 0; i < numVertices; ++i){
			vari.insert({ i, letter[i] });
			pos[(int)(letter[i] - 'a')] = i;
		}

		
		vector<vector<int>> grp(numVertices, vector<int>());
		vector<int> res, indegree(numVertices, 0);
		vector<bool> vs(numVertices, false);

		getline(cin, line);
		inStream.clear();
		inStream << line;
		while (inStream >> u >> v){
			grp[pos[(int)(u - 'a')]].push_back(pos[(int)(v - 'a')]);
			++indegree[pos[(int)(v - 'a')]];
		}

		if (br){
			cout << endl;
		}
		br = true;
		allTopologicalSort(vari, grp, indegree, res, vs, numVertices);
	}
	
	return 0;
}