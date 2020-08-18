#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long answer = 0;
    string s;
    cin >> s;
    map<int, int> m;
    m[0] = 1;
    int x = 0;
    for (auto& c : s) {
        int d = c - 'A'; // For A-Z
        x ^= 1 << d;
        answer += m[x];
        for (int i = 0; i < 26; ++i) {
            answer += m[x ^ (1 << i)];
        }
        m[x] += 1;
    }
    cout << answer << endl;
    return 0;
}
