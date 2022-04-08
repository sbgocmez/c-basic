#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_ELEMENTS 5

int main()
{
    int scores[N_ELEMENTS];
    int current_size = 0;

    int score = 0;
    while (true) {
        scanf("%d", &score);
        if (score == -1) {
            break;
        }
        scores[current_size] = score;
        current_size++;
    }

    for (int i = 0; i < current_size; i++) {
        if (i > 0) {
            printf(" | ");
        }
        printf("%d", scores[i]);
    }
    printf("\n");

    int total = 0;
    for (int i = 0; i < current_size; i++) {
        total += scores[i];
    }
    printf("Sum: %d\n", total);

    double average = (double) total / current_size;
    printf("Average: %.2f\n", average);

    int max = scores[0];
    for (int i = 1; i < current_size; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    printf("Max score: %d\n", max);

    int min = scores[0];
    for (int i = 1; i < current_size; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    printf("Min score: %d\n", min);

    int value = 48;
    int pos = -1;
    for (int i = 0; i < current_size; i++) {
        if (scores[i] == value) {
            pos = i;
            break;
        }
    }
    printf("Position: %d\n", pos);

    int remove_pos = 1;
    for (int i = remove_pos + 1; i < current_size; i++) {
        scores[i - 1] = scores[i];
    }
    current_size--;

    for (int i = 0; i < current_size; i++) {
        if (i > 0) {
            printf(" | ");
        }
        printf("%d", scores[i]);
    }
    printf("\n");

    int new_score = 98;
    if (current_size < N_ELEMENTS) {
        current_size++;
        scores[current_size - 1] = new_score;
    }

    for (int i = 0; i < current_size; i++) {
        if (i > 0) {
            printf(" | ");
        }
        printf("%d", scores[i]);
    }
    printf("\n");

    new_score = 75;
    int ins_pos = 1;
    if (current_size < N_ELEMENTS) {
        for (int i = current_size - 1; i > ins_pos; i--) {
            scores[i + 1] = scores[i];
        }
        scores[ins_pos] = new_score;
        current_size++;
    }

    for (int i = 0; i < current_size; i++) {
        if (i > 0) {
            printf(" | ");
        }
        printf("%d", scores[i]);
    }
    printf("\n");

    int pos1 = 1, pos2 = 3;
    int tmp = scores[pos1];
    scores[pos1] = scores[pos2];
    scores[pos2] = tmp;

    for (int i = 0; i < current_size; i++) {
        if (i > 0) {
            printf(" | ");
        }
        printf("%d", scores[i]);
    }

    printf("\n");
    return EXIT_SUCCESS;
}
