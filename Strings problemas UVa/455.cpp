#include <iostream>
#include <cstring>
using namespace std;

int kmp(string s){
	int i, j;
	int t[1600];
	t[0] = -1;
	i = 1;
	j = -1;

	while (i < s.length()){
		while (j >= 0 and s[j+1] != s[i])	j = t[j];
		if (s[j+1] == s[i])	++j;
		t[i] = j;
		++i;
	}
	if (s.length() % (s.length() - j - 1))
		return s.length();
	return s.length() - j - 1;
}

int main(){
	int n;
	cin >> n;

	while (n--){
		string s;
		cin >> s;
		cout << kmp(s) << endl;
		if (n)	cout << endl;
	}
	return 0;
}