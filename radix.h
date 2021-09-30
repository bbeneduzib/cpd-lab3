#ifndef RADIX_H
#define RADIX_H

#include <iostream>
#include <vector>

using namespace std;

class Radix {
public:
    Radix();

    vector<string> aux;
    void sort(vector<string> *words);
    void radixsort(vector<string> *words, int lo, int hi, int d);
        
};

#endif //RADIX_H