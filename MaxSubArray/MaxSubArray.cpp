//Using Divide and Conquer method

#include <iostream>
using namespace std;

int maxCrossSub(int arr[], int a, int mid, int b){
    int sumLeft = 0;
    int sumRight = 0;
    int sum = 0;
    
    for(int i = mid; i > a; i--){ //Starting from left side of broken down array
        sum += arr[i]; //Adding the value of each element of the left side of the array
        if(sum > sumLeft){
            sumLeft = sum;
        }
    }
    sum = 0; // Resetting
    for(int i = mid + 1; i <= b; i++){ //Starting from next index from mid, we move to the right
        sum += arr[i];
        if(sum > sumRight){
            sumRight = sum;
        }
    }
    sum = sumLeft + sumRight;
    return sum;
}

int maxSub(int arr[], int a, int b){
    
    if(a == b){//Basically if the array size is 1
        return arr[a];
    }

    
    
    int left = maxSub(arr, a, (a+b)/2); //maxSub Definition,, using arr, from A --> Midpoint
    int center = maxCrossSub(arr, a, (a+b)/2, b); //usingMaxCrossSub defition,, A --> midpoint and midpoint --> B and addying them together
    int right = maxSub(arr, ((a+b)/2) + 1, b); //maxSub Definition: using Arr, from Midpoint --> B
    
    
    
    if(left > center && left > right){
        return left;
    }
    else if(center > right && center > left){
        return center;
    }
    else return right;
}

int main(){
    int input; //How many numbers there are
    cin >> input;
    int arr[input];
    for(int i = 0; i < input; i++){
        cin >> arr[i];
    }
    cout << maxSub(arr, 0, input - 1);
    return 0;
}
