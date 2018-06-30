

import java.util.Scanner;

public class Main {
	
public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		boolean finish = false;
        while (true) {
	       	try{
	        	int base = 1080; //two full turns + 1 full counter clockwise turn
	        	int answer = 0;
	        	
	       		String myLine = scanner.nextLine();
	        	String[] inputs = myLine.trim().split("\\s+");
	        	int  init  		= Integer.valueOf(inputs[0]);
                int  firstSpin  = Integer.valueOf(inputs[1]);
                int  secondSpin = Integer.valueOf(inputs[2]);
                int  thirdSpin  = Integer.valueOf(inputs[3]);
                if(init == 0 && firstSpin == 0 && secondSpin ==0 && thirdSpin == 0){
                	scanner.close();
                	System.exit(0);
                }
                answer = base;
                //360 degrees == 40 number 1 number  = 9 degrees
                answer = answer+( (init - firstSpin) > 0 ? (init - firstSpin ) *9 : (init - firstSpin + 40) *9 );
                answer = answer + ((secondSpin - firstSpin) > 0 ? (secondSpin - firstSpin ) *9 : (secondSpin - firstSpin + 40) *9);
                answer = answer +( (secondSpin - thirdSpin) > 0 ? (secondSpin - thirdSpin ) *9 : (secondSpin - thirdSpin + 40) *9);
	        	
  
                
                System.out.println(answer);
                
	        }catch(Exception e){
	        	System.out.println(e.getMessage());
	        
	        }
        }
	        
       
	}

}
