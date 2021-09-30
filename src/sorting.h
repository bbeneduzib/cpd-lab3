#include <bits/stdc++.h>
#include <fstream>

#ifndef sorting_h
#define sorting_h

using namespace std;

void RadixSort(vector<string> *words, vector<string> *aux, int low, int high, int char_pos);

void RadixSortWrapper(vector<string> *words);

#endif
