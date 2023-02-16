#include <iostream>
using namespace std;

struct window {
    int id;
    int left, bottom, right, top;
}windows[12 * 2];

struct click {
    int x, y;
}clicks[12];

int main()
{
    int n, m;
    cin >> n >> m;
    int movecnt = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        windows[i].id = i + 1;
        cin >> windows[i].left >> windows[i].bottom >> windows[i].right >> windows[i].top;
    }
    for (int i = 0; i < m; i++) {
        cin >> clicks[i].x >> clicks[i].y;
    }
    for (int i = 0; i < m; i++) {
        flag = true;
        for (int j = n + movecnt - 1; j > -1; j--) {
            if (clicks[i].x <= windows[j].right && clicks[i].x >= windows[j].left && clicks[i].y <= windows[j].top && clicks[i].y >= windows[j].bottom) {
                cout << windows[j].id << endl;
                windows[n + movecnt] = windows[j];
                windows[j].bottom = windows[j].top + 1;
                movecnt++;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "IGNORED" << endl;
    }
}