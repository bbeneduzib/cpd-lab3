#include <bits/stdc++.h>
#include <ctype.h>

#include "sorting.h"
#include "utils.h"

using namespace std;

string FRANKENSTEIN_FILE_PATH = "frankenstein_clean.txt";
string WAR_AND_PEACE_FILE_PATH = "war_and_peace_clean.txt";

string FRANKENSTEIN_OUTPUT_PATH = "frankenstein_ordenado.txt";
string WAR_AND_PEACE_OUTPUT_PATH = "war_and_peace_ordenado.txt";

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

    string temp;
    int size;

    for (int i = 0; i < 2; i++)
    {
        ifstream file_stream;
        ofstream output_stream(output_file_name[i]);

        if (!output_stream)
        {
            cerr << "[ERROR] Could not create output file \n";
            exit(1);
        }

        file_stream.open(input_file_name[i]);

        if (!file_stream)
        {
            cerr << "[ERROR] Could not read input file \n";
            output_stream.close();

            exit(1);
        }

        size = 0;

        vector<string> str_vector;
        while (file_stream >> temp)
        {
            if (temp.length() > 3 && IsLetters(temp))
            {
                str_vector.push_back(temp);
                size++;
            }
        }

        RadixSortWrapper(&str_vector);

        CountOccurrences(&str_vector, size, output_stream);

        str_vector.clear();

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
