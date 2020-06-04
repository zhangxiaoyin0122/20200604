#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test() {
	string str("1234567890");
	int size = str.size();
	int cap = str.capacity();
	//reserve(n) : 当 n > capacity时,调整容量,但一定不修改内容和size
	str.reserve(20);
	int size1 = str.size();
	int cap1 = str.capacity();
	//reserve(n) : 按需减小:当 n < size时,不做任何操作,当capacity > n > size时,则进行减小操作
	str.reserve(5);
	int size2 = str.size();
	int cap2 = str.capacity();

	cout << size << endl;
	cout << cap << endl;
	cout << size1 << endl;
	cout << cap1 << endl;
	cout << size2 << endl;
	cout << cap2  << endl;
}


void test2() {
	string str("1234567890");
	int ret1 = str.size(); //返回有效字符的个数
	int ret2 = str.length(); //返回有效字符的个数
	int ret3 = str.capacity(); //可以存放的最大有效字符个数
	str.clear(); //只清空内容不改变容量
	int ret = str.empty(); //检测字符串是否为空串,是则返回true,否返回 false
	cout << ret << endl;
}

void test5() {
	string str("1234567890");
	//可读可写迭代器
	//正向迭代器
	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		//*it = 'x';
		++it;
	}
	cout << endl;
	//反向迭代器
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test6() {
	string str("1234567890");
	//const迭代器:不支持写操作,为只读迭代器
	string::const_iterator cit = str.cbegin();
	while (cit != str.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	string::const_reverse_iterator crt = str.crbegin();
	while (crt != str.crend()) {
		cout << *crt << " ";
		++crt;
	}
	cout << endl;
}
void test7() {
	string str("1234567890");
	//迭代器遍历
	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//operator[]遍历:可读可写接口,如果越界,则非法访问
	for (int i = 0; i < str.size(); ++i) {
		cout << str.operator[](i) << " ";
	}
	cout << endl;
	//operator[]简写:
	for (int i = 0; i < str.size(); ++i) {
		cout << str[i] << " ";
	}
	cout << endl;
	//at:可读可写,但是可读性不强,如果越界,则抛出异常
	for (int i = 0; i < str.size(); ++i) {
		cout << str.at(i) << " ";
	}
	cout << endl;
	//范围for:支持读写, 如果需要修改，则接收类型为引用类型
	//底层通过迭代器实现
	for ( auto& ch : str) {
		cout << ch << " ";
	}
	cout << endl;
}
//追加字符串
void test8() {
	string str1;
	str1.push_back('a');  //a
	str1.append(2, 'b');  //abb
	str1.append("cde");  //abbcde

	string str2;
	str2.append(str1);   //abbcde

	string str3;
	str3.append(str1, 3, 2);  //cd

	char strArr[] = "1234";
	str3.append(strArr, strArr + 2);  //cd12
	str3.append(str2.begin(), str2.end());  //cd12abbcde

	string str4;
	str4 += '1'; //1
	str4 += "234";  //1234
	str4 += str1;  //1234abbcde
}
void test9() {
	string str("aaaaaaaaa");
	size_t pos = str.find('b');  //正向查找,找到第一个匹配的位置就结束
	size_t pos2 = str.find('a'); //反向查找,找到第一个匹配的位置就结束
	
	string filel = "test.tar.gz.zip";
	pos = filel.rfind('.');
	//substr(pos,len) :如果len大于从pos到结束位置的字符串长度,则把剩余字符串全部截取出来
	string str2 = filel.substr(pos + 1, filel.size() - 1 - pos);
	string str3 = filel.substr(pos + 1);
	cout << str2 << endl;
	cout << str3 << endl;
}

void test10() {
	string s1 = "9";
	string s2 = "123";
	string s3 = "1234";
	/*bool ret = s1 > s2;
	ret = s2 > s3;
	ret = s1 > s3;*/

	string s;
	//cin >> s;
	getline(cin, s);
	cout << s;
}
int main() {
	test10();
	return 0;
}


