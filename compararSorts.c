#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TAM;

void insertionSort(int v[], int TAM) {
    int i, j, key;
    for (i = 1; i < TAM; i++) {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void merge(int v[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

int main() {
    clock_t t;
    srand((unsigned)time(NULL));

    for (int i = 0; i <= 400000; i += 50000) {
        TAM = i;
        int *vetor = malloc(TAM * sizeof(int));
        for (int a = 0; a < TAM; a++) vetor[a] = rand() % TAM;

        t = clock();
        insertionSort(vetor, TAM);
        t = clock() - t;
        printf("Tempo de execucao isort (%d elementos): %lf ms\n", TAM, ((double)t) / ((CLOCKS_PER_SEC / 1000)));

        free(vetor);
    }

    for (int i = 0; i <= 400000; i += 50000) {
        TAM = i;
        int *vetor = malloc(TAM * sizeof(int));
        for (int a = 0; a < TAM; a++) vetor[a] = rand() % TAM;

        t = clock();
        mergeSort(vetor, 0, TAM - 1);
        t = clock() - t;
        printf("Tempo de execucao msort (%d elementos): %lf ms\n", TAM, ((double)t) / ((CLOCKS_PER_SEC / 1000)));

        free(vetor);
    }

    return 0;
}
