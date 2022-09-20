/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> property;
void input();
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    input();
    solve();

    return 0;
}

void input() {
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        property.push_back(temp);
    }
}

void solve() {
    cout.tie(NULL);
    sort(property.begin(), property.end());
    pair<int, int> result;
    int prev = INT_MAX;

    int start = 0;
    int end = property.size() - 1;
    while(start < end) {
        int sum = property[start] + property[end];
        if(prev > abs(sum)) {
            prev = abs(sum);
            result = {property[start], property[end]};
        }

        if(sum != 0) {
            int temp1 = property[start] + property[end - 1];
            int temp2 = property[start + 1] + property[end];

            if(abs(temp1) < abs(temp2))
                end--;
            else
                start++;
        }

        else
            break;
    }

    cout << result.first << " " << result.second;
}
*/
