#include <iostream>
#include <cmath>
#define Pi  3.14159265

using namespace std;

class Complex {
private:
    double R_;
    double phi_;
public:
    Complex() { R_ = 0; phi_ = 0; };
    Complex(const double& R = 0, const double& phi = 0) {
        R_ = R;
        phi_ = phi;
    }

    double Get_R()  {
        return R_;
    }

    int Set_R(double x) {
        R_ = x;
        return 0;
    }

    double Get_phi()  {
        return phi_;
    }

    int Set_phi(double x) {
        phi_ = x;
        return 0;
    }
    void Print() {
        cout << R_ << " " << phi_ << endl;
    }
    friend Complex operator+(const Complex& first, const Complex& second);
    friend Complex operator- (const Complex& first, const Complex& second);
    friend Complex operator* (const Complex& first, const Complex& second);
    friend Complex operator/ (const Complex& first, const Complex& second);
    friend bool operator< (const Complex& first, const Complex& second);
    friend bool operator<= (const Complex& first, const Complex& second);
    friend bool operator>= (const Complex& first, const Complex& second);
    friend bool operator > (const Complex& first, const Complex& second);
    friend bool operator == (const Complex& first, const Complex& second);
    friend bool operator != (const Complex& first, const Complex& second);
    friend Complex conj(Complex& a);
    ~Complex () // деструктор
    {
    }
};
double sin_(double x){
    double y;
    y = x * Pi / 180.0;
    return sin(y);
}

double cos_(double x) {
    double y;
    y = x * Pi / 180.0;
    return cos(y);
}
double argz_(double a , double b){
    if(a>0){
        return atan(b/a);
    }else{
        if (b>0) {
            return {Pi + atan(b / a)};
        }else{
            return {-Pi + atan(b/a)};
        }

    }
}
// перегрузка операторов

Complex operator+(const Complex& first, const Complex& second) {
    double a1,a2,b1,b2,r0,phi0;
    a1 = first.R_*cos_(first.phi_);
    a2 = second.R_ * cos_(second.phi_);
    b1 = first.R_*sin_(first.phi_);
    b2 = second.R_ * sin_(second.phi_);
    r0 = sqrt((a1+a2) * (a1 + a2) + (b1 + b2) * (b1 + b2));
    phi0 = argz_((a1 + a2) , (b1 + b2));

    return Complex(r0 , phi0) ;
}

Complex operator- (const Complex& first, const Complex& second) {
    double a1,a2,b1,b2,r0,phi0;
    a1 = first.R_*cos_(first.phi_);
    a2 = second.R_ * cos_(second.phi_);
    b1 = first.R_*sin_(first.phi_);
    b2 = second.R_ * sin_(second.phi_);
    r0 = sqrt((a1-a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    phi0 = argz_((a1 - a2) , (b1 - b2));

    return Complex(r0 , phi0);
}

Complex operator* (const Complex& first, const Complex& second) {
    double a1,a2,b1,b2,r0,phi0;
    a1 = first.R_*cos_(first.phi_);
    a2 = second.R_ * cos_(second.phi_);
    b1 = first.R_*sin_(first.phi_);
    b2 = second.R_ * sin_(second.phi_);
    r0 = sqrt((a1*a2-b1*b2) * (a1*a2-b1*b2) + (a1 * b2 + b1 *a2) * (a1 * b2 + b1 *a2));
    phi0 = argz_((a1*a2-b1*b2) , (a1*b2 + b1*a2));
    return Complex(r0 , phi0);
}
Complex operator/ (const Complex& first, const Complex& second) {
    double a1,a2,b1,b2,r0,phi0;
    a1 = first.R_*cos_(first.phi_);
    a2 = second.R_ * cos_(second.phi_);
    b1 = first.R_*sin_(first.phi_);
    b2 = second.R_ * sin_(second.phi_);
    r0 = sqrt((a1*a2 + b1*b2) * (a1*a2 + b1*b2)/(a2*a2 + b2*b2)/(a2*a2 + b2*b2) + (a2 * b1 - b2 *a1) * (a2 * b1 - b2 *a1)/(a2*a2 + b2*b2)/(a2*a2 + b2*b2)); // (a1a2 + b1b2, b1a2 – a1b2) / (a2^2 + b2^2);
    phi0 = argz_((a1*a2 + b1*b2) , (a2 * b1 - b2 *a1));
    return Complex(r0 , phi0);
}

bool operator< (const Complex& first, const Complex& second) {
    return (first.R_ < second.R_);
}

bool operator<= (const Complex& first, const Complex& second) {
    return  (first.R_ <= second.R_);
}

bool operator> (const Complex& first, const Complex& second) {
    return  (first.R_ > second.R_);
}

bool operator>= (const Complex& first, const Complex& second) {
    return (first.R_ >= second.R_);
}

bool operator== (const Complex& first, const Complex& second) {
    return ((first.R_ == second.R_) && (first.phi_ == second.phi_));
}

bool operator!= (const Complex& first, const Complex& second) {
    return (!(first == second));
}
Complex conj(Complex& a) {
    return { a.R_, -a.phi_ };
}


int main() {
    double r1, phi1, r2, phi2;
    cin >> r1 >> phi1 >> r2 >> phi2;
    Complex a = Complex(r1 , phi1);
    Complex b = Complex(r2 , phi2);
    Complex res = Complex(0,0);
    res = a + b;
    res.Print();
    res = a - b;
    res.Print();
    res = a * b;
    res.Print();
    res = a / b;
    res.Print();
    cout << (int)(a<b) << endl;
    res = conj(a);
    res.Print();



    return 0;
}