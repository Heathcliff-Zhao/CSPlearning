#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    bool option;
    string pat;
    cin >> pat >> option;
    int nums;
    cin >> nums;
    string cop[105];
    for (int i = 0; i < nums; i++)
        cin >> cop[i];
    for (int i = 0; i < nums; i++) {
        if (!option) {
            transform(cop[i].begin(), cop[i].end(), cop[i].begin(), ::tolower);
            transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
        }
        if (cop[i].find(pat) == string::npos)
            continue;
        cout << cop[i] << endl;
    }
}
