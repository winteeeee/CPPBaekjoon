/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
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

    int result[3];
    ll tempSum = 3000000001;
    for(int i = 0; i < property.size(); i++) {
        ll prev = 3000000001;
        int tempStartIdx;
        int tempEndIdx;
        int almostZero = property[i];
        int almostZeroIdx = i;
        int start = (0 != i) ? 0 : 1;
        int end = (property.size() - 1 != i) ?  property.size() - 1 :  property.size() - 2;

        while (start < end) {
            ll sum = property[start] + property[end];
            if (prev > abs(sum + almostZero)) {
                prev = abs(sum + almostZero);
                tempStartIdx = start;
                tempEndIdx = end;
            }

            if (almostZero + sum != 0) {
                ll temp1 = property[start] + property[end - 1];
                ll temp2 = property[start + 1] + property[end];

                if (abs(temp1 + almostZero) < abs(temp2 + almostZero)) {
                    if(end - 1 != almostZeroIdx)
                        end--;
                    else
                        end -= 2;
                }

                else {
                    if(start + 1 != almostZeroIdx)
                        start++;
                    else
                        start += 2;
                }
            }

            else
                break;
        }

        if(prev < tempSum) {
            tempSum = prev;
            result[0] = property[tempStartIdx];
            result[1] = property[tempEndIdx];
            result[2] = almostZero;
        }
    }

    sort(result, result + 3);
    cout << result[0] << " " << result[1] << " " << result[2];
}*/
