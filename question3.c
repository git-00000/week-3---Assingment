// delete node in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}


struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return head;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < x - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return head;

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        appendNode(&head, val);
    }

    printf("Enter the position to delete (1-based index): ");
    scanf("%d", &x);

    head = deleteNode(head, x);

    printf("Linked list after deletion:\n");
    printList(head);

}
