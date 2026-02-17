#include "long_number.hpp"

using hatkid::LongNumber;
		
LongNumber::LongNumber() {
    numbers = new int[1];
    numbers[0] = 0;
    length = 1;
    sign = 0;
}

LongNumber::LongNumber(const char* const str) {
    length = get_length(str);
    sign = get_sign(str);
    numbers = new int[length];
    int t = (sign == -1) ? 1 : 0;
    for (int i = t; i < length;i++){
        char c = str[i];
        numbers[i] = c - '0';
    }
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
    sign = x.sign;
    numbers = new int[length];

    for (int i = 0; i < length; i++){
        numbers[i] = x.numbers[i];
    }
}

LongNumber::LongNumber(LongNumber&& x) {
    length = x.length;
    sign = x.sign;

    numbers = x.numbers;
    x = nullptr;
}

LongNumber::~LongNumber() {
    delete[] numbers;
}

LongNumber& LongNumber::operator = (const char* const str) {
    delete[] numbers;
    
    length = get_length(str);
    sign = get_sign(str);
    numbers = new int[length];
    int t = (sign == -1) ? 1 : 0;
    for (int i = t; i < length; i++){
        char c = str[i];
        numbers[i] = c - '0';
    }
    return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
    if (this == &x){
        return *this;
    }
    delete[] numbers;

    length = x.length;
    sign = x.sign;
    numbers = new int[length];
    for (int i = 0; i < length; i++){
        numbers[i] = x.numbers[i];
    }
    return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
    if (this == &x) return *this;

    delete[] numbers;

	numbers = x.numbers;
    x.numbers = nullptr;
    length = x.length;
    sign = x.sign;
    return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {	
    return !compare(*this,x);
}

bool LongNumber::operator != (const LongNumber& x) const {
    return compare(*this,x);
}

bool LongNumber::operator > (const LongNumber& x) const {
    return compare(*this,x) == -1;
}

bool LongNumber::operator < (const LongNumber& x) const {
    return compare(*this,x) == 1;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {

    if (sign != x.sign){
        
    }

    LongNumber maxi;
    LongNumber mini;

    if (*this > x){
        maxi = *this;
        mini = x;
    } else{
        maxi = x;
        mini = *this;
    }

    int* num = new int[maxi.length];
    int i = maxi.length - 1;
    int j = mini.length - 1;

    int rem = 0;

    while (i >= 0){
        if (j < 0){
            num[i] = ( maxi.numbers[i] + rem) % 10;
            rem = (maxi.numbers[i] + rem) / 10;
        } else{
            num[i] = (maxi.numbers[i] + mini.numbers[j] + rem) % 10;
            rem = (maxi.numbers[i] + mini.numbers[j] + rem) / 10;
        }
        i--;
        j--;
    }

    int* resultNum;
    int resultLength = maxi.length;

    if (rem != 0){
        resultNum = new int[maxi.length+1];
        resultNum[0] = rem;
        for (int i = 0; i < maxi.length; i++){
            resultNum[i+1] = num[i];
        }
        resultLength++;
        delete[] num;
    } else{
        resultNum = new int[maxi.length];
        for (int i = 0; i < maxi.length;i++){
            resultNum[i] = num[i];
        }
    }

    LongNumber result;
    result.numbers = resultNum;
    result.sign = sign;
    result.length = resultLength;
    return result;
    
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
    // TODO
    return *this;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	// TODO
    return *this;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
    int count = 0;
    return *this;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
    return *this;
}

bool LongNumber::is_negative() const noexcept {
	if (sign == -1){
        return true;
    }
    return false;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
    int len = 0;
    while (str[len] != '\0'){
        len++;
    }

    if (str[0] == '-'){
        len--;
    }
    return len;
}

int LongNumber::get_sign(const char* const str) const noexcept {
    if (str[0] == '-'){
        return -1;
    } else if (str[0] == '0'){
        return 0;
    }
    return 1;
}

int LongNumber::compare(const LongNumber& left, const LongNumber& right) const noexcept{

    if (left.sign != right.sign){
        return (left.sign == -1) ? 1 : -1;
    }

    int result = 0;

    if (left.length > right.length){
        return -1;
    } else if (left.length < right.length){
        return 1;
    } else{
        for (int i = 0; i < left.length; i++){
            if (left.numbers[i] > right.numbers[i]){
                result = -1;
                break;
            } else if (left.numbers[i] < right.numbers[i]){
                result = 1;
                break;
            }
        }
    }

    if (left.sign == -1 and result != 0){
        return -result;
    }

    return result;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace hatkid {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
	    for (int i = 0; i < x.length; i++){
            os << x.numbers[i];
        }
        return os;
    }
}
