#include <iostream>
using namespace std;
const long long Mod = 1000000007;
long long status[1001][1001];
int main()
{
    int n;
    cin >> n;
    memset(status, 0, sizeof(status));
    status[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        status[i][0] = 1;
        status[i][1] = (status[i - 1][1] * 2 + status[i - 1][0]) % Mod;
        status[i][2] = (status[i - 1][2] + status[i - 1][0]) % Mod;
        status[i][3] = (status[i - 1][3] * 2 + status[i - 1][1]) % Mod;
        status[i][4] = (status[i - 1][4] * 2 + status[i - 1][1] + status[i - 1][2]) % Mod;
        status[i][5] = (status[i - 1][5] * 2 + status[i - 1][3] + status[i - 1][4]) % Mod;
    }
    cout << status[n][5] << endl;
}
