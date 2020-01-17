#include "gtest/gtest.h"
#include <fstream>
#include "lib.h"
#include <iostream>
#include "error_codes.cpp"

//Тест функции работы с файлом
TEST(read_file, EmptyFile){
    int er = 0;
    try{
        read_file("../empty_f");
    }
    catch(int& err){ er = err;}

    EXPECT_EQ(10111110, er);

}
TEST(read_file, ExistFile){
    int er = 0;
    try{
        read_file("./numbers_f.txt");
    }
    catch(int& err){ er = err;}
    EXPECT_EQ(1000101, er);
}
//Тест функции чтения чисел из файла
TEST(read_numbers, FirsBadNumber){
    float ar[2];
    int er = 0;
    try {
        read_numbers(read_file("../first_n"), ar);
    }
    catch(int& err){ er = err;}
    EXPECT_EQ(101001, er);
}
TEST(read_numbers, SecondBadNumber){
    float ar[2];
    int er = 0;
    try {
        read_numbers(read_file("../second_n"), ar);
    }
    catch(int& err){ er = err;}
    EXPECT_EQ(101101, er);
}
TEST(read_numbers, OneNumber){
    float ar[2];
    int er = 0;
    try {
        read_numbers(read_file("../one_n_f"), ar);
    }
    catch(int& err){ er = err;}
    EXPECT_EQ(10111110, er);
}
TEST(read_numbers, NormalNumbers){
    float ar[2];
    float check[2] = {145, 5};
    read_numbers(read_file("../numbers.txt"), ar);
    EXPECT_EQ(check[0], ar[0]);
    EXPECT_EQ(check[1], ar[1]);
}

//Тест функции деления чисел

TEST(div_numbers, DivisionOnZero){
    float a = 2;
    float b = 0;
    int er = 0;
    try {
        float res = div_numbers(a, b);
    }
    catch(int& err){ er = err;}
    EXPECT_EQ(10001010, er);
}
TEST(div_numbers, NormalDivision){
    float a = 4;
    float b = 2;
    EXPECT_EQ(2, div_numbers(a, b));
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Russian");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}