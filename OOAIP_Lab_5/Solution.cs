using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOAIP_Lab_5
{
    class Solution
    {
        protected double[] variables;
        protected double[] answers;

        public virtual void SetVariables() { }
        public virtual void CalculateAnswer() { }
        public virtual void ShowAnswer() { }
    }
}
