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
        //fazer o sorting
        for(int i = 0; i < size; i++)
        {
            output_stream << strVector[i] << endl;
        }
        strVector.clear();

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
