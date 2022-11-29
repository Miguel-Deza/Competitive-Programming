#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<queue>

using namespace std;

int edges[200][200];
int nodes;

bool bfs(int source, int destination, int parent[]){
	
	queue <int> qBfs;
	bool visited[nodes + 10]; 
    memset(visited, 0, sizeof(visited));
    
	qBfs.push(source);
    visited[source] = true;
    parent[source] = -1;
  
    while (!qBfs.empty()){
        int frontNode = qBfs.front();
        qBfs.pop();

		if(frontNode == destination) break;

        for (int i=1; i<=nodes; i++)
        {
            if (visited[i]==false && edges[frontNode][i] > 0)
            {
                qBfs.push(i);
                parent[i] = frontNode;
                visited[i] = true;
            }
        }
    }

    return visited[destination];
}

int maxFlow(int source, int destination){

	int parent[nodes + 10];

    int max_flow = 0;

    while (bfs(source, destination, parent)){
        int path_flow = INT_MAX;
        for (int i=destination; i!=source; i=parent[i])
        {
            int curr = parent[i];
            path_flow = min(path_flow, edges[curr][i]);
        }

        for (int i=destination; i!=source; i=parent[i])
        {
            int curr = parent[i];
            edges[curr][i] -= path_flow;
            edges[i][curr] += path_flow;
        }
		
        max_flow += path_flow;
    }

    return max_flow;
}

int main(){
	
	int source, destination, networks;
	int countNetwork = 1;	
	
	while(true){
		
		scanf("%d",&nodes);
		
		if(nodes == 0) break;
		
		memset(edges,0,sizeof(edges));
		
		scanf("%d %d %d",&source, &destination, &networks);
		
		for(int i=0; i<networks; i++){
			
			int node1, node2, bandwidth;
			
			scanf("%d %d %d",&node1, &node2, &bandwidth);
			
			edges[node1][node2] += bandwidth;
			edges[node2][node1] += bandwidth;
		}
		
		printf("Network %d\n",countNetwork);
		printf("The bandwidth is %d.\n\n",maxFlow(source,destination));
		
		countNetwork++;
	}
	
	return 0;
}