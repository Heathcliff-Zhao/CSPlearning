#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 200;

struct {
    long long x, y;
} route[MAXN + 1];

struct status {
    long long x, y;
    int step, cnt;
};

bool visited[MAXN + 1];
int dfs(int n, int m, int k, int begin, int end, long long r) {
    int max;
    memset(visited, false, sizeof(visited));
    status start, front, v;
    start.x = route[begin].x;
    start.y = route[begin].y;
    start.step = 0;
    start.cnt = 0;
    queue<status> q;
    q.push(start);
    visited[begin] = true;
    while (!q.empty()) {
        front = q.front();
        q.pop();

        if (front.x == route[end].x && front.y == route[end].y)
            return front.step - 1;
        if (front.cnt == k)
            max = n;
        else
            max = n + m;
        for (int i = 0; i < max; i++) {
            if (visited[i])
                continue;
            if ((front.x - route[i].x) * (front.x - route[i].x) + (front.y - route[i].y) * (front.y - route[i].y) > r)
                continue;
            else {
                visited[i] = true;
                v.x = route[i].x;
                v.y = route[i].y;
                v.step = front.step + 1;
                if (i >= n)
                    v.cnt = front.cnt + 1;
                else
                    v.cnt = front.cnt;
                q.push(v);
            }
        }
    }
    return 0;
}

int main() {
    int n, m, k;
    long long r;
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n + m; i++)
        cin >> route[i].x >> route[i].y;
    cout << dfs(n, m, k, 0, 1, r * r) << endl;
}