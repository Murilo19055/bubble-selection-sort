#include <stdio.h>
#include <time.h>

void preencher(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = n - i;  // ordem decrescente (pior caso)
    }
}

void bubbleSort(int v[], int n, long long *comp, long long *mov) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            (*comp)++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*mov)++;
            }
        }
    }
}

void selectionSort(int v[], int n, long long *comp, long long *mov) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
            (*mov)++;
        }
    }
}

int main() {

    int tamanhos[3] = {100, 1000, 10000};
    int v[10000];

    printf("Algoritmo\tTamanho\tTempo(ms)\tComparacoes\tMovimentacoes\n");

    for (int t = 0; t < 3; t++) {

        int n = tamanhos[t];
        long long comp = 0;
        long long mov = 0;
        clock_t inicio, fim;
        double tempo;

        // BUBBLE SORT
        preencher(v, n);
        comp = 0;
        mov = 0;

        inicio = clock();
        bubbleSort(v, n, &comp, &mov);
        fim = clock();

        tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

        printf("Bubble Sort\t%d\t%.3f\t\t%lld\t\t%lld\n",
               n, tempo, comp, mov);

        // SELECTION SORT
        preencher(v, n);
        comp = 0;
        mov = 0;

        inicio = clock();
        selectionSort(v, n, &comp, &mov);
        fim = clock();

        tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

        printf("Selection Sort\t%d\t%.3f\t\t%lld\t\t%lld\n",
               n, tempo, comp, mov);
    }

    return 0;
}
