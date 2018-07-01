import java.util.Scanner;


public class Main {
	
	/* given a string returns the sum of all digits*/
	public static long sumOfDigits(String s){
		long res = 0;
		for(int i = 0; i < s.length() ; i++){
			res = res + Long.parseLong(String.valueOf(s.charAt(i))); 
		}
		return res;
	}
	
	
	

	public static void main(String[] args) {
	
		Scanner scanner = new Scanner(System.in);
		boolean finish = false;
        while (!finish) {
        	
	        	String myLine = scanner.nextLine();
	        	
	        	if(myLine.equals("0")){
	        		finish = true;
	        	}else{
	        		boolean oneDigit = false;
	        		
	        		long sum = Long.valueOf(myLine);
	        		while( !oneDigit ){
	        			sum = sumOfDigits(String.valueOf(sum));
	        			if(sum < 10){
	        				oneDigit = true;
	        			}
	        		}
	        		System.out.println(sum);
	        	}
        	}		
	}

}
