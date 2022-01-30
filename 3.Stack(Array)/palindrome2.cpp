//2020112377 컴퓨터공학과 김민수 
//palindrome2.cpp
//회문 제거해야 하는 인덱스 출력, 지워야 하는 문자는 최대 1개, 없으면 -1출력

#include "stackarr.cpp"


int main(void) {
	char input[100];
	int index = -1; 
	cout << "Input String: ";
	cin >> input;   //문자열 입력받기
	int length = strlen(input); //문자열 길이
	Stack<char> inputStack(length);
	for (int i = 0; i < length; i++) {
		inputStack.push(input[i]); //입력받은 문자열 push
	}
    for (int j = 0; j < length / 2; j++) {
        if (input[j] != inputStack.pop()) //지워야 하는 문자가 있는 경우: 왼쪽(ipnut[j]) or 오른쪽(pop했던 문자) (최대 1개라고 했으므로)
        {
			inputStack.push(input[length-j-1]); //pop했던 문자 다시 넣기
			if (input[j++] != inputStack.pop()) //왼쪽 문자 제거하고 회문이 아닌 경우
			{
				index = length - j ; //제거해야 하는 문자가 오른쪽
				break;
			}
			index = --j; //제거해야 하는 문자가 왼쪽인 경우
        }
    }
	cout << "Index: "<<index;
    return 0;
}