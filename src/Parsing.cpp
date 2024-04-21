//
// Created by apop1 on 4/21/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "../include/rapidjson/document.h"
//just need document class from json
using namespace std;
using namespace rapidjson;
#include <vector>
#include "Parsing.h"
vector<Restaurant> Parsing::Parse(string& state){
    //This function is to parse the entire json document and return an vector of Restaurant objects
    ifstream ifstream1(fileName); // This is for reading json document
    Restaurant error; //object if error occurs
    vector<Restaurant> res = {}; //vector of object if error occurs
    if ( !ifstream1.is_open() )
    {
        error.is_open = -1;
        //This error should not happen at all unless file in wrong posiiton
        std::cout<< "Could not open file for reading!\n";
        res.push_back(error);
        return res;
    }
    std::string json((istreambuf_iterator<char>(ifstream1)),istreambuf_iterator<char>());
    //string above gets all of json data into string
    Document doc;
    //document file from json parses the document into a doc tree with object at top and array of business objects
    doc.Parse(json.c_str());
    if ( doc.HasParseError())
    {
        //should not happen due to my file working
        std::cout << "Error  : " << doc.GetParseError()  << '\n'
                  << "Offset : " << doc.GetErrorOffset() << '\n';
        error.is_open = -1;
        res.push_back(error);
        return res;
    }
    Value::ConstMemberIterator itr=doc.MemberBegin(); //this is the business object
    for (SizeType i = 0; i < itr->value.Size(); i++) { //itr->value is all associated attributes with the buisness object so ~150k
        Restaurant current;
        const Value& business = itr->value[i];
        //for every buisness object get following from array
        if(business["state"].IsString() && business["state"].GetString() == state){ //if in selected state

            if(business["name"].IsString()){
                current.name = business["name"].GetString();//supposed to be string
            }
            if(business["state"].IsString()){
                current.state = business["state"].GetString();// supposed to be string
            }

            if(business["city"].IsString()){
                current.city = business["city"].GetString();//supposed to be string
            }

            if(business["postal_code"].IsString()){
                current.postalCode = business["postal_code"].GetString();//supposed to be string
            }

            if(business["stars"].IsFloat()){
                current.stars = business["stars"].GetFloat();//supposed to be float
                //stars do in fact float
            }

            if(business["is_open"].IsInt()){
                current.is_open = business["is_open"].GetInt();//supposed to be int
            }

            if(business["categories"].IsString()){
                current.categories = business["categories"].GetString();//supposed to be string
            }
            if(business["address"].IsString()){
                current.address = business["address"].GetString();//supposed to be string
            }
            res.push_back(current);
        }

    }
    return res;
}

bool Parsing::categorySelect(string& categories, string& input){
    //This function is to check if a user inputted category is in the businesses object's categories string
    stringstream ss(input);
    string currString;
    while(getline(ss, currString,',')){
        if(categories.find(currString)!=std::string::npos)
            //if the current category is found then return true
            return true;
    }
    return false;
}

int Parsing::myStoi(string &input){
    //This function is to make stoi work
    string total;
    for(char i : input) {
        if(isdigit(i)) {
            total += i;
        }
    }
    if(total.size()>1){
        return stoi(total);
    }
    return 101; //larger than useful value in next function
}

vector<Restaurant> Parsing::elimination(string& state, string& city, string& categories, string& zip) {
    //The purpose of this function is to filter for the user selected inputs
    vector<Restaurant> restaurants = Parse(state);
    //gets parsed Restaurant object vectors
    if (restaurants.size() == 1 && restaurants[0].is_open == -1) {
        return restaurants;
        //Error handeling
    }
    vector<Restaurant> hasCategory;
    vector<Restaurant> hasZip;
    vector<Restaurant> stateOnly;
    vector<Restaurant> hasCity;
    //The above vectors are storage for what happens below
    bool isCat,isCity,isZip = false;
    //city, postalcode,  categories

    for (Restaurant x: restaurants) {
        if (x.is_open == 1) {
            //The business is open
            if (x.categories.find("Restaurant")!=std::string::npos && categorySelect(x.categories, categories)) {
                //It is a restaurant and a category matches
                hasCategory.push_back(x);
                //pushes into category specific vector
                isCat = true;
            }
            else{
                if(x.categories.find("Restaurant")!=std::string::npos && !isCat){
                    //It is a restaurant and no matching category
                    if(x.city == city){
                        //if the city matches, then add to city specific vector
                        hasCity.push_back(x);
                        isCity = true;
                    }
                    else if(!isCity && -100 <= (myStoi(x.postalCode) - myStoi(zip)) && (myStoi(x.postalCode) - myStoi(zip))<= 100){
                        //if the city does not match, but the zipcode is close, add to zipcode specific vector
                        hasZip.push_back(x);
                        isZip = true;
                    }
                    else if(!isCity && !isZip){
                        //if there is no matching city or zipcode then it is in state
                        stateOnly.push_back(x);
                    }

                }
            }

        }

    }
    if(isCat){
        //if there are restaurants that match the selected category
        hasCity.clear();
        hasZip.clear();
        stateOnly.clear();
        isCity = false;
        isZip = false;
        for(auto j : hasCategory){
            if(j.city == city){
                //same as above but these are for the category vector
                hasCity.push_back(j);
                isCity = true;
            }
            else if(!isCity && -100 <= (myStoi(j.postalCode) - myStoi(zip)) && (myStoi(j.postalCode) - myStoi(zip))<= 100){
                hasZip.push_back(j);
                isZip = true;
            }
            else if(!isCity && !isZip){
                stateOnly.push_back(j);
            }
        }
    }
    if(isCity){
        if(isCat){
            //if it matches category and matches a city
            cout << "The restaurants returned below are in the selected city and match a category:" << endl;
        }
        else
            //if it matches only city
            cout << "The restaurants returned below are in the selected city, but do not match a category:" << endl;
        return hasCity;
    }

    else if(isZip){
        if(isCat){
            //if it matches the zipcode and a category
            cout << "The restaurants returned below are near the selected zipcode and match a category:" << endl;
        }
        else
            //only matches zipcode
            cout << "The restaurants returned below are near the selected zipcode, but do not match a category:" << endl;
        return hasZip;
    }

    else{
        if(isCat){
            //if it does not match city or zipcode and category
            cout << "The restaurants returned below are in the selected state and match a category:" << endl;
        }
        else
            //If it does not match city or zipcode
            cout << "The restaurants returned below are near the selected state, but do not match a category:" << endl;
        return stateOnly;
    }
}