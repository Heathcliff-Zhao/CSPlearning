#include <iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int n, tmp;
    cin >> n;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        heights.push_back(tmp);
    }

    if (n == 1)
        return heights[0];
    int res = 0;
    stack<int>stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && heights[stk.top()] > heights[i]) {
            int popheight = heights[stk.top()];
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            res = max(res, popheight * width);
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        int popheight = heights[stk.top()];
        stk.pop();
        int width = stk.empty() ? n : n - stk.top() - 1;
        res = max(res, popheight * width);
    }
    cout << res << endl;
}