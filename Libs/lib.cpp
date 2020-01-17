#include <iostream>
#include <fstream>
#include "lib.h"
#include "../error_codes.cpp"

using namespace std;

ifstream read_file(string filePath) {
    ifstream f;
    f.open(filePath);

    if (!f.is_open()) {
        throw EXST_ER;
    }
    if (f.peek() == EOF) {
        throw EMPT_ER;
    }
    return f;
}

void read_numbers(ifstream f, float numb[]){
    string check((istreambuf_iterator<char>(f)),
                 istreambuf_iterator<char>());
    f >> check;
    f.close();
    int i = 0;
    while ((check[i]!=' ') && (check[i]!= '\0')) {
        if (!isdigit(check[i])) {
            throw FIR_ER;
        }
        i++;
    }
    numb[0]=atoi(check.substr(0,i).c_str());
    if (check[i++] == '\0') throw EMPT_ER;
    int p = i;

    while (check[i]!='\0'){
        if (!isdigit(check[i])){
            throw SEC_ER;
        }
        i++;
    }
    numb[1]=atoi(check.substr(p,i-p).c_str());
}

float div_numbers(float a, float b) {
    if (b == 0) {
        throw DIV_ER;
    }
    return a / b;
}