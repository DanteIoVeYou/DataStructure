//Question 
//OR62 倒置字符串
//
//描述
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
//
//输入描述：
//每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
//
//输出描述：
//依次输出倒置之后的字符串,以空格分割
//
//示例1
//输入：
//I like beijing.
//
//输出：
//beijing. like I 


//Answer 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s1; // I like Beijing.
	getline(cin, s1);
	// 整体倒置
	reverse(s1.begin(), s1.end()); // .gnigieB ekil I
	string::iterator start = s1.begin();
	string::iterator end = s1.begin();
	// 每个单词倒置
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
