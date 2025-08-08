using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
using Lab02;
using System.Windows.Forms;
using System.Reflection;

namespace Lab02
{
    internal class Modify
    {
        SqlDataAdapter dataAdapter; // Truy suất data vào bảng 
        SqlCommand sqlCommand; // Dùng để truy vấn và cập nhật tới CSDL
        public Modify()
        {
        }

        public DataTable getAllStudent()
        {
            DataTable dataTable = new DataTable();
            string query = "select * from student";

            using (SqlConnection sqlConnection = Connection.GetConnection())
            {
                sqlConnection.Open();

                dataAdapter = new SqlDataAdapter(query, sqlConnection);
                dataAdapter.Fill(dataTable);

                sqlConnection.Close();
            }
            return dataTable;
        }

        public bool addHandler(Student student)
        {
            SqlConnection sqlConnection = Connection.GetConnection();
            string query = "insert student values (@hoTen,@ngaysinh,@gioiTinh,@email)";

            try
            {
                sqlConnection.Open();
                sqlCommand = new SqlCommand(query, sqlConnection);
                sqlCommand.Parameters.Add("@hoTen", SqlDbType.NVarChar).Value = student.Name;
                sqlCommand.Parameters.Add("@ngaysinh", SqlDbType.DateTime).Value = student.Bitrh.ToShortDateString(); // dd/mm/yyyy
                sqlCommand.Parameters.Add("@gioiTinh", SqlDbType.Bit).Value = student.Sex;
                sqlCommand.Parameters.Add("@email", SqlDbType.NVarChar).Value = student.Email;
                sqlCommand.ExecuteNonQuery(); // execute the query command
            }
            catch
            {
                return false;
            }
            finally { sqlConnection.Close(); }
            return true;
        }

        public bool updateHandler(Student student, int id)
        {
            SqlConnection sqlConnection = Connection.GetConnection();
            string query = "update student set hoTen = @Name, ngaySinh = @BirthDate, gioiTinh = @Sex, email = @Email where maso = @id";

            try
            {

                sqlConnection.Open();
                sqlCommand = new SqlCommand(query, sqlConnection);

                sqlCommand.Parameters.Add("@Name", SqlDbType.NVarChar).Value = student.Name;
                sqlCommand.Parameters.Add("@BirthDate", SqlDbType.DateTime).Value = student.Bitrh.ToShortDateString(); // dd/mm/yyyy
                sqlCommand.Parameters.Add("@Sex", SqlDbType.Bit).Value = student.Sex;
                sqlCommand.Parameters.Add("@Email", SqlDbType.NVarChar).Value = student.Email;
                sqlCommand.Parameters.Add("@id", SqlDbType.Int).Value = id;
                sqlCommand.ExecuteNonQuery();
            }
            catch
            {
                return false;
            }
            finally { sqlConnection.Close(); }
            return true;

        }

        public bool deleteHandler(int id)
        {
            SqlConnection sqlConnection = Connection.GetConnection();
            string query = "delete from student where maso = @id";

            try
            {
                sqlConnection.Open();
                sqlCommand = new SqlCommand(query, sqlConnection);
                sqlCommand.Parameters.Add("@id", SqlDbType.Int).Value = id;
                sqlCommand.ExecuteNonQuery();
            }
            catch
            {
                return false;
            }
            finally { sqlConnection.Close(); }
            return true;

        }

    }
}
