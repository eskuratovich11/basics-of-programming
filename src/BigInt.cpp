#include <BigInt.hpp>

BigInt::BigInt(const char *i) : strInt(std::string(i)){
    if(!is_int(strInt)){
        throw std::exception();
    }
    std::reverse(strInt.begin(),strInt.end());
}

BigInt &BigInt::operator+=(const BigInt &bI) {
    BigInt bIC(bI);
    size_t bICLen = bIC.strInt.length();
    if(bICLen>strInt.length()){
        strInt.append(bICLen-strInt.length(),'0');
    }else{
        bIC.strInt.append(strInt.length()-bICLen,'0');
    }
    int forNext = 0;
    int n;
    for(size_t i = 0;i<strInt.length();i++){
        n = forNext + ctoi(strInt[i]) + ctoi(bIC.strInt[i]);
        strInt[i] = itoc(n%10);
        forNext = n/10;
    }
    if(forNext!=0){
        strInt.append(1,itoc(forNext));
    }
    return *this;
}

int BigInt::ctoi(const char &ch) {
    return ch-'0';
}

char BigInt::itoc(const int &i) {
    return static_cast<char>(i)+'0';
}

char *BigInt::to_string() const{
    char* str = new char[strInt.length()+1];
    std::copy(strInt.rbegin(), strInt.rend(),str);
    str[strInt.length()] = '\0';
    return str;
}

BigInt::BigInt(const BigInt &bI) : strInt(std::string(bI.strInt)){}

BigInt BigInt::operator+(const BigInt &bI) {
    BigInt c(*this);
    return c+=bI;
}

bool BigInt::operator>(const BigInt &bI) {
    if(strInt.length()!=bI.strInt.length()){
        return strInt.length() > bI.strInt.length();
    }
    for(size_t i = strInt.length()+1;;i--){
        if(strInt[i] != bI.strInt[i]){
            return strInt[i] > bI.strInt[i];
        }
        if(i==0)break;
    }
    return false;
}
bool BigInt::operator<(const BigInt &bI) {
    if(strInt.length()!=bI.strInt.length()){
        return strInt.length() < bI.strInt.length();
    }
    for(size_t i = strInt.length()+1;;i--){
        if(strInt[i] != bI.strInt[i]){
            return strInt[i] < bI.strInt[i];
        }
        if(i==0)break;
    }
    return false;
}

bool BigInt::operator==(const BigInt &bI) {
    return strInt==bI.strInt;
}

bool BigInt::operator!=(const BigInt &bI) {
    return !(*this == bI);
}

std::ostream& operator<<(std::ostream& out,const BigInt& bi){
    char*c = bi.to_string();
    out << c;
    delete[] c;
    return out;
}
std::istream& operator>>(std::istream& in,BigInt& bi){
    std::string s;
    std::getline(in,s);
    if(!bi.is_int(s)){
        throw std::exception();
    }
    std::reverse(s.begin(),s.end());
    bi.strInt = s;
    return in;
}

bool BigInt::is_int(const std::string &str) {
    if(str.empty() || (str[0]=='0' && str.length()!=1)){
        return false;
    }
    for(const char& ch : str ){
        if(!(ch >= '0' && ch <= '9')){
            return false;
        }
    }
    return true;
}

BigInt &BigInt::operator*=(const BigInt &bI) {
    BigInt exp("0");
    for(size_t i = 0;i<bI.strInt.length();i++){
        BigInt doubleCopy = ((*this)*bI.strInt[i]);
        doubleCopy.strInt.insert(0,i,'0');
        exp += doubleCopy;
    }
    exp.strInt.erase(0, std::min(exp.strInt.find_first_not_of('0'), exp.strInt.size()-1));
    *this = exp;
    return *this;
}

BigInt BigInt::operator*(const char &ch) {
    BigInt copy(*this);
    int chNum = ctoi(ch);
    int forNext = 0;
    int n;
    for(size_t i = 0;i<copy.strInt.length();i++){
        n = forNext + ctoi(copy.strInt[i]) * chNum;
        copy.strInt[i] = itoc(n%10);
        forNext = n/10;
    }
    if(forNext!=0){
        copy.strInt.append(1,itoc(forNext));
    }
    return copy;
}

BigInt BigInt::operator*(const BigInt &bI) {
    BigInt c(*this);
    return c*=bI;
}
