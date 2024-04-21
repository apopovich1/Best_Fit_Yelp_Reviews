#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma once
#include "Parsing.h"
using namespace std;

int partition(vector<Restaurant>& restaurants, int low, int high);
void QuickSort_Helper(vector<Restaurant>& restaurants, int low, int high);
void QuickSort(vector<Restaurant>& restaurants);

void heapify_down(vector<Restaurant>& restaurants, int size, int child);
void HeapSort(vector<Restaurant>& restaurants);
