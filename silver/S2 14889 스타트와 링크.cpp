#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<vector<int>> table;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> p(n, 0);
    for(int i = 0; i < n; i++) {
        p[i] = i;
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            cin >> temp[j];
        }
        table.push_back(temp);
    }

    int result = INT_MAX;

    do {
        int start = 0;
        int link = 0;

        for(int i = 0; i < p.size() / 2; i++) {
            for(int j = i + 1; j < p.size() / 2; j++) {
                start += (table[p[i]][p[j]] + table[p[j]][p[i]]);
                link += (table[p[i + p.size() / 2]][p[j + p.size() / 2]] + table[p[j + p.size() / 2]][p[i + p.size() / 2]]);
            }
        }

        int temp = abs(start - link);
        if(result > temp) {
            result = temp;
        }
    } while(next_permutation(p.begin(), p.end()));

    cout << result;
    return 0;
}