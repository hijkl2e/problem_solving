#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, A{}, B{};
	cin >> N >> A >> B;
	cout << (A < B ? "Bus" : A > B ? "Subway" : "Anything") << "\n";
	return 0;
}
