# Whether-the-Graph-is-2-Colorable-
This program will check whether a graph is 2-colorable(Bipartite) or not by using Depth First Search.
Algorithm to check bipartiteness of a graph is as follows:
1. Declare an array to store color 0 or 1 for all the nodes that denote different color.
2. Run the depth first search algorithm on the nodes.
3. Check if Node u is visited, if not assign !color[a] to color[u].
4. Now call DFS again on the nodes connected to u.
5. When the color[u] is equal to !color[a], the graph is 2-colorable.
6. The bipartiteness checking function must return a value at the end.
