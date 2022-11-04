#include<bits/stdc++.h>
using namespace std;
int N;
char a, b, c;
bool f=false;
string line;
stringstream ss;
vector<char> elements;
vector<char>graph[5005];
map<char, bool> m;
bool check(char e)
{
    for(int i = 0; i < graph[e].size(); i++)
        if(m[graph[e][i]])
            return false;
    return true;
}

void backtracking(string path)
{
    if(path.length() == elements.size())
    {
        printf("%c", path[0]);
        for(int i = 1; i < path.length(); i++)
            printf(" %c", path[i]);
        printf("\n");
        f=true;

        return;
    }
    for(int i = 0; i < elements.size(); i++)
    {
        char ch=elements[i];
        if(m[ch]==false)
        {
            if(check(ch))
            {
                m[ch] = true;
                backtracking(path + ch);
                m[ch] = false;
            }
        }
    }
}
void sob_clear()
{
    ss.clear();
    elements.clear();
    for(char ch='A'; ch<='Z'; ch++)
    {
        graph[ch].clear();
    }
    m.clear();
    f=false;
}
int main()
{
    scanf("%d\n\n", &N);
    int t=0;
    while(1){
        if(t> 0) printf("\n");
        sob_clear();
        getline(cin, line);
        ss.str(line);
        while(ss >> a)
            elements.push_back(a);
        sort(elements.begin(), elements.end());
        getline(cin, line);
        ss.clear();
        ss.str(line);
        while(ss >> a >> b >> c)
            graph[a].push_back(c);

        backtracking("");
        if(f==false)
            printf("NO\n");
        if(!getline(cin, line)) break;
        t++;
    }
    return 0;
}