/*
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n;
vector<int> a;
vector<int> b;
int aBit[100];
int bBit[100];
long long mergeBit[100];
long long result1, result2;
const int MOD = 1999;

void bitCheck(int* v, int number) {
    for (int i = 0; i < 32; i++) {
        if (number & (1 << i)) {
            v[i]++;
        }
    }
}

long long findSumVal(int num) {
    long long sum = 1;

    for (int i = 0; i < num; i++) {
        sum = (sum % MOD * 2 % MOD) % MOD;
    }

    return sum;
}

void makeResult1() {
    for (int i = 0; i < 100; i++) {
        mergeBit[i] += (long long)aBit[i] * (long long)bBit[i];
        mergeBit[i + 1] += mergeBit[i] / 2;
        mergeBit[i] %= 2;
    }

    for (int i = 0; i < 100; i++) {
        long long temp = findSumVal(i);
        long long temp2 = mergeBit[i] ? temp : 0;
        result1 += (temp2 % MOD);
    }
}

void makeResult2() {
    for (int i = 0; i < 31; i++) {
        int aZeroMin = INT_MAX; int aZeroMax = 0; int aOneMin = INT_MAX; int aOneMax = 0;
        int bZeroMin = INT_MAX; int bZeroMax = 0; int bOneMin = INT_MAX; int bOneMax = 0;
        int curMod = pow(2, i);

        for (int j = 0; j < n; j++) {
            if (a[j] & (1 << i)) {
                aOneMin = min(aOneMin, a[j] % curMod);
                aOneMax = max(aOneMax, a[j] % curMod);
            } else {
                aZeroMin = min(aZeroMin, a[j] % curMod);
                aZeroMax = max(aZeroMax, a[j] % curMod);
            }
            
            if (b[j] & (1 << i)) {
                bOneMin = min(bOneMin, b[j] % curMod);
                bOneMax = max(bOneMax, b[j] % curMod);
            } else {
                bZeroMin = min(bZeroMin, b[j] % curMod);
                bZeroMax = max(bZeroMax, b[j] % curMod);
            }
        }

        bool condition1 = aZeroMin + bZeroMin >= curMod || aZeroMin + bZeroMin < 0;
        bool condition2 = aOneMin + bOneMin >= curMod || aOneMin + bOneMin < 0;
        bool condition3 = aZeroMax == 0 || bOneMax == 0 || aZeroMax + bOneMax < curMod;
        bool condition4 = aOneMax == 0 || bZeroMax == 0 || aOneMax + bZeroMax < curMod;

        if (condition1 && condition2 && condition3 && condition4) {
            result2 += pow(2, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
        bitCheck(aBit, temp);
    }

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
        bitCheck(bBit, temp);
    }

    makeResult1();
    makeResult2();
    cout << result1 % MOD << " " << result2;

    return 0;
}*/
