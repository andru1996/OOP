using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOAIP_Lab_5
{
    class Series
    {
        private int linearNum;
        private int squareNum;
        private int fullNum;
        private Solution[] equation;

        public Series()
        {
            Console.WriteLine("Введите количество линейных уранений:");
            linearNum = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите количество квадратных уранений:");
            squareNum = Convert.ToInt32(Console.ReadLine());
            fullNum = linearNum + squareNum;
            equation = new Solution[fullNum];
            for(int i=0;i< linearNum;i++)
            {
                equation[i] = new Linear();
            }
            for(int i=linearNum;i<fullNum;i++)
            {
                equation[i] = new Square();
            }
        }

        public void SetVariables()
        {
            for(int i=0;i<fullNum;i++)
            {
                equation[i].SetVariables();
                equation[i].CalculateAnswer();
            }
        }

        public void ShowAnswers()
        {
            for (int i = 0; i < fullNum; i++)
            {
                equation[i].ShowAnswer();
            }
        }
    }
}
