// packdel.cpp

#include <iostream>
#include <queue>		// p_q
#include <vector>		// vector
#include <utility>		// pair
#include <functional>	// greater
#define pii pair<int,int>
#define infinity 20000000
using namespace std;
int verts, edges, dist[50011];
bool visited[50011];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[50011];

int main()
{
	cin >> verts >> edges;

	// stores neighbor verts as pairs ( cost,neighbor )
	for (int i = 0; i < edges; i++) {	
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });	
		adj[b].push_back({ c,a });	
	}

	// sets all dist values to infinity except starting
	for (int i = 1; i <= verts; i++) {	
		if (i == 1) {
			dist[i] = 0;
			continue;
		}
		dist[i] = infinity;
	}

	pq.push({ 0,1 });

	while (pq.size() != 0) {
		int nextVert = pq.top().second;

		// gets rid of already visited pairs in pq
		if (visited[nextVert]) {
			pq.pop();
			continue;
		}

		int cost = pq.top().first;

		// updates distances
		if (cost < dist[nextVert]) {
			dist[nextVert] = cost;
		}

		// terminate if end is reached, output cost
		if (nextVert == verts) {
			cout << dist[nextVert] << endl;
			return 0;
		}

		int vecSize = adj[nextVert].size();
		pq.pop();

		// adds neighbor pairs to pq
		for (int i = 0; i < vecSize; i++) {
			if (!visited[adj[nextVert][i].second]) {
				if (adj[nextVert][i].first + dist[nextVert] < dist[adj[nextVert][i].second]) {
					pq.push({ adj[nextVert][i].first + dist[nextVert],adj[nextVert][i].second });
				}
			}
		}

		visited[nextVert] = true;
	}

	return 0;
}