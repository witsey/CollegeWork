using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace WinFormsApp1
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

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {   //1 Address of SQL server and Database
            string connectionString = "Data Source=DESKTOP-MI40F6K;Initial Catalog=NorthWind;Integrated Security=True;";

            //2 Establish Connection
            SqlConnection con = new SqlConnection(connectionString);

            //3 Open conncetion
            con.Open();

            //4 Prepare Query
            string firstName = tb1.Text;
            string lastName = tb2.Text;

            string query = "insert into Employees(LastName, FirstName) values('" + firstName + "', '" + lastName + "');";

            //5 Execute Query
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();

            //6 Close
            con.Close();

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();

            Form2 form2 = new Form2();
            form2.Show();
        }
    }
}
