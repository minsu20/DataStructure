//2020112377 ��ǻ�Ͱ��а� ��μ� 
//palindrome2.cpp
//ȸ�� �����ؾ� �ϴ� �ε��� ���, ������ �ϴ� ���ڴ� �ִ� 1��, ������ -1���

#include "stackarr.cpp"


int main(void) {
	char input[100];
	int index = -1; 
	cout << "Input String: ";
	cin >> input;   //���ڿ� �Է¹ޱ�
	int length = strlen(input); //���ڿ� ����
	Stack<char> inputStack(length);
	for (int i = 0; i < length; i++) {
		inputStack.push(input[i]); //�Է¹��� ���ڿ� push
	}
    for (int j = 0; j < length / 2; j++) {
        if (input[j] != inputStack.pop()) //������ �ϴ� ���ڰ� �ִ� ���: ����(ipnut[j]) or ������(pop�ߴ� ����) (�ִ� 1����� �����Ƿ�)
        {
			inputStack.push(input[length-j-1]); //pop�ߴ� ���� �ٽ� �ֱ�
			if (input[j++] != inputStack.pop()) //���� ���� �����ϰ� ȸ���� �ƴ� ���
			{
				index = length - j ; //�����ؾ� �ϴ� ���ڰ� ������
				break;
			}
			index = --j; //�����ؾ� �ϴ� ���ڰ� ������ ���
        }
    }
	cout << "Index: "<<index;
    return 0;
}