#ifndef MatrixLib
#define MatrixLib

#include <stdexcept>
#include <iostream>
#include <vector>
#include "matrix.h"

Matrix::Matrix(int height, int width){
  height_ = height;
  width_ = width;
  // create an empty matrix of zeroes 
  std::vector<double> zeroes;
  for(int i = 0; i < width; i++)
    zeroes.push_back(0);
  for (int i = 0; i < height; i++)
    rows_.push_back(zeroes);
}

Matrix::Matrix(std::vector<std::vector<double>> &rows){
  if (set_data(rows) == -1)
    throw std::invalid_argument("All rows must be the same size.");
}

// multiplies a column by a provided row (represented as a vector of doubles) and returns the sum
double Matrix::multiply_col(int col, std::vector<double> &row){
  int sum = 0;
  for (int i = 0; i < height_; i++){
    sum += rows_[i][col] * row[i];
  }
  return sum;
}

// sets the data for the matrix and ensures all rows are of the same size, returns 0 if they are, if they aren't returns -1 and doesn't update the matrix
int Matrix::set_data(std::vector<std::vector<double>> &rows){
  // get the number of rows and width of the first row
  int height = rows.size();
  int width = rows[0].size();
  // validate the size of each row
  for (int i = 1; i < height; i++){
    if (rows[i].size() != width)
      return -1;
  }
  // update the matrix
  rows_ = rows;
  height_ = height;
  width_ = width;
  return 0;
}

// adds a double to each value in the matrix
void Matrix::add(double x){
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] += x;
  }
}

// adds a matrix to this matrix, returns -1 if the matrices cannot be added 
int Matrix::add(Matrix &mat){
  // ensure the other matrix is of the correct size
  if (height_ != mat.get_height() || width_ != mat.get_width())
    return -1;
  // add each number in the two matrices  
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] += *(mat.at(i, j));
  }
  return 0;
}

// subtracts a double from each value in the matrix
void Matrix::sub(double x){
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] -= x;
  }
}

// subtracts a matrix from this matrix, returns -1 if the matrices cannot be subtracted
int Matrix::sub(Matrix &mat){
  // ensure the other matrix is of the correct size
  if (height_ != mat.get_height() || width_ != mat.get_width())
    return -1;
  // add each number in the two matrices  
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] += *(mat.at(i, j));
  }
  return 0;
}

// multiplies every element in the matrix by a double 
void Matrix::multiply(double x){
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] *= x;
  }
}

// multiplies this matrix by another, raises an error if the matrices cannot be multiplied
Matrix Matrix::multiply(Matrix &mat){
  // ensure the matrices are the correct size to multiplied
  if (width_ != mat.get_height()){
    throw std::invalid_argument("Matrices are not the correct size for multiplication");
  }
  // create the matrix to store the results
  Matrix product(height_, mat.get_width());
  // perform the multiplication
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < mat.get_width(); j++)
      *(product.at(i, j)) = mat.multiply_col(j, rows_[i]);
  }
  return product;
}

// writes the matrix to an ostream, with each row seperated by a newline
void Matrix::display(std::ostream& out){
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      out << rows_[i][j] << ", ";
    out << "\n";
  }
  out << std::endl;
}

// operators
// adds a matrix to this matrix, raises an error if the matrices cannot be added 
void Matrix::operator+=(Matrix &mat){
  if (add(mat) == -1)
    throw std::invalid_argument("Invalid matrix size for addition");
}

// subtracts a matrix from this matrix, raises an error if the matrices cannot be subtracted
void Matrix::operator-=(Matrix &mat){
  if (sub(mat) == -1)
    throw std::invalid_argument("Invalid matrix size for subtraction");
}

// returns a new matrix with the provided matrix added to this one
Matrix Matrix::operator+(Matrix &mat){
  Matrix tmp(rows_);
  tmp += mat;
  return tmp;
}

// returns a new matrix with the provided matrix subtracted from this one
Matrix Matrix::operator-(Matrix &mat){
  Matrix tmp(rows_);
  tmp -= mat;
  return tmp;
}

// returns a new matrix with the provided double added to it
Matrix Matrix::operator+(double x){
  Matrix tmp = Matrix(width_, height_);
  tmp.set_data(rows_);
  tmp += x;
  return tmp;
}

// returns a new matrix with the provided double subtracted from it
Matrix Matrix::operator-(double x){
  Matrix tmp = Matrix(rows_);
  tmp -= x;
  return tmp;
}

// returns a new matrix with each element multiplied by the provided double
Matrix Matrix::operator*(double x){
  Matrix tmp = Matrix(rows_);
  tmp *= x;
  return tmp;
}

// returns the result of multiplying this matrix by another
Matrix Matrix::operator*(Matrix &mat){
  return multiply(mat);
}

// simple operators
void Matrix::operator+=(double x){add(x);}
void Matrix::operator-=(double x){sub(x);}
void Matrix::operator*=(double x){multiply(x);}

#endif