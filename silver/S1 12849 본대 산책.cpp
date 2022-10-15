/*
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<vector<ll>> building(8, vector<ll>(8, 0));   //인접행렬
const int MOD = 1e9 + 7;
*/
/* * 0 정보과학
 * 1 전산
 * 2 미래
 * 3 신양
 * 4 한경
 * 5 진리
 * 6 형남
 * 7 학생*//*


vector<vector<ll>> pow(vector<vector<ll>> building, int n);
vector<vector<ll>> mul(vector<vector<ll>> g1, vector<vector<ll>> g2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    building[0] = {0, 1, 1, 0, 0, 0, 0, 0};
    building[1] = {1, 0, 1, 1, 0, 0, 0, 0};
    building[2] = {1, 1, 0, 1, 1, 0, 0, 0};
    building[3] = {0, 1, 1, 0, 1, 1, 0, 0};
    building[4] = {0, 0, 1, 1, 0, 1, 1, 0};
    building[5] = {0, 0, 0, 1, 1, 0, 0, 1};
    building[6] = {0, 0, 0, 0, 1, 0, 0, 1};
    building[7] = {0, 0, 0, 0, 0, 1, 1, 0};

    int d;
    cin >> d;
    vector<vector<ll>> resultBuilding = pow(building, d);

    ll result = resultBuilding[0][0];
    cout << result % MOD;
    return 0;
}

vector<vector<ll>> pow(vector<vector<ll>> building, int n) {
    if(n == 1)
        return building;
    else {
        vector<vector<ll>> temp = pow(building, n / 2);
        if(n & 1)
            return mul(mul(temp, temp), building);
        else
            return mul(temp, temp);
    }
}

vector<vector<ll>> mul(vector<vector<ll>>g1, vector<vector<ll>> g2) {
    vector<vector<ll>> result(8, vector<ll>(8, 0));

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            for(int k = 0; k < 8; k++) {
                result[i][j] += (g1[i][k] % MOD * g2[k][j] % MOD % MOD);
            }
        }
    }

    return result;
}
*/
