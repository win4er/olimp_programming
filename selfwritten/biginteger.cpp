#include <string>
#include <vector>
#include <iostream>

using namespace std;

class big_int {
private:
    vector<int> digits;
public:
    big_int(const char* number);        
    big_int(string& number);
    size_t size() const;
    int operator[](const int ind) const;
    friend ostream& operator<<(ostream& out, const big_int& number);
    big_int& operator=(const big_int& n2);
    big_int& operator+=(const big_int& n2);
};

big_int::big_int(const char* number) {
    size_t ind=0;
    while (number[ind] != '\0') {
        if (!(number[ind] >= '0' && number[ind] <= '9')) {
            throw("error");
        }
        ind++;
    }
    this->digits = {};
    while (ind>0) {
        digits.push_back(number[--ind]-'0');
    }
}

big_int::big_int(string& number) {
    this->digits = {};
    size_t size = number.size();
    for (int i=size-1; i>=0; --i) {
        if (!(number[i] >= '0' && number[i] <= '9')) {
            throw("error");
        }
        this->digits.push_back(number[i]-'0');
    }
}

size_t big_int::size() const {
    return digits.size();
}

int big_int::operator[](const int ind) const {
    return this->digits[ind];
}

ostream& operator<<(ostream& out, const big_int& number) {
    for (int i=number.size()-1; i>=0; --i) {
        out << number[i];
    }
    return out;
}

big_int& big_int::operator=(const big_int& number) {
     this->digits = number.digits;
     return *this;
}

big_int& big_int::operator+=(const big_int& number) {
    size_t size_1 = this->size();
    size_t size_2 = number.size();

    if (size_2 > size_1) {
        for (int i=0; i<size_2-size_1; ++i) {
            this->digits.push_back(0);
        }
        size_1 = size_2;
    }
    int up = 0;
    for (size_t i=0; i<size_1; ++i) {
        this->digits[i] += up;
        if (i < size_2) {
            if ((this->digits[i] + number[i]) > 10)
                up = (this->digits[i] + number[i]) % 10;
            this->digits[i] += number[i];
        }
    }
    return *this;
}

int main() {
    big_int number("1000000000000000000000000000000000000000000000000000");
    std::cout << number << std::endl;
    big_int number2("25");
    number += number2;
    std::cout << number << std::endl;
    return 0;
}