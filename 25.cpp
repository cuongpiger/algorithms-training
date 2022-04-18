// O(n*log(n)) with n = 8

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int n, l = -1, r = -1; cin >> n;
    int *a = new int[n], *sa = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sa[i] = a[i];
    }

    sort(sa, sa + n);

    for (int i = 0; i < n; ++i) {
        if (a[i] != sa[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }

    if (l != r) 
        for (int i = l, j = r; i <= r; ++i, --j) {
            if (a[i] != sa[j]) {
                cout << "no";
                return 0;
            }
        }

    if (l == -1 && r == -1) {
        l = 0;
        r = 0;
    }
    
    cout << "yes" << endl << l + 1 << " " << r + 1;

    return 0;
}