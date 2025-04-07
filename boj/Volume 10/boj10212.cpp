#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	mt19937 gen(random_device{}());
	cout << (gen() % 2 ? "Yonsei" : "Korea") << "\n";
	return 0;
}
