//
//  Helper.h
//  Tarea1.Recursividad
//
//  Created by Jonathan Ginsburg on 1/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea1_Recursividad__Helper__
#define __Tarea1_Recursividad__Helper__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

template <class T>
std::ostream & operator << (std::ostream & os, std::vector<T> values){
    if (values.size() == 0) {
        return os;
    }
    os << "(";
    for (int i = 0; i < values.size() - 1; ++i) {
        os << values[i] << ", ";
    }
    os << values[values.size() - 1] << ")";
    return os;
}

using namespace std;

class Helper {
public:
    template <class T>
    static std::vector<T> vectorSubtraction(const std::vector<T> & minuend, const std::vector<T> & subtrahend) {
        std::vector<T> answer = minuend;
        for (int i = 0; i < subtrahend.size(); ++i) {
            int tmpIndex = Helper::getIndexOf<T>(subtrahend[i], answer);
            if (tmpIndex == -1) continue;
            answer.erase(answer.begin() + tmpIndex);
        }
        return answer;
    }
    
    template <class T>
    static int getIndexOf(const T & object, const std::vector<T> & objects){
        int index = -1;
        for (int i = 0; i < objects.size(); ++i) {
            if (object == objects[i]) {
                index = i;
                break;
            }
        }
        return index;
    }
    
    static long double stringToLongDouble(std::string value){
        long double retVal =  0;
        try {
            retVal = std::stold(value);
        } catch (const out_of_range &invalido) {
            std::string description = "Number out of possible range...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        } catch (const std::invalid_argument &ia) {
            std::string description = "Argument is not a number...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        }
        return retVal;
    }
    
    static float stringToFloat(std::string value){
        float retVal =  0;
        try {
            retVal = std::stof(value);
        } catch (const out_of_range& invalido) {
            std::string description = "Number out of possible range...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        } catch (const std::invalid_argument & ia) {
            std::string description = "Argument is not a number...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        }
        return retVal;
    }
    
    static bool stringIsNumber(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
    
    static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    static std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
    
    static std::string readLine(std::string prompt){
        std::cout << prompt;
        std::cout.flush();
        std::string input = "";
        char character = std::cin.get();
        while (!(character <= 126 && character >= 32)) {
            character = std::cin.get();
        }
        while (character != '\n') {
            input += character;
            character = std::cin.get();
        }
        return input;
    }
    
    static void printSpace(){
        Helper::print("");
    }
    
    static int menu(std::string name, std::string options[], int availableOptions){
        Helper::print("");
        Helper::print("-----> Welcome to the " + name + " menu:");
        for (int i = 0; i < availableOptions; ++i) {
            Helper::print(options[i]);
        }
        int readValue = Helper::read<int>("Enter your choice:");
        Helper::print("");
        return readValue;
    }
    
    static std::string intToString(int integer){
        return std::to_string(integer);
    } //Converts from int to string.
    
    static std::string charToString(char character){
        std::stringstream ss;
        std::string s;
        ss << character;
        ss >> s;
        return s;
    } //Converts from a charatcter to a string.
    
    static void print(std::string message){
        std::cout << message << std::endl;
    } //Prints a message of type string.
    
    template <typename T>
    static T read(std::string prompt){
        T retVal;
        std::cout << prompt;
        std::cin >> retVal;
        
        return retVal;
    } //Reads from console and returns value.
    
    template <typename T>
    static void printMatrix(T** matrix, int rows, int columns){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } //Prints a matrix (assumes T has << operator overloaded).
    
    template <typename T>
    static T** buildMatrix(int rows, int columns){
        T** matrix = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new T[columns];
        }
        return matrix;
    } //Builds a newly allocated bidimensional array (remember to destroy).
    
    template <typename T>
    static void destroyMatrix(T** matrix, int rows, int columns){
        for (int i = 0; i < rows; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
    } //Destroys a bidimensional array.
};

#endif /* defined(__Tarea1_Recursividad__Helper__) */
