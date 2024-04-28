#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
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

Matrix::Matrix(const std::vector<std::vector<double>> &rows) {set_data(rows);}

// generates a square identity matrix of a provided size
Matrix Matrix::identiyMatrix(int size){
  Matrix mat = Matrix(size, size);
  for(int i = 0; i < size; i++){
    *(mat(i, i)) = 1;
  }
  return mat;

}

// multiplies a column by a provided row (represented as a vector of doubles) and returns the sum
double Matrix::multiply_col(int col, std::vector<double> row) const{
  int sum = 0;
  for (int i = 0; i < height_; i++){
    sum += rows_[i][col] * row[i];
  }
  return sum;
}

// sets the data for the matrix and ensures all rows are of the same size, returns 0 if they are, if they aren't returns -1 and doesn't update the matrix
void Matrix::set_data(const std::vector<std::vector<double>> &rows){
  // get the number of rows and width of the first row
  int height = rows.size();
  int width = rows[0].size();
  // validate the size of each row
  for (int i = 1; i < height; i++){
    if (rows[i].size() != width)
      throw std::invalid_argument("Vector is of incorrect size.");
  }
  // update the matrix
  rows_ = rows;
  height_ = height;
  width_ = width;
}

// adds a double to each value in the matrix
void Matrix::add(double x){
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] += x;
  }
}

// adds a matrix to this matrix, returns -1 if the matrices cannot be added 
void Matrix::add(Matrix &mat){
  // ensure the other matrix is of the correct size
  if (height_ != mat.get_height() || width_ != mat.get_width())
    throw std::out_of_range("Invalid row dimensions");
  // add each number in the two matrices  
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] += *(mat(i, j));
  }
}

// subtracts a double from each value in the matrix
void Matrix::sub(double x){add(x * -1);}

// subtracts a matrix from this matrix, returns -1 if the matrices cannot be subtracted
void Matrix::sub(Matrix &mat){
  // ensure the other matrix is of the correct size
  if (height_ != mat.get_height() || width_ != mat.get_width())
    throw std::out_of_range("Invalid row dimensions");
  // add each number in the two matrices  
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] -= *(mat(i, j));
  }
}

// multiplies every element in the matrix by a double 
void Matrix::multiply(double x){
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      rows_[i][j] *= x;
  }
}

// multiplies this matrix by another, raises an error if the matrices cannot be multiplied
Matrix Matrix::multiply(const Matrix &mat) const{
  // ensure the matrices are the correct size to multiplied
  if (width_ != mat.get_height()){
    throw std::invalid_argument("Matrices are not the correct size for multiplication");
  }
  // create the matrix to store the results
  Matrix product(height_, mat.get_width());
  // perform the multiplication
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < mat.get_width(); j++)
      *(product(i, j)) = mat.multiply_col(j,  rows_[i]);
  }
  return product;
}

// multiplies each element in a given row by a double, raises an error if the row is out of bounds
void Matrix::multiply_row(int row, double x){
  // ensure the row is in bounds
  if (row >= height_ || row < 0)
    throw std::out_of_range("Row index out of range");
  // multiply each element by x
  for (int i = 0; i < width_; i++)
    rows_[row][i] *= x;
}

// adds a doubl to each element in a given row, raises an error if the row is out of bounds
void Matrix::add_row(int row, double x){
  // ensure the row is in bounds
  if (row >= height_ || row < 0)
    throw std::out_of_range("Row index out of range");
  // add x to each element in the row
  for (int i = 0; i < width_; i++)
    rows_[row][i] += x;
}

// switches two rows in the matrix, throwing an error either is out of bounds
void Matrix::switch_row(int row1, int row2){
  if (row1 < 0 || row2 < 0 || row1 >= height_ || row2 >= height_)
    throw std::invalid_argument("Provided row(s) are out of bounds");
  std::vector<double> tmp = rows_[row1];
  rows_[row1] = rows_[row2];
  rows_[row2] = tmp;

}

// switches two columns in the matrix, throwing an error either is out of bounds
void Matrix::switch_col(int col1, int col2){
    if (col1 < 0 || col2 < 0 || col1 >= width_ || col2 >= width_)
      throw std::invalid_argument("Provided columns(s) are out of bounds");
    double tmp;
    for(int i = 0; i < height_; i++){
      tmp = rows_[i][col1];
      rows_[i][col1] = rows_[i][col2];
      rows_[i][col2] = tmp;
    }
}

Matrix Matrix::transpose(){
  // create a matrix to return as the transposed matrix
  Matrix result(width_, height_);
  // place each element in the transposed matrix
  for (int i = 0; i < height_; i++){
    for(int j = 0; j < width_; j++)
      *(result(j, i)) = rows_[i][j];
  }
  return result;
}

// returns true if the Matrix is an identity matrix, otherwise, false
bool Matrix::is_identity() const{
  // ensure the matrix is square 
  if (width_ != height_)
    return false;
  // ensure that the ith element, and only the ith element of each row is 1
  for (int i = 0; i < height_; i++){
    // ensure the ith element is 1
    if (rows_[i][i] != 1)
      return false;
    // ensure all other elements are 0
    for (int j = 0; j < width_; j++){
      if (rows_[i][j] != 0 && j != i)
        return false;
    }
  }
  return true;
}

// returns true if this matrix is and inverse of the provided matrix, otherwise, false
bool Matrix::is_inverse(const Matrix &mat) const{
  // ensure both matrices are square 
  if (width_ != height_ || mat.get_width() != width_ || mat.get_height() != height_)
    return false;
  // ensure the matrices multiply to identiy matrices
  Matrix product1 = multiply(mat);
  Matrix product2 = mat * *this;
  return product1.is_identity() && product2.is_identity();
}

// writes the matrix to an ostream, with each row seperated by a newline
void Matrix::display(std::ostream& out) const{
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++)
      out << rows_[i][j] << ", ";
    out << "\n";
  }
  out << std::endl;
}

// operators
// returns a new matrix with the provided matrix added to this one
Matrix Matrix::operator+(Matrix &const mat) const{
  Matrix tmp(rows_);
  tmp += mat;
  return tmp;
}

// returns a new matrix with the provided matrix subtracted from this one
Matrix Matrix::operator-(Matrix &mat) const{
  Matrix tmp(rows_);
  tmp -= mat;
  return tmp;
}

// returns a new matrix with the provided double added to it
Matrix Matrix::operator+(double x) const{
  Matrix tmp = Matrix(width_, height_);
  tmp.set_data(rows_);
  tmp += x;
  return tmp;
}

// returns a new matrix with the provided double subtracted from it
Matrix Matrix::operator-(double x) const{
  Matrix tmp = Matrix(rows_);
  tmp -= x;
  return tmp;
}

// returns a new matrix with each element multiplied by the provided double
Matrix Matrix::operator*(double x) const{
  Matrix tmp = Matrix(rows_);
  tmp *= x;
  return tmp;
}

// returns the result of multiplying this matrix by another
Matrix Matrix::operator*(const Matrix &mat) const{
  return multiply(mat);
}

// returns if two matrices are equal to eachother (that is, they are the same size and each value is the same)
bool Matrix::operator==(const Matrix &mat) const{
  // validate that the sizes are the same
  if (height_ != mat.get_height() || width_ != mat.get_width())
    return false;
  for (int i = 0; i < height_; i++){
    for (int j = 0; j < width_; j++) {
      if (rows_[i][j] != mat.get_val(i, j))
        return false;
    }
  }
}

std::ostream& operator<<(std::ostream &out, const Matrix &mat){
  mat.display(out);
  return out;
}

// simple operators
void Matrix::operator+=(double x){add(x);}
void Matrix::operator+=(Matrix &mat) {add(mat);}
void Matrix::operator-=(double x){sub(x);}
void Matrix::operator-=(Matrix &mat) {sub(mat);}
void Matrix::operator*=(double x){multiply(x);}
double* Matrix::operator()(int row, int column){return at(row, column);}

// getter 
double Matrix::get_val(int row, int col) const{
  if (row >= height_ || col >= width_ || col < 0 || row < 0)
    throw std::invalid_argument("Invalid element index");
  return rows_[row][col];
}
