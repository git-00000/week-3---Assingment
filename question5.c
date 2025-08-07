// 5. Nth Node from End
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printNthFromEnd(struct Node* head, int n) {
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;

    int count = 0;
    while (count < n) {
        if (ref_ptr == NULL) {
            printf("n is greater than the number of nodes\n");
            return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }

    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    printf("%dth node from end is %d\n", n, main_ptr->data);
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    int n = 2;
    printNthFromEnd(head, n);

    return 0;
}
