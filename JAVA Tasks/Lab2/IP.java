package labpkg;

import java.util.regex.*;
import java.util.StringTokenizer; 

class IP 
{
	public static void main(String[] args)
	{
		String IP = args[0];
		System.out.println(IP);
		String IPRegEx = "^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";
		boolean isIP = Pattern.compile(IPRegEx).matcher(IP).matches();
		if(isIP){
			System.out.println(" ");
			System.out.println("this is a valid IP");
			System.out.println(" ");
			System.out.println("slicing using split");
			System.out.println(" ");
			String[] parts = IP.split("\\.");
			for(String part : parts)
			System.out.println(part);
			
			System.out.println(" ");
			System.out.println("slicing using substrings");
			System.out.println(" ");
			String IPCopy=IP;
			int len = args[0].length();
			int dotInd = args[0].indexOf(".");
			String part= IPCopy.substring(0,dotInd);
			while(len >0 )
			{
			dotInd = IPCopy.indexOf(".");
			if(dotInd <=-1) {
				System.out.println(IPCopy);
				break; 
			}
			part= IPCopy.substring(0,dotInd);
			IPCopy = IPCopy.substring(dotInd+1);
			System.out.println(part);
			len--;
			}
			
			System.out.println(" ");
			System.out.println("slicing using string tokinizer");
			System.out.println(" ");
			StringTokenizer st = new StringTokenizer(IP,".");  
			while (st.hasMoreTokens()) {  
				System.out.println(st.nextToken());  
			}  
			
			
		}
		else{System.out.println("this is not a valid IP");}
		
		
	}
}