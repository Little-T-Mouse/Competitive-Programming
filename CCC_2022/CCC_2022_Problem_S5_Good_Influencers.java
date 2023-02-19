import java.util.*;
public class CCC_2022_Problem_S5_Good_Influencers {
	static int MAX = (int) (2e5+5);
	static int[][][] dp = new int [MAX][2][2];
	static int[][] tmpdp = new int [2][2];
	static int[] cost = new int [MAX]; 
	static LinkedList<Integer> graph[] = new LinkedList[MAX];
	static boolean[] want = new boolean[MAX];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i=0; i<MAX; i++){
            graph[i] = new LinkedList<>();
        }
	    for(int i=1, a, b; i<N; i++){
	        a = sc.nextInt(); b = sc.nextInt();
	        graph[a].add(b);
	        graph[b].add(a);
	    }
	    String s = sc.next();
	    for(int i=1; i<=N; i++){
	        want[i] = (s.charAt(i-1) == 'Y');
	        cost[i] = sc.nextInt();
	    }
	    dfs(1, 0);
	    System.out.println(Math.min(dp[1][1][0], dp[1][1][1]));
	    sc.close();
	}
	static void dfs(int cur, int pre){
	    dp[cur][0][0] = 0;
	    dp[cur][0][1] = cost[cur];
	    dp[cur][1][0] = want[cur]?0:0x3f3f3f3f;
	    dp[cur][1][1] = want[cur]?cost[cur]:0x3f3f3f3f;
	    for(int nxt: graph[cur]){
	        if(nxt == pre) continue;
	        dfs(nxt, cur);
	        for(int i=0; i<2; i++) {
	        	for(int j=0; j<2; j++) {
	        		tmpdp[i][j] = 0x3f3f3f3f;
	        	}
	        }
	        for(int i=0; i<2; i++){
	            for(int j=0; j<2; j++){
	                for(int m=0; m<2; m++){
	                    for(int n=0; n<2; n++){
	                        if(j==0 && m==0) continue;
	                        int p = i|(m&n);
	                        int q = j;
	                        tmpdp[p][q] = Math.min(tmpdp[p][q], dp[cur][i][j] + dp[nxt][m][n]);
	                    }
	                }
	            }
	        }
	        for(int i=0; i<2; i++) {
	        	for(int j=0; j<2; j++) {
	        		dp[cur][i][j] = tmpdp[i][j];
	        	}
	        }
	    }
	}
}