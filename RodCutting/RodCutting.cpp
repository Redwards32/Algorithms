//Practicing Dynamic Programming


#include <iostream>
int n;
int q;
//Psuedocode given on Page 390, Section 15.1 Rod Cutting
void extended_bottom_up_cut_rod(int p[], int n){
    int r[n + 1];
    int s[n + 1];
    r[0] = 0;
    
    for (int j = 1; j <= n; j++){
        q = 0;
        for (int i = 1; i <= j; i++){
            if (q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    //Psuedocode given on page 390, Section 15.1 Rod Cutting: Right after the 
Extended-Bottom-Up-Rod psuedocode.
    std::cout << r[n] << std::endl;
    while (n > 0){
        std::cout << s[n] << " ";
        n = n - s[n];
    }
    std::cout << "-1" << std::endl;
}
int main(){
    std::cin >> n;
    int p[n + 1];
    p[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        std::cin >> p[i];
    }
    extended_bottom_up_cut_rod(p, n);
    return 0;
}
