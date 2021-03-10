using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOAIP_Lab_5
{
    class Square : Solution
    {
        private double d;
        public Square()
        {
            variables = new double[3];
            answers = new double[2];
        }

        public Square(double a, double b, double c)
        {
            variables = new double[3];
            answers = new double[2];

            variables[0] = a;
            variables[1] = b;
            variables[2] = c;
        }

        public override void SetVariables()
        {
            Console.WriteLine("Введите параметры квадратного уравнения: ");
            Console.WriteLine("Введите переменную a: ");
            variables[0] = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите переменную b: ");
            variables[1] = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите переменную c: ");
            variables[2] = Convert.ToDouble(Console.ReadLine());
        }

        public override void CalculateAnswer()
        {
            d = variables[1] * variables[1] - (4 * variables[0] * variables[2]);
            if(d>0)
            {
                answers[0] = (-variables[1] + Math.Sqrt(d)) / (2 * variables[0]);
                answers[1] = (-variables[1] - Math.Sqrt(d)) / (2 * variables[0]);
            }

            if(d == 0)
            {
                answers[0] = -variables[1] / (2 * variables[0]);
            }
        }

        public override void ShowAnswer()
        {
            if(d>0)
            {
                Console.WriteLine($"Ответ квадратного уравнения: x1={answers[0]} x2={answers[1]}");
            }
            if(d==0)
            {
                Console.WriteLine($"Ответ квадратного уравнения: x={answers[0]}");
            }
            if(d<0)
            {
                Console.WriteLine("Нет корней уравнения.");
            }
        }
    }
}
