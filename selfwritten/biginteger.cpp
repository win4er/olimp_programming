#include <string>
#include <vector>
#include <iostream>

using namespace std;

class big_int {
private:
    vector<int> digits;
public:
    big_int();
    big_int(const char* number);        
    big_int(string& number);
    size_t size() const;
    int operator[](const int ind) const;
    friend ostream& operator<<(ostream& out, const big_int& number);
    big_int& operator=(const big_int& n2);
    big_int& operator+=(const big_int& n2);
    big_int operator+(const big_int& n2);
    big_int& operator-=(const big_int& n2);
    big_int operator-(const big_int& n2);
    big_int& operator*=(const big_int& n2);
};

big_int::big_int() {
    this->digits = {};
    this->digits.push_back(0);
}

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
    ind = this->digits.size()-1;
    while (this->digits[ind] == 0) {
        this->digits.pop_back();
        ind--;
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
    size_t ind = this->digits.size()-1;
    while (this->digits[ind] == 0) {
        this->digits.pop_back();
        ind--;
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
            up = (this->digits[i] + number[i]) / 10;
            this->digits[i] = (this->digits[i] + number[i]) % 10;
        } else {
            up = this->digits[i] / 10;
            this->digits[i] %= 10;
        }
    }
    if (up) {
        this->digits.push_back(up);
    }
    return *this;
}

big_int big_int::operator+(const big_int& n2) {
    big_int result;
    result = *this;
    result += n2;
    return result;
}

big_int& big_int::operator-=(const big_int& number) {
    size_t size_1 = this->size();
    size_t size_2 = number.size();

    if (size_2 > size_1) {
        throw("underflow");
    }
    for (int i=0; i<size_1; ++i) {
        if (i < size_2) {
            if (this->digits[i] < number[i]) {
                this->digits[i] += 10 - number[i];
                this->digits[i+1] -= 1;
            } else {
                this->digits[i] = this->digits[i] - number[i];
            }
        } else {
            if (this->digits[i] < 0) {
                this->digits[i] += 10;
                this->digits[i+1] -= 1;
            }
        }
    }
    size_t ind = this->digits.size()-1;
    while (this->digits[ind] == 0) {
        this->digits.pop_back();
        ind--;
    }
    return *this;
}

big_int big_int::operator-(const big_int& n2) {
    big_int result;
    result = *this;
    result -= n2;
    return result;
}

int main() {
    big_int number("1000000");
    std::cout << number << std::endl;
    big_int number2("10001");
    std::cout << number-number2 << std::endl;
    number = number-number2;
    std::cout << number << std::endl;
    return 0;
}