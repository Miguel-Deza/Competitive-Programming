#include <iostream>
#include <memory.h>
using namespace std;
bool freq[3001];
int main()
{
    int n, arr[3000];
    while (cin >> n){
    memset(freq, 0, 3001);

    cin >> arr[0];
    bool cond = true;
    for (int i=1; i<n; i++)
    {
        cin >> arr[i];
        freq[abs(arr[i-1]-arr[i])] = true;
    }
    for (int i=1; i<n; i++)
    {
        if (freq[i] == 0)
        {
            cond = false;
            break;
        }
    }
    if (cond == true && n>0)
       cout << "Jolly" << endl;
    else if (cond == false && n>0)
    {
        cout << "Not jolly" << endl;
    }
    n = 0;
    }
    return 0;
}