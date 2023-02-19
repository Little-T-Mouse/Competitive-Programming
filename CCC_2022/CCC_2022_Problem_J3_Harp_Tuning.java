import java.util.*;
public class CCC_2022_Problem_J3_Harp_Tuning {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine(), tmp = "";
	    for(int i=0; i<s.length(); i++){
	        if(tmp.length()!=0 && !Character.isDigit(s.charAt(i)) && Character.isDigit(s.charAt(i-1))){
	            System.out.println(tmp);
	            tmp = "";
	        }
	        if(Character.isUpperCase(s.charAt(i)) || Character.isDigit(s.charAt(i))){
	            tmp += s.charAt(i);
	        }
	        else if(s.charAt(i) == '-'){
	            tmp += " loosen ";
	        }
	        else if(s.charAt(i) == '+'){
	            tmp += " tighten ";
	        }
	    }
	    System.out.println(tmp);
		sc.close();
	}
}