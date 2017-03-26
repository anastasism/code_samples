using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
namespace WinFormCharpWebCam
{
    //Design by Pongsakorn Poosankam
    class Helper
    {
        private static Random rnd = new Random();
        public static void SaveImageCapture(System.Drawing.Image image)
        {
            var FileName = "Image";// Default file name
            var DefaultExt = ".Jpg";// Default file extension
            // Save Image
            string filename = FileName;
            FileStream fstream = new FileStream(string.Format("{0}{1}.{2}", filename, rnd.Next(0, 100000), DefaultExt), FileMode.Create);
            image.Save(fstream, System.Drawing.Imaging.ImageFormat.Jpeg);
            fstream.Close();
        }
    }
}
