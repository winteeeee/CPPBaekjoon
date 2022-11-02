/*
#include <iostream>
using namespace std;

int find(int pos, string S, string P);
bool isEqual(int pos, string S, string P);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, P;
    cin >> S >> P;

    if(find(0, S, P) != -1)
        cout << 1;
    else
        cout << 0;

    return 0;
}
bool isEqual(int pos, string S, string P) {
    for(int i = 0; P[i] != '\0'; i++) {
        if(S[i + pos] != P[i])
            return false;
    }

    return true;
}

int find(int pos, string S, string P) {
    if(P.length() > S.length() || pos > S.length())
        return -1;

    int thisLength = S.length();
    int subLength = P.length();
    int thisHash, subHash;
    thisHash = subHash = 0;
    int power = 1;
    const int X = 2;
    const int MOD = 127;

    for(int i = pos; i <= thisLength - subLength; i++) {
        if(i == pos) {
            for(int j = 0; j < subLength; j++) {
                thisHash += (S[pos + subLength - 1 - j] % MOD * power % MOD) % MOD;
                subHash += (P[subLength - 1 - j] % MOD * power % MOD) % MOD;

                if(j < subLength - 1)
                    power = (power % MOD * X % MOD) % MOD;
            }
            thisHash %= MOD;
            subHash %= MOD;
            power %= MOD;
        }

        else
            thisHash = (X % MOD * (thisHash % MOD - (S[i - 1]) % MOD * power % MOD) % MOD + S[i + subLength - 1] % MOD) % MOD;

        if(thisHash == subHash) {
            if(isEqual(i, S, P)) {
                return i;
            }
        }
    }

    return -1;
}*/
