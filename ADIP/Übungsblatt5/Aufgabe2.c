#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct DynArray{
    size_t size;
    size_t current_size;
    int * memory;
}DynArray;

typedef struct DynArrayMin{
    size_t size;
    int * memory;
}DynArrayMin;

int dyn_array_add(DynArray *arr, int value){
    assert(arr != NULL && "Array darf nicht NULL sein");

    if(arr->size == arr->current_size){
        arr->memory = realloc(arr->memory, arr->size*2);
    }
    arr->memory[arr->current_size++] = value;
    arr->size*=2;

    return 0;
}

int dyn_array_min_add(DynArrayMin *arr, int value){
    assert(arr != NULL && "Array darf nicht NULL sein");
    assert(arr->memory != NULL && "Speciher darf nicht NULL sein!");

    arr->size++;
    arr->memory = realloc(arr->memory, arr->size*sizeof(int));


    arr->memory[arr->size-1] = value;

    return 0;
}

int print_dyn_array(DynArray *arr){
    for(int i = 0; i < arr->current_size;i++){
        printf("[%i]", arr->memory[i]);
    }
    printf("\n");
    return 0;
}

int print_dyn_array_min(DynArrayMin *arr){
    for(int i = 0; i < arr->size;i++){
        printf("[%i]", arr->memory[i]);
    }
    printf("\n");
    return 0;
}

int main(){
    DynArray * arr = (DynArray*) malloc(sizeof(DynArray));
    int * memory = malloc(sizeof(int));

    arr->size = 1;
    arr->current_size = 0;
    arr->memory = memory;

    dyn_array_add(arr, 1);
    dyn_array_add(arr, 3);
    dyn_array_add(arr, 6);
    printf("size: %zu_%zu\n", arr->size, arr->current_size);
    print_dyn_array(arr);

    DynArrayMin * arr2 = (DynArrayMin*) malloc(sizeof(DynArrayMin));
    int * memory2 = malloc(sizeof(int));

    arr2->size = 0;
    arr2->memory = memory2;

    dyn_array_min_add(arr2, 1);
    dyn_array_min_add(arr2, 4);
    printf("size: %zu\n", arr2->size);
    print_dyn_array_min(arr2);

    return 0;
}
