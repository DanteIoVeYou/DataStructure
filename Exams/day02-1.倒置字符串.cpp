//Question 
//OR62 �����ַ���
//
//����
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
//
//����������
//ÿ�������������1������������ I like beijing. �����������Ȳ�����100
//
//���������
//�����������֮����ַ���,�Կո�ָ�
//
//ʾ��1
//���룺
//I like beijing.
//
//�����
//beijing. like I 


//Answer 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s1; // I like Beijing.
	getline(cin, s1);
	// ���嵹��
	reverse(s1.begin(), s1.end()); // .gnigieB ekil I
	string::iterator start = s1.begin();
	string::iterator end = s1.begin();
	// ÿ�����ʵ���
	while(start != s1.end()){
		while(end != s1.end() && *end != ' '){
			end++;
		}
		reverse(start, end);
		if(end == s1.end()){
			start = end;
		}
		else{
			start = end + 1;
			end++;
		}	
	} 
	cout << s1 << endl;
	return 0;
}
