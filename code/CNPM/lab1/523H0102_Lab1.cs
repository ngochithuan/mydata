using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            string name = txtName.Text;
            string birth = txtBirth.Text;
            string adress = txtAdress.Text;
            string city = txtCity.Text;
            string country = txtCountry.Text;
            string qua = txtQua.Text;
            string phone = txtPhone.Text;
            string email = txtEmail.Text;
            string join = txtJoin.Text;

            MessageBox.Show(name + "\n" + birth + "\n" + adress + "\n" + city + "\n" + country + "\n" + qua + "\n" + phone + "\n" + email + "\n" + join);
            
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void txtName_TextChanged(object sender, EventArgs e)
        {
            //cai nay

        }

    }
}
