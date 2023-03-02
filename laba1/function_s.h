#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

#define MAX_STORAGE 100

using namespace std;

void add_info(string path, string* array); // отримання інформації від користувача та запис у файл
int request_info(string path, string* array, int lines); // зчитування інформації з файлу
void swap(string* array, int lines); // сортування рядків за спаданням символів
void output_file(string path, string* array, int lines); // запис відсортованої інформації у файл