#include <cstdio>


int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
        puts((n % 6 ? "N" : "Y"));
    return 0;
}