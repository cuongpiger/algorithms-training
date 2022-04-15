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

    int n, tasks[2010], bTasks[2010], ranks[2010] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i];
        bTasks[i] = tasks[i];
    }

    sort(tasks, tasks + (sizeof(tasks)/sizeof(tasks[0])) / 2010 * n, greater<int>());

    for (int i = 0, r = 1; i < n; ++i, ++r) {
        if (ranks[tasks[i]] == 0)
            ranks[tasks[i]] = r;
    }

    for (int i = 0; i < n; ++i) {
        cout << ranks[bTasks[i]] << " ";
    }

    return 0;
}