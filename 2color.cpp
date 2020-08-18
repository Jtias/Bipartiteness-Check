// This Program checks whether a graph is 2-colorable(Bipartite) or not using DFS.

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// Helper function to create connected nodes 
void AddEdge(vector<int> adj[], int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}
// Check where the graph is two colorable or not
bool IsTwoColorable(vector<int> adj[], int a, vector<bool>& checked, vector<int>& color)
{
	for (int u : adj[a]) 
	{
		if (checked[u] == false)							
		{
			checked[u] = true;							// Mark this vertex as check if it hasn't been visited yet.
			color[u] = !color[a];                       // Mark as a different color from it's parent
			if (!IsTwoColorable(adj, u, checked, color))
			  return false;
		}
		else if (color[u] == color[a])
			return false;								//Graph is not 2 colorable if the 2 adjacent components are same color.
	}
	return true;
}
int main()
{
	const int N = 7;

	vector<int> adj[N + 1];
	vector<bool> checked(N + 1);
	vector<int> color(N + 1);

	// Add edges to the graph
	AddEdge(adj, 1, 2);
	AddEdge(adj, 2, 3);
	AddEdge(adj, 3, 4);
	AddEdge(adj, 4, 5);
	AddEdge(adj, 5, 6);
	AddEdge(adj, 6, 7);
	AddEdge(adj, 7, 1);

	//Mark the node at the root as visited
	checked[1] = true;
	color[1] = 0;
	//Call function to check if the graph is two colorable
	if (IsTwoColorable(adj, 1, checked, color))
		cout << "The Graph is 2-Colorable";
	else
		cout << "The Graph is not 2-Colorable";

	return 0;
}
