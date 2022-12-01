//
// Created by Trenton W. Ford on 12/1/2022.
//

#include <vector>
#include <iostream>

std::pair<bool, std::vector<uint>> prime_factorializer(int number){
    std::pair<bool, std::vector<uint>> return_pair;
    bool prime = false;

    // your code goes here

    return_pair.first = prime;
    return return_pair;
}

int main() {

    srand(time(0));
    for (uint i = 0; i <= 10; i++) {
        uint number = rand() % 1000;
        std::cout << "Randomly Generated Number: " << number << std::endl;
        std::pair<bool, std::vector<uint>> result = prime_factorializer(number);
        if (!result.first) {
            std::cout << "Prime Factors of " << number << " are : ";
            for (uint i = 0; i < result.second.size(); i++)
                std::cout << result.second.at(i) << " ";
            std::cout << std::endl;
        } else {
            std::cout << "Generated Number (" << number << ") is prime" << std::endl;
        }
    }
}