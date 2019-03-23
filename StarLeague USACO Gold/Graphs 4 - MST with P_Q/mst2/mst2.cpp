// mst2.cpp 

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#define pii pair<int,int>
using namespace std;
int verts, edges, cost(0);
bool visited[50001];
vector<pair<int, int>> adj[50001];
priority_queue<pii, vector<pii>, greater<pii>> pq;


int main()
{
	cin >> verts >> edges;

	//puts neighbors in list. pair(cost, neighbor)
	for (int i = 0; i < edges; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	int vertsVisited = 0;
	pq.push({ 0,1 });

	while (vertsVisited < verts) {
		if (visited[pq.top().second]) {	// to avoid cycles
			pq.pop();
			continue;
		}

		int nextVert = pq.top().second;
		cost += pq.top().first;			// add to cost
		pq.pop();
		int vectorSize = adj[nextVert].size();
		visited[nextVert] = true;		// update visited

		for (int i = 0; i < vectorSize; i++) {
			if (!visited[adj[nextVert][i].second]) { // excludes pairs with verts already visited
				pq.push(adj[nextVert][i]);
			}
		}
		vertsVisited++;
	}
			
		
	cout << cost << endl;

	return 0;
}

