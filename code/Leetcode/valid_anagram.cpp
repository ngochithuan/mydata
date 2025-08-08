#include<iostream>
#include<map>

using namespace std;

bool isAnagram(string s, string t);
map<char, int> toTable(string str);
bool isEqual_map(map<char, int> t1, map<char, int> t2);


int main () {
	string s = "zxcvb";
	string t = "12345";
	if (isAnagram(s, t)){
		cout << "True";	
	} else {
		cout << "False";	
	}
	return 0;
}

bool isAnagram(string s, string t) {
    map<char, int> s_tb = toTable(s);
    map<char, int> t_tb = toTable(t);
    // for (auto s_tb : s_tb) {
 	// 	cout << s_tb.first << " is: " << s_tb.second << "\n";
	// }
	if (s_tb.size() != t_tb.size()){
		return false;
	} else if (!isEqual_map(s_tb, t_tb)) {
		return false;
	}
    return true;    
}

bool isEqual_map(map<char, int> t1, map<char, int> t2){
	if (t1.size() != t2.size()){
		return false;
	}
	for (auto t : t1){
		if (!t2.count(t.first)) {
			return false;
		}
		cout << t.second << ":" << t2.at(t.first) << "\n";
	    if (t.second != t2.at(t.first)){

	    	return false;
	    }
	}
	cout << "here";
	return true;

}

map<char, int> toTable(string str){
	map<char, int> table;
	for (int i = 0; i < str.size(); i++){
		// Da ton tai
		if(table.count(str.at(i))){
			table[str.at(i)] += 1;
			continue;
		}
		// chua ton tai
		table[str.at(i)] = 1;
	}
	return table;
}
