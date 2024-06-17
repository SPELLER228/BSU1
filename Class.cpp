#include "Word.h"

Word::Word()
{
    for (int i = 0; i < 20; i++)
    {
        word[i] = '\0';
    }
}
Word::Word(const char* initialWord)
{
    strcpy(word, initialWord);
}
Word::Word(char symbol, int repetitions)
{
    for (int i = 0; i < repetitions; i++)
    {
        word[i] = symbol;
    }
    word[repetitions] = '\0';
}
Word::Word(const char* initialWord, int n, int choice)
{
    if (choice == 1)
    {
        strncpy(word, initialWord, n);
        word[n] = '\0';
    }
    if (choice == 2)
    {
        int length = strlen(initialWord);
        for (int i = 0; i < n; i++)
        {
            if (length > 0)
                word[i] = initialWord[length--];
        }
        word[n] = '\0';
    }
}

Word::Word(const Word& other)
{
    strcpy(word, other.word);
}

Word::Word(Word&& other)
{
    m_nLength = other.m_nLength;
    m_pStr = other.m_pStr;
    other.m_pStr = nullptr;
    other.m_nLength = 0;
}
Word::Word(const Word& word1, const Word& word2) // два объекта
{
    if (strcmp(word1.word, word2.word) > 0)
        strcpy(word, word1.word);
    else
        strcpy(word, word2.word);
}

Word::~Word()
{};
void Word::fillWord()
{
    cin.getline(word, 20); 
}

void Word::outputWord()
{
    for (int i = 0; i < strlen(word); i++)
        cout << word[i];
    cout << endl;
}


