//
// Created by Trenton W. Ford on 12/1/2022.
//

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

typedef std::vector<double> doubleV;

doubleV dedup(doubleV vec)
{
 // your code goes here
}

int main(){
    std::string in_filename = "unsorted_numbers.dat";
    std::string out_filename = "deduplicated_numbers.dat";

    std::ifstream infile;
    infile.open(in_filename);

    doubleV input_vector;
    double tmp;

    if(infile.is_open()) {
        while (infile >> tmp) {
            input_vector.push_back(tmp);
        }
    } else {
        std::cout << "File Failed To Open." << std::endl;
        exit(1);
    }

    doubleV deduplicated_numbers = dedup(input_vector);

    std::ofstream outfile;
    outfile.open(out_filename);

    for(int i = 0; i < deduplicated_numbers.size(); i++)
    {
        outfile << deduplicated_numbers.at(i) << " ";
    }

    infile.close();
    outfile.close();

    return 0;
}