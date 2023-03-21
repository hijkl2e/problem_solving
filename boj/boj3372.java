import java.math.BigInteger;
import java.util.Scanner;

public class boj3372 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] A = new int[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				A[i][j] = sc.nextInt();
			}
		}
		BigInteger[][] dp = new BigInteger[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dp[i][j] = BigInteger.ZERO;
			}
		}
		dp[0][0] = BigInteger.ONE;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (A[i][j] == 0) {
					continue;
				}
				if (j + A[i][j] < N) {
					dp[i][j + A[i][j]] = dp[i][j + A[i][j]].add(dp[i][j]);
				}
				if (i + A[i][j] < N) {
					dp[i + A[i][j]][j] = dp[i + A[i][j]][j].add(dp[i][j]);
				}
			}
		}
		System.out.println(dp[N - 1][N - 1]);
		sc.close();
	}
}
