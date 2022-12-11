#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;

    while(cin >> str)
    {
        int k = 0;
        int f = 1;
        int f2 = 1;
        int mi = 0;
        int len = str.length();
        string s = str;
        string str2 = str;
        reverse(str.begin(), str.end());
        if(str2.compare(str) == 0)
            f = 0;
        if(f==0)
        {
            for(int i=0;i<len;i++)
            {
                if(str[i]=='E' ||  str[i] == '3' || str[i]=='J' || str[i] == 'L'|| str[i]=='S'|| str[i]=='2' || str[i]=='Z'||str[i] =='5')
                {
                    mi = 2;
                    break;
                }
                else if(str[i] =='A'|| str[i] =='H' || str[i] =='I' || str[i] =='M' ||str[i] =='O'||str[i] =='T'||str[i] =='U' ||str[i] =='V' ||str[i] =='W'
                        ||str[i] =='X'|| str[i] =='Y' ||str[i] =='1'|| str[i] =='8')
                {
                    mi = 1;
                }
                else
                {
                    mi=3;
                    break;
                }
            }
            if(mi==2 || mi==3)
                cout << str2<< " -- is a regular palindrome."<<endl;
            else if(mi==1)
                cout << str2 << " -- is a mirrored palindrome."<<endl;
        }
        else
        {
            str = str2;
            for(int i=0;i<len;i++)
            {
                if(str2[i]=='E')
                    str2[i]='3';
                if(str2[i]=='J')
                    str2[i]='L';
                if(str2[i]=='S')
                    str2[i]='2';
                if(str2[i]=='Z')
                    str2[i]='5';
            }
            string str3;
            str3 = str2;
            reverse(str2.begin(), str2.end());
            if(str3.compare(str2) == 0)
            {
                 f2 = 0;
                 cout << s << " -- is a mirrored string."<< endl;
            }
            else
            {
                for(int i=0;i<len;i++)
                {
                    if(str[i]=='3')
                        str[i]='E';
                    if(str[i]=='L')
                        str[i]='J';
                    if(str[i]=='2')
                        str[i]='S';
                    if(str[i]=='5')
                        str[i]='Z';
                }
                string str4;
                str4 = str;
                reverse(str.begin(), str.end());
                if(str4.compare(str) == 0)
                {
                    f2 = 0;
                    cout << s << " -- is a mirrored string."<< endl;
                }
            }
            if(f == 1 &f2 == 1)
            {
                cout << s << " -- is not a palindrome."<< endl;
            }
        }
        cout << endl;
    }
}