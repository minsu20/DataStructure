//2020112377 ��ǻ�Ͱ��а� ��μ� 
//palindrome.cpp
//ȸ�� ����

#include "stackarr.cpp"

int main(void) {
	char input[100];
	cout << "Input String: ";
	cin >> input; //���ڿ� �Է� �ޱ�
	int length = strlen(input); //���ڿ� ����
	Stack<char> inputStack(length);
	for (int i = 0; i < length; i++) {
		inputStack.push(input[i]);  //�Է¹��� ���ڿ� push
	}
	for (int j = 0; j < length/2; j++) {
		if (input[j]!=inputStack.pop()) //ȸ���� �ƴ� ���
		{
			cout << "No"; 
			return 0; 
		}
	}
	cout << "Yes";
	return 0;
}