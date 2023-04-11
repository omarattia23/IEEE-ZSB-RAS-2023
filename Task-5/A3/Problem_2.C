/*
Write a C program that runs continuously and adds a node 
to a linked list if the user enters “+”, deletes one 
if he enters “-” and prints the linked list if he enters “p” 
then make it stop if “x” is entered.
Hint: Handle empty list when printing
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    char input;
    struct Node* head = NULL;

    while (1) {
        printf("Enter '+' to add a node, '-' to delete a node, 'p' to print the list, or 'x' to exit: ");
        scanf(" %c", &input);

        switch (input) {
            case '+': {
                int data;
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                insertNode(&head, data);
                printf("Node added\n");
                break;
            }
            case '-': {
                deleteNode(&head);
                printf("Node deleted\n");
                break;
            }
            case 'p': {
                printList(head);
                break;
            }
            case 'x': {
                printf("Exiting...\n");
                return 0;
            }
            default: {
                printf("Invalid input\n");
                break;
            }
        }
    }
}
