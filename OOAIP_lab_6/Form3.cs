using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OOAIP_lab_6
{
    public partial class Form3 : Form
    {
        Linear linear = new Linear();
        public Form3()
        {
            InitializeComponent();
        }

        public Form3(Form1 f)
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(Convert.ToDouble(textBox1.Text) == 0)
            {
                label6.Text = "Ошибка: a не может быть 0";
                return;
            }    
            else label6.Text = "";
            linear.SetA(Convert.ToDouble(textBox1.Text));
            linear.SetB(Convert.ToDouble(textBox2.Text));
            linear.CalculateAnswer();
            label3.Text = $"Ответ: x = {linear.GetAnswer()}";
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
