#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int x = S.size() - 7 * N;
	cout << (N - x > x ? "bigdata?" : N - x < x ? "security!" : "bigdata? security!") << "\n";
	return 0;
}
