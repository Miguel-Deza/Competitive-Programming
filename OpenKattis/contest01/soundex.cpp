#include<cstdio>
char convert(char c){
	switch (c)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		return '1';
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		return '2';
	case 'D':
	case 'T':
		return '3';
	case 'L':
		return '4';
	case 'M':
	case 'N':
		return '5';
	case 'R':
		return '6';
	default:
		return NULL;
	}
}
int main(){
	char S[1000];
	while (scanf("%s", S) == 1){
		char pre = -1;
		for (int i = 0; S[i] != '\0'; i++){
			char c = convert(S[i]);
			if (pre == c)
				continue;
			if (c != NULL)
				printf("%c", c);
			pre = c;
		}
		putchar('\n');
	}
	return 0;
}