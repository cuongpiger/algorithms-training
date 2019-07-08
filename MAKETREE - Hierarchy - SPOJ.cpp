#pragma warning(disable4996)
#include iostream
#include algorithm
#include functional
#include queue
#include vector
using namespace std;
 
=============================================================================================
const double pi = 3.14159265359;
#define p(a) ((a)  (a))
typedef long long ll;
typedef long double ld;
typedef pairint, int pii;
typedef pairdouble, double pdd;
typedef pairll, ll p2ll;
typedef pairstring, int psi;
typedef pairld, ld p2ld;
typedef pairchar, char pcc;
=============================================================================================
 
int students, successStudents;
 
bool topologicalSort(vectorvectorint &grp, vectorint &res) {
	vectorint inDegree(students + 1, 0);
	queueint zeroInDegree;
 
	for (int u = 1; u = students; ++u) {
		vectorintiterator it;
 
		for (it = grp[u].begin(); it != grp[u].end(); ++it) {
			++inDegree[it];
		}
	}
 
	for (int i = 1; i = students; ++i) {
		if (!inDegree[i]) {
			zeroInDegree.push(i);
		}
	}
 
	while (!zeroInDegree.empty()) {
		int u = zeroInDegree.front();
		zeroInDegree.pop();
		res.push_back(u);
		vectorintiterator it;
 
		for (it = grp[u].begin(); it != grp[u].end(); ++it) {
			--inDegree[it];
 
			if (!inDegree[it]) {
				zeroInDegree.push(it);
			}
		}
	}
 
	for (int i = 1; i = students; ++i) {
		if (inDegree[i]) {
			return false;
		}
	}
 
	return true;
}
 
int main() {
	vectorvectorint grp;
	vectorint res;
	vectorint position;
 
	cin  students  successStudents;
 
	grp.assign(students + 1, vectorint());
	position.resize(students + 1);
 
	for (int wishes, i = 1; i = successStudents; ++i) {
		scanf(%d, &wishes);
 
		for (int statements, j = 0; j  wishes; ++j) {
			scanf(%d, &statements);
			grp[i].push_back(statements);
		}
	}
 
	if (topologicalSort(grp, res)) {
		int pos = 0;
 
		for (int i = 0; i  res.size(); ++i) {
			int student = res[i];
			position[student] = pos;
			pos = student;
		}
 
		for (int i = 1; i = students; ++i) {
			printf(%dn, position[i]);
		}
	}
 
	return 0;
} 