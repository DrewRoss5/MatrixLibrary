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

// test to ensure that doubles are added to rows correctly
TEST(MatrixRowOperations, AddRow){
    std::vector<std::vector<double>> v1 = {{1, 1, 1}, {2, 2, 2}};
    std::vector<std::vector<double>> v2 = {{0, 1, 2}, {3, 4, 5}};
    std::vector<std::vector<double>> result1 = {{1, 1, 1}, {3, 3, 3}};
    std::vector<std::vector<double>> result2 = {{0, 1, 2}, {3.5, 4.5, 5.5}};
    // ensure values are correctly added to each row
    Matrix m1(v1);
    Matrix m2(v2);
    m1.add_row(1, 1);
    m2.add_row(1, 0.5);
    EXPECT_EQ(m1, Matrix(result1));
    EXPECT_EQ(m2, Matrix(result2));    

}

// test to ensure that rows are correctly multiplied by doubles
TEST(MatrixRowOpperations, MultiplyRow){
    std::vector<std::vector<double>> v1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> v2 = {{10, 15, 20}, {25, 30, 35}};
    std::vector<std::vector<double>> result1 = {{2, 4, 6}, {4, 5, 6}};
    std::vector<std::vector<double>> result2 = {{0, 0, 0}, {25, 30, 35}};
    Matrix m1(v1);
    Matrix m2(v2);
    m1.multiply_row(0, 2);
    m2.multiply_row(0, 0);
    EXPECT_EQ(m1, Matrix(result1));
    EXPECT_EQ(m2, Matrix(result2));
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

// test to ensure matrices are transposed properly
TEST(OtherMatrixOperations, Transpose){
    std::vector<std::vector<double>> v1 = {{11, 3}, {4, 10}};
    std::vector<std::vector<double>> v2 = {{10, 15, 16}, {20, 25, 26}};
    std::vector<std::vector<double>> result1 = {{11, 4}, {3, 10}};
    std::vector<std::vector<double>> result2 = {{10, 20}, {15, 25}, {16, 26}};
    Matrix m1(v1);
    Matrix m2(v2);
    EXPECT_EQ(m1.transpose(), Matrix(result1));
    EXPECT_EQ(m2.transpose(), Matrix(result2));
}

// test to ensure identity matrices are detected properly
TEST(OtherMatrixOperations, VerifyIdentiyMatrices){
    std::vector<std::vector<double>> v1 = {{2, 4, 6}, {8, 10, 12}};
    std::vector<std::vector<double>> v2  = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix m1(v1);
    Matrix m2(v2);
    Matrix m3 = Matrix::identiyMatrix(3);
    EXPECT_FALSE(m1.is_identity());
    EXPECT_TRUE(m2.is_identity());
    EXPECT_TRUE(m2.is_identity());

}

// test to ensure inverse matrices are detected properly
TEST(OtherMatrixOperations, VerifyInverseMatrices){
    std::vector<std::vector<double>> v1 = {{2, 0, -1}, {5, 1, 0}, {0, 1, 3}};
    std::vector<std::vector<double>> v2  = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    std::vector<std::vector<double>> v3 = {{3, -1, 1}, {-15, 6, -5}, {5, -2, 2}};
    Matrix m1(v1);
    Matrix m2(v2);
    Matrix m3(v3);
    EXPECT_FALSE(m1.is_inverse(m2));
    EXPECT_TRUE(m1.is_inverse(m3));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}