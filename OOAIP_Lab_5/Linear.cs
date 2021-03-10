using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOAIP_Lab_5
{
    class Linear : Solution
    {
        public Linear()
        {
            variables = new double[2];
            answers = new double[1];
        }

        public Linear(double a, double b)
        {
            variables = new double[2];
            answers = new double[1];
            if (a == 0) throw new Exception("первый параметр линейного уранения равен 0");
            variables[0] = a;
            variables[1] = b;
        }

        public override void SetVariables()
        {
            Console.WriteLine("Введите параметры линейного уравнения: ");
            Console.WriteLine("Введите переменную a: ");
            variables[0] = Convert.ToDouble(Console.ReadLine());
            if (variables[0] == 0) throw new Exception("первый параметр линейного уранения равен 0");
            Console.WriteLine("Введите переменную b: ");
            variables[1] = Convert.ToDouble(Console.ReadLine());
        }

        public override void CalculateAnswer()
        {
            answers[0] = -variables[1] / variables[0];
        }

        public override void ShowAnswer()
        {
            Console.WriteLine($"Ответ линейного уравнения: x={answers[0]}");
        }
    }
}
