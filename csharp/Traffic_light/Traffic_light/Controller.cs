using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Traffic_light
{
    class Controller
    {
        private Lamp Red;
        private Lamp Yellow;
        private Lamp Green;
        public Controller(Lamp red, Lamp yellow, Lamp green)
        {
            Red = red;
            Yellow = yellow;    
            Green = green;
        }
        public void TurnRed()
        {
            if (Green.IsOn)
            {
                Green.Blink();
                Yellow.On();
                Thread.Sleep(300);
                Red.On();
                Thread.Sleep(300);
                Yellow.Off();
            }
            else if (Yellow.IsOn)
            {
                Red.On();
                Thread.Sleep(300);
                Yellow.Off();
            }
            else
            {
                Red.On();
            }
        }
        public void TurnYellow()
        {
            if (Green.IsOn)
            {
                Green.Blink();
                Yellow.On();
            }
            else if (Red.IsOn)
            {
                Red.Blink();
                Yellow.On();
            }
            else
            {
                Yellow.On();
            }
        }
        public void TurnGreen()
        {
            if (Yellow.IsOn)
            {
                Yellow.Off();
                Green.On();
            }
            else if(Red.IsOn)
            {
                Red.Blink();
                Yellow.On();
                Thread.Sleep(300);
                Green.On();
                Thread.Sleep(300);
                Yellow.Off();
            }
            else
            {
                Green.On();
            }
        }
    }
}
