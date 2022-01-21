//OR63 删除公共字符
//描述
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
//
//输入描述：
//每个测试输入包含2个字符串
//
//输出描述：
//输出删除后的字符串
//示例1
//输入：
//They are students. 
//aeiou
//
//输出：
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

// 2022-1-16 笔试强训day01-第二题 
