#include <bits/stdc++.h>
#include <fstream>

using namespace std;

//--------------------------------------------------------------
void RadixSort(vector<string> *words, vector<string> *aux, int low, int high, int char_pos)
//--------------------------------------------------------------
{
  if (high < low)
    return;

  int aux_size = 'Z' - 'A' + 2;

  int pos;

  vector<int> count(aux_size + 2);

  for (int i = low; i <= high; i++)
  {
    if ((((*words)[i][char_pos] - 'A') + 2) < 0)
      pos = 1;
    else
      pos = ((*words)[i][char_pos] - 'A') + 2;

    count[pos]++;
  }

  for (int i = 0; i < aux_size + 1; i++)
    count[i + 1] += count[i];

  for (int i = low; i <= high; i++)
  {
    if ((*words)[i][char_pos] == 0)
      pos = count[0]++;
    else
      pos = count[((*words)[i][char_pos] - 'A') + 1]++;

    (*aux)[pos] = (*words)[i];
  }

  for (int i = low; i <= high; i++)
    (*words)[i] = (*aux)[i - low];

  for (int i = 0; i < aux_size; i++)
  {
    RadixSort(words, aux, low + count[i], low + count[i + 1] - 1, char_pos + 1);
  }
}

//--------------------------------------------------------------
// Define uma array auxiliar vazia com o
// tamanho da array de palavras e chama o RadixSort
//--------------------------------------------------------------
void RadixSortWrapper(vector<string> *words)
//--------------------------------------------------------------
{
  vector<string> aux;

  int size = words->size();

  aux = vector<string>(size, "\0");

  RadixSort(words, &aux, 0, size - 1, 0);

  aux.clear();
}