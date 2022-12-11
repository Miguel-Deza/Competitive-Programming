#include <bits/stdc++.h>

using namespace std;

long long reverse(long long num)
{
	long long rev = 0;

	while(num != 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}

	return rev;
}

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n;

	scanf("%d", &n);

	for(int t=0; t<n; t++)
	{
		long long num;

		scanf("%lld", &num);

		long long rev = reverse(num);
		int cnt = 0;

		do
		{
			num += rev;
			rev = reverse(num);
			cnt++;
		} while(rev != num);

		printf("%d %lld\n", cnt, num);
	}
	return 0;
}