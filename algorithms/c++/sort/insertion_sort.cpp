#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
    Considere o primeiro elemento da lista como a única sequência
    ordenada no início.
    Iteração: Para cada elemento subsequente,
    compare-o com os elementos na sequência ordenada.
     Mova os elementos maiores para a direita para
     abrir espaço para o elemento atual.
    Inserção: Insira o elemento atual na posição correta na sequência ordenada.
    Repetição: Repita os passos 2 e 3 até que todos os elementos estejam na sequência ordenada.
    O algoritmo continua a aumentar a sequência ordenada até que todos os elementos estejam classificados.
     A complexidade de tempo média do algoritmo de
     ordenação por inserção é de O(n^2), onde 'n' é o número de elementos na lista.
     No entanto, para listas pequenas ou parcialmente ordenadas, pode ser mais eficiente do que alguns algoritmos de
     ordenação mais complexos.
 */
int main() {
    int i, j, key, k;
    int A[] = {5, 2, 4, 6, 1, 3};
    /**
     * sizeof(A): Returns the total size (in bytes) of the array A.
     * It essentially gives the size of the entire array in memory.
     * sizeof(A[0]): Returns the size (in bytes) of a single element of the array A.
     * This is equivalent to the size of the data type of the elements in the array.
     */
    int n = sizeof(A) / sizeof(A[0]);

    for (j = 1; j < n; j++) {
        key = A[j];
        i = j - 1;

        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
            A[i + 1] = key;
        }
    }

    for (k = 0; k < n; k++) {
        cout << A[k] << ",";
    }

    return 0;
}