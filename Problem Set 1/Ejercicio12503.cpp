#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int stringtoint(const string &str)
{
    int numStr = 0;
    for (int i = 0; i < str.length(); i++)
    {
        numStr *= 10;
        numStr += str[i] - '0';
    }
    return numStr;
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    cin.ignore(1, '\n');

    while (T--)
    {
        int p = 0;

        int n;
        cin >> n;
        cin.ignore(1, '\n');
        vector<string> history;

        while (n--)
        {
            string cmd;
            getline(cin, cmd);

            if (cmd.substr(0, 7) == "SAME AS")
            {
                cmd = cmd.substr(8);
                int line = stringtoint(cmd);
                cmd = history[line - 1];
            }
            history.push_back(cmd);

            if (cmd == "LEFT")
            {
                --p;
            }
            else if (cmd == "RIGHT")
            {
                ++p;
            }
        }
        cout << p << endl;
    }

    return 0;
}