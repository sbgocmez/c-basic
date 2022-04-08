#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NODES 5

int count_muls = 0;

void print_matrix(const int *matrix, int m, int n)
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            int index = row * n + col;
            printf("%3d", matrix[index]);
        }
        printf("\n");
    }
}

void fill_random(int *matrix, int m, int n)
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            int index = row * n + col;
            matrix[index] = rand() % 2;
        }
    }
}

void multiply_matrix(const int *matrix1, const int *matrix2, int m, int n, int p,
                     int *matrix3)
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < p; col++) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                int index1 = row * n + i;
                int index2 = i * p + col;
                total += matrix1[index1] * matrix2[index2];
                count_muls++;
            }
            int index = row * p + col;
            matrix3[index] = total;
        }
    }
}

void copy_matrix(int *dst, const int *src, int m, int n)
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            int index = row * n + col;
            dst[index] = src[index];
        }
    }
}

void power_matrix(const int *matrix, int n, int exp, int *result)
{
    copy_matrix(result, matrix, n, n);
    for (int i = 0; i < exp - 1; i++) {
        int *next = (int *) malloc(n * n * sizeof(int));
        multiply_matrix(result, matrix, n, n, n, next);
        copy_matrix(result, next, n, n);
        free(next);
    }
}

void add_matrix(const int *matrix1, const int *matrix2, int m, int n, int *result)
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            int index = row * n + col;
            result[index] = matrix1[index] + matrix2[index];
        }
    }
}

void connectivity_matrix(const int *matrix, int n, int *result)
{
    memset(result, 0, n * n * sizeof(int));
    for (int i = 1; i <= n - 1; i++) {
        int *power = (int *) malloc(n * n * sizeof(int));
        power_matrix(matrix, n, i, power);
        int *sum = (int *) malloc(n * n * sizeof(int));
        add_matrix(result, power, n, n, sum);
        copy_matrix(result, sum, n, n);
        free(sum);
        free(power);
    }
}

void connectivity_matrix_fast(const int *matrix, int n, int *result)
{
    copy_matrix(result, matrix, n, n);
    int *next = (int *) malloc(n * n * sizeof(int));
    copy_matrix(next, matrix, n, n);
    for (int i = 2; i <= n - 1; i++) {
        int *power = (int *) malloc(n * n * sizeof(int));
        multiply_matrix(next, matrix, n, n, n, power);
        int *sum = (int *) malloc(n * n * sizeof(int));
        add_matrix(result, power, n, n, sum);
        copy_matrix(result, sum, n, n);
        copy_matrix(next, power, n, n);
        free(sum);
        free(power);
    }
    free(next);
}

void connectivity_matrix_warshall(const int *matrix, int n, int *result)
{
    copy_matrix(result, matrix, n, n);
    for (int node = 0; node < n; node++) {
        for (int row = 0; row < n; row++) {
            int index = row * n + node;
            if (result[index] == 1) {
                for (int col = 0; col < n; col++) {
                    int index1 = node * n + col;
                    if (result[index1] == 1) {
                        int index2 = row * n + col;
                        result[index2] = 1;
                    }
                }
            }
        }
    }
}

void identity_matrix(int *matrix, int n)
{
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int index = row * n + col;
            matrix[index] = row == col ? 1 : 0;
        }
    }
}

int main()
{
    int *graph = (int *) malloc(NODES * NODES * sizeof(int));

    srand(time(NULL));

    fill_random(graph, NODES, NODES);
    print_matrix(graph, NODES, NODES);
    printf("\n");

    int *squared = (int *) malloc(NODES * NODES * sizeof(int));
    multiply_matrix(graph, graph, NODES, NODES, NODES, squared);
    print_matrix(squared, NODES, NODES);
    printf("\n");
    free(squared);

    int *power = (int *) malloc(NODES * NODES * sizeof(int));
    power_matrix(graph, NODES, 2, power);
    print_matrix(power, NODES, NODES);
    printf("\n");
    free(power);

    int *sum = (int *) malloc(NODES * NODES * sizeof(int));
    add_matrix(graph, graph, NODES, NODES, sum);
    print_matrix(sum, NODES, NODES);
    printf("\n");
    free(sum);

    int *connectivity = (int *) malloc(NODES * NODES * sizeof(int));

    clock_t t1 = 0, t2 = 0;
    double elapsed = 0;

    count_muls = 0;
    t1 = clock();
    connectivity_matrix(graph, NODES, connectivity);
    t2 = clock();
    elapsed = (t2 - t1) / (float) CLOCKS_PER_SEC;
    printf("%d multiplications, %f seconds\n", count_muls, elapsed);
    print_matrix(connectivity, NODES, NODES);
    printf("\n");

    count_muls = 0;
    t1 = clock();
    connectivity_matrix_fast(graph, NODES, connectivity);
    t2 = clock();
    elapsed = (t2 - t1) / (float) CLOCKS_PER_SEC;
    printf("%d multiplications, %f seconds\n", count_muls, elapsed);
    print_matrix(connectivity, NODES, NODES);
    printf("\n");

    t1 = clock();
    connectivity_matrix_warshall(graph, NODES, connectivity);
    t2 = clock();
    elapsed = (t2 - t1) / (float) CLOCKS_PER_SEC;
    printf("%f seconds\n", elapsed);
    print_matrix(connectivity, NODES, NODES);
    printf("\n");

    free(connectivity);

    int *identity = (int *) malloc(NODES * NODES * sizeof(int));
    identity_matrix(identity, NODES);
    print_matrix(identity, NODES, NODES);
    printf("\n");
    free(identity);

    free(graph);

    return EXIT_SUCCESS;
}
