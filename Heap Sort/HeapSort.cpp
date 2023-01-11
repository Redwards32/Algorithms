#include <iostream>



void Max_Heap(int array[], int size_of_array, int i){
    int largest_for_root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < size_of_array && array[left] > array[largest_for_root]){
        largest_for_root = left;
    }
    if(right < size_of_array && array[right] > array[largest_for_root]){
        largest_for_root = right;
    }
    if(largest_for_root != i){
        std::swap(array[i], array[largest_for_root]);
        Max_Heap(array, size_of_array, largest_for_root);
    }
}






void heapSort(int array[], int size_of_array){
    for(int i = size_of_array/2 - 1; i >= 0; i--){
        Max_Heap(array, size_of_array, i);
    }
    for(int i = size_of_array - 1; i > 0; i--){
        std::swap(array[0], array[i]);
        Max_Heap(array, i, 0);
    }
}
    



int main(){
    int size_of_array;
    std::cin >> size_of_array;
    int array[size_of_array];
        
    for(int i = 0; i < size_of_array; i++){
        std::cin >> array[i];
    }
    heapSort(array, size_of_array);
    
    for(int i = 0; i < size_of_array; i++){
        std::cout << array[i] << ";";
    }
    
    
    return 0;
    
}
