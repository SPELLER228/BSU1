#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <string.h> 

using namespace std;

class Word {

    char word[20];
public:
    char* m_pStr;
    int   m_nLength;
    Word();
    Word(const char* initialWord);
    Word(char symbol, int repetitions);
    Word(const char* initialWord, int n, int choice);
    Word(const Word& other);
    Word(Word&& other);
    Word(const Word& word1, const Word& word2);
    ~Word();
   
    void fillWord();
    void outputWord();
   
};


