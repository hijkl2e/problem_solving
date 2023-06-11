#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	char op1{}, op2{};
	if (a + b == c) {
		op1 = '+', op2 = '=';
	} else if (a - b == c) {
		op1 = '-', op2 = '=';
	} else if (a * b == c) {
		op1 = '*', op2 = '=';
	} else if (a % b == 0 && a / b == c) {
		op1 = '/', op2 = '=';
	} else if (a == b + c) {
		op1 = '=', op2 = '+';
	} else if (a == b - c) {
		op1 = '=', op2 = '-';
	} else if (a == b * c) {
		op1 = '=', op2 = '*';
	} else {
		op1 = '=', op2 = '/';
	}
	cout << a << op1 << b << op2 << c << "\n";
	return 0;
}
