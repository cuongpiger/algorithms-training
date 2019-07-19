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
 
int students, successStudents;
 
bool topologicalSort(vector<vector<int>> &grp, vector<int> &res) {
	vector<int> inDegree(students + 1, 0);
	queue<int> zeroInDegree;
 
	for (int u = 1; u <= students; ++u) {
		vector<int>::iterator it;
 
		for (it = grp[u].begin(); it != grp[u].end(); ++it) {
			++inDegree[*it];
		}
	}
 
	for (int i = 1; i <= students; ++i) {
		if (!inDegree[i]) {
			zeroInDegree.push(i);
		}
	}
 
	while (!zeroInDegree.empty()) {
		int u = zeroInDegree.front();
		zeroInDegree.pop();
		res.push_back(u);
		vector<int>::iterator it;
 
		for (it = grp[u].begin(); it != grp[u].end(); ++it) {
			--inDegree[*it];
 
			if (!inDegree[*it]) {
				zeroInDegree.push(*it);
			}
		}
	}
 
	for (int i = 1; i <= students; ++i) {
		if (inDegree[i]) {
			return false;
		}
	}
 
	return true;
}
 
int main() {
	vector<vector<int>> grp;
	vector<int> res;
	vector<int> position;
 
	cin >> students >> successStudents;
 
	grp.assign(students + 1, vector<int>());
	position.resize(students + 1);
 
	for (int wishes, i = 1; i <= successStudents; ++i) {
		scanf("%d", &wishes);
 
		for (int statements, j = 0; j < wishes; ++j) {
			scanf("%d", &statements);
			grp[i].push_back(statements);
		}
	}
 
	if (topologicalSort(grp, res)) {
		int pos = 0;
 
		for (int i = 0; i < res.size(); ++i) {
			int student = res[i];
			position[student] = pos;
			pos = student;
		}
 
		for (int i = 1; i <= students; ++i) {
			printf("%d\n", position[i]);
		}
	}
 
	return 0;
} 
