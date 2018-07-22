import java.util.Scanner;


public class Main {

	
	
	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		String myLine = scanner.nextLine();
		int testCases = Integer.valueOf(myLine);
		
		for(int i = 0; i < testCases ; i++){
			
			myLine = scanner.nextLine();
			
			String[] inputs = myLine.trim().split("\\s+");
			
			int gradoMaximo = Integer.valueOf(inputs[0]);
			int length = inputs.length;
			long[] polinomio = new long[length-1];
			
			 long d = Long.valueOf(scanner.nextLine());
			 long k = Long.valueOf(scanner.nextLine());
			/// armo el polinomio
			for(int j = 0; j < length-1; j++){
				polinomio[j] = Integer.valueOf(inputs[j+1]);
			}
			//armo la secueuncia
			//long acum =0;
			int h = 1;
			long acumulacioIndiceParcial = 0;
			boolean termine = false;
			while( !termine ){
				long termino = 0;
				for( int o = 0; o < polinomio.length; o++ ){
					termino =  (long) (termino + (polinomio[o]) * Math.pow(h, o));
				}
				//aca termine de evaluar el polinomio
				//acumulacioIndiceParcial = acumulacioIndiceParcial +(termino * d);
				acumulacioIndiceParcial = acumulacioIndiceParcial +(h * d);
				if(acumulacioIndiceParcial >= k){
					System.out.println(termino);
					termine = true;
				}
				h++;
			}
	
		}
		

	}

}
