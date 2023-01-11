#include <iostream>
struct J{ //Initilize of how long the array is (this is basically columns)
    // We did this because we can't pass a 2D array, so we have to make it into a 
pointer
    int H[10];
};
//Given psuedocode, changed it to fit struct delcartion (columns of array)
void CountingSort(J* array, int size_of_array, int pos){
    J* column_value;
    column_value = new J[size_of_array];
    int max_count[10] = {0};
        
    for (int i = 0; i < size_of_array; i++){
        max_count[array[i].H[pos]]++;
    }
    
    for (int i = 1; i < 10; i++){
        max_count[i] += max_count[i - 1];
    }
    for (int i = size_of_array - 1; i >= 0; i--){
        column_value[max_count[array[i].H[pos]] - 1] = array[i];
        max_count[array[i].H[pos]]--;
    }
    for (int i = 0; i < size_of_array; i++){
        array[i] = column_value[i];
    }
}
void RadixSort(J* array, int size_of_array){
    for (int pos = 10; pos > -1; pos--){
        CountingSort(array, size_of_array, pos);
    }
}
int main(){
    int size_of_array;
    std::cin >> size_of_array;
    
    J* array;
    array = new J [size_of_array];
        
    for(int i = 0; i < size_of_array; i++){
        for(int j = 0; j < 10; j++){
            std::cin >> array[i].H[j];
        }
    }
    
    RadixSort(array, size_of_array);
    
    for(int i = 0; i < size_of_array; i++){
        for(int j = 0; j < 10; j++){
            std::cout << array[i].H[j] << ";";
        }
        std::cout << std::endl;
    }
return 0;
    
}
