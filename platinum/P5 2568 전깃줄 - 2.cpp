/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> wire;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        wire.push_back({a, b});
    }

    sort(wire.begin(), wire.end());
    vector<int> result;
    int prevIdx = 0;
    for(int i = 0; i < n; i++) {
        pair<int, int> cur = wire[i];

        if(wire[prevIdx].second > cur.second) {
            result.push_back(cur.first);
            continue;
        }

        if(i != n - 1) {
            if(wire[i + 1].second < cur.second) {
                result.push_back(cur.first);
                if(prevIdx == 0)
                    prevIdx = i + 1;
                continue;
            }
        }
    }

    int size = result.size();
    cout << size << "\n";
    for(int i = 0; i < size; i++)
        cout << result[i] << "\n";

    return 0;
}

*/
/*
 * 아래 반례를 어떻게 처리할지 고민해볼것
9
1 50000
2 4
3 11
4 12
5 6
6 3
7 2
8 9
9 10

5
1
3
4
6
7
 */
