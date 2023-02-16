#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int nums[501];
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    for (int i = 0; nums[i] < 0; i++) {
        for (int j = n - 1; nums[j] > 0; j--) {
            if (nums[i] + nums[j] == 0)
                cnt++;
        }
    }
    cout << cnt << endl;
}