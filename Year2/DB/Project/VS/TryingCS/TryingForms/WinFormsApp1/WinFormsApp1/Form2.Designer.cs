namespace WinFormsApp1
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            label2 = new Label();
            textBox1 = new TextBox();
            textBox3 = new TextBox();
            button1 = new Button();
            label3 = new Label();
            textBox2 = new TextBox();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 26F);
            label1.Location = new Point(128, 141);
            label1.Name = "label1";
            label1.Size = new Size(201, 47);
            label1.TabIndex = 0;
            label1.Text = "Tabel Name";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 26F);
            label2.Location = new Point(128, 263);
            label2.Name = "label2";
            label2.Size = new Size(180, 47);
            label2.TabIndex = 1;
            label2.Text = "Constraint";
            label2.Click += label2_Click;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(335, 164);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(152, 23);
            textBox1.TabIndex = 2;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(314, 286);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(152, 23);
            textBox3.TabIndex = 3;
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 24F);
            button1.Location = new Point(335, 349);
            button1.Name = "button1";
            button1.Size = new Size(149, 60);
            button1.TabIndex = 4;
            button1.Text = "Delete!";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 26F);
            label3.Location = new Point(128, 204);
            label3.Name = "label3";
            label3.Size = new Size(243, 47);
            label3.TabIndex = 5;
            label3.Text = "Column Name";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(377, 227);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(152, 23);
            textBox2.TabIndex = 6;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(textBox2);
            Controls.Add(label3);
            Controls.Add(button1);
            Controls.Add(textBox3);
            Controls.Add(textBox1);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form2";
            Text = "Form2";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private TextBox textBox1;
        private TextBox textBox3;
        private Button button1;
        private Label label3;
        private TextBox textBox2;
    }
}