namespace WinFormCharpWebCam
{
    //Design by Pongsakorn Poosankam
    partial class mainWinForm
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
            this.components = new System.ComponentModel.Container();
            this.imgVideo = new System.Windows.Forms.PictureBox();
            this.imgCapture = new System.Windows.Forms.PictureBox();
            this.bntStart = new System.Windows.Forms.Button();
            this.bntStop = new System.Windows.Forms.Button();
            this.bntContinue = new System.Windows.Forms.Button();
            this.bntCapture = new System.Windows.Forms.Button();
            this.bntVideoFormat = new System.Windows.Forms.Button();
            this.bntVideoSource = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.imgVideo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imgCapture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            this.SuspendLayout();
            // 
            // imgVideo
            // 
            this.imgVideo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.imgVideo.Location = new System.Drawing.Point(55, 41);
            this.imgVideo.Name = "imgVideo";
            this.imgVideo.Size = new System.Drawing.Size(163, 160);
            this.imgVideo.TabIndex = 0;
            this.imgVideo.TabStop = false;
            // 
            // imgCapture
            // 
            this.imgCapture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.imgCapture.Location = new System.Drawing.Point(224, 41);
            this.imgCapture.Name = "imgCapture";
            this.imgCapture.Size = new System.Drawing.Size(163, 160);
            this.imgCapture.TabIndex = 1;
            this.imgCapture.TabStop = false;
            // 
            // bntStart
            // 
            this.bntStart.Location = new System.Drawing.Point(55, 216);
            this.bntStart.Name = "bntStart";
            this.bntStart.Size = new System.Drawing.Size(41, 23);
            this.bntStart.TabIndex = 2;
            this.bntStart.Text = "Start";
            this.bntStart.UseVisualStyleBackColor = true;
            this.bntStart.Click += new System.EventHandler(this.bntStart_Click);
            // 
            // bntStop
            // 
            this.bntStop.Location = new System.Drawing.Point(102, 216);
            this.bntStop.Name = "bntStop";
            this.bntStop.Size = new System.Drawing.Size(49, 23);
            this.bntStop.TabIndex = 3;
            this.bntStop.Text = "Stop";
            this.bntStop.UseVisualStyleBackColor = true;
            this.bntStop.Click += new System.EventHandler(this.bntStop_Click);
            // 
            // bntContinue
            // 
            this.bntContinue.Location = new System.Drawing.Point(157, 216);
            this.bntContinue.Name = "bntContinue";
            this.bntContinue.Size = new System.Drawing.Size(61, 23);
            this.bntContinue.TabIndex = 4;
            this.bntContinue.Text = "Continue";
            this.bntContinue.UseVisualStyleBackColor = true;
            this.bntContinue.Click += new System.EventHandler(this.bntContinue_Click);
            // 
            // bntCapture
            // 
            this.bntCapture.Location = new System.Drawing.Point(224, 216);
            this.bntCapture.Name = "bntCapture";
            this.bntCapture.Size = new System.Drawing.Size(163, 23);
            this.bntCapture.TabIndex = 5;
            this.bntCapture.Text = "Сделать 4 фотографии";
            this.bntCapture.UseVisualStyleBackColor = true;
            this.bntCapture.Click += new System.EventHandler(this.bntCapture_Click);
            // 
            // bntVideoFormat
            // 
            this.bntVideoFormat.Location = new System.Drawing.Point(393, 216);
            this.bntVideoFormat.Name = "bntVideoFormat";
            this.bntVideoFormat.Size = new System.Drawing.Size(163, 23);
            this.bntVideoFormat.TabIndex = 7;
            this.bntVideoFormat.Text = "Video Format";
            this.bntVideoFormat.UseVisualStyleBackColor = true;
            this.bntVideoFormat.Click += new System.EventHandler(this.bntVideoFormat_Click);
            // 
            // bntVideoSource
            // 
            this.bntVideoSource.Location = new System.Drawing.Point(562, 216);
            this.bntVideoSource.Name = "bntVideoSource";
            this.bntVideoSource.Size = new System.Drawing.Size(163, 23);
            this.bntVideoSource.TabIndex = 8;
            this.bntVideoSource.Text = "Video Source";
            this.bntVideoSource.UseVisualStyleBackColor = true;
            this.bntVideoSource.Click += new System.EventHandler(this.bntVideoSource_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox1.Location = new System.Drawing.Point(393, 41);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(163, 160);
            this.pictureBox1.TabIndex = 9;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox2.Location = new System.Drawing.Point(562, 41);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(163, 160);
            this.pictureBox2.TabIndex = 10;
            this.pictureBox2.TabStop = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox3.Location = new System.Drawing.Point(731, 41);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(163, 160);
            this.pictureBox3.TabIndex = 11;
            this.pictureBox3.TabStop = false;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(732, 216);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(162, 20);
            this.textBox1.TabIndex = 12;
            this.textBox1.Text = "1000";
            // 
            // mainWinForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(947, 254);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.bntVideoSource);
            this.Controls.Add(this.bntVideoFormat);
            this.Controls.Add(this.bntCapture);
            this.Controls.Add(this.bntContinue);
            this.Controls.Add(this.bntStop);
            this.Controls.Add(this.bntStart);
            this.Controls.Add(this.imgCapture);
            this.Controls.Add(this.imgVideo);
            this.Name = "mainWinForm";
            this.Text = "WinForm C# WebCam";
            this.Load += new System.EventHandler(this.mainWinForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.imgVideo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imgCapture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox imgVideo;
        private System.Windows.Forms.PictureBox imgCapture;
        private System.Windows.Forms.Button bntStart;
        private System.Windows.Forms.Button bntStop;
        private System.Windows.Forms.Button bntContinue;
        private System.Windows.Forms.Button bntCapture;
        private System.Windows.Forms.Button bntVideoFormat;
        private System.Windows.Forms.Button bntVideoSource;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TextBox textBox1;
    }
}

