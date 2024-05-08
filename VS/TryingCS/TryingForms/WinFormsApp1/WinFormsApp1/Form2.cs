using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //1 Address of SQL server and Database
            string connectionString = "Data Source=DESKTOP-MI40F6K;Initial Catalog=NorthWind;Integrated Security=True;";

            //2 Establish Connection
            SqlConnection con = new SqlConnection(connectionString);

            //3 Open conncetion
            con.Open();

            //4 Prepare Query
            string TableName = textBox1.Text;
            string ColumnName = textBox2.Text;
            string Consraint = textBox3.Text;

            string query = "delete from "+TableName+" where "+ColumnName+" = '"+Consraint+"'";

            //5 Execute Query
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();

            //6 Close
            con.Close();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
