#include<stdio.h>
void sort(int* arr, int size, int k){
    int* count = (int*)calloc(k, sizeof(int)); // initialized to 0

    for(int i = 0; i < size; i++){
        if(arr[i] >= 0 && arr[i] < k){
            count[arr[i]]++;
        }
    }

    int index = 0;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < count[i]; j++){
            if(index >= size) goto END;
            arr[index++] = i;
        }
    }
    END:
    free(count);
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
