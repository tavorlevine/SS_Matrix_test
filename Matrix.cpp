#include <iostream>
#include "Matrix.hpp"

using namespace std;

namespace zich{
    Matrix Matrix:: operator+(Matrix& other){
        return other;
    }
    Matrix Matrix:: operator-(Matrix& other){
        return other;
    }
    Matrix Matrix:: operator+=(Matrix& other){
        return other;
    }
    Matrix Matrix:: operator-=(Matrix& other){
        return other;
    }
    // plus and minus onari
    Matrix operator+(Matrix& other){
        return other;
    }
    Matrix operator-(Matrix& other){
        return other;
    }
    // copare
    bool Matrix:: operator<(const Matrix other) const{
        return false;
    }
    bool Matrix:: operator<=(const Matrix other) const{
        return false;
    }
    bool Matrix:: operator>(const Matrix other) const{
        return false;
    }
    bool Matrix:: operator>=(const Matrix other) const{
        return false;
    }
    bool Matrix:: operator==(const Matrix other) {
        return false;
    }
    bool Matrix:: operator!=(const Matrix other) const{
        return false;
    }
    Matrix& Matrix:: operator++(){
        vector<double> a = {1,1,1,1};
        static Matrix ans = Matrix(a,2,2);
        return ans;
    }
    Matrix& Matrix:: operator--(){
        vector<double> a = {1,1,1,1};
        static Matrix ans = Matrix(a,2,2);
        return ans;
    }
    Matrix& Matrix:: operator++(int ind){
        vector<double> a = {1,1,1,1};
        static Matrix ans = Matrix(a,2,2);
        return ans;
    }
    Matrix& Matrix:: operator--(int ind){
        vector<double> a = {1,1,1,1};
        static Matrix ans = Matrix(a,2,2);
        return ans;
    }
    Matrix operator*(double scalar, Matrix& other){
        return other;
    } 
    // scalar*Matrix
    Matrix Matrix:: operator*(double scalar){ // matrix*scalar
        return *this;
    }
    Matrix& Matrix:: operator*=(double scalar){
        vector<double> a = {1,1,1,1};
        static Matrix ans = Matrix(a,2,2);
        return ans;
    }
    Matrix Matrix:: operator*(Matrix& other){ // kefel matrix
        return other;
    }
    // todo:
    ostream& operator<<(ostream& os, const Matrix& other){
        return cout<< "hi" << endl;
    }
    ostream& operator>>(istream& is, const Matrix& other){
        return cin >> other << endl;
    }
}