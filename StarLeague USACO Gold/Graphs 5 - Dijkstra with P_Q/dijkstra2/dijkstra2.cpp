// dijkstra's algorithm using priority queues

#include <iostream>
#include <queue>		// p_q
#include <vector>		// vector
#include <utility>		// pair
#include <functional>	// greater
#define pii pair<int,int>
using namespace std;
int verts, edges, start, dist[50001];
bool visited[50001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[50001];

int main()
{
	cin >> verts >> edges >> start;

	for (int i = 0; i < edges; i++) {	// stores neighbor verts as pairs ( cost, neighbor )
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}

	for (int i = 1; i <= verts; i++) {	// sets all dist values to 20000000 except starting 
		if (i == start) {
			dist[i] = 0;
			continue;
		}
		dist[i] = 20000000;
	}

	pq.push({ 0,start });

	while (pq.size() != 0) {
		int nextVert = pq.top().second;
		if (visited[nextVert]) {
			pq.pop();
			continue;
		}
		int cost = pq.top().first;
		if (cost < dist[nextVert]) {
			dist[nextVert] = cost;
		}
		int vecSize = adj[nextVert].size();
		pq.pop();
		for (int i = 0; i < vecSize; i++) {	// adds neighbors from adj list
			if (!visited[adj[nextVert][i].second]) {
				if (adj[nextVert][i].first + dist[nextVert] < dist[adj[nextVert][i].second]) { // if sum of dists is better than before, add vert
					pq.push({ adj[nextVert][i].first + dist[nextVert],adj[nextVert][i].second });
				}
			}
		}
		visited[nextVert] = true;
	}

	for (int i = 1; i <= verts; i++) {
		if (dist[i] == 2000000) {
			cout << -1 << endl;
			continue;
		}
		cout << dist[i] << endl;
	}

	return 0;
}