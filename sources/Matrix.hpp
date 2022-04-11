#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

namespace zich{
    class Matrix{

        private:
            size_t row;
            size_t col;
            vector <double> mat;
            double sumOfMat() const;

        public:
            Matrix(const vector<double> &mat,const int row,const int col);
            ~Matrix();

            Matrix operator + (const Matrix &other);
            Matrix &operator += (const Matrix &other);
            Matrix &operator ++ ();
            Matrix operator ++ (const int num);
            friend Matrix operator + (Matrix &mat);

            Matrix operator - (const Matrix &other);
            Matrix &operator -= (const Matrix &other);
            Matrix &operator -- ();
            Matrix operator -- (const int num);
            friend Matrix operator - (Matrix &mat);

            Matrix operator * (const Matrix &other);
            Matrix &operator *= (const Matrix &other);
            Matrix operator * (const double num);
            Matrix &operator *= (const double num);
            friend Matrix operator *(const double num, Matrix &mat);

            bool operator > (const Matrix &other) const;
            bool operator >= (const Matrix &other) const;
            bool operator < (const Matrix &other) const;
            bool operator <= (const Matrix &other) const;
            bool operator != (const Matrix &other) const;
            bool operator == (const Matrix &other) const;

            friend ostream& operator<<(ostream &out, const Matrix &mat);
            friend istream& operator>>(istream &in, const Matrix &mat);
    };
}