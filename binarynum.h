#ifndef BINARYNUM_H
#define BINARYNUM_H

#include <iostream>

struct BinaryNum {
  int size;        
  int capacity;     
  bool *contents;   
};

BinaryNum readBinaryNum(); 
void binaryConcat(BinaryNum &binNum); 
int binaryToDecimal(const BinaryNum &binNum); 
void printBinaryNum(std::ostream &out, const BinaryNum &binNum, char sep); 
BinaryNum &operator<<(BinaryNum &binNum, int num);

#endif
