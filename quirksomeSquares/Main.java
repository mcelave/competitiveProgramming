import java.util.Scanner;


//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=640&page=show_problem&problem=192
public class Main {

	
	public static int maxNumber(int number){
		if(number == 2){
			
			return 99;
		}
		
		if(number == 3){
			
			return 999;
		}
		
		if(number == 4){
			
			return 9999;
		}
		
		if(number == 8){
			
			return 99999999;
		}
		return 0;
		
	}
	
	public static String completeWithLeadingZeros(int numberOfDigits, int number ){
		
		int leadingZeros =  numberOfDigits - String.valueOf(number).length();
		
		String zeros ="";
		
		for(int i = 1; i <= leadingZeros; i++ ){
			zeros= zeros+"0";
		}
		
		return  zeros+ String.valueOf(number);
		
	}
	
	public static void displaySolution( int number ){
		// this solutions comes from solving the problema whith the comented lines
		
		if(number == 2){
			System.out.println("00");
			System.out.println("01");
			System.out.println("81");
		}
		
		if(number == 3){
			
			System.out.println("000");
			System.out.println("001");
		}
		
		
		
		if(number == 4){
			
			System.out.println("0000");
			System.out.println("0001");
			System.out.println("2025");
			System.out.println("3025");
			System.out.println("9801");
		}
		
			if(number == 6){
			System.out.println("000000");
			System.out.println("000001");
			System.out.println("088209");
			System.out.println("494209");
			System.out.println("998001");
		}
		
		if(number == 8){
			System.out.println("00000000");
			System.out.println("00000001");
			System.out.println("04941729");
			System.out.println("07441984");
			System.out.println("24502500");
			System.out.println("25502500");
			System.out.println("52881984");
			System.out.println("60481729");
			System.out.println("99980001");
			
		}

	}

	
	
	
	

	

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
	       	try{
	        	String myLine = scanner.nextLine();
	        	
                int numberOfDigits = Integer.valueOf(myLine);
                
                displaySolution(numberOfDigits);
              /*  int top = maxNumber(numberOfDigits);
                
                for( int i = 0 ; i <= top; i++ ){
                	String value = completeWithLeadingZeros(numberOfDigits, i);
                	String firstHalf = value.substring(0, value.length()/2);
                	String secondHalf = value.substring(value.length()/2,value.length());
                	
                	int firstHalfnumber = Integer.valueOf(firstHalf);
                	int secondHalfnumber = Integer.valueOf(secondHalf);
                	int sumParts = (firstHalfnumber + secondHalfnumber);
                	int sumSquares = (sumParts * sumParts);
                	if (sumSquares == i){
                		System.out.println(value);
                	}
                	 
                } */
	        	
                
	        }catch(Exception e){
	        	System.out.println(e.getMessage());
	        
	        }
        }
	        
        scanner.close();
		System.exit(0);
		
		

	}

}
