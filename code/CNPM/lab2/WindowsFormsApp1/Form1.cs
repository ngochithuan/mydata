using Lab02;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        SqlCommand sqlCommand;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        Modify modify;
        
        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            modify = new Modify();
            try
            {
                dataGridView1.DataSource = modify.getAllStudent();
            }
            catch (Exception ex) {
                MessageBox.Show("Error occoured: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

       
    

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        Student student;
        private void button4_Click(object sender, EventArgs e)
        {
            string name = this.txtNameBox.Text;
            bool sex = this.rbtnMale.Checked;
            DateTime birth = this.dateTimePicker1.Value;
            string email = this.txtEmailBox.Text;
            student = new Student(name, birth, sex, email);


            if (modify.addHandler(student))
            {
                dataGridView1.DataSource = modify.getAllStudent();
            }
            else
            {
                MessageBox.Show("Error occoured: " + "Cannot add student info", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // DELETE BUTTON
            if (modify.deleteHandler(slt_id))
            {
                dataGridView1.DataSource = modify.getAllStudent();
            }
            else
            {
                MessageBox.Show("Error occoured: " + "Cannot add student info", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // UPDATE BUTTON
            //MessageBox.Show(selectedStudent.toString() + " " + slt_id);
            string name = this.txtNameBox.Text;
            bool sex = this.rbtnMale.Checked;
            DateTime birth = this.dateTimePicker1.Value;
            string email = this.txtEmailBox.Text;
            Student newStudent = new Student(name, birth, sex, email);

            if (modify.updateHandler(newStudent, slt_id))
            {
                dataGridView1.DataSource = modify.getAllStudent();
                
            }
            else
            {
                MessageBox.Show("Error occoured: " + "Cannot update student info", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void txtNameBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        public int slt_id;
        public string slt_hoTen = "";
        public string Dslt_ngaysinh = "";
        public string Bslt_gioiTinh = "";
        public string slt_email = "";
        
        Student selectedStudent = new Student();


        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int index = e.RowIndex;
            DataGridViewRow selectedRow = dataGridView1.Rows[index];
            slt_hoTen = selectedRow.Cells[1].Value.ToString();
            Dslt_ngaysinh = selectedRow.Cells[2].Value.ToString();
            Bslt_gioiTinh = selectedRow.Cells[3].Value.ToString();
            slt_email = selectedRow.Cells[4].Value.ToString();
            string Sslt_id = selectedRow.Cells[0].Value.ToString();
            slt_id = int.Parse(Sslt_id); 

            DateTime slt_ngaysinh = DateTime.Parse(Dslt_ngaysinh);
            bool slt_gioiTinh = bool.Parse(Bslt_gioiTinh);

            selectedStudent = new Student(slt_hoTen, slt_ngaysinh, slt_gioiTinh, slt_email);

            txtNameBox.Text = slt_hoTen;
            if (slt_gioiTinh == true)
            {
                rbtnMale.Checked = true;
            }
            else
            {
                radioButton2.Checked = true;
            }
            dateTimePicker1.Text = slt_ngaysinh.ToString();
            txtEmailBox.Text = slt_email;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //CLEAR BUTTON
            txtNameBox.Text = "";
            rbtnMale.Checked = false;
            radioButton2.Checked = false;
            dateTimePicker1.Text = DateTime.Today.ToString();
            txtEmailBox.Text = "";

        }
    }
}
