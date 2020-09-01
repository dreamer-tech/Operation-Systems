#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *nxt;
};

void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->nxt;
    }
    printf("\n");
}

void insert_node(struct Node **head, int index_to_insert, int new_val) {
    int pos = 0;
    struct Node *prev_head = NULL, *init_head = *head;
    while (pos < index_to_insert && head != NULL) {
        pos++;
        prev_head = *head;
        *head = (*head)->nxt;
    }
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = new_val;
    new_node->nxt = *head;
    if (prev_head != NULL) {
        *head = init_head;
        for (pos = 0; pos < index_to_insert - 1; pos++)
            *head = (*head)->nxt;
        (*head)->nxt = new_node;
    } else
        *head = new_node;
}


void delete_node(struct Node **head, int index_to_delete) {
    if (*head == NULL)
        return;
    if (index_to_delete == 0) {
        *head = (*head)->nxt;
        return;
    }
    int pos;
    for (pos = 0; pos < index_to_delete - 1; pos++)
        *head = (*head)->nxt;
    if ((*head)->nxt != NULL)
        (*head)->nxt = (*((*head)->nxt)).nxt;
}


int main() {
    struct Node *head = NULL;
    insert_node(&head, 0, 5);
    insert_node(&head, 0, 4);
    insert_node(&head, 1, 3);
    print_list(head);
    delete_node(&head, 0);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    return 0;
}
