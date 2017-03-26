using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Traffic_light
{
    class Lamp
    {
        private readonly Color Color;
        private readonly Graphics Graphics;
        private readonly Rectangle Rect;
        private readonly PictureBox Pb;
        public bool IsOn{get; private set;}
        public Lamp(Color color, Graphics graphics, int x, int y, PictureBox pb)
        {
            Pb = pb;
            Graphics = graphics;
            Color = color;
            Rect = new Rectangle(x - 25, y - 25, 50, 50);
        }
        public void On()
        {
            IsOn = true;
            Graphics.FillEllipse(new SolidBrush(Color), Rect);
            Pb.Invalidate();
            Pb.Update();
        }
        public void Off()
        {
            IsOn = false;
            Graphics.FillEllipse(new SolidBrush(Color.Black), Rect);
            Pb.Invalidate();
            Pb.Update();
        }
        public void Blink()
        {
            for (int i = 0; i < 3; i++)
            {
                On();
                Thread.Sleep(300);
                Off();
                Thread.Sleep(300);
            }
        }
        public void Waiting()
        {
            for (int i = 0; i < 50; i++ )
            {
                On();
                Thread.Sleep(400);
                Off();
                Thread.Sleep(400);
            }
        }
    }
}
