/*
 *  Jordi Pujol Ricarte
 *  Lucas Spagnolo Bombana 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstring>
#include "radix.h"

using namespace std;

int main () {


    vector<string> text_file_name = {"../input/frankenstein.txt", "../input/war_and_peace.txt"};
    vector<string> exit_file_name = {"../output/frankenstein_ordenado.txt", "../output/war_and_peace_ordenado.txt"};
    vector<string> stats_file_name = {"../output/frankenstein_stats.csv", "../output/war_and_peace_stats.csv"};

    for (int i=0; i < 2; i++) {
        ifstream text_file(text_file_name[i]);

        if(!text_file.is_open()) {
            perror("Erro ao abrir arquivo de entrada");
            return EXIT_FAILURE;
        }

        string text;
        getline(text_file, text);

        text_file.close();

        stringstream stream(text);
        istream_iterator<string> begin(stream);
        istream_iterator<string> end;
        vector<string> text_vec (begin, end);

        cout << "arquivo: " << text_file_name[i] << endl;
        cout << "palavras: " << text_vec.size() << endl;
        cout << "-------------------" << endl;
        
        Radix *r = new Radix();
        r->sort(&text_vec);

        ofstream exit_file(exit_file_name[i]);
        
        if(!exit_file.is_open()) {
            perror("Erro ao abrir arquivo de saida");
            return EXIT_FAILURE;
        }

        for (auto word : text_vec) {
            exit_file << word << " ";
        }
        exit_file.close();

        ofstream stats_file(stats_file_name[i]);
        
        if(!stats_file.is_open()) {
            perror("Erro ao abrir arquivo de saida");
            return EXIT_FAILURE;
        }

        string pivot_word = "";
        int counter = 0;
        for (auto word : text_vec) {
            /* Se mudar a palavra, imprime a palavra no arquivo e sua contagem
            e muda a palavra pivo */
            if (word != pivot_word) {
                if (pivot_word != "") {
                    stats_file << pivot_word << "," << counter << endl;
                }
                pivot_word = word;
                counter = 1;
            }
            else {
                counter++;
            } 
        }

        stats_file.close();
    }

    return 0;
}