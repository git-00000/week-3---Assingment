#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node *insertInMiddle(struct Node *head, int x)
{
    struct Node *new_node = newNode(x);

    if (head == NULL)
    {
        return new_node;
    }

    struct Node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    new_node->next = slow->next;
    slow->next = new_node;

    return head;
}

void printList(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf(" ");
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int x;
    struct Node *head = NULL, *tail = NULL;

    char buffer[100000];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {

        head = NULL;
    }
    else
    {

        int val, i = 0;
        char *ptr = buffer;
        while (sscanf(ptr, "%d%n", &val, &i) == 1)
        {
            struct Node *node = newNode(val);
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            ptr += i;
        }
    }

    scanf("%d", &x);

    head = insertInMiddle(head, x);

    printList(head);

    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
