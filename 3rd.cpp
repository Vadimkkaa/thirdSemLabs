#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class my_minus_double {
    double mparameter;
public:
    my_minus_double(double a = 0) {
        mparameter = 0 - a;
    }

    friend ostream& operator<<(ostream& out, const my_minus_double& a) {
        out << a.mparameter;
        return out;
    }
};

class my_double {
    double parameter;
    int whole_part;
public:
    my_double(double var4par = 0, int var4int = 0) : parameter(var4par), whole_part(var4int) {}
    double get_double() {
        return parameter;
    }
    void set_double(double n) {
        parameter = n;
        return;
    }
    int get_int() {
        return whole_part;
    }
    void set_int(int n) {
        whole_part = n;
        return;
    }
    my_double operator+(my_double o) {
        my_double temp;
        temp.parameter = (parameter + o.parameter);

        return temp;
    }
    my_double operator-(my_double o) {
        my_double temp;
        temp.parameter = (parameter - o.parameter);
        return temp;
    }
    my_double operator++(int o) {
        my_double temp;
        temp = *this;
        parameter += 1;
        return temp;
    }
    my_double operator++() {
        parameter += 1;
        return this->parameter;
    }
    bool operator>(my_double o) {
        if (parameter > o.parameter) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(my_double o) {
        if (parameter < o.parameter) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator==(my_double o) {
        if (parameter == o.parameter) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator= (double o) {
        parameter = o;
        return true;
    }

    friend my_double operator--(my_double a, int o) {
        my_double temp;
        temp = a;
        a.parameter -= 1;
        return temp;
    }
    friend my_double operator--(my_double a) {
        a.parameter -= 1;
        return a.parameter;
    }
    friend bool operator==(my_double a, my_double b) {
        if (a.parameter == b.parameter) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator<(my_double a, int b) {
        double par = 1 * b;
        if (a.parameter < par) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator>(my_double a, int b) {
        double par = 1 * b;
        if (a.parameter > par) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator==(my_double a, int b) {
        double par = 1 * b;
        if (a.parameter == par) {
            return true;
        }
        else {
            return false;
        }
    }
    friend ostream& operator<<(ostream& out, const my_double& a) {
        out << a.parameter;
        return out;
    }


    explicit operator my_minus_double() {

        return my_minus_double(this->parameter);
    }
};


int main() {
    double d;
    cin >> d;
    my_double mdouble(d);
    my_minus_double mminusdouble = (my_minus_double)mdouble;
    cout << mminusdouble << endl;

    cout << "HELLO WORLD!" << endl;
    cout << "Print 4 doubles" << endl;
    double d1, d2, d3, d4;
    cin >> d1;
    my_double myd1(d1);
    cin >> d2;
    my_double myd2(d2);
    cin >> d3;
    my_double myd3(d3);
    cin >> d4;
    my_double myd4(d4);
    cout << "input was ended" << endl;
    cout << myd1 << endl << myd2 << endl;
    cout << "Sum of 1st and 3rd" << endl;

    my_double my_ddd = myd3 + myd1;
    cout << my_ddd << endl;

    cout << "Sum of 1st and 3rd" << endl;
    cout << (myd3 + myd1) << endl;

    cout << "Diff of 4th and 3rd" << endl;
    my_ddd = (myd4 - myd3);
    cout << my_ddd << endl;

    cout << "Post ++3" << endl;
    cout << myd3++ << endl;
    cout << "Pref ++3" << endl;
    cout << ++myd3 << endl;
    cout << "Post --3" << endl;
    cout << myd3-- << endl;
    cout << "Pref --3" << endl;
    cout << --myd3 << endl;

    cout << "1st < 4th? its " << endl;
    cout << (myd1 < myd4);
    cout << endl;
    cout << "1st > 4th? its " << endl;
    cout << (myd1 > myd4);
    cout << endl;



    return 0;
}
