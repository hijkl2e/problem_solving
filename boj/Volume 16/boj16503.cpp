#include <bits/stdc++.h>

using namespace std;

int func(int a, char op, int b) {
	int res{};
	if (op == '+') {
		res = a + b;
	} else if (op == '-') {
		res = a - b;
	} else if (op == '*') {
		res = a * b;
	} else if (op == '/') {
		res = a / b;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	char op1{}, op2{};
	cin >> a >> op1 >> b >> op2 >> c;
	int res1 = func(func(a, op1, b), op2, c);
	int res2 = func(a, op1, func(b, op2, c));
	cout << min(res1, res2) << "\n";
	cout << max(res1, res2) << "\n";
	return 0;
}
