#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << "int a;\n";
	cout << "int *ptr = &a;\n";
	for (int i = 2; i <= N; ++i) {
		cout << "int " << string(i, '*') << "ptr" << i;
		cout << " = &ptr" << (i > 2 ? to_string(i - 1) : "") << ";\n";
	}
	return 0;
}
