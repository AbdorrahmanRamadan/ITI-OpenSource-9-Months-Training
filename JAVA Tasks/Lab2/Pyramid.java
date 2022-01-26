package labpkg;

public class Pyramid
{

	public static void main(String[] args)
	{ 
		int NumberOfRows = 4; 
		int spaceInverted=0;

	    for (int i =0; i < NumberOfRows; ++i) {
	    	
	      for (int j = 0; j <= i; ++j) {
	        System.out.print("* ");
	      }
	      
	      for (int j=NumberOfRows-spaceInverted; j>0; j--)   
		    {   
		    System.out.print("   ");   
		    } 
	      
	      for (spaceInverted=0; spaceInverted<=i; spaceInverted++ )   
		    {   
		    System.out.print("* ");   
		    }  
	      
	      
	      System.out.println();
	    }
	    
	    
	}   

}
