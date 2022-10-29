#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000;

int arr[N];

int main()
{
    cin.sync_with_stdio(0);
    int n, q;

    vector<int> sums;
    int tc = 1;
    while (cin >> n && n)
    {
        //numeros participantes        
        sums.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        // generar sumas
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int sum = arr[i] + arr[j];
                sums.push_back(sum);
            }
        }

        cin >> q;
        cout << "Case " << tc++ << ":\n";
        for (int i = 0; i < q; i++)
        {
            int ans = 0;
            int num;
            cin >> num;

            // search closest
            int closest = 1e9;
            int dis = 1e9;
            for (int j = 0; j < sums.size(); j++)
            {
                if (abs(num - sums[j]) < dis)
                {
                    dis = abs(num - sums[j]);
                    closest = sums[j];
                }
            }

            cout << "Closest sum to " << num << " is " << closest << ".\n";
        }
    }
}