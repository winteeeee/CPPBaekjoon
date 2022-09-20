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
    int almostZero = INT_MAX;
    int almostZeroIdx = 0;
    for(int i = 0; i < property.size(); i++) {
        if(abs(almostZero) > abs(property[i])) {
            almostZero = property[i];
            almostZeroIdx = i;
        }
    }

    property.erase(property.begin() + almostZeroIdx);
    int result[3];
    int prev = INT_MAX;
    int start = 0;
    int end = property.size() - 1;
    while(start < end) {
        int sum = property[start] + property[end];
        if(prev > abs(sum + almostZero)) {
            prev = abs(sum);
            result[0] = property[start];
            result[1] = property[end];
        }

        if(almostZero + sum != 0) {
            int temp1 = property[start] + property[end - 1];
            int temp2 = property[start + 1] + property[end];

            if(abs(temp1 + almostZero) < abs(temp2 + almostZero))
                end--;
            else
                start++;
        }

        else
            break;
    }

    result[2] = almostZero;
    sort(result, result + 3);
    cout << result[0] << " " << result[1] << " " << result[2];
}