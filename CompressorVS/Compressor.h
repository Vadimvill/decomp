#include "stdio.h"
#include "stdlib.h"
typedef struct Stack {
    struct Node* top;
} Stack;
typedef struct Words {
    char* word;
    int count;
}Words;
typedef struct Node {
    char* name;
    struct Node* next;
}Node;

typedef struct Pair {
    char* word1;
    char* word2;
} Pair;
Words* textToWord(Stack* stack, Words* words, int* i);
Pair* createDictionary(Words* words, int i, int* j);
void writeKeysInFile(Pair* dictionary, int j, FILE* file);
void replaceWordWithPairInDictionaryInFile(const char* sourceFilePath, const char* outFilePath, Pair* dictionary, int j);
int push(Stack* stack, char* data);
char* pop(Stack* stack);
void init(Stack* s);
void textToStack(Stack* stack);
int isEmpty(Stack* stack);