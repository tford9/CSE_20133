//
// Created by Trenton W. Ford on 12/1/2022.
//

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

typedef std::vector<double> doubleV;

doubleV running_average(doubleV vec)
{
    doubleV averages_vec;

    for(int i = 0; i < vec.size(); i++)
    {
        double current_sum = 0;
        double current_avg;

        for(int j = 0; j <= i; j++)
        {
            current_sum += vec.at(j);
        }

        current_avg = current_sum/(double)i;
        averages_vec.push_back(current_avg);
    }

    return averages_vec;
}

int main(){
    std::string in_filename = "unsorted_numbers.dat";
    std::string out_filename = "running_averages.dat";

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

    doubleV running_avgs = running_average(input_vector);

    std::ofstream outfile;
    outfile.open(out_filename);

    for(int i = 0; i < running_avgs.size(); i++)
    {
        outfile << running_avgs.at(i) << " ";
    }

    infile.close()
    outfile.close()

    return 0;
}