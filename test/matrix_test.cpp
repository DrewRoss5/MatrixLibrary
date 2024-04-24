#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "../src/matrix.h"

// test to ensure matrix addition works properly, both with other matrices, and with doubles
TEST(MatrixArtihmeticOperations, Addition){
    std::vector<std::vector<double>> v1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> v2 = {{2, 4 ,6}, {8, 10, 12}, {14, 16, 18}};
    std::vector<std::vector<double>> result1 = {{3, 6, 9}, {12, 15, 18}, {21, 24, 27}};
    std::vector<std::vector<double>> result2 = {{1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}, {7.5, 8.5, 9.5}};
    Matrix m1(v1);
    Matrix m2(v2);
    // test addition of two matrices
    EXPECT_EQ(m1 + m2, Matrix(result1));
    // test addition of a matrix and a double
    EXPECT_EQ(m1 + 0.5, Matrix(result2));

}


// test to ensure matrix subtraction works properly, both with other matrices, and with doubles
TEST(MatrixArithmeticOperations, Subtraction){
    std::vector<std::vector<double>> v1 = {{1, 3, 5}, {7, 9, 11}};
    std::vector<std::vector<double>> v2 = {{0, 2, 4}, {6, 8, 10}};
    std::vector<std::vector<double>> result1 = {{1, 1, 1}, {1, 1, 1}};
    std::vector<std::vector<double>> result2 = {{0.5, 2.5, 4.5}, {6.5, 8.5, 10.5}};
    Matrix m1(v1);
    Matrix m2(v2);
    // test the subtraction of two matrices
    EXPECT_EQ(m1 - m2, Matrix(result1));
    // test the subtraction of a double from a Matrix
    EXPECT_EQ(m1 - 0.5, Matrix(result2));
    
}

// test to ensure matrix multiplication works properly, both with other matrices, and with doubles, this also tests identity matrices
TEST(MatrixArithmeticOperations, Multiplication){
    std::vector<std::vector<double>> v1 = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    std::vector<std::vector<double>> v2  = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    std::vector<std::vector<double>> result1 = {{108, 132, 156}, {234, 294, 354}, {360, 456, 552}};
    std::vector<std::vector<double>> result2 = {{4, 8, 12}, {16, 20, 24}, {28, 32, 36}};
    Matrix m1(v1);
    Matrix m2(v2);
    Matrix m3 = Matrix::identiyMatrix(3);
    // test the multiplication of two matrices
    EXPECT_EQ(m1 * m2, Matrix(result1));
    // test the multiplication of a matrix with an identity Matrix
    EXPECT_EQ(m1 * m3, m1);
    // test the multiplication of a matrix with a double
    EXPECT_EQ(m1 * 2, Matrix(result2));

}

// test to ensure rows switch properly
TEST(OtherMatrixOperations, SwitchRows){
    std::vector<std::vector<double>> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    std::vector<std::vector<double>> result1 = {{3, 3, 3}, {2, 2, 2}, {1, 1, 1}};
    Matrix m1(v1);
    m1.switch_row(0, 2);
    EXPECT_EQ(m1, Matrix(result1));
    
}

// test to ensure columns switch properly
TEST(OtherMatrixOperations, SwitchColumns){
    std::vector<std::vector<double>> v1 = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    std::vector<std::vector<double>> result1 = {{1, 3, 2}, {1, 3, 2}, {1, 3, 2}};
    Matrix m1(v1);
    m1.switch_col(1, 2);
    EXPECT_EQ(m1, Matrix(result1));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}