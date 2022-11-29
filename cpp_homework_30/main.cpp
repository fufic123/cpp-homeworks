//
//  main.cpp
//  cpp_homework_30
//
//  Created by Mark Semenov on 29.11.2022.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    char* stroka = new char[200];
    for (int i = 0; i < 200; i++)
    {
        stroka[i] = ' ';
    }


    std::cout << "String = ";
    gets(stroka);
    char glasn[12] = {'e', 'y', 'u', 'i', 'o', 'a', 'E', 'Y', 'U', 'I', 'O', 'A'};
    char soglasn[40] = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'R', 'T', 'P', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
    char punctuation[10] = {'.', ',', ';', ':', '!', '?', '-', '(', ')', '"'};
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int glasncount = 0, soglasncount = 0, punctuationcount = 0, numberscount = 0, wordscount = 0, anothercount = 0, allsymbols = 0;


    for ( ; allsymbols < 200; allsymbols++)
    {
        if (allsymbols != 199)
        {
            if (stroka[allsymbols + 1] == ' ' && stroka[allsymbols] != ' ')
            {
                wordscount++;
            }
        }


        for (int j = 0; j < 12; j++) //glasn check
        {
            if (stroka[allsymbols] == glasn[j])
            {
                glasncount++;
            }
        }


        for (int j = 0; j < 40; j++) //soglasn check
        {
            if (stroka[allsymbols] == soglasn[j])
            {
                soglasncount++;
            }
        }


        for (int j = 0; j < 10; j++) //punctuation check
        {
            if (stroka[allsymbols] == punctuation[j])
            {
                punctuationcount++;
            }
        }


        for (int j = 0; j < 10; j++) //numbers check
        {
            if (stroka[allsymbols] == numbers[j])
            {
                numberscount++;
            }
        }
    }
    anothercount = allsymbols - glasncount - soglasncount - punctuationcount - numberscount;
    cout << "All symbols in string - " << allsymbols << ", of them:\nWords - " << wordscount << "\nVowels - " << glasncount << "\nConsonants - " <<
        soglasncount << "\nPunctuation symbols - " << punctuationcount << "\nNumbers - " << numberscount << "\nAnother symbols - " << anothercount;


}
