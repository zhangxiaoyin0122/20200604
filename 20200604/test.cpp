#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test() {
	string str("1234567890");
	int size = str.size();
	int cap = str.capacity();
	//reserve(n) : �� n > capacityʱ,��������,��һ�����޸����ݺ�size
	str.reserve(20);
	int size1 = str.size();
	int cap1 = str.capacity();
	//reserve(n) : �����С:�� n < sizeʱ,�����κβ���,��capacity > n > sizeʱ,����м�С����
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
	int ret1 = str.size(); //������Ч�ַ��ĸ���
	int ret2 = str.length(); //������Ч�ַ��ĸ���
	int ret3 = str.capacity(); //���Դ�ŵ������Ч�ַ�����
	str.clear(); //ֻ������ݲ��ı�����
	int ret = str.empty(); //����ַ����Ƿ�Ϊ�մ�,���򷵻�true,�񷵻� false
	cout << ret << endl;
}

void test5() {
	string str("1234567890");
	//�ɶ���д������
	//���������
	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		//*it = 'x';
		++it;
	}
	cout << endl;
	//���������
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test6() {
	string str("1234567890");
	//const������:��֧��д����,Ϊֻ��������
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
	//����������
	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//operator[]����:�ɶ���д�ӿ�,���Խ��,��Ƿ�����
	for (int i = 0; i < str.size(); ++i) {
		cout << str.operator[](i) << " ";
	}
	cout << endl;
	//operator[]��д:
	for (int i = 0; i < str.size(); ++i) {
		cout << str[i] << " ";
	}
	cout << endl;
	//at:�ɶ���д,���ǿɶ��Բ�ǿ,���Խ��,���׳��쳣
	for (int i = 0; i < str.size(); ++i) {
		cout << str.at(i) << " ";
	}
	cout << endl;
	//��Χfor:֧�ֶ�д, �����Ҫ�޸ģ����������Ϊ��������
	//�ײ�ͨ��������ʵ��
	for ( auto& ch : str) {
		cout << ch << " ";
	}
	cout << endl;
}
//׷���ַ���
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
	size_t pos = str.find('b');  //�������,�ҵ���һ��ƥ���λ�þͽ���
	size_t pos2 = str.find('a'); //�������,�ҵ���һ��ƥ���λ�þͽ���
	
	string filel = "test.tar.gz.zip";
	pos = filel.rfind('.');
	//substr(pos,len) :���len���ڴ�pos������λ�õ��ַ�������,���ʣ���ַ���ȫ����ȡ����
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


