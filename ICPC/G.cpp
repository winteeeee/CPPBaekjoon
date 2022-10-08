/*
#include <iostream>
#include <algorithm>
using namespace std;

int jar[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> jar[0] >> jar[1] >> jar[2];

    int F = 0;
    int S = 0;

    int k = 1;
    bool isF = true;
    while(!(jar[0] == 0 && jar[1] == 0 && jar[2] == 0)) {
        sort(jar, jar + 3);

        if(jar[2] - k > k + 1) {
            if(jar[1] - k > k + 1) {
                if(isF) {
                    F += k;
                    isF = false;
                }
                else {
                    S += k;
                    isF = true;
                }
                jar[0] -= k;
            }

            else {
                if(isF) {
                    F += k;
                    isF = false;
                }
                else {
                    S += k;
                    isF = true;
                }
                jar[1] -= k;
            }
        }

        else {
            if(isF) {
                F += k;
                isF = false;
            }
            else {
                S += k;
                isF = true;
            }
            jar[2] -= k;
        }
        k++;
    }

    if(F == S)
        cout << "D";
    else if(F > S)
        cout << "F";
    else
        cout << "S";

    return 0;
}

*/
/*
 * 두 명의 플레이어가 한 번에 한 명씩 교대로 진행합니다.
매 턴마다 플레이어는 항아리를 선택하고 항아리에서 몇 개의 자갈을 가져옵니다.
F가 먼저 시작되고 S가 다음에 시작됩니다. 이 턴은 게임이 끝날 때까지 번갈아 가며 합니다.
k번째 턴에서 뽑을 수 있는 조약돌의 수는 k입니다. 첫 번째 턴에서 F가 가져간 조약돌의 수는 1입니다.
따라서 다음 턴에서 S는 2개의 조약돌을 취하고 세 번째 턴에서 F는 3개의 조약돌을 가져갑니다.
매 차례마다 한 항아리에서 자갈을 꺼내야 합니다.
k번째 턴에서 선택한 항아리에 남아 있는 자갈의 수가 k보다 적으면 플레이어는 그 항아리에 남아 있는 모든 자갈을 가져와야 합니다.
남은 자갈이 선택한 항아리에 k보다 크면 플레이어는 항아리에서 k보다 적은 자갈을 가져갈 수 없습니다.
세 개의 항아리에 자갈이 남아 있지 않으면 게임이 종료됩니다. 더 많은 조약돌을 가지고 있는 플레이어가 게임이 끝나면 게임에서 이깁니다.
따라서 어떤 경우에는 두 플레이어가 가져온 조약돌의 수가 같으면 무승부가 가능할 수도 있습니다.
우리는 두 명의 플레이어 F와 S가 승리하기 위해 최선을 다한다고 가정합니다.
두 명의 플레이어는 항상 세 개의 항아리에 남아 있는 자갈의 정확한 수를 알고 있습니다. 이 항아리 게임에는 숨겨진 정보가 없습니다.
세 개의 병에 들어 있는 자갈의 개수가 주어졌을 때 승자가 누구인지 또는 무승부가 가능한지를 찾는 프로그램을 작성하십시오.

입력은 첫 시작 시 항아리에 들어가 있는 자갈을 나타내는 a b c가 주어짐
F S D 출력
 */
