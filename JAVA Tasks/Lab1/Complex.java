package labpkg;
class Complex 
{
	public int real;
	public int imaginary;

	Complex(){}
  
    Complex(int argReal, int argImaginary)
    {
        real = argReal;
        imaginary = argImaginary;
    }
  
    public Complex addComp(Complex C1, Complex C2)
    {
        Complex temp = new Complex();
        temp.real = C1.real + C2.real;
        temp.imaginary = C1.imaginary + C2.imaginary;
        return temp;
    }

    public Complex subtractComp(Complex C1, Complex C2)
    {
        Complex temp = new Complex();
        temp.real = C1.real - C2.real;
        temp.imaginary = C1.imaginary - C2.imaginary;
        return temp;
    }
 
    void printComplexNumber()
    {
        System.out.println(real + " + " + imaginary + "i");
    }
	
	public static void main(String[] args)
	{
		Complex c1 = new Complex(8,2);
		Complex c2 = new Complex(5,1);
		Complex added = new Complex();
		added = added.addComp(c1,c2);
		Complex subtracted =new Complex();
		subtracted = subtracted.subtractComp(c1,c2);
		System.out.print("c1 + c2 = ");
		added.printComplexNumber();
		System.out.print("\nc1 - c2 = ");
		subtracted.printComplexNumber();
	}
}