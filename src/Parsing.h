//
// Created by apop1 on 4/21/2024.
//

#ifndef UNTITLED2_PARSING_H
#define UNTITLED2_PARSING_H
#pragma once

#include <string>
#include <vector>

using namespace std;
struct Restaurant{
    string name ;
    string state ;
    string city ;
    string postalCode = "0";
    float stars = 0.0;
    int is_open = -1;
    string categories;
    string address;
    //This is for the restaurant object
};

class Parsing {
    private:
        string fileName = "yelp_academic_dataset_business_Redo.json";
    public:
        vector<Restaurant> Parse(string& state);
        bool categorySelect(string& categories, string& input);
        int myStoi(string &input);
        vector<Restaurant> elimination(string& state, string& city, string& categories, string& zip);
};


#endif //UNTITLED2_PARSING_H
