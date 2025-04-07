import java.math.BigInteger;
import java.util.Scanner;

public class boj25922 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder out = new StringBuilder();
		int N = sc.nextInt();
		BigInteger[] A = new BigInteger[N + 1];
		for (int i = 0; i <= N; ++i) {
			System.out.println("? " + (i + 1));
			System.out.flush();
			A[i] = sc.nextBigInteger();
		}
		BigInteger[][] B = new BigInteger[N + 1][N + 1];
		for (int i = 0; i <= N; ++i) {
			B[i][0] = BigInteger.ONE;
			for (int j = 1; j <= N; ++j) {
				B[i][j] = B[i][j - 1].multiply(BigInteger.valueOf(i + 1));
			}
		}
		for (int i = 0; i <= N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				BigInteger x = B[j][i].divide(B[i][i]);
				A[j] = A[j].subtract(A[i].multiply(x));
				for (int k = i; k <= N; ++k) {
					B[j][k] = B[j][k].subtract(B[i][k].multiply(x));
				}
			}
		}
		for (int i = N; i >= 0; --i) {
			A[i] = A[i].divide(B[i][i]);
			for (int j = 0; j < i; ++j) {
				A[j] = A[j].subtract(A[i].multiply(B[j][i]));
			}
		}
		out.append("! ");
		for (int i = 0; i <= N; ++i) {
			out.append(A[i]).append(i == N ? "\n" : " ");
		}
		System.out.print(out);
		sc.close();
	}
}
