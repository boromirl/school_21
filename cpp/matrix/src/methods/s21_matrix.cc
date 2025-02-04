#include "../s21_matrix_oop.h"

void S21Matrix::AllocateMemory() {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{0};
  }
}

void S21Matrix::DeallocateMemory() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

// default constructor
S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  AllocateMemory();
}

// parameterized constructor
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Number of rows and columns must be positive.");
  }
  rows_ = rows;
  cols_ = cols;
  AllocateMemory();
}

// copy constructor
S21Matrix::S21Matrix(const S21Matrix& o) : rows_(o.rows_), cols_(o.cols_) {
  AllocateMemory();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
}

// move constructor
S21Matrix::S21Matrix(S21Matrix&& o) noexcept
    : rows_(o.rows_), cols_(o.cols_), matrix_(o.matrix_) {
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix_ = nullptr;
}

// init list constructor
S21Matrix::S21Matrix(int rows, int cols,
                     std::initializer_list<double> init_list) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Number of rows and columns must be positive.");
  }
  rows_ = rows;
  cols_ = cols;
  AllocateMemory();

  // Check if the size of init_list is correct
  if (init_list.size() != static_cast<size_t>(rows_ * cols_)) {
    throw std::invalid_argument(
        "Initializer list size does not match matrix dimensions.");
  }

  auto it = init_list.begin();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (it != init_list.end()) {
        matrix_[i][j] = *it;
        it++;
      }
    }
  }
}

// destructor
S21Matrix::~S21Matrix() { DeallocateMemory(); }

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::invalid_argument("Number of rows must be positive.");
  } else if (rows_ != new_rows) {
    // initialize new matrix with different amount of rows
    double** new_matrix = new double*[new_rows];
    for (int i = 0; i < new_rows; i++) {
      new_matrix[i] = new double[cols_]{0};
    }
    // copy data into new matrix
    for (int i = 0; i < std::min(rows_, new_rows); i++) {
      for (int j = 0; j < cols_; j++) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }

    // free old matrix
    DeallocateMemory();

    // set matrix to the new array
    matrix_ = new_matrix;
    rows_ = new_rows;
  }
};

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 1) {
    throw std::invalid_argument("Number of columns must be positive.");
  } else if (cols_ != new_cols) {
    // initialize new matrix with different amount of colummns
    double** new_matrix = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      new_matrix[i] = new double[new_cols]{0};
    }
    // copy data into new matrix
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < std::min(cols_, new_cols); j++) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }

    // free old matrix
    DeallocateMemory();

    // set matrix to the new array
    matrix_ = new_matrix;
    cols_ = new_cols;
  }
}

//
void S21Matrix::CopyMatrix(const S21Matrix& other) {
  SetRows(other.rows_);
  SetCols(other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}