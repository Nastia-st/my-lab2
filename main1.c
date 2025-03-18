#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}

void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    system("chcp 65001");
    int X[15], A;
    for (int i = 0; i < 15; i++) {
        printf("Введіть X[%d] = ", i);
        while (scanf("%d", &X[i]) != 1) {
            printf("Помилка! Введіть ціле число: ");
            while (getchar() != '\n'); 
        }
    }

    printf("Введіть значення цільового елемента (A): ");
    while (scanf("%d", &A) != 1) {
        printf("Помилка! Введіть ціле число: ");
        while (getchar() != '\n'); 
    }

    printf("\nПочатковий масив:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    int linearIndex = linearSearch(X, 15, A);
    if (linearIndex != -1) {
        printf("\nЛінійний пошук: елемент A знайдено на позиції %d\n", linearIndex);
    } else {
        printf("\nЛінійний пошук: елемент A не знайдено\n");
    }

    bubbleSortDescending(X, 15);
    printf("\nМасив після сортування за спаданням:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    int binaryIndex = binarySearch(X, 15, A);
    if (binaryIndex != -1) {
        printf("\nБінарний пошук: елемент A знайдено на позиції %d\n", binaryIndex);
    } else {
        printf("\nБінарний пошук: елемент A не знайдено\n");
    }

    return 0;
}