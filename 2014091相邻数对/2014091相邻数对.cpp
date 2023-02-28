#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n < 2)
        cout << 0 << endl;
    int nums[1005];
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);
    int l = 0, r = 1;
    int cnt = 0;
    while (r != n) {
        if (nums[r] - nums[l] == 1) {
            cnt++;
        }
        l++;
        r++;
    }
    cout << cnt << endl;
}

