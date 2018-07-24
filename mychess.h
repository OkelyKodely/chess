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

char bestMove[4] = "b1c3";
    
boolean firstTime = TRUE;
char clickedOne = 'g';
char turn;
const char g_szClassName[] = "mychess";

WNDCLASSEX wc;
WNDCLASSEX wcfwabout;
HWND hwnd;
MSG Msg;
HDC hdc;

struct GreyPawnBase {
    int x1, y1, x2, y2;
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean firstTimeMove;

} greyPawnsBase[8];

struct RedPawnBase {
    int x1, y1, x2, y2;
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean firstTimeMove;

} redPawnsBase[8];

struct Box {
    int posX, posY;
    boolean clear;
    boolean clicked;

} boxes[8][8];

struct RedRook2Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} redRook2Rectangle1;

struct RedRook1Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} redRook1Rectangle1;

struct GreyRook2Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} greyRook2Rectangle1;

struct GreyRook1Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    boolean failedpath;
    int x1, y1, x2, y2;

} greyRook1Rectangle1;

struct GreyKnight1Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} greyKnight1Rectangle1;

struct GreyKnight2Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} greyKnight2Rectangle1;

struct RedKnight2Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} redKnight2Rectangle1;

struct RedKnight1Rectangle1 {
    int posX, posY;
    char *from;
    char *to;
    boolean clicked;
    int x1, y1, x2, y2;

} redKnight1Rectangle1;

struct GreyKingSquare {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;

} greyKingSquare;

struct RedKingSquare {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;

} redKingSquare;

struct GreyQueenSquare {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} greyQueenSquare;

struct GreyQueenSquareK {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} greyQueenSquareK[8];

struct RedQueenSquare {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} redQueenSquare;

struct RedQueenSquareK {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} redQueenSquareK[8];

struct RedBishop1Square {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} redBishop1Square;

struct RedBishop2Square {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} redBishop2Square;

struct GreyBishop1Square {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} greyBishop1Square;

struct GreyBishop2Square {
    int posX, posY;
    char *from;
    char *to;
    int x1, y1, x2, y2;
    boolean clicked;
    boolean failedpath;

} greyBishop2Square;

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
    BitBlt(hdc, 20, 20, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

    SelectObject(hdcMem, oldBitmap);
    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hhbb); DeleteObject(oldBitmap);
}

boolean moveGreyQueen(UINT msg, int j, int i, int pos, int o) {

    if(redKnight1Rectangle1.posX == greyQueenSquare.posX &&
       redKnight1Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyQueenSquare.posX &&
       redKnight2Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyQueenSquare.posX &&
       redBishop1Square.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyQueenSquare.posX &&
       redBishop2Square.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyQueenSquare.posX &&
       redRook1Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyQueenSquare.posX &&
       redRook2Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyQueenSquare.posX &&
       redQueenSquare.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyQueenSquare.posX &&
           redPawnsBase[g].posY == greyQueenSquare.posY) {
            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyQueen(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquare.posY = greyQueenSquare.posY - 70;
                    
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY &&
                       greyBishop1Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY &&
                       greyBishop2Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquare.posY &&
                       greyKingSquare.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                           redPawnsBase[s].posX == greyQueenSquare.posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquare.posY &&
                           redQueenSquare.posX == greyQueenSquare.posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                           redRook1Rectangle1.posX == greyQueenSquare.posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                           redRook2Rectangle1.posX == greyQueenSquare.posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquare.posY &&
                           redBishop1Square.posX == greyQueenSquare.posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquare.posY &&
                           redBishop2Square.posX == greyQueenSquare.posX) {
                            redBishop2Square.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY - 70 &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquare.posY - 70 &&
                       redPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redQueenSquare.posY == greyQueenSquare.posY - 70 &&
                   redQueenSquare.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY - 70 &&
                   redBishop1Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY - 70 &&
                   redBishop2Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY - 70 &&
                   redBishop1Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY - 70 &&
                   redBishop2Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   redRook1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   redRook2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                   redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                
                if(!flag) {
                    greyQueenSquare.posY = greyQueenSquare.posY - 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyQueen(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquare.posY = greyQueenSquare.posY + 70;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY &&
                       greyBishop1Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY &&
                       greyBishop2Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquare.posY &&
                       greyKingSquare.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                           redPawnsBase[s].posX == greyQueenSquare.posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquare.posY &&
                           redQueenSquare.posX == greyQueenSquare.posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                           redRook1Rectangle1.posX == greyQueenSquare.posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                           redRook2Rectangle1.posX == greyQueenSquare.posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquare.posY &&
                           redBishop1Square.posX == greyQueenSquare.posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquare.posY &&
                           redBishop2Square.posX == greyQueenSquare.posX) {
                            redBishop2Square.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY + 70 &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquare.posY + 70 &&
                       redPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redQueenSquare.posY == greyQueenSquare.posY + 70 &&
                   redQueenSquare.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY + 70 &&
                   redBishop1Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY + 70 &&
                   redBishop2Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY + 70 &&
                   redBishop1Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY + 70 &&
                   redBishop2Square.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   redRook1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   redRook2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                   redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquare.posY = greyQueenSquare.posY + 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveGreyQueenSide(UINT msg, int j, int i, int pos, int o) {

    if(redKnight1Rectangle1.posX == greyQueenSquare.posX &&
       redKnight1Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyQueenSquare.posX &&
       redKnight2Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyQueenSquare.posX &&
       redBishop1Square.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyQueenSquare.posX &&
       redBishop2Square.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyQueenSquare.posX &&
       redRook1Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyQueenSquare.posX &&
       redRook2Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyQueenSquare.posX &&
       redQueenSquare.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyQueenSquare.posX &&
           redPawnsBase[g].posY == greyQueenSquare.posY) {
            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyQueenSide(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquare.posX = greyQueenSquare.posX - 70;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY &&
                       greyBishop1Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY &&
                       greyBishop2Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquare.posY &&
                       greyKingSquare.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                           redPawnsBase[s].posX == greyQueenSquare.posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquare.posY &&
                           redQueenSquare.posX == greyQueenSquare.posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                           redRook1Rectangle1.posX == greyQueenSquare.posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                           redRook2Rectangle1.posX == greyQueenSquare.posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquare.posY &&
                           redBishop1Square.posX == greyQueenSquare.posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquare.posY &&
                           redBishop2Square.posX == greyQueenSquare.posX) {
                            redBishop2Square.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                       redPawnsBase[s].posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redQueenSquare.posY == greyQueenSquare.posY &&
                   redQueenSquare.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY &&
                   redBishop1Square.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY &&
                   redBishop2Square.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                   greyRook1Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                   greyRook2Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                   greyKnight1Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                   greyKnight2Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY &&
                   redBishop1Square.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY &&
                   redBishop2Square.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                   redRook1Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                   redRook2Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                   redKnight1Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                   redKnight2Rectangle1.posX == greyQueenSquare.posX - 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquare.posX = greyQueenSquare.posX - 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyQueenSide(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquare.posX = greyQueenSquare.posX + 70;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[i].posY == greyQueenSquare.posY &&
                       greyPawnsBase[i].posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY &&
                       greyBishop1Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY &&
                       greyBishop2Square.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquare.posY &&
                       greyKingSquare.posX == greyQueenSquare.posX) {
                        greyQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                           redPawnsBase[s].posX == greyQueenSquare.posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquare.posY &&
                           redQueenSquare.posX == greyQueenSquare.posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquare.posY &&
                           redQueenSquare.posX == greyQueenSquare.posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquare.posY &&
                           redBishop1Square.posX == greyQueenSquare.posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquare.posY &&
                           redBishop2Square.posX == greyQueenSquare.posX) {
                            redBishop2Square.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                           redRook1Rectangle1.posX == greyQueenSquare.posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                           redRook2Rectangle1.posX == greyQueenSquare.posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                       greyPawnsBase[s].posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                       redPawnsBase[s].posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redQueenSquare.posY == greyQueenSquare.posY &&
                   redQueenSquare.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY &&
                   redBishop1Square.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY &&
                   redBishop2Square.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                   greyRook1Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                   greyRook2Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                   greyKnight1Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                   greyKnight2Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquare.posY &&
                   redBishop1Square.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquare.posY &&
                   redBishop2Square.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                   redRook1Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                   redRook2Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                   redKnight1Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                   redKnight2Rectangle1.posX == greyQueenSquare.posX + 70) {
                    greyQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquare.posX = greyQueenSquare.posX + 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveRedQueen(UINT msg, int j, int i, int pos, int o) {

    if(pos == 0) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redQueenSquare.posX &&
       greyKnight1Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redQueenSquare.posX &&
       greyKnight2Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redQueenSquare.posX &&
       greyBishop1Square.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redQueenSquare.posX &&
       greyBishop2Square.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redQueenSquare.posX &&
       greyRook1Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redQueenSquare.posX &&
       greyRook2Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquare.posX &&
       greyQueenSquare.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redQueenSquare.posX &&
           greyPawnsBase[g].posY == redQueenSquare.posY) {
            redQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedQueen(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquare.posY = redQueenSquare.posY - 70;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY &&
                       redPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                           greyPawnsBase[s].posX == redQueenSquare.posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquare.posY &&
                           greyQueenSquare.posX == redQueenSquare.posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                           greyRook1Rectangle1.posX == redQueenSquare.posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                           greyRook2Rectangle1.posX == redQueenSquare.posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquare.posY &&
                           greyBishop1Square.posX == redQueenSquare.posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquare.posY &&
                           greyBishop2Square.posX == redQueenSquare.posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY - 70 &&
                       redPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;                        
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redQueenSquare.posY - 70 &&
                       greyPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;                        
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                   redBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                   redBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                   redRook1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                   redRook2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                   redKnight1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                   redKnight2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                   redBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                   redBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY - 70 &&
                   greyQueenSquare.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY - 70 &&
                   greyBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY - 70 &&
                   greyBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                   greyRook1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                   greyRook2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                   greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                   greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquare.posY = redQueenSquare.posY - 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquare.failedpath = TRUE;                        
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveRedQueen(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquare.posY = redQueenSquare.posY + 70;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY &&
                       redPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                           greyPawnsBase[s].posX == redQueenSquare.posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquare.posY &&
                           greyQueenSquare.posX == redQueenSquare.posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                           greyRook1Rectangle1.posX == redQueenSquare.posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                           greyRook2Rectangle1.posX == redQueenSquare.posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquare.posY &&
                           greyBishop1Square.posX == redQueenSquare.posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquare.posY &&
                           greyBishop2Square.posX == redQueenSquare.posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY + 70 &&
                       redPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redQueenSquare.posY + 70 &&
                       greyPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquare.posY + 70 &&
                   redBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY + 70 &&
                   redBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquare.posY + 70 &&
                   redRook1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquare.posY + 70 &&
                   redRook2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquare.posY + 70 &&
                   redKnight1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquare.posY + 70 &&
                   redKnight2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquare.posY + 70 &&
                   redBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY + 70 &&
                   redBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY + 70 &&
                   greyQueenSquare.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY + 70 &&
                   greyBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY + 70 &&
                   greyBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquare.posY + 70 &&
                   greyRook1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquare.posY + 70 &&
                   greyRook2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquare.posY + 70 &&
                   greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquare.posY + 70 &&
                   greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY + 70 &&
                   greyBishop1Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY + 70 &&
                   greyBishop2Square.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY + 70 &&
                   greyQueenSquare.posX == redQueenSquare.posX) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquare.posY = redQueenSquare.posY + 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveRedQueenSide(UINT msg, int j, int i, int pos, int o) {

    if(greyKnight1Rectangle1.posX == redQueenSquare.posX &&
       greyKnight1Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redQueenSquare.posX &&
       greyKnight2Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redQueenSquare.posX &&
       greyBishop1Square.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redQueenSquare.posX &&
       greyBishop2Square.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redQueenSquare.posX &&
       greyRook1Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redQueenSquare.posX &&
       greyRook2Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquare.posX &&
       greyQueenSquare.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redQueenSquare.posX &&
           greyPawnsBase[g].posY == redQueenSquare.posY) {
            redQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedQueenSide(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquare.posX = redQueenSquare.posX - 70;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY &&
                       redPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                           greyPawnsBase[s].posX == redQueenSquare.posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquare.posY &&
                           greyQueenSquare.posX == redQueenSquare.posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                           greyRook1Rectangle1.posX == redQueenSquare.posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                           greyRook2Rectangle1.posX == redQueenSquare.posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquare.posY &&
                           greyBishop1Square.posX == redQueenSquare.posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquare.posY &&
                           greyBishop2Square.posX == redQueenSquare.posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY &&
                       redPawnsBase[s].posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                       greyPawnsBase[s].posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquare.posY &&
                   redBishop1Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY &&
                   redBishop2Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                   redRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                   redRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                   redKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                   redKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquare.posY &&
                   redBishop1Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY &&
                   redBishop2Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY &&
                   greyQueenSquare.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY &&
                   greyBishop1Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY &&
                   greyBishop2Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                   greyRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                   greyRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                   greyKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                   greyKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY &&
                   greyBishop1Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY &&
                   greyBishop2Square.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY &&
                   greyQueenSquare.posX == redQueenSquare.posX - 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquare.posX = redQueenSquare.posX - 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveRedQueenSide(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquare.posX = redQueenSquare.posX + 70;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redQueenSquare.posY &&
                       redPawnsBase[s].posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY &&
                       redBishop1Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY &&
                       redBishop2Square.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                       redRook1Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                       redRook2Rectangle1.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquare.posY &&
                       redKingSquare.posX == redQueenSquare.posX) {
                        redQueenSquare.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                           greyPawnsBase[s].posX == redQueenSquare.posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquare.posY &&
                           greyQueenSquare.posX == redQueenSquare.posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                           greyRook1Rectangle1.posX == redQueenSquare.posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                           greyRook2Rectangle1.posX == redQueenSquare.posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquare.posY &&
                           greyBishop1Square.posX == redQueenSquare.posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquare.posY &&
                           greyBishop2Square.posX == redQueenSquare.posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    if(redPawnsBase[i].posY == redQueenSquare.posY &&
                       redPawnsBase[i].posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == redQueenSquare.posY &&
                       greyPawnsBase[i].posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquare.posY &&
                   redBishop1Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY &&
                   redBishop2Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                   redRook1Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                   redRook2Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                   redKnight1Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                   redKnight2Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquare.posY &&
                   redBishop1Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquare.posY &&
                   redBishop2Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY &&
                   greyQueenSquare.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY &&
                   greyBishop1Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY &&
                   greyBishop2Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                   greyRook1Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                   greyRook2Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                   greyKnight1Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                   greyKnight2Rectangle1.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquare.posY &&
                   greyBishop1Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquare.posY &&
                   greyBishop2Square.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquare.posY &&
                   greyQueenSquare.posX == redQueenSquare.posX + 70) {
                    redQueenSquare.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquare.posX = redQueenSquare.posX + 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveRedQueenSideK(UINT msg, int j, int i, int pos, int o, int k) {

    if(greyKnight1Rectangle1.posX == redQueenSquareK[k].posX &&
       greyKnight1Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redQueenSquareK[k].posX &&
       greyKnight2Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redQueenSquareK[k].posX &&
       greyBishop1Square.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redQueenSquareK[k].posX &&
       greyBishop2Square.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redQueenSquareK[k].posX &&
       greyRook1Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redQueenSquareK[k].posX &&
       greyRook2Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquareK[k].posX &&
       greyQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redQueenSquareK[k].posX &&
           greyPawnsBase[g].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedQueenSideK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquareK[k].posX = redQueenSquareK[k].posX - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                            redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                        redQueenSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int b=0; b<8; b++) {
                            if(greyQueenSquareK[b].posY == redQueenSquareK[k].posY &&
                               greyQueenSquareK[b].posX == redQueenSquareK[k].posX) {
                                greyQueenSquareK[b].posX = 1300;
                            }
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                           greyQueenSquare.posX == redQueenSquareK[k].posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                           greyBishop1Square.posX == redQueenSquareK[k].posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                           greyBishop2Square.posX == redQueenSquareK[k].posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int d=0; d<8; d++) {
                        if(redQueenSquareK[d].posY == redQueenSquareK[k].posY &&
                           redQueenSquareK[d].posX == redQueenSquareK[k].posX - 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyQueenSquareK[d].posY == redQueenSquareK[k].posY &&
                           greyQueenSquareK[d].posX == redQueenSquareK[k].posX - 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                       greyPawnsBase[s].posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                   redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                   redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                   redRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                   redRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                   redKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                   redKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                   redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                   redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                   redQueenSquare.posX == redQueenSquareK[k].posX - 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquareK[k].posX = redQueenSquareK[k].posX - 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveRedQueenSideK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquareK[k].posX = redQueenSquareK[k].posX + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                            redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                        redQueenSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        for(int c=0; c<8; c++) {
                            if(greyQueenSquareK[c].posY == redQueenSquareK[k].posY &&
                               greyQueenSquareK[c].posX == redQueenSquareK[k].posX) {
                                greyQueenSquareK[c].posX = 1300;
                            }
                        }
                        if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                           greyQueenSquare.posX == redQueenSquareK[k].posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                           greyBishop1Square.posX == redQueenSquareK[k].posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                           greyBishop2Square.posX == redQueenSquareK[k].posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    for(int f=0; f<8; f++) {
                        if(redQueenSquareK[f].posY == redQueenSquareK[k].posY &&
                           redQueenSquareK[f].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                       redQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[i].posY == redQueenSquareK[k].posY &&
                       redPawnsBase[i].posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == redQueenSquareK[k].posY &&
                       greyPawnsBase[i].posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                   redBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                   redBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                   redRook1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                   redRook2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                   redKnight1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                   redKnight2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                   redBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                   redBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int g=0; g<8; g++) {
                    if(greyQueenSquareK[g].posY == redQueenSquareK[k].posY &&
                       greyQueenSquareK[g].posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyRook1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyRook2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyKnight1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                   greyKnight2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquareK[k].posX = redQueenSquareK[k].posX + 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveGreyQueenSideK(UINT msg, int j, int i, int pos, int o, int k) {

    if(redKnight1Rectangle1.posX == greyQueenSquareK[k].posX &&
       redKnight1Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyQueenSquareK[k].posX &&
       redKnight2Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyQueenSquareK[k].posX &&
       redBishop1Square.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyQueenSquareK[k].posX &&
       redBishop2Square.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyQueenSquareK[k].posX &&
       redRook1Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyQueenSquareK[k].posX &&
       redRook2Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyQueenSquareK[k].posX &&
       redQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyQueenSquareK[k].posX &&
           redPawnsBase[g].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyQueenSideK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquareK[k].posX = greyQueenSquareK[k].posX - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                            greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                        greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                       greyKingSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                       greyKingSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int b=0; b<8; b++) {
                            if(redQueenSquareK[b].posY == greyQueenSquareK[k].posY &&
                               redQueenSquareK[b].posX == greyQueenSquareK[k].posX) {
                                redQueenSquareK[b].posX = 1300;
                            }
                        }
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                           redQueenSquare.posX == greyQueenSquareK[k].posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                           redBishop1Square.posX == greyQueenSquareK[k].posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                           redBishop2Square.posX == greyQueenSquareK[k].posX) {
                            redBishop2Square.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int d=0; d<8; d++) {
                        if(greyQueenSquareK[d].posY == greyQueenSquareK[k].posY &&
                           greyQueenSquareK[d].posX == greyQueenSquareK[k].posX - 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(redQueenSquareK[d].posY == greyQueenSquareK[k].posY &&
                           redQueenSquareK[d].posX == greyQueenSquareK[k].posX - 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                   redQueenSquare.posX == greyQueenSquareK[k].posX - 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquareK[k].posX = greyQueenSquareK[k].posX - 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyQueenSideK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquareK[k].posX = greyQueenSquareK[k].posX + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                            greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                            greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                        greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                       greyKingSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                       greyKingSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        for(int c=0; c<8; c++) {
                            if(redQueenSquareK[c].posY == greyQueenSquareK[k].posY &&
                               redQueenSquareK[c].posX == greyQueenSquareK[k].posX) {
                                redQueenSquareK[c].posX = 1300;
                            }
                        }
                        if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                           redQueenSquare.posX == greyQueenSquareK[k].posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                           redBishop1Square.posX == greyQueenSquareK[k].posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                           redBishop2Square.posX == greyQueenSquareK[k].posX) {
                            redBishop2Square.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    for(int f=0; f<8; f++) {
                        if(redQueenSquareK[f].posY == greyQueenSquareK[k].posY &&
                           redQueenSquareK[f].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[i].posY == greyQueenSquareK[k].posY &&
                       redPawnsBase[i].posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == greyQueenSquareK[k].posY &&
                       greyPawnsBase[i].posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redRook1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redRook2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redKnight1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   redKnight2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int g=0; g<8; g++) {
                    if(greyQueenSquareK[g].posY == greyQueenSquareK[k].posY &&
                       greyQueenSquareK[g].posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyRook1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyRook2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                   greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquareK[k].posX = greyQueenSquareK[k].posX + 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveRedQueenK(UINT msg, int j, int i, int pos, int o, int k) {

    for(int q=0; q<8; q++) {
        if(q != k &&
           redQueenSquareK[q].posX == redQueenSquareK[k].posX &&
           redQueenSquareK[q].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
        if(q != k &&
           greyQueenSquareK[q].posX == redQueenSquareK[k].posX &&
           greyQueenSquareK[q].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(redQueenSquare.posX == redQueenSquareK[k].posX &&
       redQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquareK[k].posX &&
       greyQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redQueenSquareK[k].posX &&
       greyKnight1Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redQueenSquareK[k].posX &&
       greyKnight2Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redQueenSquareK[k].posX &&
       greyBishop1Square.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redQueenSquareK[k].posX &&
       greyBishop2Square.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redQueenSquareK[k].posX &&
       greyRook1Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redQueenSquareK[k].posX &&
       greyRook2Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquareK[k].posX &&
       greyQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redQueenSquareK[k].posX &&
           greyPawnsBase[g].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedQueenK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquareK[k].posY = redQueenSquareK[k].posY - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                           redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                       redQueenSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int r=0; r<8; r++) {
                            if(greyQueenSquareK[r].posY == redQueenSquareK[k].posY &&
                               greyQueenSquareK[r].posX == redQueenSquareK[k].posX) {
                                greyQueenSquareK[r].posX = 1300;
                            }
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                           greyQueenSquare.posX == redQueenSquareK[k].posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                           greyBishop1Square.posX == redQueenSquareK[k].posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                           greyBishop2Square.posX == redQueenSquareK[k].posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           redQueenSquareK[p].posY == redQueenSquareK[k].posY - 70 &&
                           redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY - 70 &&
                       redQueenSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY - 70 &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redQueenSquareK[k].posY - 70 &&
                       greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                   redBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                   redBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                   redBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                   redBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int w=0; w<8; w++) {
                    if(greyQueenSquareK[w].posY == redQueenSquareK[k].posY - 70 &&
                       greyQueenSquareK[w].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY - 70 &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                   greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquareK[k].posY = redQueenSquareK[k].posY - 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquareK[k].failedpath = TRUE;                        
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveRedQueenK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                redQueenSquareK[k].posY = redQueenSquareK[k].posY + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                           redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                       redQueenSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                       redBishop1Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                       redBishop2Square.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redQueenSquareK[k].posY &&
                       redKingSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int a=0; a<8; a++) {
                            if(greyQueenSquareK[a].posY == redQueenSquareK[k].posY &&
                               greyQueenSquareK[a].posX == redQueenSquareK[k].posX) {
                                greyQueenSquareK[a].posX = 1300;
                            }
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            greyPawnsBase[s].posX = 1300;
                        }
                        if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                           greyQueenSquare.posX == redQueenSquareK[k].posX) {
                            greyQueenSquare.posX = 1300;
                        }
                        if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }
                        if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                        if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                           greyBishop1Square.posX == redQueenSquareK[k].posX) {
                            greyBishop1Square.posX = 1300;
                        }
                        if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                           greyBishop2Square.posX == redQueenSquareK[k].posX) {
                            greyBishop2Square.posX = 1300;
                        }
                        if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }
                        if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           redQueenSquareK[p].posY == redQueenSquareK[k].posY + 70 &&
                           redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       redQueenSquare.posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == redQueenSquareK[k].posY + 70 &&
                       redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redQueenSquareK[k].posY + 70 &&
                       greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                   redBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                   redBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                   redBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                   redBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int e=0; e<8; e++) {
                    if(greyQueenSquareK[e].posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquareK[e].posX == redQueenSquareK[k].posX) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                   greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                   greyBishop1Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                   greyBishop2Square.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                   greyQueenSquare.posX == redQueenSquareK[k].posX) {
                    redQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redQueenSquareK[k].posY = redQueenSquareK[k].posY + 70;
                }

                return flag;
            }
        }

        else {

            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveGreyQueenK(UINT msg, int j, int i, int pos, int o, int k) {

    for(int q=0; q<8; q++) {
        if(q != k &&
           redQueenSquareK[q].posX == greyQueenSquareK[k].posX &&
           redQueenSquareK[q].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
        if(q != k &&
           redQueenSquareK[q].posX == greyQueenSquareK[k].posX &&
           redQueenSquareK[q].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(redQueenSquare.posX == greyQueenSquareK[k].posX &&
       redQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == greyQueenSquareK[k].posX &&
       greyQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redKnight1Rectangle1.posX == greyQueenSquareK[k].posX &&
       redKnight1Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyQueenSquareK[k].posX &&
       redKnight2Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyQueenSquareK[k].posX &&
       redBishop1Square.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyQueenSquareK[k].posX &&
       redBishop2Square.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyQueenSquareK[k].posX &&
       redRook1Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyQueenSquareK[k].posX &&
       redRook2Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyQueenSquareK[k].posX &&
       redQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyQueenSquareK[k].posX &&
           redPawnsBase[g].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos == 0) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyQueenK(msg, j, i, pos + 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquareK[k].posY = greyQueenSquareK[k].posY - 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                           greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                       greyKingSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                       greyKingSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        for(int r=0; r<8; r++) {
                            if(redQueenSquareK[r].posY == greyQueenSquareK[k].posY &&
                               redQueenSquareK[r].posX == greyQueenSquareK[k].posX) {
                                redQueenSquareK[r].posX = 1300;
                            }
                        }
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            redPawnsBase[s].posX = 1300;
                        }
                        if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                           redQueenSquare.posX == greyQueenSquareK[k].posX) {
                            redQueenSquare.posX = 1300;
                        }
                        if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redRook1Rectangle1.posX = 1300;
                        }
                        if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redRook2Rectangle1.posX = 1300;
                        }
                        if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                           redBishop1Square.posX == greyQueenSquareK[k].posX) {
                            redBishop1Square.posX = 1300;
                        }
                        if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                           redBishop2Square.posX == greyQueenSquareK[k].posX) {
                            redBishop2Square.posX = 1300;
                        }
                        if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redKnight1Rectangle1.posX = 1300;
                        }
                        if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            redKnight2Rectangle1.posX = 1300;
                        }
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           redQueenSquareK[p].posY == greyQueenSquareK[k].posY - 70 &&
                           redQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY - 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY - 70 &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquareK[k].posY - 70 &&
                       redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY - 70 &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;                        
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int w=0; w<8; w++) {
                    if(greyQueenSquareK[w].posY == greyQueenSquareK[k].posY - 70 &&
                       greyQueenSquareK[w].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY - 70 &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                   greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquareK[k].posY = greyQueenSquareK[k].posY - 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquareK[k].failedpath = TRUE;                        
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyQueenK(msg, j, i, pos - 70, o, k);
        }
        if(!f) {
            if(pos == o) {

                greyQueenSquareK[k].posY = greyQueenSquareK[k].posY + 70;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                           greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    for(int a=0; a<8; a++) {
                        if(redQueenSquareK[a].posY == greyQueenSquareK[k].posY &&
                           redQueenSquareK[a].posX == greyQueenSquareK[k].posX) {
                            redQueenSquareK[a].posX = 1300;
                        }
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    for(int p=0; p<8; p++) {
                        if(p != k &&
                           greyQueenSquareK[p].posY == greyQueenSquareK[k].posY + 70 &&
                           greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyQueenSquareK[k].posY + 70 &&
                       redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY + 70 &&
                       greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                   redBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                   redBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                for(int e=0; e<8; e++) {
                    if(greyQueenSquareK[e].posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquareK[e].posX == greyQueenSquareK[k].posX) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                   greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                   greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                   greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                   greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                    greyQueenSquareK[k].failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyQueenSquareK[k].posY = greyQueenSquareK[k].posY + 70;
                }

                return flag;
            }
        }

        else {

            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveGreyQueenDiagonally(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(redKnight1Rectangle1.posX == greyQueenSquare.posX &&
       redKnight1Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyQueenSquare.posX &&
       redKnight2Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyQueenSquare.posX &&
       redBishop1Square.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyQueenSquare.posX &&
       redBishop2Square.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyQueenSquare.posX &&
       redRook1Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyQueenSquare.posX &&
       redRook2Rectangle1.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyQueenSquare.posX &&
       redQueenSquare.posY == greyQueenSquare.posY) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyQueenSquare.posX &&
           redPawnsBase[g].posY == greyQueenSquare.posY) {
            greyQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        greyQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        greyQueenSquare.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveGreyQueenDiagonally(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquare.posY = greyQueenSquare.posY - 70;
                    greyQueenSquare.posX = greyQueenSquare.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquare.posY &&
                           greyBishop1Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquare.posY &&
                           greyBishop2Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquare.posY &&
                           greyKingSquare.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquare.posY &&
                           greyBishop1Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquare.posY &&
                           greyBishop2Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquare.posY &&
                           greyKingSquare.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                               redPawnsBase[s].posX == greyQueenSquare.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquare.posY &&
                               redBishop1Square.posX == greyQueenSquare.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquare.posY &&
                               redBishop2Square.posX == greyQueenSquare.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                               redRook1Rectangle1.posX == greyQueenSquare.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                               redRook2Rectangle1.posX == greyQueenSquare.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redQueenSquare.posY == greyQueenSquare.posY &&
                               redQueenSquare.posX == greyQueenSquare.posX) {
                                redQueenSquare.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY - 70 &&
                           redPawnsBase[s].posX == greyQueenSquare.posX - 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY - 70 &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX - 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquare.posY - 70 &&
                       redQueenSquare.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redRook1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redRook2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquare.posY - 70 &&
                       greyQueenSquare.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquare.posY - 70 &&
                       greyBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquare.posY - 70 &&
                       greyBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY - 70 &&
                       greyBishop1Square.posX == greyQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY - 70 &&
                       greyBishop2Square.posX == greyQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquare.posY - 70 &&
                       greyQueenSquare.posX == greyQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquare.posY = greyQueenSquare.posY - 70;
                        greyQueenSquare.posX = greyQueenSquare.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveGreyQueenDiagonally(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquare.posY = greyQueenSquare.posY - 70;
                    greyQueenSquare.posX = greyQueenSquare.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquare.posY &&
                           greyBishop1Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquare.posY &&
                           greyBishop2Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquare.posY &&
                           greyKingSquare.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                               redPawnsBase[s].posX == greyQueenSquare.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquare.posY &&
                               redBishop1Square.posX == greyQueenSquare.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquare.posY &&
                               redBishop2Square.posX == greyQueenSquare.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                               redRook1Rectangle1.posX == greyQueenSquare.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                               redRook2Rectangle1.posX == greyQueenSquare.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redQueenSquare.posY == greyQueenSquare.posY &&
                               redQueenSquare.posX == greyQueenSquare.posX) {
                                redQueenSquare.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY - 70 &&
                           redPawnsBase[s].posX == greyQueenSquare.posX + 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY - 70 &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX + 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquare.posY - 70 &&
                       redQueenSquare.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redRook1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redRook2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY - 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY - 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY - 70 &&
                       greyBishop1Square.posX == greyQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY - 70 &&
                       greyBishop2Square.posX == greyQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquare.posY - 70 &&
                       greyQueenSquare.posX == greyQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquare.posY = greyQueenSquare.posY - 70;
                        greyQueenSquare.posX = greyQueenSquare.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveGreyQueenDiagonally(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquare.posY = greyQueenSquare.posY + 70;
                    greyQueenSquare.posX = greyQueenSquare.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquare.posY &&
                           greyBishop1Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquare.posY &&
                           greyBishop2Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquare.posY &&
                           greyKingSquare.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                               redPawnsBase[s].posX == greyQueenSquare.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquare.posY &&
                               redBishop1Square.posX == greyQueenSquare.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquare.posY &&
                               redBishop2Square.posX == greyQueenSquare.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                               redRook1Rectangle1.posX == greyQueenSquare.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                               redRook2Rectangle1.posX == greyQueenSquare.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redQueenSquare.posY == greyQueenSquare.posY &&
                               redQueenSquare.posX == greyQueenSquare.posX) {
                                redQueenSquare.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY + 70 &&
                           redPawnsBase[s].posX == greyQueenSquare.posX - 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY + 70 &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX - 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquare.posY + 70 &&
                       redQueenSquare.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redRook1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redRook2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX - 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY + 70 &&
                       greyBishop1Square.posX == greyQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY + 70 &&
                       greyBishop2Square.posX == greyQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquare.posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquare.posY = greyQueenSquare.posY + 70;
                        greyQueenSquare.posX = greyQueenSquare.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveGreyQueenDiagonally(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquare.posY = greyQueenSquare.posY + 70;
                    greyQueenSquare.posX = greyQueenSquare.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquare.posY &&
                           greyBishop1Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquare.posY &&
                           greyBishop2Square.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquare.posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook1Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquare.posY &&
                           greyRook2Rectangle1.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquare.posY &&
                           greyKingSquare.posX == greyQueenSquare.posX) {
                            greyQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redPawnsBase[s].posY == greyQueenSquare.posY &&
                               redPawnsBase[s].posX == greyQueenSquare.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight1Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquare.posY &&
                               redKnight2Rectangle1.posX == greyQueenSquare.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquare.posY &&
                               redBishop1Square.posX == greyQueenSquare.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquare.posY &&
                               redBishop2Square.posX == greyQueenSquare.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquare.posY &&
                               redRook1Rectangle1.posX == greyQueenSquare.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquare.posY &&
                               redRook2Rectangle1.posX == greyQueenSquare.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redQueenSquare.posY == greyQueenSquare.posY &&
                               redQueenSquare.posX == greyQueenSquare.posX) {
                                redQueenSquare.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyQueenSquare.posY + 70 &&
                           redPawnsBase[s].posX == greyQueenSquare.posX + 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquare.posY + 70 &&
                           greyPawnsBase[s].posX == greyQueenSquare.posX + 70) {
                            greyQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquare.posY + 70 &&
                       redQueenSquare.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redRook1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redRook2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop1Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquare.posY + 70 &&
                       redBishop2Square.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquare.posY + 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquare.posX + 70) {
                        greyQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquare.posY + 70 &&
                       greyBishop1Square.posX == greyQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquare.posY + 70 &&
                       greyBishop2Square.posX == greyQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquare.posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquare.posY = greyQueenSquare.posY + 70;
                        greyQueenSquare.posX = greyQueenSquare.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveRedQueenDiagonally(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(greyKnight1Rectangle1.posX == redQueenSquare.posX &&
       greyKnight1Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redQueenSquare.posX &&
       greyKnight2Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redQueenSquare.posX &&
       greyBishop1Square.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redQueenSquare.posX &&
       greyBishop2Square.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redQueenSquare.posX &&
       greyRook1Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redQueenSquare.posX &&
       greyRook2Rectangle1.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquare.posX &&
       greyQueenSquare.posY == redQueenSquare.posY) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redQueenSquare.posX &&
           greyPawnsBase[g].posY == redQueenSquare.posY) {
            redQueenSquare.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        redQueenSquare.failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        redQueenSquare.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveRedQueenDiagonally(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquare.posY = redQueenSquare.posY - 70;
                    redQueenSquare.posX = redQueenSquare.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY &&
                           redPawnsBase[s].posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquare.posY &&
                           redBishop1Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquare.posY &&
                           redBishop2Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                           redKnight1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                           redKnight2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                           redRook1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                           redRook2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquare.posY &&
                           redKingSquare.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                               greyPawnsBase[s].posX == redQueenSquare.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                               greyRook1Rectangle1.posX == redQueenSquare.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                               greyRook2Rectangle1.posX == redQueenSquare.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY - 70 &&
                           redPawnsBase[s].posX == redQueenSquare.posX - 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquare.posY - 70 &&
                           greyPawnsBase[s].posX == redQueenSquare.posX - 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                       redBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                       redBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                       redBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                       redBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                       redBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                       redBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                       redBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                       redBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquare.posY + 70 &&
                       greyQueenSquare.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquare.posY = redQueenSquare.posY - 70;
                        redQueenSquare.posX = redQueenSquare.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveRedQueenDiagonally(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquare.posY = redQueenSquare.posY - 70;
                    redQueenSquare.posX = redQueenSquare.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY &&
                           redPawnsBase[s].posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquare.posY &&
                           redBishop1Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquare.posY &&
                           redBishop2Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                           redKnight1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                           redKnight2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                           redRook1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                           redRook2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquare.posY &&
                           redKingSquare.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                               greyPawnsBase[s].posX == redQueenSquare.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                               greyRook1Rectangle1.posX == redQueenSquare.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                               greyRook2Rectangle1.posX == redQueenSquare.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY - 70 &&
                           redPawnsBase[s].posX == redQueenSquare.posX + 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquare.posY - 70 &&
                           greyPawnsBase[s].posX == redQueenSquare.posX + 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                       redBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                       redBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redRook1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redRook2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY - 70 &&
                       redBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY - 70 &&
                       redBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyRook1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyRook2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquare.posY - 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquare.posY + 70 &&
                       greyQueenSquare.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquare.posY = redQueenSquare.posY - 70;
                        redQueenSquare.posX = redQueenSquare.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveRedQueenDiagonally(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquare.posY = redQueenSquare.posY + 70;
                    redQueenSquare.posX = redQueenSquare.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY &&
                           redPawnsBase[s].posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquare.posY &&
                           redBishop1Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquare.posY &&
                           redBishop2Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                           redKnight1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                           redKnight2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                           redRook1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                           redRook2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquare.posY &&
                           redKingSquare.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                               greyPawnsBase[s].posX == redQueenSquare.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                               greyRook1Rectangle1.posX == redQueenSquare.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                               greyRook2Rectangle1.posX == redQueenSquare.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY + 70 &&
                           redPawnsBase[s].posX == redQueenSquare.posX - 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquare.posY + 70 &&
                           greyPawnsBase[s].posX == redQueenSquare.posX - 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY + 70 &&
                       redBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY + 70 &&
                       redBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY + 70 &&
                       redBishop1Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY + 70 &&
                       redBishop2Square.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyRook1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyRook2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquare.posX - 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquare.posY + 70 &&
                       greyQueenSquare.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquare.posY = redQueenSquare.posY + 70;
                        redQueenSquare.posX = redQueenSquare.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveRedQueenDiagonally(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquare.posY = redQueenSquare.posY + 70;
                    redQueenSquare.posX = redQueenSquare.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY &&
                           redPawnsBase[s].posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquare.posY &&
                           redBishop1Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquare.posY &&
                           redBishop2Square.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquare.posY &&
                           redKnight1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquare.posY &&
                           redKnight2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquare.posY &&
                           redRook1Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquare.posY &&
                           redRook2Rectangle1.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquare.posY &&
                           redKingSquare.posX == redQueenSquare.posX) {
                            redQueenSquare.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyPawnsBase[s].posY == redQueenSquare.posY &&
                               greyPawnsBase[s].posX == redQueenSquare.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquare.posY &&
                               greyRook1Rectangle1.posX == redQueenSquare.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquare.posY &&
                               greyRook2Rectangle1.posX == redQueenSquare.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquare.posY &&
                               greyBishop1Square.posX == redQueenSquare.posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquare.posY &&
                               greyBishop2Square.posX == redQueenSquare.posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight1Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquare.posY &&
                               greyKnight2Rectangle1.posX == redQueenSquare.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquare.posY + 70 &&
                           redPawnsBase[s].posX == redQueenSquare.posX + 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquare.posY + 70 &&
                           greyPawnsBase[s].posX == redQueenSquare.posX + 70) {
                            redQueenSquare.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY + 70 &&
                       redBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY + 70 &&
                       redBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redRook1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redRook2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redKnight1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       redKnight2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquare.posY + 70 &&
                       redBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquare.posY + 70 &&
                       redBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyRook1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyRook2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquare.posY + 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop1Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquare.posY + 70 &&
                       greyBishop2Square.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquare.posY + 70 &&
                       greyQueenSquare.posX == redQueenSquare.posX + 70) {
                        redQueenSquare.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquare.posY = redQueenSquare.posY + 70;
                        redQueenSquare.posX = redQueenSquare.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquare.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveRedQueenDiagonallyK(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2, int k) {

    for(int p=0; p<8; p++) {
        if(p != k &&
           redQueenSquareK[p].posX == redQueenSquareK[k].posX &&
           redQueenSquareK[p].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
        if(p != k &&
           greyQueenSquareK[p].posX == redQueenSquareK[k].posX &&
           greyQueenSquareK[p].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(redQueenSquare.posX == redQueenSquareK[k].posX &&
       redQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquareK[k].posX &&
       greyQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redQueenSquareK[k].posX &&
       greyKnight1Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redQueenSquareK[k].posX &&
       greyKnight2Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redQueenSquareK[k].posX &&
       greyBishop1Square.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redQueenSquareK[k].posX &&
       greyBishop2Square.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redQueenSquareK[k].posX &&
       greyRook1Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redQueenSquareK[k].posX &&
       greyRook2Rectangle1.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redQueenSquareK[k].posX &&
       greyQueenSquare.posY == redQueenSquareK[k].posY) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redQueenSquareK[k].posX &&
           greyPawnsBase[g].posY == redQueenSquareK[k].posY) {
            redQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        redQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        redQueenSquareK[k].failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveRedQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquareK[k].posY = redQueenSquareK[k].posY - 70;
                    redQueenSquareK[k].posX = redQueenSquareK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX &&
                               redQueenSquareK[p].posY == redQueenSquareK[k].posY) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(redQueenSquare.posX == redQueenSquareK[k].posX &&
                           redQueenSquare.posY == redQueenSquareK[k].posY) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                           redBishop1Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                           redBishop2Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquareK[k].posY &&
                           redKingSquare.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(greyQueenSquareK[r].posY == redQueenSquareK[k].posY &&
                                   greyQueenSquareK[r].posX == redQueenSquareK[k].posX) {
                                    greyQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                               greyQueenSquare.posX == redQueenSquareK[k].posX) {
                                greyQueenSquare.posX = 1300;
                            }
                            if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                               greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY - 70 &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX - 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY - 70 &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX - 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX - 70 &&
                               redQueenSquareK[p].posY == redQueenSquareK[k].posY - 70) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               greyQueenSquareK[p].posX == redQueenSquareK[k].posX - 70 &&
                               greyQueenSquareK[p].posY == redQueenSquareK[k].posY - 70) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                    }
                    if(redQueenSquare.posX == redQueenSquareK[k].posX - 70 &&
                       redQueenSquare.posY == redQueenSquareK[k].posY - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyQueenSquare.posX == redQueenSquareK[k].posX - 70 &&
                       greyQueenSquare.posY == redQueenSquareK[k].posY - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquareK[k].posY = redQueenSquareK[k].posY - 70;
                        redQueenSquareK[k].posX = redQueenSquareK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveRedQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquareK[k].posY = redQueenSquareK[k].posY - 70;
                    redQueenSquareK[k].posX = redQueenSquareK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX &&
                               redQueenSquareK[p].posY == redQueenSquareK[k].posY) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(redQueenSquare.posX == redQueenSquareK[k].posX &&
                           redQueenSquare.posY == redQueenSquareK[k].posY) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                           redBishop1Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                           redBishop2Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquareK[k].posY &&
                           redKingSquare.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(greyQueenSquareK[r].posY == redQueenSquareK[k].posY &&
                                   greyQueenSquareK[r].posX == redQueenSquareK[k].posX) {
                                    greyQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                               greyQueenSquare.posX == redQueenSquareK[k].posX) {
                                greyQueenSquare.posX = 1300;
                            }
                            if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                               greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               redQueenSquareK[h].posY == redQueenSquareK[k].posY - 70 &&
                               redQueenSquareK[h].posX == redQueenSquareK[k].posX + 70) {
                                redQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               greyQueenSquareK[h].posY == redQueenSquareK[k].posY - 70 &&
                               greyQueenSquareK[h].posX == redQueenSquareK[k].posX + 70) {
                                redQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(redQueenSquare.posY == redQueenSquareK[k].posY - 70 &&
                           redQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY - 70 &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY - 70 &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyRook1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyRook2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY - 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquareK[k].posY = redQueenSquareK[k].posY - 70;
                        redQueenSquareK[k].posX = redQueenSquareK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveRedQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquareK[k].posY = redQueenSquareK[k].posY + 70;
                    redQueenSquareK[k].posX = redQueenSquareK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        for(int p=0; p<8; p++) {
                            if(redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                           redQueenSquare.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                           redBishop1Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                           redBishop2Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquareK[k].posY &&
                           redKingSquare.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(greyQueenSquareK[r].posY == redQueenSquareK[k].posY &&
                                   greyQueenSquareK[r].posX == redQueenSquareK[k].posX) {
                                    greyQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                               greyQueenSquare.posX == redQueenSquareK[k].posX) {
                                greyQueenSquare.posX = 1300;
                            }
                            if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                               greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               redQueenSquareK[p].posY == redQueenSquareK[k].posY + 70 &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX - 70) {
                                redQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                            if(p != k &&
                               greyQueenSquareK[p].posY == redQueenSquareK[k].posY + 70 &&
                               greyQueenSquareK[p].posX == redQueenSquareK[k].posX - 70) {
                                redQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY + 70 &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX - 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY + 70 &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX - 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       redQueenSquare.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyRook1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyRook2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquareK[k].posX - 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquareK[k].posY = redQueenSquareK[k].posY + 70;
                        redQueenSquareK[k].posX = redQueenSquareK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveRedQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redQueenSquareK[k].posY = redQueenSquareK[k].posY + 70;
                    redQueenSquareK[k].posX = redQueenSquareK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               redQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                               redQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               greyQueenSquareK[p].posY == redQueenSquareK[k].posY &&
                               greyQueenSquareK[p].posX == redQueenSquareK[k].posX) {
                                redQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(redQueenSquare.posY == redQueenSquareK[k].posY &&
                           redQueenSquare.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redQueenSquareK[k].posY &&
                           redBishop1Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redQueenSquareK[k].posY &&
                           redBishop2Square.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                           redRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redQueenSquareK[k].posY &&
                           redKingSquare.posX == redQueenSquareK[k].posX) {
                            redQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(greyQueenSquareK[r].posY == redQueenSquareK[k].posY &&
                                   greyQueenSquareK[r].posX == redQueenSquareK[k].posX) {
                                    greyQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(greyQueenSquare.posY == redQueenSquareK[k].posY &&
                               greyQueenSquare.posX == redQueenSquareK[k].posX) {
                                greyQueenSquare.posX = 1300;
                            }
                            if(greyPawnsBase[s].posY == redQueenSquareK[k].posY &&
                               greyPawnsBase[s].posX == redQueenSquareK[k].posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }
                            if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyRook2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                            if(greyBishop1Square.posY == redQueenSquareK[k].posY &&
                               greyBishop1Square.posX == redQueenSquareK[k].posX) {
                                greyBishop1Square.posX = 1300;
                            }
                            if(greyBishop2Square.posY == redQueenSquareK[k].posY &&
                               greyBishop2Square.posX == redQueenSquareK[k].posX) {
                                greyBishop2Square.posX = 1300;
                            }
                            if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight1Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }
                            if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY &&
                               greyKnight2Rectangle1.posX == redQueenSquareK[k].posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redQueenSquareK[k].posY + 70 &&
                           redPawnsBase[s].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redQueenSquareK[k].posY + 70 &&
                           greyPawnsBase[s].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           redQueenSquareK[s].posY == redQueenSquareK[k].posY + 70 &&
                           redQueenSquareK[s].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           greyQueenSquareK[s].posY == redQueenSquareK[k].posY + 70 &&
                           greyQueenSquareK[s].posX == redQueenSquareK[k].posX + 70) {
                            redQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       redQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redRook1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redRook2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redKnight1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       redKnight2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyRook1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyRook2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyKnight1Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redQueenSquareK[k].posY + 70 &&
                       greyKnight2Rectangle1.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == redQueenSquareK[k].posX + 70) {
                        redQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redQueenSquareK[k].posY = redQueenSquareK[k].posY + 70;
                        redQueenSquareK[k].posX = redQueenSquareK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveGreyQueenDiagonallyK(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2, int k) {

    for(int p=0; p<8; p++) {
        if(p != k &&
           greyQueenSquareK[p].posX == greyQueenSquareK[k].posX &&
           greyQueenSquareK[p].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
        if(p != k &&
           greyQueenSquareK[p].posX == greyQueenSquareK[k].posX &&
           greyQueenSquareK[p].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(redQueenSquare.posX == greyQueenSquareK[k].posX &&
       redQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == greyQueenSquareK[k].posX &&
       greyQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redKnight1Rectangle1.posX == greyQueenSquareK[k].posX &&
       redKnight1Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyQueenSquareK[k].posX &&
       redKnight2Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyQueenSquareK[k].posX &&
       redBishop1Square.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyQueenSquareK[k].posX &&
       redBishop2Square.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyQueenSquareK[k].posX &&
       redRook1Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyQueenSquareK[k].posX &&
       redRook2Rectangle1.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyQueenSquareK[k].posX &&
       redQueenSquare.posY == greyQueenSquareK[k].posY) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyQueenSquareK[k].posX &&
           redPawnsBase[g].posY == greyQueenSquareK[k].posY) {
            greyQueenSquareK[k].failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos1 == 0) {
        greyQueenSquareK[k].failedpath = TRUE;
        return TRUE;
    }
    boolean fail = FALSE;
    if(pos1 == ps1) {
        fail = FALSE;
    } else if(pos1 == -ps1) {
        fail = FALSE;
    } else {
        fail = TRUE;
        greyQueenSquareK[k].failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveGreyQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquareK[k].posY = greyQueenSquareK[k].posY - 70;
                    greyQueenSquareK[k].posX = greyQueenSquareK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(greyQueenSquare.posX == greyQueenSquareK[k].posX &&
                           greyQueenSquare.posY == greyQueenSquareK[k].posY) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                           greyKingSquare.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(redQueenSquareK[r].posY == greyQueenSquareK[k].posY &&
                                   redQueenSquareK[r].posX == greyQueenSquareK[k].posX) {
                                    redQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                               redQueenSquare.posX == greyQueenSquareK[k].posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                               redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY - 70 &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX - 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY - 70 &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX - 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX - 70 &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY - 70) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX - 70 &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY - 70) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                    }
                    if(redQueenSquare.posX == greyQueenSquareK[k].posX - 70 &&
                       redQueenSquare.posY == greyQueenSquareK[k].posY - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyQueenSquare.posX == greyQueenSquareK[k].posX - 70 &&
                       greyQueenSquare.posY == greyQueenSquareK[k].posY - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquareK[k].posY = greyQueenSquareK[k].posY - 70;
                        greyQueenSquareK[k].posX = greyQueenSquareK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveGreyQueenDiagonallyK(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquareK[k].posY = greyQueenSquareK[k].posY - 70;
                    greyQueenSquareK[k].posX = greyQueenSquareK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(greyQueenSquare.posX == greyQueenSquareK[k].posX &&
                           greyQueenSquare.posY == greyQueenSquareK[k].posY) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                           greyKingSquare.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(redQueenSquareK[r].posY == greyQueenSquareK[k].posY &&
                                   redQueenSquareK[r].posX == greyQueenSquareK[k].posX) {
                                    redQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                               redQueenSquare.posX == greyQueenSquareK[k].posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                               redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               greyQueenSquareK[h].posY == greyQueenSquareK[k].posY - 70 &&
                               greyQueenSquareK[h].posX == greyQueenSquareK[k].posX + 70) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        for(int h=0; h<8; h++) {
                            if(h != k &&
                               greyQueenSquareK[h].posY == greyQueenSquareK[k].posY - 70 &&
                               greyQueenSquareK[h].posX == greyQueenSquareK[k].posX + 70) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(redQueenSquare.posY == greyQueenSquareK[k].posY - 70 &&
                           redQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY - 70 &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY - 70 &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY - 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY - 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquareK[k].posY = greyQueenSquareK[k].posY - 70;
                        greyQueenSquareK[k].posX = greyQueenSquareK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveGreyQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquareK[k].posY = greyQueenSquareK[k].posY + 70;
                    greyQueenSquareK[k].posX = greyQueenSquareK[k].posX - 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                           greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                           greyKingSquare.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(redQueenSquareK[r].posY == greyQueenSquareK[k].posY &&
                                   redQueenSquareK[r].posX == greyQueenSquareK[k].posX) {
                                    redQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                               redQueenSquare.posX == greyQueenSquareK[k].posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                               redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY + 70 &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX - 70) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                            if(p != k &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY + 70 &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX - 70) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                flag = TRUE;
                            }
                        }
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY + 70 &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX - 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY + 70 &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX - 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX - 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquareK[k].posY = greyQueenSquareK[k].posY + 70;
                        greyQueenSquareK[k].posX = greyQueenSquareK[k].posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveGreyQueenDiagonallyK(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2, k);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyQueenSquareK[k].posY = greyQueenSquareK[k].posY + 70;
                    greyQueenSquareK[k].posX = greyQueenSquareK[k].posX + 70;

                    for(int s=0; s<8; s++) {
                        for(int p=0; p<8; p++) {
                            if(p != k &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                            if(p != k &&
                               greyQueenSquareK[p].posY == greyQueenSquareK[k].posY &&
                               greyQueenSquareK[p].posX == greyQueenSquareK[k].posX) {
                                greyQueenSquareK[k].failedpath = TRUE;
                                return TRUE;
                            }
                        }
                        if(greyQueenSquare.posY == greyQueenSquareK[k].posY &&
                           greyQueenSquare.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop1Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyQueenSquareK[k].posY &&
                           greyBishop2Square.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                           greyRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyQueenSquareK[k].posY &&
                           greyKingSquare.posX == greyQueenSquareK[k].posX) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            for(int r=0; r<8; r++) {
                                if(redQueenSquareK[r].posY == greyQueenSquareK[k].posY &&
                                   redQueenSquareK[r].posX == greyQueenSquareK[k].posX) {
                                    redQueenSquareK[r].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyQueenSquareK[k].posY &&
                               redQueenSquare.posX == greyQueenSquareK[k].posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyQueenSquareK[k].posY &&
                               redPawnsBase[s].posX == greyQueenSquareK[k].posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redRook2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                            if(redBishop1Square.posY == greyQueenSquareK[k].posY &&
                               redBishop1Square.posX == greyQueenSquareK[k].posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyQueenSquareK[k].posY &&
                               redBishop2Square.posX == greyQueenSquareK[k].posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight1Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY &&
                               redKnight2Rectangle1.posX == greyQueenSquareK[k].posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyQueenSquareK[k].posY + 70 &&
                           redPawnsBase[s].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyQueenSquareK[k].posY + 70 &&
                           greyPawnsBase[s].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           greyQueenSquareK[s].posY == greyQueenSquareK[k].posY + 70 &&
                           greyQueenSquareK[s].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(s != k &&
                           greyQueenSquareK[s].posY == greyQueenSquareK[k].posY + 70 &&
                           greyQueenSquareK[s].posX == greyQueenSquareK[k].posX + 70) {
                            greyQueenSquareK[k].failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       redQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redRook1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redRook2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redKnight1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       redKnight2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       redBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyRook1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyRook2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyKnight1Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyQueenSquareK[k].posY + 70 &&
                       greyKnight2Rectangle1.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop1Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyQueenSquareK[k].posY + 70 &&
                       greyBishop2Square.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == greyQueenSquareK[k].posY + 70 &&
                       greyQueenSquare.posX == greyQueenSquareK[k].posX + 70) {
                        greyQueenSquareK[k].failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyQueenSquareK[k].posY = greyQueenSquareK[k].posY + 70;
                        greyQueenSquareK[k].posX = greyQueenSquareK[k].posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyQueenSquareK[k].failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveGreyBishop1(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(redKnight1Rectangle1.posX == greyBishop1Square.posX &&
       redKnight1Rectangle1.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyBishop1Square.posX &&
       redKnight2Rectangle1.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyBishop1Square.posX &&
       redBishop1Square.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyBishop1Square.posX &&
       redBishop2Square.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyBishop1Square.posX &&
       redRook1Rectangle1.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyBishop1Square.posX &&
       redRook2Rectangle1.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyBishop1Square.posX &&
       redQueenSquare.posY == greyBishop1Square.posY) {
        greyBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyBishop1Square.posX &&
           redPawnsBase[g].posY == greyBishop1Square.posY) {
            greyBishop1Square.failedpath = TRUE;
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
        greyBishop1Square.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveGreyBishop1(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop1Square.posY = greyBishop1Square.posY - 70;
                    greyBishop1Square.posX = greyBishop1Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyBishop1Square.posY &&
                           greyBishop2Square.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop1Square.posY &&
                           greyKingSquare.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop1Square.posY &&
                               redBishop1Square.posX == greyBishop1Square.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyBishop1Square.posY &&
                               redPawnsBase[s].posX == greyBishop1Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop1Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop1Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop1Square.posY &&
                               redQueenSquare.posX == greyBishop1Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop1Square.posY &&
                               redRook1Rectangle1.posX == greyBishop1Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop1Square.posY &&
                               redRook2Rectangle1.posX == greyBishop1Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop1Square.posY - 70 &&
                           redPawnsBase[s].posX == greyBishop1Square.posX - 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY - 70 &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX - 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop1Square.posY - 70 &&
                       redQueenSquare.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop1Square.posY - 70 &&
                       redBishop2Square.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop1Square.posY - 70 &&
                       redBishop1Square.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redRook1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redRook2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redKnight1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redKnight2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyBishop1Square.posY - 70 &&
                       greyBishop2Square.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyRook1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyRook2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop1Square.posY = greyBishop1Square.posY - 70;
                        greyBishop1Square.posX = greyBishop1Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveGreyBishop1(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop1Square.posY = greyBishop1Square.posY - 70;
                    greyBishop1Square.posX = greyBishop1Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyBishop1Square.posY &&
                           greyBishop2Square.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop1Square.posY &&
                           greyKingSquare.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop1Square.posY &&
                               redBishop1Square.posX == greyBishop1Square.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyBishop1Square.posY &&
                               redPawnsBase[s].posX == greyBishop1Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop1Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop1Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop1Square.posY &&
                               redQueenSquare.posX == greyBishop1Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop1Square.posY &&
                               redRook1Rectangle1.posX == greyBishop1Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop1Square.posY &&
                               redRook2Rectangle1.posX == greyBishop1Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop1Square.posY - 70 &&
                           redPawnsBase[s].posX == greyBishop1Square.posX + 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY - 70 &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX + 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop1Square.posY - 70 &&
                       redQueenSquare.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop1Square.posY - 70 &&
                       redBishop2Square.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop1Square.posY - 70 &&
                       redBishop1Square.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redRook1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redRook2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redKnight1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       redKnight2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyBishop1Square.posY - 70 &&
                       greyBishop2Square.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyRook1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyRook2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop1Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop1Square.posY = greyBishop1Square.posY - 70;
                        greyBishop1Square.posX = greyBishop1Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveGreyBishop1(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop1Square.posY = greyBishop1Square.posY + 70;
                    greyBishop1Square.posX = greyBishop1Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyBishop1Square.posY &&
                           greyBishop2Square.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop1Square.posY &&
                           greyKingSquare.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop1Square.posY &&
                               redBishop1Square.posX == greyBishop1Square.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyBishop1Square.posY &&
                               redPawnsBase[s].posX == greyBishop1Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop1Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop1Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop1Square.posY &&
                               redQueenSquare.posX == greyBishop1Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop1Square.posY &&
                               redRook1Rectangle1.posX == greyBishop1Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop1Square.posY &&
                               redRook2Rectangle1.posX == greyBishop1Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop1Square.posY + 70 &&
                           redPawnsBase[s].posX == greyBishop1Square.posX - 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY + 70 &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX - 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop1Square.posY + 70 &&
                       redQueenSquare.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop1Square.posY + 70 &&
                       redBishop1Square.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop1Square.posY + 70 &&
                       redBishop2Square.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redRook1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redRook2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redKnight1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redKnight2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyBishop1Square.posY + 70 &&
                       greyBishop2Square.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyRook1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyRook2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == greyBishop1Square.posX - 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop1Square.posY = greyBishop1Square.posY + 70;
                        greyBishop1Square.posX = greyBishop1Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveGreyBishop1(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop1Square.posY = greyBishop1Square.posY + 70;
                    greyBishop1Square.posX = greyBishop1Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop2Square.posY == greyBishop1Square.posY &&
                           greyBishop2Square.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop1Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop1Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop1Square.posY &&
                           greyKingSquare.posX == greyBishop1Square.posX) {
                            greyBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop1Square.posY &&
                               redBishop1Square.posX == greyBishop1Square.posX) {
                                redBishop1Square.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redPawnsBase[s].posY == greyBishop1Square.posY &&
                               redPawnsBase[s].posX == greyBishop1Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop1Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop1Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop1Square.posY &&
                               redQueenSquare.posX == greyBishop1Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop1Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop1Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop1Square.posY &&
                               redBishop2Square.posX == greyBishop1Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop1Square.posY &&
                               redRook1Rectangle1.posX == greyBishop1Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop1Square.posY &&
                               redRook2Rectangle1.posX == greyBishop1Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop1Square.posY + 70 &&
                           redPawnsBase[s].posX == greyBishop1Square.posX + 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop1Square.posY + 70 &&
                           greyPawnsBase[s].posX == greyBishop1Square.posX + 70) {
                            greyBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop1Square.posY + 70 &&
                       redQueenSquare.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop1Square.posY + 70 &&
                       redBishop1Square.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop1Square.posY + 70 &&
                       redBishop2Square.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redRook1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redRook2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redKnight1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       redKnight2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == greyBishop1Square.posY + 70 &&
                       greyBishop2Square.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyRook1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyRook2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop1Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == greyBishop1Square.posX + 70) {
                        greyBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop1Square.posY = greyBishop1Square.posY + 70;
                        greyBishop1Square.posX = greyBishop1Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveGreyBishop2(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(redKnight1Rectangle1.posX == greyBishop2Square.posX &&
       redKnight1Rectangle1.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyBishop2Square.posX &&
       redKnight2Rectangle1.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyBishop2Square.posX &&
       redBishop1Square.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyBishop2Square.posX &&
       redBishop2Square.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyBishop2Square.posX &&
       redRook1Rectangle1.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyBishop2Square.posX &&
       redRook2Rectangle1.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyBishop2Square.posX &&
       redQueenSquare.posY == greyBishop2Square.posY) {
        greyBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyBishop2Square.posX &&
           redPawnsBase[g].posY == greyBishop2Square.posY) {
            greyBishop2Square.failedpath = TRUE;
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
        greyBishop2Square.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveGreyBishop2(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop2Square.posY = greyBishop2Square.posY - 70;
                    greyBishop2Square.posX = greyBishop2Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyBishop2Square.posY &&
                           greyBishop1Square.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop2Square.posY &&
                           greyKingSquare.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop2Square.posY &&
                               redBishop1Square.posX == greyBishop2Square.posX) {
                                redBishop1Square.posX = 1300;
                            }

                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }

                            if(redPawnsBase[s].posY == greyBishop2Square.posY &&
                               redPawnsBase[s].posX == greyBishop2Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop2Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop2Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop2Square.posY &&
                               redQueenSquare.posX == greyBishop2Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop2Square.posY &&
                               redRook1Rectangle1.posX == greyBishop2Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop2Square.posY &&
                               redRook2Rectangle1.posX == greyBishop2Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop2Square.posY - 70 &&
                           redPawnsBase[s].posX == greyBishop2Square.posX - 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY - 70 &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX - 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop2Square.posY - 70 &&
                       redQueenSquare.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop2Square.posY - 70 &&
                       redBishop2Square.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop2Square.posY - 70 &&
                       redBishop1Square.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redRook1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redRook2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redKnight1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redKnight2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyBishop2Square.posY - 70 &&
                       greyBishop1Square.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyRook1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyRook2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop2Square.posY = greyBishop2Square.posY - 70;
                        greyBishop2Square.posX = greyBishop2Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveGreyBishop2(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop2Square.posY = greyBishop2Square.posY - 70;
                    greyBishop2Square.posX = greyBishop2Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyBishop2Square.posY &&
                           greyBishop1Square.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop2Square.posY &&
                           greyKingSquare.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop2Square.posY &&
                               redBishop1Square.posX == greyBishop2Square.posX) {
                                redBishop1Square.posX = 1300;
                            }

                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }

                            if(redPawnsBase[s].posY == greyBishop2Square.posY &&
                               redPawnsBase[s].posX == greyBishop2Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop2Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop2Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop2Square.posY &&
                               redQueenSquare.posX == greyBishop2Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop2Square.posY &&
                               redRook1Rectangle1.posX == greyBishop2Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop2Square.posY &&
                               redRook2Rectangle1.posX == greyBishop2Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop2Square.posY - 70 &&
                           redPawnsBase[s].posX == greyBishop2Square.posX + 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY - 70 &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX + 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop2Square.posY - 70 &&
                       redQueenSquare.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop2Square.posY - 70 &&
                       redBishop2Square.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop2Square.posY - 70 &&
                       redBishop1Square.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redRook1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redRook2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redKnight1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       redKnight2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyBishop2Square.posY - 70 &&
                       greyBishop1Square.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyRook1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyRook2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop2Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop2Square.posY = greyBishop2Square.posY - 70;
                        greyBishop2Square.posX = greyBishop2Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveGreyBishop2(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop2Square.posY = greyBishop2Square.posY + 70;
                    greyBishop2Square.posX = greyBishop2Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyBishop2Square.posY &&
                           greyBishop1Square.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop2Square.posY &&
                           greyKingSquare.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop2Square.posY &&
                               redBishop1Square.posX == greyBishop2Square.posX) {
                                redBishop1Square.posX = 1300;
                            }

                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }

                            if(redPawnsBase[s].posY == greyBishop2Square.posY &&
                               redPawnsBase[s].posX == greyBishop2Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop2Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop2Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop2Square.posY &&
                               redQueenSquare.posX == greyBishop2Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop2Square.posY &&
                               redRook1Rectangle1.posX == greyBishop2Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop2Square.posY &&
                               redRook2Rectangle1.posX == greyBishop2Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop2Square.posY + 70 &&
                           redPawnsBase[s].posX == greyBishop2Square.posX - 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY + 70 &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX - 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop2Square.posY + 70 &&
                       redQueenSquare.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop2Square.posY + 70 &&
                       redBishop1Square.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop2Square.posY + 70 &&
                       redBishop2Square.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redRook1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redRook2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redKnight1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redKnight2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyBishop2Square.posY + 70 &&
                       greyBishop1Square.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyRook1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyRook2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == greyBishop2Square.posX - 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop2Square.posY = greyBishop2Square.posY + 70;
                        greyBishop2Square.posX = greyBishop2Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveGreyBishop2(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    greyBishop2Square.posY = greyBishop2Square.posY + 70;
                    greyBishop2Square.posX = greyBishop2Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyBishop1Square.posY == greyBishop2Square.posY &&
                           greyBishop1Square.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight1Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKnight2Rectangle1.posY == greyBishop2Square.posY &&
                           greyKnight2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook1Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook1Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(greyKingSquare.posY == greyBishop2Square.posY &&
                           greyKingSquare.posX == greyBishop2Square.posX) {
                            greyBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(redBishop1Square.posY == greyBishop2Square.posY &&
                               redBishop1Square.posX == greyBishop2Square.posX) {
                                redBishop1Square.posX = 1300;
                            }

                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }

                            if(redPawnsBase[s].posY == greyBishop2Square.posY &&
                               redPawnsBase[s].posX == greyBishop2Square.posX) {
                                redPawnsBase[s].posX = 1300;
                            }
                            for(int z=0; z<8; z++) {
                                if(redQueenSquareK[z].posY == greyBishop2Square.posY &&
                                   redQueenSquareK[z].posX == greyBishop2Square.posX) {
                                    redQueenSquareK[z].posX = 1300;
                                }
                            }
                            if(redQueenSquare.posY == greyBishop2Square.posY &&
                               redQueenSquare.posX == greyBishop2Square.posX) {
                                redQueenSquare.posX = 1300;
                            }
                            if(redKnight1Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight1Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight1Rectangle1.posX = 1300;
                            }
                            if(redKnight2Rectangle1.posY == greyBishop2Square.posY &&
                               redKnight2Rectangle1.posX == greyBishop2Square.posX) {
                                redKnight2Rectangle1.posX = 1300;
                            }
                            if(redBishop2Square.posY == greyBishop2Square.posY &&
                               redBishop2Square.posX == greyBishop2Square.posX) {
                                redBishop2Square.posX = 1300;
                            }
                            if(redRook1Rectangle1.posY == greyBishop2Square.posY &&
                               redRook1Rectangle1.posX == greyBishop2Square.posX) {
                                redRook1Rectangle1.posX = 1300;
                            }
                            if(redRook2Rectangle1.posY == greyBishop2Square.posY &&
                               redRook2Rectangle1.posX == greyBishop2Square.posX) {
                                redRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == greyBishop2Square.posY + 70 &&
                           redPawnsBase[s].posX == greyBishop2Square.posX + 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == greyBishop2Square.posY + 70 &&
                           greyPawnsBase[s].posX == greyBishop2Square.posX + 70) {
                            greyBishop2Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redQueenSquare.posY == greyBishop2Square.posY + 70 &&
                       redQueenSquare.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == greyBishop2Square.posY + 70 &&
                       redBishop1Square.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == greyBishop2Square.posY + 70 &&
                       redBishop2Square.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redRook1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redRook2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redKnight1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       redKnight2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == greyBishop2Square.posY + 70 &&
                       greyBishop1Square.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyRook1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyRook2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyBishop2Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == greyBishop2Square.posX + 70) {
                        greyBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        greyBishop2Square.posY = greyBishop2Square.posY + 70;
                        greyBishop2Square.posX = greyBishop2Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                greyBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveRedBishop1(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(greyKnight1Rectangle1.posX == redBishop1Square.posX &&
       greyKnight1Rectangle1.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redBishop1Square.posX &&
       greyKnight2Rectangle1.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redBishop1Square.posX &&
       greyBishop1Square.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redBishop1Square.posX &&
       greyBishop2Square.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redBishop1Square.posX &&
       greyRook1Rectangle1.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redBishop1Square.posX &&
       greyRook2Rectangle1.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redBishop1Square.posX &&
       greyQueenSquare.posY == redBishop1Square.posY) {
        redBishop1Square.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redBishop1Square.posX &&
           greyPawnsBase[g].posY == redBishop1Square.posY) {
            redBishop1Square.failedpath = TRUE;
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
        redBishop1Square.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveRedBishop1(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop1Square.posY = redBishop1Square.posY - 70;
                    redBishop1Square.posX = redBishop1Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY &&
                           redPawnsBase[s].posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }

                        if(redBishop2Square.posY == redBishop1Square.posY &&
                           redBishop2Square.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop1Square.posY &&
                           redKnight1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop1Square.posY &&
                           redKnight2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop1Square.posY &&
                           redRook1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop1Square.posY &&
                           redRook2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop1Square.posY &&
                           redKingSquare.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }

                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop1Square.posY &&
                               greyBishop1Square.posX == redBishop1Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop1Square.posY &&
                               greyBishop2Square.posX == redBishop1Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop1Square.posY &&
                               greyPawnsBase[s].posX == redBishop1Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop1Square.posY &&
                               greyRook1Rectangle1.posX == redBishop1Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                               greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY - 70 &&
                           redPawnsBase[s].posX == redBishop1Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop1Square.posY - 70 &&
                           greyPawnsBase[s].posX == redBishop1Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop2Square.posY == redBishop1Square.posY - 70 &&
                       redBishop2Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redRook1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redRook2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redKnight1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redKnight2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop1Square.posY - 70 &&
                       greyBishop1Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redBishop1Square.posY - 70 &&
                       redBishop2Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyRook1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyRook2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop1Square.posY - 70 &&
                       greyQueenSquare.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop1Square.posY - 70 &&
                       greyBishop1Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop1Square.posY - 70 &&
                       greyBishop2Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop1Square.posY = redBishop1Square.posY - 70;
                        redBishop1Square.posX = redBishop1Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveRedBishop1(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop1Square.posY = redBishop1Square.posY - 70;
                    redBishop1Square.posX = redBishop1Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY &&
                           redPawnsBase[s].posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redBishop1Square.posY &&
                           redBishop2Square.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop1Square.posY &&
                           redKnight1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop1Square.posY &&
                           redKnight2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop1Square.posY &&
                           redRook1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop1Square.posY &&
                           redRook2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop1Square.posY &&
                           redKingSquare.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }

                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop1Square.posY &&
                               greyBishop1Square.posX == redBishop1Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop1Square.posY &&
                               greyBishop2Square.posX == redBishop1Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop1Square.posY &&
                               greyPawnsBase[s].posX == redBishop1Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop1Square.posY &&
                               greyRook1Rectangle1.posX == redBishop1Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                               greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY - 70 &&
                           redPawnsBase[s].posX == redBishop1Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop1Square.posY - 70 &&
                           greyPawnsBase[s].posX == redBishop1Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop2Square.posY == redBishop1Square.posY - 70 &&
                       redBishop2Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redRook1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redRook2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redKnight1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       redKnight2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop1Square.posY - 70 &&
                       redBishop1Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyRook1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyRook2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop1Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop1Square.posY - 70 &&
                       greyQueenSquare.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop1Square.posY - 70 &&
                       greyBishop1Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop1Square.posY - 70 &&
                       greyBishop2Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop1Square.posY = redBishop1Square.posY - 70;
                        redBishop1Square.posX = redBishop1Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveRedBishop1(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop1Square.posY = redBishop1Square.posY + 70;
                    redBishop1Square.posX = redBishop1Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY &&
                           redPawnsBase[s].posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redBishop1Square.posY &&
                           redBishop2Square.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop1Square.posY &&
                           redKnight1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop1Square.posY &&
                           redKnight2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop1Square.posY &&
                           redRook1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop1Square.posY &&
                           redRook2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop1Square.posY &&
                           redKingSquare.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }

                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop1Square.posY &&
                               greyBishop1Square.posX == redBishop1Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop1Square.posY &&
                               greyBishop2Square.posX == redBishop1Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop1Square.posY &&
                               greyPawnsBase[s].posX == redBishop1Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop1Square.posY &&
                               greyRook1Rectangle1.posX == redBishop1Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                               greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY + 70 &&
                           redPawnsBase[s].posX == redBishop1Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop1Square.posY + 70 &&
                           greyPawnsBase[s].posX == redBishop1Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redBishop1Square.posY + 70 &&
                       redBishop1Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redBishop1Square.posY + 70 &&
                       redBishop2Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redRook1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redRook2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redKnight1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redKnight2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop1Square.posY + 70 &&
                       redBishop1Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyRook1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyRook2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop1Square.posY + 70 &&
                       greyQueenSquare.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop1Square.posY + 70 &&
                       greyBishop1Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop1Square.posY + 70 &&
                       greyBishop2Square.posX == redBishop1Square.posX - 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop1Square.posY = redBishop1Square.posY + 70;
                        redBishop1Square.posX = redBishop1Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveRedBishop1(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop1Square.posY = redBishop1Square.posY + 70;
                    redBishop1Square.posX = redBishop1Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY &&
                           redPawnsBase[s].posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop2Square.posY == redBishop1Square.posY &&
                           redBishop2Square.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop1Square.posY &&
                           redKnight1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop1Square.posY &&
                           redKnight2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop1Square.posY &&
                           redRook1Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop1Square.posY &&
                           redRook2Rectangle1.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop1Square.posY &&
                           redKingSquare.posX == redBishop1Square.posX) {
                            redBishop1Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop1Square.posY &&
                               greyBishop1Square.posX == redBishop1Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop1Square.posY &&
                               greyBishop2Square.posX == redBishop1Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop1Square.posY &&
                               greyPawnsBase[s].posX == redBishop1Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop1Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop1Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop1Square.posY &&
                               greyQueenSquare.posX == redBishop1Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop1Square.posY &&
                               greyRook1Rectangle1.posX == redBishop1Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                               greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop1Square.posY + 70 &&
                           redPawnsBase[s].posX == redBishop1Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop1Square.posY + 70 &&
                           greyPawnsBase[s].posX == redBishop1Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redBishop1Square.posY + 70 &&
                       redBishop1Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop2Square.posY == redBishop1Square.posY + 70 &&
                       redBishop2Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redRook1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redRook2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redKnight1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       redKnight2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop1Square.posY + 70 &&
                       redBishop1Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyRook1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyRook2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop1Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop1Square.posY + 70 &&
                       greyQueenSquare.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop1Square.posY + 70 &&
                       greyBishop1Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop1Square.posY + 70 &&
                       greyBishop2Square.posX == redBishop1Square.posX + 70) {
                        redBishop1Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop1Square.posY = redBishop1Square.posY + 70;
                        redBishop1Square.posX = redBishop1Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop1Square.failedpath = TRUE;
                return TRUE;
            }
        }
    }
}

boolean moveRedBishop2(UINT msg, int j, int i, int pos1, int ps1, int pos2, int ps2) {

    if(greyKnight1Rectangle1.posX == redBishop2Square.posX &&
       greyKnight1Rectangle1.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redBishop2Square.posX &&
       greyKnight2Rectangle1.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redBishop2Square.posX &&
       greyBishop1Square.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redBishop2Square.posX &&
       greyBishop2Square.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redBishop2Square.posX &&
       greyRook1Rectangle1.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redBishop2Square.posX &&
       greyRook2Rectangle1.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redBishop2Square.posX &&
       greyQueenSquare.posY == redBishop2Square.posY) {
        redBishop2Square.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redBishop2Square.posX &&
           greyPawnsBase[g].posY == redBishop2Square.posY) {
            redBishop2Square.failedpath = TRUE;
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
        redBishop2Square.failedpath = fail;
    }
    if(pos1 < 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 < -70) {
                f = moveRedBishop2(msg, j, i, pos1 + 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop2Square.posY = redBishop2Square.posY - 70;
                    redBishop2Square.posX = redBishop2Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY &&
                           redPawnsBase[s].posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redBishop2Square.posY &&
                           redBishop1Square.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop2Square.posY &&
                           redKnight1Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop2Square.posY &&
                           redKnight2Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop2Square.posY &&
                           redRook1Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop2Square.posY &&
                           redRook2Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop2Square.posY &&
                           redKingSquare.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop2Square.posY &&
                               greyBishop1Square.posX == redBishop2Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop2Square.posY &&
                               greyBishop2Square.posX == redBishop2Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop2Square.posY &&
                               greyPawnsBase[s].posX == redBishop2Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop2Square.posY &&
                               greyQueenSquare.posX == redBishop2Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop2Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop2Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop2Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop2Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop2Square.posY &&
                               greyQueenSquare.posX == redBishop2Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop2Square.posY &&
                               greyRook1Rectangle1.posX == redBishop2Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                               greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY - 70 &&
                           redPawnsBase[s].posX == redBishop2Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop2Square.posY - 70 &&
                           greyPawnsBase[s].posX == redBishop2Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY - 70 &&
                       redBishop1Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redRook1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redRook2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redKnight1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redKnight2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY - 70 &&
                       redBishop1Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyRook1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyRook2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop2Square.posY - 70 &&
                       greyQueenSquare.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop2Square.posY - 70 &&
                       greyBishop1Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop2Square.posY - 70 &&
                       greyBishop2Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop2Square.posY = redBishop2Square.posY - 70;
                        redBishop2Square.posX = redBishop2Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 < -70 && ps1 > 70) {
                f = moveRedBishop2(msg, j, i, pos1 + 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop2Square.posY = redBishop2Square.posY - 70;
                    redBishop2Square.posX = redBishop2Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY &&
                           redPawnsBase[s].posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redBishop2Square.posY &&
                           redBishop1Square.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop2Square.posY &&
                           redKnight1Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop2Square.posY &&
                           redKnight2Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop2Square.posY &&
                           redRook1Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop2Square.posY &&
                           redRook2Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop2Square.posY &&
                           redKingSquare.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop2Square.posY &&
                               greyBishop1Square.posX == redBishop2Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop2Square.posY &&
                               greyBishop2Square.posX == redBishop2Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop2Square.posY &&
                               greyPawnsBase[s].posX == redBishop2Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop2Square.posY &&
                               greyQueenSquare.posX == redBishop2Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop2Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop2Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop2Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop2Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop2Square.posY &&
                               greyQueenSquare.posX == redBishop2Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop2Square.posY &&
                               greyRook1Rectangle1.posX == redBishop2Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                               greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY - 70 &&
                           redPawnsBase[s].posX == redBishop2Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop2Square.posY - 70 &&
                           greyPawnsBase[s].posX == redBishop2Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY - 70 &&
                       redBishop1Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redRook1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redRook2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redKnight1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       redKnight2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY - 70 &&
                       redBishop1Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyRook1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyRook2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyKnight1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop2Square.posY - 70 &&
                       greyKnight2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop2Square.posY - 70 &&
                       greyQueenSquare.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop2Square.posY - 70 &&
                       greyBishop1Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop2Square.posY - 70 &&
                       greyBishop2Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop2Square.posY = redBishop2Square.posY - 70;
                        redBishop2Square.posX = redBishop2Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
    } else if(pos1 > 0) {
        if(ps1 < 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 < -70) {
                f = moveRedBishop2(msg, j, i, pos1 - 70, ps1 + 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop2Square.posY = redBishop2Square.posY + 70;
                    redBishop2Square.posX = redBishop2Square.posX - 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY &&
                           redPawnsBase[s].posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyPawnsBase[s].posY == redBishop2Square.posY &&
                               greyPawnsBase[s].posX == redBishop2Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }
                        }
                    }

                    if(redBishop1Square.posY == redBishop2Square.posY &&
                       redBishop1Square.posX == redBishop2Square.posX) {
                        redBishop2Square.failedpath = TRUE;
                        return TRUE;
                    }

                    if(redKnight1Rectangle1.posY == redBishop2Square.posY &&
                       redKnight1Rectangle1.posX == redBishop2Square.posX) {
                        redBishop2Square.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop2Square.posY &&
                       redKnight2Rectangle1.posX == redBishop2Square.posX) {
                        redBishop2Square.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop2Square.posY &&
                       redRook1Rectangle1.posX == redBishop2Square.posX) {
                        redBishop2Square.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop2Square.posY &&
                       redRook2Rectangle1.posX == redBishop2Square.posX) {
                        redBishop2Square.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redBishop2Square.posY &&
                       redKingSquare.posX == redBishop2Square.posX) {
                        redBishop2Square.failedpath = TRUE;
                        return TRUE;
                    }
                    if(j != -888) {
                        if(greyBishop1Square.posY == redBishop2Square.posY &&
                           greyBishop1Square.posX == redBishop2Square.posX) {
                            greyBishop1Square.posX = 1300;
                        }

                        if(greyBishop2Square.posY == redBishop2Square.posY &&
                           greyBishop2Square.posX == redBishop2Square.posX) {
                            greyBishop2Square.posX = 1300;
                        }

                        if(greyQueenSquare.posY == redBishop2Square.posY &&
                           greyQueenSquare.posX == redBishop2Square.posX) {
                            greyQueenSquare.posX = 1300;
                        }

                        if(greyKnight1Rectangle1.posY == redBishop2Square.posY &&
                           greyKnight1Rectangle1.posX == redBishop2Square.posX) {
                            greyKnight1Rectangle1.posX = 1300;
                        }

                        if(greyKnight2Rectangle1.posY == redBishop2Square.posY &&
                           greyKnight2Rectangle1.posX == redBishop2Square.posX) {
                            greyKnight2Rectangle1.posX = 1300;
                        }

                        if(greyQueenSquare.posY == redBishop2Square.posY &&
                           greyQueenSquare.posX == redBishop2Square.posX) {
                            greyQueenSquare.posX = 1300;
                        }

                        if(greyRook1Rectangle1.posY == redBishop2Square.posY &&
                           greyRook1Rectangle1.posX == redBishop2Square.posX) {
                            greyRook1Rectangle1.posX = 1300;
                        }

                        if(greyRook2Rectangle1.posY == greyBishop2Square.posY &&
                           greyRook2Rectangle1.posX == greyBishop2Square.posX) {
                            greyRook2Rectangle1.posX = 1300;
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY + 70 &&
                           redPawnsBase[s].posX == redBishop2Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop2Square.posY + 70 &&
                           greyPawnsBase[s].posX == redBishop2Square.posX - 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY + 70 &&
                       redBishop1Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redRook1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redRook2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redKnight1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redKnight2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY + 70 &&
                       redBishop1Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyRook1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyRook2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop2Square.posY + 70 &&
                       greyQueenSquare.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop2Square.posY + 70 &&
                       greyBishop1Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop2Square.posY + 70 &&
                       greyBishop2Square.posX == redBishop2Square.posX - 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop2Square.posY = redBishop2Square.posY + 70;
                        redBishop2Square.posX = redBishop2Square.posX - 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop2Square.failedpath = TRUE;
                return TRUE;
            }
        }
        if(ps1 > 0) {
            boolean f = FALSE;
            if(pos1 > 70 && ps1 > 70) {
                f = moveRedBishop2(msg, j, i, pos1 - 70, ps1 - 70, pos2, ps2);
            }
            if(!f) {
                if(pos1 == pos2 &&
                    ps1 == ps2) {

                    redBishop2Square.posY = redBishop2Square.posY + 70;
                    redBishop2Square.posX = redBishop2Square.posX + 70;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY &&
                           redPawnsBase[s].posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redBishop1Square.posY == redBishop2Square.posY &&
                           redBishop1Square.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight1Rectangle1.posY == redBishop2Square.posY &&
                           redKnight1Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKnight2Rectangle1.posY == redBishop2Square.posY &&
                           redKnight2Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook1Rectangle1.posY == redBishop2Square.posY &&
                           redRook1Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redRook2Rectangle1.posY == redBishop2Square.posY &&
                           redRook2Rectangle1.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(redKingSquare.posY == redBishop2Square.posY &&
                           redKingSquare.posX == redBishop2Square.posX) {
                            redBishop2Square.failedpath = TRUE;
                            return TRUE;
                        }
                        if(j != -888) {
                            if(greyBishop1Square.posY == redBishop2Square.posY &&
                               greyBishop1Square.posX == redBishop2Square.posX) {
                                greyBishop1Square.posX = 1300;
                            }

                            if(greyBishop2Square.posY == redBishop2Square.posY &&
                               greyBishop2Square.posX == redBishop2Square.posX) {
                                greyBishop2Square.posX = 1300;
                            }

                            if(greyPawnsBase[s].posY == redBishop2Square.posY &&
                               greyPawnsBase[s].posX == redBishop2Square.posX) {
                                greyPawnsBase[s].posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop2Square.posY &&
                               greyQueenSquare.posX == redBishop2Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyKnight1Rectangle1.posY == redBishop2Square.posY &&
                               greyKnight1Rectangle1.posX == redBishop2Square.posX) {
                                greyKnight1Rectangle1.posX = 1300;
                            }

                            if(greyKnight2Rectangle1.posY == redBishop2Square.posY &&
                               greyKnight2Rectangle1.posX == redBishop2Square.posX) {
                                greyKnight2Rectangle1.posX = 1300;
                            }

                            if(greyQueenSquare.posY == redBishop2Square.posY &&
                               greyQueenSquare.posX == redBishop2Square.posX) {
                                greyQueenSquare.posX = 1300;
                            }

                            if(greyRook1Rectangle1.posY == redBishop2Square.posY &&
                               greyRook1Rectangle1.posX == redBishop2Square.posX) {
                                greyRook1Rectangle1.posX = 1300;
                            }

                            if(greyRook2Rectangle1.posY == redBishop2Square.posY &&
                               greyRook2Rectangle1.posX == redBishop2Square.posX) {
                                greyRook2Rectangle1.posX = 1300;
                            }
                        }
                    }

                    return FALSE;

                } else {

                    boolean flag = FALSE;

                    for(int s=0; s<8; s++) {
                        if(redPawnsBase[s].posY == redBishop2Square.posY + 70 &&
                           redPawnsBase[s].posX == redBishop2Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                        if(greyPawnsBase[s].posY == redBishop2Square.posY + 70 &&
                           greyPawnsBase[s].posX == redBishop2Square.posX + 70) {
                            redBishop1Square.failedpath = TRUE;
                            flag = TRUE;
                        }
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY + 70 &&
                       redBishop1Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redRook1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redRook2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redRook2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redKnight1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       redKnight2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redBishop1Square.posY == redBishop2Square.posY + 70 &&
                       redBishop1Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyRook1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyRook2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyRook2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyKnight1Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == redBishop2Square.posY + 70 &&
                       greyKnight2Rectangle1.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redBishop2Square.posY + 70 &&
                       greyQueenSquare.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop1Square.posY == redBishop2Square.posY + 70 &&
                       greyBishop1Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyBishop2Square.posY == redBishop2Square.posY + 70 &&
                       greyBishop2Square.posX == redBishop2Square.posX + 70) {
                        redBishop2Square.failedpath = TRUE;
                        flag = TRUE;
                    }

                    if(!flag) {
                        redBishop2Square.posY = redBishop2Square.posY + 70;
                        redBishop2Square.posX = redBishop2Square.posX + 70;
                    }

                    return flag;
                }
            }

            else {

                redBishop2Square.failedpath = TRUE;                
                return TRUE;
            }
        }
    }
}

boolean moveGreyRook1(UINT msg, int j, int i, int pos, int o) {

    if(redKingSquare.posX == greyRook1Rectangle1.posX &&
       redKingSquare.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKingSquare.posX == greyRook2Rectangle1.posX &&
       redKingSquare.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight1Rectangle1.posX == greyRook1Rectangle1.posX &&
       redKnight1Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }                                                                                  
    if(redKnight2Rectangle1.posX == greyRook1Rectangle1.posX &&
       redKnight2Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyRook1Rectangle1.posX &&
       redBishop1Square.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyRook1Rectangle1.posX &&
       redBishop2Square.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyRook1Rectangle1.posX &&
       redRook1Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyRook1Rectangle1.posX &&
       redRook2Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyRook1Rectangle1.posX &&
       redQueenSquare.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyRook1Rectangle1.posX &&
           redPawnsBase[g].posY == greyRook1Rectangle1.posY) {
            greyRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyRook1(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook1Rectangle1.posY = greyRook1Rectangle1.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook1Rectangle1.posY &&
                       greyKingSquare.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook1Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook1Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                       redBishop1Square.posX == greyRook1Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook1Rectangle1.posY &&
                       redBishop2Square.posX == greyRook1Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY - 70 &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY - 70 &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY - 70 &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY - 70 &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook1Rectangle1.posY - 70 &&
                   redBishop2Square.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   redRook1Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   redRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   redKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   redKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   greyRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY - 70 &&
                   greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook1Rectangle1.posY = greyRook1Rectangle1.posY - 70;
                }

                return flag;
            }
        }

        else {

            greyRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyRook1(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook1Rectangle1.posY = greyRook1Rectangle1.posY + 70;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook1Rectangle1.posY &&
                       greyKingSquare.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook1Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook1Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                       redBishop1Square.posX == greyRook1Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook1Rectangle1.posY &&
                       redBishop2Square.posX == greyRook1Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY + 70 &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY + 70 &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY + 70 &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY + 70 &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook1Rectangle1.posY + 70 &&
                   redBishop2Square.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   redRook1Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   redRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   redKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   redKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY + 70 &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   greyRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY + 70 &&
                   greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook1Rectangle1.posY = greyRook1Rectangle1.posY + 70;
                }

                return flag;
            }
        }

        else {

            greyRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveGreyRook1Side(UINT msg, int j, int i, int pos, int o) {

    if(redKingSquare.posX == greyRook1Rectangle1.posX &&
       redKingSquare.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKingSquare.posX == greyRook2Rectangle1.posX &&
       redKingSquare.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight1Rectangle1.posX == greyRook1Rectangle1.posX &&
       redKnight1Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyRook1Rectangle1.posX &&
       redKnight2Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyRook1Rectangle1.posX &&
       redBishop1Square.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyRook1Rectangle1.posX &&
       redBishop2Square.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyRook1Rectangle1.posX &&
       redRook1Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyRook1Rectangle1.posX &&
       redRook2Rectangle1.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyRook1Rectangle1.posX &&
       redQueenSquare.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyRook1Rectangle1.posX &&
           redPawnsBase[g].posY == greyRook1Rectangle1.posY) {
            greyRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyRook1Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook1Rectangle1.posX = greyRook1Rectangle1.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook1Rectangle1.posY &&
                       greyKingSquare.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook1Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook1Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                       redBishop1Square.posX == greyRook1Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook1Rectangle1.posY &&
                       redBishop2Square.posX == greyRook1Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX - 70) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX - 70) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX - 70) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook1Rectangle1.posY &&
                   redBishop2Square.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook1Rectangle1.posY - 70 &&
                   redBishop2Square.posX == greyRook1Rectangle1.posX) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redRook1Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redRook2Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redKnight1Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redKnight2Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   greyRook2Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX - 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook1Rectangle1.posX = greyRook1Rectangle1.posX - 70;
                }

                return flag;
            }
        }

        else {

            greyRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyRook1Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook1Rectangle1.posX = greyRook1Rectangle1.posX + 70;
                
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook1Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook1Rectangle1.posY &&
                       greyKingSquare.posX == greyRook1Rectangle1.posX) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook1Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook1Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                       redBishop1Square.posX == greyRook1Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook1Rectangle1.posY &&
                       redBishop2Square.posX == greyRook1Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook1Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook1Rectangle1.posX + 70) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook1Rectangle1.posX + 70) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook1Rectangle1.posY &&
                       redQueenSquare.posX == greyRook1Rectangle1.posX + 70) {
                        greyRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook1Rectangle1.posY &&
                   redBishop2Square.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redRook1Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redRook2Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redKnight1Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   redKnight2Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == greyRook1Rectangle1.posY &&
                   redBishop1Square.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   greyRook2Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook1Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook1Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == greyRook1Rectangle1.posX + 70) {
                    greyRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook1Rectangle1.posX = greyRook1Rectangle1.posX + 70;
                }

                return flag;
            }
        }

        else {

            greyRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveRedRook1(UINT msg, int j, int i, int pos, int o) {

    if(greyKingSquare.posX == redRook1Rectangle1.posX &&
       greyKingSquare.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKingSquare.posX == redRook2Rectangle1.posX &&
       greyKingSquare.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redRook1Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redRook1Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redRook1Rectangle1.posX &&
       greyBishop1Square.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redRook1Rectangle1.posX &&
       greyBishop2Square.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redRook1Rectangle1.posX &&
       greyRook1Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redRook1Rectangle1.posX &&
       greyRook2Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redRook1Rectangle1.posX &&
       greyQueenSquare.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redRook1Rectangle1.posX &&
           greyPawnsBase[g].posY == redRook1Rectangle1.posY) {
            redRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedRook1(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook1Rectangle1.posY = redRook1Rectangle1.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                       redBishop1Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                       redBishop2Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook1Rectangle1.posY &&
                       redKingSquare.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook1Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook1Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook1Rectangle1.posY &&
                       greyQueenSquare.posX == redRook1Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook1Rectangle1.posY &&
                       greyBishop1Square.posX == redRook1Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook1Rectangle1.posY &&
                       greyBishop2Square.posX == redRook1Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY - 70 &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redRook1Rectangle1.posY - 70 &&
                       greyQueenSquare.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY - 70 &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook1Rectangle1.posY - 70 &&
                   redBishop1Square.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook1Rectangle1.posY - 70 &&
                   redBishop2Square.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   redRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   redKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   redKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   redRook1Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   greyRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                   redBishop1Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                   redBishop2Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   greyKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY - 70 &&
                   greyKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook1Rectangle1.posY = redRook1Rectangle1.posY - 70;
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
            f = moveRedRook1(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook1Rectangle1.posY = redRook1Rectangle1.posY + 70;
                
                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                       redBishop1Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                       redBishop2Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook1Rectangle1.posY &&
                       redKingSquare.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook1Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook1Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook1Rectangle1.posY &&
                       greyQueenSquare.posX == redRook1Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook1Rectangle1.posY &&
                       greyBishop1Square.posX == redRook1Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook1Rectangle1.posY &&
                       greyBishop2Square.posX == redRook1Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY + 70 &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redRook1Rectangle1.posY + 70 &&
                       greyQueenSquare.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY + 70 &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook1Rectangle1.posY + 70 &&
                   redBishop1Square.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook1Rectangle1.posY + 70 &&
                   redBishop2Square.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   redRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   redKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   redKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   redRook1Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   greyRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redRook1Rectangle1.posY + 70 &&
                   redBishop1Square.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook1Rectangle1.posY + 70 &&
                   redBishop2Square.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   greyKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY + 70 &&
                   greyKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook1Rectangle1.posY = redRook1Rectangle1.posY + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}

boolean moveRedRook1Side(UINT msg, int j, int i, int pos, int o) {

    if(greyKingSquare.posX == redRook1Rectangle1.posX &&
       greyKingSquare.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKingSquare.posX == redRook2Rectangle1.posX &&
       greyKingSquare.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redRook1Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redRook1Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redRook1Rectangle1.posX &&
       greyBishop1Square.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redRook1Rectangle1.posX &&
       greyBishop2Square.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redRook1Rectangle1.posX &&
       greyRook1Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redRook1Rectangle1.posX &&
       greyRook2Rectangle1.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redRook1Rectangle1.posX &&
       greyQueenSquare.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redRook1Rectangle1.posX &&
           greyPawnsBase[g].posY == redRook1Rectangle1.posY) {
            redRook1Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedRook1Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook1Rectangle1.posX = redRook1Rectangle1.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                       redBishop1Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                       redBishop2Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook1Rectangle1.posY &&
                       redKingSquare.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook1Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook1Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook1Rectangle1.posY &&
                       greyQueenSquare.posX == redRook1Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook1Rectangle1.posY &&
                       greyBishop1Square.posX == redRook1Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook1Rectangle1.posY &&
                       greyBishop2Square.posX == redRook1Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX - 70) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == redRook1Rectangle1.posY &&
                       redQueenSquare.posX == redRook1Rectangle1.posX - 70) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX - 70) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                   redBishop1Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                   redBishop2Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                   redRook2Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                   redKnight1Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                   redKnight2Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook1Rectangle1.posY &&
                   redRook1Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                   greyRook2Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redRook1Rectangle1.posY &&
                   greyBishop1Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redRook1Rectangle1.posY &&
                   greyBishop2Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook1Rectangle1.posX = redRook1Rectangle1.posX - 70;
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
            f = moveRedRook1Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook1Rectangle1.posX = redRook1Rectangle1.posX + 70;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                       redBishop1Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                       redBishop2Square.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       redRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook1Rectangle1.posY &&
                       redKingSquare.posX == redRook1Rectangle1.posX) {
                        redRook1Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook1Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook1Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook1Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook1Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook1Rectangle1.posY &&
                       greyQueenSquare.posX == redRook1Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook1Rectangle1.posY &&
                       greyBishop1Square.posX == redRook1Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook1Rectangle1.posY &&
                       greyBishop2Square.posX == redRook1Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook1Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    if(redPawnsBase[i].posY == redRook1Rectangle1.posY &&
                       redPawnsBase[i].posX == redRook1Rectangle1.posX + 70) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == redRook1Rectangle1.posY &&
                       greyPawnsBase[i].posX == redRook1Rectangle1.posX + 70) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == redRook1Rectangle1.posY &&
                       redQueenSquare.posX == redRook1Rectangle1.posX + 70) {
                        redRook1Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook1Rectangle1.posY &&
                   redBishop1Square.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook1Rectangle1.posY &&
                   redBishop2Square.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                   redRook2Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                   redKnight1Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                   redKnight2Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook1Rectangle1.posY &&
                   redRook1Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == redRook1Rectangle1.posY &&
                   greyRook2Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redRook1Rectangle1.posY &&
                   greyBishop1Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redRook1Rectangle1.posY &&
                   greyBishop2Square.posX == redRook1Rectangle1.posX - 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook1Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook1Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == redRook1Rectangle1.posX + 70) {
                    redRook1Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook1Rectangle1.posX = redRook1Rectangle1.posX + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}

boolean moveGreyRook2(UINT msg, int j, int i, int pos, int o) {

    if(redKingSquare.posX == greyRook1Rectangle1.posX &&
       redKingSquare.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKingSquare.posX == greyRook2Rectangle1.posX &&
       redKingSquare.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight1Rectangle1.posX == greyRook2Rectangle1.posX &&
       redKnight1Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyRook2Rectangle1.posX &&
       redKnight2Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyRook2Rectangle1.posX &&
       redBishop1Square.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyRook2Rectangle1.posX &&
       redBishop2Square.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyRook2Rectangle1.posX &&
       redRook1Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyRook2Rectangle1.posX &&
       redRook2Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyRook2Rectangle1.posX &&
       redQueenSquare.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyRook2Rectangle1.posX &&
           redPawnsBase[g].posY == greyRook2Rectangle1.posY) {
            greyRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyRook2(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook2Rectangle1.posY = greyRook2Rectangle1.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook2Rectangle1.posY &&
                       greyKingSquare.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook1Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook1Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook2Rectangle1.posY &&
                       redBishop1Square.posX == greyRook2Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook2Rectangle1.posY &&
                       redBishop2Square.posX == greyRook2Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY - 70 &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY - 70 &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY - 70 &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook2Rectangle1.posY - 70 &&
                   redBishop1Square.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook2Rectangle1.posY - 70 &&
                   redBishop2Square.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   redRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   redKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   redKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY - 70 &&
                   greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook2Rectangle1.posY = greyRook2Rectangle1.posY - 70;
                }

                return flag;
            }
        }

        else {

            greyRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyRook2(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook2Rectangle1.posY = greyRook2Rectangle1.posY + 70;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook2Rectangle1.posY &&
                       greyKingSquare.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook1Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook1Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook2Rectangle1.posY &&
                       redBishop1Square.posX == greyRook2Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook2Rectangle1.posY &&
                       redBishop2Square.posX == greyRook2Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY + 70 &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY + 70 &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY + 70 &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook2Rectangle1.posY + 70 &&
                   redBishop1Square.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook2Rectangle1.posY + 70 &&
                   redBishop2Square.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   redRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   redKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   redKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY + 70 &&
                   greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook2Rectangle1.posY = greyRook2Rectangle1.posY + 70;
                }

                return flag;
            }
        }

        else {

            greyRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveGreyRook2Side(UINT msg, int j, int i, int pos, int o) {

    if(redKingSquare.posX == greyRook1Rectangle1.posX &&
       redKingSquare.posY == greyRook1Rectangle1.posY) {
        greyRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKingSquare.posX == greyRook2Rectangle1.posX &&
       redKingSquare.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight1Rectangle1.posX == greyRook2Rectangle1.posX &&
       redKnight1Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redKnight2Rectangle1.posX == greyRook2Rectangle1.posX &&
       redKnight2Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop1Square.posX == greyRook2Rectangle1.posX &&
       redBishop1Square.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redBishop2Square.posX == greyRook2Rectangle1.posX &&
       redBishop2Square.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook1Rectangle1.posX == greyRook2Rectangle1.posX &&
       redRook1Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redRook2Rectangle1.posX == greyRook2Rectangle1.posX &&
       redRook2Rectangle1.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(redQueenSquare.posX == greyRook2Rectangle1.posX &&
       redQueenSquare.posY == greyRook2Rectangle1.posY) {
        greyRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(redPawnsBase[g].posX == greyRook2Rectangle1.posX &&
           redPawnsBase[g].posY == greyRook2Rectangle1.posY) {
            greyRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveGreyRook2Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook2Rectangle1.posX = greyRook2Rectangle1.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook2Rectangle1.posY &&
                       greyKingSquare.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook2Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook2Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook2Rectangle1.posY &&
                       redBishop1Square.posX == greyRook2Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook2Rectangle1.posY &&
                       redBishop2Square.posX == greyRook2Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX - 70) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX - 70) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX - 70) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook2Rectangle1.posY &&
                   redBishop1Square.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook2Rectangle1.posY &&
                   redBishop2Square.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   redRook2Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                   redKnight1Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   redKnight2Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX - 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook2Rectangle1.posX = greyRook2Rectangle1.posX - 70;
                }

                return flag;
            }
        }

        else {

            greyRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    } else if(pos > 0) {
        boolean f = FALSE;
        if(pos > 70) {
            f = moveGreyRook2Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                greyRook2Rectangle1.posX = greyRook2Rectangle1.posX + 70;
                
                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop1Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop1Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyBishop2Square.posY == greyRook2Rectangle1.posY &&
                       greyBishop2Square.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyKingSquare.posY == greyRook2Rectangle1.posY &&
                       greyKingSquare.posX == greyRook2Rectangle1.posX) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX) {
                        redPawnsBase[s].posX = 1300;
                    }
                    if(redRook1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook1Rectangle1.posX = 1300;
                    }
                    if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redRook2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(redQueenSquareK[z].posY == greyRook2Rectangle1.posY &&
                           redQueenSquareK[z].posX == greyRook2Rectangle1.posX) {
                            redQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX) {
                        redQueenSquare.posX = 1300;
                    }
                    if(redBishop1Square.posY == greyRook2Rectangle1.posY &&
                       redBishop1Square.posX == greyRook2Rectangle1.posX) {
                        redBishop1Square.posX = 1300;
                    }
                    if(redBishop2Square.posY == greyRook2Rectangle1.posY &&
                       redBishop2Square.posX == greyRook2Rectangle1.posX) {
                        redBishop2Square.posX = 1300;
                    }
                    if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight1Rectangle1.posX = 1300;
                    }
                    if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == greyRook2Rectangle1.posX) {
                        redKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(greyPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == greyRook2Rectangle1.posX + 70) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redPawnsBase[s].posY == greyRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == greyRook2Rectangle1.posX + 70) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == greyRook2Rectangle1.posY &&
                       redQueenSquare.posX == greyRook2Rectangle1.posX + 70) {
                        greyRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == greyRook2Rectangle1.posY &&
                   redBishop1Square.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == greyRook2Rectangle1.posY &&
                   redBishop2Square.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   redRook2Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                   redKnight1Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   redKnight2Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyRook2Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == greyRook2Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == greyRook2Rectangle1.posX + 70) {
                    greyRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    greyRook2Rectangle1.posX = greyRook2Rectangle1.posX + 70;
                }

                return flag;
            }
        }

        else {

            greyRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
}

boolean moveRedRook2(UINT msg, int j, int i, int pos, int o) {

    if(greyKingSquare.posX == redRook1Rectangle1.posX &&
       greyKingSquare.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKingSquare.posX == redRook2Rectangle1.posX &&
       greyKingSquare.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redRook2Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redRook2Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redRook2Rectangle1.posX &&
       greyBishop1Square.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redRook2Rectangle1.posX &&
       greyBishop2Square.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redRook2Rectangle1.posX &&
       greyRook1Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redRook2Rectangle1.posX &&
       greyRook2Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redRook2Rectangle1.posX &&
       greyQueenSquare.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redRook2Rectangle1.posX &&
           greyPawnsBase[g].posY == redRook2Rectangle1.posY) {
            redRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedRook2(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook2Rectangle1.posY = redRook2Rectangle1.posY - 70;
                
                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook2Rectangle1.posY &&
                       redBishop1Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook2Rectangle1.posY &&
                       redBishop2Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook2Rectangle1.posY &&
                       redKingSquare.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook2Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook2Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook2Rectangle1.posY &&
                       greyQueenSquare.posX == redRook2Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook2Rectangle1.posY &&
                       greyBishop1Square.posX == redRook2Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook2Rectangle1.posY &&
                       greyBishop2Square.posX == redRook2Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY - 70 &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redRook2Rectangle1.posY - 70 &&
                       greyQueenSquare.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == redRook2Rectangle1.posY - 70 &&
                       greyPawnsBase[i].posX == redRook2Rectangle1.posX) {
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook2Rectangle1.posY - 70 &&
                   redBishop1Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook2Rectangle1.posY - 70 &&
                   redBishop2Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook2Rectangle1.posY - 70 &&
                   redRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY - 70 &&
                   redKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY - 70 &&
                   redKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY - 70 &&
                   greyRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redRook2Rectangle1.posY - 70 &&
                   greyBishop1Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redRook2Rectangle1.posY - 70 &&
                   greyBishop2Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY - 70 &&
                   greyKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY - 70 &&
                   greyKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook2Rectangle1.posY = redRook2Rectangle1.posY - 70;
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
            f = moveRedRook2(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook2Rectangle1.posY = redRook2Rectangle1.posY + 70;
                
                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook2Rectangle1.posY &&
                       redBishop1Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook2Rectangle1.posY &&
                       redBishop2Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook2Rectangle1.posY &&
                       redKingSquare.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook2Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook2Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook2Rectangle1.posY &&
                       greyQueenSquare.posX == redRook2Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook2Rectangle1.posY &&
                       greyBishop1Square.posX == redRook2Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook2Rectangle1.posY &&
                       greyBishop2Square.posX == redRook2Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY + 70 &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyQueenSquare.posY == redRook2Rectangle1.posY + 70 &&
                       greyQueenSquare.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == redRook2Rectangle1.posY + 70 &&
                       greyPawnsBase[i].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook2Rectangle1.posY + 70 &&
                   redBishop1Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook2Rectangle1.posY - 70 &&
                   redBishop2Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook2Rectangle1.posY + 70 &&
                   redRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY + 70 &&
                   redKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY + 70 &&
                   redKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop1Square.posY == redRook2Rectangle1.posY + 70 &&
                   redBishop1Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY + 70 &&
                   greyRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redRook2Rectangle1.posY - 70 &&
                   greyBishop1Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redRook2Rectangle1.posY - 70 &&
                   greyBishop2Square.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY + 70 &&
                   greyKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY + 70 &&
                   greyKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook2Rectangle1.posY = redRook2Rectangle1.posY + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}

boolean moveRedRook2Side(UINT msg, int j, int i, int pos, int o) {

    if(greyKingSquare.posX == redRook1Rectangle1.posX &&
       greyKingSquare.posY == redRook1Rectangle1.posY) {
        redRook1Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKingSquare.posX == redRook2Rectangle1.posX &&
       greyKingSquare.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight1Rectangle1.posX == redRook2Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX == redRook2Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop1Square.posX == redRook2Rectangle1.posX &&
       greyBishop1Square.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyBishop2Square.posX == redRook2Rectangle1.posX &&
       greyBishop2Square.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook1Rectangle1.posX == redRook2Rectangle1.posX &&
       greyRook1Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyRook2Rectangle1.posX == redRook2Rectangle1.posX &&
       greyRook2Rectangle1.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    if(greyQueenSquare.posX == redRook2Rectangle1.posX &&
       greyQueenSquare.posY == redRook2Rectangle1.posY) {
        redRook2Rectangle1.failedpath = TRUE;
        return TRUE;
    }
    for(int g=0; g<8; g++) {
        if(greyPawnsBase[g].posX == redRook2Rectangle1.posX &&
           greyPawnsBase[g].posY == redRook2Rectangle1.posY) {
            redRook2Rectangle1.failedpath = TRUE;
            return TRUE;
        }
    }
    if(pos < 0) {
        boolean f = FALSE;
        if(pos < -70) {
            f = moveRedRook2Side(msg, j, i, pos + 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook2Rectangle1.posX = redRook2Rectangle1.posX - 70;
                
                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook2Rectangle1.posY &&
                       redBishop1Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook2Rectangle1.posY &&
                       redBishop2Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook2Rectangle1.posY &&
                       redKingSquare.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook2Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook2Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook2Rectangle1.posY &&
                       greyQueenSquare.posX == redRook2Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook2Rectangle1.posY &&
                       greyBishop1Square.posX == redRook2Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook2Rectangle1.posY &&
                       greyBishop2Square.posX == redRook2Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX - 70) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook2Rectangle1.posX - 70) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == redRook2Rectangle1.posY &&
                       redQueenSquare.posX == redRook2Rectangle1.posX - 70) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook2Rectangle1.posY &&
                   redBishop1Square.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook2Rectangle1.posY &&
                   redBishop2Square.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                   redRook1Rectangle1.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                   redKnight1Rectangle1.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                   redKnight2Rectangle1.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                   greyRook1Rectangle1.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redRook2Rectangle1.posY &&
                   greyBishop1Square.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redRook2Rectangle1.posY &&
                   greyBishop2Square.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == redRook2Rectangle1.posX - 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook2Rectangle1.posX = redRook2Rectangle1.posX - 70;
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
            f = moveRedRook2Side(msg, j, i, pos - 70, o);
        }
        if(!f) {
            if(pos == o) {

                redRook2Rectangle1.posX = redRook2Rectangle1.posX + 70;

                for(int s=0; s<8; s++) {
                    if(redPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       redPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop1Square.posY == redRook2Rectangle1.posY &&
                       redBishop1Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redBishop2Square.posY == redRook2Rectangle1.posY &&
                       redBishop2Square.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       redKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       redRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(redKingSquare.posY == redRook2Rectangle1.posY &&
                       redKingSquare.posX == redRook2Rectangle1.posX) {
                        redRook2Rectangle1.failedpath = TRUE;
                        return TRUE;
                    }
                    if(greyPawnsBase[s].posY == redRook2Rectangle1.posY &&
                       greyPawnsBase[s].posX == redRook2Rectangle1.posX) {
                        greyPawnsBase[s].posX = 1300;
                    }
                    if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook1Rectangle1.posX = 1300;
                    }
                    if(greyRook2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyRook2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyRook2Rectangle1.posX = 1300;
                    }
                    for(int z=0; z<8; z++) {
                        if(greyQueenSquareK[z].posY == redRook2Rectangle1.posY &&
                           greyQueenSquareK[z].posX == redRook2Rectangle1.posX) {
                            greyQueenSquareK[z].posX = 1300;
                        }
                    }
                    if(greyQueenSquare.posY == redRook2Rectangle1.posY &&
                       greyQueenSquare.posX == redRook2Rectangle1.posX) {
                        greyQueenSquare.posX = 1300;
                    }
                    if(greyBishop1Square.posY == redRook2Rectangle1.posY &&
                       greyBishop1Square.posX == redRook2Rectangle1.posX) {
                        greyBishop1Square.posX = 1300;
                    }
                    if(greyBishop2Square.posY == redRook2Rectangle1.posY &&
                       greyBishop2Square.posX == redRook2Rectangle1.posX) {
                        greyBishop2Square.posX = 1300;
                    }
                    if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight1Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight1Rectangle1.posX = 1300;
                    }
                    if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                       greyKnight2Rectangle1.posX == redRook2Rectangle1.posX) {
                        greyKnight2Rectangle1.posX = 1300;
                    }
                }
                
                return FALSE;

            } else {

                boolean flag = FALSE;

                for(int i=0; i<8; i++) {
                    if(redPawnsBase[i].posY == redRook2Rectangle1.posY &&
                       redPawnsBase[i].posX == redRook2Rectangle1.posX + 70) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(greyPawnsBase[i].posY == redRook2Rectangle1.posY &&
                       greyPawnsBase[i].posX == redRook2Rectangle1.posX + 70) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                    if(redQueenSquare.posY == redRook2Rectangle1.posY &&
                       redQueenSquare.posX == redRook2Rectangle1.posX + 70) {
                        redRook2Rectangle1.failedpath = TRUE;
                        flag = TRUE;
                    }
                }
                if(redBishop1Square.posY == redRook2Rectangle1.posY &&
                   redBishop1Square.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redBishop2Square.posY == redRook2Rectangle1.posY &&
                   redBishop2Square.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                   redRook1Rectangle1.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                   redKnight1Rectangle1.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(redKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                   redKnight2Rectangle1.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyRook1Rectangle1.posY == redRook2Rectangle1.posY &&
                   greyRook1Rectangle1.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop1Square.posY == redRook2Rectangle1.posY &&
                   greyBishop1Square.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyBishop2Square.posY == redRook2Rectangle1.posY &&
                   greyBishop2Square.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight1Rectangle1.posY == redRook2Rectangle1.posY &&
                   greyKnight1Rectangle1.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }
                if(greyKnight2Rectangle1.posY == redRook2Rectangle1.posY &&
                   greyKnight2Rectangle1.posX == redRook2Rectangle1.posX + 70) {
                    redRook2Rectangle1.failedpath = TRUE;
                    flag = TRUE;
                }

                if(!flag) {
                    redRook2Rectangle1.posX = redRook2Rectangle1.posX + 70;
                }

                return flag;
            }
        }

        else {

            return TRUE;
        }
    }
}