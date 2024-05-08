using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace CSharpOnVS
{
    class Program
    {
        static void Main()
        {

            string firstName;
            string lastName;

            //1 Address of SQL server and Database
            string connectionString = "Data Source=DESKTOP-MI40F6K;Initial Catalog=NorthWind;Integrated Security=True;";

            //2 Establish Connection
            SqlConnection con = new SqlConnection(connectionString);

            //3 Open conncetion
            con.Open();

            //4 Prepare Query
            Console.WriteLine("Enter Last Name:");
            lastName = Console.ReadLine();

            Console.WriteLine("Enter First Name:");
            firstName = Console.ReadLine();

            string query = "insert into Employees(LastName, FirstName) values('"+lastName+"', '"+firstName+"');";

            //5 Execute Query
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();

            //6 Confirm

            con.Close();
            Console.WriteLine("Done!");
            Console.ReadKey();

        }
    }
}
