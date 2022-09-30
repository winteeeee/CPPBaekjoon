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

        long long cycleNumber = k / 4;
        long long remainNumber = k % 4;
        if(m % 9 == 0) {
            if(remainNumber == 1)
                result.second= 1;
            else if(remainNumber == 2) {
                result.first = 1;
                result.second = 1;
            }
            else if(remainNumber == 3)
                result.first = 1;
        }

        else if(m % 9 == 1) {

        }

        else if(m % 9 == 2) {

        }

        else if(m % 9 == 3) {

        }

        else if(m % 9 == 4) {

        }

        else if(m % 9 == 5) {

        }

        else if(m % 9 == 6) {

        }

        else if(m % 9 == 7) {

        }

        else if(m % 9 == 8) {

        }

        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}

/*
 * forward 값의 규칙
 * m % 9값 - 나타나는 forward 값의 규칙
 * 1 - 1반복
 * 2 - 1 2 4 8 7 5 반복
 * 3 - 1 3 이후 9반복
 * 4 - 1 4 7 반복
 * 5 - 1 5 7 8 4 2 반복
 * 6 - 1 6 이후 9반복
 * 7 - 1 7 4 반복
 * 8 - 1 8
 * 9 - 1 이후 9반복
 */