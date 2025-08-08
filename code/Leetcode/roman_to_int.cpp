#include <iostream>

int rnum[2][7] = {
    {'I', 'V', 'X', 'L', 'C', 'D', 'M'},
    {1, 5, 10, 50, 100, 500, 1000}
};

int romanToInt(std::string s);
int convert(char ch);

int main(){
    std::cout << romanToInt("DCXXI");
    return 0;
}

int romanToInt(std::string s) {
    int sum = 0;
    int value;
    int size = s.length();
    bool f = false;
    for (int i = 0; i < size; i++){
        
        if (i+1 < size){
            if (s.at(i) == 'I' && ((s.at(i+1))=='V' || (s.at(i+1)=='X'))){
                value = convert(s.at(i+1)) - convert(s.at(i));
                i+=1;
                f = true;
            }
            else if (s.at(i) == 'X' && ((s.at(i+1))=='L' || (s.at(i+1)=='C'))){
                value = convert(s.at(i+1)) - convert(s.at(i));
                i+=1;
                f = true;
            }
            else if (s.at(i) == 'C' && ((s.at(i+1))=='D' || (s.at(i+1)=='M'))){
                value = convert(s.at(i+1)) - convert(s.at(i));
                i+=1;
                f = true;
            }
            else{
                value = convert(s.at(i));
            }
        }
        if (i == size-1 && f == false){
            value = convert(s.at(i));
        }
        sum+= value;
        f = false;
    }
    return sum;        
}

int convert(char ch){
    for(int i = 0; i < 7; i++){
        if(ch == rnum[0][i]){
            return rnum[1][i];
        }
    }
}