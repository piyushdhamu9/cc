// import java.util.Scanner;

// public class SampleDLL {
// 	static {
// 		System.loadLibrary("SampleDLL");
// 	}

// 	public native int add(int num1, int num2);

// 	public static void main(String args[]) {
// 		Scanner sc = new Scanner(System.in);
// 		int num1 = 0, num2 = 0;
// 		System.out.println("DLL Example Addition Operation");
// 		System.out.print("Enter first number: ");
// 		num1 = sc.nextInt();
// 		System.out.print("Enter second number: ");
// 		num2 = sc.nextInt();
// 		System.out.println("Result: "+new SampleDLL().add(num1,num2));
// 	}
// }


import java.util.Scanner;

public class SampleDLL {
    // Load the DLL (ensure the file name matches your compiled DLL)
    static {
        System.loadLibrary("SampleDLL"); // For Windows: SampleDLL.dll, for Linux: libSampleDLL.so
    }

    // Declare the native method
    public native int add(int num1, int num2);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("DLL Example: Addition Operation");

        // Taking input from the user
        System.out.print("Enter first number: ");
        int num1 = sc.nextInt();

        System.out.print("Enter second number: ");
        int num2 = sc.nextInt();

        // Create an instance to invoke the native method
        SampleDLL sampleDLL = new SampleDLL();
        int result = sampleDLL.add(num1, num2);

        // Display the result
        System.out.println("Result: " + result);

        // Close the scanner to prevent resource leaks
        sc.close();
    }
}

