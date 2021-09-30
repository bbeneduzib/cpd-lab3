#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void radixSort(vector<string> *words, vector<string> *aux, int lo, int hi, int d)
{
  /* Condicao de parada */
  if (hi < lo)
    return;

  // Caracteres validos na tabela ASCII
  int aux_size = 'Z' - 'A' + 2;

  //Vetor de contagem de caracteres (mesmo para acumulacao)
  vector<int> count(aux_size + 2);

  /* Conta aparições de cada caracter na posicao d */
  for (int i = lo; i <= hi; i++)
  {
    /* Operador ternario para garantir que o \0 vai ser levado em conta */
    int pos = (((*words)[i][d] - 'A') + 2) < 0 ? 1 : ((*words)[i][d] - 'A') + 2;
    count[pos]++;
  }

  /* Transforma o vetor em um vetor de acumulacao,
       o qual indicara os indices das palavras */
  for (int r = 0; r < aux_size + 1; r++)
    count[r + 1] += count[r];

  /* Distribui os caracteres no vetor auxiliar */
  for (int i = lo; i <= hi; i++)
  {
    /* Operador ternario para garantir que o \0 vai ser levado em conta */
    int pos = (*words)[i][d] == 0 ? count[0]++ : count[((*words)[i][d] - 'A') + 1]++;
    (*aux)[pos] = (*words)[i];
  }

  /* Copia as palavras semi-ordenadas de volta ao vetor original */
  for (int i = lo; i <= hi; i++)
    (*words)[i] = (*aux)[i - lo];

  /* Chama recursivamente a ordenacao para cada caracter  */
  for (int r = 0; r < aux_size; r++)
  {
    radixSort(words, aux, lo + count[r], lo + count[r + 1] - 1, d + 1);
  }
}

void sort(vector<string> *words)
{
  vector<string> aux;

  int N = words->size();

  aux = vector<string>(N, "\0");

  radixSort(words, &aux, 0, N - 1, 0);

  aux.clear();
}