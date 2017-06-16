/*
 * quicksort_string.c
 *
 *  Created on: May 29, 2017
 *      Author: josngoc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char** arr, int left, int right) {
    int i, j;
    char *pivot;
    char *tmp = (char *) malloc(4 * sizeof(char));
    pivot = arr[left];
    i = left;
    j = right + 1;
    while (1) {
        do {
            ++i;
        } while (strcmp(arr[i], pivot) <= 0 && i <= right);
        do {
            --j;
        } while (strcmp(arr[j], pivot) > 0);
        if (i >= j) {
            break;
        }
        strcpy(tmp, arr[i]);

        arr[i] = (char *) malloc(4 * sizeof(char));
        strcpy(arr[i], arr[j]);

        arr[j] = (char *) malloc(4 * sizeof(char));
        strcpy(arr[j], tmp);
    }
    strcpy(tmp, arr[left]);

    arr[left] = (char *) malloc(4 * sizeof(char));
    strcpy(arr[left], arr[j]);

    arr[j] = (char *) malloc(4 * sizeof(char));
    strcpy(arr[j], tmp);

    free(tmp);
    return j;
}

void quicksort(char** arr, int left, int right) {
    int mid;
    if (left < right) {
        mid = partition(arr, left, right);
        quicksort(arr, left, mid - 1);
        quicksort(arr, mid + 1, right);
    }
}

int main(int argc, char **argv) {
    char* stringArr[5] = { "abcd", "defg", "asdv", "Abcd", "abc" };

//	char *pivot;
//	pivot = stringArr[0];
//	printf("%s\n", pivot);

    quicksort(stringArr, 0, 4);
    int i;
    for (i = 0; i < 5; ++i) {
        printf("%s\n", stringArr[i]);
    }

    return 0;
}
