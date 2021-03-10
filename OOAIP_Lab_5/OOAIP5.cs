using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace OOAIP_Lab_5
{
    class OOAIP5
    {
        static void Main(string[] args)
        {
			try
			{
				Series a = new Series();
				a.SetVariables();
				a.ShowAnswers();
			}
			catch (Exception a)
			{
				Console.WriteLine($"Error: {a.Message}");
			}

			Console.ReadKey();
        }
    }
}
