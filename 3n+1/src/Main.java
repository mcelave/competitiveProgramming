import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		
			Scanner scanner = new Scanner(System.in);
			long[][] longitudes = new long[10000][1];

	        while (true) {
		       	try{
		        	String myLine = scanner.nextLine();
		        	if(myLine == null || myLine.isEmpty()){
		        		scanner.close();
		        		System.exit(0);
		        	} 
		        	long i = 0,j  =0,idisplay =0,jdisplay=0;
		            try {
		            	String[] inputs = myLine.trim().split("\\s+");
		                 i = Long.valueOf(inputs[0]);
		                 j = Long.valueOf(inputs[1]);
		                 idisplay = i;
		                 jdisplay=j;
		                 if( i > j  ){
		                	 long aux = i;
		                	 i = j;
		                	 j= aux;
		                 }
		              
		                 long max = 0;
		                 
		                 for( long k=i; k <= j; k++ ){
		                	 long currentValue = k;
		                	 boolean foundBefore = false;
		                	 long res = 1;
		                	 while( currentValue != 1 && !foundBefore ){
		                		 
		                		 if( currentValue < k &&  currentValue < 10000 && longitudes[(int) currentValue][0] != 0 ){ //uso que todo empieza en 0
		                			 foundBefore = true;
		                			 res= res + longitudes[(int) currentValue][0] - 1; // le resto uno porque lo increment al final del ciclo
		                			
		                		 }else{
		                			 
		                			 if( currentValue % 2 == 0 ){
		                				 currentValue = currentValue/2;
		                			 }else{
		                				 currentValue = currentValue*3 + 1;
		                			 }
		                			 res++;
		                		 }
		                	 }
		                	 if(res > max){
		                		 max = res;
		                	 }
		                	 if(k < 10000){
		                		 longitudes[(int) k][0] = res; // agrego el 1 incluido
		                	 }
		                 }
		                 
		                 System.out.println(idisplay + " " +jdisplay + " " +max);
		            }catch (Exception ex){
		                System.out.println(ex.getMessage());
		            }
			        }catch(Exception e){
			        	break;
			        }
		            
		        }
	        
	}

}