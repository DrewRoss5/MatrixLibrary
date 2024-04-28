# MatrixLibrary
A Matrix Library written in C++

## Roadmap/ToDo
- Add matrix transposition

## API 
### The Matrix Class:
The Matrix class represents a two-dimensional matrix of any size. Matrices use zero-based indexing. 
#### Constructors:
`Matrix(int height, int width)`<br>
  &nbsp;&nbsp;&nbsp;&nbsp;Creates a Matrix with it's dimensions set to the provided height and width, all elements default to zero.
  
`Matrix(const vector<vector<double>> &rows)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Creates a Matrix from nested vectors of double representing rows. This will raise an error if all the vectors are not the same size.
#### Public Functions:
`void set_data(const vector<vector<double>>)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Sets the Matrix's elements with nested vectors of doubles. Each vector represents a row. If the rows are not all the same size, this will raise an error, and not update the Matrix.

`void add(double x)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Adds the value of `x` to each element in the Matrix. Can also be called with the `+` and `+=` operators.

`void add(const Matrix &mat)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Adds the provided to matrix to this one, raises an error if the matrices can not be added. Can also be called with the `+` and `+=` operators (these operators will throw an error if the matrices cannot be added).

`void sub(double x)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Subtracts the value of `x` from each element in the Matrix. Can also be called with the `-` and `-=` operators.

`void sub(const Matrix &mat)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Subtracts the provided to matrix from this one, raises an error if the matrices can not be added. Can also be called with the `-` and `-=` operators (these operators will throw an error if the matrices cannot be added).

`void multiply(double x)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Multiplies each element in the matrix by the value of `x`. Can also be called with the `*` and `*=` operators. 

`Matrix multiply(const Matrix &mat)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Returns the result of multiplying this Matrix by `mat`. Raises an error if the matrices cannot be multiplied. Can also be called with the `*` operator. 

`void swtich_row(int row1, int row2)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Switches all of the elements in the row of index `row1` with those in the row of index `row2`. Raises an error if either parameter is out of bounds.

`void switch_col(int col1, int col2)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Switches all of the elements in the column of index `col1` with those in the column of index `col2`. Raises an error if either parameter is out of bounds.

`void display(ostream &out)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Writes the contents of the matrix to `out` with each column seperated with a comma, and each row seperated with a new line. Can also be called with the `<<` operator.

`int get_height()`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Returns the height of the matrix.

`int get_width()`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Returns the width of the matrix.

`double get_val(int row, int col)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Returns the value of the element in row `row` and column `col`, raises an error if either parameter is out of bounds.

`double* at(int row, int col)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;Returns a mutable pointer to the element in row `row` and column `col`, or a `nullptr` if either parameter is out of bounds. Can also be called with `()` operator. For example, the pointer of the first element a matrix called `my_matrix` could be retrived with the following: `my_matrix(0, 0)`;







