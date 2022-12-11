#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
map<string, int> S;
multimap<string, string> x;
string to_standard(string a){
	for (int i = 0; i < a.length(); i++){
		if (isalpha(a[i])) a[i] = tolower(a[i]);
		else a[i] = ' ';
	}
	return a;
}
int main(){
	string s;
	while (cin >> s){
		string data_s=s;
		if (s[0] == '#')
			break;
		s = to_standard(s);
		sort(s.begin(),s.end());
		x.insert(multimap<string, string>::value_type(s, data_s));
		if (!S.count(s)) S[s] = 1;
		else			 S[s] = 0;
	}
	for (map<string, int>::iterator it = S.begin(); it != S.end(); it++) {
		multimap<string, string>::iterator z;
		if ((it->second) == 0) {
			while (1) {
				z = x.find(it->first);
				if (z != x.end())
					x.erase(z);
				else break;
			}
		}
	}
	vector<string> ans;
	for (multimap<string, string>::iterator it = x.begin(); it != x.end(); it++) {
		ans.push_back(it->second);
		//cout << (it->second) << endl;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	//system("PAUSE");
	return 0;
}