#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node 
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to calculate the sum of odd positioned nodes
int sumOfOddPositionedNodes(struct Node* head) 
{
    struct Node* current = head;
    int position = 1;
    int totalSum = 0;

    while (current != NULL) {
        if (position % 2 != 0) {
            totalSum += current->data;
        }
        current = current->next;
        position++;
    }

    return totalSum;
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    // Calculating the sum of odd-positioned nodes
    int result = sumOfOddPositionedNodes(head);
    printf("Sum of odd positioned nodes: %d\n", result);

    return 0;
}
