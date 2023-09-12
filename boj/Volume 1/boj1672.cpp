#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, char> tab{
		{130, 'A'}, {136, 'C'}, {132, 'A'}, {149, 'G'}, {142, 'G'},
		{138, 'T'}, {155, 'A'}, {134, 'C'}, {151, 'G'}, {168, 'T'}
	};
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	while (S.size() > 1) {
		int x = S.back();
		S.pop_back();
		S.back() = tab[x + S.back()];
	}
	cout << S << "\n";
	return 0;
}
