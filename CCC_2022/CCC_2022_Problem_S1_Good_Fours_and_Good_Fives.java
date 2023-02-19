import java.util.*;
public class CCC_2022_Problem_S1_Good_Fours_and_Good_Fives {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), cnt = 0;
		for(int i=0; i<=N; i++) {
			if((N-i) % 4 == 0 && i % 5 == 0) {
				cnt++;
			}
		}
		System.out.println(cnt);
		sc.close();
	}
}