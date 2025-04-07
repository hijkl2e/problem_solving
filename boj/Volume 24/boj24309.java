import java.math.BigInteger;
import java.util.Scanner;

public class boj24309 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger A = sc.nextBigInteger();
		BigInteger B = sc.nextBigInteger();
		BigInteger C = sc.nextBigInteger();
		System.out.println(B.subtract(C).divide(A));
		sc.close();
	}
}
