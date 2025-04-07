import java.math.BigInteger;
import java.util.Scanner;

public class boj1914 {
	public static StringBuilder out = new StringBuilder();
	
	public static void solve(int n, int a, int b) {
		if (n == 0) {
			return;
		}
		solve(n - 1, a, a ^ b);
		out.append(a).append(" ").append(b).append("\n");
		solve(n - 1, a ^ b, b);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		out.append(BigInteger.ONE.shiftLeft(N).subtract(BigInteger.ONE)).append("\n");
		if (N < 21) {
			solve(N, 1, 3);
		}
		System.out.print(out);
		sc.close();
	}
}
