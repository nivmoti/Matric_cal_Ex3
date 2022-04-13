#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
namespace zich
{
    class Matrix
    {
    private:
        vector<vector<double>> ve;
        int row,col;
        double sum=0;
    public:
     
        Matrix();
        Matrix (const vector<double> &ve,const int &rows,const int &cols);
        Matrix(const Matrix &other);
        ~Matrix ();
        void SetMatrix(const vector<double> &ve,const int &rows,const int &cols,Matrix& s) const;
        Matrix& operator=(const Matrix &other );
        Matrix  operator -()const;
        Matrix  operator +()const;
        Matrix  operator -(const Matrix &other)const;
        Matrix  operator +(const Matrix &other)const ;
        Matrix  operator*(const Matrix &other)const;
        Matrix  operator*(const int &num)const; 
        void CheckSum();
        friend std::ostream &operator<<(std::ostream &os, const Matrix &m) {
          for (unsigned long i=0; i < m.row; ++i) {
           os<<'[';
           for (unsigned long j=0; j < m.col; ++j) {
             if(j==m.col-1){os << m.ve[i][j];}
             else{os << m.ve[i][j] <<" ";}
              }
            os<<']';
            if(i!=m.row-1){
            os <<'\n';
            }
           }
           
            return os;
          }
          
        friend  Matrix operator *(const int & num,const Matrix &m)
        {
          return (m*num);
        }
        friend Matrix operator +(const int &num,const Matrix &t)
        {
          return (num+t);
        }
        Matrix& operator*=(const Matrix &other);
        Matrix& operator*=(const int &num);
        Matrix& operator+=(const Matrix &other);
        Matrix& operator-=(const Matrix &other);
        bool operator!() const;
        friend bool operator==(const Matrix& c1, const Matrix& c2);
        friend bool operator!=(const Matrix& c1, const Matrix& c2);
        friend bool operator>(const Matrix& c1, const Matrix& c2);
        friend bool operator>=(const Matrix& c1, const Matrix& c2);
        friend bool operator<=(const Matrix& c1, const Matrix& c2);
        friend bool operator<(const Matrix& c1, const Matrix& c2);
        Matrix& operator++();
        Matrix operator++(int);
         Matrix& operator--();
         Matrix operator--(int);
          friend istream& operator>>(istream& input, Matrix& source);
        
    };
    
    
    
} // namespace zich