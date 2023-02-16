#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, tmp;
    int nums[1010] = { 0 };
    cin >> n;
    while (n--) {
        cin >> tmp;
        nums[tmp]++;
    }
    cout << max_element(nums, nums + 1010) - nums << endl;
}
