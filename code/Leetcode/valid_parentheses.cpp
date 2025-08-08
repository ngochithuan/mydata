#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s) {
	stack<char> stack;
	for (auto ch : s){
		if((ch != ')') && (ch != ']') && (ch != '}')){
			stack.push(ch);
		}
		else {
			if (!stack.empty()){
				if((ch == ')') && (stack.top() != '(')){
					return false;
				} else if ((ch == ']') && (stack.top() != '[')) {
					return false;
				} else if ((ch == '}') && (stack.top() != '{')) {
					return false;
				}
				stack.pop();
			} else if ((ch == ')') || (ch == ']') || (ch == '}')){
				return false;
			}
		}
	}
	// while(!stack.empty()){
	// 	cout << stack.top() << '\n';
	// 	stack.pop();
	// }
	return true;
}

int main() {
	cout << isValid("[");
	return 0;
}
