#include <stdio.h>

void convertToBinary(int number) {
    int binary[32];
    int i = 0;

    if (number == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (number > 0) {
        binary[i++] = number % 2;
        number = number / 2;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    convertToBinary(num);

    return 0;
}
