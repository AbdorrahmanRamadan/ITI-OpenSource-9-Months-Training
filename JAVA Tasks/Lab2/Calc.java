package labpkg;
class Calc 
{
	public static void main(String[] args)
	{
		System.out.print(args[0]);
		System.out.print(" "+args[1]+" ");
		System.out.print(args[2]);
		System.out.print(" = ");
		Float firstNum = Float.parseFloat(args[0]);
		Float secondNum = Float.parseFloat(args[2]);
		String total;
		switch(args[1]) {
			case "+":
				total = String.valueOf(firstNum+secondNum);
			break;
			case "-":
				total = String.valueOf(firstNum-secondNum);
			break;
			case "x":
			case "X":
				total = String.valueOf(firstNum*secondNum);
			break;
			case "/":
				total = String.valueOf(firstNum/secondNum);
			break;
			case "%":
				total = String.valueOf(firstNum%secondNum);
			break;
			default:
				total = "can't use this operator";
		}
		System.out.print(total);
	}
}