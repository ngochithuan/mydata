#include<iostream>

using namespace std;

string xuLi(string s){
	string sr = "";
	for(int i = 0; i < s.size(); i++){
		if(!isalpha(s.at(i)) && !isdigit(s.at(i))){
			continue;
		}
		if(isupper(s.at(i))){
			sr+=(tolower(s.at(i)));
		} else {
			sr+=(s.at(i));	
		}
		
	}
	return sr;
}

bool isPalindrome(string s) {
	s = xuLi(s);
	// cout << s;
	int fi = 0;
	int bi = s.size()-1;
	while(fi <= bi){
		if(s.at(fi) != s.at(bi)){
			return false;
		}
		fi+=1;
		bi-=1;
	}
	return true;        
}

int main() {
	cout << isPalindrome("0P");
	return 0;
}