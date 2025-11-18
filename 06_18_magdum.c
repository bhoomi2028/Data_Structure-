
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *temp = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index])
            temp->children[index] = createNode();
        temp = temp->children[index];
    }
    temp->isEndOfWord = 1;
    printf("Inserted: %s\n", word);
}

int search(struct TrieNode *root, const char *word) {
    struct TrieNode *temp = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index])
            return 0;
        temp = temp->children[index];
    }
    return temp->isEndOfWord;
}

int main() {
    struct TrieNode *root = createNode();
    int choice;
    char word[100];

    printf("Welcome to Trie operations!\n");

    while (1) {
        printf("\n1. Insert word\n2. Search word\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter word (lowercase only): ");
        scanf("%s", word);

        if (choice == 1) {
            insert(root, word);
        } else if (choice == 2) {
            if (search(root, word))
                printf("Found: %s\n", word);
            else
                printf("Not found: %s\n", word);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
