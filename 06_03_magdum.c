#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE];
int *top, *next;
int totalSize, numStacks;
int freeSpot;

void setup(int size, int stacks) {
    totalSize = size;
    numStacks = stacks;

    top = malloc(numStacks * sizeof(int));
    next = malloc(totalSize * sizeof(int));

    for (int i = 0; i < numStacks; i++) top[i] = -1;
    for (int i = 0; i < totalSize - 1; i++) next[i] = i + 1;
    next[totalSize - 1] = -1;

    freeSpot = 0;
}

void push(int stack, int value) {
    if (freeSpot == -1) {
        printf("No space left. Can't add %d to stack %d\n", value, stack);
        return;
    }

    int index = freeSpot;
    freeSpot = next[index];

    next[index] = top[stack];
    top[stack] = index;

    arr[index] = value;

    printf("%d added to stack %d\n", value, stack);
}

void pop(int stack) {
    if (top[stack] == -1) {
        printf("Stack %d is empty\n", stack);
        return;
    }

    int index = top[stack];
    top[stack] = next[index];

    next[index] = freeSpot;
    freeSpot = index;

    printf("%d removed from stack %d\n", arr[index], stack);
}

void peek(int stack) {
    if (top[stack] == -1) {
        printf("Stack %d is empty\n", stack);
    } else {
        printf("Top of stack %d is %d\n", stack, arr[top[stack]]);
    }
}

void show(int stack) {
    if (top[stack] == -1) {
        printf("Stack %d is empty\n", stack);
        return;
    }

    printf("Stack %d: ", stack);
    for (int i = top[stack]; i != -1; i = next[i]) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, stack, value;

    printf("How big should the array be? ");
    scanf("%d", &totalSize);
    printf("How many stacks do you want? ");
    scanf("%d", &numStacks);

    setup(totalSize, numStacks);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add to stack\n");
        printf("2. Remove from stack\n");
        printf("3. See top item\n");
        printf("4. Show stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Goodbye!\n");
            break;
        }

        printf("Which stack? (0 to %d): ", numStacks - 1);
        scanf("%d", &stack);

        if (stack < 0 || stack >= numStacks) {
            printf("That's not a valid stack number\n");
            continue;
        }

        if (choice == 1) {
            printf("Enter value to add: ");
            scanf("%d", &value);
            push(stack, value);
        } else if (choice == 2) {
            pop(stack);
        } else if (choice == 3) {
            peek(stack);
        } else if (choice == 4) {
            show(stack);
        } else {
            printf("Invalid choice\n");
        }
    }

    free(top);
    free(next);
    return 0;
}
