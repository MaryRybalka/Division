#include <iostream>
#include <fstream>
#include "lib.h"
#include "../error_codes.cpp"
using namespace std;

int main() {
    try{
        float ar[2];
        read_numbers(read_file("../numbers.txt"), ar);
        cout << "Res: " << div_numbers(ar[0], ar[1]);
    }
    catch(int& err){
        switch (err){
            case EXST_ER:
                cout << "File does not exist or you have not allow." << endl;
                break;
            case EMPT_ER:
                cout << "File is empty or contains less numbers than you need." << endl;
                break;
            case DIV_ER:
                cout << "You can't division number on zero!"<< endl;
                break;
            case FIR_ER:
                cout << "First number isn't number"<< endl;
                break;
            case SEC_ER:
                cout << "Second number isn't number";
        }
    }
    return 0;
}
