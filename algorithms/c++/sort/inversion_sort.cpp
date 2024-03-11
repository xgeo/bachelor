#include <iostream>
// Função para mesclar dois subvetores ordenados e contar inversões
long long mergeAndCount(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    long long inversionCount = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            // Se o elemento em left[i] for maior que right[j], isso forma inversões
            inversionCount += n1 - i;
            arr[k++] = right[j++];
        }
    }

    // Copia os elementos restantes do subvetor esquerdo, se houver
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // Copia os elementos restantes do subvetor direito, se houver
    while (j < n2) {
        arr[k++] = right[j++];
    }

    return inversionCount;
}

// Função principal de contagem de inversões usando o merge sort
long long countInversions(int arr[], int low, int high) {
    long long inversionCount = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        // Divide e conquista para contar inversões nos subvetores esquerdo e direito
        inversionCount += countInversions(arr, low, mid);
        inversionCount += countInversions(arr, mid + 1, high);

        // Mescla os subvetores e conta as inversões na mesclagem
        inversionCount += mergeAndCount(arr, low, mid, high);
    }

    return inversionCount;
}

int main() {
    int arr[] = {1, 3, 5, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Conta e exibe o número de inversões no vetor dado
    long long inversions = countInversions(arr, 0, n - 1);

    std::cout << "Inversões: " << inversions << std::endl;

    return 0;
}

/**
 *
 * Estratégia de dividir para conquistar
 *
 * do merge sort para contar eficientemente as inversões em um vetor
 * de números reais.
 *
 * A complexidade de tempo desse algoritmo é O(n log(n)) tanto no melhor quanto
 * no pior caso.
*/