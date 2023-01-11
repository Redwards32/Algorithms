#include <iostream>
void merge(int array[], int left_start, int mid, int right, int array_length){
    
    
    int left = left_start;
    int right_start = mid + 1;
    int size = array_length;
    int index = left_start;
    
    //creating a temp array
    int temp_array[size];
    
    while (left <= mid && right_start <= right){
        if(array[left] <= array[right_start]){
            temp_array[index] = array[left];
            left++;
        }else{
            temp_array[index] = array[right_start];
            right_start++;
        }
        index++;
    }
    
    //Copying remainder elemnts of both sides
    
    while(left <= mid){
        temp_array[index] = array[left];
        index++;
        left++;
    }
    
    while(right_start <= right){
        temp_array[index] = array[right_start];
        index++;
        right_start++;
    }
    for (int i = left_start; i < right + 1; i++){
        array[i] = temp_array[i];
    }
    
    
}
void merge_sort(int array[], int left, int right, int array_length){
    
    if (array_length <= 1){
        return;
    }
    if (left < right){
        int mid = (left + right) / 2;
        merge_sort(array, left, mid, array_length);//left side
        merge_sort(array, mid + 1, right, array_length);
        
        //merging
        merge(array, left, mid, right, array_length);
    }
}
int main(){
    int array_length; //This is so we can define the size of the given array
    
    std::cin >> array_length;
    //Now we define how big the array is
    int myarray[array_length];
    //User input of arrays in specific elements
    
    for(int i = 0; i < array_length; i++){
        std::cin >> myarray[i];
    }
    merge_sort(myarray, 0, (array_length - 1), array_length);
    for(int i = 0; i < array_length; i++){
                std::cout << myarray[i] << ";";
        }
}
