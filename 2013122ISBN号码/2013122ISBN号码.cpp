#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    string isbn;
    cin >> isbn;
    int pos = 1, sum = 0;
    for (int i = 0; i < isbn.length()-2; i++) {
        if (isdigit(isbn[i])) {
            sum += (isbn[i] - 48) * pos;
            pos++;
        }
    }
    if (sum % 11 == isbn[12] - 48)
        cout << "Right" << endl;
    else {
        isbn[12] = char(sum % 11 + 48);
        cout << isbn << endl;
    }
}
