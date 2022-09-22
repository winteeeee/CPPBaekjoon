#include <iostream>
#include <vector>
using namespace std;

pair<int, int> mat[501];
vector<pair<pair<int, int>, long long>> DP;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        mat[i] = {r, c};
    }


    DP.push_back({{mat[0].first, mat[0].second}, 0});

    for(int i = 1; i < n - 1; i++) {
        int first = DP[i - 1].first.first * mat[i].first * mat[i].second;
        int second = mat[i].first * mat[i + 1].first * mat[i + 1].second;

        if(first < second)
            DP.push_back({{DP[i - 1].first.first, mat[i].second}, first + DP[i - 1].second});
        else
            DP.push_back({{mat[i].first, mat[i + 1].second}, second + DP[i - 1].second});

    }
    DP.push_back({{DP[n - 2].first.first, mat[n - 1].second}, DP[n - 2].first.first * mat[n - 1].first * mat[n - 1].second + DP[n - 2].second});

    cout << DP[n - 1].second;
    return 0;
}

//앞 행 * 뒤 행 * 뒤 열 -> 크기는 앞 행 뒤 열
//min[원 배열 * dp[i - 1], 원 배열 * 원 배열 + 1]