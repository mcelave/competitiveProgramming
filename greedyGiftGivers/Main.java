import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Scanner;


public class Main {
//greedy gift givers
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNextLine()) {
		       	try{
		       		
		       		int cantPersonas = Integer.valueOf(scanner.nextLine());
		       		HashMap<String,Integer> resultados = new LinkedHashMap<String, Integer>();
		       		String lineaNombres = scanner.nextLine();
		       		String[] nombres = lineaNombres.trim().split("\\s+");
		       	
		       		for(int j=0; j < nombres.length; j++){
		       				resultados.put(nombres[j],0);
		       		}
		       		
		     		for(int i = 0; i < cantPersonas; i++){	
		     			String regalo = scanner.nextLine();
		     			String[] partesDeRegalo = regalo.trim().split("\\s+");
		     			int cantidadArepartir = Integer.valueOf(partesDeRegalo[1]);
		     			//analizar caso borde con cantidades 0 y 0 regalos
		     			
		     			int cantidadDePersonasAregalar = Integer.valueOf(partesDeRegalo[2]);
		     			int gastoEnRegalos =0;
		     			if( cantidadDePersonasAregalar != 0 ){
		     				 gastoEnRegalos = cantidadArepartir/cantidadDePersonasAregalar;
		     				 String nombreADebitar = partesDeRegalo[0];
		     				 int cantADebitar = gastoEnRegalos * cantidadDePersonasAregalar;
		     				 int acum = resultados.get(nombreADebitar);
		     				 resultados.put(nombreADebitar, acum - cantADebitar );
		     			}
		     			
		     			
		     			for(int j = 0; j < cantidadDePersonasAregalar; j++ ){
		     				String persona = partesDeRegalo[j+3];
		     				int acum2 = resultados.get(persona);
		     				resultados.put(persona, acum2+gastoEnRegalos);
		     			}
		     			
		       		}
		       		
		     		//pongo el output
		     		for( String s : resultados.keySet()){
		     			System.out.println(s + " " +resultados.get(s));
		     		}
		     	
		     		if(scanner.hasNextLine()){
		     			System.out.println();
		     			
		     		}
		       		
	                
		        }catch(Exception e){
		        	System.out.println(e.getMessage());
		        
		        }
	        }
		        
	        scanner.close();
			System.exit(0);
		
		

	}

}
