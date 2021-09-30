#include <bits/stdc++.h>
#include <ctype.h>

//#include "sorting.h"

using namespace std;

string FRANKENSTEIN_FILE_PATH = "frankenstein_clean.txt";
string WAR_AND_PEACE_FILE_PATH = "war_and_peace_clean.txt";

string FRANKENSTEIN_OUTPUT_PATH = "frankenstein_ordenado.txt";
string WAR_AND_PEACE_OUTPUT_PATH = "war_and_peace_ordenado.txt";

bool IsLetters(string input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!isalpha(input[i]))
          return false;  // character is not alphabetic
    }
    return true;  // Every character is alphabetic
}

void RadixSort(vector<string> *words, vector<string> *aux, int lo, int hi, int d)
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
        (*aux)[pos] = (*words)[i];
    }

    /* Copia as palavras semi-ordenadas de volta ao vetor original */
    for (int i = lo; i <= hi; i++)
        (*words)[i] = (*aux)[i - lo];

    /* Chama recursivamente a ordenacao para cada caracter  */
    for (int r = 0; r < aux_size; r++){
        RadixSort(words, aux, lo + count[r], lo + count[r+1] - 1, d+1);
    }
}

//--------------------------------------------------------------
// Cria os arquivos de saída e abre o arquivo de entrada.
// Faz a leitura e parse de cada linha.
// Para cada arquivo de entrada, faz a ordenacao lexicografica
// das palavras.
// Escreve no arquivo de saida uma litsa com todas as palavras
// e o numero de ocorrencias de cada uma.
//--------------------------------------------------------------
void Laboratorio()
//--------------------------------------------------------------
{
    vector<string> input_file_name = {FRANKENSTEIN_FILE_PATH, WAR_AND_PEACE_FILE_PATH};
    vector<string> output_file_name = {FRANKENSTEIN_OUTPUT_PATH, WAR_AND_PEACE_OUTPUT_PATH};

    int size;
    string temp;

    for (int i=0; i < 2; i++)
    {
        ifstream file_stream;
        ofstream output_stream(output_file_name[i]);

        if (!output_stream)
        {
            cerr << "[ERROR] Could not create output file \n";
            exit(1);
        }

        file_stream.open(input_file_name[i]);

        if(!file_stream)
        {
            cerr << "[ERROR] Could not read input file \n";
            output_stream.close();

            exit(1);
        }

        size = 0;

        vector <string> strVector;
        while (file_stream >> temp)
        {
            if(temp.length() > 3 && IsLetters(temp))
            {
                strVector.push_back(temp);
                size++;
            }
        }

        vector<string> aux;
        /*
        for(int j = 0; j < size; j++){
            aux[j] = "\0";
        }
        */

        RadixSort(&strVector, &aux, 0, size-1, 0);

        for(int i = 0; i < size; i++)
        {
            output_stream << strVector[i] << endl;
        }

        strVector.clear();
        //aux.clear();

        file_stream.close();
        output_stream.close();
    }
}

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
  Laboratorio();

  return 0;
}
