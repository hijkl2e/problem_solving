import java.math.BigDecimal;
import java.math.MathContext;
import java.util.Scanner;

public class boj15858 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigDecimal A = sc.nextBigDecimal();
		BigDecimal B = sc.nextBigDecimal();
		BigDecimal C = sc.nextBigDecimal();
		System.out.println(A.multiply(B).divide(C, new MathContext(30)));
		sc.close();
	}
}
