#ifndef MatrixLib
#define MatrixLib

#include <iostream>
#include <vector>

class Matrix{
  private:
    int width_;
    int height_;
    std::vector<std::vector<double>> rows_;
    double multiply_col(int col, std::vector<double> row) const;
  public:
    Matrix(int height, int width);
    Matrix(const std::vector<std::vector<double>> &rows);
    static Matrix identiyMatrix(int size);
    void set_data(const std::vector<std::vector<double>> &rows);
    void add(double x);
    void add(Matrix &mat);
    void sub(double x);
    void sub(Matrix &mat);
    void multiply(double x);
    Matrix multiply(const Matrix &mat) const;
    void Matrix::multiply_row(int row, double x);
    void Matrix::add_row(int row, double x);
    void switch_row(int row1, int row2);
    void switch_col(int col1, int col2);
    Matrix transpose();
    bool is_identity() const;
    bool is_inverse(const Matrix &mat) const;
    void display(std::ostream &out) const;
    void operator+=(double x);
    void operator+=(Matrix &mat);
    void operator-=(double x);
    void operator-=(Matrix &mat);
    void operator*=(double x);
    Matrix operator+(double x) const;
    Matrix operator+(Matrix &mat) const;
    Matrix operator-(double x) const;
    Matrix operator-(Matrix &mat) const;
    Matrix operator*(double x) const;
    Matrix operator*(const Matrix &mat) const;
    bool operator==(const Matrix &mat) const;
    double* operator()(int row, int col);
    friend std::ostream& operator<<(std::ostream &out, const Matrix &mat);
    // getters
    int get_height() const {return height_;}
    int get_width() const {return width_;}
    double get_val(int row, int col) const;
    double* at(int row, int col) {return (row < height_ && col < width_ && col >= 0 && row >= 0) ? &rows_[row][col] : nullptr;}

};

#endif