using System;
using System.Linq;
using System.Text;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using System.ComponentModel;
using System.Collections.Generic;
using System.Threading;



namespace WinFormCharpWebCam
{
    //Design by Pongsakorn Poosankam
    public partial class mainWinForm : Form
    {
        private IList<PictureBox> _pictureBoxes = new List<PictureBox>();
        private WebCam webcam;

        public mainWinForm()
        {
            InitializeComponent();
            _pictureBoxes.Add(imgCapture);
            _pictureBoxes.Add(pictureBox1);
            _pictureBoxes.Add(pictureBox2);
            _pictureBoxes.Add(pictureBox3);
            _pbIterator = _pictureBoxes.GetEnumerator();
            string h = textBox1.Text;
            timer1.Interval = Convert.ToInt16(h);
            timer1.Start();
        }
        private void mainWinForm_Load(object sender, EventArgs e)
        {
            webcam = new WebCam();
            webcam.InitializeWebCam(ref imgVideo);
        }

        private void bntStart_Click(object sender, EventArgs e)
        {
            webcam.Start();
        }

        private void bntStop_Click(object sender, EventArgs e)
        {
            webcam.Stop();
        }

        private void bntContinue_Click(object sender, EventArgs e)
        {
            webcam.Continue();
        }

        private void bntCapture_Click(object sender, EventArgs e)
        {
            _pbIterator.Reset();
            started = true;
        }

        private void bntSave_Click(object sender, EventArgs e)
        {
            Helper.SaveImageCapture(imgCapture.Image);
        }

        private void bntVideoFormat_Click(object sender, EventArgs e)
        {
            webcam.ResolutionSetting();
        }

        private void bntVideoSource_Click(object sender, EventArgs e)
        {
            webcam.AdvanceSetting();
        }

        bool started = false;
        private IEnumerator<PictureBox> _pbIterator;
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (started)
            {
                if (_pbIterator.MoveNext())
                {
                    _pbIterator.Current.Image = imgVideo.Image;
                    Helper.SaveImageCapture(_pbIterator.Current.Image);
                }
                else
                {
                    started = false;
                }
            }
         }
    }
}
