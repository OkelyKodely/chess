using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace Solitaire
{
    public class Card
    {
        public static int DIAMOND = 1;
        public static int HEART = 2;
        public static int CLUB = 3;
        public static int SPADE = 4;

        public int suit;
        public int rank;

        public string card;

        public Rectangle place;
        public string whatplace;

        public bool back;
    }
}