import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int cases = Integer.valueOf(scanner.nextLine());
		for( int i = 0; i < cases; i++ ){
			String myLine = String.valueOf(scanner.nextLine());
			String[] inputs = myLine.trim().split("\\s+");
        	int  n  		= Integer.valueOf(inputs[0]);
            int  m  = Integer.valueOf(inputs[1]);
            int answer = (int) Math.ceil(n/3) * (int) Math.ceil(m/3);
         
            System.out.println(answer);
            
			
		}
		
		
		

	}

}
