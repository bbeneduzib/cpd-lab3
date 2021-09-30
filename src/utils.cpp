#include <bits/stdc++.h>
#include <fstream>

using namespace std;

bool IsLetters(string input)
{
  for (size_t i = 0; i < input.size(); i++)
  {
    if (!isalpha(input[i]))
      return false;
  }

  return true;
}

void CountOccurrences(vector<string> *arr, int size, ofstream &output_stream)
{
  int word_count = 1;

  if (size == 0)
    return;

  string curr_word = (*arr)[0];

  for (int i = 1; i < size; i++)
  {
    if (curr_word != (*arr)[i] || i == size - 1)
    {
      if (curr_word == (*arr)[i] && i == size - 1)
        word_count++;

      output_stream << curr_word << " " << word_count << endl;

      word_count = 0;
      curr_word = (*arr)[i];
    }

    word_count++;
  }

  if ((*arr)[size - 1] != (*arr)[size - 2])
  {
    output_stream << (*arr)[size - 1] << " 1" << endl;
  }
}