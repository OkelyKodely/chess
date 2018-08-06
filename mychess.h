#define ID_CLICK_ME_NEW_GAME 9001
#define ID_CLICK_ME_QUIT 9002

#define ID_PC_GAME 9000
#define ID_HUMAN_GAME 8999

#define ID_EASY 4443
#define ID_MEDIUM 4444
#define ID_HARD 4445
#define ID_IMPOSSIBLE 4446

#define ID_TIMER_0MIN 8001
#define ID_TIMER_5MIN 9003
#define ID_TIMER_10MIN 9004
#define ID_TIMER_15MIN 9005
#define ID_TIMER_20MIN 9006
#define ID_TIMER_25MIN 9007
#define ID_TIMER_30MIN 9008
#define ID_TIMER_35MIN 9009
#define ID_TIMER_40MIN 9010
#define ID_TIMER_45MIN 9011
#define ID_TIMER_50MIN 9012
#define ID_TIMER_55MIN 9013
#define ID_TIMER_60MIN 9014
#define ID_TIMER_65MIN 9015
#define ID_TIMER_70MIN 9016
#define ID_TIMER_75MIN 9017
#define ID_TIMER_80MIN 9018
#define ID_TIMER_85MIN 9019
#define ID_TIMER_90MIN 9020

#define ID_ABOUT 9021

#define ID_2PLY_SU 9023
#define ID_2PLY_SI 9024
#define ID_2PLY_SO 9025
#define ID_2PLY 9022

char bestMove[4] = "b1c3";
    
boolean firstTime = TRUE;
char clickedOne = 'g';
char turn;
const char g_szClassName[] = "mychess";

WNDCLASSEX wc;
WNDCLASSEX wcfwabout;
WNDCLASSEX wc2players;
HWND hwnd, hwnd2players;
MSG Msg;
HDC hdc;

HWND hEditUsername, hEditPassword;
HWND saveButton;
HWND hWndComboBox;

struct WhitePawn {
    int x1, y1, x2, y2;
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean firstTimeMove;

} whitePawns[8];

struct BlackPawn {
    int x1, y1, x2, y2;
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean firstTimeMove;

} blackPawns[8];

struct Box {
    int posX, posY;
    boolean clear;
    boolean clicked;

} boxes[8][8];

struct BlackRook2 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} blackRook2;

struct BlackRook1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} blackRook1;

struct WhiteRook2 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} whiteRook2;

struct WhiteRook1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} whiteRook1;

struct WhiteKnight1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} whiteKnight1;

struct WhiteKnight2 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} whiteKnight2;

struct BlackKnight2 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} blackKnight2;

struct BlackKnight1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} blackKnight1;

struct WhiteKing {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;

} whiteKing;

struct BlackKing {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;

} blackKing;

struct WhiteQueen {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} whiteQueen;

struct WhiteQueenK {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} whiteQueenK[8];

struct BlackQueen {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} blackQueen;

struct BlackQueenK {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} blackQueenK[8];

struct BlackBishop1 {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} blackBishop1;

struct BlackBishop2 {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} blackBishop2;

struct WhiteBishop1 {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} whiteBishop1;

struct WhiteBishop2 {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} whiteBishop2;

HBITMAP hBitmap;
HINSTANCE hInst;

PAINTSTRUCT     ps;
BITMAP          bitmap;
HDC             hdcMem;
HGDIOBJ         oldBitmap;
HBITMAP         hhbb;

int reMap(char b[], int typ) {

    if(typ == 0) {

        if(b[0] == 'a') {
            return 0;
        }

        if(b[0] == 'b') {
            return 70;
        }

        if(b[0] == 'c') {
            return 140;
        }

        if(b[0] == 'd') {
            return 210;
        }

        if(b[0] == 'e') {
            return 280;
        }

        if(b[0] == 'f') {
            return 350;
        }

        if(b[0] == 'g') {
            return 420;
        }

        if(b[0] == 'h') {
            return 490;
        }
    }

    else if(typ == 1) {

        if(b[1] == '1') {
            return 490;
        }

        if(b[1] == '2') {
            return 420;
        }

        if(b[1] == '3') {
            return 350;
        }

        if(b[1] == '4') {
            return 280;
        }

        if(b[1] == '5') {
            return 210;
        }

        if(b[1] == '6') {
            return 140;
        }

        if(b[1] == '7') {
            return 70;
        }

        if(b[1] == '8') {
            return 0;
        }
    }
    
    return -1;
}

int re_Map(char b[], int typ) {

    if(typ == 0) {

        if(b[2] == 'a') {
            return 0;
        }

        if(b[2] == 'b') {
            return 70;
        }

        if(b[2] == 'c') {
            return 140;
        }

        if(b[2] == 'd') {
            return 210;
        }

        if(b[2] == 'e') {
            return 280;
        }

        if(b[2] == 'f') {
            return 350;
        }

        if(b[2] == 'g') {
            return 420;
        }

        if(b[2] == 'h') {
            return 490;
        }
    }

    else if(typ == 1) {

        if(b[3] == '1') {
            return 490;
        }

        if(b[3] == '2') {
            return 420;
        }

        if(b[3] == '3') {
            return 350;
        }

        if(b[3] == '4') {
            return 280;
        }

        if(b[3] == '5') {
            return 210;
        }

        if(b[3] == '6') {
            return 140;
        }

        if(b[3] == '7') {
            return 70;
        }

        if(b[3] == '8') {
            return 0;
        }
    }

    return -1;
}

char *map(int j, int i) {

    char *be = (char*) malloc(2);

    for(int y = 0; y < 8; y++) {
        if(i == 0) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "a%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 1) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "b%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 2) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "c%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 3) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "d%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 4) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "e%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 5) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "f%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 6) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "g%d", bee);
                return be;
            }
        }
    }

    for(int y = 0; y < 8; y++) {
        if(i == 7) {
            if(j == y) {
                int bee = 8 - y;
                sprintf(be, "h%d", bee);
                return be;
            }
        }
    }
    
    return be;
}

void DrawChessBoard() {

    hhbb = (HBITMAP)LoadImage(hInst, "chessboard.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    hdcMem = CreateCompatibleDC(hdc);
    oldBitmap = SelectObject(hdcMem, hhbb);

    GetObject(hhbb, sizeof(bitmap), &bitmap);
    BitBlt(hdc, 15, 12, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

    SelectObject(hdcMem, oldBitmap);
    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hhbb); DeleteObject(oldBitmap);
    DeleteObject(hhbb);
}

boolean moveWhiteQueen(UINT msg, int j, int i, int pos, int o) {

    if(blackKnight1.posX == whiteQueen.posX &&
       blackKnight1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteQueen.posX &&
       blackKnight2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteQueen.posX &&
       blackBishop1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteQueen.posX &&
       blackBishop2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteQueen.posX &&
       blackRook1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteQueen.posX &&
       blackRook2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteQueen.posX &&
       blackQueen.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteQueen.posX &&
           blackPawns[g].posY == whiteQueen.posY) {
            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteQueen(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteQueen.posY = whiteQueen.posY - 70;
                    
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY &&
                       whitePawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY &&
                       whiteBishop1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY &&
                       whiteBishop2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY &&
                       whiteKnight1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY &&
                       whiteKnight2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY &&
                       whiteRook1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY &&
                       whiteRook2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueen.posY &&
                       whiteKing.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(blackPawns[s].posY == whiteQueen.posY &&
                           blackPawns[s].posX == whiteQueen.posX) {
                            blackPawns[s].posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueen.posY &&
                           blackQueen.posX == whiteQueen.posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueen.posY &&
                           blackRook1.posX == whiteQueen.posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueen.posY &&
                           blackRook2.posX == whiteQueen.posX) {
                            blackRook2.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueen.posY &&
                           blackKnight1.posX == whiteQueen.posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueen.posY &&
                           blackKnight2.posX == whiteQueen.posX) {
                            blackKnight2.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueen.posY &&
                           blackBishop1.posX == whiteQueen.posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueen.posY &&
                           blackBishop2.posX == whiteQueen.posX) {
                            blackBishop2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY - 70 &&
                       whitePawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueen.posY - 70 &&
                       blackPawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackQueen.posY == whiteQueen.posY - 70 &&
                   blackQueen.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY - 70 &&
                   blackBishop1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY - 70 &&
                   blackBishop2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueen.posY - 70 &&
                   whiteRook1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueen.posY - 70 &&
                   whiteRook2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueen.posY - 70 &&
                   whiteKnight1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueen.posY - 70 &&
                   whiteKnight2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY - 70 &&
                   blackBishop1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY - 70 &&
                   blackBishop2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueen.posY - 70 &&
                   blackRook1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueen.posY - 70 &&
                   blackRook2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueen.posY - 70 &&
                   blackKnight1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueen.posY - 70 &&
                   blackKnight2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                
                if(!flag) {
                    whiteQueen.posY = whiteQueen.posY - 70;
                }

                return flag;
            }
        }

        else {

            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteQueen(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteQueen.posY = whiteQueen.posY + 70;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY &&
                       whitePawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY &&
                       whiteBishop1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY &&
                       whiteBishop2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY &&
                       whiteKnight1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY &&
                       whiteKnight2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY &&
                       whiteRook1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY &&
                       whiteRook2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueen.posY &&
                       whiteKing.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(blackPawns[s].posY == whiteQueen.posY &&
                           blackPawns[s].posX == whiteQueen.posX) {
                            blackPawns[s].posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueen.posY &&
                           blackQueen.posX == whiteQueen.posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueen.posY &&
                           blackRook1.posX == whiteQueen.posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueen.posY &&
                           blackRook2.posX == whiteQueen.posX) {
                            blackRook2.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueen.posY &&
                           blackKnight1.posX == whiteQueen.posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueen.posY &&
                           blackKnight2.posX == whiteQueen.posX) {
                            blackKnight2.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueen.posY &&
                           blackBishop1.posX == whiteQueen.posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueen.posY &&
                           blackBishop2.posX == whiteQueen.posX) {
                            blackBishop2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY + 70 &&
                       whitePawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueen.posY + 70 &&
                       blackPawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackQueen.posY == whiteQueen.posY + 70 &&
                   blackQueen.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY + 70 &&
                   blackBishop1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY + 70 &&
                   blackBishop2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueen.posY + 70 &&
                   whiteRook1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueen.posY + 70 &&
                   whiteRook2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueen.posY + 70 &&
                   whiteKnight1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueen.posY + 70 &&
                   whiteKnight2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY + 70 &&
                   blackBishop1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY + 70 &&
                   blackBishop2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueen.posY + 70 &&
                   blackRook1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueen.posY + 70 &&
                   blackRook2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueen.posY + 70 &&
                   blackKnight1.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueen.posY + 70 &&
                   blackKnight2.posX == whiteQueen.posX) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueen.posY = whiteQueen.posY + 70;
                }

                return flag;
            }
        }

        else {

            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveWhiteQueenSide(UINT msg, int j, int i, int pos, int o) {

    if(blackKnight1.posX == whiteQueen.posX &&
       blackKnight1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteQueen.posX &&
       blackKnight2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteQueen.posX &&
       blackBishop1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteQueen.posX &&
       blackBishop2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteQueen.posX &&
       blackRook1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteQueen.posX &&
       blackRook2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteQueen.posX &&
       blackQueen.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteQueen.posX &&
           blackPawns[g].posY == whiteQueen.posY) {
            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteQueenSide(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteQueen.posX = whiteQueen.posX - 70;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY &&
                       whitePawns[s].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY &&
                       whiteBishop1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY &&
                       whiteBishop2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY &&
                       whiteKnight1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY &&
                       whiteKnight2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY &&
                       whiteRook1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY &&
                       whiteRook2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueen.posY &&
                       whiteKing.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(blackPawns[s].posY == whiteQueen.posY &&
                           blackPawns[s].posX == whiteQueen.posX) {
                            blackPawns[s].posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueen.posY &&
                           blackQueen.posX == whiteQueen.posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueen.posY &&
                           blackRook1.posX == whiteQueen.posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueen.posY &&
                           blackRook2.posX == whiteQueen.posX) {
                            blackRook2.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueen.posY &&
                           blackKnight1.posX == whiteQueen.posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueen.posY &&
                           blackKnight2.posX == whiteQueen.posX) {
                            blackKnight2.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueen.posY &&
                           blackBishop1.posX == whiteQueen.posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueen.posY &&
                           blackBishop2.posX == whiteQueen.posX) {
                            blackBishop2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY &&
                       whitePawns[s].posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueen.posY &&
                       blackPawns[s].posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackQueen.posY == whiteQueen.posY &&
                   blackQueen.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY &&
                   blackBishop1.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY &&
                   blackBishop2.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueen.posY &&
                   whiteRook1.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueen.posY &&
                   whiteRook2.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueen.posY &&
                   whiteKnight1.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueen.posY &&
                   whiteKnight2.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY &&
                   blackBishop1.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY &&
                   blackBishop2.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueen.posY &&
                   blackRook1.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueen.posY &&
                   blackRook2.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueen.posY &&
                   blackKnight1.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueen.posY &&
                   blackKnight2.posX == whiteQueen.posX - 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueen.posX = whiteQueen.posX - 70;
                }

                return flag;
            }
        }

        else {

            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteQueenSide(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteQueen.posX = whiteQueen.posX + 70;

                for(int s=0; s<8; s++) {
                    if(whitePawns[i].posY == whiteQueen.posY &&
                       whitePawns[i].posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY &&
                       whiteBishop1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY &&
                       whiteBishop2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY &&
                       whiteKnight1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY &&
                       whiteKnight2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY &&
                       whiteRook1.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY &&
                       whiteRook2.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueen.posY &&
                       whiteKing.posX == whiteQueen.posX) {
                        whiteQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(blackPawns[s].posY == whiteQueen.posY &&
                           blackPawns[s].posX == whiteQueen.posX) {
                            blackPawns[s].posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueen.posY &&
                           blackQueen.posX == whiteQueen.posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueen.posY &&
                           blackKnight1.posX == whiteQueen.posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueen.posY &&
                           blackKnight2.posX == whiteQueen.posX) {
                            blackKnight2.posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueen.posY &&
                           blackQueen.posX == whiteQueen.posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueen.posY &&
                           blackBishop1.posX == whiteQueen.posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueen.posY &&
                           blackBishop2.posX == whiteQueen.posX) {
                            blackBishop2.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueen.posY &&
                           blackRook1.posX == whiteQueen.posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueen.posY &&
                           blackRook2.posX == whiteQueen.posX) {
                            blackRook2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteQueen.posY &&
                       whitePawns[s].posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueen.posY &&
                       blackPawns[s].posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackQueen.posY == whiteQueen.posY &&
                   blackQueen.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY &&
                   blackBishop1.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY &&
                   blackBishop2.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueen.posY &&
                   whiteRook1.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueen.posY &&
                   whiteRook2.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueen.posY &&
                   whiteKnight1.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueen.posY &&
                   whiteKnight2.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueen.posY &&
                   blackBishop1.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueen.posY &&
                   blackBishop2.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueen.posY &&
                   blackRook1.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueen.posY &&
                   blackRook2.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueen.posY &&
                   blackKnight1.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueen.posY &&
                   blackKnight2.posX == whiteQueen.posX + 70) {
                    whiteQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueen.posX = whiteQueen.posX + 70;
                }

                return flag;
            }
        }

        else {

            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveBlackQueen(UINT msg, int j, int i, int pos, int o) {

    if(pos == 0) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackQueen.posX &&
       whiteKnight1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackQueen.posX &&
       whiteKnight2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackQueen.posX &&
       whiteBishop1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackQueen.posX &&
       whiteBishop2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackQueen.posX &&
       whiteRook1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackQueen.posX &&
       whiteRook2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueen.posX &&
       whiteQueen.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackQueen.posX &&
           whitePawns[g].posY == blackQueen.posY) {
            blackQueen.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackQueen(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackQueen.posY = blackQueen.posY - 70;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY &&
                       blackPawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(whitePawns[s].posY == blackQueen.posY &&
                           whitePawns[s].posX == blackQueen.posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueen.posY &&
                           whiteQueen.posX == blackQueen.posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueen.posY &&
                           whiteRook1.posX == blackQueen.posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueen.posY &&
                           whiteRook2.posX == blackQueen.posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueen.posY &&
                           whiteBishop1.posX == blackQueen.posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueen.posY &&
                           whiteBishop2.posX == blackQueen.posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueen.posY &&
                           whiteKnight1.posX == blackQueen.posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueen.posY &&
                           whiteKnight2.posX == blackQueen.posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY - 70 &&
                       blackPawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;                        
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackQueen.posY - 70 &&
                       whitePawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;                        
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueen.posY - 70 &&
                   blackBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY - 70 &&
                   blackBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueen.posY - 70 &&
                   blackRook1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueen.posY - 70 &&
                   blackRook2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueen.posY - 70 &&
                   blackKnight1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueen.posY - 70 &&
                   blackKnight2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueen.posY - 70 &&
                   blackBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY - 70 &&
                   blackBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY - 70 &&
                   whiteQueen.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY - 70 &&
                   whiteBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY - 70 &&
                   whiteBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueen.posY - 70 &&
                   whiteRook1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueen.posY - 70 &&
                   whiteRook2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueen.posY - 70 &&
                   whiteKnight1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueen.posY - 70 &&
                   whiteKnight2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueen.posY = blackQueen.posY - 70;
                }

                return flag;
            }
        }

        else {

            blackQueen.failedpath = TRUE;                        
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackQueen(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackQueen.posY = blackQueen.posY + 70;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY &&
                       blackPawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(whitePawns[s].posY == blackQueen.posY &&
                           whitePawns[s].posX == blackQueen.posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueen.posY &&
                           whiteQueen.posX == blackQueen.posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueen.posY &&
                           whiteRook1.posX == blackQueen.posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueen.posY &&
                           whiteRook2.posX == blackQueen.posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueen.posY &&
                           whiteBishop1.posX == blackQueen.posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueen.posY &&
                           whiteBishop2.posX == blackQueen.posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueen.posY &&
                           whiteKnight1.posX == blackQueen.posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueen.posY &&
                           whiteKnight2.posX == blackQueen.posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY + 70 &&
                       blackPawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackQueen.posY + 70 &&
                       whitePawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueen.posY + 70 &&
                   blackBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY + 70 &&
                   blackBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueen.posY + 70 &&
                   blackRook1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueen.posY + 70 &&
                   blackRook2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueen.posY + 70 &&
                   blackKnight1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueen.posY + 70 &&
                   blackKnight2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueen.posY + 70 &&
                   blackBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY + 70 &&
                   blackBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY + 70 &&
                   whiteQueen.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY + 70 &&
                   whiteBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY + 70 &&
                   whiteBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueen.posY + 70 &&
                   whiteRook1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueen.posY + 70 &&
                   whiteRook2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueen.posY + 70 &&
                   whiteKnight1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueen.posY + 70 &&
                   whiteKnight2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY + 70 &&
                   whiteBishop1.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY + 70 &&
                   whiteBishop2.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY + 70 &&
                   whiteQueen.posX == blackQueen.posX) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueen.posY = blackQueen.posY + 70;
                }

                return flag;
            }
        }

        else {

            blackQueen.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveBlackQueenSide(UINT msg, int j, int i, int pos, int o) {

    if(whiteKnight1.posX == blackQueen.posX &&
       whiteKnight1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackQueen.posX &&
       whiteKnight2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackQueen.posX &&
       whiteBishop1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackQueen.posX &&
       whiteBishop2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackQueen.posX &&
       whiteRook1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackQueen.posX &&
       whiteRook2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueen.posX &&
       whiteQueen.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackQueen.posX &&
           whitePawns[g].posY == blackQueen.posY) {
            blackQueen.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackQueenSide(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackQueen.posX = blackQueen.posX - 70;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY &&
                       blackPawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(whitePawns[s].posY == blackQueen.posY &&
                           whitePawns[s].posX == blackQueen.posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueen.posY &&
                           whiteQueen.posX == blackQueen.posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueen.posY &&
                           whiteRook1.posX == blackQueen.posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueen.posY &&
                           whiteRook2.posX == blackQueen.posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueen.posY &&
                           whiteBishop1.posX == blackQueen.posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueen.posY &&
                           whiteBishop2.posX == blackQueen.posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueen.posY &&
                           whiteKnight1.posX == blackQueen.posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueen.posY &&
                           whiteKnight2.posX == blackQueen.posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY &&
                       blackPawns[s].posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackQueen.posY &&
                       whitePawns[s].posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueen.posY &&
                   blackBishop1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY &&
                   blackBishop2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueen.posY &&
                   blackRook1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueen.posY &&
                   blackRook2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueen.posY &&
                   blackKnight1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueen.posY &&
                   blackKnight2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueen.posY &&
                   blackBishop1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY &&
                   blackBishop2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY &&
                   whiteQueen.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY &&
                   whiteBishop1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY &&
                   whiteBishop2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueen.posY &&
                   whiteRook1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueen.posY &&
                   whiteRook2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueen.posY &&
                   whiteKnight1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueen.posY &&
                   whiteKnight2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY &&
                   whiteBishop1.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY &&
                   whiteBishop2.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY &&
                   whiteQueen.posX == blackQueen.posX - 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueen.posX = blackQueen.posX - 70;
                }

                return flag;
            }
        }

        else {

            blackQueen.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackQueenSide(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackQueen.posX = blackQueen.posX + 70;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackQueen.posY &&
                       blackPawns[s].posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY &&
                       blackBishop1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY &&
                       blackBishop2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY &&
                       blackKnight1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY &&
                       blackKnight2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY &&
                       blackRook1.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY &&
                       blackRook2.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueen.posY &&
                       blackKing.posX == blackQueen.posX) {
                        blackQueen.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(whitePawns[s].posY == blackQueen.posY &&
                           whitePawns[s].posX == blackQueen.posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueen.posY &&
                           whiteQueen.posX == blackQueen.posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueen.posY &&
                           whiteRook1.posX == blackQueen.posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueen.posY &&
                           whiteRook2.posX == blackQueen.posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueen.posY &&
                           whiteBishop1.posX == blackQueen.posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueen.posY &&
                           whiteBishop2.posX == blackQueen.posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueen.posY &&
                           whiteKnight1.posX == blackQueen.posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueen.posY &&
                           whiteKnight2.posX == blackQueen.posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    if(blackPawns[i].posY == blackQueen.posY &&
                       blackPawns[i].posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == blackQueen.posY &&
                       whitePawns[i].posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueen.posY &&
                   blackBishop1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY &&
                   blackBishop2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueen.posY &&
                   blackRook1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueen.posY &&
                   blackRook2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueen.posY &&
                   blackKnight1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueen.posY &&
                   blackKnight2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueen.posY &&
                   blackBishop1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueen.posY &&
                   blackBishop2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY &&
                   whiteQueen.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY &&
                   whiteBishop1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY &&
                   whiteBishop2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueen.posY &&
                   whiteRook1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueen.posY &&
                   whiteRook2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueen.posY &&
                   whiteKnight1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueen.posY &&
                   whiteKnight2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueen.posY &&
                   whiteBishop1.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueen.posY &&
                   whiteBishop2.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueen.posY &&
                   whiteQueen.posX == blackQueen.posX + 70) {
                    blackQueen.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueen.posX = blackQueen.posX + 70;
                }

                return flag;
            }
        }

        else {

            blackQueen.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveBlackQueenSideK(UINT msg, int j, int i, int pos, int o, int k) {

    if(whiteKnight1.posX == blackQueenK[k].posX &&
       whiteKnight1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackQueenK[k].posX &&
       whiteKnight2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackQueenK[k].posX &&
       whiteBishop1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackQueenK[k].posX &&
       whiteBishop2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackQueenK[k].posX &&
       whiteRook1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackQueenK[k].posX &&
       whiteRook2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueenK[k].posX &&
       whiteQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackQueenK[k].posX &&
           whitePawns[g].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackQueenSideK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                blackQueenK[k].posX = blackQueenK[k].posX - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            blackQueenK[p].posY == blackQueenK[k].posY &&
                            blackQueenK[p].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY &&
                        blackQueen.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY &&
                       blackPawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int b=0; b<8; b++) {
                            if(whiteQueenK[b].posY == blackQueenK[k].posY &&
                               whiteQueenK[b].posX == blackQueenK[k].posX) {
                                whiteQueenK[b].posX = 1300;
                            }
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY &&
                           whitePawns[s].posX == blackQueenK[k].posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueenK[k].posY &&
                           whiteQueen.posX == blackQueenK[k].posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueenK[k].posY &&
                           whiteRook1.posX == blackQueenK[k].posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueenK[k].posY &&
                           whiteRook2.posX == blackQueenK[k].posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueenK[k].posY &&
                           whiteBishop1.posX == blackQueenK[k].posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueenK[k].posY &&
                           whiteBishop2.posX == blackQueenK[k].posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueenK[k].posY &&
                           whiteKnight1.posX == blackQueenK[k].posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueenK[k].posY &&
                           whiteKnight2.posX == blackQueenK[k].posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int d=0; d<8; d++) {
                        if(blackQueenK[d].posY == blackQueenK[k].posY &&
                           blackQueenK[d].posX == blackQueenK[k].posX - 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whiteQueenK[d].posY == blackQueenK[k].posY &&
                           whiteQueenK[d].posX == blackQueenK[k].posX - 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY &&
                       blackPawns[s].posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackQueenK[k].posY &&
                       whitePawns[s].posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueenK[k].posY &&
                   blackBishop1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY &&
                   blackBishop2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueenK[k].posY &&
                   blackRook1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueenK[k].posY &&
                   blackRook2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueenK[k].posY &&
                   blackKnight1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueenK[k].posY &&
                   blackKnight2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueenK[k].posY &&
                   blackBishop1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY &&
                   blackBishop2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueenK[k].posY &&
                   whiteQueen.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY &&
                   whiteBishop1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY &&
                   whiteBishop2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueenK[k].posY &&
                   whiteRook1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueenK[k].posY &&
                   whiteRook2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueenK[k].posY &&
                   whiteKnight1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueenK[k].posY &&
                   whiteKnight2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY &&
                   whiteBishop1.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY &&
                   whiteBishop2.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueenK[k].posY &&
                   whiteQueen.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackQueen.posY == blackQueenK[k].posY &&
                   blackQueen.posX == blackQueenK[k].posX - 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueenK[k].posX = blackQueenK[k].posX - 70;
                }

                return flag;
            }
        }

        else {

            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackQueenSideK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                blackQueenK[k].posX = blackQueenK[k].posX + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            blackQueenK[p].posY == blackQueenK[k].posY &&
                            blackQueenK[p].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY &&
                        blackQueen.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY &&
                       blackPawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(whitePawns[s].posY == blackQueenK[k].posY &&
                           whitePawns[s].posX == blackQueenK[k].posX) {
                            whitePawns[s].posX = 1300;
                        }
                        for(int c=0; c<8; c++) {
                            if(whiteQueenK[c].posY == blackQueenK[k].posY &&
                               whiteQueenK[c].posX == blackQueenK[k].posX) {
                                whiteQueenK[c].posX = 1300;
                            }
                        }
                        if(whiteQueen.posY == blackQueenK[k].posY &&
                           whiteQueen.posX == blackQueenK[k].posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueenK[k].posY &&
                           whiteRook1.posX == blackQueenK[k].posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueenK[k].posY &&
                           whiteRook2.posX == blackQueenK[k].posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueenK[k].posY &&
                           whiteBishop1.posX == blackQueenK[k].posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueenK[k].posY &&
                           whiteBishop2.posX == blackQueenK[k].posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueenK[k].posY &&
                           whiteKnight1.posX == blackQueenK[k].posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueenK[k].posY &&
                           whiteKnight2.posX == blackQueenK[k].posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    for(int f=0; f<8; f++) {
                        if(blackQueenK[f].posY == blackQueenK[k].posY &&
                           blackQueenK[f].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY &&
                       blackQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[i].posY == blackQueenK[k].posY &&
                       blackPawns[i].posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == blackQueenK[k].posY &&
                       whitePawns[i].posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueenK[k].posY &&
                   blackBishop1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY &&
                   blackBishop2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueenK[k].posY &&
                   blackRook1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueenK[k].posY &&
                   blackRook2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueenK[k].posY &&
                   blackKnight1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueenK[k].posY &&
                   blackKnight2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueenK[k].posY &&
                   blackBishop1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY &&
                   blackBishop2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int g=0; g<8; g++) {
                    if(whiteQueenK[g].posY == blackQueenK[k].posY &&
                       whiteQueenK[g].posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(whiteQueen.posY == blackQueenK[k].posY &&
                   whiteQueen.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY &&
                   whiteBishop1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY &&
                   whiteBishop2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueenK[k].posY &&
                   whiteRook1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueenK[k].posY &&
                   whiteRook2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueenK[k].posY &&
                   whiteKnight1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueenK[k].posY &&
                   whiteKnight2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY &&
                   whiteBishop1.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY &&
                   whiteBishop2.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueenK[k].posY &&
                   whiteQueen.posX == blackQueenK[k].posX + 70) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueenK[k].posX = blackQueenK[k].posX + 70;
                }

                return flag;
            }
        }

        else {

            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveWhiteQueenSideK(UINT msg, int j, int i, int pos, int o, int k) {

    if(blackKnight1.posX == whiteQueenK[k].posX &&
       blackKnight1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteQueenK[k].posX &&
       blackKnight2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteQueenK[k].posX &&
       blackBishop1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteQueenK[k].posX &&
       blackBishop2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteQueenK[k].posX &&
       blackRook1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteQueenK[k].posX &&
       blackRook2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteQueenK[k].posX &&
       blackQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteQueenK[k].posX &&
           blackPawns[g].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteQueenSideK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                whiteQueenK[k].posX = whiteQueenK[k].posX - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            whiteQueenK[p].posY == whiteQueenK[k].posY &&
                            whiteQueenK[p].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY &&
                        whiteQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY &&
                       whitePawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY &&
                       whiteBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY &&
                       whiteBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY &&
                       whiteKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY &&
                       whiteKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY &&
                       whiteRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY &&
                       whiteRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueenK[k].posY &&
                       whiteKing.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY &&
                       whiteBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY &&
                       whiteBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY &&
                       whiteKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY &&
                       whiteKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY &&
                       whiteRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY &&
                       whiteRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueenK[k].posY &&
                       whiteKing.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int b=0; b<8; b++) {
                            if(blackQueenK[b].posY == whiteQueenK[k].posY &&
                               blackQueenK[b].posX == whiteQueenK[k].posX) {
                                blackQueenK[b].posX = 1300;
                            }
                        }
                        if(blackPawns[s].posY == whiteQueenK[k].posY &&
                           blackPawns[s].posX == whiteQueenK[k].posX) {
                            blackPawns[s].posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueenK[k].posY &&
                           blackQueen.posX == whiteQueenK[k].posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueenK[k].posY &&
                           blackRook1.posX == whiteQueenK[k].posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueenK[k].posY &&
                           blackRook2.posX == whiteQueenK[k].posX) {
                            blackRook2.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueenK[k].posY &&
                           blackBishop1.posX == whiteQueenK[k].posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueenK[k].posY &&
                           blackBishop2.posX == whiteQueenK[k].posX) {
                            blackBishop2.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueenK[k].posY &&
                           blackKnight1.posX == whiteQueenK[k].posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueenK[k].posY &&
                           blackKnight2.posX == whiteQueenK[k].posX) {
                            blackKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int d=0; d<8; d++) {
                        if(whiteQueenK[d].posY == whiteQueenK[k].posY &&
                           whiteQueenK[d].posX == whiteQueenK[k].posX - 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(blackQueenK[d].posY == whiteQueenK[k].posY &&
                           blackQueenK[d].posX == whiteQueenK[k].posX - 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackPawns[s].posY == whiteQueenK[k].posY &&
                       blackPawns[s].posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY &&
                       whitePawns[s].posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteQueenK[k].posY &&
                   blackBishop1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY &&
                   blackBishop2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueenK[k].posY &&
                   blackRook1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueenK[k].posY &&
                   blackRook2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueenK[k].posY &&
                   blackKnight1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueenK[k].posY &&
                   blackKnight2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueenK[k].posY &&
                   blackBishop1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY &&
                   blackBishop2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == whiteQueenK[k].posY &&
                   whiteQueen.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY &&
                   whiteBishop1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY &&
                   whiteBishop2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueenK[k].posY &&
                   whiteRook1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueenK[k].posY &&
                   whiteRook2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueenK[k].posY &&
                   whiteKnight1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueenK[k].posY &&
                   whiteKnight2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY &&
                   whiteBishop1.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY &&
                   whiteBishop2.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == whiteQueenK[k].posY &&
                   whiteQueen.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackQueen.posY == whiteQueenK[k].posY &&
                   blackQueen.posX == whiteQueenK[k].posX - 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueenK[k].posX = whiteQueenK[k].posX - 70;
                }

                return flag;
            }
        }

        else {

            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteQueenSideK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                whiteQueenK[k].posX = whiteQueenK[k].posX + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            whiteQueenK[p].posY == whiteQueenK[k].posY &&
                            whiteQueenK[p].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY &&
                        whiteQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY &&
                       whitePawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY &&
                       whiteBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY &&
                       whiteBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY &&
                       whiteKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY &&
                       whiteKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY &&
                       whiteRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY &&
                       whiteRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueenK[k].posY &&
                       whiteKing.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY &&
                       whiteBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY &&
                       whiteBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY &&
                       whiteKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY &&
                       whiteKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY &&
                       whiteRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY &&
                       whiteRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueenK[k].posY &&
                       whiteKing.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(blackPawns[s].posY == whiteQueenK[k].posY &&
                           blackPawns[s].posX == whiteQueenK[k].posX) {
                            blackPawns[s].posX = 1300;
                        }
                        for(int c=0; c<8; c++) {
                            if(blackQueenK[c].posY == whiteQueenK[k].posY &&
                               blackQueenK[c].posX == whiteQueenK[k].posX) {
                                blackQueenK[c].posX = 1300;
                            }
                        }
                        if(blackQueen.posY == whiteQueenK[k].posY &&
                           blackQueen.posX == whiteQueenK[k].posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueenK[k].posY &&
                           blackRook1.posX == whiteQueenK[k].posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueenK[k].posY &&
                           blackRook2.posX == whiteQueenK[k].posX) {
                            blackRook2.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueenK[k].posY &&
                           blackBishop1.posX == whiteQueenK[k].posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueenK[k].posY &&
                           blackBishop2.posX == whiteQueenK[k].posX) {
                            blackBishop2.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueenK[k].posY &&
                           blackKnight1.posX == whiteQueenK[k].posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueenK[k].posY &&
                           blackKnight2.posX == whiteQueenK[k].posX) {
                            blackKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    for(int f=0; f<8; f++) {
                        if(blackQueenK[f].posY == whiteQueenK[k].posY &&
                           blackQueenK[f].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY &&
                       blackQueen.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[i].posY == whiteQueenK[k].posY &&
                       blackPawns[i].posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == whiteQueenK[k].posY &&
                       whitePawns[i].posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteQueenK[k].posY &&
                   blackBishop1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY &&
                   blackBishop2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueenK[k].posY &&
                   blackRook1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueenK[k].posY &&
                   blackRook2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueenK[k].posY &&
                   blackKnight1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueenK[k].posY &&
                   blackKnight2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueenK[k].posY &&
                   blackBishop1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY &&
                   blackBishop2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int g=0; g<8; g++) {
                    if(whiteQueenK[g].posY == whiteQueenK[k].posY &&
                       whiteQueenK[g].posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(whiteQueen.posY == whiteQueenK[k].posY &&
                   whiteQueen.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY &&
                   whiteBishop1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY &&
                   whiteBishop2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueenK[k].posY &&
                   whiteRook1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueenK[k].posY &&
                   whiteRook2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueenK[k].posY &&
                   whiteKnight1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueenK[k].posY &&
                   whiteKnight2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY &&
                   whiteBishop1.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY &&
                   whiteBishop2.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == whiteQueenK[k].posY &&
                   whiteQueen.posX == whiteQueenK[k].posX + 70) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueenK[k].posX = whiteQueenK[k].posX + 70;
                }

                return flag;
            }
        }

        else {

            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveBlackQueenK(UINT msg, int j, int i, int pos, int o, int k) {

    for(int q=0; q<8; q++) {
        if(q != k &&
           blackQueenK[q].posX == blackQueenK[k].posX &&
           blackQueenK[q].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
        if(q != k &&
           whiteQueenK[q].posX == blackQueenK[k].posX &&
           whiteQueenK[q].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(blackQueen.posX == blackQueenK[k].posX &&
       blackQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueenK[k].posX &&
       whiteQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackQueenK[k].posX &&
       whiteKnight1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackQueenK[k].posX &&
       whiteKnight2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackQueenK[k].posX &&
       whiteBishop1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackQueenK[k].posX &&
       whiteBishop2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackQueenK[k].posX &&
       whiteRook1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackQueenK[k].posX &&
       whiteRook2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueenK[k].posX &&
       whiteQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackQueenK[k].posX &&
           whitePawns[g].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackQueenK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                blackQueenK[k].posY = blackQueenK[k].posY - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           blackQueenK[p].posY == blackQueenK[k].posY &&
                           blackQueenK[p].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY &&
                       blackQueen.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY &&
                       blackPawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int r=0; r<8; r++) {
                            if(whiteQueenK[r].posY == blackQueenK[k].posY &&
                               whiteQueenK[r].posX == blackQueenK[k].posX) {
                                whiteQueenK[r].posX = 1300;
                            }
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY &&
                           whitePawns[s].posX == blackQueenK[k].posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueenK[k].posY &&
                           whiteQueen.posX == blackQueenK[k].posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueenK[k].posY &&
                           whiteRook1.posX == blackQueenK[k].posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueenK[k].posY &&
                           whiteRook2.posX == blackQueenK[k].posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueenK[k].posY &&
                           whiteBishop1.posX == blackQueenK[k].posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueenK[k].posY &&
                           whiteBishop2.posX == blackQueenK[k].posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueenK[k].posY &&
                           whiteKnight1.posX == blackQueenK[k].posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueenK[k].posY &&
                           whiteKnight2.posX == blackQueenK[k].posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           blackQueenK[p].posY == blackQueenK[k].posY - 70 &&
                           blackQueenK[p].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY - 70 &&
                       blackQueen.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY - 70 &&
                       blackPawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackQueenK[k].posY - 70 &&
                       whitePawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                   blackBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                   blackBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueenK[k].posY - 70 &&
                   blackRook1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueenK[k].posY - 70 &&
                   blackRook2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueenK[k].posY - 70 &&
                   blackKnight1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueenK[k].posY - 70 &&
                   blackKnight2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                   blackBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                   blackBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int w=0; w<8; w++) {
                    if(whiteQueenK[w].posY == blackQueenK[k].posY - 70 &&
                       whiteQueenK[w].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(whiteQueen.posY == blackQueenK[k].posY - 70 &&
                   whiteQueen.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY - 70 &&
                   whiteBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY - 70 &&
                   whiteBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueenK[k].posY - 70 &&
                   whiteRook1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueenK[k].posY - 70 &&
                   whiteRook2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueenK[k].posY - 70 &&
                   whiteKnight1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueenK[k].posY - 70 &&
                   whiteKnight2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueenK[k].posY = blackQueenK[k].posY - 70;
                }

                return flag;
            }
        }

        else {

            blackQueenK[k].failedpath = TRUE;                        
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackQueenK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                blackQueenK[k].posY = blackQueenK[k].posY + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           blackQueenK[p].posY == blackQueenK[k].posY &&
                           blackQueenK[p].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY &&
                       blackQueen.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY &&
                       blackPawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY &&
                       blackBishop1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY &&
                       blackBishop2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY &&
                       blackKnight1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY &&
                       blackKnight2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY &&
                       blackRook1.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY &&
                       blackRook2.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackQueenK[k].posY &&
                       blackKing.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int a=0; a<8; a++) {
                            if(whiteQueenK[a].posY == blackQueenK[k].posY &&
                               whiteQueenK[a].posX == blackQueenK[k].posX) {
                                whiteQueenK[a].posX = 1300;
                            }
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY &&
                           whitePawns[s].posX == blackQueenK[k].posX) {
                            whitePawns[s].posX = 1300;
                        }
                        if(whiteQueen.posY == blackQueenK[k].posY &&
                           whiteQueen.posX == blackQueenK[k].posX) {
                            whiteQueen.posX = 1300;
                        }
                        if(whiteRook1.posY == blackQueenK[k].posY &&
                           whiteRook1.posX == blackQueenK[k].posX) {
                            whiteRook1.posX = 1300;
                        }
                        if(whiteRook2.posY == blackQueenK[k].posY &&
                           whiteRook2.posX == blackQueenK[k].posX) {
                            whiteRook2.posX = 1300;
                        }
                        if(whiteBishop1.posY == blackQueenK[k].posY &&
                           whiteBishop1.posX == blackQueenK[k].posX) {
                            whiteBishop1.posX = 1300;
                        }
                        if(whiteBishop2.posY == blackQueenK[k].posY &&
                           whiteBishop2.posX == blackQueenK[k].posX) {
                            whiteBishop2.posX = 1300;
                        }
                        if(whiteKnight1.posY == blackQueenK[k].posY &&
                           whiteKnight1.posX == blackQueenK[k].posX) {
                            whiteKnight1.posX = 1300;
                        }
                        if(whiteKnight2.posY == blackQueenK[k].posY &&
                           whiteKnight2.posX == blackQueenK[k].posX) {
                            whiteKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           blackQueenK[p].posY == blackQueenK[k].posY + 70 &&
                           blackQueenK[p].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY + 70 &&
                       blackQueen.posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == blackQueenK[k].posY + 70 &&
                       blackPawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackQueenK[k].posY + 70 &&
                       whitePawns[s].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackQueenK[k].posY + 70 &&
                   blackBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY + 70 &&
                   blackBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackQueenK[k].posY + 70 &&
                   blackRook1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackQueenK[k].posY + 70 &&
                   blackRook2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackQueenK[k].posY + 70 &&
                   blackKnight1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackQueenK[k].posY + 70 &&
                   blackKnight2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackQueenK[k].posY + 70 &&
                   blackBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackQueenK[k].posY + 70 &&
                   blackBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int e=0; e<8; e++) {
                    if(whiteQueenK[e].posY == blackQueenK[k].posY + 70 &&
                       whiteQueenK[e].posX == blackQueenK[k].posX) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                   whiteQueen.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY + 70 &&
                   whiteBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY + 70 &&
                   whiteBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackQueenK[k].posY + 70 &&
                   whiteRook1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackQueenK[k].posY + 70 &&
                   whiteRook2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackQueenK[k].posY + 70 &&
                   whiteKnight1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackQueenK[k].posY + 70 &&
                   whiteKnight2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackQueenK[k].posY + 70 &&
                   whiteBishop1.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackQueenK[k].posY + 70 &&
                   whiteBishop2.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                   whiteQueen.posX == blackQueenK[k].posX) {
                    blackQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackQueenK[k].posY = blackQueenK[k].posY + 70;
                }

                return flag;
            }
        }

        else {

            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveWhiteQueenK(UINT msg, int j, int i, int pos, int o, int k) {

    for(int q=0; q<8; q++) {
        if(q != k &&
           blackQueenK[q].posX == whiteQueenK[k].posX &&
           blackQueenK[q].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
        if(q != k &&
           blackQueenK[q].posX == whiteQueenK[k].posX &&
           blackQueenK[q].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(blackQueen.posX == whiteQueenK[k].posX &&
       blackQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == whiteQueenK[k].posX &&
       whiteQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight1.posX == whiteQueenK[k].posX &&
       blackKnight1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteQueenK[k].posX &&
       blackKnight2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteQueenK[k].posX &&
       blackBishop1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteQueenK[k].posX &&
       blackBishop2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteQueenK[k].posX &&
       blackRook1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteQueenK[k].posX &&
       blackRook2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteQueenK[k].posX &&
       blackQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteQueenK[k].posX &&
           blackPawns[g].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteQueenK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                whiteQueenK[k].posY = whiteQueenK[k].posY - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           whiteQueenK[p].posY == whiteQueenK[k].posY &&
                           whiteQueenK[p].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY &&
                       whiteQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY &&
                       whitePawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY &&
                       whiteBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY &&
                       whiteBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY &&
                       whiteKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY &&
                       whiteKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY &&
                       whiteRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY &&
                       whiteRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueenK[k].posY &&
                       whiteKing.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY &&
                       whiteBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY &&
                       whiteBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY &&
                       whiteKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY &&
                       whiteKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY &&
                       whiteRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY &&
                       whiteRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteQueenK[k].posY &&
                       whiteKing.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int r=0; r<8; r++) {
                            if(blackQueenK[r].posY == whiteQueenK[k].posY &&
                               blackQueenK[r].posX == whiteQueenK[k].posX) {
                                blackQueenK[r].posX = 1300;
                            }
                        }
                        if(blackPawns[s].posY == whiteQueenK[k].posY &&
                           blackPawns[s].posX == whiteQueenK[k].posX) {
                            blackPawns[s].posX = 1300;
                        }
                        if(blackQueen.posY == whiteQueenK[k].posY &&
                           blackQueen.posX == whiteQueenK[k].posX) {
                            blackQueen.posX = 1300;
                        }
                        if(blackRook1.posY == whiteQueenK[k].posY &&
                           blackRook1.posX == whiteQueenK[k].posX) {
                            blackRook1.posX = 1300;
                        }
                        if(blackRook2.posY == whiteQueenK[k].posY &&
                           blackRook2.posX == whiteQueenK[k].posX) {
                            blackRook2.posX = 1300;
                        }
                        if(blackBishop1.posY == whiteQueenK[k].posY &&
                           blackBishop1.posX == whiteQueenK[k].posX) {
                            blackBishop1.posX = 1300;
                        }
                        if(blackBishop2.posY == whiteQueenK[k].posY &&
                           blackBishop2.posX == whiteQueenK[k].posX) {
                            blackBishop2.posX = 1300;
                        }
                        if(blackKnight1.posY == whiteQueenK[k].posY &&
                           blackKnight1.posX == whiteQueenK[k].posX) {
                            blackKnight1.posX = 1300;
                        }
                        if(blackKnight2.posY == whiteQueenK[k].posY &&
                           blackKnight2.posX == whiteQueenK[k].posX) {
                            blackKnight2.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           blackQueenK[p].posY == whiteQueenK[k].posY - 70 &&
                           blackQueenK[p].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY - 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY - 70 &&
                       blackQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueenK[k].posY - 70 &&
                       blackPawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY - 70 &&
                       whitePawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                   blackBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                   blackBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueenK[k].posY - 70 &&
                   blackRook1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueenK[k].posY - 70 &&
                   blackRook2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueenK[k].posY - 70 &&
                   blackKnight1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueenK[k].posY - 70 &&
                   blackKnight2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                   blackBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                   blackBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int w=0; w<8; w++) {
                    if(whiteQueenK[w].posY == whiteQueenK[k].posY - 70 &&
                       whiteQueenK[w].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(whiteQueen.posY == whiteQueenK[k].posY - 70 &&
                   whiteQueen.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY - 70 &&
                   whiteBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY - 70 &&
                   whiteBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueenK[k].posY - 70 &&
                   whiteRook1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueenK[k].posY - 70 &&
                   whiteRook2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueenK[k].posY - 70 &&
                   whiteKnight1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueenK[k].posY - 70 &&
                   whiteKnight2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueenK[k].posY = whiteQueenK[k].posY - 70;
                }

                return flag;
            }
        }

        else {

            whiteQueenK[k].failedpath = TRUE;                        
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteQueenK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                whiteQueenK[k].posY = whiteQueenK[k].posY + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           whiteQueenK[p].posY == whiteQueenK[k].posY &&
                           whiteQueenK[p].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY &&
                       whiteQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY &&
                       blackQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueenK[k].posY &&
                       blackPawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY &&
                       blackBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY &&
                       blackBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY &&
                       blackKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY &&
                       blackKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY &&
                       blackRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY &&
                       blackRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY &&
                       blackBishop1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY &&
                       blackBishop2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY &&
                       blackKnight1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY &&
                       blackKnight2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY &&
                       blackRook1.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY &&
                       blackRook2.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    for(int a=0; a<8; a++) {
                        if(blackQueenK[a].posY == whiteQueenK[k].posY &&
                           blackQueenK[a].posX == whiteQueenK[k].posX) {
                            blackQueenK[a].posX = 1300;
                        }
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY &&
                       whitePawns[s].posX == whiteQueenK[k].posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY &&
                       blackQueen.posX == whiteQueenK[k].posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY &&
                       blackRook1.posX == whiteQueenK[k].posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY &&
                       blackRook2.posX == whiteQueenK[k].posX) {
                        blackRook2.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY &&
                       blackBishop1.posX == whiteQueenK[k].posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY &&
                       blackBishop2.posX == whiteQueenK[k].posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY &&
                       blackKnight1.posX == whiteQueenK[k].posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY &&
                       blackKnight2.posX == whiteQueenK[k].posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           whiteQueenK[p].posY == whiteQueenK[k].posY + 70 &&
                           whiteQueenK[p].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY + 70 &&
                       blackQueen.posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteQueenK[k].posY + 70 &&
                       blackPawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == whiteQueenK[k].posY + 70 &&
                       whitePawns[s].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteQueenK[k].posY + 70 &&
                   blackBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY + 70 &&
                   blackBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteQueenK[k].posY + 70 &&
                   blackRook1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteQueenK[k].posY + 70 &&
                   blackRook2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteQueenK[k].posY + 70 &&
                   blackKnight1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteQueenK[k].posY + 70 &&
                   blackKnight2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteQueenK[k].posY + 70 &&
                   blackBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteQueenK[k].posY + 70 &&
                   blackBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int e=0; e<8; e++) {
                    if(whiteQueenK[e].posY == whiteQueenK[k].posY + 70 &&
                       whiteQueenK[e].posX == whiteQueenK[k].posX) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                   whiteQueen.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY + 70 &&
                   whiteBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY + 70 &&
                   whiteBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == whiteQueenK[k].posY + 70 &&
                   whiteRook1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteQueenK[k].posY + 70 &&
                   whiteRook2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteQueenK[k].posY + 70 &&
                   whiteKnight1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteQueenK[k].posY + 70 &&
                   whiteKnight2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == whiteQueenK[k].posY + 70 &&
                   whiteBishop1.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == whiteQueenK[k].posY + 70 &&
                   whiteBishop2.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                   whiteQueen.posX == whiteQueenK[k].posX) {
                    whiteQueenK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteQueenK[k].posY = whiteQueenK[k].posY + 70;
                }

                return flag;
            }
        }

        else {

            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveWhiteQueenDiagonally(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(blackKnight1.posX == whiteQueen.posX &&
       blackKnight1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteQueen.posX &&
       blackKnight2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteQueen.posX &&
       blackBishop1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteQueen.posX &&
       blackBishop2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteQueen.posX &&
       blackRook1.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteQueen.posX &&
       blackRook2.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteQueen.posX &&
       blackQueen.posY == whiteQueen.posY) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteQueen.posX &&
           blackPawns[g].posY == whiteQueen.posY) {
            whiteQueen.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        whiteQueen.failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        whiteQueen.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveWhiteQueenDiagonally(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueen.posY = whiteQueen.posY - 70;
                    whiteQueen.posX = whiteQueen.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteQueen.posY &&
                           whitePawns[s].posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueen.posY &&
                           whiteBishop1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueen.posY &&
                           whiteBishop2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueen.posY &&
                           whiteKnight1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueen.posY &&
                           whiteKnight2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueen.posY &&
                           whiteRook1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueen.posY &&
                           whiteRook2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueen.posY &&
                           whiteKing.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueen.posY &&
                           whiteBishop1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueen.posY &&
                           whiteBishop2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueen.posY &&
                           whiteKnight1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueen.posY &&
                           whiteKnight2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueen.posY &&
                           whiteRook1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueen.posY &&
                           whiteRook2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueen.posY &&
                           whiteKing.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackPawns[s].posY == whiteQueen.posY &&
                               blackPawns[s].posX == whiteQueen.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueen.posY &&
                               blackKnight1.posX == whiteQueen.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueen.posY &&
                               blackKnight2.posX == whiteQueen.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueen.posY &&
                               blackBishop1.posX == whiteQueen.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueen.posY &&
                               blackBishop2.posX == whiteQueen.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueen.posY &&
                               blackRook1.posX == whiteQueen.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueen.posY &&
                               blackRook2.posX == whiteQueen.posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackQueen.posY == whiteQueen.posY &&
                               blackQueen.posX == whiteQueen.posX) {
                                blackQueen.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteQueen.posY - 70 &&
                           blackPawns[s].posX == whiteQueen.posX - 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueen.posY - 70 &&
                           whitePawns[s].posX == whiteQueen.posX - 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueen.posY - 70 &&
                       blackQueen.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY - 70 &&
                       blackBishop1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY - 70 &&
                       blackBishop2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueen.posY - 70 &&
                       blackRook1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueen.posY - 70 &&
                       blackRook2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueen.posY - 70 &&
                       blackKnight1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueen.posY - 70 &&
                       blackKnight2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY - 70 &&
                       blackBishop1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY - 70 &&
                       blackBishop2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueen.posY - 70 &&
                       whiteQueen.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueen.posY - 70 &&
                       whiteBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueen.posY - 70 &&
                       whiteBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY - 70 &&
                       whiteRook1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY - 70 &&
                       whiteRook2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY - 70 &&
                       whiteKnight1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY - 70 &&
                       whiteKnight2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY - 70 &&
                       whiteBishop1.posX == whiteQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY - 70 &&
                       whiteBishop2.posX == whiteQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueen.posY - 70 &&
                       whiteQueen.posX == whiteQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueen.posY = whiteQueen.posY - 70;
                        whiteQueen.posX = whiteQueen.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueen.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveWhiteQueenDiagonally(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueen.posY = whiteQueen.posY - 70;
                    whiteQueen.posX = whiteQueen.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteQueen.posY &&
                           whitePawns[s].posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueen.posY &&
                           whiteBishop1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueen.posY &&
                           whiteBishop2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueen.posY &&
                           whiteKnight1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueen.posY &&
                           whiteKnight2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueen.posY &&
                           whiteRook1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueen.posY &&
                           whiteRook2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueen.posY &&
                           whiteKing.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackPawns[s].posY == whiteQueen.posY &&
                               blackPawns[s].posX == whiteQueen.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueen.posY &&
                               blackKnight1.posX == whiteQueen.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueen.posY &&
                               blackKnight2.posX == whiteQueen.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueen.posY &&
                               blackBishop1.posX == whiteQueen.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueen.posY &&
                               blackBishop2.posX == whiteQueen.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueen.posY &&
                               blackRook1.posX == whiteQueen.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueen.posY &&
                               blackRook2.posX == whiteQueen.posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackQueen.posY == whiteQueen.posY &&
                               blackQueen.posX == whiteQueen.posX) {
                                blackQueen.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteQueen.posY - 70 &&
                           blackPawns[s].posX == whiteQueen.posX + 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueen.posY - 70 &&
                           whitePawns[s].posX == whiteQueen.posX + 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueen.posY - 70 &&
                       blackQueen.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY - 70 &&
                       blackBishop1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY - 70 &&
                       blackBishop2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueen.posY - 70 &&
                       blackRook1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueen.posY - 70 &&
                       blackRook2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueen.posY - 70 &&
                       blackKnight1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueen.posY - 70 &&
                       blackKnight2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY - 70 &&
                       blackBishop1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY - 70 &&
                       blackBishop2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY - 70 &&
                       whiteRook1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY - 70 &&
                       whiteRook2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY - 70 &&
                       whiteKnight1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY - 70 &&
                       whiteKnight2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY - 70 &&
                       whiteBishop1.posX == whiteQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY - 70 &&
                       whiteBishop2.posX == whiteQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueen.posY - 70 &&
                       whiteQueen.posX == whiteQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueen.posY = whiteQueen.posY - 70;
                        whiteQueen.posX = whiteQueen.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueen.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveWhiteQueenDiagonally(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueen.posY = whiteQueen.posY + 70;
                    whiteQueen.posX = whiteQueen.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteQueen.posY &&
                           whitePawns[s].posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueen.posY &&
                           whiteBishop1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueen.posY &&
                           whiteBishop2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueen.posY &&
                           whiteKnight1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueen.posY &&
                           whiteKnight2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueen.posY &&
                           whiteRook1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueen.posY &&
                           whiteRook2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueen.posY &&
                           whiteKing.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackPawns[s].posY == whiteQueen.posY &&
                               blackPawns[s].posX == whiteQueen.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueen.posY &&
                               blackKnight1.posX == whiteQueen.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueen.posY &&
                               blackKnight2.posX == whiteQueen.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueen.posY &&
                               blackBishop1.posX == whiteQueen.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueen.posY &&
                               blackBishop2.posX == whiteQueen.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueen.posY &&
                               blackRook1.posX == whiteQueen.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueen.posY &&
                               blackRook2.posX == whiteQueen.posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackQueen.posY == whiteQueen.posY &&
                               blackQueen.posX == whiteQueen.posX) {
                                blackQueen.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteQueen.posY + 70 &&
                           blackPawns[s].posX == whiteQueen.posX - 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueen.posY + 70 &&
                           whitePawns[s].posX == whiteQueen.posX - 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueen.posY + 70 &&
                       blackQueen.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY + 70 &&
                       blackBishop1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY + 70 &&
                       blackBishop2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueen.posY + 70 &&
                       blackRook1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueen.posY + 70 &&
                       blackRook2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueen.posY + 70 &&
                       blackKnight1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueen.posY + 70 &&
                       blackKnight2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY + 70 &&
                       blackBishop1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY + 70 &&
                       blackBishop2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY + 70 &&
                       whiteRook1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY + 70 &&
                       whiteRook2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY + 70 &&
                       whiteKnight1.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY + 70 &&
                       whiteKnight2.posX == whiteQueen.posX - 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY + 70 &&
                       whiteBishop1.posX == whiteQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY + 70 &&
                       whiteBishop2.posX == whiteQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueen.posY + 70 &&
                       whiteQueen.posX == whiteQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueen.posY = whiteQueen.posY + 70;
                        whiteQueen.posX = whiteQueen.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueen.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveWhiteQueenDiagonally(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueen.posY = whiteQueen.posY + 70;
                    whiteQueen.posX = whiteQueen.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteQueen.posY &&
                           whitePawns[s].posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueen.posY &&
                           whiteBishop1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueen.posY &&
                           whiteBishop2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueen.posY &&
                           whiteKnight1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueen.posY &&
                           whiteKnight2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueen.posY &&
                           whiteRook1.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueen.posY &&
                           whiteRook2.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueen.posY &&
                           whiteKing.posX == whiteQueen.posX) {
                            whiteQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackPawns[s].posY == whiteQueen.posY &&
                               blackPawns[s].posX == whiteQueen.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueen.posY &&
                               blackKnight1.posX == whiteQueen.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueen.posY &&
                               blackKnight2.posX == whiteQueen.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueen.posY &&
                               blackBishop1.posX == whiteQueen.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueen.posY &&
                               blackBishop2.posX == whiteQueen.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueen.posY &&
                               blackRook1.posX == whiteQueen.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueen.posY &&
                               blackRook2.posX == whiteQueen.posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackQueen.posY == whiteQueen.posY &&
                               blackQueen.posX == whiteQueen.posX) {
                                blackQueen.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteQueen.posY + 70 &&
                           blackPawns[s].posX == whiteQueen.posX + 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueen.posY + 70 &&
                           whitePawns[s].posX == whiteQueen.posX + 70) {
                            whiteQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueen.posY + 70 &&
                       blackQueen.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY + 70 &&
                       blackBishop1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY + 70 &&
                       blackBishop2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueen.posY + 70 &&
                       blackRook1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueen.posY + 70 &&
                       blackRook2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueen.posY + 70 &&
                       blackKnight1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueen.posY + 70 &&
                       blackKnight2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueen.posY + 70 &&
                       blackBishop1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueen.posY + 70 &&
                       blackBishop2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueen.posY + 70 &&
                       whiteRook1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueen.posY + 70 &&
                       whiteRook2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueen.posY + 70 &&
                       whiteKnight1.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueen.posY + 70 &&
                       whiteKnight2.posX == whiteQueen.posX + 70) {
                        whiteQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueen.posY + 70 &&
                       whiteBishop1.posX == whiteQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueen.posY + 70 &&
                       whiteBishop2.posX == whiteQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueen.posY + 70 &&
                       whiteQueen.posX == whiteQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueen.posY = whiteQueen.posY + 70;
                        whiteQueen.posX = whiteQueen.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueen.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveBlackQueenDiagonally(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(whiteKnight1.posX == blackQueen.posX &&
       whiteKnight1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackQueen.posX &&
       whiteKnight2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackQueen.posX &&
       whiteBishop1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackQueen.posX &&
       whiteBishop2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackQueen.posX &&
       whiteRook1.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackQueen.posX &&
       whiteRook2.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueen.posX &&
       whiteQueen.posY == blackQueen.posY) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackQueen.posX &&
           whitePawns[g].posY == blackQueen.posY) {
            blackQueen.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        blackQueen.failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        blackQueen.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveBlackQueenDiagonally(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueen.posY = blackQueen.posY - 70;
                    blackQueen.posX = blackQueen.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY &&
                           blackPawns[s].posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueen.posY &&
                           blackBishop1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueen.posY &&
                           blackBishop2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueen.posY &&
                           blackKnight1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueen.posY &&
                           blackKnight2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueen.posY &&
                           blackRook1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueen.posY &&
                           blackRook2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueen.posY &&
                           blackKing.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whitePawns[s].posY == blackQueen.posY &&
                               whitePawns[s].posX == blackQueen.posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueen.posY &&
                               whiteRook1.posX == blackQueen.posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueen.posY &&
                               whiteRook2.posX == blackQueen.posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY - 70 &&
                           blackPawns[s].posX == blackQueen.posX - 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueen.posY - 70 &&
                           whitePawns[s].posX == blackQueen.posX - 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackQueen.posY - 70 &&
                       blackBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY - 70 &&
                       blackBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY - 70 &&
                       blackRook1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY - 70 &&
                       blackRook2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY - 70 &&
                       blackKnight1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY - 70 &&
                       blackKnight2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY - 70 &&
                       blackBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY - 70 &&
                       blackBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueen.posY - 70 &&
                       whiteRook1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueen.posY - 70 &&
                       whiteRook2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueen.posY - 70 &&
                       whiteKnight1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueen.posY - 70 &&
                       whiteKnight2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(blackBishop1.posY == blackQueen.posY - 70 &&
                       blackBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY - 70 &&
                       blackBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY - 70 &&
                       blackRook1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY - 70 &&
                       blackRook2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY - 70 &&
                       blackKnight1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY - 70 &&
                       blackKnight2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY - 70 &&
                       blackBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY - 70 &&
                       blackBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueen.posY - 70 &&
                       whiteRook1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueen.posY - 70 &&
                       whiteRook2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueen.posY - 70 &&
                       whiteKnight1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueen.posY - 70 &&
                       whiteKnight2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueen.posY + 70 &&
                       whiteBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueen.posY + 70 &&
                       whiteBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueen.posY + 70 &&
                       whiteQueen.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueen.posY = blackQueen.posY - 70;
                        blackQueen.posX = blackQueen.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueen.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveBlackQueenDiagonally(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueen.posY = blackQueen.posY - 70;
                    blackQueen.posX = blackQueen.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY &&
                           blackPawns[s].posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueen.posY &&
                           blackBishop1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueen.posY &&
                           blackBishop2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueen.posY &&
                           blackKnight1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueen.posY &&
                           blackKnight2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueen.posY &&
                           blackRook1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueen.posY &&
                           blackRook2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueen.posY &&
                           blackKing.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whitePawns[s].posY == blackQueen.posY &&
                               whitePawns[s].posX == blackQueen.posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueen.posY &&
                               whiteRook1.posX == blackQueen.posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueen.posY &&
                               whiteRook2.posX == blackQueen.posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY - 70 &&
                           blackPawns[s].posX == blackQueen.posX + 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueen.posY - 70 &&
                           whitePawns[s].posX == blackQueen.posX + 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackQueen.posY - 70 &&
                       blackBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY - 70 &&
                       blackBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY - 70 &&
                       blackRook1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY - 70 &&
                       blackRook2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY - 70 &&
                       blackKnight1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY - 70 &&
                       blackKnight2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY - 70 &&
                       blackBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY - 70 &&
                       blackBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueen.posY - 70 &&
                       whiteRook1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueen.posY - 70 &&
                       whiteRook2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueen.posY - 70 &&
                       whiteKnight1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueen.posY - 70 &&
                       whiteKnight2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueen.posY + 70 &&
                       whiteBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueen.posY + 70 &&
                       whiteBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueen.posY + 70 &&
                       whiteQueen.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueen.posY = blackQueen.posY - 70;
                        blackQueen.posX = blackQueen.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueen.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveBlackQueenDiagonally(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueen.posY = blackQueen.posY + 70;
                    blackQueen.posX = blackQueen.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY &&
                           blackPawns[s].posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueen.posY &&
                           blackBishop1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueen.posY &&
                           blackBishop2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueen.posY &&
                           blackKnight1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueen.posY &&
                           blackKnight2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueen.posY &&
                           blackRook1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueen.posY &&
                           blackRook2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueen.posY &&
                           blackKing.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whitePawns[s].posY == blackQueen.posY &&
                               whitePawns[s].posX == blackQueen.posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueen.posY &&
                               whiteRook1.posX == blackQueen.posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueen.posY &&
                               whiteRook2.posX == blackQueen.posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY + 70 &&
                           blackPawns[s].posX == blackQueen.posX - 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueen.posY + 70 &&
                           whitePawns[s].posX == blackQueen.posX - 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackQueen.posY + 70 &&
                       blackBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY + 70 &&
                       blackBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY + 70 &&
                       blackRook1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY + 70 &&
                       blackRook2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY + 70 &&
                       blackKnight1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY + 70 &&
                       blackKnight2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY + 70 &&
                       blackBishop1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY + 70 &&
                       blackBishop2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueen.posY + 70 &&
                       whiteRook1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueen.posY + 70 &&
                       whiteRook2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueen.posY + 70 &&
                       whiteKnight1.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueen.posY + 70 &&
                       whiteKnight2.posX == blackQueen.posX - 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueen.posY + 70 &&
                       whiteBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueen.posY + 70 &&
                       whiteBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueen.posY + 70 &&
                       whiteQueen.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueen.posY = blackQueen.posY + 70;
                        blackQueen.posX = blackQueen.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueen.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveBlackQueenDiagonally(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueen.posY = blackQueen.posY + 70;
                    blackQueen.posX = blackQueen.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY &&
                           blackPawns[s].posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueen.posY &&
                           blackBishop1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueen.posY &&
                           blackBishop2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueen.posY &&
                           blackKnight1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueen.posY &&
                           blackKnight2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueen.posY &&
                           blackRook1.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueen.posY &&
                           blackRook2.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueen.posY &&
                           blackKing.posX == blackQueen.posX) {
                            blackQueen.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whitePawns[s].posY == blackQueen.posY &&
                               whitePawns[s].posX == blackQueen.posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueen.posY &&
                               whiteRook1.posX == blackQueen.posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueen.posY &&
                               whiteRook2.posX == blackQueen.posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueen.posY &&
                               whiteBishop1.posX == blackQueen.posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueen.posY &&
                               whiteBishop2.posX == blackQueen.posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueen.posY &&
                               whiteKnight1.posX == blackQueen.posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueen.posY &&
                               whiteKnight2.posX == blackQueen.posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueen.posY + 70 &&
                           blackPawns[s].posX == blackQueen.posX + 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueen.posY + 70 &&
                           whitePawns[s].posX == blackQueen.posX + 70) {
                            blackQueen.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackQueen.posY + 70 &&
                       blackBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY + 70 &&
                       blackBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueen.posY + 70 &&
                       blackRook1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueen.posY + 70 &&
                       blackRook2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueen.posY + 70 &&
                       blackKnight1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueen.posY + 70 &&
                       blackKnight2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueen.posY + 70 &&
                       blackBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueen.posY + 70 &&
                       blackBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueen.posY + 70 &&
                       whiteRook1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueen.posY + 70 &&
                       whiteRook2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueen.posY + 70 &&
                       whiteKnight1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueen.posY + 70 &&
                       whiteKnight2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueen.posY + 70 &&
                       whiteBishop1.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueen.posY + 70 &&
                       whiteBishop2.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueen.posY + 70 &&
                       whiteQueen.posX == blackQueen.posX + 70) {
                        blackQueen.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueen.posY = blackQueen.posY + 70;
                        blackQueen.posX = blackQueen.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueen.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveBlackQueenDiagonallyK(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2, int k) {

    for(int p=0; p<8; p++) {
        if(p != k &&
           blackQueenK[p].posX == blackQueenK[k].posX &&
           blackQueenK[p].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
        if(p != k &&
           whiteQueenK[p].posX == blackQueenK[k].posX &&
           whiteQueenK[p].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(blackQueen.posX == blackQueenK[k].posX &&
       blackQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueenK[k].posX &&
       whiteQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackQueenK[k].posX &&
       whiteKnight1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackQueenK[k].posX &&
       whiteKnight2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackQueenK[k].posX &&
       whiteBishop1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackQueenK[k].posX &&
       whiteBishop2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackQueenK[k].posX &&
       whiteRook1.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackQueenK[k].posX &&
       whiteRook2.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackQueenK[k].posX &&
       whiteQueen.posY == blackQueenK[k].posY) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackQueenK[k].posX &&
           whitePawns[g].posY == blackQueenK[k].posY) {
            blackQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        blackQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        blackQueenK[k].failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveBlackQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueenK[k].posY = blackQueenK[k].posY - 70;
                    blackQueenK[k].posX = blackQueenK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               blackQueenK[p].posX == blackQueenK[k].posX &&
                               blackQueenK[p].posY == blackQueenK[k].posY) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(blackQueen.posX == blackQueenK[k].posX &&
                           blackQueen.posY == blackQueenK[k].posY) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackPawns[s].posY == blackQueenK[k].posY &&
                           blackPawns[s].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueenK[k].posY &&
                           blackBishop1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueenK[k].posY &&
                           blackBishop2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueenK[k].posY &&
                           blackKnight1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueenK[k].posY &&
                           blackKnight2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueenK[k].posY &&
                           blackRook1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueenK[k].posY &&
                           blackRook2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueenK[k].posY &&
                           blackKing.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(whiteQueenK[r].posY == blackQueenK[k].posY &&
                                   whiteQueenK[r].posX == blackQueenK[k].posX) {
                                    whiteQueenK[r].posX = 1300;
                                }
                            }
                            if(whiteQueen.posY == blackQueenK[k].posY &&
                               whiteQueen.posX == blackQueenK[k].posX) {
                                whiteQueen.posX = 1300;
                            }
                            if(whitePawns[s].posY == blackQueenK[k].posY &&
                               whitePawns[s].posX == blackQueenK[k].posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueenK[k].posY &&
                               whiteRook1.posX == blackQueenK[k].posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueenK[k].posY &&
                               whiteRook2.posX == blackQueenK[k].posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueenK[k].posY - 70 &&
                           blackPawns[s].posX == blackQueenK[k].posX - 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY - 70 &&
                           whitePawns[s].posX == blackQueenK[k].posX - 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               blackQueenK[p].posX == blackQueenK[k].posX - 70 &&
                               blackQueenK[p].posY == blackQueenK[k].posY - 70) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               whiteQueenK[p].posX == blackQueenK[k].posX - 70 &&
                               whiteQueenK[p].posY == blackQueenK[k].posY - 70) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                    }
                    if(blackQueen.posX == blackQueenK[k].posX - 70 &&
                       blackQueen.posY == blackQueenK[k].posY - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteQueen.posX == blackQueenK[k].posX - 70 &&
                       whiteQueen.posY == blackQueenK[k].posY - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                       blackBishop1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                       blackBishop2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY - 70 &&
                       blackRook1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY - 70 &&
                       blackRook2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY - 70 &&
                       blackKnight1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY - 70 &&
                       blackKnight2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                       blackBishop1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                       blackBishop2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueenK[k].posY - 70 &&
                       whiteRook1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueenK[k].posY - 70 &&
                       whiteRook2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueenK[k].posY - 70 &&
                       whiteKnight1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueenK[k].posY - 70 &&
                       whiteKnight2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                       blackBishop1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                       blackBishop2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY - 70 &&
                       blackRook1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY - 70 &&
                       blackRook2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY - 70 &&
                       blackKnight1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY - 70 &&
                       blackKnight2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                       blackBishop1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                       blackBishop2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueenK[k].posY - 70 &&
                       whiteRook1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueenK[k].posY - 70 &&
                       whiteRook2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueenK[k].posY - 70 &&
                       whiteKnight1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueenK[k].posY - 70 &&
                       whiteKnight2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                       whiteQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueenK[k].posY = blackQueenK[k].posY - 70;
                        blackQueenK[k].posX = blackQueenK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveBlackQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueenK[k].posY = blackQueenK[k].posY - 70;
                    blackQueenK[k].posX = blackQueenK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               blackQueenK[p].posX == blackQueenK[k].posX &&
                               blackQueenK[p].posY == blackQueenK[k].posY) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(blackQueen.posX == blackQueenK[k].posX &&
                           blackQueen.posY == blackQueenK[k].posY) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackPawns[s].posY == blackQueenK[k].posY &&
                           blackPawns[s].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueenK[k].posY &&
                           blackBishop1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueenK[k].posY &&
                           blackBishop2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueenK[k].posY &&
                           blackKnight1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueenK[k].posY &&
                           blackKnight2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueenK[k].posY &&
                           blackRook1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueenK[k].posY &&
                           blackRook2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueenK[k].posY &&
                           blackKing.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(whiteQueenK[r].posY == blackQueenK[k].posY &&
                                   whiteQueenK[r].posX == blackQueenK[k].posX) {
                                    whiteQueenK[r].posX = 1300;
                                }
                            }
                            if(whiteQueen.posY == blackQueenK[k].posY &&
                               whiteQueen.posX == blackQueenK[k].posX) {
                                whiteQueen.posX = 1300;
                            }
                            if(whitePawns[s].posY == blackQueenK[k].posY &&
                               whitePawns[s].posX == blackQueenK[k].posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueenK[k].posY &&
                               whiteRook1.posX == blackQueenK[k].posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueenK[k].posY &&
                               whiteRook2.posX == blackQueenK[k].posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               blackQueenK[h].posY == blackQueenK[k].posY - 70 &&
                               blackQueenK[h].posX == blackQueenK[k].posX + 70) {
                                blackQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               whiteQueenK[h].posY == blackQueenK[k].posY - 70 &&
                               whiteQueenK[h].posX == blackQueenK[k].posX + 70) {
                                blackQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(blackQueen.posY == blackQueenK[k].posY - 70 &&
                           blackQueen.posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(blackPawns[s].posY == blackQueenK[k].posY - 70 &&
                           blackPawns[s].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY - 70 &&
                           whitePawns[s].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                       blackBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                       blackBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY - 70 &&
                       blackRook1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY - 70 &&
                       blackRook2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY - 70 &&
                       blackKnight1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY - 70 &&
                       blackKnight2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY - 70 &&
                       blackBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY - 70 &&
                       blackBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueenK[k].posY - 70 &&
                       whiteRook1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueenK[k].posY - 70 &&
                       whiteRook2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueenK[k].posY - 70 &&
                       whiteKnight1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueenK[k].posY - 70 &&
                       whiteKnight2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                       whiteQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueenK[k].posY = blackQueenK[k].posY - 70;
                        blackQueenK[k].posX = blackQueenK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveBlackQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueenK[k].posY = blackQueenK[k].posY + 70;
                    blackQueenK[k].posX = blackQueenK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               blackQueenK[p].posY == blackQueenK[k].posY &&
                               blackQueenK[p].posX == blackQueenK[k].posX) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        for(int p=0; p<8; p++) {
                            if(blackQueenK[p].posY == blackQueenK[k].posY &&
                               blackQueenK[p].posX == blackQueenK[k].posX) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(blackQueen.posY == blackQueenK[k].posY &&
                           blackQueen.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackPawns[s].posY == blackQueenK[k].posY &&
                           blackPawns[s].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueenK[k].posY &&
                           blackBishop1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueenK[k].posY &&
                           blackBishop2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueenK[k].posY &&
                           blackKnight1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueenK[k].posY &&
                           blackKnight2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueenK[k].posY &&
                           blackRook1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueenK[k].posY &&
                           blackRook2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueenK[k].posY &&
                           blackKing.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(whiteQueenK[r].posY == blackQueenK[k].posY &&
                                   whiteQueenK[r].posX == blackQueenK[k].posX) {
                                    whiteQueenK[r].posX = 1300;
                                }
                            }
                            if(whiteQueen.posY == blackQueenK[k].posY &&
                               whiteQueen.posX == blackQueenK[k].posX) {
                                whiteQueen.posX = 1300;
                            }
                            if(whitePawns[s].posY == blackQueenK[k].posY &&
                               whitePawns[s].posX == blackQueenK[k].posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueenK[k].posY &&
                               whiteRook1.posX == blackQueenK[k].posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueenK[k].posY &&
                               whiteRook2.posX == blackQueenK[k].posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               blackQueenK[p].posY == blackQueenK[k].posY + 70 &&
                               blackQueenK[p].posX == blackQueenK[k].posX - 70) {
                                blackQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                            if(p != k &&
                               whiteQueenK[p].posY == blackQueenK[k].posY + 70 &&
                               whiteQueenK[p].posX == blackQueenK[k].posX - 70) {
                                blackQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(blackPawns[s].posY == blackQueenK[k].posY + 70 &&
                           blackPawns[s].posX == blackQueenK[k].posX - 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY + 70 &&
                           whitePawns[s].posX == blackQueenK[k].posX - 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY + 70 &&
                       blackQueen.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                       whiteQueen.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY + 70 &&
                       blackBishop1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY + 70 &&
                       blackBishop2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY + 70 &&
                       blackRook1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY + 70 &&
                       blackRook2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY + 70 &&
                       blackKnight1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY + 70 &&
                       blackKnight2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY + 70 &&
                       blackBishop1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY + 70 &&
                       blackBishop2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueenK[k].posY + 70 &&
                       whiteRook1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueenK[k].posY + 70 &&
                       whiteRook2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueenK[k].posY + 70 &&
                       whiteKnight1.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueenK[k].posY + 70 &&
                       whiteKnight2.posX == blackQueenK[k].posX - 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                       whiteQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueenK[k].posY = blackQueenK[k].posY + 70;
                        blackQueenK[k].posX = blackQueenK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveBlackQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackQueenK[k].posY = blackQueenK[k].posY + 70;
                    blackQueenK[k].posX = blackQueenK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               blackQueenK[p].posY == blackQueenK[k].posY &&
                               blackQueenK[p].posX == blackQueenK[k].posX) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               whiteQueenK[p].posY == blackQueenK[k].posY &&
                               whiteQueenK[p].posX == blackQueenK[k].posX) {
                                blackQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(blackQueen.posY == blackQueenK[k].posY &&
                           blackQueen.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackPawns[s].posY == blackQueenK[k].posY &&
                           blackPawns[s].posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackQueenK[k].posY &&
                           blackBishop1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackQueenK[k].posY &&
                           blackBishop2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackQueenK[k].posY &&
                           blackKnight1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackQueenK[k].posY &&
                           blackKnight2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackQueenK[k].posY &&
                           blackRook1.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackQueenK[k].posY &&
                           blackRook2.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackQueenK[k].posY &&
                           blackKing.posX == blackQueenK[k].posX) {
                            blackQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(whiteQueenK[r].posY == blackQueenK[k].posY &&
                                   whiteQueenK[r].posX == blackQueenK[k].posX) {
                                    whiteQueenK[r].posX = 1300;
                                }
                            }
                            if(whiteQueen.posY == blackQueenK[k].posY &&
                               whiteQueen.posX == blackQueenK[k].posX) {
                                whiteQueen.posX = 1300;
                            }
                            if(whitePawns[s].posY == blackQueenK[k].posY &&
                               whitePawns[s].posX == blackQueenK[k].posX) {
                                whitePawns[s].posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteRook1.posY == blackQueenK[k].posY &&
                               whiteRook1.posX == blackQueenK[k].posX) {
                                whiteRook1.posX = 1300;
                            }
                            if(whiteRook2.posY == blackQueenK[k].posY &&
                               whiteRook2.posX == blackQueenK[k].posX) {
                                whiteRook2.posX = 1300;
                            }
                            if(whiteBishop1.posY == blackQueenK[k].posY &&
                               whiteBishop1.posX == blackQueenK[k].posX) {
                                whiteBishop1.posX = 1300;
                            }
                            if(whiteBishop2.posY == blackQueenK[k].posY &&
                               whiteBishop2.posX == blackQueenK[k].posX) {
                                whiteBishop2.posX = 1300;
                            }
                            if(whiteKnight1.posY == blackQueenK[k].posY &&
                               whiteKnight1.posX == blackQueenK[k].posX) {
                                whiteKnight1.posX = 1300;
                            }
                            if(whiteKnight2.posY == blackQueenK[k].posY &&
                               whiteKnight2.posX == blackQueenK[k].posX) {
                                whiteKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackQueenK[k].posY + 70 &&
                           blackPawns[s].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackQueenK[k].posY + 70 &&
                           whitePawns[s].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           blackQueenK[s].posY == blackQueenK[k].posY + 70 &&
                           blackQueenK[s].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           whiteQueenK[s].posY == blackQueenK[k].posY + 70 &&
                           whiteQueenK[s].posX == blackQueenK[k].posX + 70) {
                            blackQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == blackQueenK[k].posY + 70 &&
                       blackQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                       whiteQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY + 70 &&
                       blackBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY + 70 &&
                       blackBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackQueenK[k].posY + 70 &&
                       blackRook1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackQueenK[k].posY + 70 &&
                       blackRook2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackQueenK[k].posY + 70 &&
                       blackKnight1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackQueenK[k].posY + 70 &&
                       blackKnight2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackQueenK[k].posY + 70 &&
                       blackBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackQueenK[k].posY + 70 &&
                       blackBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackQueenK[k].posY + 70 &&
                       whiteRook1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackQueenK[k].posY + 70 &&
                       whiteRook2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackQueenK[k].posY + 70 &&
                       whiteKnight1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackQueenK[k].posY + 70 &&
                       whiteKnight2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop1.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackQueenK[k].posY + 70 &&
                       whiteBishop2.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackQueenK[k].posY + 70 &&
                       whiteQueen.posX == blackQueenK[k].posX + 70) {
                        blackQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackQueenK[k].posY = blackQueenK[k].posY + 70;
                        blackQueenK[k].posX = blackQueenK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveWhiteQueenDiagonallyK(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2, int k) {

    for(int p=0; p<8; p++) {
        if(p != k &&
           whiteQueenK[p].posX == whiteQueenK[k].posX &&
           whiteQueenK[p].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
        if(p != k &&
           whiteQueenK[p].posX == whiteQueenK[k].posX &&
           whiteQueenK[p].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(blackQueen.posX == whiteQueenK[k].posX &&
       blackQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == whiteQueenK[k].posX &&
       whiteQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight1.posX == whiteQueenK[k].posX &&
       blackKnight1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteQueenK[k].posX &&
       blackKnight2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteQueenK[k].posX &&
       blackBishop1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteQueenK[k].posX &&
       blackBishop2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteQueenK[k].posX &&
       blackRook1.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteQueenK[k].posX &&
       blackRook2.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteQueenK[k].posX &&
       blackQueen.posY == whiteQueenK[k].posY) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteQueenK[k].posX &&
           blackPawns[g].posY == whiteQueenK[k].posY) {
            whiteQueenK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        whiteQueenK[k].failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        whiteQueenK[k].failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveWhiteQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueenK[k].posY = whiteQueenK[k].posY - 70;
                    whiteQueenK[k].posX = whiteQueenK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(whiteQueen.posX == whiteQueenK[k].posX &&
                           whiteQueen.posY == whiteQueenK[k].posY) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY &&
                           whitePawns[s].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueenK[k].posY &&
                           whiteBishop1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueenK[k].posY &&
                           whiteBishop2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueenK[k].posY &&
                           whiteKnight1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueenK[k].posY &&
                           whiteKnight2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueenK[k].posY &&
                           whiteRook1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueenK[k].posY &&
                           whiteRook2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueenK[k].posY &&
                           whiteKing.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(blackQueenK[r].posY == whiteQueenK[k].posY &&
                                   blackQueenK[r].posX == whiteQueenK[k].posX) {
                                    blackQueenK[r].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteQueenK[k].posY &&
                               blackQueen.posX == whiteQueenK[k].posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteQueenK[k].posY &&
                               blackPawns[s].posX == whiteQueenK[k].posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueenK[k].posY &&
                               blackRook1.posX == whiteQueenK[k].posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueenK[k].posY &&
                               blackRook2.posX == whiteQueenK[k].posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteQueenK[k].posY - 70 &&
                           blackPawns[s].posX == whiteQueenK[k].posX - 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY - 70 &&
                           whitePawns[s].posX == whiteQueenK[k].posX - 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX - 70 &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY - 70) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX - 70 &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY - 70) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                    }
                    if(blackQueen.posX == whiteQueenK[k].posX - 70 &&
                       blackQueen.posY == whiteQueenK[k].posY - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteQueen.posX == whiteQueenK[k].posX - 70 &&
                       whiteQueen.posY == whiteQueenK[k].posY - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY - 70 &&
                       blackRook1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY - 70 &&
                       blackRook2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY - 70 &&
                       blackKnight1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY - 70 &&
                       blackKnight2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY - 70 &&
                       whiteRook1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY - 70 &&
                       whiteRook2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY - 70 &&
                       whiteKnight1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY - 70 &&
                       whiteKnight2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY - 70 &&
                       blackRook1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY - 70 &&
                       blackRook2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY - 70 &&
                       blackKnight1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY - 70 &&
                       blackKnight2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY - 70 &&
                       whiteRook1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY - 70 &&
                       whiteRook2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY - 70 &&
                       whiteKnight1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY - 70 &&
                       whiteKnight2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueenK[k].posY = whiteQueenK[k].posY - 70;
                        whiteQueenK[k].posX = whiteQueenK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveWhiteQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueenK[k].posY = whiteQueenK[k].posY - 70;
                    whiteQueenK[k].posX = whiteQueenK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(whiteQueen.posX == whiteQueenK[k].posX &&
                           whiteQueen.posY == whiteQueenK[k].posY) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY &&
                           whitePawns[s].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueenK[k].posY &&
                           whiteBishop1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueenK[k].posY &&
                           whiteBishop2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueenK[k].posY &&
                           whiteKnight1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueenK[k].posY &&
                           whiteKnight2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueenK[k].posY &&
                           whiteRook1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueenK[k].posY &&
                           whiteRook2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueenK[k].posY &&
                           whiteKing.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(blackQueenK[r].posY == whiteQueenK[k].posY &&
                                   blackQueenK[r].posX == whiteQueenK[k].posX) {
                                    blackQueenK[r].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteQueenK[k].posY &&
                               blackQueen.posX == whiteQueenK[k].posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteQueenK[k].posY &&
                               blackPawns[s].posX == whiteQueenK[k].posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueenK[k].posY &&
                               blackRook1.posX == whiteQueenK[k].posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueenK[k].posY &&
                               blackRook2.posX == whiteQueenK[k].posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               whiteQueenK[h].posY == whiteQueenK[k].posY - 70 &&
                               whiteQueenK[h].posX == whiteQueenK[k].posX + 70) {
                                whiteQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               whiteQueenK[h].posY == whiteQueenK[k].posY - 70 &&
                               whiteQueenK[h].posX == whiteQueenK[k].posX + 70) {
                                whiteQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(blackQueen.posY == whiteQueenK[k].posY - 70 &&
                           blackQueen.posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(blackPawns[s].posY == whiteQueenK[k].posY - 70 &&
                           blackPawns[s].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY - 70 &&
                           whitePawns[s].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY - 70 &&
                       blackRook1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY - 70 &&
                       blackRook2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY - 70 &&
                       blackKnight1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY - 70 &&
                       blackKnight2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY - 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY - 70 &&
                       whiteRook1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY - 70 &&
                       whiteRook2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY - 70 &&
                       whiteKnight1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY - 70 &&
                       whiteKnight2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueenK[k].posY = whiteQueenK[k].posY - 70;
                        whiteQueenK[k].posX = whiteQueenK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveWhiteQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueenK[k].posY = whiteQueenK[k].posY + 70;
                    whiteQueenK[k].posX = whiteQueenK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(whiteQueen.posY == whiteQueenK[k].posY &&
                           whiteQueen.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY &&
                           whitePawns[s].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueenK[k].posY &&
                           whiteBishop1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueenK[k].posY &&
                           whiteBishop2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueenK[k].posY &&
                           whiteKnight1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueenK[k].posY &&
                           whiteKnight2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueenK[k].posY &&
                           whiteRook1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueenK[k].posY &&
                           whiteRook2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueenK[k].posY &&
                           whiteKing.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(blackQueenK[r].posY == whiteQueenK[k].posY &&
                                   blackQueenK[r].posX == whiteQueenK[k].posX) {
                                    blackQueenK[r].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteQueenK[k].posY &&
                               blackQueen.posX == whiteQueenK[k].posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteQueenK[k].posY &&
                               blackPawns[s].posX == whiteQueenK[k].posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueenK[k].posY &&
                               blackRook1.posX == whiteQueenK[k].posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueenK[k].posY &&
                               blackRook2.posX == whiteQueenK[k].posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY + 70 &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX - 70) {
                                whiteQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                            if(p != k &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY + 70 &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX - 70) {
                                whiteQueenK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(blackPawns[s].posY == whiteQueenK[k].posY + 70 &&
                           blackPawns[s].posX == whiteQueenK[k].posX - 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY + 70 &&
                           whitePawns[s].posX == whiteQueenK[k].posX - 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY + 70 &&
                       blackQueen.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY + 70 &&
                       blackRook1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY + 70 &&
                       blackRook2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY + 70 &&
                       blackKnight1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY + 70 &&
                       blackKnight2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY + 70 &&
                       whiteRook1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY + 70 &&
                       whiteRook2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY + 70 &&
                       whiteKnight1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY + 70 &&
                       whiteKnight2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop1.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop2.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX - 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueenK[k].posY = whiteQueenK[k].posY + 70;
                        whiteQueenK[k].posX = whiteQueenK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveWhiteQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteQueenK[k].posY = whiteQueenK[k].posY + 70;
                    whiteQueenK[k].posX = whiteQueenK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               whiteQueenK[p].posY == whiteQueenK[k].posY &&
                               whiteQueenK[p].posX == whiteQueenK[k].posX) {
                                whiteQueenK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(whiteQueen.posY == whiteQueenK[k].posY &&
                           whiteQueen.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY &&
                           whitePawns[s].posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteQueenK[k].posY &&
                           whiteBishop1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteQueenK[k].posY &&
                           whiteBishop2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteQueenK[k].posY &&
                           whiteKnight1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteQueenK[k].posY &&
                           whiteKnight2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteQueenK[k].posY &&
                           whiteRook1.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteQueenK[k].posY &&
                           whiteRook2.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteQueenK[k].posY &&
                           whiteKing.posX == whiteQueenK[k].posX) {
                            whiteQueenK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(blackQueenK[r].posY == whiteQueenK[k].posY &&
                                   blackQueenK[r].posX == whiteQueenK[k].posX) {
                                    blackQueenK[r].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteQueenK[k].posY &&
                               blackQueen.posX == whiteQueenK[k].posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteQueenK[k].posY &&
                               blackPawns[s].posX == whiteQueenK[k].posX) {
                                blackPawns[s].posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteQueenK[k].posY &&
                               blackRook1.posX == whiteQueenK[k].posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteQueenK[k].posY &&
                               blackRook2.posX == whiteQueenK[k].posX) {
                                blackRook2.posX = 1300;
                            }
                            if(blackBishop1.posY == whiteQueenK[k].posY &&
                               blackBishop1.posX == whiteQueenK[k].posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteQueenK[k].posY &&
                               blackBishop2.posX == whiteQueenK[k].posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteQueenK[k].posY &&
                               blackKnight1.posX == whiteQueenK[k].posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteQueenK[k].posY &&
                               blackKnight2.posX == whiteQueenK[k].posX) {
                                blackKnight2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteQueenK[k].posY + 70 &&
                           blackPawns[s].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteQueenK[k].posY + 70 &&
                           whitePawns[s].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           whiteQueenK[s].posY == whiteQueenK[k].posY + 70 &&
                           whiteQueenK[s].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           whiteQueenK[s].posY == whiteQueenK[k].posY + 70 &&
                           whiteQueenK[s].posX == whiteQueenK[k].posX + 70) {
                            whiteQueenK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteQueenK[k].posY + 70 &&
                       blackQueen.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteQueenK[k].posY + 70 &&
                       blackRook1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteQueenK[k].posY + 70 &&
                       blackRook2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteQueenK[k].posY + 70 &&
                       blackKnight1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteQueenK[k].posY + 70 &&
                       blackKnight2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteQueenK[k].posY + 70 &&
                       blackBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteQueenK[k].posY + 70 &&
                       whiteRook1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteQueenK[k].posY + 70 &&
                       whiteRook2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteQueenK[k].posY + 70 &&
                       whiteKnight1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteQueenK[k].posY + 70 &&
                       whiteKnight2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop1.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteQueenK[k].posY + 70 &&
                       whiteBishop2.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == whiteQueenK[k].posY + 70 &&
                       whiteQueen.posX == whiteQueenK[k].posX + 70) {
                        whiteQueenK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteQueenK[k].posY = whiteQueenK[k].posY + 70;
                        whiteQueenK[k].posX = whiteQueenK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteQueenK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveWhiteBishop1(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(blackKnight1.posX == whiteBishop1.posX &&
       blackKnight1.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteBishop1.posX &&
       blackKnight2.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteBishop1.posX &&
       blackBishop1.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteBishop1.posX &&
       blackBishop2.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteBishop1.posX &&
       blackRook1.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteBishop1.posX &&
       blackRook2.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteBishop1.posX &&
       blackQueen.posY == whiteBishop1.posY) {
        whiteBishop1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteBishop1.posX &&
           blackPawns[g].posY == whiteBishop1.posY) {
            whiteBishop1.failedpath = TRUE;
            return TRUE;
        }
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        whiteBishop1.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveWhiteBishop1(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop1.posY = whiteBishop1.posY - 70;
                    whiteBishop1.posX = whiteBishop1.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop1.posY &&
                           whitePawns[s].posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteBishop1.posY &&
                           whiteBishop2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop1.posY &&
                           whiteKnight1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop1.posY &&
                           whiteKnight2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop1.posY &&
                           whiteRook1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop1.posY &&
                           whiteRook2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop1.posY &&
                           whiteKing.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop1.posY &&
                               blackBishop1.posX == whiteBishop1.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteBishop1.posY &&
                               blackPawns[s].posX == whiteBishop1.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop1.posY &&
                                   blackQueenK[z].posX == whiteBishop1.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop1.posY &&
                               blackQueen.posX == whiteBishop1.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop1.posY &&
                               blackKnight1.posX == whiteBishop1.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop1.posY &&
                               blackKnight2.posX == whiteBishop1.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop1.posY &&
                               blackRook1.posX == whiteBishop1.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop1.posY &&
                               blackRook2.posX == whiteBishop1.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop1.posY - 70 &&
                           blackPawns[s].posX == whiteBishop1.posX - 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop1.posY - 70 &&
                           whitePawns[s].posX == whiteBishop1.posX - 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop1.posY - 70 &&
                       blackQueen.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop1.posY - 70 &&
                       blackBishop2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop1.posY - 70 &&
                       blackBishop1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop1.posY - 70 &&
                       blackRook1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop1.posY - 70 &&
                       blackRook2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop1.posY - 70 &&
                       blackKnight1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop1.posY - 70 &&
                       blackKnight2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteBishop1.posY - 70 &&
                       whiteBishop2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop1.posY - 70 &&
                       whiteRook1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop1.posY - 70 &&
                       whiteRook2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop1.posY - 70 &&
                       whiteKnight1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop1.posY - 70 &&
                       whiteKnight2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop1.posY = whiteBishop1.posY - 70;
                        whiteBishop1.posX = whiteBishop1.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveWhiteBishop1(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop1.posY = whiteBishop1.posY - 70;
                    whiteBishop1.posX = whiteBishop1.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop1.posY &&
                           whitePawns[s].posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteBishop1.posY &&
                           whiteBishop2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop1.posY &&
                           whiteKnight1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop1.posY &&
                           whiteKnight2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop1.posY &&
                           whiteRook1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop1.posY &&
                           whiteRook2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop1.posY &&
                           whiteKing.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop1.posY &&
                               blackBishop1.posX == whiteBishop1.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteBishop1.posY &&
                               blackPawns[s].posX == whiteBishop1.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop1.posY &&
                                   blackQueenK[z].posX == whiteBishop1.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop1.posY &&
                               blackQueen.posX == whiteBishop1.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop1.posY &&
                               blackKnight1.posX == whiteBishop1.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop1.posY &&
                               blackKnight2.posX == whiteBishop1.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop1.posY &&
                               blackRook1.posX == whiteBishop1.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop1.posY &&
                               blackRook2.posX == whiteBishop1.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop1.posY - 70 &&
                           blackPawns[s].posX == whiteBishop1.posX + 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop1.posY - 70 &&
                           whitePawns[s].posX == whiteBishop1.posX + 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop1.posY - 70 &&
                       blackQueen.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop1.posY - 70 &&
                       blackBishop2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop1.posY - 70 &&
                       blackBishop1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop1.posY - 70 &&
                       blackRook1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop1.posY - 70 &&
                       blackRook2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop1.posY - 70 &&
                       blackKnight1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop1.posY - 70 &&
                       blackKnight2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteBishop1.posY - 70 &&
                       whiteBishop2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop1.posY - 70 &&
                       whiteRook1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop1.posY - 70 &&
                       whiteRook2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop1.posY - 70 &&
                       whiteKnight1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop1.posY - 70 &&
                       whiteKnight2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop1.posY = whiteBishop1.posY - 70;
                        whiteBishop1.posX = whiteBishop1.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveWhiteBishop1(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop1.posY = whiteBishop1.posY + 70;
                    whiteBishop1.posX = whiteBishop1.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop1.posY &&
                           whitePawns[s].posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteBishop1.posY &&
                           whiteBishop2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop1.posY &&
                           whiteKnight1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop1.posY &&
                           whiteKnight2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop1.posY &&
                           whiteRook1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop1.posY &&
                           whiteRook2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop1.posY &&
                           whiteKing.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop1.posY &&
                               blackBishop1.posX == whiteBishop1.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteBishop1.posY &&
                               blackPawns[s].posX == whiteBishop1.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop1.posY &&
                                   blackQueenK[z].posX == whiteBishop1.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop1.posY &&
                               blackQueen.posX == whiteBishop1.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop1.posY &&
                               blackKnight1.posX == whiteBishop1.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop1.posY &&
                               blackKnight2.posX == whiteBishop1.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop1.posY &&
                               blackRook1.posX == whiteBishop1.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop1.posY &&
                               blackRook2.posX == whiteBishop1.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop1.posY + 70 &&
                           blackPawns[s].posX == whiteBishop1.posX - 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop1.posY + 70 &&
                           whitePawns[s].posX == whiteBishop1.posX - 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop1.posY + 70 &&
                       blackQueen.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop1.posY + 70 &&
                       blackBishop1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop1.posY + 70 &&
                       blackBishop2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop1.posY + 70 &&
                       blackRook1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop1.posY + 70 &&
                       blackRook2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop1.posY + 70 &&
                       blackKnight1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop1.posY + 70 &&
                       blackKnight2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteBishop1.posY + 70 &&
                       whiteBishop2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop1.posY + 70 &&
                       whiteRook1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop1.posY + 70 &&
                       whiteRook2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop1.posY + 70 &&
                       whiteKnight1.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop1.posY + 70 &&
                       whiteKnight2.posX == whiteBishop1.posX - 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop1.posY = whiteBishop1.posY + 70;
                        whiteBishop1.posX = whiteBishop1.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveWhiteBishop1(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop1.posY = whiteBishop1.posY + 70;
                    whiteBishop1.posX = whiteBishop1.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop1.posY &&
                           whitePawns[s].posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop2.posY == whiteBishop1.posY &&
                           whiteBishop2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop1.posY &&
                           whiteKnight1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop1.posY &&
                           whiteKnight2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop1.posY &&
                           whiteRook1.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop1.posY &&
                           whiteRook2.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop1.posY &&
                           whiteKing.posX == whiteBishop1.posX) {
                            whiteBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop1.posY &&
                               blackBishop1.posX == whiteBishop1.posX) {
                                blackBishop1.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackPawns[s].posY == whiteBishop1.posY &&
                               blackPawns[s].posX == whiteBishop1.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop1.posY &&
                                   blackQueenK[z].posX == whiteBishop1.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop1.posY &&
                               blackQueen.posX == whiteBishop1.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop1.posY &&
                               blackKnight1.posX == whiteBishop1.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop1.posY &&
                               blackKnight2.posX == whiteBishop1.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop1.posY &&
                               blackBishop2.posX == whiteBishop1.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop1.posY &&
                               blackRook1.posX == whiteBishop1.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop1.posY &&
                               blackRook2.posX == whiteBishop1.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop1.posY + 70 &&
                           blackPawns[s].posX == whiteBishop1.posX + 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop1.posY + 70 &&
                           whitePawns[s].posX == whiteBishop1.posX + 70) {
                            whiteBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop1.posY + 70 &&
                       blackQueen.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop1.posY + 70 &&
                       blackBishop1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop1.posY + 70 &&
                       blackBishop2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop1.posY + 70 &&
                       blackRook1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop1.posY + 70 &&
                       blackRook2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop1.posY + 70 &&
                       blackKnight1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop1.posY + 70 &&
                       blackKnight2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == whiteBishop1.posY + 70 &&
                       whiteBishop2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop1.posY + 70 &&
                       whiteRook1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop1.posY + 70 &&
                       whiteRook2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop1.posY + 70 &&
                       whiteKnight1.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop1.posY + 70 &&
                       whiteKnight2.posX == whiteBishop1.posX + 70) {
                        whiteBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop1.posY = whiteBishop1.posY + 70;
                        whiteBishop1.posX = whiteBishop1.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveWhiteBishop2(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(blackKnight1.posX == whiteBishop2.posX &&
       blackKnight1.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteBishop2.posX &&
       blackKnight2.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteBishop2.posX &&
       blackBishop1.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteBishop2.posX &&
       blackBishop2.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteBishop2.posX &&
       blackRook1.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteBishop2.posX &&
       blackRook2.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteBishop2.posX &&
       blackQueen.posY == whiteBishop2.posY) {
        whiteBishop2.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteBishop2.posX &&
           blackPawns[g].posY == whiteBishop2.posY) {
            whiteBishop2.failedpath = TRUE;
            return TRUE;
        }
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        whiteBishop2.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveWhiteBishop2(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop2.posY = whiteBishop2.posY - 70;
                    whiteBishop2.posX = whiteBishop2.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop2.posY &&
                           whitePawns[s].posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteBishop2.posY &&
                           whiteBishop1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop2.posY &&
                           whiteKnight1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop2.posY &&
                           whiteKnight2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop2.posY &&
                           whiteRook1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop2.posY &&
                           whiteRook2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop2.posY &&
                           whiteKing.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop2.posY &&
                               blackBishop1.posX == whiteBishop2.posX) {
                                blackBishop1.posX = 1300;
                            }

                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }

                            if(blackPawns[s].posY == whiteBishop2.posY &&
                               blackPawns[s].posX == whiteBishop2.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop2.posY &&
                                   blackQueenK[z].posX == whiteBishop2.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop2.posY &&
                               blackQueen.posX == whiteBishop2.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop2.posY &&
                               blackKnight1.posX == whiteBishop2.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop2.posY &&
                               blackKnight2.posX == whiteBishop2.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop2.posY &&
                               blackRook1.posX == whiteBishop2.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop2.posY &&
                               blackRook2.posX == whiteBishop2.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop2.posY - 70 &&
                           blackPawns[s].posX == whiteBishop2.posX - 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop2.posY - 70 &&
                           whitePawns[s].posX == whiteBishop2.posX - 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop2.posY - 70 &&
                       blackQueen.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop2.posY - 70 &&
                       blackBishop2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop2.posY - 70 &&
                       blackBishop1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop2.posY - 70 &&
                       blackRook1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop2.posY - 70 &&
                       blackRook2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop2.posY - 70 &&
                       blackKnight1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop2.posY - 70 &&
                       blackKnight2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteBishop2.posY - 70 &&
                       whiteBishop1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop2.posY - 70 &&
                       whiteRook1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop2.posY - 70 &&
                       whiteRook2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop2.posY - 70 &&
                       whiteKnight1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop2.posY - 70 &&
                       whiteKnight2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop2.posY = whiteBishop2.posY - 70;
                        whiteBishop2.posX = whiteBishop2.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveWhiteBishop2(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop2.posY = whiteBishop2.posY - 70;
                    whiteBishop2.posX = whiteBishop2.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop2.posY &&
                           whitePawns[s].posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteBishop2.posY &&
                           whiteBishop1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop2.posY &&
                           whiteKnight1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop2.posY &&
                           whiteKnight2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop2.posY &&
                           whiteRook1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop2.posY &&
                           whiteRook2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop2.posY &&
                           whiteKing.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop2.posY &&
                               blackBishop1.posX == whiteBishop2.posX) {
                                blackBishop1.posX = 1300;
                            }

                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }

                            if(blackPawns[s].posY == whiteBishop2.posY &&
                               blackPawns[s].posX == whiteBishop2.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop2.posY &&
                                   blackQueenK[z].posX == whiteBishop2.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop2.posY &&
                               blackQueen.posX == whiteBishop2.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop2.posY &&
                               blackKnight1.posX == whiteBishop2.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop2.posY &&
                               blackKnight2.posX == whiteBishop2.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop2.posY &&
                               blackRook1.posX == whiteBishop2.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop2.posY &&
                               blackRook2.posX == whiteBishop2.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop2.posY - 70 &&
                           blackPawns[s].posX == whiteBishop2.posX + 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop2.posY - 70 &&
                           whitePawns[s].posX == whiteBishop2.posX + 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop2.posY - 70 &&
                       blackQueen.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop2.posY - 70 &&
                       blackBishop2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop2.posY - 70 &&
                       blackBishop1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop2.posY - 70 &&
                       blackRook1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop2.posY - 70 &&
                       blackRook2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop2.posY - 70 &&
                       blackKnight1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop2.posY - 70 &&
                       blackKnight2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteBishop2.posY - 70 &&
                       whiteBishop1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop2.posY - 70 &&
                       whiteRook1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop2.posY - 70 &&
                       whiteRook2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop2.posY - 70 &&
                       whiteKnight1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop2.posY - 70 &&
                       whiteKnight2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop2.posY = whiteBishop2.posY - 70;
                        whiteBishop2.posX = whiteBishop2.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveWhiteBishop2(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop2.posY = whiteBishop2.posY + 70;
                    whiteBishop2.posX = whiteBishop2.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop2.posY &&
                           whitePawns[s].posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteBishop2.posY &&
                           whiteBishop1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop2.posY &&
                           whiteKnight1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop2.posY &&
                           whiteKnight2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop2.posY &&
                           whiteRook1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop2.posY &&
                           whiteRook2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop2.posY &&
                           whiteKing.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop2.posY &&
                               blackBishop1.posX == whiteBishop2.posX) {
                                blackBishop1.posX = 1300;
                            }

                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }

                            if(blackPawns[s].posY == whiteBishop2.posY &&
                               blackPawns[s].posX == whiteBishop2.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop2.posY &&
                                   blackQueenK[z].posX == whiteBishop2.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop2.posY &&
                               blackQueen.posX == whiteBishop2.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop2.posY &&
                               blackKnight1.posX == whiteBishop2.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop2.posY &&
                               blackKnight2.posX == whiteBishop2.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop2.posY &&
                               blackRook1.posX == whiteBishop2.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop2.posY &&
                               blackRook2.posX == whiteBishop2.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop2.posY + 70 &&
                           blackPawns[s].posX == whiteBishop2.posX - 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop2.posY + 70 &&
                           whitePawns[s].posX == whiteBishop2.posX - 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop2.posY + 70 &&
                       blackQueen.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop2.posY + 70 &&
                       blackBishop1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop2.posY + 70 &&
                       blackBishop2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop2.posY + 70 &&
                       blackRook1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop2.posY + 70 &&
                       blackRook2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop2.posY + 70 &&
                       blackKnight1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop2.posY + 70 &&
                       blackKnight2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteBishop2.posY + 70 &&
                       whiteBishop1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop2.posY + 70 &&
                       whiteRook1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop2.posY + 70 &&
                       whiteRook2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop2.posY + 70 &&
                       whiteKnight1.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop2.posY + 70 &&
                       whiteKnight2.posX == whiteBishop2.posX - 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop2.posY = whiteBishop2.posY + 70;
                        whiteBishop2.posX = whiteBishop2.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveWhiteBishop2(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    whiteBishop2.posY = whiteBishop2.posY + 70;
                    whiteBishop2.posX = whiteBishop2.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(whitePawns[s].posY == whiteBishop2.posY &&
                           whitePawns[s].posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteBishop1.posY == whiteBishop2.posY &&
                           whiteBishop1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight1.posY == whiteBishop2.posY &&
                           whiteKnight1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKnight2.posY == whiteBishop2.posY &&
                           whiteKnight2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook1.posY == whiteBishop2.posY &&
                           whiteRook1.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteRook2.posY == whiteBishop2.posY &&
                           whiteRook2.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(whiteKing.posY == whiteBishop2.posY &&
                           whiteKing.posX == whiteBishop2.posX) {
                            whiteBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(blackBishop1.posY == whiteBishop2.posY &&
                               blackBishop1.posX == whiteBishop2.posX) {
                                blackBishop1.posX = 1300;
                            }

                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }

                            if(blackPawns[s].posY == whiteBishop2.posY &&
                               blackPawns[s].posX == whiteBishop2.posX) {
                                blackPawns[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(blackQueenK[z].posY == whiteBishop2.posY &&
                                   blackQueenK[z].posX == whiteBishop2.posX) {
                                    blackQueenK[z].posX = 1300;
                                }
                            }
                            if(blackQueen.posY == whiteBishop2.posY &&
                               blackQueen.posX == whiteBishop2.posX) {
                                blackQueen.posX = 1300;
                            }
                            if(blackKnight1.posY == whiteBishop2.posY &&
                               blackKnight1.posX == whiteBishop2.posX) {
                                blackKnight1.posX = 1300;
                            }
                            if(blackKnight2.posY == whiteBishop2.posY &&
                               blackKnight2.posX == whiteBishop2.posX) {
                                blackKnight2.posX = 1300;
                            }
                            if(blackBishop2.posY == whiteBishop2.posY &&
                               blackBishop2.posX == whiteBishop2.posX) {
                                blackBishop2.posX = 1300;
                            }
                            if(blackRook1.posY == whiteBishop2.posY &&
                               blackRook1.posX == whiteBishop2.posX) {
                                blackRook1.posX = 1300;
                            }
                            if(blackRook2.posY == whiteBishop2.posY &&
                               blackRook2.posX == whiteBishop2.posX) {
                                blackRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == whiteBishop2.posY + 70 &&
                           blackPawns[s].posX == whiteBishop2.posX + 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == whiteBishop2.posY + 70 &&
                           whitePawns[s].posX == whiteBishop2.posX + 70) {
                            whiteBishop2.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackQueen.posY == whiteBishop2.posY + 70 &&
                       blackQueen.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == whiteBishop2.posY + 70 &&
                       blackBishop1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == whiteBishop2.posY + 70 &&
                       blackBishop2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == whiteBishop2.posY + 70 &&
                       blackRook1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == whiteBishop2.posY + 70 &&
                       blackRook2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == whiteBishop2.posY + 70 &&
                       blackKnight1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == whiteBishop2.posY + 70 &&
                       blackKnight2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == whiteBishop2.posY + 70 &&
                       whiteBishop1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == whiteBishop2.posY + 70 &&
                       whiteRook1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == whiteBishop2.posY + 70 &&
                       whiteRook2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == whiteBishop2.posY + 70 &&
                       whiteKnight1.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == whiteBishop2.posY + 70 &&
                       whiteKnight2.posX == whiteBishop2.posX + 70) {
                        whiteBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        whiteBishop2.posY = whiteBishop2.posY + 70;
                        whiteBishop2.posX = whiteBishop2.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                whiteBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveBlackBishop1(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(whiteKnight1.posX == blackBishop1.posX &&
       whiteKnight1.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackBishop1.posX &&
       whiteKnight2.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackBishop1.posX &&
       whiteBishop1.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackBishop1.posX &&
       whiteBishop2.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackBishop1.posX &&
       whiteRook1.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackBishop1.posX &&
       whiteRook2.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackBishop1.posX &&
       whiteQueen.posY == blackBishop1.posY) {
        blackBishop1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackBishop1.posX &&
           whitePawns[g].posY == blackBishop1.posY) {
            blackBishop1.failedpath = TRUE;
            return TRUE;
        }
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        blackBishop1.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveBlackBishop1(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop1.posY = blackBishop1.posY - 70;
                    blackBishop1.posX = blackBishop1.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY &&
                           blackPawns[s].posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }

                        if(blackBishop2.posY == blackBishop1.posY &&
                           blackBishop2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop1.posY &&
                           blackKnight1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop1.posY &&
                           blackKnight2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop1.posY &&
                           blackRook1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop1.posY &&
                           blackRook2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop1.posY &&
                           blackKing.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }

                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop1.posY &&
                               whiteBishop1.posX == blackBishop1.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop1.posY &&
                               whiteBishop2.posX == blackBishop1.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop1.posY &&
                               whitePawns[s].posX == blackBishop1.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop1.posY &&
                               whiteKnight1.posX == blackBishop1.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop1.posY &&
                               whiteKnight2.posX == blackBishop1.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop1.posY &&
                               whiteRook1.posX == blackBishop1.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == whiteBishop2.posY &&
                               whiteRook2.posX == whiteBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY - 70 &&
                           blackPawns[s].posX == blackBishop1.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop1.posY - 70 &&
                           whitePawns[s].posX == blackBishop1.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop2.posY == blackBishop1.posY - 70 &&
                       blackBishop2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop1.posY - 70 &&
                       blackRook1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop1.posY - 70 &&
                       blackRook2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop1.posY - 70 &&
                       blackKnight1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop1.posY - 70 &&
                       blackKnight2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop1.posY - 70 &&
                       whiteBishop1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackBishop1.posY - 70 &&
                       blackBishop2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop1.posY - 70 &&
                       whiteRook1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop1.posY - 70 &&
                       whiteRook2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop1.posY - 70 &&
                       whiteKnight1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop1.posY - 70 &&
                       whiteKnight2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop1.posY - 70 &&
                       whiteQueen.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop1.posY - 70 &&
                       whiteBishop1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop1.posY - 70 &&
                       whiteBishop2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop1.posY = blackBishop1.posY - 70;
                        blackBishop1.posX = blackBishop1.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveBlackBishop1(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop1.posY = blackBishop1.posY - 70;
                    blackBishop1.posX = blackBishop1.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY &&
                           blackPawns[s].posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackBishop1.posY &&
                           blackBishop2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop1.posY &&
                           blackKnight1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop1.posY &&
                           blackKnight2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop1.posY &&
                           blackRook1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop1.posY &&
                           blackRook2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop1.posY &&
                           blackKing.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }

                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop1.posY &&
                               whiteBishop1.posX == blackBishop1.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop1.posY &&
                               whiteBishop2.posX == blackBishop1.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop1.posY &&
                               whitePawns[s].posX == blackBishop1.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop1.posY &&
                               whiteKnight1.posX == blackBishop1.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop1.posY &&
                               whiteKnight2.posX == blackBishop1.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop1.posY &&
                               whiteRook1.posX == blackBishop1.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == whiteBishop2.posY &&
                               whiteRook2.posX == whiteBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY - 70 &&
                           blackPawns[s].posX == blackBishop1.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop1.posY - 70 &&
                           whitePawns[s].posX == blackBishop1.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop2.posY == blackBishop1.posY - 70 &&
                       blackBishop2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop1.posY - 70 &&
                       blackRook1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop1.posY - 70 &&
                       blackRook2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop1.posY - 70 &&
                       blackKnight1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop1.posY - 70 &&
                       blackKnight2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop1.posY - 70 &&
                       blackBishop1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop1.posY - 70 &&
                       whiteRook1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop1.posY - 70 &&
                       whiteRook2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop1.posY - 70 &&
                       whiteKnight1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop1.posY - 70 &&
                       whiteKnight2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop1.posY - 70 &&
                       whiteQueen.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop1.posY - 70 &&
                       whiteBishop1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop1.posY - 70 &&
                       whiteBishop2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop1.posY = blackBishop1.posY - 70;
                        blackBishop1.posX = blackBishop1.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveBlackBishop1(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop1.posY = blackBishop1.posY + 70;
                    blackBishop1.posX = blackBishop1.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY &&
                           blackPawns[s].posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackBishop1.posY &&
                           blackBishop2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop1.posY &&
                           blackKnight1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop1.posY &&
                           blackKnight2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop1.posY &&
                           blackRook1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop1.posY &&
                           blackRook2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop1.posY &&
                           blackKing.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }

                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop1.posY &&
                               whiteBishop1.posX == blackBishop1.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop1.posY &&
                               whiteBishop2.posX == blackBishop1.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop1.posY &&
                               whitePawns[s].posX == blackBishop1.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop1.posY &&
                               whiteKnight1.posX == blackBishop1.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop1.posY &&
                               whiteKnight2.posX == blackBishop1.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop1.posY &&
                               whiteRook1.posX == blackBishop1.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == whiteBishop2.posY &&
                               whiteRook2.posX == whiteBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY + 70 &&
                           blackPawns[s].posX == blackBishop1.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop1.posY + 70 &&
                           whitePawns[s].posX == blackBishop1.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackBishop1.posY + 70 &&
                       blackBishop1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackBishop1.posY + 70 &&
                       blackBishop2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop1.posY + 70 &&
                       blackRook1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop1.posY + 70 &&
                       blackRook2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop1.posY + 70 &&
                       blackKnight1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop1.posY + 70 &&
                       blackKnight2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop1.posY + 70 &&
                       blackBishop1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop1.posY + 70 &&
                       whiteRook1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop1.posY + 70 &&
                       whiteRook2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop1.posY + 70 &&
                       whiteKnight1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop1.posY + 70 &&
                       whiteKnight2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop1.posY + 70 &&
                       whiteQueen.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop1.posY + 70 &&
                       whiteBishop1.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop1.posY + 70 &&
                       whiteBishop2.posX == blackBishop1.posX - 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop1.posY = blackBishop1.posY + 70;
                        blackBishop1.posX = blackBishop1.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveBlackBishop1(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop1.posY = blackBishop1.posY + 70;
                    blackBishop1.posX = blackBishop1.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY &&
                           blackPawns[s].posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop2.posY == blackBishop1.posY &&
                           blackBishop2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop1.posY &&
                           blackKnight1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop1.posY &&
                           blackKnight2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop1.posY &&
                           blackRook1.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop1.posY &&
                           blackRook2.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop1.posY &&
                           blackKing.posX == blackBishop1.posX) {
                            blackBishop1.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop1.posY &&
                               whiteBishop1.posX == blackBishop1.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop1.posY &&
                               whiteBishop2.posX == blackBishop1.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop1.posY &&
                               whitePawns[s].posX == blackBishop1.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop1.posY &&
                               whiteKnight1.posX == blackBishop1.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop1.posY &&
                               whiteKnight2.posX == blackBishop1.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop1.posY &&
                               whiteQueen.posX == blackBishop1.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop1.posY &&
                               whiteRook1.posX == blackBishop1.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == whiteBishop2.posY &&
                               whiteRook2.posX == whiteBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop1.posY + 70 &&
                           blackPawns[s].posX == blackBishop1.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop1.posY + 70 &&
                           whitePawns[s].posX == blackBishop1.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackBishop1.posY + 70 &&
                       blackBishop1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop2.posY == blackBishop1.posY + 70 &&
                       blackBishop2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop1.posY + 70 &&
                       blackRook1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop1.posY + 70 &&
                       blackRook2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop1.posY + 70 &&
                       blackKnight1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop1.posY + 70 &&
                       blackKnight2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop1.posY + 70 &&
                       blackBishop1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop1.posY + 70 &&
                       whiteRook1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop1.posY + 70 &&
                       whiteRook2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop1.posY + 70 &&
                       whiteKnight1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop1.posY + 70 &&
                       whiteKnight2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop1.posY + 70 &&
                       whiteQueen.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop1.posY + 70 &&
                       whiteBishop1.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop1.posY + 70 &&
                       whiteBishop2.posX == blackBishop1.posX + 70) {
                        blackBishop1.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop1.posY = blackBishop1.posY + 70;
                        blackBishop1.posX = blackBishop1.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop1.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveBlackBishop2(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(whiteKnight1.posX == blackBishop2.posX &&
       whiteKnight1.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackBishop2.posX &&
       whiteKnight2.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackBishop2.posX &&
       whiteBishop1.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackBishop2.posX &&
       whiteBishop2.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackBishop2.posX &&
       whiteRook1.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackBishop2.posX &&
       whiteRook2.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackBishop2.posX &&
       whiteQueen.posY == blackBishop2.posY) {
        blackBishop2.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackBishop2.posX &&
           whitePawns[g].posY == blackBishop2.posY) {
            blackBishop2.failedpath = TRUE;
            return TRUE;
        }
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        blackBishop2.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveBlackBishop2(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop2.posY = blackBishop2.posY - 70;
                    blackBishop2.posX = blackBishop2.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY &&
                           blackPawns[s].posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackBishop2.posY &&
                           blackBishop1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop2.posY &&
                           blackKnight1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop2.posY &&
                           blackKnight2.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop2.posY &&
                           blackRook1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop2.posY &&
                           blackRook2.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop2.posY &&
                           blackKing.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop2.posY &&
                               whiteBishop1.posX == blackBishop2.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop2.posY &&
                               whiteBishop2.posX == blackBishop2.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop2.posY &&
                               whitePawns[s].posX == blackBishop2.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop2.posY &&
                               whiteQueen.posX == blackBishop2.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop2.posY &&
                               whiteKnight1.posX == blackBishop2.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop2.posY &&
                               whiteKnight2.posX == blackBishop2.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop2.posY &&
                               whiteQueen.posX == blackBishop2.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop2.posY &&
                               whiteRook1.posX == blackBishop2.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == whiteBishop2.posY &&
                               whiteRook2.posX == whiteBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY - 70 &&
                           blackPawns[s].posX == blackBishop2.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop2.posY - 70 &&
                           whitePawns[s].posX == blackBishop2.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackBishop2.posY - 70 &&
                       blackBishop1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop2.posY - 70 &&
                       blackRook1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop2.posY - 70 &&
                       blackRook2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop2.posY - 70 &&
                       blackKnight1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop2.posY - 70 &&
                       blackKnight2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop2.posY - 70 &&
                       blackBishop1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop2.posY - 70 &&
                       whiteRook1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop2.posY - 70 &&
                       whiteRook2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop2.posY - 70 &&
                       whiteKnight1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop2.posY - 70 &&
                       whiteKnight2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop2.posY - 70 &&
                       whiteQueen.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop2.posY - 70 &&
                       whiteBishop1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop2.posY - 70 &&
                       whiteBishop2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop2.posY = blackBishop2.posY - 70;
                        blackBishop2.posX = blackBishop2.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveBlackBishop2(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop2.posY = blackBishop2.posY - 70;
                    blackBishop2.posX = blackBishop2.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY &&
                           blackPawns[s].posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackBishop2.posY &&
                           blackBishop1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop2.posY &&
                           blackKnight1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop2.posY &&
                           blackKnight2.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop2.posY &&
                           blackRook1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop2.posY &&
                           blackRook2.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop2.posY &&
                           blackKing.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop2.posY &&
                               whiteBishop1.posX == blackBishop2.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop2.posY &&
                               whiteBishop2.posX == blackBishop2.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop2.posY &&
                               whitePawns[s].posX == blackBishop2.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop2.posY &&
                               whiteQueen.posX == blackBishop2.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop2.posY &&
                               whiteKnight1.posX == blackBishop2.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop2.posY &&
                               whiteKnight2.posX == blackBishop2.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop2.posY &&
                               whiteQueen.posX == blackBishop2.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop2.posY &&
                               whiteRook1.posX == blackBishop2.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == whiteBishop2.posY &&
                               whiteRook2.posX == whiteBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY - 70 &&
                           blackPawns[s].posX == blackBishop2.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop2.posY - 70 &&
                           whitePawns[s].posX == blackBishop2.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackBishop2.posY - 70 &&
                       blackBishop1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop2.posY - 70 &&
                       blackRook1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop2.posY - 70 &&
                       blackRook2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop2.posY - 70 &&
                       blackKnight1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop2.posY - 70 &&
                       blackKnight2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop2.posY - 70 &&
                       blackBishop1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop2.posY - 70 &&
                       whiteRook1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop2.posY - 70 &&
                       whiteRook2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop2.posY - 70 &&
                       whiteKnight1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop2.posY - 70 &&
                       whiteKnight2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop2.posY - 70 &&
                       whiteQueen.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop2.posY - 70 &&
                       whiteBishop1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop2.posY - 70 &&
                       whiteBishop2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop2.posY = blackBishop2.posY - 70;
                        blackBishop2.posX = blackBishop2.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveBlackBishop2(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop2.posY = blackBishop2.posY + 70;
                    blackBishop2.posX = blackBishop2.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY &&
                           blackPawns[s].posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whitePawns[s].posY == blackBishop2.posY &&
                               whitePawns[s].posX == blackBishop2.posX) {
                                whitePawns[s].posX = 1300;
                            }
                        }
                    }

                    if(blackBishop1.posY == blackBishop2.posY &&
                       blackBishop1.posX == blackBishop2.posX) {
                        blackBishop2.failedpath = TRUE;
                        return TRUE;
                    }

                    if(blackKnight1.posY == blackBishop2.posY &&
                       blackKnight1.posX == blackBishop2.posX) {
                        blackBishop2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackBishop2.posY &&
                       blackKnight2.posX == blackBishop2.posX) {
                        blackBishop2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackBishop2.posY &&
                       blackRook1.posX == blackBishop2.posX) {
                        blackBishop2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackBishop2.posY &&
                       blackRook2.posX == blackBishop2.posX) {
                        blackBishop2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackBishop2.posY &&
                       blackKing.posX == blackBishop2.posX) {
                        blackBishop2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(whiteBishop1.posY == blackBishop2.posY &&
                           whiteBishop1.posX == blackBishop2.posX) {
                            whiteBishop1.posX = 1300;
                        }

                        if(whiteBishop2.posY == blackBishop2.posY &&
                           whiteBishop2.posX == blackBishop2.posX) {
                            whiteBishop2.posX = 1300;
                        }

                        if(whiteQueen.posY == blackBishop2.posY &&
                           whiteQueen.posX == blackBishop2.posX) {
                            whiteQueen.posX = 1300;
                        }

                        if(whiteKnight1.posY == blackBishop2.posY &&
                           whiteKnight1.posX == blackBishop2.posX) {
                            whiteKnight1.posX = 1300;
                        }

                        if(whiteKnight2.posY == blackBishop2.posY &&
                           whiteKnight2.posX == blackBishop2.posX) {
                            whiteKnight2.posX = 1300;
                        }

                        if(whiteQueen.posY == blackBishop2.posY &&
                           whiteQueen.posX == blackBishop2.posX) {
                            whiteQueen.posX = 1300;
                        }

                        if(whiteRook1.posY == blackBishop2.posY &&
                           whiteRook1.posX == blackBishop2.posX) {
                            whiteRook1.posX = 1300;
                        }

                        if(whiteRook2.posY == whiteBishop2.posY &&
                           whiteRook2.posX == whiteBishop2.posX) {
                            whiteRook2.posX = 1300;
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY + 70 &&
                           blackPawns[s].posX == blackBishop2.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop2.posY + 70 &&
                           whitePawns[s].posX == blackBishop2.posX - 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackBishop2.posY + 70 &&
                       blackBishop1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop2.posY + 70 &&
                       blackRook1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop2.posY + 70 &&
                       blackRook2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop2.posY + 70 &&
                       blackKnight1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop2.posY + 70 &&
                       blackKnight2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop2.posY + 70 &&
                       blackBishop1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop2.posY + 70 &&
                       whiteRook1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop2.posY + 70 &&
                       whiteRook2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop2.posY + 70 &&
                       whiteKnight1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop2.posY + 70 &&
                       whiteKnight2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop2.posY + 70 &&
                       whiteQueen.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop2.posY + 70 &&
                       whiteBishop1.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop2.posY + 70 &&
                       whiteBishop2.posX == blackBishop2.posX - 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop2.posY = blackBishop2.posY + 70;
                        blackBishop2.posX = blackBishop2.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop2.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveBlackBishop2(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    blackBishop2.posY = blackBishop2.posY + 70;
                    blackBishop2.posX = blackBishop2.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY &&
                           blackPawns[s].posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackBishop1.posY == blackBishop2.posY &&
                           blackBishop1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight1.posY == blackBishop2.posY &&
                           blackKnight1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKnight2.posY == blackBishop2.posY &&
                           blackKnight2.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook1.posY == blackBishop2.posY &&
                           blackRook1.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackRook2.posY == blackBishop2.posY &&
                           blackRook2.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(blackKing.posY == blackBishop2.posY &&
                           blackKing.posX == blackBishop2.posX) {
                            blackBishop2.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(whiteBishop1.posY == blackBishop2.posY &&
                               whiteBishop1.posX == blackBishop2.posX) {
                                whiteBishop1.posX = 1300;
                            }

                            if(whiteBishop2.posY == blackBishop2.posY &&
                               whiteBishop2.posX == blackBishop2.posX) {
                                whiteBishop2.posX = 1300;
                            }

                            if(whitePawns[s].posY == blackBishop2.posY &&
                               whitePawns[s].posX == blackBishop2.posX) {
                                whitePawns[s].posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop2.posY &&
                               whiteQueen.posX == blackBishop2.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteKnight1.posY == blackBishop2.posY &&
                               whiteKnight1.posX == blackBishop2.posX) {
                                whiteKnight1.posX = 1300;
                            }

                            if(whiteKnight2.posY == blackBishop2.posY &&
                               whiteKnight2.posX == blackBishop2.posX) {
                                whiteKnight2.posX = 1300;
                            }

                            if(whiteQueen.posY == blackBishop2.posY &&
                               whiteQueen.posX == blackBishop2.posX) {
                                whiteQueen.posX = 1300;
                            }

                            if(whiteRook1.posY == blackBishop2.posY &&
                               whiteRook1.posX == blackBishop2.posX) {
                                whiteRook1.posX = 1300;
                            }

                            if(whiteRook2.posY == blackBishop2.posY &&
                               whiteRook2.posX == blackBishop2.posX) {
                                whiteRook2.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(blackPawns[s].posY == blackBishop2.posY + 70 &&
                           blackPawns[s].posX == blackBishop2.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(whitePawns[s].posY == blackBishop2.posY + 70 &&
                           whitePawns[s].posX == blackBishop2.posX + 70) {
                            blackBishop1.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(blackBishop1.posY == blackBishop2.posY + 70 &&
                       blackBishop1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook1.posY == blackBishop2.posY + 70 &&
                       blackRook1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackRook2.posY == blackBishop2.posY + 70 &&
                       blackRook2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight1.posY == blackBishop2.posY + 70 &&
                       blackKnight1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackKnight2.posY == blackBishop2.posY + 70 &&
                       blackKnight2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackBishop1.posY == blackBishop2.posY + 70 &&
                       blackBishop1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook1.posY == blackBishop2.posY + 70 &&
                       whiteRook1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteRook2.posY == blackBishop2.posY + 70 &&
                       whiteRook2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight1.posY == blackBishop2.posY + 70 &&
                       whiteKnight1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteKnight2.posY == blackBishop2.posY + 70 &&
                       whiteKnight2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackBishop2.posY + 70 &&
                       whiteQueen.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop1.posY == blackBishop2.posY + 70 &&
                       whiteBishop1.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteBishop2.posY == blackBishop2.posY + 70 &&
                       whiteBishop2.posX == blackBishop2.posX + 70) {
                        blackBishop2.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        blackBishop2.posY = blackBishop2.posY + 70;
                        blackBishop2.posX = blackBishop2.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                blackBishop2.failedpath = TRUE;                
                return TRUE;
            }
        }
    }
}

boolean moveWhiteRook1(UINT msg, int j, int i, int pos, int o) {

    if(blackKing.posX == whiteRook1.posX &&
       blackKing.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackKing.posX == whiteRook2.posX &&
       blackKing.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight1.posX == whiteRook1.posX &&
       blackKnight1.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }                                                                                  
    if(blackKnight2.posX == whiteRook1.posX &&
       blackKnight2.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteRook1.posX &&
       blackBishop1.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteRook1.posX &&
       blackBishop2.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteRook1.posX &&
       blackRook1.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteRook1.posX &&
       blackRook2.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteRook1.posX &&
       blackQueen.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteRook1.posX &&
           blackPawns[g].posY == whiteRook1.posY) {
            whiteRook1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteRook1(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook1.posY = whiteRook1.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY &&
                       whitePawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook1.posY &&
                       whiteBishop1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook1.posY &&
                       whiteBishop2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook1.posY &&
                       whiteKnight1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook1.posY &&
                       whiteKnight2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteRook1.posY &&
                       whiteRook2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook1.posY &&
                       whiteKing.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY &&
                       blackPawns[s].posX == whiteRook1.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook1.posY &&
                       blackRook1.posX == whiteRook1.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook1.posY &&
                       blackRook2.posX == whiteRook1.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook1.posY &&
                           blackQueenK[z].posX == whiteRook1.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook1.posY &&
                       blackQueen.posX == whiteRook1.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook1.posY &&
                       blackBishop1.posX == whiteRook1.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook1.posY &&
                       blackBishop2.posX == whiteRook1.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook1.posY &&
                       blackKnight1.posX == whiteRook1.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook1.posY &&
                       blackKnight2.posX == whiteRook1.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY - 70 &&
                       whitePawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY - 70 &&
                       blackPawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook1.posY - 70 &&
                       blackQueen.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook1.posY - 70 &&
                   blackBishop1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook1.posY - 70 &&
                   blackBishop2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteRook1.posY - 70 &&
                   blackRook1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook1.posY - 70 &&
                   blackRook2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook1.posY - 70 &&
                   blackKnight1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook1.posY - 70 &&
                   blackKnight2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook1.posY - 70 &&
                   whiteRook2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook1.posY - 70 &&
                   whiteKnight1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook1.posY - 70 &&
                   whiteKnight2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook1.posY = whiteRook1.posY - 70;
                }

                return flag;
            }
        }

        else {

            whiteRook1.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteRook1(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook1.posY = whiteRook1.posY + 70;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY &&
                       whitePawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook1.posY &&
                       whiteBishop1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook1.posY &&
                       whiteBishop2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook1.posY &&
                       whiteKnight1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook1.posY &&
                       whiteKnight2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteRook1.posY &&
                       whiteRook2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook1.posY &&
                       whiteKing.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY &&
                       blackPawns[s].posX == whiteRook1.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook1.posY &&
                       blackRook1.posX == whiteRook1.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook1.posY &&
                       blackRook2.posX == whiteRook1.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook1.posY &&
                           blackQueenK[z].posX == whiteRook1.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook1.posY &&
                       blackQueen.posX == whiteRook1.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook1.posY &&
                       blackBishop1.posX == whiteRook1.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook1.posY &&
                       blackBishop2.posX == whiteRook1.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook1.posY &&
                       blackKnight1.posX == whiteRook1.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook1.posY &&
                       blackKnight2.posX == whiteRook1.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY + 70 &&
                       whitePawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY + 70 &&
                       blackPawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook1.posY + 70 &&
                       blackQueen.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook1.posY + 70 &&
                   blackBishop1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook1.posY + 70 &&
                   blackBishop2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteRook1.posY + 70 &&
                   blackRook1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook1.posY + 70 &&
                   blackRook2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook1.posY + 70 &&
                   blackKnight1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook1.posY + 70 &&
                   blackKnight2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteRook1.posY + 70 &&
                   blackBishop1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook1.posY + 70 &&
                   whiteRook2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook1.posY + 70 &&
                   whiteKnight1.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook1.posY + 70 &&
                   whiteKnight2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook1.posY = whiteRook1.posY + 70;
                }

                return flag;
            }
        }

        else {

            whiteRook1.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveWhiteRook1Side(UINT msg, int j, int i, int pos, int o) {

    if(blackKing.posX == whiteRook1.posX &&
       blackKing.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackKing.posX == whiteRook2.posX &&
       blackKing.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight1.posX == whiteRook1.posX &&
       blackKnight1.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteRook1.posX &&
       blackKnight2.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteRook1.posX &&
       blackBishop1.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteRook1.posX &&
       blackBishop2.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteRook1.posX &&
       blackRook1.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteRook1.posX &&
       blackRook2.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteRook1.posX &&
       blackQueen.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteRook1.posX &&
           blackPawns[g].posY == whiteRook1.posY) {
            whiteRook1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteRook1Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook1.posX = whiteRook1.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY &&
                       whitePawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook1.posY &&
                       whiteBishop1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook1.posY &&
                       whiteBishop2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook1.posY &&
                       whiteKnight1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook1.posY &&
                       whiteKnight2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteRook1.posY &&
                       whiteRook2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook1.posY &&
                       whiteKing.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY &&
                       blackPawns[s].posX == whiteRook1.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook1.posY &&
                       blackRook1.posX == whiteRook1.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook1.posY &&
                       blackRook2.posX == whiteRook1.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook1.posY &&
                           blackQueenK[z].posX == whiteRook1.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook1.posY &&
                       blackQueen.posX == whiteRook1.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook1.posY &&
                       blackBishop1.posX == whiteRook1.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook1.posY &&
                       blackBishop2.posX == whiteRook1.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook1.posY &&
                       blackKnight1.posX == whiteRook1.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook1.posY &&
                       blackKnight2.posX == whiteRook1.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY &&
                       whitePawns[s].posX == whiteRook1.posX - 70) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY &&
                       blackPawns[s].posX == whiteRook1.posX - 70) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook1.posY &&
                       blackQueen.posX == whiteRook1.posX - 70) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook1.posY &&
                   blackBishop1.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook1.posY &&
                   blackBishop2.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook1.posY - 70 &&
                   blackBishop2.posX == whiteRook1.posX) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteRook1.posY &&
                   blackRook1.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook1.posY &&
                   blackRook2.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook1.posY &&
                   blackKnight1.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook1.posY &&
                   blackKnight2.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteRook1.posY &&
                   blackBishop1.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook1.posY &&
                   whiteRook2.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook1.posY &&
                   whiteKnight1.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook1.posY &&
                   whiteKnight2.posX == whiteRook1.posX - 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook1.posX = whiteRook1.posX - 70;
                }

                return flag;
            }
        }

        else {

            whiteRook1.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteRook1Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook1.posX = whiteRook1.posX + 70;
                
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY &&
                       whitePawns[s].posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook1.posY &&
                       whiteBishop1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook1.posY &&
                       whiteBishop2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook1.posY &&
                       whiteKnight1.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook1.posY &&
                       whiteKnight2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook2.posY == whiteRook1.posY &&
                       whiteRook2.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook1.posY &&
                       whiteKing.posX == whiteRook1.posX) {
                        whiteRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY &&
                       blackPawns[s].posX == whiteRook1.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook1.posY &&
                       blackRook1.posX == whiteRook1.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook1.posY &&
                       blackRook2.posX == whiteRook1.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook1.posY &&
                           blackQueenK[z].posX == whiteRook1.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook1.posY &&
                       blackQueen.posX == whiteRook1.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook1.posY &&
                       blackBishop1.posX == whiteRook1.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook1.posY &&
                       blackBishop2.posX == whiteRook1.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook1.posY &&
                       blackKnight1.posX == whiteRook1.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook1.posY &&
                       blackKnight2.posX == whiteRook1.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook1.posY &&
                       whitePawns[s].posX == whiteRook1.posX + 70) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook1.posY &&
                       blackPawns[s].posX == whiteRook1.posX + 70) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook1.posY &&
                       blackQueen.posX == whiteRook1.posX + 70) {
                        whiteRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook1.posY &&
                   blackBishop1.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook1.posY &&
                   blackBishop2.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == whiteRook1.posY &&
                   blackRook1.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook1.posY &&
                   blackRook2.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook1.posY &&
                   blackKnight1.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook1.posY &&
                   blackKnight2.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == whiteRook1.posY &&
                   blackBishop1.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook1.posY &&
                   whiteRook2.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook1.posY &&
                   whiteKnight1.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook1.posY &&
                   whiteKnight2.posX == whiteRook1.posX + 70) {
                    whiteRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook1.posX = whiteRook1.posX + 70;
                }

                return flag;
            }
        }

        else {

            whiteRook1.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveBlackRook1(UINT msg, int j, int i, int pos, int o) {

    if(whiteKing.posX == blackRook1.posX &&
       whiteKing.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKing.posX == blackRook2.posX &&
       whiteKing.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackRook1.posX &&
       whiteKnight1.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackRook1.posX &&
       whiteKnight2.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackRook1.posX &&
       whiteBishop1.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackRook1.posX &&
       whiteBishop2.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackRook1.posX &&
       whiteRook1.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackRook1.posX &&
       whiteRook2.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackRook1.posX &&
       whiteQueen.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackRook1.posX &&
           whitePawns[g].posY == blackRook1.posY) {
            blackRook1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackRook1(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook1.posY = blackRook1.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY &&
                       blackPawns[s].posX == blackRook1.posX) {
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook1.posY &&
                       blackBishop1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook1.posY &&
                       blackBishop2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook1.posY &&
                       blackKnight1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook1.posY &&
                       blackKnight2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackRook1.posY &&
                       blackRook2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook1.posY &&
                       blackKing.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY &&
                       whitePawns[s].posX == blackRook1.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook1.posY &&
                       whiteRook1.posX == blackRook1.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook1.posY &&
                       whiteRook2.posX == blackRook1.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook1.posY &&
                           whiteQueenK[z].posX == blackRook1.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook1.posY &&
                       whiteQueen.posX == blackRook1.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook1.posY &&
                       whiteBishop1.posX == blackRook1.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook1.posY &&
                       whiteBishop2.posX == blackRook1.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook1.posY &&
                       whiteKnight1.posX == blackRook1.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook1.posY &&
                       whiteKnight2.posX == blackRook1.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY - 70 &&
                       blackPawns[s].posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackRook1.posY - 70 &&
                       whiteQueen.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY - 70 &&
                       whitePawns[s].posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook1.posY - 70 &&
                   blackBishop1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook1.posY - 70 &&
                   blackBishop2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackRook1.posY - 70 &&
                   blackRook2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook1.posY - 70 &&
                   blackKnight1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook1.posY - 70 &&
                   blackKnight2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook1.posY - 70 &&
                   blackRook1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackRook1.posY - 70 &&
                   whiteRook2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackRook1.posY &&
                   blackBishop1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook1.posY &&
                   blackBishop2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook1.posY - 70 &&
                   whiteKnight1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook1.posY - 70 &&
                   whiteKnight2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook1.posY = blackRook1.posY - 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackRook1(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook1.posY = blackRook1.posY + 70;
                
                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY &&
                       blackPawns[s].posX == blackRook1.posX) {
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook1.posY &&
                       blackBishop1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook1.posY &&
                       blackBishop2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook1.posY &&
                       blackKnight1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook1.posY &&
                       blackKnight2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackRook1.posY &&
                       blackRook2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook1.posY &&
                       blackKing.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY &&
                       whitePawns[s].posX == blackRook1.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook1.posY &&
                       whiteRook1.posX == blackRook1.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook1.posY &&
                       whiteRook2.posX == blackRook1.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook1.posY &&
                           whiteQueenK[z].posX == blackRook1.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook1.posY &&
                       whiteQueen.posX == blackRook1.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook1.posY &&
                       whiteBishop1.posX == blackRook1.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook1.posY &&
                       whiteBishop2.posX == blackRook1.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook1.posY &&
                       whiteKnight1.posX == blackRook1.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook1.posY &&
                       whiteKnight2.posX == blackRook1.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY + 70 &&
                       blackPawns[s].posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackRook1.posY + 70 &&
                       whiteQueen.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY + 70 &&
                       whitePawns[s].posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook1.posY + 70 &&
                   blackBishop1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook1.posY + 70 &&
                   blackBishop2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackRook1.posY + 70 &&
                   blackRook2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook1.posY + 70 &&
                   blackKnight1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook1.posY + 70 &&
                   blackKnight2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook1.posY + 70 &&
                   blackRook1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackRook1.posY + 70 &&
                   whiteRook2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackRook1.posY + 70 &&
                   blackBishop1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook1.posY + 70 &&
                   blackBishop2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook1.posY + 70 &&
                   whiteKnight1.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook1.posY + 70 &&
                   whiteKnight2.posX == blackRook1.posX) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook1.posY = blackRook1.posY + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}

boolean moveBlackRook1Side(UINT msg, int j, int i, int pos, int o) {

    if(whiteKing.posX == blackRook1.posX &&
       whiteKing.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKing.posX == blackRook2.posX &&
       whiteKing.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackRook1.posX &&
       whiteKnight1.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackRook1.posX &&
       whiteKnight2.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackRook1.posX &&
       whiteBishop1.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackRook1.posX &&
       whiteBishop2.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackRook1.posX &&
       whiteRook1.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackRook1.posX &&
       whiteRook2.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackRook1.posX &&
       whiteQueen.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackRook1.posX &&
           whitePawns[g].posY == blackRook1.posY) {
            blackRook1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackRook1Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook1.posX = blackRook1.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY &&
                       blackPawns[s].posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook1.posY &&
                       blackBishop1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook1.posY &&
                       blackBishop2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook1.posY &&
                       blackKnight1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook1.posY &&
                       blackKnight2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackRook1.posY &&
                       blackRook2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook1.posY &&
                       blackKing.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY &&
                       whitePawns[s].posX == blackRook1.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook1.posY &&
                       whiteRook1.posX == blackRook1.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook1.posY &&
                       whiteRook2.posX == blackRook1.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook1.posY &&
                           whiteQueenK[z].posX == blackRook1.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook1.posY &&
                       whiteQueen.posX == blackRook1.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook1.posY &&
                       whiteBishop1.posX == blackRook1.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook1.posY &&
                       whiteBishop2.posX == blackRook1.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook1.posY &&
                       whiteKnight1.posX == blackRook1.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook1.posY &&
                       whiteKnight2.posX == blackRook1.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY &&
                       blackPawns[s].posX == blackRook1.posX - 70) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == blackRook1.posY &&
                       blackQueen.posX == blackRook1.posX - 70) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY &&
                       whitePawns[s].posX == blackRook1.posX - 70) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook1.posY &&
                   blackBishop1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook1.posY &&
                   blackBishop2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackRook1.posY &&
                   blackRook2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook1.posY &&
                   blackKnight1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook1.posY &&
                   blackKnight2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook1.posY &&
                   blackRook1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackRook1.posY &&
                   whiteRook2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackRook1.posY &&
                   whiteBishop1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackRook1.posY &&
                   whiteBishop2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook1.posY &&
                   whiteKnight1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook1.posY &&
                   whiteKnight2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook1.posX = blackRook1.posX - 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackRook1Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook1.posX = blackRook1.posX + 70;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook1.posY &&
                       blackPawns[s].posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook1.posY &&
                       blackBishop1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook1.posY &&
                       blackBishop2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook1.posY &&
                       blackKnight1.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook1.posY &&
                       blackKnight2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook2.posY == blackRook1.posY &&
                       blackRook2.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook1.posY &&
                       blackKing.posX == blackRook1.posX) {
                        blackRook1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook1.posY &&
                       whitePawns[s].posX == blackRook1.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook1.posY &&
                       whiteRook1.posX == blackRook1.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook1.posY &&
                       whiteRook2.posX == blackRook1.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook1.posY &&
                           whiteQueenK[z].posX == blackRook1.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook1.posY &&
                       whiteQueen.posX == blackRook1.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook1.posY &&
                       whiteBishop1.posX == blackRook1.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook1.posY &&
                       whiteBishop2.posX == blackRook1.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook1.posY &&
                       whiteKnight1.posX == blackRook1.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook1.posY &&
                       whiteKnight2.posX == blackRook1.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    if(blackPawns[i].posY == blackRook1.posY &&
                       blackPawns[i].posX == blackRook1.posX + 70) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == blackRook1.posY &&
                       whitePawns[i].posX == blackRook1.posX + 70) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == blackRook1.posY &&
                       blackQueen.posX == blackRook1.posX + 70) {
                        blackRook1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook1.posY &&
                   blackBishop1.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook1.posY &&
                   blackBishop2.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == blackRook1.posY &&
                   blackRook2.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook1.posY &&
                   blackKnight1.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook1.posY &&
                   blackKnight2.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook1.posY &&
                   blackRook1.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == blackRook1.posY &&
                   whiteRook2.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackRook1.posY &&
                   whiteBishop1.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackRook1.posY &&
                   whiteBishop2.posX == blackRook1.posX - 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook1.posY &&
                   whiteKnight1.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook1.posY &&
                   whiteKnight2.posX == blackRook1.posX + 70) {
                    blackRook1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook1.posX = blackRook1.posX + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}

boolean moveWhiteRook2(UINT msg, int j, int i, int pos, int o) {

    if(blackKing.posX == whiteRook1.posX &&
       blackKing.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackKing.posX == whiteRook2.posX &&
       blackKing.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight1.posX == whiteRook2.posX &&
       blackKnight1.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteRook2.posX &&
       blackKnight2.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteRook2.posX &&
       blackBishop1.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteRook2.posX &&
       blackBishop2.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteRook2.posX &&
       blackRook1.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteRook2.posX &&
       blackRook2.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteRook2.posX &&
       blackQueen.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteRook2.posX &&
           blackPawns[g].posY == whiteRook2.posY) {
            whiteRook2.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteRook2(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook2.posY = whiteRook2.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY &&
                       whitePawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook2.posY &&
                       whiteBishop1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook2.posY &&
                       whiteBishop2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook2.posY &&
                       whiteKnight1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook2.posY &&
                       whiteKnight2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteRook2.posY &&
                       whiteRook1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook2.posY &&
                       whiteKing.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY &&
                       blackPawns[s].posX == whiteRook2.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook2.posY &&
                       blackRook1.posX == whiteRook2.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook2.posY &&
                       blackRook2.posX == whiteRook2.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook1.posY &&
                           blackQueenK[z].posX == whiteRook1.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook2.posY &&
                       blackQueen.posX == whiteRook2.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook2.posY &&
                       blackBishop1.posX == whiteRook2.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook2.posY &&
                       blackBishop2.posX == whiteRook2.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook2.posY &&
                       blackKnight1.posX == whiteRook2.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook2.posY &&
                       blackKnight2.posX == whiteRook2.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY - 70 &&
                       whitePawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY - 70 &&
                       blackPawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook2.posY - 70 &&
                       blackQueen.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook2.posY - 70 &&
                   blackBishop1.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook2.posY - 70 &&
                   blackBishop2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY - 70 &&
                   whiteRook2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook2.posY - 70 &&
                   blackRook2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook2.posY - 70 &&
                   blackKnight1.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook2.posY - 70 &&
                   blackKnight2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY - 70 &&
                   whiteRook2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook2.posY - 70 &&
                   whiteKnight1.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook2.posY - 70 &&
                   whiteKnight2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook2.posY = whiteRook2.posY - 70;
                }

                return flag;
            }
        }

        else {

            whiteRook2.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteRook2(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook2.posY = whiteRook2.posY + 70;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY &&
                       whitePawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook2.posY &&
                       whiteBishop1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook2.posY &&
                       whiteBishop2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook2.posY &&
                       whiteKnight1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook2.posY &&
                       whiteKnight2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteRook2.posY &&
                       whiteRook1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook2.posY &&
                       whiteKing.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY &&
                       blackPawns[s].posX == whiteRook2.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook2.posY &&
                       blackRook1.posX == whiteRook2.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook2.posY &&
                       blackRook2.posX == whiteRook2.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook1.posY &&
                           blackQueenK[z].posX == whiteRook1.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook2.posY &&
                       blackQueen.posX == whiteRook2.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook2.posY &&
                       blackBishop1.posX == whiteRook2.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook2.posY &&
                       blackBishop2.posX == whiteRook2.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook2.posY &&
                       blackKnight1.posX == whiteRook2.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook2.posY &&
                       blackKnight2.posX == whiteRook2.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY + 70 &&
                       whitePawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY + 70 &&
                       blackPawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook2.posY + 70 &&
                       blackQueen.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook2.posY + 70 &&
                   blackBishop1.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook2.posY + 70 &&
                   blackBishop2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY + 70 &&
                   whiteRook2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook2.posY + 70 &&
                   blackRook2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook2.posY + 70 &&
                   blackKnight1.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook2.posY + 70 &&
                   blackKnight2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY + 70 &&
                   whiteRook2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook2.posY + 70 &&
                   whiteKnight1.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook2.posY + 70 &&
                   whiteKnight2.posX == whiteRook2.posX) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook2.posY = whiteRook2.posY + 70;
                }

                return flag;
            }
        }

        else {

            whiteRook2.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveWhiteRook2Side(UINT msg, int j, int i, int pos, int o) {

    if(blackKing.posX == whiteRook1.posX &&
       blackKing.posY == whiteRook1.posY) {
        whiteRook1.failedpath = TRUE;
        return TRUE;
    }
    if(blackKing.posX == whiteRook2.posX &&
       blackKing.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight1.posX == whiteRook2.posX &&
       blackKnight1.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackKnight2.posX == whiteRook2.posX &&
       blackKnight2.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop1.posX == whiteRook2.posX &&
       blackBishop1.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackBishop2.posX == whiteRook2.posX &&
       blackBishop2.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook1.posX == whiteRook2.posX &&
       blackRook1.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackRook2.posX == whiteRook2.posX &&
       blackRook2.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    if(blackQueen.posX == whiteRook2.posX &&
       blackQueen.posY == whiteRook2.posY) {
        whiteRook2.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(blackPawns[g].posX == whiteRook2.posX &&
           blackPawns[g].posY == whiteRook2.posY) {
            whiteRook2.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveWhiteRook2Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook2.posX = whiteRook2.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY &&
                       whitePawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook2.posY &&
                       whiteBishop1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook2.posY &&
                       whiteBishop2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook2.posY &&
                       whiteKnight1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook2.posY &&
                       whiteKnight2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteRook2.posY &&
                       whiteRook1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook2.posY &&
                       whiteKing.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY &&
                       blackPawns[s].posX == whiteRook2.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook2.posY &&
                       blackRook1.posX == whiteRook2.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook2.posY &&
                       blackRook2.posX == whiteRook2.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook2.posY &&
                           blackQueenK[z].posX == whiteRook2.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook2.posY &&
                       blackQueen.posX == whiteRook2.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook2.posY &&
                       blackBishop1.posX == whiteRook2.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook2.posY &&
                       blackBishop2.posX == whiteRook2.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook2.posY &&
                       blackKnight1.posX == whiteRook2.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook2.posY &&
                       blackKnight2.posX == whiteRook2.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY &&
                       whitePawns[s].posX == whiteRook2.posX - 70) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY &&
                       blackPawns[s].posX == whiteRook2.posX - 70) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook2.posY &&
                       blackQueen.posX == whiteRook2.posX - 70) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook2.posY &&
                   blackBishop1.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook2.posY &&
                   blackBishop2.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY &&
                   whiteRook2.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook2.posY &&
                   blackRook2.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook2.posY &&
                   blackKnight1.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook2.posY &&
                   blackKnight2.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY &&
                   whiteRook2.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook2.posY &&
                   whiteKnight1.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook2.posY &&
                   whiteKnight2.posX == whiteRook2.posX - 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook2.posX = whiteRook2.posX - 70;
                }

                return flag;
            }
        }

        else {

            whiteRook2.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveWhiteRook2Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                whiteRook2.posX = whiteRook2.posX + 70;
                
                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY &&
                       whitePawns[s].posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop1.posY == whiteRook2.posY &&
                       whiteBishop1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteBishop2.posY == whiteRook2.posY &&
                       whiteBishop2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight1.posY == whiteRook2.posY &&
                       whiteKnight1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKnight2.posY == whiteRook2.posY &&
                       whiteKnight2.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteRook1.posY == whiteRook2.posY &&
                       whiteRook1.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whiteKing.posY == whiteRook2.posY &&
                       whiteKing.posX == whiteRook2.posX) {
                        whiteRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY &&
                       blackPawns[s].posX == whiteRook2.posX) {
                        blackPawns[s].posX = 1300;
                    }
                    if(blackRook1.posY == whiteRook2.posY &&
                       blackRook1.posX == whiteRook2.posX) {
                        blackRook1.posX = 1300;
                    }
                    if(blackRook2.posY == whiteRook2.posY &&
                       blackRook2.posX == whiteRook2.posX) {
                        blackRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(blackQueenK[z].posY == whiteRook2.posY &&
                           blackQueenK[z].posX == whiteRook2.posX) {
                            blackQueenK[z].posX = 1300;
                        }
                    }
                    if(blackQueen.posY == whiteRook2.posY &&
                       blackQueen.posX == whiteRook2.posX) {
                        blackQueen.posX = 1300;
                    }
                    if(blackBishop1.posY == whiteRook2.posY &&
                       blackBishop1.posX == whiteRook2.posX) {
                        blackBishop1.posX = 1300;
                    }
                    if(blackBishop2.posY == whiteRook2.posY &&
                       blackBishop2.posX == whiteRook2.posX) {
                        blackBishop2.posX = 1300;
                    }
                    if(blackKnight1.posY == whiteRook2.posY &&
                       blackKnight1.posX == whiteRook2.posX) {
                        blackKnight1.posX = 1300;
                    }
                    if(blackKnight2.posY == whiteRook2.posY &&
                       blackKnight2.posX == whiteRook2.posX) {
                        blackKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(whitePawns[s].posY == whiteRook2.posY &&
                       whitePawns[s].posX == whiteRook2.posX + 70) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackPawns[s].posY == whiteRook2.posY &&
                       blackPawns[s].posX == whiteRook2.posX + 70) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == whiteRook2.posY &&
                       blackQueen.posX == whiteRook2.posX + 70) {
                        whiteRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == whiteRook2.posY &&
                   blackBishop1.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == whiteRook2.posY &&
                   blackBishop2.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY &&
                   whiteRook2.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook2.posY == whiteRook2.posY &&
                   blackRook2.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == whiteRook2.posY &&
                   blackKnight1.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == whiteRook2.posY &&
                   blackKnight2.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook2.posY == whiteRook2.posY &&
                   whiteRook2.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == whiteRook2.posY &&
                   whiteKnight1.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == whiteRook2.posY &&
                   whiteKnight2.posX == whiteRook2.posX + 70) {
                    whiteRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    whiteRook2.posX = whiteRook2.posX + 70;
                }

                return flag;
            }
        }

        else {

            whiteRook2.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveBlackRook2(UINT msg, int j, int i, int pos, int o) {

    if(whiteKing.posX == blackRook1.posX &&
       whiteKing.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKing.posX == blackRook2.posX &&
       whiteKing.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackRook2.posX &&
       whiteKnight1.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackRook2.posX &&
       whiteKnight2.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackRook2.posX &&
       whiteBishop1.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackRook2.posX &&
       whiteBishop2.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackRook2.posX &&
       whiteRook1.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackRook2.posX &&
       whiteRook2.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackRook2.posX &&
       whiteQueen.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackRook2.posX &&
           whitePawns[g].posY == blackRook2.posY) {
            blackRook2.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackRook2(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook2.posY = blackRook2.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY &&
                       blackPawns[s].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook2.posY &&
                       blackBishop1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook2.posY &&
                       blackBishop2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook2.posY &&
                       blackKnight1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook2.posY &&
                       blackKnight2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackRook2.posY &&
                       blackRook1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook2.posY &&
                       blackKing.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook2.posY &&
                       whitePawns[s].posX == blackRook2.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook2.posY &&
                       whiteRook1.posX == blackRook2.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook2.posY &&
                       whiteRook2.posX == blackRook2.posX) {
                        whiteRook2.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook2.posY &&
                       whiteRook2.posX == blackRook2.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook2.posY &&
                           whiteQueenK[z].posX == blackRook2.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook2.posY &&
                       whiteQueen.posX == blackRook2.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook2.posY &&
                       whiteBishop1.posX == blackRook2.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook2.posY &&
                       whiteBishop2.posX == blackRook2.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook2.posY &&
                       whiteKnight1.posX == blackRook2.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook2.posY &&
                       whiteKnight2.posX == blackRook2.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY - 70 &&
                       blackPawns[s].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackRook2.posY - 70 &&
                       whiteQueen.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == blackRook2.posY - 70 &&
                       whitePawns[i].posX == blackRook2.posX) {
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook2.posY - 70 &&
                   blackBishop1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook2.posY - 70 &&
                   blackBishop2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook2.posY - 70 &&
                   blackRook1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook2.posY - 70 &&
                   blackKnight1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook2.posY - 70 &&
                   blackKnight2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackRook2.posY - 70 &&
                   whiteRook1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackRook2.posY - 70 &&
                   whiteBishop1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackRook2.posY - 70 &&
                   whiteBishop2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook2.posY - 70 &&
                   whiteKnight1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook2.posY - 70 &&
                   whiteKnight2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook2.posY = blackRook2.posY - 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackRook2(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook2.posY = blackRook2.posY + 70;
                
                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY &&
                       blackPawns[s].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook2.posY &&
                       blackBishop1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook2.posY &&
                       blackBishop2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook2.posY &&
                       blackKnight1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook2.posY &&
                       blackKnight2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackRook2.posY &&
                       blackRook1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook2.posY &&
                       blackKing.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook2.posY &&
                       whitePawns[s].posX == blackRook2.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook2.posY &&
                       whiteRook1.posX == blackRook2.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook2.posY &&
                       whiteRook2.posX == blackRook2.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook2.posY &&
                           whiteQueenK[z].posX == blackRook2.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook2.posY &&
                       whiteQueen.posX == blackRook2.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook2.posY &&
                       whiteBishop1.posX == blackRook2.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook2.posY &&
                       whiteBishop2.posX == blackRook2.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook2.posY &&
                       whiteKnight1.posX == blackRook2.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook2.posY &&
                       whiteKnight2.posX == blackRook2.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY + 70 &&
                       blackPawns[s].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whiteQueen.posY == blackRook2.posY + 70 &&
                       whiteQueen.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == blackRook2.posY + 70 &&
                       whitePawns[i].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook2.posY + 70 &&
                   blackBishop1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook2.posY - 70 &&
                   blackBishop2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook2.posY + 70 &&
                   blackRook1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook2.posY + 70 &&
                   blackKnight1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook2.posY + 70 &&
                   blackKnight2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop1.posY == blackRook2.posY + 70 &&
                   blackBishop1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackRook2.posY + 70 &&
                   whiteRook1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackRook2.posY - 70 &&
                   whiteBishop1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackRook2.posY - 70 &&
                   whiteBishop2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook2.posY + 70 &&
                   whiteKnight1.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook2.posY + 70 &&
                   whiteKnight2.posX == blackRook2.posX) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook2.posY = blackRook2.posY + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}

boolean moveBlackRook2Side(UINT msg, int j, int i, int pos, int o) {

    if(whiteKing.posX == blackRook1.posX &&
       whiteKing.posY == blackRook1.posY) {
        blackRook1.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKing.posX == blackRook2.posX &&
       whiteKing.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight1.posX == blackRook2.posX &&
       whiteKnight1.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteKnight2.posX == blackRook2.posX &&
       whiteKnight2.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop1.posX == blackRook2.posX &&
       whiteBishop1.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteBishop2.posX == blackRook2.posX &&
       whiteBishop2.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook1.posX == blackRook2.posX &&
       whiteRook1.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteRook2.posX == blackRook2.posX &&
       whiteRook2.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    if(whiteQueen.posX == blackRook2.posX &&
       whiteQueen.posY == blackRook2.posY) {
        blackRook2.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(whitePawns[g].posX == blackRook2.posX &&
           whitePawns[g].posY == blackRook2.posY) {
            blackRook2.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveBlackRook2Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook2.posX = blackRook2.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY &&
                       blackPawns[s].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook2.posY &&
                       blackBishop1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook2.posY &&
                       blackBishop2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook2.posY &&
                       blackKnight1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook2.posY &&
                       blackKnight2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackRook2.posY &&
                       blackRook1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook2.posY &&
                       blackKing.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook2.posY &&
                       whitePawns[s].posX == blackRook2.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook2.posY &&
                       whiteRook1.posX == blackRook2.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook2.posY &&
                       whiteRook2.posX == blackRook2.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook2.posY &&
                           whiteQueenK[z].posX == blackRook2.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook2.posY &&
                       whiteQueen.posX == blackRook2.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook2.posY &&
                       whiteBishop1.posX == blackRook2.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook2.posY &&
                       whiteBishop2.posX == blackRook2.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook2.posY &&
                       whiteKnight1.posX == blackRook2.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook2.posY &&
                       whiteKnight2.posX == blackRook2.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY &&
                       blackPawns[s].posX == blackRook2.posX - 70) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[s].posY == blackRook2.posY &&
                       whitePawns[s].posX == blackRook2.posX - 70) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == blackRook2.posY &&
                       blackQueen.posX == blackRook2.posX - 70) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook2.posY &&
                   blackBishop1.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook2.posY &&
                   blackBishop2.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook2.posY &&
                   blackRook1.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook2.posY &&
                   blackKnight1.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook2.posY &&
                   blackKnight2.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackRook2.posY &&
                   whiteRook1.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackRook2.posY &&
                   whiteBishop1.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackRook2.posY &&
                   whiteBishop2.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook2.posY &&
                   whiteKnight1.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook2.posY &&
                   whiteKnight2.posX == blackRook2.posX - 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook2.posX = blackRook2.posX - 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveBlackRook2Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                blackRook2.posX = blackRook2.posX + 70;

                for(int s=0; s<8; s++) {
                    if(blackPawns[s].posY == blackRook2.posY &&
                       blackPawns[s].posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop1.posY == blackRook2.posY &&
                       blackBishop1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackBishop2.posY == blackRook2.posY &&
                       blackBishop2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight1.posY == blackRook2.posY &&
                       blackKnight1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKnight2.posY == blackRook2.posY &&
                       blackKnight2.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackRook1.posY == blackRook2.posY &&
                       blackRook1.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(blackKing.posY == blackRook2.posY &&
                       blackKing.posX == blackRook2.posX) {
                        blackRook2.failedpath = TRUE;
                        return TRUE;
                    }
                    if(whitePawns[s].posY == blackRook2.posY &&
                       whitePawns[s].posX == blackRook2.posX) {
                        whitePawns[s].posX = 1300;
                    }
                    if(whiteRook1.posY == blackRook2.posY &&
                       whiteRook1.posX == blackRook2.posX) {
                        whiteRook1.posX = 1300;
                    }
                    if(whiteRook2.posY == blackRook2.posY &&
                       whiteRook2.posX == blackRook2.posX) {
                        whiteRook2.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(whiteQueenK[z].posY == blackRook2.posY &&
                           whiteQueenK[z].posX == blackRook2.posX) {
                            whiteQueenK[z].posX = 1300;
                        }
                    }
                    if(whiteQueen.posY == blackRook2.posY &&
                       whiteQueen.posX == blackRook2.posX) {
                        whiteQueen.posX = 1300;
                    }
                    if(whiteBishop1.posY == blackRook2.posY &&
                       whiteBishop1.posX == blackRook2.posX) {
                        whiteBishop1.posX = 1300;
                    }
                    if(whiteBishop2.posY == blackRook2.posY &&
                       whiteBishop2.posX == blackRook2.posX) {
                        whiteBishop2.posX = 1300;
                    }
                    if(whiteKnight1.posY == blackRook2.posY &&
                       whiteKnight1.posX == blackRook2.posX) {
                        whiteKnight1.posX = 1300;
                    }
                    if(whiteKnight2.posY == blackRook2.posY &&
                       whiteKnight2.posX == blackRook2.posX) {
                        whiteKnight2.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    if(blackPawns[i].posY == blackRook2.posY &&
                       blackPawns[i].posX == blackRook2.posX + 70) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(whitePawns[i].posY == blackRook2.posY &&
                       whitePawns[i].posX == blackRook2.posX + 70) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(blackQueen.posY == blackRook2.posY &&
                       blackQueen.posX == blackRook2.posX + 70) {
                        blackRook2.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(blackBishop1.posY == blackRook2.posY &&
                   blackBishop1.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackBishop2.posY == blackRook2.posY &&
                   blackBishop2.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackRook1.posY == blackRook2.posY &&
                   blackRook1.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight1.posY == blackRook2.posY &&
                   blackKnight1.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(blackKnight2.posY == blackRook2.posY &&
                   blackKnight2.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteRook1.posY == blackRook2.posY &&
                   whiteRook1.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop1.posY == blackRook2.posY &&
                   whiteBishop1.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteBishop2.posY == blackRook2.posY &&
                   whiteBishop2.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight1.posY == blackRook2.posY &&
                   whiteKnight1.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }
                if(whiteKnight2.posY == blackRook2.posY &&
                   whiteKnight2.posX == blackRook2.posX + 70) {
                    blackRook2.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    blackRook2.posX = blackRook2.posX + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}