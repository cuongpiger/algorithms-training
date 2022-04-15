// O(n*log(n))

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)


int main() {
    FAST_IO;
    // FILE_IO;

    int n, a, b, tasks[2010];
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) cin >> tasks[i];

    sort(tasks, tasks + (sizeof(tasks)/sizeof(tasks[0])) / 2010 * n);

    cout << tasks[b] - tasks[b - 1];

    return 0;
}