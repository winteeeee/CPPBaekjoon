/*
#include <iostream>
#include <vector>
using namespace std;

int dp[1000001] = {-1};
vector<int> route;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        if(i % 6 == 0) {
            dp[i] = min(dp[i/3], dp[i/2]) + 1;
        }

        else if(i % 3 == 0 && i % 2 != 0) {
            dp[i] = min(dp[i/3], dp[i-1]) + 1;
        }

        else if(i % 2 == 0 && i % 3 != 0) {
            dp[i] = min(dp[i/2], dp[i-1]) + 1;
        }

        else {
            dp[i] = dp[i-1] + 1;
        }
    }
    cout << dp[n] << "\n";
    int idx = 0;
    cout << n << " ";
    for(int i = n; i != 1; idx++) {
        if(i % 6 == 0) {
            if(dp[i / 3] < dp[i / 2]) {
                route.push_back(i / 3);
                i /= 3;
            }
            else {
                route.push_back(i / 2);
                i /= 2;
            }
        }

        else if(i % 3 == 0 && i % 2 != 0) {
            if(dp[i / 3] < dp[i - 1]) {
                route.push_back(i / 3);
                i /= 3;
            }
            else {
                route.push_back(i - 1);
                i--;
            }
        }

        else if(i % 2 == 0 && i % 3 != 0) {
            if(dp[i / 2] < dp[i - 1]) {
                route.push_back(i / 2);
                i /= 2;
            }
            else {
                route.push_back(i - 1);
                i--;
            }
        }

        else {
            route.push_back(i - 1);
            i--;
        }

        cout << route[idx] << " ";
    }
    return 0;
}*/
