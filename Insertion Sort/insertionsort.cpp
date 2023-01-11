#include <iostream>
void insertion_sort(int array[], int array_length){
  
    //For loop to read the array through.
    
    //We store each element in a temp key to have it used as a 'reference'
    for(int i = 1; i < array_length; i++){
        int temp_key = array[i];
        int j = i - 1;
        
        //j is going to compare the values with each element in the array: starting
from end to the very beginning
        while(j >= 0 && temp_key < array[j]){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp_key;
        for(j = 0; j <= i; j++){
            std::cout << array[j] << ";";
        }
        std::cout << std::endl;
    }
}
int main(){
    int array_length; //This is so we can define the size of the given array
    
    std::cin >> array_length;
    //Now we define how big the array is
    int array[array_length];
    //User input of arrays in specific elements
    
    for(int i = 0; i < array_length; i++){
        std::cin >> array[i];
    }
    insertion_sort(array, array_length);
}
