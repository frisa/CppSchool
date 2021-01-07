using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamplesCS
{
	class A
	{
		int a;
		public int b;
	}

	interface IA
	{
		int fcn();
	}
	struct SA
	{
		int fcn()
		{
			return 0;
		}
	}

	abstract class AA
	{
		public abstract void fcn();
		public void fcnI()
		{
			
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			A aa = new A();
			aa.b = 0;
			//IA ia = new IA();
			//int x = ia.fcn();
		}
	}
}
