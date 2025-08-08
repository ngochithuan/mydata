using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace Lab02
{
    internal class Connection
    {
        //SQLEXPRESS
        //private static string stringConnection = "Data Source=.;Initial Catalog=school;Integrated Security=True";
        private static string stringConnection = "Data Source=.\\SQLEXPRESS;Initial Catalog=school;Integrated Security=True";

        public static SqlConnection GetConnection()
        {
            return new SqlConnection(stringConnection);
        }

    }
}
