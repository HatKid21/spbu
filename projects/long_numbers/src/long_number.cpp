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
	if (compare(*this,x) == -1){
        return true;
    }
    return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	if (compare(*this,x) == 1){
        return true;
    }
    return false;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	// TODO
    return *this;
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
	// TODO
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
    int offset = 0;
	if (str[0] == '-'){
        offset = 1;
    }
    return sizeof(str) / sizeof(str[0]) - offset;
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
    if (left.length > right.length){
        return -1;
    } else if (left.length < right.length){
        return 1;
    } else{
        for (int i = 0; i < length; i++){
            if (left.numbers[i] > right.numbers[i]){
                return -1;
            } else if (left.numbers[i] < right.numbers[i]){
                return 1;
            }
        }
    }
    return 0;
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
