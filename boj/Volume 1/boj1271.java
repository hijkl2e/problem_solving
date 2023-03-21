import java.math.BigInteger;
import java.util.Scanner;

public class boj1271 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger N = sc.nextBigInteger();
		BigInteger M = sc.nextBigInteger();
		BigInteger[] res = N.divideAndRemainder(M);
		System.out.println(res[0]);
		System.out.println(res[1]);
		sc.close();
	}
}
