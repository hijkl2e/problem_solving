#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f
	};
	int s{};
	string N;
	cin >> s >> N;
	for (int i = 0; i < N.size(); ++i) {
		cout << " " << string(s, (A[N[i] - '0'] & 1) ? '-' : ' ') << "  ";
	}
	cout << "\n";
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < N.size(); ++j) {
			cout << (((A[N[j] - '0'] >> 5) & 1) ? "|" : " ") << string(s, ' ');
			cout << (((A[N[j] - '0'] >> 1) & 1) ? "|" : " ") << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N.size(); ++i) {
		cout << " " << string(s, ((A[N[i] - '0'] >> 6) & 1) ? '-' : ' ') << "  ";
	}
	cout << "\n";
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < N.size(); ++j) {
			cout << (((A[N[j] - '0'] >> 4) & 1) ? "|" : " ") << string(s, ' ');
			cout << (((A[N[j] - '0'] >> 2) & 1) ? "|" : " ") << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N.size(); ++i) {
		cout << " " << string(s, ((A[N[i] - '0'] >> 3) & 1) ? '-' : ' ') << "  ";
	}
	cout << "\n";
	return 0;
}
