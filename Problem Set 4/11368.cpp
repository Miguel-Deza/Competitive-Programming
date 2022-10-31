#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<pair<int,int>> dolls;
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            dolls.push_back({a,b});
        }
        sort(dolls.begin(),dolls.end(),[](pair<int,int>&a,pair<int,int>&b){
             
             if(a.first==b.first) return a.second > b.second;
             return a.first < b.first;
             });
        
        
        
        deque<int> nestedY;
        for(int i=0;i<n;i++){
            int pos = lower_bound(nestedY.begin(),nestedY.end(),dolls[i].second) - nestedY.begin();
            
            if(pos == 0){
                nestedY.push_front(dolls[i].second);
            } else {
                nestedY[pos-1] = dolls[i].second;
            }
        }
        printf("%d\n",nestedY.size());
    }
}