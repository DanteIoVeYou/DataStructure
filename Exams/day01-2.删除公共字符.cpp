//OR63 ɾ�������ַ�
//����
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
//
//����������
//ÿ�������������2���ַ���
//
//���������
//���ɾ������ַ���
//ʾ��1
//���룺
//They are students. 
//aeiou
//
//�����
//Thy r stdnts.

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1;
    string s2;
    string s3;
    getline(cin, s1);
    getline(cin, s2);
    int hash[256] = {0};
    for(auto& e: s2){
        hash[e]++;
    }
    for(auto& e: s1){
        if(hash[e] == 0){
            s3.push_back(e);
        }
    }    
    cout << s3 << endl;
    return 0;
}

// 2022-1-16 ����ǿѵday01-�ڶ��� 
