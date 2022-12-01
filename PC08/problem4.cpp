//
// Created by Trenton W. Ford on 12/1/2022.
//

#include <iostream>


// your code goes here

int main() {

    int a = 7;
    int b = 11;
    double c = 2.5;

    std::cout << "7^11=" << power(a,b) << std::endl;
    std::cout << "10^7=" << power(a) << std::endl;
    std::cout << "e^2.5=" << power(c) << std::endl;

    return 0;
}