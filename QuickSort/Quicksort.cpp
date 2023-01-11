#include <iostream>


void swap(int* first_element, int* second_element){
    int t = *first_element;
    *first_element = *second_element;
    *second_element = t;
}



int randompartition(int array[], int lower, int higher){
    int random_pivit = array[higher];
    int i = (lower - 1);
    
    
    for (int j = lower; j < higher; j++){
        if (array[j] < random_pivit){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[higher]);
    return (i + 1);
}





void QuickSort(int array[], int lower, int higher){
    if (lower < higher){
        int q = randompartition(array, lower, higher);
        
        
        QuickSort(array, lower, q - 1);
        QuickSort(array, q + 1, higher);
    }
}

int main(){
    int size_of_array;
    std::cin >> size_of_array;
    int array[size_of_array];
        
    for(int i = 0; i < size_of_array; i++){
        std::cin >> array[i];
    }
    QuickSort(array, 0, size_of_array - 1);
    
    for(int i = 0; i < size_of_array; i++){
        std::cout << array[i] << ";";
    }
    
    
    return 0;
    
}
