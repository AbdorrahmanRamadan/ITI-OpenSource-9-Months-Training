package labpkg; 

import java.io.*;

class ReadFromFile { 
  
    public static void main (String[] args)
	{	
		try{
		FileInputStream fis = new FileInputStream("labpkg/sample.txt");
		int size = fis.available();
		byte[] b = new byte[size];
		fis.read(b);
		System.out.println(new String(b));
		fis.close();
		}catch(Exception e){ System.out.println("exception caught");}
	}       
} 