#include "Matrix.hpp"

using namespace std;

namespace zich{
    Matrix::Matrix(const vector<double> &mat, const int row, const int col) {
        if (row <= 0 || col <= 0) {
            throw invalid_argument("Matrix dimensions must be positive");
        }
        if (mat.size() != row * col) {
            throw invalid_argument("Matrix dimensions must match vector size");
        }
        this->mat = mat;
        this->row = (size_t)row;
        this->col = (size_t)col;
    }

    Matrix::~Matrix() {}

    //Addition operators (+)
    Matrix Matrix::operator + (const Matrix &other){
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        vector<double> newMat;
        for(size_t i = 0; i < this->row * this->col; i++){
            newMat.push_back(this->mat[i] + other.mat[i]);
        }
        return Matrix(newMat, this->row, this->col);
    }

    Matrix &Matrix::operator += (const Matrix &other){
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        for(size_t i = 0; i < this->row * this->col; i++){
            this->mat[i] += other.mat[i];
        }
        return *this;
    }

    Matrix &Matrix::operator ++ (){
        for(size_t i = 0; i < this->row * this->col; i++){
            this->mat[i]++;
        }
        return *this;
    }

    Matrix Matrix::operator ++ (int num){
        Matrix temp = *this;
        for(size_t i = 0; i < this->row * this->col; i++){
            this->mat[i]++;
        }
        return temp;
    }

    Matrix operator + (Matrix& mat){
        return mat;
    }

    //Subtraction operators (-)
    Matrix Matrix::operator - (const Matrix &other){
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        vector<double> newMat;
        for(size_t i = 0; i < this->row * this->col; i++){
            newMat.push_back(this->mat[i] - other.mat[i]);
        }
        return Matrix(newMat, this->row, this->col);
    }

    Matrix &Matrix::operator -= (const Matrix &other){
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        for(size_t i = 0; i < this->row * this->col; i++){
            this->mat[i] -= other.mat[i];
        }
        return *this;
    }

    Matrix &Matrix::operator -- (){
        for(size_t i = 0; i < this->row * this->col; i++){
            this->mat[i]--;
        }
        return *this;
    }

    Matrix Matrix::operator -- (int num){
        Matrix temp = *this;
        for(size_t i = 0; i < this->row * this->col; i++){
            this->mat[i]--;
        }
        return temp;
    }

    Matrix operator - (Matrix &mat)
    {
        return mat * -1;
    }

    //Multiplaction operators (*)
    Matrix Matrix::operator * (const Matrix &other){
        if (this->col != other.row) {
            throw invalid_argument("Matrices must have compatible dimensions");
        }
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++) {
            for (size_t j = 0; j < other.col; j++) {
                double sum = 0;
                for (size_t k = 0; k < this->col; k++) {
                    sum += this->mat[i * this->col + k] * other.mat[k * other.col + j];
                }
                newMat.push_back(sum);
            }
        }
        return Matrix(newMat, this->row, other.col);
    }

    Matrix &Matrix::operator *= (const Matrix &other){
        *this = (*this) * other;
        return *this;
    }

    Matrix Matrix::operator * (const double num){
        vector<double> newMat;
        for(size_t i = 0; i < this->row * this->col; i++){
            newMat.push_back(this->mat[i] * num);
        }
        return Matrix(newMat, this->row, this->col);
    }


    Matrix &Matrix::operator *= (const double num){
        *this = (*this) * num;
        return *this;
    }

    Matrix operator * (const double num, Matrix &mat){
        return mat * num;
    }
    
    //Comparison operators (>, >=, <, <=, !=, ==)
    double Matrix::sumOfMat() const{
        double sum = 0;
        for(size_t i = 0; i < this->row * this->col; i++){
            sum += this->mat[i];
        }
        return sum;
    }

    bool Matrix::operator > (const Matrix &other) const{
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        return (*this).sumOfMat() > other.sumOfMat();
    }

    bool Matrix::operator >= (const Matrix &other) const{
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        return (*this).sumOfMat() >= other.sumOfMat();
    }

    bool Matrix::operator < (const Matrix &other) const{
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        return (*this).sumOfMat() < other.sumOfMat();
    }

    bool Matrix::operator <= (const Matrix &other) const{
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        return (*this).sumOfMat() <= other.sumOfMat();
    }

    bool Matrix::operator != (const Matrix &other) const{
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        for (size_t i = 0; i < this->row * this->col ; i++)
        {
            if (this->mat[i] != other.mat[i])
            {
                return true;
            }
        }
        return false; 
    }

    bool Matrix::operator == (const Matrix &other) const{
        if(this->row != other.row || this->col != other.col){
            throw invalid_argument("Matrices must have the same dimensions");
        }
        return !((*this) != other); 
    }

    //Printing and inputting(<<, >>)
    ostream& operator<<(ostream& out, const Matrix& mat){
        for (size_t i = 0; i < mat.row; i++)
        {
            out << '[';
            for (size_t j = 0; j < mat.col; j++)
            {
                if (j != mat.col - 1)
                {
                    out << mat.mat[i * mat.col + j] << " ";
                }
                else
                {
                    out << mat.mat[i * mat.col + j];
                }
            }
            if (i != mat.row - 1)
            {
                out << "]" << endl;
            }
            else
            {
                out << ']';
            }
        }
        return out;
    }

    istream& operator>>(istream& in, const Matrix& mat){
        return in;
    }
}
