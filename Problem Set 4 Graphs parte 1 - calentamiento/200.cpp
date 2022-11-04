#include "stdlib.h"
#include <string>
#include <iostream>
using namespace std;
void CheckMatrix(bool matriY[26][26]);
void CheckList(int list[]);


int main(){
	bool matrix[26][26] = { { 0 } };
	int list[26] , nodes = 0;
	for (int i = 0; i < 26; i++) list[i] = -1;
	string previous, current;
	
	cin >> previous;

	while (cin >> current && current != "#"){
		int maxlength = (previous.length()>current.length() ? current.length() : previous.length());
		for (int i = 0; i < maxlength; i++)
			if (previous[i] != current[i]){ matrix[previous[i] - 65][current[i] - 65] = true; break; }
		previous = current;
	}

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (matrix[i][j]){
				if (list[i] == -1){ list[i] = 0; nodes++; }
				if (list[j] == -1){ list[j] = 0; nodes++; }
				list[j]++;
			}

	while (nodes > 0){
		char avatar='A';
		for (int i = 0; i < 26; i++)
			if (list[i] == 0){
				avatar += i;
				cout << avatar;
				list[i] = -1;
				nodes--;
				for (int j = 0; j < 26; j++)
					if (matrix[i][j]) list[j]--;
				break;
			}
	}
	system("PAUSE");
	return 0;
}