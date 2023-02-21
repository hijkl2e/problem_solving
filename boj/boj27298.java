import java.math.BigInteger;
import java.util.Scanner;

public class boj27298 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		BigInteger[] A = new BigInteger[3];
		char[][] A_tab = new char[3][10];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 10; ++j) {
				A_tab[i][j] = (char) ('0' + j);
			}
		}
		A_tab[0][8] = A_tab[0][9] = '5';
		A_tab[1][8] = A_tab[1][9] = '6';
		A_tab[2][8] = '9';
		A_tab[2][9] = '8';
		for (int i = 0; i < 3; ++i) {
			StringBuilder sb = new StringBuilder();
			for (char c : S.toCharArray()) {
				sb.append(A_tab[i][c - '0']);
			}
			A[i] = new BigInteger(sb.toString());
		}
		BigInteger[] B = new BigInteger[4];
		char[][] B_tab = {
			{'0', '2', '1', '1', '4', '1', '1', '7', '1', '1'},
			{'0', '3', '3', '2', '4', '2', '2', '7', '2', '2'},
			{'0', '5', '5', '5', '4', '3', '3', '7', '3', '3'},
			{'0', '8', '8', '8', '4', '8', '9', '7', '5', '6'}
		};
		for (int i = 0; i < 4; ++i) {
			StringBuilder sb = new StringBuilder();
			for (char c : S.toCharArray()) {
				sb.append(B_tab[i][c - '0']);
			}
			B[i] = new BigInteger(sb.toString());
		}
		BigInteger A_sum = BigInteger.ZERO;
		for (int i = 0; i < 3; ++i) {
			A_sum = A_sum.add(A[i]);
		}
		BigInteger B_sum = BigInteger.ZERO;
		for (int i = 0; i < 4; ++i) {
			B_sum = B_sum.add(B[i]);
		}
		boolean flag = true;
		for (char c : S.toCharArray()) {
			if (c == '4' || c == '7') {
				flag = false;
				break;
			}
		}
		if (A_sum.compareTo(B_sum) == 1 && flag) {
			System.out.println(B_sum + " 4");
			for (int i = 0; i < 4; ++i) {
				System.out.println(B[i]);
			}
		} else {
			System.out.println(A_sum + " 3");
			for (int i = 0; i < 3; ++i) {
				System.out.println(A[i]);
			}
		}
		sc.close();
	}
}
