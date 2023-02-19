import java.util.*;
public class CCC_2022_Problem_J2_Fergusonball_Ratings {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), cnt = 0;
	    for(int i=0; i<N; i++){
	        int a = sc.nextInt(), b = sc.nextInt();
	        if(a*5 - b*3 > 40) cnt++;
	    }
	    if(cnt == N) System.out.println(cnt + "+");
	    else System.out.println(cnt);
		sc.close();
	}
}