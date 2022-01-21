#include<iostream>
#include<string>
using namespace std;
int main() {
	string in; cin >> in;
	int times[10] = { 0 },an[25],len=0,carry=0;
	for (int i = in.size() - 1; i >= 0; i--) {
		int t = in[i] - '0';
		times[t]++; //每个数字出现的次数
		an[len++] = (t * 2+carry) % 10;
		carry = (t * 2 + carry) / 10; //进位
	}
	if (carry != 0) an[len++] = carry; //还有进位则增加一位
	for (int i = 0; i < len; i++) {
		times[an[i]]--;
	}
	int flag = 1;
	if (len > in.size()) flag = 0; //漏了的话有一个测试点会无法通过
	for (int i = 1; i <= 9; i++) {
		if (times[i] != 0) flag = 0;
	}
	printf("%s\n", flag ? "Yes" : "No");
	for (int i = len - 1; i >= 0; i--) {
		cout << an[i];
	}
	return 0;
}

