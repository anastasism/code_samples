using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Traffic_light
{
    public partial class Form1 : Form
    {
        private SmartTrafficLight TrafficLight;
        private Bitmap bm;
        public Form1()
        {
            InitializeComponent();
            bm = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            TrafficLight = new SmartTrafficLight(pictureBox1, Graphics.FromImage(bm));
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImageUnscaled(bm, 0, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            TrafficLight.TurnRed();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TrafficLight.TurnYellow();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            TrafficLight.TurnGreen();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if(TrafficLight.Green.IsOn)
            {
                TrafficLight.Green.Off();
            }
            if(TrafficLight.Red.IsOn)
            {
                TrafficLight.Red.Off();
            }
            TrafficLight.Yellow.Waiting();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            TrafficLight.Green.Off();
            TrafficLight.Red.Off();
            TrafficLight.Yellow.Off();
        }
    }
}
