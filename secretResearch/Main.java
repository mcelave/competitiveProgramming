import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int cases = Integer.valueOf(scanner.nextLine());
		
		for( int i = 0; i < cases; i++ ){ 	
			
			String myLine = String.valueOf(scanner.nextLine());
        	
			if( myLine.equals("1") ||  myLine.equals("4") || myLine.equals("78") ){
        		System.out.println("+");
        	}else{
        		if( (myLine.charAt(myLine.length()-1) == '5') &&   (myLine.charAt(myLine.length()-2) == '3') ){
        			System.out.println("-");
        		}else{
        			if( (myLine.charAt(0)== '9' ) && (myLine.charAt(myLine.length()-1) == '4' ) ){
        				System.out.println("*");
        			}else{
        				if( myLine.startsWith("190")) {
        					System.out.println("?");
        				}
        			}
        		}
        	}
		}
		System.exit(0);
	}

}
