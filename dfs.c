// 1:Initialization:

// adj[20][20], stack[20], top = -1, n, i, j, start, visited[20]: 
// These are variables used to represent the adjacency matrix, stack, the top of the stack, 
// the number of nodes, loop indices, the starting node, 
// and an array to keep track of visited nodes, respectively.

//2: Input Number of Nodes:

// The code prompts the user to enter the number of nodes (n) in the graph.

//3: Input Adjacency Matrix:

// The code reads the adjacency matrix, which indicates whether there is an edge between two nodes.
//  For example, adj[i][j] = 1 means there is an edge between node i and node j.

// 4:Input Starting Node:

// The code prompts the user to enter the starting node for the DFS traversal.

// 5:DFS Traversal:

// The DFS traversal is performed starting from the given node using the dfs function.

// 6:DFS Function (dfs(int node)):

// The dfs function marks the current node as visited and prints it.

// It then recursively visits all adjacent nodes (children) that are not yet visited.

// Here's how the DFS traversal works for a given graph:

// Starting from the start node, the algorithm visits the node, marks it as visited, and prints it.

// It then explores all adjacent nodes that haven't been visited yet by making recursive calls to the dfs function.

// This process continues until all reachable nodes from the start node are visited.





#include <stdio.h>
#include <stdbool.h>
int adj[20][20], stack[20], top = -1, n, i, j, start, visited[20];
void dfs(int start);
void main()
{
    printf("\nEnter number of nodes:");
    scanf("%d", &n);
    // Reading the graph from adjacency matrix
    printf("\nEnter the adjacency matrix : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\nA[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    printf("\nEnter starting node:");
    scanf("%d", &start);
    printf("\nDFS Visited Order\n");
    dfs(start);
}
void dfs(int node)
{
    // visiting the node
    visited[node] = 1;
    printf(" %d", node);
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] != 1)  
        //this checks if there is any edge between the current node and i
  //then it checks i is an unvisited or visited node (both the conditions needs to be true)
        {
            // calling dfs recursively on each children
            dfs(i);
        }
    }
}