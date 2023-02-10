#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string a(N, 'B');
	string b(N, 'B');
	b[N - 2] = 'A';
	b[N - 1] = 'a';
	cout << a << "\n" << b << "\n";
	return 0;
}
