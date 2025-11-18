#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    printf("%d added to the list\n", value);
}

void deleteValue(struct Node **head, int value) {
    struct Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list\n", value);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("%d removed from the list\n", value);
}

void reverseList(struct Node **head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed\n");
}

struct Node* mergeLists(struct Node *a, struct Node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node *merged = NULL;
    if (a->data < b->data) {
        merged = a;
        merged->next = mergeLists(a->next, b);
    } else {
        merged = b;
        merged->next = mergeLists(a, b->next);
    }
    return merged;
}

void findMiddle(struct Node *head) {
    struct Node *slow = head, *fast = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle of the list: %d\n", slow->data);
}

void sortList(struct Node **head) {
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted\n");
}

int detectLoop(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

void sumOfData(struct Node *head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    printf("Sum of all values: %d\n", sum);
}

void printOddEven(struct Node *head) {
    printf("Odd values: ");
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data % 2 != 0) printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nEven values: ");
    temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void showList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int choice, value, listNum;

    printf("Welcome! Let's explore linked list operations.\n");

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n2. Delete\n3. Reverse\n4. Merge\n5. Find Middle\n6. Sort\n");
        printf("7. Detect Loop\n8. Sum of Data\n9. Print Odd/Even\n10. Show List\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 11) {
            printf("Goodbye!\n");
            break;
        }

        if (choice == 1 || choice == 2) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            printf("Enter value: ");
            scanf("%d", &value);
            if (choice == 1) {
                if (listNum == 1) insertEnd(&head1, value);
                else insertEnd(&head2, value);
            } else {
                if (listNum == 1) deleteValue(&head1, value);
                else deleteValue(&head2, value);
            }
        } else if (choice == 3) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            if (listNum == 1) reverseList(&head1);
            else reverseList(&head2);
        } else if (choice == 4) {
            struct Node *merged = mergeLists(head1, head2);
            printf("Merged list: ");
            showList(merged);
        } else if (choice == 5) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            if (listNum == 1) findMiddle(head1);
            else findMiddle(head2);
        } else if (choice == 6) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            if (listNum == 1) sortList(&head1);
            else sortList(&head2);
        } else if (choice == 7) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            int hasLoop = (listNum == 1) ? detectLoop(head1) : detectLoop(head2);
            if (hasLoop) printf("Loop detected!\n");
            else printf("No loop found\n");
        } else if (choice == 8) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            if (listNum == 1) sumOfData(head1);
            else sumOfData(head2);
        } else if (choice == 9) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            if (listNum == 1) printOddEven(head1);
            else printOddEven(head2);
        } else if (choice == 10) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listNum);
            if (listNum == 1) showList(head1);
            else showList(head2);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
