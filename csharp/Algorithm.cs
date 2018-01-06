using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm {
class Program {
	static void Main(string[] args) {
		//Calculator.printXto1(10);
		Console.WriteLine(Calculator.SumFrom1ToX(100));
	}
}
class Calculator {
	//public static void printXto1(int x)
	//{
	//    //for (int i = x; i > 0; --i)
	//    //{
	//    //    Console.WriteLine(i);
	//    //}
	//    if (x == 1)
	//        Console.WriteLine(1);
	//    else
	//    {
	//        Console.WriteLine(x);
	//        printXto1(x - 1);
	//    }
	//}
	public static int SumFrom1ToX(int x) {
		if(x == 1) {
			return 1;
		} else {
			int result = x + SumFrom1ToX(x - 1);
			return result;
		}
	}
}
}
