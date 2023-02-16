#include <iostream>
using namespace std;

bool visited[52][52];
bool visitedcpy[52][52];
char graph[52][52];
int r, c;

struct direction
{
    int dr, dc;
}directions[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool legal(int nowr, int nowc) {
    if (nowr >= 0 && nowc >= 0 && nowr < r && nowc < c && !visited[nowr][nowc] && graph[nowr][nowc] != '#')
        return true;
    return false;
}

void dfs(int nowr, int nowc) {
    int nextr, nextc;
    visited[nowr][nowc] = 1;
    if (graph[nowr][nowc] == '+' || graph[nowr][nowc] == 'S' || graph[nowr][nowc] == 'T') {
        for (int i = 0; i < 4; i++) {
            nextr = nowr + directions[i].dr;
            nextc = nowc + directions[i].dc;
            if (legal(nextr, nextc))
                dfs(nextr, nextc);
        }
    }
    else if (graph[nowr][nowc] == '-') {
        for (int i = 2; i < 4; i++) {
            nextr = nowr + directions[i].dr;
            nextc = nowc + directions[i].dc;
            if (legal(nextr, nextc))
                dfs(nextr, nextc);
        }
    }
    else if (graph[nowr][nowc] == '|') {
        for (int i = 0; i < 2; i++) {
            nextr = nowr + directions[i].dr;
            nextc = nowc + directions[i].dc;
            if (legal(nextr, nextc))
                dfs(nextr, nextc);
        }
    }
    else if (graph[nowr][nowc] == '.') {
        nextr = nowr + directions[1].dr;
        nextc = nowc + directions[1].dc;
        if (legal(nextr, nextc))
            dfs(nextr, nextc);
    }
}

int main()
{
    cin >> r >> c;
    int sr, sc, tr, tc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (graph[i][j] == 'T') {
                tr = i;
                tc = j;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    dfs(sr, sc);
    memcpy(visitedcpy, visited, sizeof(visited));
    if (visitedcpy[tr][tc]) {
        int count = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (visitedcpy[i][j]) {
                    memset(visited, 0, sizeof(visited));
                    dfs(i, j);
                    if (!visited[tr][tc])
                        count++;
                }
            }
        cout << count << endl;
    }
    else
        cout << "I'm stuck!" << endl;
    return 0;
}
