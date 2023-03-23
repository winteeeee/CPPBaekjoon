    /*
    #include <iostream>
    #include <vector>
    #include <stack>
    using namespace std;

    int n;
    long long result;
    vector<int> arr;

    class human {
    public:
        int height;
        int num;
    };

    void input() {
        cin >> n;

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
    }

    void solve() {
        stack<human> s;

        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push({arr[i], 1});
            } else {
                for (human top = s.top(); !s.empty() && top.height < arr[i];) {
                    result += (s.top().num);
                    s.pop();

                    if (!s.empty()) {
                        top = s.top();
                    }
                }

                if (!s.empty() && s.top().height == arr[i]) {
                    result += s.top().num;
                    s.top().num++;
                } else {
                    s.push({arr[i], 1});
                }

                if (!(s.empty() || s.size() == 1)) {
                    result++;
                }
            }
        }

        cout << result;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        input();
        solve();

        return 0;
    }*/
