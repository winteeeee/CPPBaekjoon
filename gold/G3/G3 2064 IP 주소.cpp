#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int n, maskIdx;
string networkAddress, networkMask;
bitset<32> arr[1001];

void input();
void extractMaskIdx();
void extractNetworkAddress();
void extractNetworkMask();
void printBitset(const string& str);
int main() {
    /*
     * [풀이]
     * 비트 수준의 연산을 통해 네트워크 마스크가 시작되는 부분의 인덱스를 구한 후 적절히 출력한다.
     * 이미 알고 있는 CS 지식을 기반으로 하는 도메인이라서 문제 해결 자체는 어렵지 않았음.
     * 비트 수준의 연산을 요구하므로 해당 부분만 실수 없이 구현해주면 됐다.
     */

    input();
    extractMaskIdx();
    extractNetworkAddress();
    extractNetworkMask();
    printBitset(networkAddress);
    printBitset(networkMask);

    return 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ip;
        cin >> ip;

        string address;
        for (int j = 0; ip[j] != '\0'; ) {
            string partOfAddress;
            while (true) {
                partOfAddress += ip[j++];

                if (ip[j] == '.') {
                    j++;
                    break;
                } else if (ip[j] == '\0') {
                    break;
                }
            }

            bitset<8> partOfAddressBitset(stoi(partOfAddress));
            address += partOfAddressBitset.to_string();
        }

        arr[i] = bitset<32>(address);
    }
}

void extractMaskIdx() {
    for (; maskIdx < 32; maskIdx++) {
        bool find = false;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i].to_string()[maskIdx] != arr[i + 1].to_string()[maskIdx]) {
                find = true;
                break;
            }
        }

        if (find) {
            break;
        }
    }
}

void extractNetworkAddress() {
    networkAddress = arr[0].to_string().substr(0, maskIdx);

    for (int i = maskIdx; i < 32; i++) {
        networkAddress += "0";
    }
}

void extractNetworkMask() {
    for (int i = 0; i < maskIdx; i++) {
        networkMask += "1";
    }

    for (int i = maskIdx; i < 32; i++) {
        networkMask += "0";
    }
}

void printBitset(const string& str) {
    for (int i = 0; i < 4; i++) {
        cout << bitset<8>(str.substr(8 * i, 8)).to_ulong();

        if (i != 3) {
            cout << '.';
        }
    }
    cout << '\n';
}