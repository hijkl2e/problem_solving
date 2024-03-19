#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"Algorithm", "DataAnalysis", "ArtificialIntelligence",
		"CyberSecurity", "Network", "Startup", "TestStrategy"
	};
	vector<string> B{
		"204", "207", "302", "B101", "303", "501", "105"
	};
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		int x = find(A.begin(), A.end(), S) - A.begin();
		cout << B[x] << "\n";
	}
	return 0;
}
