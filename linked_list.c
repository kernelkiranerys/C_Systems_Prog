#include <stdio.h>
#include <stdlib.h> 

struct Node {
    char data;
    struct Node *next;
    struct Node *prev;

};
int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = NULL;
    third->prev = second;

    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    free(head);
    free(second);
    free(third);

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
