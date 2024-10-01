#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_vetor(int *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%dª posição: %d\n", i+1, vetor[i]);
        printf("\n");
    }
}

int getMax(size_t *arr, __uint8_t size) {
    int i;
    int max = arr[0]; // initialize max with the first element of the array;
    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // update the max value
        }
    }
    return max; // return the max value
}

void countingSort(size_t arr[], __uint8_t size, int exp){
    size_t temp[size];
    

}


void radixsort(size_t *arr, __uint8_t size){
    int m = getMax(arr, size);
    int exp;
    for(exp = 1; m/exp > 0; exp *=10)
        countingSort(arr, size, exp);
}

int main(){
    size_t arr[100];
    __uint8_t size = sizeof(arr)/sizeof(arr[0]);

    printf("arr before sorted: \n\n");
    imprimir_vetor(arr, size);


    

    return 0;
}