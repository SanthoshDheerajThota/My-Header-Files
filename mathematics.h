//this header file has all basic operations of complex rational and matrix data types
//This is compltely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class Complex{
    private:
        int real;
        int imag;
    public :
        void setData();
        void printData();
        Complex operator+(Complex c);
        Complex operator *(Complex c);
        friend ostream &operator<<(ostream &output,Complex c);
        friend istream &operator>>(istream &input,Complex &c);
};
class Rational{
    private:
        int numerator;
        int denominator;
    public :
        void setData();
        void printData();
        Rational operator+(Rational c);
        Rational operator *(Rational c);
        friend ostream &operator<<(ostream &output,Rational c);
        friend istream &operator>>(istream &input,Rational &c);
};
class Matrix {
    private:
        int **matrix;
        int rows;
        int columns;
    public :
        Matrix();
        Matrix(int a ,int b);
        void setData();
        void printData();
        Matrix operator+(Matrix c);
        Matrix operator *(Matrix c);
        friend ostream &operator<<(ostream &output,Matrix c);
        friend istream &operator>>(istream &input,Matrix &c);      
};
void Complex::setData(){
    cout<<"enter the real and imaginary part of the complex number :"<<endl;
    cin>>this->real>>this->imag;
}
void Complex:: printData(){
    cout<<this->real<<" + "<<this->imag<<" i "<<endl;
}
Complex Complex::operator+(Complex c){
    Complex answer;
    answer.real=this->real+c.imag;
    answer.imag=this->imag+c.imag;
    return answer;
}
Complex Complex:: operator *(Complex c){
    Complex answer;
    answer.real=this->real*real-this->imag*c.imag;
    answer.imag=this->real*c.imag+this->imag*c.real;
    return answer;
}
ostream & operator<<(ostream &output,Complex c){
    output<<c.real<<" + "<<c.imag<<" i "<<endl;
    return output;
}
istream & operator>>(istream &input,Complex &c){
    cout<<"enter the real and imaginary part of the complex number :"<<endl;
    input>>c.real>>c.imag;
    return input;
}


void Rational::setData(){
    cout<<"enter the numerator and denominator :"<<endl;
    cin>>this->numerator>>this->denominator;
}
void Rational:: printData(){
    cout<<this->numerator<<" / "<<this->denominator<<endl;
}
Rational Rational::operator+(Rational c){
    Rational answer;
    answer.numerator=this->numerator*c.denominator+c.numerator*this->denominator;
    answer.denominator=this->denominator*c.denominator;
    return answer;
}
Rational Rational :: operator *(Rational c){
    Rational answer;
    answer.numerator=this->numerator*c.numerator;
    answer.denominator=this->denominator*this->denominator;
    return answer;
}
ostream &operator<<(ostream &output,Rational c){
    output<<c.numerator<<" / "<<c.denominator<<endl;
    return output;
}
istream &operator>>(istream &input,Rational &c){
    cout<<"enter the numerator and denominator :"<<endl;
    input>>c.numerator>>c.denominator;
    return input;
}

Matrix ::Matrix(){
    matrix=new int *;
    rows=columns=0;
}
Matrix ::Matrix(int a ,int b){
    matrix=new int *;
    rows=a;
    columns=b;
    for(int i=0;i<rows;i++){
        matrix[i]=new int[columns];
    }
}
void Matrix::setData(){
    cout<<"enter the number of rows and columns :"<<endl;
    cin>>rows>>columns;
    matrix=new int*;
    for(int i=0;i<rows;i++){
        matrix[i]=new int[columns];
    }
    cout<<"enter the elements of the Matrix :"<<rows*columns<<" number of elements :"<<endl;
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            cin>>matrix[i][j];
        }
    }
    return;
}
void Matrix::printData(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
}
Matrix Matrix::operator+(Matrix c){
     Matrix answer(rows,columns);
    if(!(rows==c.rows&&columns==c.columns)){
        cout<<"matrix addition is not at all possible "<<endl;
        return answer;
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            answer.matrix[i][j]=matrix[i][j]+c.matrix[i][j];
        }
    }
    return answer;
}
Matrix Matrix::operator *(Matrix c){
    Matrix answer(this->rows,c.columns);
    if(this->columns!=c.rows){
        cout<<"matrix multiplication is not possible "<<endl;
        return answer;
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<c.columns;j++){
            answer.matrix[i][j]=0;
            for(int k=0;k<this->columns;k++){
                answer.matrix[i][j]=answer.matrix[i][j]+matrix[i][k]*c.matrix[k][j];
            }
        }
    }
    return answer;
}
ostream &operator <<(ostream &output,Matrix c){
    output<<"the matrix is "<<endl;
    for(int i=0;i<c.rows;i++){
        for(int j=0;j<c.columns;j++){
            output<<c.matrix[i][j]<<"   ";
        }
        output<<endl;
    }
    return output;
}
istream &operator >>(istream &input,Matrix &c){
    cout<<"enter the rows and columns : "<<endl;
    input>>c.rows>>c.columns;
    c.matrix=new int*;
    for(int i=0;i<c.rows;i++){
        c.matrix[i]=new int[c.columns];
    }
    for(int i=0;i<c.rows;i++){
        for(int j=0;j<c.columns;j++){
            input>>c.matrix[i][j];
        }
    }
    return input;
} 
