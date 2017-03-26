using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Traffic_light
{
    class TrafficLight
    {
        public readonly Lamp Red;
        public readonly Lamp Yellow;
        public readonly Lamp Green;
        private readonly Graphics Graphics;

        public TrafficLight(PictureBox pb, Graphics graphics)
        {
            Graphics = graphics;
            graphics.DrawRectangle(new Pen(Color.Black,3), new Rectangle(70, 40, 60, 200));
            Red = new Lamp(Color.Red, graphics, 100, 70, pb);
            Yellow = new Lamp(Color.Yellow, graphics, 100, 140, pb);
            Green = new Lamp(Color.Green, graphics, 100, 210, pb);
            Red.Off();
            Yellow.Off();
            Green.Off();
        }
    }
    class SmartTrafficLight : TrafficLight
    {

        private Controller Controller;
        public SmartTrafficLight(PictureBox pb, Graphics g) : base(pb, g) 
        {
            Controller = new Controller(Red, Yellow, Green);
        }
        public void TurnRed()
        {
            Controller.TurnRed();
        }
        public void TurnGreen()
        {
            Controller.TurnGreen();
        }
        public void TurnYellow()
        {
            Controller.TurnYellow();
        }
        public void Broke()
        {
            Red.Off();
            Green.Off();
            Yellow.Blink();
        }
    }
}
