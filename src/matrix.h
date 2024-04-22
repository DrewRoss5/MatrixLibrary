#ifndef MatrixLib
#define MatrixLib

#include <iostream>
#include <vector>

class Matrix{
  private:
    int width_;
    int height_;
    std::vector<std::vector<double>> rows_;
    double multiply_col(int col, std::vector<double> &row);
  public:
    Matrix(int height, int width);
    Matrix(std::vector<std::vector<double>> &rows);
    static Matrix identiyMatrix(int size);
    int set_data(std::vector<std::vector<double>> &rows);
    void add(double x);
    int add(Matrix &mat);
    void sub(double x);
    int sub(Matrix &mat);
    void multiply(double x);
    Matrix multiply(Matrix &mat);
    void switch_row(int row1, int row2);
    void switch_col(int col1, int col2);
    void display(std::ostream &out);
    void operator+=(double x);
    void operator+=(Matrix &mat);
    void operator-=(double x);
    void operator-=(Matrix &mat);
    void operator*=(double x);
    Matrix operator+(double x);
    Matrix operator+(Matrix &mat);
    Matrix operator-(double x);
    Matrix operator-(Matrix &mat);
    Matrix operator*(double x);
    Matrix operator*(Matrix &mat);
    bool operator==(Matrix &mat);
    double* operator()(int row, int col);
    friend std::ostream& operator<<(std::ostream &out, Matrix &mat);
    // getters
    int get_height() {return height_;}
    int get_width() {return width_;}
    double* at(int row, int col) {return (row < height_ && col < width_ && col >= 0 && row >= 0) ? &rows_[row][col] : nullptr;}
};

#endif