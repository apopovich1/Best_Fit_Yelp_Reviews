#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Restaurant {
    string name;
    float stars;
};

int partition(vector<Restaurant>& restaurants, int low, int high);
void QuickSort_Helper(vector<Restaurant>& restaurants, int low, int high);
string QuickSort(vector<Restaurant>& restaurants);

void heapify_down(vector<Restaurant>& restaurants, int size, int child);
string HeapSort(vector<Restaurant>& restaurants);
