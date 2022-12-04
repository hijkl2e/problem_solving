#include <bits/stdc++.h>

using namespace std;

using cc = pair<char, char>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	vector<pair<char, function<int(int, int)>>> op{
		{'*', multiplies()}, {'+', plus()},
		{'-', minus()}, {'/', divides()}
	};
	vector<cc> A;
	for (auto &p : op) {
		if (p.first == '/' && b == 0) {
			continue;
		}
		for (auto &q : op) {
			if (q.first == '/' && d == 0) {
				continue;
			}
			if (p.second(a, b) == q.second(c, d)) {
				A.push_back({p.first, q.first});
			}
		}
	}
	if (A.empty()) {
		cout << "problems ahead\n";
	} else {
		for (auto &[op1, op2] : A) {
			cout << a << " " << op1 << " " << b << " = ";
			cout << c << " " << op2 << " " << d << "\n";
		}
	}
	return 0;
}
