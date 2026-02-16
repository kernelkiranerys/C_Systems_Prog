#include <stdio.h>
#include <stdlib.h> 

struct Node {
    char data;
    struct Node *next;
    struct Node *prev;

};

// Function prototypes
void add(struct Node **head, char data);
void sort(struct Node *head);
void delete(struct Node **head, char key);
void printList(struct Node *node);
void freeList(struct Node *head);

int main() {
    struct Node *head = NULL;
    
    printf("=== Linked List Testing Suite ===\n\n");
    
    // Test 1: Add elements
    printf("Test 1: Adding elements (A, B, C, D, E)\n");
    add(&head, 'A');
    add(&head, 'B');
    add(&head, 'C');
    add(&head, 'D');
    add(&head, 'E');
    printf("List after adding: ");
    printList(head);
    
    // Test 2: Print to verify
    printf("\nTest 2: Current list\n");
    printf("List: ");
    printList(head);
    
    // Test 3: Sort elements
    printf("\nTest 3: Sorting list in ascending order\n");
    sort(head);
    printf("List after sorting: ");
    printList(head);
    
    // Test 4: Delete an element
    printf("\nTest 4: Deleting element 'C'\n");
    delete(&head, 'C');
    printf("List after deleting 'C': ");
    printList(head);
    
    // Test 5: Delete head element
    printf("\nTest 5: Deleting head element 'A'\n");
    delete(&head, 'A');
    printf("List after deleting 'A': ");
    printList(head);
    
    // Test 6: Delete non-existent element
    printf("\nTest 6: Attempting to delete non-existent element 'Z'\n");
    delete(&head, 'Z');
    printf("List after attempting to delete 'Z': ");
    printList(head);
    
    // Test 7: Add more elements and re-sort
    printf("\nTest 7: Adding more elements (M, F, X)\n");
    add(&head, 'M');
    add(&head, 'F');
    add(&head, 'X');
    printf("List after adding: ");
    printList(head);
    
    printf("\nSorting again: ");
    sort(head);
    printList(head);
    
    // Clean up
    printf("\nFreeing all nodes...\n");
    freeList(head);
    printf("Done!\n");
    
    return 0;
}   
//add elements to the linked list
void add(struct Node **head, char data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

//sort elements in the linked list in ascending order of character values (unicode)
void sort(struct Node *head) {
    if (head == NULL) {
        return;
    }

    struct Node *current = head;
    while (current != NULL) {
        struct Node *next_node = current->next;
        while (next_node != NULL) {
            if (current->data > next_node->data) {
                char temp = current->data;
                current->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        current = current->next;
    }
}

//delete elements from the linked list
void delete(struct Node **head, char key) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return; // Key not found
    }

    if (prev == NULL) {
        *head = current->next; // Deleting the head node
    } else {
        prev->next = current->next; // Bypass the current node
    }

    if (current->next != NULL) {
        current->next->prev = prev; // Update the previous pointer of the next node
    }

    free(current); // Free the memory of the deleted node
}

//print the linked list when changes are made
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

//free all nodes in the linked list
void freeList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}
