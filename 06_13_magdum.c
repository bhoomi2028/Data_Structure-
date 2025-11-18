#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
typedef struct Node Node;

Node *head1 = NULL, *head2 = NULL;

Node* newNode(int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}

void insert(Node **head, int val) {
    Node *n = newNode(val);
    if (!*head) *head = n;
    else {
        Node *t = *head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void delete(Node **head, int val) {
    Node *t = *head;
    while (t && t->data != val) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else *head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void reverse(Node **head) {
    Node *curr = *head, *temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) *head = temp->prev;
}

Node* merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        if (a->next) a->next->prev = a;
        return a;
    } else {
        b->next = merge(a, b->next);
        if (b->next) b->next->prev = b;
        return b;
    }
}

void middle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) printf("Middle: %d\n", slow->data);
}

void sort(Node *head) {
    for (Node *i = head; i; i = i->next)
        for (Node *j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
}

int hasLoop(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

void sum(Node *head) {
    int total = 0;
    while (head) total += head->data, head = head->next;
    printf("Sum: %d\n", total);
}

void printOddEven(Node *head) {
    printf("Odd: ");
    for (Node *t = head; t; t = t->next)
        if (t->data % 2) printf("%d ", t->data);
    printf("\nEven: ");
    for (Node *t = head; t; t = t->next)
        if (t->data % 2 == 0) printf("%d ", t->data);
    printf("\n");
}

void show(Node *head) {
    while (head) printf("%d ", head->data), head = head->next;
    printf("\n");
}

int main() {
    int ch, val, list;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Reverse 4.Merge 5.Middle 6.Sort 7.Loop 8.Sum 9.OddEven 10.Show 11.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 11) break;
        if (ch <= 3 || (ch >= 5 && ch <= 10)) {
            printf("List (1 or 2): ");
            scanf("%d", &list);
        }
        Node **target = (list == 2) ? &head2 : &head1;
        if (ch == 1) {
            printf("Value: ");
            scanf("%d", &val);
            insert(target, val);
        } else if (ch == 2) {
            printf("Value: ");
            scanf("%d", &val);
            delete(target, val);
        } else if (ch == 3) reverse(target);
        else if (ch == 4) {
            Node *m = merge(head1, head2);
            show(m);
        } else if (ch == 5) middle(*target);
        else if (ch == 6) sort(*target);
        else if (ch == 7) printf(hasLoop(*target) ? "Loop found\n" : "No loop\n");
        else if (ch == 8) sum(*target);
        else if (ch == 9) printOddEven(*target);
        else if (ch == 10) show(*target);
    }
    return 0;
}
