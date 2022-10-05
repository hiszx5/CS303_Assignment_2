#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int checkIndex(int* array, int number, int size);
int modifyIndex(int*& array, int index, int number);
void addIndex(int*& array, int number, int& size);
void del_val(int*& array, int& size, unsigned int index);
void printArray(int* array, int size);
void printMenu();
#endif