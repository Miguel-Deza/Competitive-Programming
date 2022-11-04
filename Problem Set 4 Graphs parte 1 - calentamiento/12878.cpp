#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define MAX_TRAIL_LENGTH 20000000	
#define MAX_NUM_OF_POINTS 10000

typedef struct Edge_t {		
	int to;		
	int weight;	
} Edge;

vector<int> arranged(MAX_NUM_OF_POINTS);


void dijkstra(vector<vector<Edge>>* graph, vector<int>* min_dists) {
	vector<int> unscanned(arranged.begin(), arranged.begin() + graph->size());
	int point;	
	int index;	
	while (!unscanned.empty()) {
		index = 0;
		point = unscanned[0];
		
		for (int i = 0; i < (int) unscanned.size(); i++) {
			if ((*min_dists)[unscanned[i]] < (*min_dists)[point]) {
				index = i;
				point = unscanned[i];
			}
		}
		unscanned.erase(unscanned.begin() + index);
		Edge* iter = NULL;
		
		for (int i = 0; i < (int) (*graph)[point].size(); i++) {
			iter = &(*graph)[point][i];
			if ((*min_dists)[iter->to] > (*min_dists)[point] + iter->weight) {
				(*min_dists)[iter->to] = (*min_dists)[point] + iter->weight;
			}
		}
	}
}




void solve(int P, int T) {
	vector<vector<Edge>> graph(P);	
	int point1, point2, weight;	
	Edge temp;
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &point1, &point2, &weight);	
		if (point1 == point2) {
			continue;	
		}
		
		temp.weight = weight;
		temp.to = point2;
		graph[point1].push_back(temp);
		temp.to = point1;
		graph[point2].push_back(temp);
	}
	
	vector<int> min_dist_from_start(P, MAX_TRAIL_LENGTH);
	min_dist_from_start[0] = 0;
	vector<int> min_dist_from_end(P, MAX_TRAIL_LENGTH);
	min_dist_from_end[P - 1] = 0;
	
	dijkstra(&graph, &min_dist_from_start);
	int dist_start_to_end = min_dist_from_start[P - 1];
	
	dijkstra(&graph, &min_dist_from_end);
	int sum = 0;	
	
	for (int i = 0; i < (int) graph.size(); i++) {
		for (int j = 0; j < (int) graph[i].size(); j++) {
			
			
			if (min_dist_from_start[i] + graph[i][j].weight
					+ min_dist_from_end[graph[i][j].to] == dist_start_to_end) {
				sum += graph[i][j].weight;
			}
		}
	}
	printf("%d\n", 2 * sum);	
}

int main() {
	
	
	for (int i = 0; i < (int) arranged.size(); i++) {
		arranged[i] = i;
	}
	int P;	
	int T;	
	while (scanf("%d %d", &P, &T) != EOF) {
		solve(P, T);
	}
	return 0;
}