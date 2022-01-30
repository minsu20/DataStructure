//2020112377 컴퓨터공학과 김민수 
//palindrome.cpp
//회문 판정

#include "stackarr.cpp"

int main(void) {
	char input[100];
	cout << "Input String: ";
	cin >> input; //문자열 입력 받기
	int length = strlen(input); //문자열 길이
	Stack<char> inputStack(length);
	for (int i = 0; i < length; i++) {
		inputStack.push(input[i]);  //입력받은 문자열 push
	}
	for (int j = 0; j < length/2; j++) {
		if (input[j]!=inputStack.pop()) //회문이 아닌 경우
		{
			cout << "No"; 
			return 0; 
		}
	}
	cout << "Yes";
	return 0;
}