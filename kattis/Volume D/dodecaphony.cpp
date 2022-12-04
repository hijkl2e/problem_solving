#include <bits/stdc++.h>

using namespace std;

bool transposition(vector<int> A, vector<int> B) {
	int d = (A[0] - B[0] + 12) % 12;
	for (int i = 0; i < A.size(); ++i) {
		if (d != (A[i] - B[i] + 12) % 12) {
			return false;
		}
	}
	return true;
}

bool retrograde(vector<int> A, vector<int> B) {
	reverse(A.begin(), A.end());
	return A == B;
}

bool inversion(vector<int> A, vector<int> B) {
	for (int i = 0; i < A.size(); ++i) {
		if (B[i] != (2 * A[0] - A[i] + 12) % 12) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> n2i{
		{"C", 0}, {"C#", 1}, {"D", 2}, {"D#", 3}, {"E", 4}, {"F", 5}, 
		{"F#", 6}, {"G", 7}, {"G#", 8}, {"A", 9}, {"A#", 10}, {"B", 11}
	};
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		A[i] = n2i[s];
	}
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		B[i] = n2i[s];
	}
	if (transposition(A, B)) {
		cout << "Transposition\n";
	} else if (retrograde(A, B)) {
		cout << "Retrograde\n";
	} else if (inversion(A, B)) {
		cout << "Inversion\n";
	} else {
		cout << "Nonsense\n";
	}
	return 0;
}
