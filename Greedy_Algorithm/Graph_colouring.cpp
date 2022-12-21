// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <list>
using namespace std;
 
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
	public:
    // Constructor and destructor
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints greedy coloring of the vertices
    void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
    int result_colour[V];
 	int colour;
    // Assign the first color to first vertex
    result_colour[0]  = 0;
 	list<int>::iterator i;
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result_colour[u] = -1;  // no color is assigned to u
 
    // A temporary array to store the available_colours for a vertex. True
    // value of available_colours[colour] would mean that the colour is available
    // and false would mean it is assigned to one of its adjacent vertices.
    bool available_colours[V];
    for (int colour = 0; colour < V; colour++)
        available_colours[colour] = true;
 
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable_colours
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result_colour[*i] != -1)//if an already coloured and connected vertex is found.
                available_colours[result_colour[*i]] = false;
 
        // Find the first available_colours color
        for (colour = 0; colour < V; colour++)
            if (available_colours[colour] == true)
                break;
 
        result_colour[u] = colour; // Assign the found color
 
        // Reset the values back to false for the next iteration
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
                available_colours[result_colour[*i]] = true;
    }
 
    // print the result_colour
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result_colour[u] << endl;
}
 
// Driver program to test above function
int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();
 
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    g2.greedyColoring();
 
    return 0;
}
