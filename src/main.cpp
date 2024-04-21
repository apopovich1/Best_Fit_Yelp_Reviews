#include <iostream>
#include <cctype>
using namespace std;
#include <vector>
#include "Parsing.h"
#include "Sorter.h"
int main() {
    string state;
    cout << "Enter a State Abbreviation of two uppercase characters ex FL for Florida:";
    cin >> state;
    while(state.length()>3){
        cout << "Not an abbreviation, enter again:";
        cin >> state;
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        state[i] = (toupper(int(state[i])));
    }
    string city;
    cout << "Enter the city of the restaurant:";
    cin >> city;
    cout << endl;
    city[0] = toupper(int(city[0]));
    for(int i =1; i< city.size(); i++){
        city[i] = tolower(city[i]);
    }
    string categories;
    cout << "Enter any category for the restaurant, if multiple categories seperated by comma with first letter capitalized:";
    cin >>categories;
    cout << endl;
    string zip;
    cout << "What is the zipcode of the targeted area:";
    cin >> zip;
    cout << endl;
    Parsing parse;
    vector<Restaurant> sorting= parse.elimination(state, city, categories, zip);
    cout << endl;
    QuickSort(sorting);
    cout << "\n";
    HeapSort(sorting);
    return 0;
}
