/*
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> stone;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int left = 0;
    int right = 0;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        stone.push_back(temp);
    }

    left += stone[0];
    right += stone[1];

    for(int i = 2; i < n; i++) {
       if(left == right) 
           left += stone[i];
       else {
           if(left > right) 
               right += stone[i];
           else 
               left += stone[i];
       }
    }
    
    int count = 0;
    while(left != right) {
        if(left > right) {
            if(abs(left - right) > 100) {
                right += 100;
                count++;
            }
            
            else if(50 <= abs(left - right) && abs(left - right) < 100) {
                right += 50;
                count++;
            }

            else if(20 <= abs(left - right) && abs(left - right) < 50) {
                right += 20;
                count++;
            }

            else if(10 <= abs(left - right) && abs(left - right) < 20) {
                right += 10;
                count++;
            }

            else if(5 <= abs(left - right) && abs(left - right) < 10) {
                right += 5;
                count++;
            }

            else if(2 <= abs(left - right) && abs(left - right) < 5) {
                right += 2;
                count++;
            }

            else if(1 <= abs(left - right) && abs(left - right) < 2) {
                right += 1;
                count++;
            }
        }
        
        else {
            if(abs(left - right) > 100) {
                left += 100;
                count++;
            }

            else if(50 <= abs(left - right) && abs(left - right) < 100) {
                left += 50;
                count++;
            }

            else if(20 <= abs(left - right) && abs(left - right) < 50) {
                left += 20;
                count++;
            }

            else if(10 <= abs(left - right) && abs(left - right) < 20) {
                left += 10;
                count++;
            }

            else if(5 <= abs(left - right) && abs(left - right) < 10) {
                left += 5;
                count++;
            }

            else if(2 <= abs(left - right) && abs(left - right) < 5) {
                left += 2;
                count++;
            }

            else if(1 <= abs(left - right) && abs(left - right) < 2) {
                left += 1;
                count++;
            }
        }
    }

    cout << count;
    return 0;
}
*/
