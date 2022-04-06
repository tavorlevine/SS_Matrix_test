#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

 //* AUTHORS: <Tavor Levine>

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}



TEST_CASE("size of matrix"){
    for (double i=0; i<10; i++){
        vector<double>a = {i,i,i,i,i,i};
        Matrix ans = zich::Matrix{a,3,2};
        vector<double>b = {i,i,i,i,i,i};
        Matrix check = zich::Matrix{b,2,3};
        // check some operators
        CHECK_THROWS(ans + check);
        CHECK_THROWS(ans * check);
        CHECK_THROWS(ans < check);
        CHECK_THROWS(ans == check);

    }
    
}
TEST_CASE("constractor"){
    vector<double> a = {1,0,0,0,1,0,0,0,1};
    CHECK_NOTHROW(Matrix(a,3,3));
    CHECK_THROWS(Matrix(a,3,4));
    CHECK_THROWS(Matrix(a,-1,4));
}
TEST_CASE("operator +") {
    for (double i=0; i < 10; i++){
        vector<double> a = {i,0,0,0,i,0,0,0,i};
        Matrix ans = Matrix{a,3,3};
        vector<double> b = {2*i,0,0,0,2*i,0,0,0,2*i};
        Matrix check = Matrix(b,3,3);
        CHECK(((ans+ans) == check));
    }
}
TEST_CASE("operator -"){
    for(double i=0; i<10; i++){
        vector<double> a = {i,0,0,0,i,0,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {0,0,0,0,0,0,0,0,0};
        Matrix check = zich::Matrix(b,3,3);
        CHECK((ans-ans == check));

    }    
}
TEST_CASE("operator +=" ){
    for (double i=0; i < 10; i++){
        vector<double> a = {i,0,0,0,i,0,0,0,i};
        Matrix ans = Matrix{a,3,3};
        vector<double> b = {2*i,0,0,0,2*i,0,0,0,2*i};
        Matrix check = Matrix(b,3,3);
        CHECK(((ans+=ans) == check));
    }
}
TEST_CASE("operator -="){
    for(double i=0; i<10; i++){
        vector<double> a = {i,0,0,0,i,0,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {0,0,0,0,0,0,0,0,0};
        Matrix check = zich::Matrix(b,3,3);
        CHECK(((ans-=ans) == check));
    }    
}
TEST_CASE("operator <"){
    for (double i=0; i<10; i++){
        vector<double> a = {i,0,0,0,i,0,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {10,0,0,10,0,0,0,0,10};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans<check), true);
    }
    for (double i=0; i<10; i++){
        vector<double> a = {3*i,0,0,0,3*i,0,0,0,2*i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,0,0,2*i,0,i,0,0,2*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans<check), false);
    }
}    

TEST_CASE("operator <=") {
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {10,5,0,10,0,0,5,0,10};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans<check), true);
    }
    for (double i=1; i<10; i++){
        vector<double> a = {3*i,0,0,3*i,0,i,0,0,2*i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,i,0,2*i,0,0,0,0,2*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans<check), false);
    }

} 

TEST_CASE("operator >") {
    for (double i=10; i<=15; i++){
        vector<double> a = {i,i,0,i,0,i,i,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {10,5,0,10,0,0,5,0,10};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans>check), true);
    }
    for (double i=1; i<10; i++){
        vector<double> a = {3*i,0,0,3*i,0,i,0,0,2*i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,i,0,2*i,0,0,0,0,2*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans>check), false);
    }
}

TEST_CASE("operator >=") {
    for (double i=10; i<=15; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {10,0,0,10,0,0,0,0,10};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans>=check), true);
    }
    for (double i=0; i<10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,2*i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,3*i,0,2*i,0,3*i,0,0,2*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans>=check), false);
    }

}
TEST_CASE("operator ==") {
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,0,0,i,i,0,0,i,0};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans==check), true);
    }
}
TEST_CASE("operator !="){ 
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,0,0,i,i,0,0,i,0};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans!=check), false);
    }   
    for (double i=1; i<10; i++){
        vector<double> a = {3*i,0,0,3*i,0,i,0,0,2*i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i,i,0,2*i,0,0,0,0,2*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((ans!=check), true);
    }
}   
TEST_CASE("operator ++()") {
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i+1,0,0,i+1,0,i+1,0,0,i+1};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((ans++) == check)), true);
    }
} 
TEST_CASE("operator --()") {
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i+1,0,0,i+1,0,i+1,0,0,i+1};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((check--) == ans)), true);
        CHECK_EQ((((ans--) == check)), false);
    }
}
TEST_CASE("operator ++(ind)") { // ++ first 
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i+1,0,0,i+1,0,i+1,0,0,i+1};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((++ans) == check)), true);
        CHECK_EQ((((++check) == ans)), false);
    }
}
TEST_CASE("operator --()") { // -- first
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {i+1,0,0,i+1,0,i+1,0,0,i+1};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((--check) == ans)), true);
        CHECK_EQ((((--ans) == check)), false);
    }
}
TEST_CASE("operator *") { //scalar*matrix
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {4*i,0,0,4*i,0,4*i,0,0,4*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((4*ans) == check)), true);
        CHECK_EQ((((5*ans) == check)), false);
    }
}
TEST_CASE("operator *") { //matrix*scalar
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {4*i,0,0,4*i,0,4*i,0,0,4*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((ans*4) == check)), true);
        CHECK_EQ((((ans*5) == check)), false);
    }
}
TEST_CASE("operator *=") { //matrix*=scalar
    for (double i=0; i<=10; i++){
        vector<double> a = {i,0,0,i,0,i,0,0,i};
        Matrix ans = zich::Matrix{a,3,3};
        vector<double> b = {4*i,0,0,4*i,0,4*i,0,0,4*i};
        Matrix check = zich::Matrix(b,3,3);
        CHECK_EQ((((ans*=4) == check)), true);
        CHECK_EQ((((ans*=5) == check)), false);
    }
}
TEST_CASE("operator *") { //matrix*matrix
    vector<double> v1 = {1,1,1,1};
    vector<double> v2 = {2,2,2,2};
    vector<double> v3 = {3,3,3,3,3,3};
    vector<double> v4 = {12,12,12,12,12,12};
    Matrix m1 = Matrix(v1,2,2);
    Matrix m2 = Matrix(v2,2,2);
    Matrix m3 = Matrix(v3,2,3);
    Matrix m4 = Matrix(v3,3,2);
    Matrix m5 = Matrix(v4,3,2);
    CHECK_EQ(m2*m4 == m5, true);
    CHECK_EQ(m1*m3 == m3,true);
    CHECK_EQ(m1*m2 == m1,false); 
    CHECK_THROWS(m5*m2);
    CHECK_THROWS(m4*m4);
}



