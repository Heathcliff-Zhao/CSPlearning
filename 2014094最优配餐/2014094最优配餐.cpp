#include <iostream>
using namespace std;

int map[1005][1005];

int main()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < m; i++) {
        int xi, yi;
        cin >> xi >> yi;
        map[xi][yi] = 2;
    }
    for (int i = 0; i < n; i++) {
        int xi, yi, ci;
        cin >> xi >> yi >> ci;

    }
}
