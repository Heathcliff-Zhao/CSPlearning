#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<map>

using namespace std;

const int N = 256;
char spliter[] = " ";

void split(vector<string>& strvec, char* str, char* spliter) {
    char* seg;
    seg = strtok(str, spliter);
    while (seg) {
        strvec.push_back(seg);
        seg = strtok(NULL, spliter);
    }
}

void getcmd(char* oricmd) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        *oricmd++ = c;
    *oricmd = '\0';
}

int main()
{
    string config;
    char origincmd[N + 1];
    int n;
    cin >> config >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        vector<string> strvector;
        map<string, string> cmd;
        getcmd(origincmd);
        split(strvector, origincmd, spliter);
        for (int j = 1; j < (int)strvector.size(); j++) {
            if (strvector[j].size() == 2 && strvector[j][0] == '-') {
                int pos = config.find(strvector[j][1]);
                if (pos == -1)
                    break;
                if (cmd.find(strvector[j]) == cmd.end())
                    cmd[strvector[j]] = "";
                if (config[pos + 1] == ':' && j + 1 < (int)strvector.size()) {
                    cmd[strvector[j]] = strvector[j + 1];
                    j++;
                }
            }
            else
                break;
        }
        cout << "Case " << i << ":";
        for (map<string, string>::iterator it = cmd.begin(); it != cmd.end(); it++) {
            cout << " " << it->first;
            if (it->second != "")
                cout << " " << it->second;
        }
        cout << endl;
    }
}
