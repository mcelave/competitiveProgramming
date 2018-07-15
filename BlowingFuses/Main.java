import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Scanner;


public class Main {

	
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int sequence = 1;
        while (true) {
	       	try{
	        	String myLine = scanner.nextLine();
	        	String[] inputs = myLine.trim().split("\\s+");
	        	if(inputs.length >= 3){
	        	
			        	if( inputs[0].equals("0") && inputs[1].equals("0") && inputs[2].equals("0") ){
			        		scanner.close();
			        		System.exit(0);
			        	
			        	}else{
			        		
			        		int devices = Integer.valueOf(inputs[0]);
			        		int operationsPerformed = Integer.valueOf(inputs[1]);
			        		int capacityOfFuse = Integer.valueOf(inputs[2]);
			        		//inicializo diccionario todas va a estar false
			        		HashMap<Integer,Boolean> onOrOff = new LinkedHashMap<Integer, Boolean>();
			        		for( int i = 1; i <=  devices ; i++ ){
			        			onOrOff.put(i,false);
			        		}
			        		
			        		HashMap<Integer,Integer> consumes = new LinkedHashMap<Integer, Integer>();
			        		for( int k =1; k <= devices; k++ ){
			        			int con = scanner.nextInt();
			        			consumes.put(k,con);
			        		}
			        		/// hasta aqui esta cardao el diccionario de consumos
			        		//empiezo a iterr
			        		int acum =0;
			        		int max = 0;
			        		boolean blown = false;
			        		for(int k =1; k <= operationsPerformed;k++ ){
			        			int operation = scanner.nextInt();
			        			if(onOrOff.get(operation) ){//if its on I turn it off and change the acum minus the consume of that device
			        				onOrOff.put(operation,false);
			        				acum = acum - consumes.get(operation); 
			        			}else{ //if its off i turn it on and change the acum plus  the consume of that device
			        				//acum = acum + consumes.get(operation); 
			        				onOrOff.put(operation,true);
			        				if( acum + consumes.get(operation) > capacityOfFuse){
			        					blown = true;
			        				}else{
			        					acum = acum + consumes.get(operation); 
			        				}
			        			}
			        			if(acum > max ){
			        				max = acum;
			        			}
			        		}
			        		
			        		System.out.println("Sequence " + sequence);
			        		if(blown){
			        			System.out.println("Fuse was blown.");
			        		}else{
			        			System.out.println("Fuse was not blown.");
			        			System.out.println("Maximal power consumption was "+max + " amperes.");
			        		}
			        		System.out.println();
			        		sequence++;
			        	}
	        	}
	        	
	       	}catch( Exception e ){
	       		System.out.println(e.getMessage());
	       		
	       	}
	        	
        }
	}
}
	
	
	


