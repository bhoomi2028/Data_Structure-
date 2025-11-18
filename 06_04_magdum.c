#include <stdio.h>
#define SIZE 100

int arr[SIZE];
int front1 = -1, rear1 = -1;
int front2 = SIZE, rear2 = SIZE;

void addToQueue1(int value) {
    if (rear1 + 1 == rear2) {
        printf("Oops! No space left in Queue 1\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    arr[++rear1] = value;
    printf("%d added to Queue 1\n", value);
}

void addToQueue2(int value) {
    if (rear2 - 1 == rear1) {
        printf("Oops! No space left in Queue 2\n");
        return;
    }
    if (front2 == SIZE) front2 = SIZE - 1;
    arr[--rear2] = value;
    printf("%d added to Queue 2\n", value);
}

void removeFromQueue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue 1 is empty. Nothing to remove\n");
        return;
    }
    printf("%d removed from Queue 1\n", arr[front1++]);
}

void removeFromQueue2() {
    if (front2 == SIZE || front2 < rear2) {
        printf("Queue 2 is empty. Nothing to remove\n");
        return;
    }
    printf("%d removed from Queue 2\n", arr[front2--]);
}

void showQueue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void showQueue2() {
    if (front2 == SIZE || front2 < rear2) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Queue 2: ");
    for (int i = front2; i >= rear2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, queueNum, value;

    printf("Welcome! Let's manage two queues using one array.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add to a queue\n");
        printf("2. Remove from a queue\n");
        printf("3. Show a queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Thanks for using the program. See you next time!\n");
            break;
        }

        printf("Which queue? (1 or 2): ");
        scanf("%d", &queueNum);

        if (queueNum != 1 && queueNum != 2) {
            printf("Hmm, that's not a valid queue number.\n");
            continue;
        }

        if (choice == 1) {
            printf("Enter the number you want to add: ");
            scanf("%d", &value);
            if (queueNum == 1) addToQueue1(value);
            else addToQueue2(value);
        } else if (choice == 2) {
            if (queueNum == 1) removeFromQueue1();
            else removeFromQueue2();
        } else if (choice == 3) {
            if (queueNum == 1) showQueue1();
            else showQueue2();
        } else {
            printf("That option doesn't exist\n");
        }
    }

    return 0;
}
