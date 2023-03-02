#pragma once
#include <iostream>

#define MAX_STORAGE 100

using namespace std;

int add_info_p(const char* path, char array[][MAX_STORAGE], int size); // отримання інформації від користувача та запис у файл
void swap_p(char array[][MAX_STORAGE], int size); // сортування рядків за спаданням символів
void out_file_p(const char* path, char array[][MAX_STORAGE], int size); // запис відсортованої інформації у файл 