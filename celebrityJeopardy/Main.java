import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
	       	try{
	        	String myLine = scanner.nextLine();
                
                System.out.println(myLine);
                
	        }catch(Exception e){
	        	System.out.println(e.getMessage());
	        
	        }
        }
	        
        scanner.close();
		System.exit(0);
	}

}
