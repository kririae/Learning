using System;
using System.Linq;
using System.Windows.Forms;
namespace LearningCsharp
{
class Program
{
	static void Main(string[] args)
	{
		Form F = new Form();
		//string str = "Hello";
		/*var a = "HelloWorld";
		Console.WriteLine(a.GetType().Name);
		var b = 3;
		Console.WriteLine(b.GetType().Name);
		var c = 3.0F;
		Console.WriteLine(c.GetType().Name);
		var d = 3.0;
		Console.WriteLine(d.GetType().Name);*/
		Console.WriteLine(Calculator.Add(1, 2));
		string str = Calculator.Today();
		Console.WriteLine(str);
		Calculator.printSum(4, 6);
		//程序 = 数据 + 算法
	}
}
class Calculator
{
	public static int Add(int a, int b)
	{
		return a + b;
	}
	public static string Today()
	{
		int day = DateTime.Now.Day;
		return day.ToString();
	}
	public static void printSum(int a, int b)
	{
		int result = a + b;
		Console.WriteLine(result);
	}
}
}