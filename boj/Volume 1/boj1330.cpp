#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{};
	cin >> A >> B;
	cout << (A > B ? ">" : A < B ? "<" : "==") << "\n";
	return 0;
}
