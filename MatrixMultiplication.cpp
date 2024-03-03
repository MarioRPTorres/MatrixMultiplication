﻿
#include "MatrixMultiplication.h"
// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

// For demonstration purpose, we will fill up
// a vector with random integers and then sort
// them using sort function. We fill record
// and print the time required by sort function
int main()
{

    M<uint8_t> left(3,3);
    cout << "Initialized left \n" << left;

    // Generate Random values
    auto f = []() -> uint8_t { 

        return rand() % 256; 
    };

    // Fill up the vector
     generate(left.begin(), left.end(), f);

    cout << "\nFilled left\n" << left;
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    M<uint8_t> result = multiplyMatrix(&left, &left);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;

    return 0;
}