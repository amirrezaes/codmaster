#include <iostream>
#include <vector>
#include <math.h>

bool is_prime(std::vector<int> &primes,const int n){
    int range = sqrt(n); 
    for(int i=0; primes[i] <= range; i++){
        if(n % primes[i] == 0) return false;
    }
    primes.push_back(n);
    return true;
}

bool rev_base_eq(int n, int k, std::string chars){
    std::string result = "";
    while(n){
        result = chars[n % k] + result;
        n /= k;
    }
    if(std::string(result.rbegin(),result.rend()) == result) return true;
    return false;
}

int main(){

    const std::string chars = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::vector<int> primes = {2};
    int count = 0, n, k, cur_number = 1;
    std::cin >> n >> k;
    
    if (rev_base_eq(2, k, chars)) count++; // since 2 will not appear in the test below

    while (count < n){
        cur_number += 2;  // only testing the odd numbers
        if (is_prime(primes, cur_number) && rev_base_eq(cur_number, k, chars)){
            count++;
            // std::cout << cur_number << '\n';
        }
    }
    std::cout << cur_number << '\n';
}
