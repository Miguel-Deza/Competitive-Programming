#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n;

	while(cin>>n && n){

		int maximo=0;

		map <vector<int>, int> frosh;
		vector <int> arr(5);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5 ; j++)
			{
				cin>>arr[j];
			}

			sort(arr.begin(), arr.end());

			if(frosh.count(arr)==1){
				frosh[arr]++;
			}
			else{
				frosh[arr]=1;
			}

		}

		map<vector<int>, int>::iterator i;

		for (i = frosh.begin(); i != frosh.end(); ++i)
		{
			if((i->second)>maximo)
				maximo= i->second;
		}

		int cont=0;

		for (i = frosh.begin(); i != frosh.end(); ++i)
		{
			if((i->second)==maximo)
				cont++;
				
		}
		maximo= maximo*cont;
		

		cout<<maximo<<'\n';

		frosh.clear();

	}

	return 0;
}