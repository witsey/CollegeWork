namespace WinFormsApp1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tb1 = new TextBox();
            label1 = new Label();
            button1 = new Button();
            label2 = new Label();
            tb2 = new TextBox();
            label3 = new Label();
            backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            button2 = new Button();
            SuspendLayout();
            // 
            // tb1
            // 
            tb1.AccessibleName = "";
            tb1.Cursor = Cursors.IBeam;
            tb1.ForeColor = SystemColors.InactiveCaptionText;
            tb1.Location = new Point(401, 167);
            tb1.Name = "tb1";
            tb1.Size = new Size(175, 23);
            tb1.TabIndex = 0;
            tb1.TextAlign = HorizontalAlignment.Center;
            tb1.TextChanged += textBox1_TextChanged;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 26F);
            label1.Location = new Point(209, 144);
            label1.Name = "label1";
            label1.Size = new Size(186, 47);
            label1.TabIndex = 1;
            label1.Text = "First Name";
            label1.Click += label1_Click;
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 26F);
            button1.Location = new Point(439, 385);
            button1.Name = "button1";
            button1.Size = new Size(161, 53);
            button1.TabIndex = 2;
            button1.Text = "Save";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 26F);
            label2.Location = new Point(212, 215);
            label2.Name = "label2";
            label2.Size = new Size(183, 47);
            label2.TabIndex = 3;
            label2.Text = "Last Name";
            label2.Click += label2_Click;
            // 
            // tb2
            // 
            tb2.Location = new Point(401, 238);
            tb2.Name = "tb2";
            tb2.Size = new Size(175, 23);
            tb2.TabIndex = 4;
            tb2.TextAlign = HorizontalAlignment.Center;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Segoe UI", 26F);
            label3.Location = new Point(401, 33);
            label3.Name = "label3";
            label3.Size = new Size(169, 47);
            label3.TabIndex = 5;
            label3.Text = "HELLO! : )";
            label3.Click += label3_Click;
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 26F);
            button2.Location = new Point(838, 385);
            button2.Name = "button2";
            button2.Size = new Size(161, 53);
            button2.TabIndex = 6;
            button2.Text = "Delete?";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.BurlyWood;
            ClientSize = new Size(1022, 450);
            Controls.Add(button2);
            Controls.Add(label3);
            Controls.Add(tb2);
            Controls.Add(label2);
            Controls.Add(button1);
            Controls.Add(label1);
            Controls.Add(tb1);
            Name = "Form1";
            Text = "MyForm";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox tb1;
        private Label label1;
        private Button button1;
        private Label label2;
        private TextBox tb2;
        private Label label3;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private Button button2;
    }
}
