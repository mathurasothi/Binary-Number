#include "binarynum.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


BinaryNum readBinaryNum() {
    string s;
    char c;
    BinaryNum b = {};
    b.capacity = 4;
    b.size = 0;
    while (1) {
        cin >> c;
        if (c != '1' && c != '0')
            break;
        b.size++;
        if (b.capacity < b.size){
            b.capacity *= 2;
        }
        s += c;
    }
    bool *barr = new bool[b.capacity];
    for (int i = 0; i<b.size; i++) {
        bool tmp;
        if (s[i] == '0') {
            tmp = 0;
        } else {
            tmp = 1;
        }
        barr[i] = tmp;
    }
    b.contents = barr;
    return b;
}



void binaryConcat(BinaryNum &binNum){
    string s;
    char c;
    int size = binNum.size;
    int capacity = binNum.capacity;
    while (1) {
        cin >> c;
        if (c != '1' && c != '0')
            break;
        size++;
        if (capacity < size)
        {
            capacity *= 2;
        }
        s += c;
    }
    binNum.capacity = capacity;
    bool *barr = new bool[capacity];
    for (int i = 0; i < binNum.size; i++) {
        barr[i] = binNum.contents[i];
    }
    int itmp = 0;
    for (int i = binNum.size; i < size; i++){
        bool tmp;
        if (s[itmp] == '0') {
            tmp = 0;
        } else {
            tmp = 1;
        }
        barr[i] = tmp;
        itmp++;
    }
    binNum.size = size;
    delete[] binNum.contents;
    binNum.contents = barr;
}



int binaryToDecimal(const BinaryNum &binNum) {
    int dec_val = 0;
    int val = 1;
    for (int i = (binNum.size - 1); i>=0; i--) {
        dec_val += binNum.contents[i] * val;
        val *= 2;
    }
    return dec_val;
}



void printBinaryNum(std::ostream &out, const BinaryNum &binNum, char sep) {
    out << binNum.contents[0] << sep;        //print out first
    for (int i = 1; i<(binNum.size - 1); i++) { //loop for in between
        out << binNum.contents[i] << sep;
    }
    out << binNum.contents[binNum.size - 1]; //print out last
}



BinaryNum &operator<<(BinaryNum &binNum, int num) {
    while ((binNum.capacity + num) < (binNum.size + num)) {
        binNum.capacity *= 2;
    }
    bool *barr = new bool[binNum.capacity];
    for (int i = 0; i < binNum.size; i++) {
        barr[i] = binNum.contents[i];
    }
    for (int i = binNum.size; i<(binNum.size + num); i++) {
        barr[i] = 0;
    }
    binNum.size += num;
    delete[] binNum.contents;
    binNum.contents = barr;
    return binNum;
}

