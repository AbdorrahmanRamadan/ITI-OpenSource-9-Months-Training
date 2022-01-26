import java.util.*; 
import java.util.stream.*;
import java.util.Date;
import java.time.*;
import java.time.temporal.ChronoUnit;

@FunctionalInterface
interface NumericTest
{ 
    boolean test(int n, int m);
}

@FunctionalInterface
interface StringFunction {
    String applyFunction(String s);
}

@FunctionalInterface
interface StringConsumer {
void consumeFunction(String s);
}

class Utils {
    public static String transform(String st,StringFunction f) 
    {
        return(f.applyFunction(st));
    }
    public static void byebye(String st, StringConsumer f)
    {
        f.consumeFunction(st);
    }
    public static String makeExciting(String s) 
    {
        return(s + " ** !!");
    }
    private Utils() {}
}

class App{
    public static void main(String[] args){
        ArrayList<String> items = new ArrayList<>();
        items.add("A");
        items.add("B");
        items.add("C");
        items.add("D");
        items.add("E");
		System.out.println("printing ArrayList items using lambda expression \nitems.forEach(item -> System.out.println(item));");
        items.forEach(item -> System.out.println(item));
		System.out.println("printing ArrayList items using Method Reference\nitems.forEach(System.out::println);");
        items.forEach(System.out::println);
		System.out.println("using NumericTest Functional interface to find if number is a factor of another number");
        NumericTest isFactor = (n, d) -> (n % d) == 0; 
        if(isFactor.test(10, 2)) System.out.println("2 is a factor of 10"); 
        if(!isFactor.test(10, 3)) System.out.println("3 is not a factor of 10"); 
		System.out.println("using NumericTest Functional interface to find if number is less than another number");
        NumericTest lessThan = (n, m) -> (n < m);
        if(lessThan.test(2, 10)) System.out.println("2 is less than 10");
		
		System.out.println("using Utils class with  Functional interfaces to demonstrate the usage of method references");
        String s = "TestITI";
		System.out.print("\n1 Class::StaticMethod ");
        String result1 = Utils.transform(s, Utils::makeExciting);
        System.out.print(result1 + "\n");
        String prefix = "Blah @@ ";
		System.out.print("\n2- object::instance method: ");
        String result2 = Utils.transform(s, prefix::concat); 
        System.out.print(result2 + "\n");
		System.out.print("\n3- Class::instance Method: ");
        String result3 = Utils.transform(s, String::toUpperCase);
        System.out.print(result3 + "\n");
		System.out.print("\n4- Class::constructor: ");
        String result4 = Utils.transform("hi - > "+s, String::new);
        System.out.print(result4 + "\n");


        System.out.print("\n StreamAPI:- ");
        int[] values = {1, 5, 8, 7, 6, 3, 2, 9, 4};
        IntStream.of(values).filter(value -> value % 2 == 0).sorted().forEach(value -> System.out.printf("%d%n", value));
        System.out.printf("%d%n", IntStream.of(values).count());
        System.out.printf("%d%n", IntStream.of(values).max().getAsInt());
        System.out.printf("%d%n", IntStream.of(values).sum());

		
		System.out.print("\n DateAPI:- ");
        Date date = new Date(12, 12, 12);
        System.out.println(date);
        LocalDate  day = LocalDate.of(1931, Month.OCTOBER, 15);
        System.out.println(day);
        LocalDate computerBirth = LocalDate.ofEpochDay(1); 
        System.out.println(computerBirth); 
        Instant start= Instant.now();
        Instant end= Instant.now();
        Duration d=Duration.between(start, end);
        System.out.println("Time between "+ d.toMillis());
        LocalDate now = LocalDate.now();
        LocalDate past = LocalDate.of(1564, Month.APRIL, 23);
        Period p = past.until(now);
        System.out.println("years =" + p.getYears());

    }
}






