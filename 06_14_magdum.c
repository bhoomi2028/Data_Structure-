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

void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void bfs(struct Node *root) {
    if (!root) return;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node *temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

void dfs(struct Node *root) {
    if (!root) return;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node *temp = stack[top--];
        printf("%d ", temp->data);
        if (temp->right) stack[++top] = temp->right;
        if (temp->left) stack[++top] = temp->left;
    }
}

struct Node* mirror(struct Node *root) {
    if (!root) return NULL;
    struct Node *temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    return root;
}

void findChildren(struct Node *root, int value) {
    if (!root) return;
    if (root->data == value) {
        if (root->left) printf("Left child: %d\n", root->left->data);
        if (root->right) printf("Right child: %d\n", root->right->data);
        if (!root->left && !root->right) printf("No children\n");
        return;
    }
    findChildren(root->left, value);
    findChildren(root->right, value);
}

void findParent(struct Node *root, int value, struct Node *parent) {
    if (!root) return;
    if (root->data == value) {
        if (parent) printf("Parent: %d\n", parent->data);
        else printf("This is the root node\n");
        return;
    }
    findParent(root->left, value, root);
    findParent(root->right, value, root);
}

void findSibling(struct Node *root, int value) {
    if (!root || (!root->left && !root->right)) return;
    if (root->left && root->left->data == value && root->right)
        printf("Sibling: %d\n", root->right->data);
    else if (root->right && root->right->data == value && root->left)
        printf("Sibling: %d\n", root->left->data);
    else {
        findSibling(root->left, value);
        findSibling(root->right, value);
    }
}

void findGP(struct Node *root, int value, struct Node *parent, struct Node *gp) {
    if (!root) return;
    if (root->data == value) {
        if (gp) printf("Grandparent: %d\n", gp->data);
        else printf("No grandparent found\n");
        return;
    }
    findGP(root->left, value, root, parent);
    findGP(root->right, value, root, parent);
}

void findUncle(struct Node *root, int value, struct Node *parent, struct Node *gp) {
    if (!root) return;
    if (root->data == value) {
        if (!gp) {
            printf("No grandparent, so no uncle\n");
            return;
        }
        if (gp->left == parent && gp->right)
            printf("Uncle: %d\n", gp->right->data);
        else if (gp->right == parent && gp->left)
            printf("Uncle: %d\n", gp->left->data);
        else
            printf("No uncle found\n");
        return;
    }
    findUncle(root->left, value, root, parent);
    findUncle(root->right, value, root, parent);
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    printf("Welcome! Let's build and explore a Binary Search Tree.\n");

    while (1) {
        printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.BFS 6.DFS 7.Mirror\n");
        printf("8.Children 9.Sibling 10.Parent 11.Grandparent 12.Uncle 13.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 13) {
            printf("Goodbye!\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
        } else if (choice >= 2 && choice <= 6) {
            printf("Traversal: ");
            if (choice == 2) inorder(root);
            else if (choice == 3) preorder(root);
            else if (choice == 4) postorder(root);
            else if (choice == 5) bfs(root);
            else if (choice == 6) dfs(root);
            printf("\n");
        } else if (choice == 7) {
            root = mirror(root);
            printf("Tree mirrored\n");
        } else {
            printf("Enter node value: ");
            scanf("%d", &value);
            if (choice == 8) findChildren(root, value);
            else if (choice == 9) findSibling(root, value);
            else if (choice == 10) findParent(root, value, NULL);
            else if (choice == 11) findGP(root, value, NULL, NULL);
            else if (choice == 12) findUncle(root, value, NULL, NULL);
        }
    }

    return 0;
}
