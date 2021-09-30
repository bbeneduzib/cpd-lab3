#include <iostream>
#include <vector>
#include <string>
#include "radix.h"

using namespace std;

Radix::Radix(){}

void Radix::sort(vector<string> *words)
{
    //Tamanho do vetor de palavras
    int N = words->size();
    
    //Inicializa e zera vetor auxiliar
    this->aux = vector<string>(N,"\0");
    Radix::radixsort(words, 0, N-1, 0);
}

void Radix::radixsort(vector<string> *words, int lo, int hi, int d)
{
    /* Condicao de parada */
    if (hi < lo) return;

    // Caracteres validos na tabela ASCII
    int aux_size = 'Z' - 'A'+2;

    //Vetor de contagem de caracteres (mesmo para acumulacao)
    vector<int> count(aux_size+2);
    
    /* Conta aparições de cada caracter na posicao d */
    for (int i = lo; i <= hi; i++)
    {
        /* Operador ternario para garantir que o \0 vai ser levado em conta */
        int pos = (((*words)[i][d] - 'A')+2) < 0 ? 1 : ((*words)[i][d] - 'A') + 2;
        count[pos]++;
    }
        

    /* Transforma o vetor em um vetor de acumulacao,
       o qual indicara os indices das palavras */
    for (int r = 0; r < aux_size+1; r++)
        count[r+1] += count[r];

    /* Distribui os caracteres no vetor auxiliar */
    for (int i = lo; i <= hi; i++) {
        /* Operador ternario para garantir que o \0 vai ser levado em conta */
        int pos = (*words)[i][d] == 0 ? count[0]++ : count[((*words)[i][d] - 'A') + 1]++;
        this->aux[pos] = (*words)[i];
    }
    
    /* Copia as palavras semi-ordenadas de volta ao vetor original */
    for (int i = lo; i <= hi; i++)
        (*words)[i] = this->aux[i - lo];

    /* Chama recursivamente a ordenacao para cada caracter  */
    for (int r = 0; r < aux_size; r++){
        Radix::radixsort(words, lo + count[r], lo + count[r+1] - 1, d+1);
    }
}