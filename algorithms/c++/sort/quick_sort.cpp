#include <iostream>

using namespace std;

void swap (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    /**
     * Setar o mais alto como Pivor
     * Lembrando que não faz diferença se eu escolho o maior ou menor
     * eu escolhi usar o maior.
     */
    int pivot = arr[high];

    /**
     * Aqui simplesmente o valor mais baixo -1 para inciar oi processo
     * de ordenação
     */
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        /**
         * Sempre que o elemento do índice J que é do menor para o maior
         * faremos um swap e jogaremos ele para a esquerda
         */
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    /**
     * Se o valor informado como low realmente for menor que o high
     * daremos continuidade a recorrência
     */
    if (low < high) {
        int pi = partition(arr, low, high);
        /**
         * valor a esquerda mais baixo onde tá o pivor
         */
        quickSort(arr, low, pi - 1);

        /**
         * valor mais alto a direita onde ta o pivor
         */
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    quickSort(arr, 0, n-1);

    for (i = 0; i <= n-1; i++)
    {
        cout << arr[i] << "";
    }

    cout << endl;

    return 0;
}