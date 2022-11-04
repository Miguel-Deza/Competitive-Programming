#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;



int minDistance(int dist[], bool shortest[], int N) 
{ 
	
	int min = INT_MAX;
  int index; 

	for (int i = 0; i < N; i++) {
    if (shortest[i] == false && dist[i] <= min){
      min = dist[i];
      index = i; 
    }
  }

	return index; 
} 



void dijkstra(int** graph, int exit, int N, int* dist) 
{
	bool shortest[N];             
	
	for (int i = 0; i < N; i++)   
  { 
    dist[i] = INT_MAX;
    shortest[i] = false; 
  }
	
	dist[exit] = 0;                

	for (int j = 0; j < N - 1; j++) 
  { 
		
		int u = minDistance(dist, shortest, N); 
		shortest[u] = true; 

		
		for (int v = 0; v < N; v++)   
    {
      
			if (!shortest[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
      } 
    }
	}

} 


int** Make2dArray(int width, int height)
{
    int** newMaze;
    newMaze = new int*[height];

    for(int i = 0; i < height; i++){
        newMaze[i] = new int[width];
    }

    return newMaze;
}


void display(int* otherDist, int V, int T)
{
  int numMice = 0;
  for (int i = 1; i < V; i++)
    {
      if (otherDist[i] <= T)
      {
        numMice++;
      }
    }
    cout << numMice;
}


void clear(int** g, int* d, int* od){
  delete [] g;
  delete [] d;
  delete [] od;
}

int main() 
{ 
  int tests, counter = 0;
  int N, E, T, M, numMice;
  int a, b, time;
  string x;
  
  cin >> tests;

  int** maze;             
  int* dist;              
  int* otherDist;         

  while(counter < tests)
  {
    getline(cin, x);		  
    cin >> N;             
    cin >> E;             
    cin >> T;             
    cin >> M;             

    N++;

    maze = Make2dArray(N, N);

    dist = new int[N];     
    otherDist = new int[N];

    
    for(int i = 0; i < M; i++)          
    {
      cin >> a >> b >> time;            
      maze[a][b] = time;                
    }

    for (int j = 0; j < N; j++)
    {
      otherDist[j] = INT_MAX;           
    }
    
    for (int r = 1; r < N; r++)         
    {
      dijkstra(maze, r, N, dist);       

      if (otherDist[r] > dist[E])       
      {
        otherDist[r] = dist[E];
      }
    }

    display(otherDist, N, T);
    clear(maze, dist, otherDist);

    if (counter != tests - 1)           
      cout << "\n\n";
    else
      cout << '\n';

    counter++;
  }
  return 0;