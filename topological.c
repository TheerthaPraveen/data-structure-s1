// 1:Initialization:

// Declare variables: adjacency matrix adj[20][20], queue queue[20], in-degree array inDegree[20],
//and other necessary variables.

// Initialize front, rear, and all elements of inDegree to -1 and 0, respectively.

// 2:Input Number of Nodes:

// Prompt the user to enter the number of nodes (n).

// 3:Initialize In-Degree Array:

// Set all elements of the inDegree array to 0.

// 4:Input Adjacency Matrix and Update In-Degree:

// Prompt the user to enter the adjacency matrix.

// For each edge i -> j:

// If there is a self-loop (i.e., i == j && adj[i][j] != 0), print an error message and exit.

// If there is an edge (i.e., adj[i][j] == 1), increment the in-degree of node j.

// Add Nodes with Zero In-Degree to Queue:

// For each node i, if inDegree[i] == 0, add it to the queue using the enqueue function.

// Print Topological Sorting Order:

// Print "Topological Sorting Ordering".

// Process Nodes in Queue:

// While the queue is not empty (i.e., front != -1 && rear != -1):

// Dequeue a node (vertex) and print it.

// Increment visitedCount.

// For each adjacent node i of vertex:

// Decrement the in-degree of node i.

// If the in-degree of node i becomes 0, add it to the queue using enqueue.

// Check for Cyclic Graph:

// If visitedCount is less than n, print "Graph is cyclic".













#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n, adj[20][20], visitedCount = 0, queue[20], front = -1, rear = -1, inDegree[20];
void enqueue(int vertex);
int dequeue();
void main()
{
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        inDegree[i] = 0;
    }
    printf("\nEnter the adjacency matrix");
    // reading the adjacency matrix and upadating the indegree
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\na[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
            if (i == j && adj[i][j] != 0) //checking for self loops
            {
                printf("\nGraph contains self loops...Exiting");
                exit(0);
            }
            if (adj[i][j] == 1)
            {
                // incrementing indegree for j for each directed edge i-->j
                inDegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            // adding all the vertices with zero indegree to queue
            enqueue(i);
        }
    }
    printf("\nTopological Sorting Ordering\n");
    while (front != -1 && rear != -1)
    {
        // repeat all the steps while queue is not empty
        int vertex = dequeue();
        // removing vertex from queue and adding it to topological ordering
        printf("%d ", vertex);
        visitedCount++;
        // updating indegree for all adjacent vertices of vertex 'vertex' and adding
        // it to queue if the upadated indegree is zero
        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] == 1)
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
    }
    if (visitedCount < n)
    {
        // if there are nodes left even after queue is empty, the graph is cyclic
        printf("\nGraph is cyclic");
    }
}
void enqueue(int vertex)
{
    if (front == -1)
    {
        front++;
    }
    rear++;
    queue[rear] = vertex;
}
int dequeue()
{
    int vertex = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return vertex;
}