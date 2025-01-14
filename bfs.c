// 1:Initialization:

// adj[20][20], queue[10], front = -1, rear = -1, n, i, j, start, visited[20]: 
// These are variables used to represent the adjacency matrix, queue, 
// front and rear of the queue, the number of nodes, loop indices, the starting node, 
// and an array to keep track of visited nodes, respectively.

// 2:Input Number of Nodes:

// The code prompts the user to enter the number of nodes (n) in the graph.

// 3:Input Adjacency Matrix:

// The code reads the adjacency matrix, which indicates whether there is an edge between two nodes. 
// For example, adj[i][j] = 1 means there is an edge between node i and node j.

// 4:Input Starting Node:

// The code prompts the user to enter the starting node for the BFS traversal.

// If the starting node is invalid (i.e., less than 0 or greater than n-1), it prints "Invalid Entry!!".

// 5:BFS Traversal:

// The BFS traversal is performed starting from the given node using the bfs function.

// 6:BFS Function (bfs(int start)):

// enqueue(start): The starting node is enqueued into the queue.

// visited[start] = 1: The starting node is marked as visited.

// printf("%d\t", start): The starting node is printed.

// 7:While Loop:

// The while loop runs as long as the queue is not empty (front != -1 && rear != -1).

// int node = dequeue(): The front node is dequeued from the queue.

// 8:For Loop:

// The for loop iterates over all nodes i in the graph.

// if (adj[i][node] == 1 && visited[i] != 1): Checks if there is an edge between node and i, 
// and if i has not been visited.

// visited[i] = 1: Marks node i as visited.

// printf("%d\t", i): Prints node i.

// enqueue(i): Enqueues node i into the queue.

// 9:Enqueue Function (enqueue(int node)):

// If the queue is empty (front == -1 && rear == -1), it sets front and rear to 0.

// Otherwise, it increments rear.

// The node is added to the queue at the position indicated by rear.

// 10:Dequeue Function (dequeue()):

// Dequeues the node at the position indicated by front.

// If the queue becomes empty (front == rear), it resets front and rear to -1.

// Otherwise, it increments front.







#include <stdio.h>

int n, i, j, adj[20][20], start, visited[20], queue[10], front = -1, rear = -1;

void bfs(int start);
void enqueue(int node);
int dequeue();

int main() {
    printf("\nEnter the no: of nodes:");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Reading the graph from adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\nEnter A[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter the starting vertex:");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("\nInvalid Entry!!");
    } else {
        printf("BFS visited order\n");
        bfs(start);
    }

    return 0;
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;
    printf("%d\t", start);

    while (front != -1 && rear!= -1)
     { //this loop runs as there are elements in the queue
        int node = dequeue();
        
        // Explore all neighbors of the node
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] != 1) {
                visited[i] = 1;
                printf("%d\t", i);
                enqueue(i);
            }
        }
    }
}

void enqueue(int node) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = node;
}

int dequeue() {
    int node = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else 
    {
        front++;
    }
return node;
}
