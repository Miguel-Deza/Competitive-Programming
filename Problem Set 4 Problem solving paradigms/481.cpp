#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int> &seq,
           const vector<int> &path,
           int pos)
{
    if (pos == -1)
        return;
    print(seq, path, path[pos]);
    cout << seq[pos] << endl;
}

int main()
{
    int n;
    vector<int> seq;
    while (cin >> n)
        seq.push_back(n);

    vector<int> L(seq.size());
    vector<int> L_id(seq.size());
    vector<int> path(seq.size());
    int lisEnd = 0, lisCount = 0;

    for (int i = 0; i < seq.size(); ++i)
    {

        size_t pos = lower_bound(L.begin(), L.begin() + lisCount, seq[i]) - L.begin();
        L[pos] = seq[i];
        L_id[pos] = i;

        path[i] = pos ? L_id[pos - 1] : -1;

        if (pos == lisCount)
        {
            ++lisCount;
            lisEnd = i;
        }
    }

    cout << lisCount << "\n-\n";
    print(seq, path, lisEnd);

    return 0;
}