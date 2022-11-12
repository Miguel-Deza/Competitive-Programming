#include<iostream>

    #include<bits/stdc++.h>
    using namespace std;

       void dfs( vector<int> *edges , int start,int n,bool *visit ,stack<int> *nodex)
        {

          visit[start]  = true;
    

          for (int i = 0; i < edges[start].size(); ++i)
          {
                int next = edges[start][i];

                  if(visit[next] == false)
                   dfs(edges,next,n,visit,nodex);

          }

             nodex->push(start);
        }

     void dfs(vector<int> *edges,int start, bool *visit,int n)
    {
        visit[start] = true;

        for(int i=0;i<edges[start].size();i++)
        {
        int next = edges[start][i]; 
            if(visit[next]==false)
            dfs(edges,next,visit,n);
        }
    }

    int main()
    {
        int t;
        cin>>t;
      while(t--)
    {
           int n,m;
           cin>>n>>m;

           vector<int> *edges = new vector<int>[n+1];

                for (int i = 0; i < m; ++i)
                {
                    int start,end;
                     cin>>start>>end;

                     edges[start].push_back(end);  
                }

                

                  bool *visit = new bool[n+1];

                  for (int i = 0; i<=n; ++i)
                  {
                    visit[i] = false;
                  }


                stack<int> *nodex = new stack<int>();

                 for (int i = 1; i<=n; ++i)
                   {
                     if(visit[i]  == false)
                       dfs(edges,i,n,visit,nodex);
                   }
                

             for(int i=0;i<=n;i++)
              visit[i] = false;

                   int count=0;
                   while(!nodex->empty())
                        {
                       int up = nodex->top();
                        nodex->pop();
    
                            if(visit[up] ==false )
                            {
                                dfs(edges,up,visit,n);
                                count++;
                            }       
                    

                        }
                        cout<<count<<endl;

    }

        return 0;
    }