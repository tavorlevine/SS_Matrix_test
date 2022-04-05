# include <iostream>
# include <vector>
#include <stdexcept>

using namespace std;

namespace zich{
class Matrix{
    private:
        int column;
        int row;
        vector<double> mat;
    public:
        Matrix(vector<double> mat, int col, int row){
            //good_input(col,row);
            this->column = col;
            this->row = row; 
            this->mat = mat;
        };
        int getCol(){
            return column;
        };
        int getRow(){
            return row;
        };
        // bool good_input(int col, int row){
        //     if (col<=0 || row<=0){
        //         //throws runtime_error("row and column must be positive");
        //     }
        // };
        // std::vector getData(){
        //     return this->mat;
        // }
        int sumMatrix(Matrix mat);
        Matrix operator+(Matrix& other);
        Matrix operator-(Matrix& other);
        Matrix operator+=(Matrix& other);
        Matrix operator-=(Matrix& other);
        // plus and minus onari
        friend Matrix operator+(Matrix& other);
        friend Matrix operator-(Matrix& other);
        // copare
        bool operator<(const Matrix other) const;
        bool operator<=(const Matrix other) const;
        bool operator>(const Matrix other) const;
        bool operator>=(const Matrix other) const;
        bool operator==(const Matrix other);
        bool operator!=(const Matrix other) const;
        Matrix& operator++();
        Matrix& operator--();
        Matrix& operator++(int ind);
        Matrix& operator--(int ind);
        friend Matrix operator*(const double scalar,Matrix &other); // scalar*Matrix
        Matrix operator*(double scalar); // matrix*scalar
        Matrix& operator*=(double scalar); //matrix*=scalar
        Matrix operator*(Matrix& other); // matrix*matrix
        // todo:
        friend ostream& operator<<(ostream& os, const Matrix& other);
        friend ostream& operator>>(istream& is, const Matrix& other);      
};
}