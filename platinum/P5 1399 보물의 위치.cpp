/*
#include <iostream>
using namespace std;

long long t, k, m;
pair<long long, long long> result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> k >> m;
        result = {0, 0};

        long long remainNumber;
        if(m % 9 == 0) {
            result.second++;

            if(k > 1) {
                remainNumber = (k + 2) % 4;
                if (remainNumber >= 0)
                    result.first += 9;
                if (remainNumber >= 1)
                    result.second -= 9;
                if (remainNumber >= 2)
                    result.first -= 9;
                if (remainNumber >= 3)
                    result.second += 9;
            }
        }

        else if(m % 9 == 1) {
            remainNumber = k % 4;

            if(remainNumber == 1)
                result.second= 1;
            else if(remainNumber == 2) {
                result.first = 1;
                result.second = 1;
            }
            else if(remainNumber == 3)
                result.first = 1;

        }

        else if(m % 9 == 2) {
            remainNumber = k % 12 - 1;

            if(remainNumber >= 0)
                result.second += 1;
            if(remainNumber >= 1)
                result.first += 2;
            if(remainNumber >= 2)
                result.second -= 4;
            if(remainNumber >= 3)
                result.first -= 8;
            if(remainNumber >= 4)
                result.second += 7;
            if(remainNumber >= 5)
                result.first += 5;
            if(remainNumber >= 6)
                result.second -= 1;
            if(remainNumber >= 7)
                result.first -= 2;
            if(remainNumber >= 8)
                result.second += 4;
            if(remainNumber >= 9)
                result.first += 8;
            if(remainNumber >= 10)
                result.second -= 7;
            if(remainNumber >= 11)
                result.first -= 5;
        }

        else if(m % 9 == 3) {
            result.second++;
            if(k > 1)
                result.first += 3;

            if(k > 2) {
                remainNumber = (k + 1) % 4;
                if (remainNumber >= 0)
                    result.second -= 9;
                if (remainNumber >= 1)
                    result.first -= 9;
                if (remainNumber >= 2)
                    result.second += 9;
                if (remainNumber >= 3)
                    result.first += 9;
            }
        }

        else if(m % 9 == 4) {
            remainNumber = k % 12 - 1;

            if(remainNumber >= 0)
                result.second += 1;
            if(remainNumber >= 1)
                result.first += 4;
            if(remainNumber >= 2)
                result.second -= 7;
            if(remainNumber >= 3)
                result.first -= 1;
            if(remainNumber >= 4)
                result.second += 4;
            if(remainNumber >= 5)
                result.first += 7;
            if(remainNumber >= 6)
                result.second -= 1;
            if(remainNumber >= 7)
                result.first -= 4;
            if(remainNumber >= 8)
                result.second += 7;
            if(remainNumber >= 9)
                result.first += 1;
            if(remainNumber >= 10)
                result.second -= 4;
            if(remainNumber >= 11)
                result.first -= 7;
        }

        else if(m % 9 == 5) {
            remainNumber = k % 12 - 1;

            if(remainNumber >= 0)
                result.second += 1;
            if(remainNumber >= 1)
                result.first += 5;
            if(remainNumber >= 2)
                result.second -= 7;
            if(remainNumber >= 3)
                result.first -= 8;
            if(remainNumber >= 4)
                result.second += 4;
            if(remainNumber >= 5)
                result.first += 2;
            if(remainNumber >= 6)
                result.second -= 1;
            if(remainNumber >= 7)
                result.first -= 5;
            if(remainNumber >= 8)
                result.second += 7;
            if(remainNumber >= 9)
                result.first += 8;
            if(remainNumber >= 10)
                result.second -= 4;
            if(remainNumber >= 11)
                result.first -= 2;
        }

        else if(m % 9 == 6) {
            result.second++;
            if(k > 1)
                result.first += 6;

            if(k > 2) {
                remainNumber = (k + 1) % 4;
                if(remainNumber >= 0)
                    result.second -= 9;
                if(remainNumber >= 1)
                    result.first -= 9;
                if(remainNumber >= 2)
                    result.second += 9;
                if(remainNumber >= 3)
                    result.first += 9;
            }
        }

        else if(m % 9 == 7) {
            remainNumber = k % 12 - 1;

            if(remainNumber >= 0)
                result.second += 1;
            if(remainNumber >= 1)
                result.first += 7;
            if(remainNumber >= 2)
                result.second -= 4;
            if(remainNumber >= 3)
                result.first -= 1;
            if(remainNumber >= 4)
                result.second += 7;
            if(remainNumber >= 5)
                result.first += 4;
            if(remainNumber >= 6)
                result.second -= 1;
            if(remainNumber >= 7)
                result.first -= 7;
            if(remainNumber >= 8)
                result.second += 4;
            if(remainNumber >= 9)
                result.first += 1;
            if(remainNumber >= 10)
                result.second -= 7;
            if(remainNumber >= 11)
                result.first -= 4;
        }

        else if(m % 9 == 8) {
            remainNumber = k % 4 - 1;

            if(remainNumber >= 0)
                result.second += 1;
            if(remainNumber >= 1)
                result.first += 8;
            if(remainNumber >= 2)
                result.second -= 1;
            if(remainNumber >= 3)
                result.first -= 8;
        }

        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}*/
