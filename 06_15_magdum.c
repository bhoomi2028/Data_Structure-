#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value) {
    if (!root) return create(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

void printRange(struct Node *root, int low, int high) {
    if (!root) return;

    if (root->data > low)
        printRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        printRange(root->right, low, high);
}

int main() {
    struct Node *root = NULL;
    int n, val, low, high;

    printf("How many values to insert in BST? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter range (low high): ");
    scanf("%d %d", &low, &high);

    printf("Values in range [%d, %d]: ", low, high);
    printRange(root, low, high);
    printf("\n");

    return 0;
}
