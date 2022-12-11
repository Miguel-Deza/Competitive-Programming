#include <cstdio>

int main()
{
	int T;
	while (scanf("%d", &T) != EOF) {
		int nr_answers = 5, nr_correct_answers = 0, a;
		do {
			scanf("%d", &a);
			if (a == T)
				nr_correct_answers++;
		} while (--nr_answers);
		printf("%d\n", nr_correct_answers);
	}
	return 0;
}