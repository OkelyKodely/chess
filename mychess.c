/* 
 * Application: mychess.exe
 * Author: Daniel Cho
 *
 */

//ming gcc compiled
//linked libraries: gdi32, comctl32, winmm, winhttp, ws2_32

#include <winsock2.h>
#include <stdbool.h>
#include <windows.h>
#include <commctrl.h>
#include <mmsystem.h>
#include <time.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "mychess.h"

int nCmdShow2 = 123;
HDC hdc2;
int wLMSize;
char *wLM[1000];
char *wLgalMoves;

PAINTSTRUCT     pss;
BITMAP          bitmaps;
HDC             hdcMems;
HGDIOBJ         oldBitmaps;
HBITMAP         hhbbs;

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

boolean checkmate = FALSE;
boolean tft = FALSE;

char filename[FILENAME_MAX];
char buff[FILENAME_MAX];

#define	BUTTON_IDENTIFIER 1

boolean pcgame = FALSE;

int begin = 1;

int iResult = -10;
int iresult = -10;

char *from;
char *to;

char *gt = "GET /game?fen=";
char *initfn = "rnbqkbnr%2Fpppppppp%2F8%2F8%2F8%2F8%2FPPPPPPPP%2FRNBQKBNR+w+KQkq+-+0+1";
char *hstt = "&format=json HTTP/1.0\r\nHost: api.underwaterchess.com\r\nContent-Type: application/json; charset=UTF-8\r\n\r\n";
char *fen = "rnbqkbnr%2Fpppppppp%2F8%2F8%2F8%2F8%2FPPPPPPPP%2FRNBQKBNR+w+KQkq+-+0+1";

char *fen2 = "rnbqkbnr%2Fpppppppp%2F8%2F8%2F8%2F8%2FPPPPPPPP%2FRNBQKBNR+w+KQkq+-+0+1";

HINSTANCE hInsta_nce;
HBITMAP hbit;

#define ID_CAPTURE_SCREEN 16001
#define IDC_DOWNLOAD_BUTTON 16002
#define ID_FILE_DOWNLOAD 16003

boolean fftime = TRUE;

int finished = -1;

int _y_ = 20;

char chosenPiece[2] = "";

#define COLORREF2RGB(Color) (Color & 0xff00) | ((Color >> 16) & 0xff) | ((Color << 16) & 0xfe0000)
#define IDC_QUIT_BUTTON 101
#define IDC_NEW_GAME_BUTTON 102

boolean klicked = FALSE;

int i__PosX = 0;
int i__PosY = 0;
            
boolean done = FALSE;
boolean whiteKingMoved = FALSE;
boolean blackKingMoved = FALSE;
boolean whiteRook1Moved = FALSE;
boolean blackRook1Moved = FALSE;
boolean whiteRook2Moved = FALSE;
boolean blackRook2Moved = FALSE;

MSG msg;

RECT rect;

HINSTANCE hInst;
HINSTANCE g_hinstance;
HBITMAP hBitmap;
HBITMAP hBitmapSideLogo;
HBITMAP hBitmapAbout;
HBITMAP hBitmapSq;
HBITMAP pawnBlack, pawnWhite, knightBlack, knight2Black, knightWhite, knight2White, rookBlack, rook2Black, rookWhite, rook2White, bishopBlack, bishop2Black, bishopWhite, bishop2White, queenBlack, queenWhite, kingBlack, kingWhite;
HBITMAP pawnBlack_s, pawnWhite_s, knightBlack_s, knight2Black_s, knightWhite_s, knight2White_s, rookBlack_s, rook2Black_s, rookWhite_s, rook2White_s, bishopBlack_s, bishop2Black_s, bishopWhite_s, bishop2White_s, queenBlack_s, queenWhite_s, kingBlack_s, kingWhite_s;
HBITMAP pawnBlack_ss, pawnWhite_ss, knightBlack_ss, knight2Black_ss, knightWhite_ss, knight2White_ss, rookBlack_ss, rook2Black_ss, rookWhite_ss, rook2White_ss, bishopBlack_ss, bishop2Black_ss, bishopWhite_ss, bishop2White_ss, queenBlack_ss, queenWhite_ss, kingBlack_ss, kingWhite_ss;

HINSTANCE		ghInstance = NULL ;
ATOM			RegisterWindowClass(HINSTANCE hInstance, char *pszWindowClassName) ;
BOOL			InitInstance(HINSTANCE, int, char *pszWindowClassName) ;
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM) ;
HBITMAP                 ReplaceColor(HBITMAP hBmp, COLORREF cOldColor,COLORREF cNewColor,HDC hBmpDC);

static HWND hwnd_timer, hwnd_white, hwnd_black, hwnd_newgamebtn, hwnd_downloadbtn, hwnd_quitbtn;

int x, w, y, h;

HANDLE thread_1;

HANDLE thread;

HANDLE sideLogoThread;

HANDLE wkThread;
HANDLE wqThread;
HANDLE wpThread;
HANDLE wr1Thread;
HANDLE wr2Thread;
HANDLE wb1Thread;
HANDLE wb2Thread;
HANDLE wk1Thread;
HANDLE wk2Thread;

int whiteKingStart = -1;
int whiteQueenStart = -1;
int whitePawnsStart = -1;
int whiteRook1Start = -1;
int whiteRook2Start = -1;
int whiteBishop1Start = -1;
int whiteBishop2Start = -1;
int whiteKnight1Start = -1;
int whiteKnight2Start = -1;

int whitePawnsIndex;
int whiteKingFunc;
int whiteQueenFunc;
int whitePawnsFunc;
int whiteRook1Func;
int whiteRook2Func;
int whiteBishop1Func;
int whiteBishop2Func;
int whiteKnight1Func;
int whiteKnight2Func;

HANDLE bkThread;
HANDLE bqThread;
HANDLE bpThread;
HANDLE br1Thread;
HANDLE br2Thread;
HANDLE bb1Thread;
HANDLE bb2Thread;
HANDLE bk1Thread;
HANDLE bk2Thread;

int blackKingStart = -1;
int blackQueenStart = -1;
int blackPawnsStart = -1;
int blackRook1Start = -1;
int blackRook2Start = -1;
int blackBishop1Start = -1;
int blackBishop2Start = -1;
int blackKnight1Start = -1;
int blackKnight2Start = -1;

int blackPawnsIndex;
int blackKingFunc;
int blackQueenFunc;
int blackPawnsFunc;
int blackRook1Func;
int blackRook2Func;
int blackBishop1Func;
int blackBishop2Func;
int blackKnight1Func;
int blackKnight2Func;

int timestampPast;
int timestampNow;
int min;
int sec;
int total;
int ws, wm;

int ttw = 0;
int timeToWait = 0;

time_t secs;
boolean turnChanged = FALSE;

HBRUSH hColorBrush = 0;

boolean gettingit = FALSE;

double difficulty = 2.0;

HMENU hMenu, hSubMenu;
HICON hIcon, hIconSm;
            
char *newGame = "new game";
char *getMine = "get mine";
char *captureScreen = "capture screen";
char *exitGame = "exit game";

char *pcGame = "> 1 PLAYER (HUMAN VERSUS P.C.)";
char *humanGame = "2 players (human versus human)";

char *easy = "> EASY";
char *medium = "medium";
char *hard = "hard";
char *impossible = "impossible";

char *zeroMin = "> NO TIME (2 PLAYERS)";
char *fiveMin = "5 mins (2 players)";
char *tenMin = "10 mins (2 players)";
char *fifteenMin = "15 mins (2 players)";
char *twentyMin = "20 mins (2 players)";
char *twentyFiveMin = "25 mins (2 players)";
char *thirtyMin = "30 mins (2 players)";
char *thirtyFiveMin = "35 mins (2 players)";
char *fortyMin = "40 mins (2 players)";
char *fortyFiveMin = "45 mins (2 players)";
char *fiftyMin = "50 mins (2 players)";
char *fiftyFiveMin = "55 mins (2 players)";
char *sixtyMin = "60 mins (2 players)";
char *sixtyFiveMin = "65 mins (2 players)";
char *seventyMin = "70 mins (2 players)";
char *seventyFiveMin = "75 mins (2 players)";
char *eightyMin = "80 mins (2 players)";
char *eightyFiveMin = "85 mins (2 players)";
char *ninetyMin = "90 mins (2 players)";

void paintWhiteKing(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(whiteKingFunc == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP kingWhites = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(kingWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteKing.posX+20, 
                              whiteKing.posY+11, 
                              whiteKing.posX+20+70,
                              whiteKing.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(kingWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteKing.posX+20, 
                              whiteKing.posY+11, 
                              whiteKing.posX+20+70,
                              whiteKing.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteKing.posX+25+0+ipt, whiteKing.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(kingWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteQueen(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(whiteQueenFunc == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP queenWhites = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(queenWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteQueen.posX+20, 
                              whiteQueen.posY+11, 
                              whiteQueen.posX+20+70,
                              whiteQueen.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(queenWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteQueen.posX+20, 
                              whiteQueen.posY+11, 
                              whiteQueen.posX+20+70,
                              whiteQueen.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteQueen.posX+25+0+ipt, whiteQueen.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(queenWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhitePawn(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(whitePawnsFunc == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP pawnWhites = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whitePawns[whitePawnsIndex].posX/70)+(whitePawns[whitePawnsIndex].posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(pawnWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whitePawns[whitePawnsIndex].posX+20, 
                              whitePawns[whitePawnsIndex].posY+11, 
                              whitePawns[whitePawnsIndex].posX+20+70,
                              whitePawns[whitePawnsIndex].posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(pawnWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whitePawns[whitePawnsIndex].posX+20, 
                              whitePawns[whitePawnsIndex].posY+11, 
                              whitePawns[whitePawnsIndex].posX+20+70,
                              whitePawns[whitePawnsIndex].posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whitePawns[whitePawnsIndex].posX+25+0+ipt, whitePawns[whitePawnsIndex].posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(pawnWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteRook1(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(whiteRook1Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP rookWhites = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(rookWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteRook1.posX+20, 
                              whiteRook1.posY+11, 
                              whiteRook1.posX+20+70,
                              whiteRook1.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(rookWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteRook1.posX+20, 
                              whiteRook1.posY+11, 
                              whiteRook1.posX+20+70,
                              whiteRook1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteRook1.posX+25+0+ipt, whiteRook1.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(rookWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteRook2(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(whiteRook2Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP rookWhites = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(rookWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteRook2.posX+20, 
                              whiteRook2.posY+11, 
                              whiteRook2.posX+20+70,
                              whiteRook2.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(rookWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteRook2.posX+20, 
                              whiteRook2.posY+11, 
                              whiteRook2.posX+20+70,
                              whiteRook2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteRook2.posX+25+0+ipt, whiteRook2.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(rookWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteBishop1(void *data) {
  
    int ipt;
  
    while(1) {
        if(whiteBishop1Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP bishopWhites = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(bishopWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteBishop1.posX+20, 
                              whiteBishop1.posY+11, 
                              whiteBishop1.posX+20+70,
                              whiteBishop1.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(bishopWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteBishop1.posX+20, 
                              whiteBishop1.posY+11, 
                              whiteBishop1.posX+20+70,
                              whiteBishop1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteBishop1.posX+25+0+ipt, whiteBishop1.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(bishopWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteBishop2(void *data) {
  
    int ipt;
  
    while(1) {
        if(whiteBishop2Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP bishopWhites = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(bishopWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteBishop2.posX+20, 
                              whiteBishop2.posY+11, 
                              whiteBishop2.posX+20+70,
                              whiteBishop2.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(bishopWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteBishop2.posX+20, 
                              whiteBishop2.posY+11, 
                              whiteBishop2.posX+20+70,
                              whiteBishop2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteBishop2.posX+25+0+ipt, whiteBishop2.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(bishopWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteKnight1(void *data) {
  
    int ipt;
  
    while(1) {
        if(whiteKnight1Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP knightWhites = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(knightWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteKnight1.posX+20, 
                              whiteKnight1.posY+11, 
                              whiteKnight1.posX+20+70,
                              whiteKnight1.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(knightWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteKnight1.posX+20, 
                              whiteKnight1.posY+11, 
                              whiteKnight1.posX+20+70,
                              whiteKnight1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteKnight1.posX+25+0+ipt, whiteKnight1.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(knightWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintWhiteKnight2(void *data) {
  
    int ipt;
  
    while(1) {
        if(whiteKnight2Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP knightWhites = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(knightWhites,0x110000,0xffffff,hdcMems);
                HBRUSH white_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {whiteKnight2.posX+20, 
                              whiteKnight2.posY+11, 
                              whiteKnight2.posX+20+70,
                              whiteKnight2.posY+11+70};
                FillRect(hdc, &rrect, white_brush);
                DeleteObject(white_brush);
            } else {
                hBmp = ReplaceColor(knightWhites,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {whiteKnight2.posX+20, 
                              whiteKnight2.posY+11, 
                              whiteKnight2.posX+20+70,
                              whiteKnight2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, whiteKnight2.posX+25+0+ipt, whiteKnight2.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(knightWhites);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackKing(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(blackKingFunc == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP kingBlacks = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(kingBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackKing.posX+20, 
                              blackKing.posY+11, 
                              blackKing.posX+20+70,
                              blackKing.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(kingBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackKing.posX+20, 
                              blackKing.posY+11, 
                              blackKing.posX+20+70,
                              blackKing.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackKing.posX+25+0+ipt, blackKing.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(kingBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackQueen(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(blackQueenFunc == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP queenBlacks = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(queenBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackQueen.posX+20, 
                              blackQueen.posY+11, 
                              blackQueen.posX+20+70,
                              blackQueen.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(queenBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackQueen.posX+20, 
                              blackQueen.posY+11, 
                              blackQueen.posX+20+70,
                              blackQueen.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackQueen.posX+25+0+ipt, blackQueen.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(queenBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackPawn(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(blackPawnsFunc == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP pawnBlacks = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackPawns[blackPawnsIndex].posX/70)+(blackPawns[blackPawnsIndex].posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(pawnBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackPawns[blackPawnsIndex].posX+20, 
                              blackPawns[blackPawnsIndex].posY+11, 
                              blackPawns[blackPawnsIndex].posX+20+70,
                              blackPawns[blackPawnsIndex].posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(pawnBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackPawns[blackPawnsIndex].posX+20, 
                              blackPawns[blackPawnsIndex].posY+11, 
                              blackPawns[blackPawnsIndex].posX+20+70,
                              blackPawns[blackPawnsIndex].posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackPawns[blackPawnsIndex].posX+25+0+ipt, blackPawns[blackPawnsIndex].posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(pawnBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackRook1(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(blackRook1Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP rookBlacks = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(rookBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackRook1.posX+20, 
                              blackRook1.posY+11, 
                              blackRook1.posX+20+70,
                              blackRook1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(rookBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackRook1.posX+20, 
                              blackRook1.posY+11, 
                              blackRook1.posX+20+70,
                              blackRook1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackRook1.posX+25+0+ipt, blackRook1.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(rookBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackRook2(void *data) {
  
    int ipt;
  
    while(TRUE) {
        if(blackRook2Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP rookBlacks = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(rookBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackRook2.posX+20, 
                              blackRook2.posY+11, 
                              blackRook2.posX+20+70,
                              blackRook2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(rookBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackRook2.posX+20, 
                              blackRook2.posY+11, 
                              blackRook2.posX+20+70,
                              blackRook2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackRook2.posX+25+0+ipt, blackRook2.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(rookBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackBishop1(void *data) {
  
    int ipt;
  
    while(1) {
        if(blackBishop1Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP bishopBlacks = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(bishopBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackBishop1.posX+20, 
                              blackBishop1.posY+11, 
                              blackBishop1.posX+20+70,
                              blackBishop1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(bishopBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackBishop1.posX+20, 
                              blackBishop1.posY+11, 
                              blackBishop1.posX+20+70,
                              blackBishop1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackBishop1.posX+25+0+ipt, blackBishop1.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(bishopBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackBishop2(void *data) {
  
    int ipt;
  
    while(1) {
        if(blackBishop2Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP bishopBlacks = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(bishopBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackBishop2.posX+20, 
                              blackBishop2.posY+11, 
                              blackBishop2.posX+20+70,
                              blackBishop2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(bishopBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackBishop2.posX+20, 
                              blackBishop2.posY+11, 
                              blackBishop2.posX+20+70,
                              blackBishop2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackBishop2.posX+25+0+ipt, blackBishop2.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(bishopBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackKnight1(void *data) {
  
    int ipt;
  
    while(1) {
        if(blackKnight1Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP knightBlacks = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(knightBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackKnight1.posX+20, 
                              blackKnight1.posY+11, 
                              blackKnight1.posX+20+70,
                              blackKnight1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(knightBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackKnight1.posX+20, 
                              blackKnight1.posY+11, 
                              blackKnight1.posX+20+70,
                              blackKnight1.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackKnight1.posX+25+0+ipt, blackKnight1.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(knightBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void paintBlackKnight2(void *data) {
  
    int ipt;
  
    while(1) {
        if(blackKnight2Func == -1) {
            break;
        } else {
            //ppp();
            Sleep(50);
            HBITMAP knightBlacks = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hdcMems = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0) {
                hBmp = ReplaceColor(knightBlacks,0x110000,0xffffff,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(255,255,255));
                RECT rrect = {blackKnight2.posX+20, 
                              blackKnight2.posY+11, 
                              blackKnight2.posX+20+70,
                              blackKnight2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            } else {
                hBmp = ReplaceColor(knightBlacks,0x110000,0x000000,hdcMems);
                HBRUSH black_brush = CreateSolidBrush(RGB(0,0,0));
                RECT rrect = {blackKnight2.posX+20, 
                              blackKnight2.posY+11, 
                              blackKnight2.posX+20+70,
                              blackKnight2.posY+11+70};
                FillRect(hdc, &rrect, black_brush);
                DeleteObject(black_brush);
            }
            oldBitmaps = SelectObject(hdcMems, hBmp);
            GetObject(hBmp, sizeof(bitmaps), &bitmaps);
            BitBlt(hdc, blackKnight2.posX+25+0+ipt, blackKnight2.posY+25, 46, 46, hdcMems, 0, 0, SRCCOPY);
            SelectObject(hdcMems, oldBitmaps);
            ReleaseDC(hwnd, hdcMems); DeleteDC(hdcMems); DeleteObject(hBmp);
            DeleteObject(knightBlacks);

            if(ipt == 17)
                ipt = 0;

            ipt++;
        }
    }
}

void SetMyMenu(int option) {

    DeleteObject(hMenu);

    DeleteObject(hSubMenu);
  
    hMenu = CreateMenu();

    hSubMenu = CreatePopupMenu();
    
    AppendMenu(hSubMenu, MF_STRING, ID_CLICK_ME_NEW_GAME, newGame);
    AppendMenu(hSubMenu, MF_STRING, ID_FILE_DOWNLOAD, getMine);
    AppendMenu(hSubMenu, MF_STRING, ID_CAPTURE_SCREEN, captureScreen);
    AppendMenu(hSubMenu, MF_STRING, ID_CLICK_ME_QUIT, exitGame);
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "File");

    if(option == 1) {
        pcGame = "> 1 PLAYER (HUMAN VERSUS P.C.)";
        humanGame = "2 players (human versus human)";
    }

    if(option == 2) {
        pcGame = "1 player (human versus P.C.)";
        humanGame = "> 2 PLAYERS (HUMAN VERSUS HUMAN)";
    }
    
    hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, ID_PC_GAME, pcGame);
    AppendMenu(hSubMenu, MF_STRING, ID_HUMAN_GAME, humanGame);
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Player Options");

    if(option == 3) {
        easy = "> EASY";
        medium = "medium";
        hard = "hard";
        impossible = "impossible";
    }

    if(option == 4) {
        easy = "easy";
        medium = "> MEDIUM";
        hard = "hard";
        impossible = "impossible";
    }

    if(option == 5) {
        easy = "easy";
        medium = "medium";
        hard = "> HARD";
        impossible = "impossible";
    }

    if(option == 6) {
        easy = "easy";
        medium = "medium";
        hard = "hard";
        impossible = "> IMPOSSIBLE";
    }

    hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, ID_EASY, easy);
    AppendMenu(hSubMenu, MF_STRING, ID_MEDIUM, medium);
    AppendMenu(hSubMenu, MF_STRING, ID_HARD, hard);
    AppendMenu(hSubMenu, MF_STRING, ID_IMPOSSIBLE, impossible);
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "1 Player Difficulty Options");

    if(option == 7) {
        zeroMin = "> NO TIME (2 PLAYERS)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 8) {
        zeroMin = "no time (2 players)";
        fiveMin = "> 5 MINS (2 PLAYERS)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 9) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "> 10 MINS (2 PLAYERS)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 10) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "> 15 MINS (2 PLAYERS)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 11) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "> 20 MINS (2 PLAYERS)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 12) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "> 25 MINS (2 PLAYERS)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 13) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "> 30 MINS (2 PLAYERS)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 14) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "> 35 MINS (2 PLAYERS)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 15) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "> 40 MINS (2 PLAYERS)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 16) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "> 45 MINS (2 PLAYERS)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 17) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "> 50 MINS (2 PLAYERS)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 18) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "> 55 MINS (2 PLAYERS)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 19) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "> 60 MINS (2 PLAYERS)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 20) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "> 65 MINS (2 PLAYERS)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 21) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "> 70 MINS (2 PLAYERS)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 22) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "> 75 MINS (2 PLAYERS)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 23) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "> 80 MINS (2 PLAYERS)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 24) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "> 85 MINS (2 PLAYERS)";
        ninetyMin = "90 mins (2 players)";
    }

    if(option == 25) {
        zeroMin = "no time (2 players)";
        fiveMin = "5 mins (2 players)";
        tenMin = "10 mins (2 players)";
        fifteenMin = "15 mins (2 players)";
        twentyMin = "20 mins (2 players)";
        twentyFiveMin = "25 mins (2 players)";
        thirtyMin = "30 mins (2 players)";
        thirtyFiveMin = "35 mins (2 players)";
        fortyMin = "40 mins (2 players)";
        fortyFiveMin = "45 mins (2 players)";
        fiftyMin = "50 mins (2 players)";
        fiftyFiveMin = "55 mins (2 players)";
        sixtyMin = "60 mins (2 players)";
        sixtyFiveMin = "65 mins (2 players)";
        seventyMin = "70 mins (2 players)";
        seventyFiveMin = "75 mins (2 players)";
        eightyMin = "80 mins (2 players)";
        eightyFiveMin = "85 mins (2 players)";
        ninetyMin = "> 90 MINS (2 PLAYERS)";
    }

    hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_0MIN, zeroMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_5MIN, fiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_10MIN, tenMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_15MIN, fifteenMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_20MIN, twentyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_25MIN, twentyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_30MIN, thirtyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_35MIN, thirtyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_40MIN, fortyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_45MIN, fortyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_50MIN, fiftyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_55MIN, fiftyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_60MIN, sixtyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_65MIN, sixtyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_70MIN, seventyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_75MIN, seventyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_80MIN, eightyMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_85MIN, eightyFiveMin);
    AppendMenu(hSubMenu, MF_STRING, ID_TIMER_90MIN, ninetyMin);
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Timer Settings");

    hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, ID_ABOUT, "about");
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Help");

    SetMenu(hwnd, hMenu);
}

LRESULT CALLBACK aboutWindowProcess(HWND hwnd2, UINT msg, WPARAM wParam, LPARAM lParam) {
    
    switch(msg) {
        case WM_PAINT: {
            hBitmapAbout = (HBITMAP)LoadImage(hInst, "about.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            hdc2 = BeginPaint(hwnd2, &ps);
            hdcMem = CreateCompatibleDC(hdc2);

            oldBitmap = SelectObject(hdcMem, hBitmapAbout);

            GetObject(hBitmapAbout, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 0, 0, 504, 539, hdcMem, 0, 0, SRCCOPY);

            SelectObject(hdcMem, oldBitmap);
            DeleteDC(hdcMem); DeleteObject(hBitmapAbout);
            DeleteObject(hBitmapAbout);

            EndPaint(hwnd2, &ps);
        }
        break;
        case WM_DESTROY: {
            return 0;
        }
        break;
    }

    return DefWindowProc(hwnd2, msg, wParam, lParam);
}

int GetTextSize(LPSTR a0) {
    for(int iLoopCounter = 0;;iLoopCounter++) {
        if(a0[iLoopCounter] == '\0') {
            return iLoopCounter;
        }
    }
}

char *replaceWord(const char *s, const char *oldW,
                                 const char *newW) {
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
 
    for(i=0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
            i += oldWlen - 1;
        }
    }
 
    result = (char*) malloc(i + cnt * (newWlen - oldWlen) + 1);
 
    i = 0;
    while (*s) {
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else {
            result[i++] = *s++;
        }
    }
 
    result[i] = '\0';
    return result;
}

int indexOf_shift (char* base, char* str, int startIndex) {
    int result;
    int baselen = strlen(base);
    // str should not longer than base
    if (strlen(str) > baselen || startIndex > baselen) {
        result = -1;
    } else {
        if (startIndex < 0 ) {
            startIndex = 0;
        }
        char* pos = strstr(base+startIndex, str);
        if (pos == NULL) {
            result = -1;
        } else {
            result = pos - base;
        }
    }
    return result;
}

int lastIndexOf (char* base, char* str) {
    int result;
    // str should not longer than base
    if (strlen(str) > strlen(base)) {
        result = -1;
    } else {
        int start = 0;
        int endinit = strlen(base) - strlen(str);
        int end = endinit;
        int endtmp = endinit;
        while(start != end) {
            start = indexOf_shift(base, str, start);
            end = indexOf_shift(base, str, end);

            // not found from start
            if (start == -1) {
                end = -1; // then break;
            } else if (end == -1) {
                // found from start
                // but not found from end
                // move end to middle
                if (endtmp == (start+1)) {
                    end = start; // then break;
                } else {
                    end = endtmp - (endtmp - start) / 2;
                    if (end <= start) {
                        end = start+1;
                    }
                    endtmp = end;
                }
            } else {
                // found from both start and end
                // move start to end and
                // move end to base - strlen(str)
                start = end;
                end = endinit;
            }
        }
        result = start;
    }
    return result;
}

void removeChar( char * string, char letter ) {
  int i1 = 0;
  for( unsigned int i = 0; i < strlen( string ); i++ )
    if( string[i] == letter ) {
      if(letter == ' ') {
        i1++;
      }
      strcpy( string + i, string + i + 1 );
    }
  if(letter == ' ')
    wLMSize = ++i1;
}

void paintSideLogo() {

    int ipp;
    
    while(1) {
        Sleep(3);

        hBitmapSideLogo = (HBITMAP)LoadImage(hInst, "sidelogo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        
        hdcMem = CreateCompatibleDC(hdc);
        oldBitmap = SelectObject(hdcMem, hBitmapSideLogo);

        GetObject(hBitmapSideLogo, sizeof(bitmap), &bitmap);
        BitBlt(hdc, 976, 0+ipp, 1030, 740+ipp, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, oldBitmap);
        DeleteDC(hdcMem); DeleteObject(hBitmapSideLogo);

        ipp++;
        
        if(ipp == 600)
            ipp = 0;
    }
}

void getApiUnderwaterChessDotComMove(char *frm, char *too) {

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 2, 2 );

    err = WSAStartup( wVersionRequested, &wsaData );
    if(err != 0) {
        printf("no winsock.");
        return;
    }

    int portno = 80;
    char *host = "api.underwaterchess.com";

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char message[1024],response[8192];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("ERROR opening socket");
    }

    server = gethostbyname(host);
    if(server == NULL) {
        printf("ERROR, no such host");
    }

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("ERROR connecting");
    }

    char *str_2 = (char*) malloc(1 + strlen(gt)+ strlen(fen)+ strlen("&move=")+ strlen(frm)+ strlen(too)+ strlen(hstt));
    strcpy(str_2, gt);
    strcat(str_2, fen);
    strcat(str_2, "&move=");
    strcat(str_2, frm);
    strcat(str_2, too);
    strcat(str_2, hstt);
    char *str = (char *) malloc(1 + strlen(str_2));
    strcpy(str, str_2);

    int length = strlen(str);
    int x = send(sockfd, str, length, 0);
    if(x == SOCKET_ERROR) {
        printf("socket error");
    }
    
    do {
        iResult = recv(sockfd, response, 8192, 0);
    } while(iResult > 0);

    printf(response);

    char *aab = strstr(response, "color\": \"");
    char *taf = (char *) malloc(5);
    strncpy(taf, aab+9, 5);
    
    char *ab = (char *) malloc(100);
    ab = strstr(response, "isCheckmate\": ");
    char *tf = (char *) malloc(4);
    strncpy(tf, ab+14, 4);

    char *isin;
    char *c = (char *) malloc(1);
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        isin = strstr(response, "isInCheck\": ");
        strncpy(c, isin+12, 1);
    }
    
    char *wLegalMoves;
    char *l1 = (char *) malloc(1000);
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'w') {
            l1 = strstr(response, "[");
            int iii = strcspn(l1,"]");
            wLegalMoves = malloc(iii);
            strncpy(wLegalMoves,l1+1,iii-1);
            wLegalMoves[iii-1] = '\0';
            removeChar(wLegalMoves, '\"');
            removeChar(wLegalMoves, ' ');
            printf("Size of wLMSize: %d", wLMSize);
            char *token = strtok(wLegalMoves, ",");
            wLM[0] = token;
            printf(wLM[0]);
            printf("\n\n");
            int qq = 1;
            while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, ",");
                wLM[qq] = token;
                qq++;
            }
        }
    }

    char *legalMoves;
    char *l = (char *) malloc(1000);
    int ert;
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'b' && c[0] == 'f') {
            l = strstr(response, "[");
            int iii = strcspn(l,"]");
            int yte = iii - 2;
            ert = yte - 6;
            ert = (int)round((double)ert / 8.0) + 1;
            legalMoves = (char *) malloc(iii);
            strncpy(legalMoves,l+1,iii-1);
            legalMoves[iii-1] = '\0';
            printf(legalMoves);
        }
    }
    
    boolean useLegalMoves = FALSE;
    int randomnumber;
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'b' && c[0] == 'f') {
            srand(time(NULL));
            randomnumber = rand() % ert;
            printf("%d\n", randomnumber);
            int rad = (int)round((double)ert / difficulty);
            if(ert != 1 && randomnumber != 1) {
                if(randomnumber >= 0 && randomnumber <= rad) {
                    useLegalMoves = TRUE;
                    randomnumber = rand() % ert;
                }
            } else {
                useLegalMoves = TRUE;
            }
        }
    }
    
    char *a = strstr(response, "fen\": \"");
    char *fee = (char*) malloc(200);
    char *aaa = NULL;
    int i = 0;
    strncpy(fee, a+7, 93);
    i = strcspn(fee,",");    
    fen = (char*) malloc(i);
    strncpy(fen, fee, i-1);
    fen[i-1] = '\0';
    aaa = replaceWord(fen, "/", "%2F");
    fen = aaa;
    aaa = replaceWord(fen, " ", "+");
    fen = aaa;

    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'b') {
            if(useLegalMoves == FALSE || c[0] == 't') {
                char *b = strstr(response, "bestMove\": \"");
                strncpy(bestMove, b+12, 4);
            } else {
                printf("%d\n", randomnumber);
                strncpy(bestMove,legalMoves+((randomnumber-1)*8)+1,4);
            }
            printf("\r\nbest move :: ");
            printf(bestMove);
            printf("\r\n\r\n");
        }
    } else {
        checkmate = TRUE;
        if(taf[0]=='w') {
            MessageBox(hwnd,"Black wins! Checkmate!","Black Wins",MB_OK);
            PlaySound(TEXT("ding.wav"), NULL, SND_FILENAME);
        } else if(taf[0]=='b') {
            MessageBox(hwnd,"White wins! Checkmate!","White Wins",MB_OK);
            PlaySound(TEXT("a-team_plan.wav"), NULL, SND_FILENAME);
        }
    }

    /* close the socket */
    close(sockfd);
    
    WSACleanup();
}

void getApiUnderwaterChessDotComMove2(char *frm, char *too) {

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 2, 2 );

    err = WSAStartup( wVersionRequested, &wsaData );
    if(err != 0) {
        printf("no winsock.");
        return;
    }

    int portno = 80;
    char *host = "api.underwaterchess.com";

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char message[1024],response[8192];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("ERROR opening socket");
    }

    server = gethostbyname(host);
    if(server == NULL) {
        printf("ERROR, no such host");
    }

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("ERROR connecting");
    }

    char *str_2 = (char*) malloc(1 + strlen(gt)+ strlen(fen2)+ strlen("&move=")+ strlen(frm)+ strlen(too)+ strlen(hstt));
    strcpy(str_2, gt);
    strcat(str_2, fen2);
    strcat(str_2, "&move=");
    strcat(str_2, frm);
    strcat(str_2, too);
    strcat(str_2, hstt);
    char *str = (char *) malloc(1 + strlen(str_2));
    strcpy(str, str_2);

    int length = strlen(str);
    int x = send(sockfd, str, length, 0);
    if(x == SOCKET_ERROR) {
        printf("socket error");
    }
    
    do {
        iResult = recv(sockfd, response, 8192, 0);
    } while(iResult > 0);

    printf(response);

    char *aab = strstr(response, "color\": \"");
    char *taf = (char *) malloc(5);
    strncpy(taf, aab+9, 5);
    
    char *ab = (char *) malloc(100);
    ab = strstr(response, "isCheckmate\": ");
    char *tf = (char *) malloc(4);
    strncpy(tf, ab+14, 4);

    char *isin;
    char *c = (char *) malloc(1);
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        isin = strstr(response, "isInCheck\": ");
        strncpy(c, isin+12, 1);
    }
    
    char *LegalMoves;
    char *l1 = (char *) malloc(1000);
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'w' || taf[0] == 'b') {
            l1 = strstr(response, "[");
            int iii = strcspn(l1,"]");
            LegalMoves = malloc(iii);
            strncpy(LegalMoves,l1+1,iii-1);
            LegalMoves[iii-1] = '\0';
            removeChar(LegalMoves, '\"');
            removeChar(LegalMoves, ' ');
            printf("Size of wLMSize: %d", wLMSize);
            char *token = strtok(LegalMoves, ",");
            wLM[0] = token;
            printf(wLM[0]);
            printf("\n\n");
            int qq = 1;
            while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, ",");
                wLM[qq] = token;
                qq++;
            }
        }
    }

    char *legalMoves;
    char *l = (char *) malloc(1000);
    int ert;
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'b' && c[0] == 'f') {
            l = strstr(response, "[");
            int iii = strcspn(l,"]");
            int yte = iii - 2;
            ert = yte - 6;
            ert = (int)round((double)ert / 8.0) + 1;
            legalMoves = (char *) malloc(iii);
            strncpy(legalMoves,l+1,iii-1);
            legalMoves[iii-1] = '\0';
            printf(legalMoves);
        }
    }
    
    boolean useLegalMoves = FALSE;
    int randomnumber;
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {
        if(taf[0] == 'b' && c[0] == 'f') {
            srand(time(NULL));
            randomnumber = rand() % ert;
            printf("%d\n", randomnumber);
            int rad = (int)round((double)ert / difficulty);
            if(ert != 1 && randomnumber != 1) {
                if(randomnumber >= 0 && randomnumber <= rad) {
                    useLegalMoves = TRUE;
                    randomnumber = rand() % ert;
                }
            } else {
                useLegalMoves = TRUE;
            }
        }
    }
    
    char *a = strstr(response, "fen\": \"");
    char *fee = (char*) malloc(200);
    char *aaa = NULL;
    int i = 0;
    strncpy(fee, a+7, 93);
    i = strcspn(fee,",");    
    fen2 = (char*) malloc(i);
    strncpy(fen2, fee, i-1);
    fen2[i-1] = '\0';
    aaa = replaceWord(fen2, "/", "%2F");
    fen2 = aaa;
    aaa = replaceWord(fen2, " ", "+");
    fen2 = aaa;

    if(tf[0]=='t' &&
       tf[1]=='r' &&
       tf[2]=='u' &&
       tf[3]=='e') {
        checkmate = TRUE;
        if(taf[0]=='w') {
            MessageBox(hwnd,"Black wins! Checkmate!","Black Wins",MB_OK);
            PlaySound(TEXT("a-team_plan.wav"), NULL, SND_FILENAME);
        } else if(taf[0]=='b') {
            MessageBox(hwnd,"White wins! Checkmate!","White Wins",MB_OK);
            PlaySound(TEXT("a-team_plan.wav"), NULL, SND_FILENAME);
        }
    }

    /* close the socket */
    close(sockfd);
    
    WSACleanup();
}

DWORD WINAPI callApi(void *data) {

    gettingit = TRUE;
    
    tft = TRUE;

    getApiUnderwaterChessDotComMove(from, to);

    boolean refreshme = FALSE;

    if(bestMove != NULL) {
        boolean changeiii = FALSE;
        for(int z=0; z<8; z++) {
            if(blackPawns[z].posY == 20+reMap(bestMove,1) &&
               420+20 == blackPawns[z].posY &&
               blackPawns[z].posX == 20+reMap(bestMove,0)) {
                strncpy(chosenPiece, "qr", 2);
                changeiii = TRUE;
                blackPawns[z].from = map((blackPawns[z].posY-20)/70, (blackPawns[z].posX-20)/70);
                int x = 20+re_Map(bestMove,0);
                int y = 20+re_Map(bestMove,1);
                blackQueenK[z].posX = x;
                blackQueenK[z].posY = y;
                blackQueenK[z].from = map((y-20)/70, (x-20)/70);
                blackQueenK[z].to = map((y-20)/70, (x-20)/70);
                blackPawns[z].to = map((y-20)/70, (x-20)/70);
                strcat(blackPawns[z].to,"q");
                getApiUnderwaterChessDotComMove(
                      blackPawns[z].from,
                      blackPawns[z].to);
                refreshme = TRUE;
                blackPawns[z].posX = 1300;
                blackPawns[z].posY = -1000;
            }
        }
    }
    if(bestMove != NULL &&
       blackKnight1.posX == 20+reMap(bestMove,0)) {
        if(blackKnight1.posY == 20+reMap(bestMove,1)) {
            blackKnight1.from = map(blackKnight1.posY/70, blackKnight1.posX/70);
            blackKnight1.posY = 20+re_Map(bestMove,1);
            blackKnight1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackKnight1.posX == whitePawns[z].posX &&
                   blackKnight1.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackKnight1.posX == whiteRook1.posX &&
               blackKnight1.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackKnight1.posX == whiteRook2.posX &&
               blackKnight1.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackKnight1.posX == whiteKnight1.posX &&
               blackKnight1.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackKnight1.posX == whiteKnight2.posX &&
               blackKnight1.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackKnight1.posX == whiteBishop1.posX &&
               blackKnight1.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackKnight1.posX == whiteBishop2.posX &&
               blackKnight1.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackKnight1.posX == whiteQueen.posX &&
               blackKnight1.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackKnight1.to = map(blackKnight1.posY/70, blackKnight1.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackKnight1.from,
                  blackKnight1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackKnight2.posX == 20+reMap(bestMove,0)) {
        if(blackKnight2.posY == 20+reMap(bestMove,1)) {
            blackKnight2.from = map(blackKnight2.posY/70, blackKnight2.posX/70);
            blackKnight2.posY = 20+re_Map(bestMove,1);
            blackKnight2.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackKnight2.posX == whitePawns[z].posX &&
                   blackKnight2.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackKnight2.posX == whiteRook1.posX &&
               blackKnight2.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackKnight2.posX == whiteRook2.posX &&
               blackKnight2.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackKnight2.posX == whiteKnight1.posX &&
               blackKnight2.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackKnight2.posX == whiteKnight2.posX &&
               blackKnight2.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackKnight2.posX == whiteBishop1.posX &&
               blackKnight2.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackKnight2.posX == whiteBishop2.posX &&
               blackKnight2.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackKnight2.posX == whiteQueen.posX &&
               blackKnight2.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackKnight2.to = map(blackKnight2.posY/70, blackKnight2.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackKnight2.from,
                  blackKnight2.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackBishop1.posX == 20+reMap(bestMove,0)) {
        if(blackBishop1.posY == 20+reMap(bestMove,1)) {
            blackBishop1.from = map(blackBishop1.posY/70, blackBishop1.posX/70);
            blackBishop1.posY = 20+re_Map(bestMove,1);
            blackBishop1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackBishop1.posX == whitePawns[z].posX &&
                   blackBishop1.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackBishop1.posX == whiteRook1.posX &&
               blackBishop1.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackBishop1.posX == whiteRook2.posX &&
               blackBishop1.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackBishop1.posX == whiteKnight1.posX &&
               blackBishop1.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackBishop1.posX == whiteKnight2.posX &&
               blackBishop1.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackBishop1.posX == whiteBishop1.posX &&
               blackBishop1.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackBishop1.posX == whiteBishop2.posX &&
               blackBishop1.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackBishop1.posX == whiteQueen.posX &&
               blackBishop1.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackBishop1.to = map(blackBishop1.posY/70, blackBishop1.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackBishop1.from,
                  blackBishop1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackBishop2.posX == 20+reMap(bestMove,0)) {
        if(blackBishop2.posY == 20+reMap(bestMove,1)) {
            blackBishop2.from = map(blackBishop2.posY/70, blackBishop2.posX/70);
            blackBishop2.posY = 20+re_Map(bestMove,1);
            blackBishop2.posX = 20+re_Map(bestMove,0);
                for(int z=0; z<8; z++) {
                    if(blackBishop2.posX == whitePawns[z].posX &&
                       blackBishop2.posY == whitePawns[z].posY) {
                        whitePawns[z].posX = 1300;
                    }
                }
                if(blackBishop2.posX == whiteRook1.posX &&
                   blackBishop2.posY == whiteRook1.posY) {
                    whiteRook1.posX = 1300;
                }
                if(blackBishop2.posX == whiteRook2.posX &&
                   blackBishop2.posY == whiteRook2.posY) {
                    whiteRook2.posX = 1300;
                }
                if(blackBishop2.posX == whiteKnight1.posX &&
                   blackBishop2.posY == whiteKnight1.posY) {
                    whiteKnight1.posX = 1300;
                }
                if(blackBishop2.posX == whiteKnight2.posX &&
                   blackBishop2.posY == whiteKnight2.posY) {
                    whiteKnight2.posX = 1300;
                }
                if(blackBishop2.posX == whiteBishop1.posX &&
                   blackBishop2.posY == whiteBishop1.posY) {
                    whiteBishop1.posX = 1300;
                }
                if(blackBishop2.posX == whiteBishop2.posX &&
                   blackBishop2.posY == whiteBishop2.posY) {
                    whiteBishop2.posX = 1300;
                }
                if(blackBishop2.posX == whiteQueen.posX &&
                   blackBishop2.posY == whiteQueen.posY) {
                    whiteQueen.posX = 1300;
                }
            blackBishop2.to = map(blackBishop2.posY/70, blackBishop2.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackBishop2.from,
                  blackBishop2.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackRook1.posX == 20+reMap(bestMove,0)) {
        if(blackRook1.posY == 20+reMap(bestMove,1)) {
            blackRook1.from = map(blackRook1.posY/70, blackRook1.posX/70);
            blackRook1.posY = 20+re_Map(bestMove,1);
            blackRook1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackRook1.posX == whitePawns[z].posX &&
                   blackRook1.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackRook1.posX == whiteRook1.posX &&
               blackRook1.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackRook1.posX == whiteRook2.posX &&
               blackRook1.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackRook1.posX == whiteKnight1.posX &&
               blackRook1.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackRook1.posX == whiteKnight2.posX &&
               blackRook1.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackRook1.posX == whiteBishop1.posX &&
               blackRook1.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackRook1.posX == whiteBishop2.posX &&
               blackRook1.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackRook1.posX == whiteQueen.posX &&
               blackRook1.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackRook1.to = map(blackRook1.posY/70, blackRook1.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackRook1.from,
                  blackRook1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackRook2.posX == 20+reMap(bestMove,0)) {
        if(blackRook2.posY == 20+reMap(bestMove,1)) {
            blackRook2.from = map(blackRook2.posY/70, blackRook2.posX/70);
            blackRook2.posY = 20+re_Map(bestMove,1);
            blackRook2.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackRook2.posX == whitePawns[z].posX &&
                   blackRook2.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackRook2.posX == whiteRook1.posX &&
               blackRook2.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackRook2.posX == whiteRook2.posX &&
               blackRook2.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackRook2.posX == whiteKnight1.posX &&
               blackRook2.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackRook2.posX == whiteKnight2.posX &&
               blackRook2.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackRook2.posX == whiteBishop1.posX &&
               blackRook2.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackRook2.posX == whiteBishop2.posX &&
               blackRook2.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackRook2.posX == whiteQueen.posX &&
               blackRook2.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackRook2.to = map(blackRook2.posY/70, blackRook2.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackRook2.from,
                  blackRook2.to);
            refreshme = TRUE;
        }
    }
    for(int d=0; d<8; d++) {
        if(bestMove != NULL &&
           blackQueenK[d].posX == 20+reMap(bestMove,0)) {
            if(blackQueenK[d].posY == 20+reMap(bestMove,1)) {
                blackQueenK[d].from = map(blackQueenK[d].posY/70, blackQueenK[d].posX/70);
                blackQueenK[d].posY = 20+re_Map(bestMove,1);
                blackQueenK[d].posX = 20+re_Map(bestMove,0);
                for(int z=0; z<8; z++) {
                    if(blackQueenK[d].posX == whitePawns[z].posX &&
                       blackQueenK[d].posY == whitePawns[z].posY) {
                        whitePawns[z].posX = 1300;
                    }
                }
                if(blackQueenK[d].posX == whiteRook1.posX &&
                   blackQueenK[d].posY == whiteRook1.posY) {
                    whiteRook1.posX = 1300;
                }
                if(blackQueenK[d].posX == whiteRook2.posX &&
                   blackQueenK[d].posY == whiteRook2.posY) {
                    whiteRook2.posX = 1300;
                }
                if(blackQueenK[d].posX == whiteKnight1.posX &&
                   blackQueenK[d].posY == whiteKnight1.posY) {
                    whiteKnight1.posX = 1300;
                }
                if(blackQueenK[d].posX == whiteKnight2.posX &&
                   blackQueenK[d].posY == whiteKnight2.posY) {
                    whiteKnight2.posX = 1300;
                }
                if(blackQueenK[d].posX == whiteBishop1.posX &&
                   blackQueenK[d].posY == whiteBishop1.posY) {
                    whiteBishop1.posX = 1300;
                }
                if(blackQueenK[d].posX == whiteBishop2.posX &&
                   blackQueenK[d].posY == whiteBishop2.posY) {
                    whiteBishop2.posX = 1300;
                }
                if(blackQueenK[d].posX == whiteQueen.posX &&
                   blackQueenK[d].posY == whiteQueen.posY) {
                    whiteQueen.posX = 1300;
                }
                blackQueenK[d].to = map(blackQueenK[d].posY/70, blackQueenK[d].posX/70);
                getApiUnderwaterChessDotComMove(
                      blackQueenK[d].from,
                      blackQueenK[d].to);
                refreshme = TRUE;
            }
        }
    }
    if(bestMove != NULL &&
       blackQueen.posX == 20+reMap(bestMove,0)) {
        if(blackQueen.posY == 20+reMap(bestMove,1)) {
            blackQueen.from = map(blackQueen.posY/70, blackQueen.posX/70);
            blackQueen.posY = 20+re_Map(bestMove,1);
            blackQueen.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackQueen.posX == whitePawns[z].posX &&
                   blackQueen.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackQueen.posX == whiteRook1.posX &&
               blackQueen.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackQueen.posX == whiteRook2.posX &&
               blackQueen.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackQueen.posX == whiteKnight1.posX &&
               blackQueen.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackQueen.posX == whiteKnight2.posX &&
               blackQueen.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackQueen.posX == whiteBishop1.posX &&
               blackQueen.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackQueen.posX == whiteBishop2.posX &&
               blackQueen.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackQueen.posX == whiteQueen.posX &&
               blackQueen.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackQueen.to = map(blackQueen.posY/70, blackQueen.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackQueen.from,
                  blackQueen.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackKing.posX == 20+reMap(bestMove,0)) {
        if(blackKing.posY == 20+reMap(bestMove,1)) {
            blackKing.from = map(blackKing.posY/70, blackKing.posX/70);
            int xxxx = blackKing.posX;
            int yyyy = blackKing.posY;
            blackKing.posY = 20+re_Map(bestMove,1);
            blackKing.posX = 20+re_Map(bestMove,0);
            if(xxxx - blackKing.posX == 200) {
                blackRook1.posX += 300;
            }
            if(blackKing.posX - xxxx == 200) {
                blackRook2.posX -= 200;
            }
            for(int z=0; z<8; z++) {
                if(blackKing.posX == whitePawns[z].posX &&
                   blackKing.posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackKing.posX == whiteRook1.posX &&
               blackKing.posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackKing.posX == whiteRook2.posX &&
               blackKing.posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackKing.posX == whiteKnight1.posX &&
               blackKing.posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackKing.posX == whiteKnight2.posX &&
               blackKing.posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackKing.posX == whiteBishop1.posX &&
               blackKing.posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackKing.posX == whiteBishop2.posX &&
               blackKing.posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackKing.posX == whiteQueen.posX &&
               blackKing.posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackKing.to = map(blackKing.posY/70, blackKing.posX/70);
            getApiUnderwaterChessDotComMove(
                  blackKing.from,
                  blackKing.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[0].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[0].posY == 20+reMap(bestMove,1)) {
            blackPawns[0].from = map(blackPawns[0].posY/70, blackPawns[0].posX/70);
            blackPawns[0].posY = 20+re_Map(bestMove,1);
            blackPawns[0].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[0].posX == whitePawns[z].posX &&
                   blackPawns[0].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[0].posX == whiteRook1.posX &&
               blackPawns[0].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[0].posX == whiteRook2.posX &&
               blackPawns[0].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[0].posX == whiteKnight1.posX &&
               blackPawns[0].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[0].posX == whiteKnight2.posX &&
               blackPawns[0].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[0].posX == whiteBishop1.posX &&
               blackPawns[0].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[0].posX == whiteBishop2.posX &&
               blackPawns[0].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[0].posX == whiteQueen.posX &&
               blackPawns[0].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[0].to = map(blackPawns[0].posY/70, blackPawns[0].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[0].from,
                  blackPawns[0].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[1].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[1].posY == 20+reMap(bestMove,1)) {
            blackPawns[1].from = map(blackPawns[1].posY/70, blackPawns[1].posX/70);
            blackPawns[1].posY = 20+re_Map(bestMove,1);
            blackPawns[1].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[1].posX == whitePawns[z].posX &&
                   blackPawns[1].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[1].posX == whiteRook1.posX &&
               blackPawns[1].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[1].posX == whiteRook2.posX &&
               blackPawns[1].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[1].posX == whiteKnight1.posX &&
               blackPawns[1].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[1].posX == whiteKnight2.posX &&
               blackPawns[1].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[1].posX == whiteBishop1.posX &&
               blackPawns[1].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[1].posX == whiteBishop2.posX &&
               blackPawns[1].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[1].posX == whiteQueen.posX &&
               blackPawns[1].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[1].to = map(blackPawns[1].posY/70, blackPawns[1].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[1].from,
                  blackPawns[1].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[2].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[2].posY == 20+reMap(bestMove,1)) {
            blackPawns[2].from = map(blackPawns[2].posY/70, blackPawns[2].posX/70);
            blackPawns[2].posY = 20+re_Map(bestMove,1);
            blackPawns[2].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[2].posX == whitePawns[z].posX &&
                   blackPawns[2].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[2].posX == whiteRook1.posX &&
               blackPawns[2].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[2].posX == whiteRook2.posX &&
               blackPawns[2].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[2].posX == whiteKnight1.posX &&
               blackPawns[2].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[2].posX == whiteKnight2.posX &&
               blackPawns[2].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[2].posX == whiteBishop1.posX &&
               blackPawns[2].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[2].posX == whiteBishop2.posX &&
               blackPawns[2].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[2].posX == whiteQueen.posX &&
               blackPawns[2].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[2].to = map(blackPawns[2].posY/70, blackPawns[2].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[2].from,
                  blackPawns[2].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[3].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[3].posY == 20+reMap(bestMove,1)) {
            blackPawns[3].from = map(blackPawns[3].posY/70, blackPawns[3].posX/70);
            blackPawns[3].posY = 20+re_Map(bestMove,1);
            blackPawns[3].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[3].posX == whitePawns[z].posX &&
                   blackPawns[3].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[3].posX == whiteRook1.posX &&
               blackPawns[3].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[3].posX == whiteRook2.posX &&
               blackPawns[3].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[3].posX == whiteKnight1.posX &&
               blackPawns[3].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[3].posX == whiteKnight2.posX &&
               blackPawns[3].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[3].posX == whiteBishop1.posX &&
               blackPawns[3].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[3].posX == whiteBishop2.posX &&
               blackPawns[3].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[3].posX == whiteQueen.posX &&
               blackPawns[3].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[3].to = map(blackPawns[3].posY/70, blackPawns[3].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[3].from,
                  blackPawns[3].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[4].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[4].posY == 20+reMap(bestMove,1)) {
            blackPawns[4].from = map(blackPawns[4].posY/70, blackPawns[4].posX/70);
            blackPawns[4].posY = 20+re_Map(bestMove,1);
            blackPawns[4].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[4].posX == whitePawns[z].posX &&
                   blackPawns[4].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[4].posX == whiteRook1.posX &&
               blackPawns[4].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[4].posX == whiteRook2.posX &&
               blackPawns[4].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[4].posX == whiteKnight1.posX &&
               blackPawns[4].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[4].posX == whiteKnight2.posX &&
               blackPawns[4].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[4].posX == whiteBishop1.posX &&
               blackPawns[4].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[4].posX == whiteBishop2.posX &&
               blackPawns[4].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[4].posX == whiteQueen.posX &&
               blackPawns[4].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[4].to = map(blackPawns[4].posY/70, blackPawns[4].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[4].from,
                  blackPawns[4].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[5].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[5].posY == 20+reMap(bestMove,1)) {
            blackPawns[5].from = map(blackPawns[5].posY/70, blackPawns[5].posX/70);
            blackPawns[5].posY = 20+re_Map(bestMove,1);
            blackPawns[5].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[5].posX == whitePawns[z].posX &&
                   blackPawns[5].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[5].posX == whiteRook1.posX &&
               blackPawns[5].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[5].posX == whiteRook2.posX &&
               blackPawns[5].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[5].posX == whiteKnight1.posX &&
               blackPawns[5].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[5].posX == whiteKnight2.posX &&
               blackPawns[5].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[5].posX == whiteBishop1.posX &&
               blackPawns[5].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[5].posX == whiteBishop2.posX &&
               blackPawns[5].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[5].posX == whiteQueen.posX &&
               blackPawns[5].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[5].to = map(blackPawns[5].posY/70, blackPawns[5].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[5].from,
                  blackPawns[5].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[6].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[6].posY == 20+reMap(bestMove,1)) {
            blackPawns[6].from = map(blackPawns[6].posY/70, blackPawns[6].posX/70);
            blackPawns[6].posY = 20+re_Map(bestMove,1);
            blackPawns[6].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[6].posX == whitePawns[z].posX &&
                   blackPawns[6].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[6].posX == whiteRook1.posX &&
               blackPawns[6].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[6].posX == whiteRook2.posX &&
               blackPawns[6].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[6].posX == whiteKnight1.posX &&
               blackPawns[6].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[6].posX == whiteKnight2.posX &&
               blackPawns[6].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[6].posX == whiteBishop1.posX &&
               blackPawns[6].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[6].posX == whiteBishop2.posX &&
               blackPawns[6].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[6].posX == whiteQueen.posX &&
               blackPawns[6].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[6].to = map(blackPawns[6].posY/70, blackPawns[6].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[6].from,
                  blackPawns[6].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       blackPawns[7].posX == 20+reMap(bestMove,0)) {
        if(blackPawns[7].posY == 20+reMap(bestMove,1)) {
            blackPawns[7].from = map(blackPawns[7].posY/70, blackPawns[7].posX/70);
            blackPawns[7].posY = 20+re_Map(bestMove,1);
            blackPawns[7].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(blackPawns[7].posX == whitePawns[z].posX &&
                   blackPawns[7].posY == whitePawns[z].posY) {
                    whitePawns[z].posX = 1300;
                }
            }
            if(blackPawns[7].posX == whiteRook1.posX &&
               blackPawns[7].posY == whiteRook1.posY) {
                whiteRook1.posX = 1300;
            }
            if(blackPawns[7].posX == whiteRook2.posX &&
               blackPawns[7].posY == whiteRook2.posY) {
                whiteRook2.posX = 1300;
            }
            if(blackPawns[7].posX == whiteKnight1.posX &&
               blackPawns[7].posY == whiteKnight1.posY) {
                whiteKnight1.posX = 1300;
            }
            if(blackPawns[7].posX == whiteKnight2.posX &&
               blackPawns[7].posY == whiteKnight2.posY) {
                whiteKnight2.posX = 1300;
            }
            if(blackPawns[7].posX == whiteBishop1.posX &&
               blackPawns[7].posY == whiteBishop1.posY) {
                whiteBishop1.posX = 1300;
            }
            if(blackPawns[7].posX == whiteBishop2.posX &&
               blackPawns[7].posY == whiteBishop2.posY) {
                whiteBishop2.posX = 1300;
            }
            if(blackPawns[7].posX == whiteQueen.posX &&
               blackPawns[7].posY == whiteQueen.posY) {
                whiteQueen.posX = 1300;
            }
            blackPawns[7].to = map(blackPawns[7].posY/70, blackPawns[7].posX/70);
            getApiUnderwaterChessDotComMove(
                  blackPawns[7].from,
                  blackPawns[7].to);
            refreshme = TRUE;
        }
    }

    if(refreshme) {

        hdcMem = CreateCompatibleDC(hdc);
        oldBitmap = SelectObject(hdcMem, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, oldBitmap);
        DeleteDC(hdcMem); DeleteObject(hBitmap);

        DrawChessBoard();

        Sleep(1);
        pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hBmp;
        if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(rookWhite,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(rookWhite,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteRook1.posX+25+7, whiteRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(rook2White,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(rook2White,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteRook2.posX+25+7, whiteRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(knightWhite,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(knightWhite,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteKnight1.posX+25+7, whiteKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(knight2White,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(knight2White,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteKnight2.posX+25+7, whiteKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(bishopWhite,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(bishopWhite,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteBishop1.posX+25+7, whiteBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(bishop2White,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(bishop2White,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteBishop2.posX+25+7, whiteBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteQueen.posX+25+7, whiteQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        
        hdcMem = CreateCompatibleDC(hdc);
        if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(kingWhite,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(kingWhite,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, whiteKing.posX+25+7, whiteKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        for(int o=0; o<8; o++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((whitePawns[o].posX/70)+(whitePawns[o].posY/70)) % 2 == 0)
                hBmp = ReplaceColor(pawnWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(pawnWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whitePawns[o].posX+25+7, whitePawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(rookBlack,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackRook1.posX+25+7, blackRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(rook2Black,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackRook2.posX+25+7, blackRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(knightBlack,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(knightBlack,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackKnight1.posX+25+7, blackKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(knight2Black,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(knight2Black,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackKnight2.posX+25+7, blackKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(bishopBlack,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(bishopBlack,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackBishop1.posX+25+7, blackBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(bishop2Black,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(bishop2Black,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackBishop2.posX+25+7, blackBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackQueen.posX+25+7, blackQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0)
            hBmp = ReplaceColor(kingBlack,0x110000,0xffffff,hdcMem);
        else
            hBmp = ReplaceColor(kingBlack,0x110000,0x000000,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, blackKing.posX+25+7, blackKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        for(int o=0; o<8; o++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((blackPawns[o].posX/70)+(blackPawns[o].posY/70)) % 2 == 0)
                hBmp = ReplaceColor(pawnBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(pawnBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackPawns[o].posX+25+7, blackPawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        for(int m=0; m<8; m++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteQueenK[m].posX/70)+(whiteQueenK[m].posY/70)) % 2 == 0)
                hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteQueenK[m].posX+25+7, whiteQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        for(int m=0; m<8; m++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((blackQueenK[m].posX/70)+(blackQueenK[m].posY/70)) % 2 == 0)
                hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackQueenK[m].posX+25+7, blackQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        DeleteObject(pawnBlack);
        DeleteObject(pawnWhite);
        DeleteObject(knightBlack);
        DeleteObject(knightWhite);
        DeleteObject(knight2Black);
        DeleteObject(knight2White);
        DeleteObject(rookBlack);
        DeleteObject(rookWhite);
        DeleteObject(rook2Black);
        DeleteObject(rook2White);
        DeleteObject(bishopBlack);
        DeleteObject(bishopWhite);
        DeleteObject(bishop2Black);
        DeleteObject(bishop2White);
        DeleteObject(queenBlack);
        DeleteObject(queenWhite);
        DeleteObject(kingBlack);
        DeleteObject(kingWhite);

        Sleep(1);
        pawnBlack_s = (HBITMAP)LoadImage(hInst, "pawnblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        pawnWhite_s = (HBITMAP)LoadImage(hInst, "pawnwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knightBlack_s = (HBITMAP)LoadImage(hInst, "knightblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knightWhite_s = (HBITMAP)LoadImage(hInst, "knightwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knight2Black_s = (HBITMAP)LoadImage(hInst, "knightblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        knight2White_s = (HBITMAP)LoadImage(hInst, "knightwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rookBlack_s = (HBITMAP)LoadImage(hInst, "rookblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rookWhite_s = (HBITMAP)LoadImage(hInst, "rookwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rook2Black_s = (HBITMAP)LoadImage(hInst, "rookblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        rook2White_s = (HBITMAP)LoadImage(hInst, "rookwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishopBlack_s = (HBITMAP)LoadImage(hInst, "bishopblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishopWhite_s = (HBITMAP)LoadImage(hInst, "bishopwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishop2Black_s = (HBITMAP)LoadImage(hInst, "bishopblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        bishop2White_s = (HBITMAP)LoadImage(hInst, "bishopwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        queenBlack_s = (HBITMAP)LoadImage(hInst, "queenblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        queenWhite_s = (HBITMAP)LoadImage(hInst, "queenwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        kingBlack_s = (HBITMAP)LoadImage(hInst, "kingblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(1);
        kingWhite_s = (HBITMAP)LoadImage(hInst, "kingwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        _y_ = 20;

        HBRUSH yellow_brush = CreateSolidBrush(RGB(255,255,0));
        RECT rrect = {635+0, 17, 910, 740};
        FillRect(hdc, &rrect, yellow_brush);
        DeleteObject(yellow_brush);

        if(whiteRook1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rookWhite_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteRook1.from != NULL && whiteRook1.to != NULL) {
                if(strlen(whiteRook1.from) >= 2 && strlen(whiteRook1.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteRook1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteRook2.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rook2White_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteRook2.from != NULL && whiteRook2.to != NULL) {
                if(strlen(whiteRook2.from) >= 2 && strlen(whiteRook2.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteRook2.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteKnight1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knightWhite_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteKnight1.from != NULL && whiteKnight1.to != NULL) {
                if(strlen(whiteKnight1.from) >= 2 && strlen(whiteKnight1.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteKnight1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteKnight2.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knight2White_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteKnight2.from != NULL && whiteKnight2.to != NULL) {
                if(strlen(whiteKnight2.from) >= 2 && strlen(whiteKnight2.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteKnight2.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteBishop1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishopWhite_s,0x4cb122,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteBishop1.from != NULL && whiteBishop1.to != NULL) {
                if(strlen(whiteBishop1.from) >= 2 && strlen(whiteBishop1.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteBishop1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteBishop2.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishop2White_s,0x4cb122,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteBishop2.from != NULL && whiteBishop2.to != NULL) {
                if(strlen(whiteBishop2.from) >= 2 && strlen(whiteBishop2.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteBishop2.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteQueen.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(whiteQueen.from != NULL && whiteQueen.to != NULL) {
                if(strlen(whiteQueen.from) >= 2 && strlen(whiteQueen.to) >= 2) {
                    TextOut(hdc,
                            615+50,
                            _y_,
                            whiteQueen.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(whiteKing.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(kingWhite_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        for(int o=0; o<8; o++) {
            if(whitePawns[o].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(pawnWhite_s,0x000000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whitePawns[o].from != NULL && whitePawns[o].to != NULL) {
                    if(strlen(whitePawns[o].from) >= 2 && strlen(whitePawns[o].to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whitePawns[o].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        for(int m=0; m<8; m++) {
            if(whiteQueenK[m].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteQueenK[m].from != NULL && whiteQueenK[m].to != NULL) {
                    if(strlen(whiteQueenK[m].from) >= 2 && strlen(whiteQueenK[m].to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteQueenK[m].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        _y_ = 20;

        if(blackRook1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rookBlack_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackRook1.from != NULL && blackRook1.to != NULL) {
                if(strlen(blackRook1.from) >= 2 && strlen(blackRook1.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackRook1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackRook2.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rook2Black_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackRook2.from != NULL && blackRook2.to != NULL) {
                if(strlen(blackRook2.from) >= 2 && strlen(blackRook2.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackRook2.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackKnight1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knightBlack_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackKnight1.from != NULL && blackKnight1.to != NULL) {
                if(strlen(blackKnight1.from) >= 2 && strlen(blackKnight1.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackKnight1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackKnight2.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knight2Black_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackKnight2.from != NULL && blackKnight2.to != NULL) {
                if(strlen(blackKnight2.from) >= 2 && strlen(blackKnight2.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackKnight2.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackBishop1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishopBlack_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackBishop1.from != NULL && blackBishop1.to != NULL) {
                if(strlen(blackBishop1.from) >= 2 && strlen(blackBishop1.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackBishop1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackBishop2.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishop2Black_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackBishop2.from != NULL && blackBishop2.to != NULL) {
                if(strlen(blackBishop2.from) >= 2 && strlen(blackBishop2.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackBishop2.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackQueen.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(blackQueen.from != NULL && blackQueen.to != NULL) {
                if(strlen(blackQueen.from) >= 2 && strlen(blackQueen.to) >= 2) {
                    TextOut(hdc,
                            690+50,
                            _y_,
                            blackQueen.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(blackKing.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(kingBlack_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        for(int o=0; o<8; o++) {
            if(blackPawns[o].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(pawnBlack_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackPawns[o].from != NULL && blackPawns[o].to != NULL) {
                    if(strlen(blackPawns[o].from) >= 2 && strlen(blackPawns[o].to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackPawns[o].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        for(int m=0; m<8; m++) {
            if(blackQueenK[m].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackQueenK[m].from != NULL && blackQueenK[m].to != NULL) {
                    if(strlen(blackQueenK[m].from) >= 2 && strlen(blackQueenK[m].to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackQueenK[m].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        DeleteObject(pawnBlack_s);
        DeleteObject(pawnWhite_s);
        DeleteObject(knightBlack_s);
        DeleteObject(knightWhite_s);
        DeleteObject(knight2Black_s);
        DeleteObject(knight2White_s);
        DeleteObject(rookBlack_s);
        DeleteObject(rookWhite_s);
        DeleteObject(rook2Black_s);
        DeleteObject(rook2White_s);
        DeleteObject(bishopBlack_s);
        DeleteObject(bishopWhite_s);
        DeleteObject(bishop2Black_s);
        DeleteObject(bishop2White_s);
        DeleteObject(queenBlack_s);
        DeleteObject(queenWhite_s);
        DeleteObject(kingBlack_s);
        DeleteObject(kingWhite_s);
    }

    turn = 'h';

    gettingit = FALSE;
    
    PlaySound(TEXT("ding.wav"), NULL, SND_FILENAME);
    
    return 0;
}

void CaptureWindow(HWND hWnd) {
    Sleep(5000);

    keybd_event(VK_SNAPSHOT, 1, KEYEVENTF_EXTENDEDKEY, 0);

    keybd_event(VK_SNAPSHOT, 1, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

HBITMAP ReplaceColor(HBITMAP hBmp,COLORREF cOldColor,COLORREF cNewColor,HDC hBmpDC) {
    HBITMAP RetBmp=NULL;
    if (hBmp)
    {
        HDC BufferDC=CreateCompatibleDC(NULL);
        if (BufferDC)
        {
            HBITMAP hTmpBitmap = (HBITMAP) NULL;
            if (hBmpDC)
                if (hBmp == (HBITMAP)GetCurrentObject(hBmpDC, OBJ_BITMAP))
            {
                hTmpBitmap = CreateBitmap(1, 1, 1, 1, NULL);
                SelectObject(hBmpDC, hTmpBitmap);
            }

            HGDIOBJ PreviousBufferObject=SelectObject(BufferDC,hBmp);
            
            HDC DirectDC=CreateCompatibleDC(NULL);
            if (DirectDC)
            {
                BITMAP bm;
                GetObject(hBmp, sizeof(bm), &bm);

                BITMAPINFO RGB32BitsBITMAPINFO; 
                ZeroMemory(&RGB32BitsBITMAPINFO,sizeof(BITMAPINFO));
                RGB32BitsBITMAPINFO.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
                RGB32BitsBITMAPINFO.bmiHeader.biWidth=bm.bmWidth;
                RGB32BitsBITMAPINFO.bmiHeader.biHeight=bm.bmHeight;
                RGB32BitsBITMAPINFO.bmiHeader.biPlanes=1;
                RGB32BitsBITMAPINFO.bmiHeader.biBitCount=32;

                UINT * ptPixels;    

                HBITMAP DirectBitmap = CreateDIBSection(DirectDC, 
                                       (BITMAPINFO *)&RGB32BitsBITMAPINFO, 
                                       DIB_RGB_COLORS,
                                       (void **)&ptPixels, 
                                       NULL, 0);
                if (DirectBitmap)
                {
                    HGDIOBJ PreviousObject=SelectObject(DirectDC, DirectBitmap);
                    BitBlt(DirectDC,0,0,
                                   bm.bmWidth,bm.bmHeight,
                                   BufferDC,0,0,SRCCOPY);

                    cOldColor=COLORREF2RGB(cOldColor);
                    cNewColor=COLORREF2RGB(cNewColor);

                    for (int i=((bm.bmWidth*bm.bmHeight)-1);i>=0;i--)
                    {
                        if (ptPixels[i]==cOldColor) ptPixels[i]=cNewColor;
                    }
                    SelectObject(DirectDC,PreviousObject);

                    RetBmp=DirectBitmap;
                }
                DeleteDC(DirectDC);
            }            
            if (hTmpBitmap)
            {
                SelectObject(hBmpDC, hBmp);
                DeleteObject(hTmpBitmap);
            }
            SelectObject(BufferDC,PreviousBufferObject);
            DeleteDC(BufferDC);
        }
    }
    return RetBmp;
}

DWORD WINAPI ThreadFunc(void *data) {
    char b[91];
    SYSTEMTIME st;
    GetLocalTime(&st);
    ws = st.wSecond;
    wm = st.wMinute;
    time_t seconds;
    seconds = time(NULL);
    boolean dodo = TRUE;
    int ls;
    while(TRUE) {
        GetLocalTime(&st);
        timestampNow = st.wSecond; 
        GetLocalTime(&st);
        sec = st.wSecond - ws;
        if(sec < 0) {
            sec = 60 - (st.wSecond - ws) * -1;
            min = st.wMinute - wm;
            min--;
        } else {
            min = st.wMinute - wm;
        }
        int cs = secs;
        secs = time(NULL) - seconds;
        ls = secs;
        sec = secs % 60;
        min = secs / 60;
        total = min*60 + sec;
        boolean notimelimit = FALSE;
        if(ttw == 0 && timeToWait == 0) {
            notimelimit = TRUE;
        }
        if(!notimelimit) {
            if(turn == 'h') {

                sprintf(b, "white player - %d:%d/%d mins", min, sec, ttw);
            } else {

                sprintf(b, "black player - %d:%d/%d mins", min, sec, ttw);
            }
        } else {
            
            if(!pcgame) {
                
                if(turn == 'h') {

                    sprintf(b, "white player - no time");

                } else {

                    sprintf(b, "black player - no time");
                }
                
            } else {
                
                if(turn == 'h') {

                    sprintf(b, "white player");
                
                } else {

                    sprintf(b, "black player");
                }
                
            }
            
        }
        if(ls != cs) {
            SetWindowText(hwnd_timer, b);
            if(gettingit) {
                SetWindowText(hwnd_timer, "thinking ...");
            } else {
                if(pcgame && tft) {
                    TerminateThread(callApi, 0);
                    tft = FALSE;
                }
            }
        }
        if(!notimelimit) {
            if(total >= timeToWait || turnChanged) {
                if(!turnChanged && !fftime) {
                    if(turn == 'h') {
                        turn = 'r';
                    } else if(turn == 'r') {
                        turn = 'h';
                    }
                }
                turnChanged = FALSE;
                ws = st.wSecond;
                wm = st.wMinute;
                sec = 0;
                min = 0;
                total = 0;
                seconds = time(NULL);
            }
        }
    }
    
    return 0;
}

int center_window(HWND parent_window, int width, int height) {
    GetClientRect(parent_window, &rect);
    rect.left = (rect.right/2) - (width/2);
    rect.top = (rect.bottom/2) - (height/2);
    return 0;
}

void Play() {
    firstTime = FALSE;
    whiteKingMoved = FALSE;
    blackKingMoved = FALSE;
    whiteRook1Moved = FALSE;
    blackRook1Moved = FALSE;
    whiteRook2Moved = FALSE;
    blackRook2Moved = FALSE;
    whiteKing.posX = 4*70+20;
    whiteKing.posY = 7*70+20;
    blackKing.posX = 4*70+20;
    blackKing.posY = 0*70+20;
    whiteQueen.posX = 3*70+20;
    whiteQueen.posY = 7*70+20;
    whiteQueen.from = map(7, 3);
    whiteQueen.to = map(7, 3);
    whiteBishop1.posX = 2*70+20;
    whiteBishop1.posY = 7*70+20;
    whiteBishop1.from = map(7, 2);
    whiteBishop1.to = map(7, 2);
    whiteBishop2.posX = 5*70+20;
    whiteBishop2.posY = 7*70+20;
    whiteBishop2.from = map(7, 5);
    whiteBishop2.to = map(7, 5);
    blackRook1.posX = 0*70+20;
    blackRook1.posY = 0*70+20;
    blackRook1.from = map(0, 0);
    blackRook1.to = map(0, 0);
    blackRook2.posX = 7*70+20;
    blackRook2.posY = 0*70+20;
    blackRook2.from = map(0, 7);
    blackRook2.to = map(0, 7);
    whiteRook1.posX = 0*70+20;
    whiteRook1.posY = 7*70+20;
    whiteRook1.from = map(7, 0);
    whiteRook1.to = map(7, 0);
    whiteRook2.posX = 7*70+20;
    whiteRook2.posY = 7*70+20;
    whiteRook2.from = map(7, 7);
    whiteRook2.to = map(7, 7);
    whiteKnight2.posX = 1*70+20;
    whiteKnight2.posY = 7*70+20;
    whiteKnight2.from = map(7, 1);
    whiteKnight2.to = map(7, 1);
    whiteKnight1.posX = 6*70+20;
    whiteKnight1.posY = 7*70+20;
    whiteKnight1.from = map(7, 6);
    whiteKnight1.to = map(7, 6);
    blackKnight2.posX = 1*70+20;
    blackKnight2.posY = 0*70+20;
    blackKnight2.from = map(0, 1);
    blackKnight2.to = map(0, 1);
    blackKnight1.posX = 6*70+20;
    blackKnight1.posY = 0*70+20;
    blackKnight1.from = map(0, 6);
    blackKnight1.to = map(0, 6);
    blackQueen.posX = 3*70+20;
    blackQueen.posY = 0*70+20;
    blackQueen.from = map(0, 3);
    blackQueen.to = map(0, 3);
    for(int p=0; p<8; p++) {
        blackQueenK[p].posX = 1200;
    }
    for(int p=0; p<8; p++) {
        whiteQueenK[p].posX = 1200;
    }
    blackBishop1.posX = 2*70+20;
    blackBishop1.posY = 0*70+20;
    blackBishop1.from = map(0, 2);
    blackBishop1.to = map(0, 2);
    blackBishop2.posX = 5*70+20;
    blackBishop2.posY = 0*70+20;
    blackBishop2.from = map(0, 5);
    blackBishop2.to = map(0, 5);
    blackKing.posX = 4*70+20;
    blackKing.posY = 0*70+20;
    for(int i=0; i<8; i++) {
        whitePawns[i].posX = i*70+20;
        whitePawns[i].posY = 420+20;
        whitePawns[i].from = map(6, i);
        whitePawns[i].to = map(6, i);
    }
    for(int i=0; i<8; i++) {
        blackPawns[i].posX = i*70+20;
        blackPawns[i].posY = 70+20;
        blackPawns[i].from = map(1, i);
        blackPawns[i].to = map(1, i);
    }
    for(int i=0; i<8; i++) {
        blackPawns[i].firstTimeMove = TRUE;
    }
    for(int i=0; i<8; i++) {
        whitePawns[i].firstTimeMove = TRUE;
    }
    for(int j=0; j<8; j++) {
        for(int i=0; i<8; i++) {
            boxes[j][i].posX = i*70+20;
            boxes[j][i].posY = j*70+20;
            boxes[j][i].clear = TRUE;
        }
    }
    turn = 'h';
}

boolean checkQueenCheckBlack(int j, int i) {

    int a1 = whiteQueen.posY;
    int a0 = whiteQueen.posX;

    boolean f = FALSE;

    whiteQueen.failedpath = FALSE;

    if(whiteQueen.posX == 1300) {
        f = TRUE;
    }

    if(blackKing.posX == whiteQueen.posX) {
        f = moveWhiteQueen(0, -888, i, blackKing.posY - whiteQueen.posY, blackKing.posY - whiteQueen.posY);
        f = whiteQueen.failedpath;
    } else if(blackKing.posY == whiteQueen.posY) {
        f = moveWhiteQueenSide(0, -888, i, blackKing.posX - whiteQueen.posX, blackKing.posX - whiteQueen.posX);
        f = whiteQueen.failedpath;
    } else if(blackKing.posX != whiteQueen.posX &&
       blackKing.posY != whiteQueen.posY) {
        if(blackKing.posY - whiteQueen.posY == blackKing.posX - whiteQueen.posX ||
           blackKing.posY - whiteQueen.posY == -1 * (blackKing.posX - whiteQueen.posX)) {
            f = moveWhiteQueenDiagonally(0, -888, i, blackKing.posY - whiteQueen.posY, blackKing.posX - whiteQueen.posX, blackKing.posY - whiteQueen.posY, blackKing.posX - whiteQueen.posX);
            f = whiteQueen.failedpath;
        } else {
            f = whiteQueen.failedpath = TRUE;
        }
    } else {
        f = whiteQueen.failedpath = TRUE;
    }

    whiteQueen.posY = a1;
    whiteQueen.posX = a0;

    if(!f) {
        whiteQueen.failedpath = FALSE;
        return TRUE;
    }
    
    whiteQueen.failedpath = FALSE;
    return FALSE;
}

boolean checkRookCheckWhite(int j, int i) {

    int a1 = blackRook1.posY;
    int a0 = blackRook1.posX;

    boolean f = FALSE;

    blackRook1.failedpath = FALSE;

    if(whiteKing.posX == blackRook1.posX) {
        f = moveBlackRook1(0, j, i, whiteKing.posY - blackRook1.posY, whiteKing.posY - blackRook1.posY);
        f = blackRook1.failedpath;
    } else if(whiteKing.posY == blackRook1.posY) {
        f = moveBlackRook1Side(0, j, i, whiteKing.posX - blackRook1.posX, whiteKing.posX - blackRook1.posX);
        f = blackRook1.failedpath;
    } else {
        f = blackRook1.failedpath = TRUE;
    }

    blackRook1.posY = a1;
    blackRook1.posX = a0;

    a1 = blackRook2.posY;
    a0 = blackRook2.posX;

    boolean f2 = FALSE;

    blackRook2.failedpath = FALSE;

    if(whiteKing.posX == blackRook2.posX) {
        f2 = moveBlackRook2(0, j, i, whiteKing.posY - blackRook2.posY, whiteKing.posY - blackRook2.posY);
        f2 = blackRook2.failedpath;
    } else if(whiteKing.posY == blackRook2.posY) {
        f2 = moveBlackRook2Side(0, j, i, whiteKing.posX - blackRook2.posX, whiteKing.posX - blackRook2.posX);
        f2 = blackRook2.failedpath;
    } else {
        f2 = blackRook2.failedpath = TRUE;
    }

    blackRook2.posY = a1;
    blackRook2.posX = a0;

    if(!f || !f2) {
        blackRook1.failedpath = FALSE;
        blackRook2.failedpath = FALSE;
        return TRUE;
    }
    
    blackRook1.failedpath = FALSE;
    blackRook2.failedpath = FALSE;
    return FALSE;
}

boolean checkRookCheckBlack(int j, int i) {

    int a1 = whiteRook1.posY;
    int a0 = whiteRook1.posX;

    boolean f = FALSE;

    whiteRook1.failedpath = FALSE;

    if(blackKing.posX == whiteRook1.posX) {
        f = moveWhiteRook1(0, j, i, blackKing.posY - whiteRook1.posY, blackKing.posY - whiteRook1.posY);
        f = whiteRook1.failedpath;
    } else if(blackKing.posY == whiteRook1.posY) {
        f = moveWhiteRook1Side(0, j, i, blackKing.posX - whiteRook1.posX, blackKing.posX - whiteRook1.posX);
        f = whiteRook1.failedpath;
    } else {
        f = whiteRook1.failedpath = TRUE;
    }

    whiteRook1.posY = a1;
    whiteRook1.posX = a0;

    a1 = whiteRook2.posY;
    a0 = whiteRook2.posX;

    boolean f2 = FALSE;

    whiteRook2.failedpath = FALSE;

    if(blackKing.posX == whiteRook2.posX) {
        f2 = moveWhiteRook2(0, j, i, blackKing.posY - whiteRook2.posY, blackKing.posY - whiteRook2.posY);
        f2 = whiteRook2.failedpath;
    } else if(blackKing.posY == whiteRook2.posY) {
        f2 = moveWhiteRook2Side(0, j, i, blackKing.posX - whiteRook2.posX, blackKing.posX - whiteRook2.posX);
        f2 = whiteRook2.failedpath;
    } else {
        f2 = whiteRook2.failedpath = TRUE;
    }

    whiteRook2.posY = a1;
    whiteRook2.posX = a0;

    if(!f || !f2) {
        whiteRook1.failedpath = FALSE;
        whiteRook2.failedpath = FALSE;
        return TRUE;
    }
    
    whiteRook1.failedpath = FALSE;
    whiteRook2.failedpath = FALSE;
    return FALSE;
}

boolean checkQueenCheckWhite(int j, int i) {

    int a1 = blackQueen.posY;
    int a0 = blackQueen.posX;

    boolean f = FALSE;

    blackQueen.failedpath = FALSE;
    
    if(blackQueen.posX == 1300) {
        f = TRUE;
    }

    if(whiteKing.posX == blackQueen.posX) {
        f = moveBlackQueen(0, -888, i, whiteKing.posY - blackQueen.posY, whiteKing.posY - blackQueen.posY);
        f = blackQueen.failedpath;
        if(whiteKing.posY - blackQueen.posY == 0) {
            f = blackQueen.failedpath = TRUE;
        }
    } else if(whiteKing.posY == blackQueen.posY) {
        f = moveBlackQueenSide(0, -888, i, whiteKing.posX - blackQueen.posX, whiteKing.posX - blackQueen.posX);
        f = blackQueen.failedpath;
    } else if(whiteKing.posX != blackQueen.posX &&
       whiteKing.posY != blackQueen.posY) {
        if(whiteKing.posY - blackQueen.posY == whiteKing.posX - blackQueen.posX ||
           whiteKing.posY - blackQueen.posY == -1 * (whiteKing.posX - blackQueen.posX)) {
            f = moveBlackQueenDiagonally(0, -888, i, whiteKing.posY - blackQueen.posY, whiteKing.posX - blackQueen.posX, whiteKing.posY - blackQueen.posY, whiteKing.posX - blackQueen.posX);
            f = blackQueen.failedpath;
        } else {
            f = blackQueen.failedpath = TRUE;
        }
    } else {
        f = blackQueen.failedpath = TRUE;
    }

    blackQueen.posY = a1;
    blackQueen.posX = a0;

    if(!f) {
        blackQueen.failedpath = FALSE;
        return TRUE;
    }
    
    blackQueen.failedpath = FALSE;
    return FALSE;
}

boolean checkQueenCheckWhiteK(int j, int i) {

  for(int z=0; z<8; z++) {
  
        int a1 = blackQueenK[z].posY;
        int a0 = blackQueenK[z].posX;

        if(blackQueenK[z].posX > 800)
            continue;

        boolean f = FALSE;

        blackQueenK[z].failedpath = FALSE;

        if(whiteKing.posX == blackQueenK[z].posX) {
            f = moveBlackQueenK(0, -888, i, whiteKing.posY - blackQueenK[z].posY, whiteKing.posY - blackQueenK[z].posY, z);
            f = blackQueenK[z].failedpath;
        } else if(whiteKing.posY == blackQueenK[z].posY) {
            f = moveBlackQueenSideK(0, -888, i, whiteKing.posX - blackQueenK[z].posX, whiteKing.posX - blackQueenK[z].posX, z);
            f = blackQueenK[z].failedpath;
        } else if(whiteKing.posX != blackQueenK[z].posX &&
           whiteKing.posY != blackQueenK[z].posY) {
            if(whiteKing.posY - blackQueenK[z].posY == whiteKing.posX - blackQueenK[z].posX ||
               whiteKing.posY - blackQueenK[z].posY == -1 * (whiteKing.posX - blackQueenK[z].posX)) {
                f = moveBlackQueenDiagonallyK(0, -888, i, whiteKing.posY - blackQueenK[z].posY, whiteKing.posX - blackQueenK[z].posX, whiteKing.posY - blackQueenK[z].posY, whiteKing.posX - blackQueenK[z].posX, z);
                f = blackQueenK[z].failedpath;
            } else {
                f = blackQueenK[z].failedpath = TRUE;
            }
        } else {
            f = blackQueenK[z].failedpath = TRUE;
        }

        blackQueenK[z].posY = a1;
        blackQueenK[z].posX = a0;

        if(!f) {
            blackQueenK[z].failedpath = FALSE;
            return TRUE;
        }

        blackQueenK[z].failedpath = FALSE;
    }

    return FALSE;
}

boolean checkQueenCheckBlackK(int j, int i) {

    for(int z=0; z<8; z++) {
  
        int a1 = whiteQueenK[z].posY;
        int a0 = whiteQueenK[z].posX;

        if(whiteQueenK[z].posX > 800)
            continue;
        
        boolean f = FALSE;

        whiteQueenK[z].failedpath = FALSE;

        if(blackKing.posX == whiteQueenK[z].posX) {
            f = moveWhiteQueenK(0, -888, i, blackKing.posY - whiteQueenK[z].posY, blackKing.posY - whiteQueenK[z].posY, z);
            f = whiteQueenK[z].failedpath;
        } else if(blackKing.posY == whiteQueenK[z].posY) {
            f = moveWhiteQueenSideK(0, -888, i, blackKing.posX - whiteQueenK[z].posX, blackKing.posX - whiteQueenK[z].posX, z);
            f = whiteQueenK[z].failedpath;
        } else if(blackKing.posX != whiteQueenK[z].posX &&
           blackKing.posY != whiteQueenK[z].posY) {
            if(blackKing.posY - whiteQueenK[z].posY == blackKing.posX - whiteQueenK[z].posX ||
               blackKing.posY - whiteQueenK[z].posY == -1 * (blackKing.posX - whiteQueenK[z].posX)) {
                f = moveWhiteQueenDiagonallyK(0, -888, i, blackKing.posY - whiteQueenK[z].posY, blackKing.posX - whiteQueenK[z].posX, blackKing.posY - whiteQueenK[z].posY, blackKing.posX - whiteQueenK[z].posX, z);
                f = whiteQueenK[z].failedpath;
            } else {
                f = whiteQueenK[z].failedpath = TRUE;
            }
        } else {
            f = whiteQueenK[z].failedpath = TRUE;
        }

        whiteQueenK[z].posY = a1;
        whiteQueenK[z].posX = a0;

        if(!f) {
            whiteQueenK[z].failedpath = FALSE;
            return TRUE;
        }

        whiteQueenK[z].failedpath = FALSE;
    }

    return FALSE;
}

boolean checkBishopCheckBlack(int j, int i) {

    int a1 = whiteBishop1.posY;
    int a0 = whiteBishop1.posX;

    boolean f = FALSE;

    whiteBishop1.failedpath = FALSE;

    if(blackKing.posX != whiteBishop1.posX &&
       blackKing.posY != whiteBishop1.posY) {
        f = moveWhiteBishop1(0, -888, i, blackKing.posY - whiteBishop1.posY, blackKing.posX - whiteBishop1.posX, blackKing.posY - whiteBishop1.posY, blackKing.posX - whiteBishop1.posX);
        f = whiteBishop1.failedpath;
    } else {
        f = whiteBishop1.failedpath = TRUE;
    }

    whiteBishop1.posY = a1;
    whiteBishop1.posX = a0;

    a1 = whiteBishop2.posY;
    a0 = whiteBishop2.posX;

    boolean f2 = FALSE;
    
    whiteBishop2.failedpath = FALSE;

    if(blackKing.posX != whiteBishop2.posX &&
       blackKing.posY != whiteBishop2.posY) {
        f2 = moveWhiteBishop2(0, -888, i, blackKing.posY - whiteBishop2.posY, blackKing.posX - whiteBishop2.posX, blackKing.posY - whiteBishop2.posY, blackKing.posX - whiteBishop2.posX);
        f2 = whiteBishop2.failedpath;
    } else {
        f2 = whiteBishop2.failedpath = TRUE;
    }

    whiteBishop2.posY = a1;
    whiteBishop2.posX = a0;

    if(!f || !f2) {
        whiteBishop1.failedpath = FALSE;
        whiteBishop2.failedpath = FALSE;
        return TRUE;
    }
    
    whiteBishop1.failedpath = FALSE;
    whiteBishop2.failedpath = FALSE;
    return FALSE;
}

boolean checkBishopCheckWhite(int j, int i) {

    int a1 = blackBishop1.posY;
    int a0 = blackBishop1.posX;

    boolean f = FALSE;

    blackBishop1.failedpath = FALSE;

    if(whiteKing.posX != blackBishop1.posX &&
       whiteKing.posY != blackBishop1.posY) {
        f = moveBlackBishop1(0, -888, i, whiteKing.posY - blackBishop1.posY, whiteKing.posX - blackBishop1.posX, whiteKing.posY - blackBishop1.posY, whiteKing.posX - blackBishop1.posX);
        f = blackBishop1.failedpath;
    } else {
        f = blackBishop1.failedpath = TRUE;
    }

    blackBishop1.posY = a1;
    blackBishop1.posX = a0;

    a1 = blackBishop2.posY;
    a0 = blackBishop2.posX;

    boolean f2 = FALSE;
    
    blackBishop2.failedpath = FALSE;

    if(whiteKing.posX != blackBishop2.posX &&
       whiteKing.posY != blackBishop2.posY) {
        f2 = moveBlackBishop2(0, -888, i, whiteKing.posY - blackBishop2.posY, whiteKing.posX - blackBishop2.posX, whiteKing.posY - blackBishop2.posY, whiteKing.posX - blackBishop2.posX);
        f2 = blackBishop2.failedpath;
    } else {
        f2 = blackBishop2.failedpath = TRUE;
    }

    blackBishop2.posY = a1;
    blackBishop2.posX = a0;

    if(!f || !f2) {
        blackBishop1.failedpath = FALSE;
        blackBishop2.failedpath = FALSE;
        return TRUE;
    }
    
    blackBishop1.failedpath = FALSE;
    blackBishop2.failedpath = FALSE;
    return FALSE;
}

boolean checkKnightCheckWhite(int j, int i) {

    if(whiteKnight1.posX == blackKnight1.posX &&
       whiteKnight1.posY == blackKnight1.posY) {
        return FALSE;
    }
    if(whiteKnight2.posX == blackKnight2.posX &&
       whiteKnight2.posY == blackKnight2.posY) {
        return FALSE;
    }
    if(whiteKnight1.posX == blackKnight2.posX &&
       whiteKnight1.posY == blackKnight2.posY) {
        return FALSE;
    }
    if(whiteKnight2.posX == blackKnight1.posX &&
       whiteKnight2.posY == blackKnight1.posY) {
        return FALSE;
    }
    if(blackKnight1.posX - 70 == whiteKing.posX &&
       blackKnight1.posY - 140 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX - 140 == whiteKing.posX &&
              blackKnight1.posY - 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX - 140 == whiteKing.posX &&
              blackKnight1.posY + 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX - 70 == whiteKing.posX &&
              blackKnight1.posY + 140 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX + 70 == whiteKing.posX &&
              blackKnight1.posY + 140 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX + 140 == whiteKing.posX &&
              blackKnight1.posY + 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX + 140 == whiteKing.posX &&
              blackKnight1.posY - 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight1.posX + 70 == whiteKing.posX &&
              blackKnight1.posY - 140 == whiteKing.posY) {
        return TRUE;
    }
    if(blackKnight2.posX - 70 == whiteKing.posX &&
       blackKnight2.posY - 140 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX - 140 == whiteKing.posX &&
              blackKnight2.posY - 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX - 140 == whiteKing.posX &&
              blackKnight2.posY + 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX - 70 == whiteKing.posX &&
              blackKnight2.posY + 140 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX + 70 == whiteKing.posX &&
              blackKnight2.posY + 140 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX + 140 == whiteKing.posX &&
              blackKnight2.posY + 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX + 140 == whiteKing.posX &&
              blackKnight2.posY - 70 == whiteKing.posY) {
        return TRUE;
    } else if(blackKnight2.posX + 70 == whiteKing.posX &&
              blackKnight2.posY - 140 == whiteKing.posY) {
        return TRUE;
    }
    return FALSE;
}

boolean checkPawnsCheckWhite(int j, int i) {
    
    for(int t=0; t<8; t++) {
        if(blackPawns[t].posX + 70 == whiteKing.posX &&
           blackPawns[t].posY + 70 == whiteKing.posY) {
            return TRUE;
        }

        if(blackPawns[t].posX - 70 == whiteKing.posX &&
           blackPawns[t].posY + 70 == whiteKing.posY) {
            return TRUE;
        }
    }
    return FALSE;
}

boolean checkPawnsCheckBlack(int j, int i) {
    
    for(int t=0; t<8; t++) {
        if(whitePawns[t].posX + 70 == blackKing.posX &&
           whitePawns[t].posY - 70 == blackKing.posY) {
            return TRUE;
        }
        if(whitePawns[t].posX - 70 == blackKing.posX &&
           whitePawns[t].posY - 70 == blackKing.posY) {
            return TRUE;
        }
    }
    return FALSE;
}

boolean checkKnightCheckBlack(int j, int i) {
    
    if(whiteKnight1.posX == blackKnight1.posX &&
       whiteKnight1.posY == blackKnight1.posY) {
        return FALSE;
    }
    if(whiteKnight2.posX == blackKnight2.posX &&
       whiteKnight2.posY == blackKnight2.posY) {
        return FALSE;
    }
    if(whiteKnight1.posX == blackKnight2.posX &&
       whiteKnight1.posY == blackKnight2.posY) {
        return FALSE;
    }
    if(whiteKnight2.posX == blackKnight1.posX &&
       whiteKnight2.posY == blackKnight1.posY) {
        return FALSE;
    }
    if(whiteKnight1.posX - 70 == blackKing.posX &&
       whiteKnight1.posY - 140 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX - 140 == blackKing.posX &&
              whiteKnight1.posY - 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX - 140 == blackKing.posX &&
              whiteKnight1.posY + 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX - 70 == blackKing.posX &&
              whiteKnight1.posY + 140 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX + 70 == blackKing.posX &&
              whiteKnight1.posY + 140 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX + 140 == blackKing.posX &&
              whiteKnight1.posY + 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX + 140 == blackKing.posX &&
              whiteKnight1.posY - 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight1.posX + 70 == blackKing.posX &&
              whiteKnight1.posY - 140 == blackKing.posY) {
        return TRUE;
    }
    if(whiteKnight2.posX - 70 == blackKing.posX &&
       whiteKnight2.posY - 140 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX - 140 == blackKing.posX &&
              whiteKnight2.posY - 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX - 140 == blackKing.posX &&
              whiteKnight2.posY + 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX - 70 == blackKing.posX &&
              whiteKnight2.posY + 140 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX + 70 == blackKing.posX &&
              whiteKnight2.posY + 140 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX + 140 == blackKing.posX &&
              whiteKnight2.posY + 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX + 140 == blackKing.posX &&
              whiteKnight2.posY - 70 == blackKing.posY) {
        return TRUE;
    } else if(whiteKnight2.posX + 70 == blackKing.posX &&
              whiteKnight2.posY - 140 == blackKing.posY) {
        return TRUE;
    }
    return FALSE;
}

boolean checkCheckWhite(int j, int i) {
    if(checkKnightCheckWhite(j, i) ||
       checkBishopCheckWhite(j, i) ||
       checkQueenCheckWhite(j, i) ||
       checkQueenCheckWhiteK(j, i) ||
       checkRookCheckWhite(j, i) ||
       checkPawnsCheckWhite(j, i)) {
        return TRUE;
    }
    return FALSE;
}

boolean checkCheckBlack(int j, int i) {
    if(checkKnightCheckBlack(j, i) ||
       checkBishopCheckBlack(j, i) ||
       checkQueenCheckBlack(j, i) ||
       checkQueenCheckBlackK(j, i) ||
       checkRookCheckBlack(j, i) ||
       checkPawnsCheckBlack(j, i)) {
        return TRUE;
    }
    return FALSE;
}

void DisableMaximizeMinimizeButton(HWND hwnd) {
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
}

void highlightPossibleMoves(int j, int i) {

    if(wLMSize == 0)
        return;

    for(int q=0; q<wLMSize; q++) {
        char letter = wLM[q][0];
        char number = wLM[q][1];
        char *location = map(j, i);
        if(location[0] == letter &&
           location[1] == number) {
            int y = re_Map(wLM[q], 1);
            int x = re_Map(wLM[q], 0);
            HBRUSH rBrush;
            rBrush = CreateSolidBrush(RGB(200, 200, 255));
            RECT r = {x+20+20+5, y+20+31, x+20+20 + 63, y+20+20-7 + 68};
            FillRect(hdc, &r, rBrush);
            DeleteObject(rBrush);
        }
    }
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_PAINT:
        {
            if(finished == -1) {

                hdc = BeginPaint(hwnd, &ps);
                hdcMem = CreateCompatibleDC(hdc);
                
                oldBitmap = SelectObject(hdcMem, hBitmap);

                GetObject(hBitmap, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 0, 0, 1040, 740, hdcMem, 0, 0, SRCCOPY);

                SelectObject(hdcMem, oldBitmap);
                DeleteDC(hdcMem); DeleteObject(hBitmap);

                finished = 0;
                
                PlaySound(TEXT("a-team_plan.wav"), NULL, SND_FILENAME);
    
                Sleep(1500);

//                HBRUSH brush = CreateSolidBrush(RGB(255,0,0));
//                RECT rrect = {0, 0, 1040, 740};
//                FillRect(hdc, &rrect, brush);
//                DeleteObject(brush);

                hdcMem = CreateCompatibleDC(hdc);
                
                oldBitmap = SelectObject(hdcMem, hBitmapSideLogo);

                GetObject(hBitmapSideLogo, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 963, 0, 1010, 740, hdcMem, 0, 0, SRCCOPY);

                SelectObject(hdcMem, oldBitmap);
                DeleteDC(hdcMem); DeleteObject(hBitmapSideLogo);

                EndPaint(hwnd, &ps);

                hdc = GetDC(hwnd);

                wLMSize = 20;
                wLM[0] = "b1a3";
                wLM[1] = "b1c3";
                wLM[2] = "e2e3";
                wLM[3] = "g1f3";
                wLM[4] = "g1h3";
                wLM[5] = "a2a3";
                wLM[6] = "b2b3";
                wLM[7] = "c2c3";
                wLM[8] = "d2d3";
                wLM[9] = "f2f3";
                wLM[10] = "g2g3";
                wLM[11] = "h2h3";
                wLM[12] = "e2e4";
                wLM[13] = "a2a4";
                wLM[14] = "b2b4";
                wLM[15] = "c2c4";
                wLM[16] = "d2d4";
                wLM[17] = "f2f4";
                wLM[18] = "g2g4";
                wLM[19] = "h2h4";

                //sideLogoThread = CreateThread(NULL, 0, paintSideLogo, NULL, 0, NULL);

                thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
                Play();
                PostMessage(hwnd, WM_NOTIFY, 0, 0);
            }
        }
        break;
        case WM_NOTIFY:
        {
            if(klicked) {

                Sleep(1);
                pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                int xq = 0;

                hdcMem = CreateCompatibleDC(hdc);

                if(chosenPiece[0] == 'p' && chosenPiece[1] == 'r') {
                    hBitmapSq = pawnBlack;
                    xq = 22;
                }

                if(chosenPiece[0] == 'p' && chosenPiece[1] == 'w') {

                    hBitmapSq = pawnWhite;

                    hBitmapSq = ReplaceColor(hBitmapSq, 0x000000, 0xc8c8ff, hdcMem);

                    xq = 22;
                }

                if(chosenPiece[0] == 'k' && chosenPiece[1] == 'w') {
                    hBitmapSq = knightWhite;
                    xq = 22;
                }

                if(chosenPiece[0] == 'k' && chosenPiece[1] == 'r') {
                    hBitmapSq = knightBlack;
                    xq = 22;
                }

                if(chosenPiece[0] == 'b' && chosenPiece[1] == 'w') {
                    hBitmapSq = bishopWhite;
                    xq = 22;
                }

                if(chosenPiece[0] == 'b' && chosenPiece[1] == 'r') {
                    hBitmapSq = bishopBlack;
                    xq = 22;
                }

                if(chosenPiece[0] == 'r' && chosenPiece[1] == 'w') {
                    hBitmapSq = rookWhite;
                    xq = 22;
                }

                if(chosenPiece[0] == 'r' && chosenPiece[1] == 'r') {
                    hBitmapSq = rookBlack;
                    xq = 22;
                }

                if(chosenPiece[0] == 'q' && chosenPiece[1] == 'w') {
                    hBitmapSq = queenWhite;
                    xq = 22;
                }

                if(chosenPiece[0] == 'q' && chosenPiece[1] == 'r') {
                    hBitmapSq = queenBlack;
                    xq = 22;
                }

                if(chosenPiece[0] == 'c' && chosenPiece[1] == 'w') {
                    hBitmapSq = kingWhite;
                    xq = 22;
                }

                if(chosenPiece[0] == 'c' && chosenPiece[1] == 'r') {
                    hBitmapSq = kingBlack;
                    xq = 22;
                }

                hBitmapSq = ReplaceColor(hBitmapSq, 0xff0000, 0xc8c8ff, hdcMem);

                hBitmapSq = ReplaceColor(hBitmapSq, 0x4cb122, 0xc8c8ff, hdcMem);
                
                hBitmapSq = ReplaceColor(hBitmapSq, 0x00ff00, 0xc8c8ff, hdcMem);

                oldBitmap = SelectObject(hdcMem, hBitmapSq);

                GetObject(hBitmapSq, sizeof(bitmap), &bitmap);
                BitBlt(hdc, i__PosX-30, i__PosY-30, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBitmapSq);
                DeleteObject(oldBitmap);
                
                DeleteObject(pawnBlack);
                DeleteObject(pawnWhite);
                DeleteObject(knightBlack);
                DeleteObject(knightWhite);
                DeleteObject(knight2Black);
                DeleteObject(knight2White);
                DeleteObject(rookBlack);
                DeleteObject(rookWhite);
                DeleteObject(rook2Black);
                DeleteObject(rook2White);
                DeleteObject(bishopBlack);
                DeleteObject(bishopWhite);
                DeleteObject(bishop2Black);
                DeleteObject(bishop2White);
                DeleteObject(queenBlack);
                DeleteObject(queenWhite);
                DeleteObject(kingBlack);
                DeleteObject(kingWhite);
                
                GdiFlush();

            } else {

                hdcMem = CreateCompatibleDC(hdc);
                oldBitmap = SelectObject(hdcMem, hBitmap);

                GetObject(hBitmap, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

                SelectObject(hdcMem, oldBitmap);
                DeleteDC(hdcMem); DeleteObject(hBitmap);

                DrawChessBoard();

                Sleep(1);
                pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                Sleep(1);
                kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp;
                if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(rookWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(rookWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteRook1.posX+25+7, whiteRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(rook2White,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(rook2White,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteRook2.posX+25+7, whiteRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(knightWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(knightWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteKnight1.posX+25+7, whiteKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(knight2White,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(knight2White,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteKnight2.posX+25+7, whiteKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(bishopWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(bishopWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteBishop1.posX+25+7, whiteBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(bishop2White,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(bishop2White,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteBishop2.posX+25+7, whiteBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteQueen.posX+25+7, whiteQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(kingWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(kingWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteKing.posX+25+7, whiteKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                for(int o=0; o<8; o++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((whitePawns[o].posX/70)+(whitePawns[o].posY/70)) % 2 == 0)
                        hBmp = ReplaceColor(pawnWhite,0x110000,0xffffff,hdcMem);
                    else
                        hBmp = ReplaceColor(pawnWhite,0x110000,0x000000,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, whitePawns[o].posX+25+7, whitePawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(rookBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackRook1.posX+25+7, blackRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(rook2Black,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackRook2.posX+25+7, blackRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(knightBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(knightBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackKnight1.posX+25+7, blackKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(knight2Black,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(knight2Black,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackKnight2.posX+25+7, blackKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(bishopBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(bishopBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackBishop1.posX+25+7, blackBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(bishop2Black,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(bishop2Black,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackBishop2.posX+25+7, blackBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackQueen.posX+25+7, blackQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(kingBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(kingBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackKing.posX+25+7, blackKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                for(int o=0; o<8; o++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((blackPawns[o].posX/70)+(blackPawns[o].posY/70)) % 2 == 0)
                        hBmp = ReplaceColor(pawnBlack,0x110000,0xffffff,hdcMem);
                    else
                        hBmp = ReplaceColor(pawnBlack,0x110000,0x000000,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, blackPawns[o].posX+25+7, blackPawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }

                for(int m=0; m<8; m++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((whiteQueenK[m].posX/70)+(whiteQueenK[m].posY/70)) % 2 == 0)
                        hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                    else
                        hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, whiteQueenK[m].posX+25+7, whiteQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }

                for(int m=0; m<8; m++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((blackQueenK[m].posX/70)+(blackQueenK[m].posY/70)) % 2 == 0)
                        hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                    else
                        hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, blackQueenK[m].posX+25+7, blackQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }
                
                DeleteObject(pawnBlack);
                DeleteObject(pawnWhite);
                DeleteObject(knightBlack);
                DeleteObject(knightWhite);
                DeleteObject(knight2Black);
                DeleteObject(knight2White);
                DeleteObject(rookBlack);
                DeleteObject(rookWhite);
                DeleteObject(rook2Black);
                DeleteObject(rook2White);
                DeleteObject(bishopBlack);
                DeleteObject(bishopWhite);
                DeleteObject(bishop2Black);
                DeleteObject(bishop2White);
                DeleteObject(queenBlack);
                DeleteObject(queenWhite);
                DeleteObject(kingBlack);
                DeleteObject(kingWhite);
    
                GdiFlush();
            }

            Sleep(1);
            pawnBlack_s = (HBITMAP)LoadImage(hInst, "pawnblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            pawnWhite_s = (HBITMAP)LoadImage(hInst, "pawnwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knightBlack_s = (HBITMAP)LoadImage(hInst, "knightblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knightWhite_s = (HBITMAP)LoadImage(hInst, "knightwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knight2Black_s = (HBITMAP)LoadImage(hInst, "knightblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knight2White_s = (HBITMAP)LoadImage(hInst, "knightwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rookBlack_s = (HBITMAP)LoadImage(hInst, "rookblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rookWhite_s = (HBITMAP)LoadImage(hInst, "rookwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rook2Black_s = (HBITMAP)LoadImage(hInst, "rookblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rook2White_s = (HBITMAP)LoadImage(hInst, "rookwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishopBlack_s = (HBITMAP)LoadImage(hInst, "bishopblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishopWhite_s = (HBITMAP)LoadImage(hInst, "bishopwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishop2Black_s = (HBITMAP)LoadImage(hInst, "bishopblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishop2White_s = (HBITMAP)LoadImage(hInst, "bishopwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            queenBlack_s = (HBITMAP)LoadImage(hInst, "queenblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            queenWhite_s = (HBITMAP)LoadImage(hInst, "queenwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            kingBlack_s = (HBITMAP)LoadImage(hInst, "kingblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            kingWhite_s = (HBITMAP)LoadImage(hInst, "kingwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            _y_ = 20;

            HBRUSH yellow_brush = CreateSolidBrush(RGB(255,255,0));
            RECT rrect = {635+0, 17, 910, 740};
            FillRect(hdc, &rrect, yellow_brush);
            DeleteObject(yellow_brush);

            if(whiteRook1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rookWhite_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteRook1.from != NULL && whiteRook1.to != NULL) {
                    if(strlen(whiteRook1.from) >= 2 && strlen(whiteRook1.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteRook1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteRook2.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rook2White_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteRook2.from != NULL && whiteRook2.to != NULL) {
                    if(strlen(whiteRook2.from) >= 2 && strlen(whiteRook2.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteRook2.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteKnight1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knightWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteKnight1.from != NULL && whiteKnight1.to != NULL) {
                    if(strlen(whiteKnight1.from) >= 2 && strlen(whiteKnight1.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteKnight1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteKnight2.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knight2White_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteKnight2.from != NULL && whiteKnight2.to != NULL) {
                    if(strlen(whiteKnight2.from) >= 2 && strlen(whiteKnight2.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteKnight2.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteBishop1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishopWhite_s,0x4cb122,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteBishop1.from != NULL && whiteBishop1.to != NULL) {
                    if(strlen(whiteBishop1.from) >= 2 && strlen(whiteBishop1.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteBishop1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteBishop2.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishop2White_s,0x4cb122,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteBishop2.from != NULL && whiteBishop2.to != NULL) {
                    if(strlen(whiteBishop2.from) >= 2 && strlen(whiteBishop2.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteBishop2.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteQueen.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(whiteQueen.from != NULL && whiteQueen.to != NULL) {
                    if(strlen(whiteQueen.from) >= 2 && strlen(whiteQueen.to) >= 2) {
                        TextOut(hdc,
                                615+50,
                                _y_,
                                whiteQueen.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(whiteKing.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(kingWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            for(int o=0; o<8; o++) {
                if(whitePawns[o].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(pawnWhite_s,0x000000,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(whitePawns[o].from != NULL && whitePawns[o].to != NULL) {
                        if(strlen(whitePawns[o].from) >= 2 && strlen(whitePawns[o].to) >= 2) {
                            TextOut(hdc,
                                    615+50,
                                    _y_,
                                    whitePawns[o].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            for(int m=0; m<8; m++) {
                if(whiteQueenK[m].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(whiteQueenK[m].from != NULL && whiteQueenK[m].to != NULL) {
                        if(strlen(whiteQueenK[m].from) >= 2 && strlen(whiteQueenK[m].to) >= 2) {
                            TextOut(hdc,
                                    615+50,
                                    _y_,
                                    whiteQueenK[m].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            _y_ = 20;

            if(blackRook1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rookBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackRook1.from != NULL && blackRook1.to != NULL) {
                    if(strlen(blackRook1.from) >= 2 && strlen(blackRook1.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackRook1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackRook2.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rook2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackRook2.from != NULL && blackRook2.to != NULL) {
                    if(strlen(blackRook2.from) >= 2 && strlen(blackRook2.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackRook2.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackKnight1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knightBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackKnight1.from != NULL && blackKnight1.to != NULL) {
                    if(strlen(blackKnight1.from) >= 2 && strlen(blackKnight1.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackKnight1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackKnight2.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knight2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackKnight2.from != NULL && blackKnight2.to != NULL) {
                    if(strlen(blackKnight2.from) >= 2 && strlen(blackKnight2.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackKnight2.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackBishop1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishopBlack_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackBishop1.from != NULL && blackBishop1.to != NULL) {
                    if(strlen(blackBishop1.from) >= 2 && strlen(blackBishop1.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackBishop1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackBishop2.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishop2Black_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackBishop2.from != NULL && blackBishop2.to != NULL) {
                    if(strlen(blackBishop2.from) >= 2 && strlen(blackBishop2.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackBishop2.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackQueen.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(blackQueen.from != NULL && blackQueen.to != NULL) {
                    if(strlen(blackQueen.from) >= 2 && strlen(blackQueen.to) >= 2) {
                        TextOut(hdc,
                                690+50,
                                _y_,
                                blackQueen.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(blackKing.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(kingBlack_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            for(int o=0; o<8; o++) {
                if(blackPawns[o].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(pawnBlack_s,0xff0000,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(blackPawns[o].from != NULL && blackPawns[o].to != NULL) {
                        if(strlen(blackPawns[o].from) >= 2 && strlen(blackPawns[o].to) >= 2) {
                            TextOut(hdc,
                                    690+50,
                                    _y_,
                                    blackPawns[o].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            for(int m=0; m<8; m++) {
                if(blackQueenK[m].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(blackQueenK[m].from != NULL && blackQueenK[m].to != NULL) {
                        if(strlen(blackQueenK[m].from) >= 2 && strlen(blackQueenK[m].to) >= 2) {
                            TextOut(hdc,
                                    690+50,
                                    _y_,
                                    blackQueenK[m].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            DeleteObject(pawnBlack_s);
            DeleteObject(pawnWhite_s);
            DeleteObject(knightBlack_s);
            DeleteObject(knightWhite_s);
            DeleteObject(knight2Black_s);
            DeleteObject(knight2White_s);
            DeleteObject(rookBlack_s);
            DeleteObject(rookWhite_s);
            DeleteObject(rook2Black_s);
            DeleteObject(rook2White_s);
            DeleteObject(bishopBlack_s);
            DeleteObject(bishopWhite_s);
            DeleteObject(bishop2Black_s);
            DeleteObject(bishop2White_s);
            DeleteObject(queenBlack_s);
            DeleteObject(queenWhite_s);
            DeleteObject(kingBlack_s);
            DeleteObject(kingWhite_s);

            GdiFlush();
        }
        break;
        case WM_LBUTTONUP:
            klicked = FALSE;
            
            DrawChessBoard();

            Sleep(1);
            pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            Sleep(1);
            kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp;
            if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(rookWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(rookWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteRook1.posX+25+7, whiteRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(rook2White,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(rook2White,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteRook2.posX+25+7, whiteRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(knightWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(knightWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteKnight1.posX+25+7, whiteKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(knight2White,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(knight2White,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteKnight2.posX+25+7, whiteKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(bishopWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(bishopWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteBishop1.posX+25+7, whiteBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(bishop2White,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(bishop2White,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteBishop2.posX+25+7, whiteBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteQueen.posX+25+7, whiteQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            
            hdcMem = CreateCompatibleDC(hdc);
            if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(kingWhite,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(kingWhite,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, whiteKing.posX+25+7, whiteKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            for(int o=0; o<8; o++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((whitePawns[o].posX/70)+(whitePawns[o].posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(pawnWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(pawnWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whitePawns[o].posX+25+7, whitePawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(rookBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackRook1.posX+25+7, blackRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(rook2Black,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(rook2Black,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackRook2.posX+25+7, blackRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(knightBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(knightBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackKnight1.posX+25+7, blackKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(knight2Black,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(knight2Black,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackKnight2.posX+25+7, blackKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(bishopBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(bishopBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackBishop1.posX+25+7, blackBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(bishop2Black,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(bishop2Black,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackBishop2.posX+25+7, blackBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackQueen.posX+25+7, blackQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            
            hdcMem = CreateCompatibleDC(hdc);
            if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0)
                hBmp = ReplaceColor(kingBlack,0x110000,0xffffff,hdcMem);
            else
                hBmp = ReplaceColor(kingBlack,0x110000,0x000000,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, blackKing.posX+25+7, blackKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            for(int o=0; o<8; o++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((blackPawns[o].posX/70)+(blackPawns[o].posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(pawnBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(pawnBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackPawns[o].posX+25+7, blackPawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }

            for(int m=0; m<8; m++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((whiteQueenK[m].posX/70)+(whiteQueenK[m].posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, whiteQueenK[m].posX+25+7, whiteQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }

            //draw grey queen
            for(int m=0; m<8; m++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((blackQueenK[m].posX/70)+(blackQueenK[m].posY/70)) % 2 == 0)
                    hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                else
                    hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, blackQueenK[m].posX+25+7, blackQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }
            
            DeleteObject(pawnBlack);
            DeleteObject(pawnWhite);
            DeleteObject(knightBlack);
            DeleteObject(knightWhite);
            DeleteObject(knight2Black);
            DeleteObject(knight2White);
            DeleteObject(rookBlack);
            DeleteObject(rookWhite);
            DeleteObject(rook2Black);
            DeleteObject(rook2White);
            DeleteObject(bishopBlack);
            DeleteObject(bishopWhite);
            DeleteObject(bishop2Black);
            DeleteObject(bishop2White);
            DeleteObject(queenBlack);
            DeleteObject(queenWhite);
            DeleteObject(kingBlack);
            DeleteObject(kingWhite);

            GdiFlush();

        case WM_LBUTTONDOWN:
        {
            if(msg == WM_LBUTTONDOWN)
                klicked = TRUE;
            
            done = FALSE;

            if(checkmate)
                break;

            int iPosX = LOWORD(lParam);
            int iPosY = HIWORD(lParam);

            for(int j=0; j<8; j++) {
                for(int i=0; i<8; i++) {
                    if(iPosX >= i*70+20+20 &&
                       iPosY >= j*70+20+20 &&
                       iPosX < i*70+20+20+70 &&
                       iPosY < j*70+20+20+70) {
                        
                        for(int k=0; k<8; k++) {
                            for(int l=0; l<8; l++) {
                                boxes[k][l].clicked = FALSE;
                            }
                        }
                        boxes[j][i].clicked = TRUE;

                        if(turn == 'h') {
                            
                            for(int k=0; k<8; k++) {
                            
                                if(whitePawns[k].posX == i*70+20 &&
                                   whitePawns[k].posY == j*70+20) {

                                    clickedOne = 'g';
                                    whitePawns[k].clicked = TRUE;
                                    whitePawns[k].from = map(j, i);
                                    from = map(j, i);
                                    turn = 'h';

                                    if(msg == WM_LBUTTONDOWN) {
                                        if(whitePawnsStart == -1 || whitePawnsFunc == -1) {
                                            whitePawnsIndex = k;
                                            whiteBishop2Func = -1;
                                            whiteBishop1Func = -1;
                                            whiteKnight1Func = -1;
                                            whiteKnight2Func = -1;
                                            whitePawnsFunc = 0;
                                            whiteRook1Func = -1;
                                            whiteRook2Func = -1;
                                            whiteKingFunc = -1;
                                            whiteQueenFunc = -1;
                                            wpThread = CreateThread(NULL, 0, paintWhitePawn, NULL, 0, NULL);
                                            whitePawnsStart = 0;
                                        }
                                    }
                                    
                                    strncpy(chosenPiece, "pw", 2);
                                    
                                    for(int l=0; l<8; l++) {
                                        blackPawns[l].clicked = FALSE;
                                    }

                                    for(int l=0; l<8; l++) {
                                        if(l != k) {
                                            whitePawns[l].clicked = FALSE;
                                        }
                                    }
                                } else {
                                    if(whitePawns[k].clicked == TRUE) {
                                        whitePawns[k].to = map(j, i);
                                        to = map(j, i);
                                    }
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(clickedOne == 'g' &&
                                       whitePawns[k].clicked == TRUE && 
                                       whitePawns[k].firstTimeMove == TRUE) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

//                                        for(int m=0; m<8; m++) {
//                                            if(whitePawns[m].posY == whitePawns[k].posY - 70 &&
//                                               (whitePawns[m].posX == whitePawns[k].posX + 70 || whitePawns[m].posX == whitePawns[k].posX - 70)) {
//                                                ff = TRUE;
//                                            }
//                                            if(whitePawns[m].posY == whitePawns[k].posY - 70 &&
//                                               whitePawns[m].posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whitePawns[m].posY == whitePawns[k].posY - 70 &&
//                                               whitePawns[m].posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight1.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight2.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop1.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop2.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook1.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook2.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight1.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight2.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop1.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop2.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook1.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook2.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                        }
                                        
                                        if(!ff &&
                                           j*70+20 == whitePawns[k].posY - 70 &&
                                          (i*70+20 == whitePawns[k].posX + 70 ||
                                           i*70+20 == whitePawns[k].posX - 70)) {

                                            turn = 'r';

                                            boolean ate = FALSE;
                                            
                                            int a0 = whitePawns[k].posX;
                                            int a1 = whitePawns[k].posY;

                                            boxes[j][i].clear = FALSE;
                                            boxes[whitePawns[k].posY/70][whitePawns[k].posX/70].clear = TRUE;
                                            whitePawns[k].posY = j*70+20;
                                            whitePawns[k].posX = i*70+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if(blackPawns[l].posX == i*70+20 &&
                                                   blackPawns[l].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(blackQueenK[z].posX == i*70+20 &&
                                                   blackQueenK[z].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(blackQueen.posX == i*70+20 &&
                                               blackQueen.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackBishop1.posX == i*70+20 &&
                                               blackBishop1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackBishop2.posX == i*70+20 &&
                                               blackBishop2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackKnight1.posX == i*70+20 &&
                                               blackKnight1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackKnight2.posX == i*70+20 &&
                                               blackKnight2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackRook1.posX == i*70+20 &&
                                               blackRook1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackRook2.posX == i*70+20 &&
                                               blackRook2.posY == j*70+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(blackPawns[u].posX == whitePawns[k].posX &&
                                                   blackPawns[u].posY == whitePawns[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckWhite(j, i);

                                            if(ffff && fff) {
                                                whitePawns[k].posX = a0;
                                                whitePawns[k].posY = a1;

                                                turn = 'h';

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if(blackPawns[l].posX == i*70+20 &&
                                                       blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whitePawns[k].posX &&
                                                       blackPawns[u].posY == whitePawns[k].posY) {
                                                        blackPawns[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    whitePawnsFunc = -1;

                                                    whitePawns[k].firstTimeMove = FALSE;

                                                    whitePawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                } else {
                                                    whitePawns[k].posX = a0;
                                                    whitePawns[k].posY = a1;

                                                    turn = 'h';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                                j*70+20 == whitePawns[k].posY - 70 &&
                                                i*70+20 == whitePawns[k].posX) {

                                            turn = 'r';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(whitePawns[s].posX == whitePawns[k].posX &&
                                                   whitePawns[s].posY + 70 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == whitePawns[k].posX &&
                                                   blackPawns[s].posY + 70 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = whitePawns[k].posX;
                                                int a1 = whitePawns[k].posY;
                                                
                                                boxes[j][i].clear = FALSE;
                                                boxes[whitePawns[k].posY/70][whitePawns[k].posX/70].clear = TRUE;

                                                whitePawns[k].posY = j*70+20;

                                                boolean ffff = checkCheckWhite(j, i);
                                                
                                                if(ffff) {
                                                    whitePawns[k].posX = a0;
                                                    whitePawns[k].posY = a1;

                                                    turn = 'h';
                                                } else {
                                                    whitePawnsFunc = -1;

                                                    whitePawns[k].firstTimeMove = FALSE;

                                                    whitePawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            } else {
                                                turn = 'h';
                                            }
                                        }

                                        else if(!fail &&
                                                j*70+20 == whitePawns[k].posY - 140 &&
                                                i*70+20 == whitePawns[k].posX) {

                                            turn = 'r';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(whitePawns[s].posX == whitePawns[k].posX &&
                                                   whitePawns[s].posY + 70 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(whitePawns[s].posX == whitePawns[k].posX &&
                                                   whitePawns[s].posY + 140 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == whitePawns[k].posX &&
                                                   blackPawns[s].posY + 70 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == whitePawns[k].posX &&
                                                   blackPawns[s].posY + 140 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = whitePawns[k].posX;
                                                int a1 = whitePawns[k].posY;
                                                
                                                whitePawns[k].posX = a0;
                                                whitePawns[k].posY = a1;

                                                boxes[j][i].clear = FALSE;
                                                boxes[whitePawns[k].posY/70][whitePawns[k].posX/70].clear = TRUE;

                                                whitePawns[k].posY = j*70+20;

                                                boolean ffff = checkCheckWhite(j, i);
                                                
                                                if(ffff) {

                                                    whitePawns[k].posX = a0;
                                                    whitePawns[k].posY = a1;

                                                    turn = 'h';
                                                } else {
                                                    whitePawnsFunc = -1;

                                                    whitePawns[k].firstTimeMove = FALSE;

                                                    whitePawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }                       
                                            } else {
                                                turn = 'h';
                                            }
                                        }

                                    } else if(clickedOne == 'g' &&
                                              whitePawns[k].clicked) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

//                                        for(int m=0; m<8; m++) {
//                                            if(whitePawns[m].posY == whitePawns[k].posY - 70 &&
//                                               (whitePawns[m].posX == whitePawns[k].posX + 70 || whitePawns[m].posX == whitePawns[k].posX - 70)) {
//                                                ff = TRUE;
//                                            }
//                                            if(whitePawns[m].posY == whitePawns[k].posY - 70 &&
//                                               whitePawns[m].posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whitePawns[m].posY == whitePawns[k].posY - 70 &&
//                                               whitePawns[m].posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight1.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight2.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop1.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop2.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook1.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook2.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight1.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight2.posY == whitePawns[k].posY - 70 &&
//                                               whiteKnight2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop1.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop2.posY == whitePawns[k].posY - 70 &&
//                                               whiteBishop2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook1.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook1.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook2.posY == whitePawns[k].posY - 70 &&
//                                               whiteRook2.posX == whitePawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                        }
                                        
                                        if(!ff &&
                                           j*70+20 == whitePawns[k].posY - 70 &&
                                          (i*70+20 == whitePawns[k].posX - 70 ||
                                           i*70+20 == whitePawns[k].posX + 70)) {

                                            turn = 'r';

                                            boolean ate = FALSE;

                                            int a0 = whitePawns[k].posX;
                                            int a1 = whitePawns[k].posY;

                                            boxes[j][i].clear = FALSE;
                                            boxes[whitePawns[k].posY/70][whitePawns[k].posX/70].clear = TRUE;

                                            whitePawns[k].posY = j*70+20;
                                            whitePawns[k].posX = i*70+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if(blackPawns[l].posX == i*70+20 &&
                                                   blackPawns[l].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(blackQueenK[z].posX == i*70+20 &&
                                                   blackQueenK[z].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(blackQueen.posX == i*70+20 &&
                                               blackQueen.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackBishop1.posX == i*70+20 &&
                                               blackBishop1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackBishop2.posX == i*70+20 &&
                                               blackBishop2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackKnight1.posX == i*70+20 &&
                                               blackKnight1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackKnight2.posX == i*70+20 &&
                                               blackKnight2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackRook1.posX == i*70+20 &&
                                               blackRook1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(blackRook2.posX == i*70+20 &&
                                               blackRook2.posY == j*70+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(blackPawns[u].posX == whitePawns[k].posX &&
                                                   blackPawns[u].posY == whitePawns[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckWhite(j, i);

                                            if(ffff && fff) {
                                                whitePawns[k].posX = a0;
                                                whitePawns[k].posY = a1;

                                                turn = 'h';
                                            
                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whitePawns[k].posX ||
                                                        blackPawns[l].posX == whitePawns[k].posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whitePawns[k].posX &&
                                                       blackPawns[u].posY == whitePawns[k].posY) {
                                                        blackPawns[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    whitePawnsFunc = -1;

                                                    whitePawns[k].firstTimeMove = FALSE;
                                                    whitePawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                } else {
                                                    whitePawns[k].posX = a0;
                                                    whitePawns[k].posY = a1;

                                                    turn = 'h';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                           j*70+20 == whitePawns[k].posY - 70 &&
                                           i*70+20 == whitePawns[k].posX) {

                                            turn = 'r';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(whitePawns[s].posX == whitePawns[k].posX &&
                                                   whitePawns[s].posY + 70 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == whitePawns[k].posX &&
                                                   blackPawns[s].posY + 70 == whitePawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = whitePawns[k].posX;
                                                int a1 = whitePawns[k].posY;
                                                
                                                boxes[j][i].clear = FALSE;
                                                boxes[whitePawns[k].posY/70][whitePawns[k].posX/70].clear = TRUE;

                                                whitePawns[k].posY = j*70+20;

                                                boolean ffff = checkCheckWhite(j, i);
                                                
                                                if(ffff) {
                                                    whitePawns[k].posX = a0;
                                                    whitePawns[k].posY = a1;

                                                    turn = 'h';
                                                } else {
                                                    whitePawnsFunc = -1;

                                                    whitePawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            } else {
                                                turn = 'h';
                                            }
                                        }
                                    }
                                }
                            }

                            boolean itdid = FALSE;
                            
                            if(whiteKnight2.posX == i*70+20 &&
                               whiteKnight2.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteKnight2.clicked = TRUE;
                                whiteKnight2.from = (char*) malloc(2);
                                whiteKnight2.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteKnight2Start == -1 || whiteKnight2Func == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop2Func = -1;
                                        whiteBishop1Func = -1;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = 0;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = -1;
                                        wk2Thread = CreateThread(NULL, 0, paintWhiteKnight2, NULL, 0, NULL);
                                        whiteKnight2Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "kw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteKnight2.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteKnight2.clicked == TRUE) {
                                    whiteKnight2.to = (char*) malloc(2);
                                    whiteKnight2.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;
                                    
                                    clickedOne = 'g';

                                    whiteKnight2.clicked = FALSE;

                                    if(j*70+20 == whiteKnight2.posY - 140 &&
                                       i*70+20 == whiteKnight2.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        int a1 = whiteKnight2.posY;
                                        int a0 = whiteKnight2.posX;

                                        whiteKnight2.posX = i*70+20;
                                        whiteKnight2.posY = j*70+20;

                                        if(!failed) {

                                            boolean ffff = checkCheckWhite(j, i);

                                            if(ffff) {

                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY - 140 &&
                                              i*70+20 == whiteKnight2.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY - 70 &&
                                              i*70+20 == whiteKnight2.posX - 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);

                                            if(ffff) {
                                                
                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY + 70 &&
                                              i*70+20 == whiteKnight2.posX - 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                                
                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY + 140 &&
                                              i*70+20 == whiteKnight2.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                                
                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;
                                                
                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY + 140 &&
                                              i*70+20 == whiteKnight2.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);

                                            if(ffff) {

                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY - 70 &&
                                              i*70+20 == whiteKnight2.posX + 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                            
                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight2.posY + 70 &&
                                              i*70+20 == whiteKnight2.posX + 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight2.posY;
                                            int a0 = whiteKnight2.posX;

                                            whiteKnight2.posX = i*70+20;
                                            whiteKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                                
                                                whiteKnight2.posY = a1;
                                                whiteKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    }
                                }
                            }

                            itdid = FALSE;
                            
                            if(whiteKnight1.posX == i*70+20 &&
                               whiteKnight1.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteKnight1.clicked = TRUE;
                                whiteKnight1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteKnight1Start == -1 || whiteKnight1Func == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop2Func = -1;
                                        whiteBishop1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteKnight1Func = 0;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = -1;
                                        wk1Thread = CreateThread(NULL, 0, paintWhiteKnight1, NULL, 0, NULL);
                                        whiteKnight1Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "kw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteKnight1.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteKnight1.clicked == TRUE) {
                                    whiteKnight1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;
                                    
                                    clickedOne = 'g';

                                    whiteKnight1.clicked = FALSE;

                                    if(j*70+20 == whiteKnight1.posY - 140 &&
                                       i*70+20 == whiteKnight1.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;
                                                
                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY - 140 &&
                                              i*70+20 == whiteKnight1.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY - 70 &&
                                              i*70+20 == whiteKnight1.posX - 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;

                                            } else {
                                            
                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY + 70 &&
                                              i*70+20 == whiteKnight1.posX - 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                            
                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;

                                            } else {
                                            
                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY + 140 &&
                                              i*70+20 == whiteKnight1.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                            
                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;
                                                
                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY + 140 &&
                                              i*70+20 == whiteKnight1.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;

                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                                
                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;

                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY - 70 &&
                                              i*70+20 == whiteKnight1.posX + 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                                
                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;

                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKnight1.posY + 70 &&
                                              i*70+20 == whiteKnight1.posX + 140) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = whiteKnight1.posY;
                                            int a0 = whiteKnight1.posX;
                                            
                                            whiteKnight1.posX = i*70+20;
                                            whiteKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckWhite(j, i);

                                            if(ffff) {
                                                
                                                whiteKnight1.posY = a1;
                                                whiteKnight1.posX = a0;

                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(blackPawns[t].posX == i*70+20 &&
                                                       blackPawns[t].posY == j*70+20) {
                                                        blackPawns[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                whiteKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    }
                                }
                            }
                            
                            itdid = FALSE;
                            
                            if(whiteKing.posX == i*70+20 &&
                               whiteKing.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteKing.clicked = TRUE;
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteKingStart == -1 || whiteKingFunc == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop1Func = -1;
                                        whiteBishop2Func = -1;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = 0;
                                        whiteQueenFunc = -1;
                                        wkThread = CreateThread(NULL, 0, paintWhiteKing, NULL, 0, NULL);
                                        whiteKingStart = 0;
                                    }
                                }
                                strncpy(chosenPiece, "cw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteKing.clicked == TRUE) {
                                itdid = TRUE;
                                to = map(j, i);
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;
                                    
                                    clickedOne = 'g';

                                    whiteKing.clicked = FALSE;

                                    if(j*70+20 == whiteKing.posY &&
                                       i*70+20 == whiteKing.posX - 140) {
                                        if(whiteRook1.posY == 490+20 &&
                                           whiteRook1.posX == 0+20) {
                                            if(whiteKing.posY == 490+20 &&
                                               whiteKing.posX == 280+20) {
                                                boolean isthere = FALSE;
                                                if(whiteRook1.posX == 210+20 &&
                                                   whiteRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook1.posX == 140+20 &&
                                                   whiteRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook1.posX == 70+20 &&
                                                   whiteRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 210+20 &&
                                                   whiteRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 140+20 &&
                                                   whiteRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 70+20 &&
                                                   whiteRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 210+20 &&
                                                   blackRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 140+20 &&
                                                   blackRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 70+20 &&
                                                   blackRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 210+20 &&
                                                   blackRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 140+20 &&
                                                   blackRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 70+20 &&
                                                   blackRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 210+20 &&
                                                   whiteBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 140+20 &&
                                                   whiteBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 70+20 &&
                                                   whiteBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 210+20 &&
                                                   whiteBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 140+20 &&
                                                   whiteBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 70+20 &&
                                                   whiteBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 210+20 &&
                                                   blackBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 140+20 &&
                                                   blackBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 70+20 &&
                                                   blackBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 210+20 &&
                                                   blackBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 140+20 &&
                                                   blackBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 70+20 &&
                                                   blackBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 210+20 &&
                                                   whiteKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 140+20 &&
                                                   whiteKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 70+20 &&
                                                   whiteKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 210+20 &&
                                                   whiteKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 140+20 &&
                                                   whiteKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 70+20 &&
                                                   whiteKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 210+20 &&
                                                   blackKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 140+20 &&
                                                   blackKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 70+20 &&
                                                   blackKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 210+20 &&
                                                   blackKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 140+20 &&
                                                   blackKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 70+20 &&
                                                   blackKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 210+20 &&
                                                   whiteQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 140+20 &&
                                                   whiteQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 70+20 &&
                                                   whiteQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 210+20 &&
                                                   blackQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 140+20 &&
                                                   blackQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 70+20 &&
                                                   blackQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !whiteKingMoved && !whiteRook1Moved) {
                                                    whiteKing.posX -= 140;
                                                    whiteRook1.posX += 210;
                                                    whiteKingMoved = TRUE;
                                                    whiteRook1Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'r';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*70+20 == whiteKing.posY &&
                                       i*70+20 == whiteKing.posX + 140) {
                                        if(whiteRook2.posY == 490+20 &&
                                           whiteRook2.posX == 490+20) {
                                            if(whiteKing.posY == 490+20 &&
                                               whiteKing.posX == 400+20) {
                                                boolean isthere = FALSE;
                                                if(whiteRook1.posX == 350+20 &&
                                                   whiteRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook1.posX == 420+20 &&
                                                   whiteRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 350+20 &&
                                                   whiteRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 420+20 &&
                                                   whiteRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 350+20 &&
                                                   blackRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 420+20 &&
                                                   blackRook1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 350+20 &&
                                                   blackRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 420+20 &&
                                                   blackRook2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 350+20 &&
                                                   whiteBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 420+20 &&
                                                   whiteBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 350+20 &&
                                                   whiteBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 420+20 &&
                                                   whiteBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 350+20 &&
                                                   blackBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 420+20 &&
                                                   blackBishop1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 350+20 &&
                                                   blackBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 420+20 &&
                                                   blackBishop2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 350+20 &&
                                                   whiteKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 420+20 &&
                                                   whiteKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 350+20 &&
                                                   whiteKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 420+20 &&
                                                   whiteKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 350+20 &&
                                                   blackKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 420+20 &&
                                                   blackKnight1.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 350+20 &&
                                                   blackKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 420+20 &&
                                                   blackKnight2.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 350+20 &&
                                                   whiteQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 420+20 &&
                                                   whiteQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 350+20 &&
                                                   blackQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 420+20 &&
                                                   blackQueen.posY == 490+20) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !whiteKingMoved && !whiteRook2Moved) {
                                                    whiteKing.posX += 140;
                                                    whiteRook2.posX -= 140;
                                                    whiteKingMoved = TRUE;
                                                    whiteRook2Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'r';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*70+20 == whiteKing.posY - 70 &&
                                       i*70+20 == whiteKing.posX) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;

                                            whiteKing.posY -= 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY - 70 &&
                                              i*70+20 == whiteKing.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;

                                            whiteKing.posY -= 70;
                                            whiteKing.posX += 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {
                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {
                                            
                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY &&
                                              i*70+20 == whiteKing.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;

                                            whiteKing.posX += 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY + 70 &&
                                              i*70+20 == whiteKing.posX + 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;

                                            whiteKing.posX += 70;
                                            whiteKing.posY += 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY + 70 &&
                                              i*70+20 == whiteKing.posX) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;
                                            
                                            whiteKing.posY += 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY + 70 &&
                                              i*70+20 == whiteKing.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;
                                            
                                            whiteKing.posX -= 70;
                                            whiteKing.posY += 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY &&
                                              i*70+20 == whiteKing.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;
                                            
                                            whiteKing.posX -= 70;

                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == whiteKing.posY - 70 &&
                                              i*70+20 == whiteKing.posX - 70) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(whitePawns[t].posX == i*70+20 &&
                                               whitePawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(whiteQueen.posX == i*70+20 &&
                                           whiteQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop1.posX == i*70+20 &&
                                           whiteBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteBishop2.posX == i*70+20 &&
                                           whiteBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight1.posX == i*70+20 &&
                                           whiteKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKnight2.posX == i*70+20 &&
                                           whiteKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook1.posX == i*70+20 &&
                                           whiteRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteRook2.posX == i*70+20 &&
                                           whiteRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            
                                            int a1 = whiteKing.posY;
                                            int a0 = whiteKing.posX;
                                            
                                            whiteKing.posX -= 70;
                                            whiteKing.posY -= 70;
                                            
                                            boolean ffff = checkCheckWhite(j, i);
                                            
                                            if(ffff) {

                                                whiteKing.posY = a1;
                                                whiteKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((blackPawns[l].posX == whiteKing.posX ||
                                                        blackPawns[l].posX == whiteKing.posX) && 
                                                        blackPawns[l].posY == j*70+20) {
                                                        blackPawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(blackQueen.posX == i*70+20 &&
                                                   blackQueen.posY == j*70+20) {
                                                    blackQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(blackQueenK[z].posX == i*70+20 &&
                                                       blackQueenK[z].posY == j*70+20) {
                                                        blackQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(blackBishop1.posX == i*70+20 &&
                                                   blackBishop1.posY == j*70+20) {
                                                    blackBishop1.posX = 1300;
                                                }
                                                if(blackBishop2.posX == i*70+20 &&
                                                   blackBishop2.posY == j*70+20) {
                                                    blackBishop2.posX = 1300;
                                                }
                                                if(blackKnight1.posX == i*70+20 &&
                                                   blackKnight1.posY == j*70+20) {
                                                    blackKnight1.posX = 1300;
                                                }
                                                if(blackKnight2.posX == i*70+20 &&
                                                   blackKnight2.posY == j*70+20) {
                                                    blackKnight2.posX = 1300;
                                                }
                                                if(blackRook1.posX == i*70+20 &&
                                                   blackRook1.posY == j*70+20) {
                                                    blackRook1.posX = 1300;
                                                }
                                                if(blackRook2.posX == i*70+20 &&
                                                   blackRook2.posY == j*70+20) {
                                                    blackRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(blackPawns[u].posX == whiteKing.posX &&
                                                       blackPawns[u].posY == whiteKing.posY + 70) {
                                                        blackPawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                whiteKingMoved = TRUE;
                                                done = TRUE;
                                                whiteKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    }
                                }
                            }

                            boolean changeii = FALSE;
                            
                            for(int z=0; z<8; z++) {
                                if(whitePawns[z].posY == 0+20) {
                                    strncpy(chosenPiece, "qw", 2);
                                    changeii = TRUE;
                                    int x = whitePawns[z].posX;
                                    int y = whitePawns[z].posY;
                                    strcat(whitePawns[z].to,"q");
                                    strcat(to,"q");
                                    whiteQueenK[z].posX = x;
                                    whiteQueenK[z].posY = y;
                                    whiteQueenK[z].from = map(j, i);
                                    whiteQueenK[z].to = map(j, i);
                                    
                                    whitePawns[z].posX = 1300;
                                    whitePawns[z].posY = -1000;
                                    
                                    turn = 'r';
                                }
                            }

                            itdid = FALSE;
                            
                            if(whiteQueen.posX == i*70+20 &&
                               whiteQueen.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteQueen.clicked = TRUE;
                                whiteQueen.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteQueenStart == -1 || whiteQueenFunc == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop1Func = -1;
                                        whiteBishop2Func = -1;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = 0;
                                        wqThread = CreateThread(NULL, 0, paintWhiteQueen, NULL, 0, NULL);
                                        whiteQueenStart = 0;
                                    }
                                }
                                strncpy(chosenPiece, "qw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteQueen.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteQueen.clicked == TRUE) {
                                    whiteQueen.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    whiteQueen.clicked = FALSE;

                                    int a1 = whiteQueen.posY;
                                    int a0 = whiteQueen.posX;

                                    boxes[whiteQueen.posY/70][whiteQueen.posX/70].clear = TRUE;
                                    boolean f = FALSE;
                                    
                                    whiteQueen.failedpath = FALSE;

                                    if(i*70+20 == whiteQueen.posX) {
                                        f = moveWhiteQueen(msg, j, i, j*70+20 - whiteQueen.posY, j*70+20 - whiteQueen.posY);
                                        f = whiteQueen.failedpath;
                                    } else if(j*70+20 == whiteQueen.posY) {
                                        f = moveWhiteQueenSide(msg, j, i, i*70+20 - whiteQueen.posX, i*70+20 - whiteQueen.posX);
                                        f = whiteQueen.failedpath;
                                    } else if(i*70+20 != whiteQueen.posX &&
                                       j*70+20 != whiteQueen.posY) {
                                        f = moveWhiteQueenDiagonally(msg, j, i, j*70+20 - whiteQueen.posY, i*70+20 - whiteQueen.posX, j*70+20 - whiteQueen.posY, i*70+20 - whiteQueen.posX);
                                        f = whiteQueen.failedpath;
                                    }

                                    boolean fff = checkCheckWhite(j, i);

                                    if(f || fff) {

                                        whiteQueen.posY = a1;
                                        whiteQueen.posX = a0;

                                        turn = 'h';
                                    }

                                    else if(1 == 1) {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        whiteQueenFunc = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    
                                    itdid = FALSE;
                                }
                            }

                            for(int z=0; z<8; z++) {

                                itdid = FALSE;

                                if(changeii == FALSE &&
                                   whiteQueenK[z].posX == i*70+20 &&
                                   whiteQueenK[z].posY == j*70+20) {

                                    clickedOne = 'h';
                                    whiteQueenK[z].clicked = TRUE;
                                    whiteQueenK[z].from = map(j, i);
                                    from = map(j, i);
                                    turn = 'h';
                                    strncpy(chosenPiece, "qw", 2);
                                } else if(clickedOne == 'h' &&
                                          whiteQueenK[z].clicked == TRUE) {
                                    itdid = TRUE;
                                    if(whiteQueenK[z].clicked == TRUE) {
                                        whiteQueenK[z].to = map(j, i);
                                        to = map(j, i);
                                    }
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(itdid && changeii == FALSE) {

                                        clickedOne = 'h';
                                        whiteQueenK[z].clicked = FALSE;

                                        int a1 = whiteQueenK[z].posY;
                                        int a0 = whiteQueenK[z].posX;

                                        boolean f = FALSE;

                                        whiteQueenK[z].failedpath = FALSE;

                                        if(i*70+20 == whiteQueenK[z].posX) {
                                            f = moveWhiteQueenK(msg, j, i, j*70+20 - whiteQueenK[z].posY, j*70+20 - whiteQueenK[z].posY, z);
                                            f = whiteQueenK[z].failedpath;
                                        } else if(j*70+20 == whiteQueenK[z].posY) {
                                            f = moveWhiteQueenSideK(msg, j, i, i*70+20 - whiteQueenK[z].posX, i*70+20 - whiteQueenK[z].posX, z);
                                            f = whiteQueenK[z].failedpath;
                                        } else if(i*70+20 != whiteQueenK[z].posX &&
                                           j*70+20 != whiteQueenK[z].posY) {
                                            if(j*70+20 - whiteQueenK[z].posY == i*70+20 - whiteQueenK[z].posX ||
                                               j*70+20 - whiteQueenK[z].posY == -1 * (i*70+20 - whiteQueenK[z].posX)) {
                                                f = moveWhiteQueenDiagonallyK(msg, j, i, j*70+20 - whiteQueenK[z].posY, i*70+20 - whiteQueenK[z].posX, j*70+20 - whiteQueenK[z].posY, i*70+20 - whiteQueenK[z].posX, z);
                                                f = whiteQueenK[z].failedpath;
                                            } else {
                                                f = whiteQueenK[z].failedpath = TRUE;
                                            }
                                        }
                                        
                                        boolean fff = checkCheckWhite(j, i);

                                        if(f || fff) {

                                            whiteQueenK[z].posY = a1;
                                            whiteQueenK[z].posX = a0;

                                            turn = 'h';
                                        }

                                        else {
                                            for(int a=0; a<8; a++) {
                                                whitePawns[a].clicked = FALSE;
                                            }
                                            for(int a=0; a<8; a++) {
                                                whitePawns[a].clicked = FALSE;
                                            }
                                            boxes[j][i].clear = FALSE;
                                            turn = 'r';
                                            turnChanged = TRUE;
                                            done = TRUE;
                                        }

                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }

                                        itdid = FALSE;
                                    }
                                }
                            }

                            itdid = FALSE;
                            
                            if(whiteBishop1.posX == i*70+20 &&
                               whiteBishop1.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteBishop1.clicked = TRUE;
                                whiteBishop1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteBishop1Start == -1 || whiteBishop1Func == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop1Func = 0;
                                        whiteBishop2Func = -1;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = -1;
                                        wb1Thread = CreateThread(NULL, 0, paintWhiteBishop1, NULL, 0, NULL);
                                        whiteBishop1Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "bw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteBishop1.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteBishop1.clicked == TRUE) {
                                    whiteBishop1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    whiteBishop1.clicked = FALSE;

                                    int a1 = whiteBishop1.posY;
                                    int a0 = whiteBishop1.posX;

                                    boolean f = FALSE;

                                    whiteBishop1.failedpath = FALSE;

                                    if(i*70+20 != whiteBishop1.posX &&
                                       j*70+20 != whiteBishop1.posY) {
                                        f = moveWhiteBishop1(msg, j, i, j*70+20 - whiteBishop1.posY, i*70+20 - whiteBishop1.posX, j*70+20 - whiteBishop1.posY, i*70+20 - whiteBishop1.posX);
                                        f = whiteBishop1.failedpath;
                                    } else {
                                        f = whiteBishop1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckWhite(j, i);
                                    
                                    if(f || fff) {

                                        whiteBishop1.posY = a1;
                                        whiteBishop1.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        whiteBishop1Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;
                            
                            if(whiteBishop2.posX == i*70+20 &&
                               whiteBishop2.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteBishop2.clicked = TRUE;
                                whiteBishop2.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteBishop2Start == -1 || whiteBishop2Func == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop1Func = -1;
                                        whiteBishop2Func = 0;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = -1;
                                        wb2Thread = CreateThread(NULL, 0, paintWhiteBishop2, NULL, 0, NULL);
                                        whiteBishop2Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "bw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteBishop2.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteBishop2.clicked == TRUE) {
                                    whiteBishop2.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    whiteBishop2.clicked = FALSE;

                                    int a1 = whiteBishop2.posY;
                                    int a0 = whiteBishop2.posX;

                                    boolean f = FALSE;

                                    whiteBishop2.failedpath = FALSE;
                                    
                                    if(i*70+20 != whiteBishop2.posX &&
                                       j*70+20 != whiteBishop2.posY) {
                                        f = moveWhiteBishop2(msg, j, i, j*70+20 - whiteBishop2.posY, i*70+20 - whiteBishop2.posX, j*70+20 - whiteBishop2.posY, i*70+20 - whiteBishop2.posX);
                                        f = whiteBishop2.failedpath;
                                    } else {
                                        f = whiteBishop2.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckWhite(j, i);

                                    if(f || fff) {
                                        
                                        whiteBishop2.posY = a1;
                                        whiteBishop2.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        whiteBishop2Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;
                            
                            if(whiteRook1.posX == i*70+20 &&
                               whiteRook1.posY == j*70+20) {
                                
                                clickedOne = 'g';
                                whiteRook1.clicked = TRUE;
                                whiteRook1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteRook1Start == -1 || whiteRook1Func == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop1Func = -1;
                                        whiteBishop2Func = -1;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteRook1Func = 0;
                                        whiteRook2Func = -1;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = -1;
                                        wr1Thread = CreateThread(NULL, 0, paintWhiteRook1, NULL, 0, NULL);
                                        whiteRook1Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "rw", 2);
                            } else if(clickedOne == 'g' &&
                                      whiteRook1.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteRook1.clicked == TRUE) {
                                    whiteRook1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    whiteRook1.clicked = FALSE;

                                    int a1 = whiteRook1.posY;
                                    int a0 = whiteRook1.posX;

                                    boxes[whiteRook1.posY/70][whiteRook1.posX/70].clear = TRUE;

                                    boolean f = FALSE;

                                    whiteRook1.failedpath = FALSE;

                                    if(i*70+20 == whiteRook1.posX) {
                                        f = moveWhiteRook1(msg, j, i, j*70+20 - whiteRook1.posY, j*70+20 - whiteRook1.posY);
                                        f = whiteRook1.failedpath;
                                    } else if(j*70+20 == whiteRook1.posY) {
                                        f = moveWhiteRook1Side(msg, j, i, i*70+20 - whiteRook1.posX, i*70+20 - whiteRook1.posX);
                                        f = whiteRook1.failedpath;
                                    } else {
                                        f = whiteRook1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckWhite(j, i);

                                    if(f || fff) {

                                        whiteRook1.posY = a1;
                                        whiteRook1.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        whiteQueen.clicked = FALSE;
                                        whiteRook2.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        whiteRook1Moved = TRUE;
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        whiteRook1Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    whiteQueen.clicked = FALSE;
                                    whiteRook2.clicked = FALSE;
                                    
                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;
                            
                            if(whiteRook2.posX == i*70+20 &&
                               whiteRook2.posY == j*70+20) {
                                
                                clickedOne = 'h';
                                whiteRook2.clicked = TRUE;
                                whiteRook2.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(whiteRook2Start == -1 || whiteRook2Func == -1) {
                                        whitePawnsFunc = -1;
                                        whiteBishop1Func = -1;
                                        whiteBishop2Func = -1;
                                        whiteKnight1Func = -1;
                                        whiteKnight2Func = -1;
                                        whiteRook1Func = -1;
                                        whiteRook2Func = 0;
                                        whiteKingFunc = -1;
                                        whiteQueenFunc = -1;
                                        wr2Thread = CreateThread(NULL, 0, paintWhiteRook2, NULL, 0, NULL);
                                        whiteRook2Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "rw", 2);
                            } else if(clickedOne == 'h' &&
                                      whiteRook2.clicked == TRUE) {
                                itdid = TRUE;
                                if(whiteRook2.clicked == TRUE) {
                                    whiteRook2.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'h';
                                    whiteRook2.clicked = FALSE;

                                    int a1 = whiteRook2.posY;
                                    int a0 = whiteRook2.posX;

                                    boxes[whiteRook2.posY/70][whiteRook2.posX/70].clear = TRUE;

                                    boolean f = FALSE;

                                    whiteRook2.failedpath = FALSE;

                                    if(i*70+20 == whiteRook2.posX) {
                                        f = moveWhiteRook2(msg, j, i, j*70+20 - whiteRook2.posY, j*70+20 - whiteRook2.posY);
                                        f = whiteRook2.failedpath;
                                    } else if(j*70+20 == whiteRook2.posY) {
                                        f = moveWhiteRook2Side(msg, j, i, i*70+20 - whiteRook2.posX, i*70+20 - whiteRook2.posX);
                                        f = whiteRook2.failedpath;
                                    } else {
                                        f = whiteRook2.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckWhite(j, i);
                                    
                                    if(f || fff) {

                                        whiteRook2.posY = a1;
                                        whiteRook2.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        whiteQueen.clicked = FALSE;
                                        whiteRook1.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        whiteRook2Moved = TRUE;
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        whiteRook2Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    whiteQueen.clicked = FALSE;
                                    whiteRook1.clicked = FALSE;
                                    
                                    itdid = FALSE;
                                }
                            }

                            HBRUSH rBrush;
                            rBrush = CreateSolidBrush(RGB(0, 255, 0));
                            RECT r = {i*70+20+20, j*70+20+20-8, i*70+20+20 + 12, j*70+20+20-8 + 12};
                            for(int t=0; t<8; t++) {
                                if(turn == 'r' && whitePawns[t].posX == i*70+20 &&
                                   whitePawns[t].posY == j*70+20) {
                                    if(TRUE==done) {
                                        int l1_x1 = i*70+20+20;
                                        int l1_y1 = j*70+20 + 8;
                                        int l1_x2 = i*70+20+20 + 8;
                                        int l1_y2 = j*70+20 + 16;
                                        int l2_x1 = i*70+20+20 + 8;
                                        int l2_y1 = j*70+20 + 16;
                                        int l2_x2 = i*70+20+20 + 16;
                                        int l2_y2 = j*70+20;
                                        PAINTSTRUCT pntS;
                                        HPEN pen, oldPen;
                                        pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                        oldPen = (HPEN)SelectObject(hdc, pen);				
                                        MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                        LineTo(hdc, l1_x2, l1_y2);
                                        MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                        LineTo(hdc, l2_x2, l2_y2);
                                        SelectObject(hdc, oldPen); 
                                        DeleteObject(pen);
                                    }
                                }
                            }
                            for(int t=0; t<8; t++) {
                                if(turn == 'h' && whitePawns[t].posX == i*70+20 &&
                                   whitePawns[t].posY == j*70+20) {
                                    FillRect(hdc, &r, rBrush);
                                }
                            }
                            if(turn == 'r' && whiteKing.posX == i*70+20 &&
                               whiteKing.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteKing.posX == i*70+20 &&
                               whiteKing.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && whiteQueen.posX == i*70+20 &&
                               whiteQueen.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteQueen.posX == i*70+20 &&
                               whiteQueen.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            for(int z=0; z<8; z++) {
                                if(turn == 'r' && whiteQueenK[z].posX == i*70+20 &&
                                   whiteQueenK[z].posY == j*70+20) {
                                    if(TRUE==done) {
                                        int l1_x1 = i*70+20+20;
                                        int l1_y1 = j*70+20 + 8;
                                        int l1_x2 = i*70+20+20 + 8;
                                        int l1_y2 = j*70+20 + 16;
                                        int l2_x1 = i*70+20+20 + 8;
                                        int l2_y1 = j*70+20 + 16;
                                        int l2_x2 = i*70+20+20 + 16;
                                        int l2_y2 = j*70+20;
                                        PAINTSTRUCT pntS;
                                        HPEN pen, oldPen;
                                        pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                        oldPen = (HPEN)SelectObject(hdc, pen);				
                                        MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                        LineTo(hdc, l1_x2, l1_y2);
                                        MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                        LineTo(hdc, l2_x2, l2_y2);
                                        SelectObject(hdc, oldPen); 
                                        DeleteObject(pen);
                                    }
                                }
                                if(turn == 'h' && whiteQueenK[z].posX == i*70+20 &&
                                   whiteQueenK[z].posY == j*70+20) {
                                    FillRect(hdc, &r, rBrush);
                                }
                            }
                            if(turn == 'r' && whiteKnight1.posX == i*70+20 &&
                               whiteKnight1.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteKnight1.posX == i*70+20 &&
                               whiteKnight1.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && whiteKnight2.posX == i*70+20 &&
                               whiteKnight2.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteKnight2.posX == i*70+20 &&
                               whiteKnight2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && whiteBishop1.posX == i*70+20 &&
                               whiteBishop1.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteBishop1.posX == i*70+20 &&
                               whiteBishop1.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && whiteBishop2.posX == i*70+20 &&
                               whiteBishop2.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteBishop2.posX == i*70+20 &&
                               whiteBishop2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && whiteRook1.posX == i*70+20 &&
                               whiteRook1.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteRook1.posX == i*70+20 &&
                               whiteRook1.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && whiteRook2.posX == i*70+20 &&
                               whiteRook2.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && whiteRook2.posX == i*70+20 &&
                               whiteRook2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            DeleteObject(rBrush);
                            
                            if(!pcgame && done) {
                                getApiUnderwaterChessDotComMove2(from, to);
                            }

                            highlightPossibleMoves(j, i);

                            hdcMem = CreateCompatibleDC(hdc);
                            oldBitmap = SelectObject(hdcMem, hBitmap);

                            GetObject(hBitmap, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

                            SelectObject(hdcMem, oldBitmap);
                            DeleteDC(hdcMem); DeleteObject(hBitmap);

                            Sleep(1);
                            pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                            hdcMem = CreateCompatibleDC(hdc);
                            HBITMAP hBmp;
                            if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rookWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rookWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteRook1.posX+25+7, whiteRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rook2White,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rook2White,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteRook2.posX+25+7, whiteRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knightWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knightWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteKnight1.posX+25+7, whiteKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knight2White,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knight2White,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteKnight2.posX+25+7, whiteKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishopWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishopWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteBishop1.posX+25+7, whiteBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishop2White,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishop2White,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteBishop2.posX+25+7, whiteBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteQueen.posX+25+7, whiteQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(kingWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(kingWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteKing.posX+25+7, whiteKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            for(int o=0; o<8; o++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whitePawns[o].posX/70)+(whitePawns[o].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(pawnWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(pawnWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whitePawns[o].posX+25+7, whitePawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rookBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackRook1.posX+25+7, blackRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rook2Black,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackRook2.posX+25+7, blackRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knightBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knightBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackKnight1.posX+25+7, blackKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knight2Black,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knight2Black,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackKnight2.posX+25+7, blackKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishopBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishopBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackBishop1.posX+25+7, blackBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishop2Black,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishop2Black,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackBishop2.posX+25+7, blackBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackQueen.posX+25+7, blackQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(kingBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(kingBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackKing.posX+25+7, blackKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            for(int o=0; o<8; o++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackPawns[o].posX/70)+(blackPawns[o].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(pawnBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(pawnBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackPawns[o].posX+25+7, blackPawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            for(int m=0; m<8; m++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteQueenK[m].posX/70)+(whiteQueenK[m].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteQueenK[m].posX+25+7, whiteQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            for(int m=0; m<8; m++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackQueenK[m].posX/70)+(blackQueenK[m].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackQueenK[m].posX+25+7, blackQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            DeleteObject(pawnBlack);
                            DeleteObject(pawnWhite);
                            DeleteObject(knightBlack);
                            DeleteObject(knightWhite);
                            DeleteObject(knight2Black);
                            DeleteObject(knight2White);
                            DeleteObject(rookBlack);
                            DeleteObject(rookWhite);
                            DeleteObject(rook2Black);
                            DeleteObject(rook2White);
                            DeleteObject(bishopBlack);
                            DeleteObject(bishopWhite);
                            DeleteObject(bishop2Black);
                            DeleteObject(bishop2White);
                            DeleteObject(queenBlack);
                            DeleteObject(queenWhite);
                            DeleteObject(kingBlack);
                            DeleteObject(kingWhite);

                            if(done) {

                                hdcMem = CreateCompatibleDC(hdc);
                                oldBitmap = SelectObject(hdcMem, hBitmap);

                                GetObject(hBitmap, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

                                SelectObject(hdcMem, oldBitmap);
                                DeleteDC(hdcMem); DeleteObject(hBitmap);

                                DrawChessBoard();

                                Sleep(1);
                                pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                                hdcMem = CreateCompatibleDC(hdc);
                                HBITMAP hBmp;
                                if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(rookWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(rookWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteRook1.posX+25+7, whiteRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(rook2White,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(rook2White,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteRook2.posX+25+7, whiteRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(knightWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(knightWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteKnight1.posX+25+7, whiteKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(knight2White,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(knight2White,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteKnight2.posX+25+7, whiteKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(bishopWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishopWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteBishop1.posX+25+7, whiteBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(bishop2White,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishop2White,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteBishop2.posX+25+7, whiteBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteQueen.posX+25+7, whiteQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(kingWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(kingWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteKing.posX+25+7, whiteKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                for(int o=0; o<8; o++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((whitePawns[o].posX/70)+(whitePawns[o].posY/70)) % 2 == 0)
                                        hBmp = ReplaceColor(pawnWhite,0x110000,0xffffff,hdcMem);
                                    else
                                        hBmp = ReplaceColor(pawnWhite,0x110000,0x000000,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, whitePawns[o].posX+25+7, whitePawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(rookBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackRook1.posX+25+7, blackRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(rook2Black,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackRook2.posX+25+7, blackRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(knightBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(knightBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackKnight1.posX+25+7, blackKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(knight2Black,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(knight2Black,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackKnight2.posX+25+7, blackKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(bishopBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishopBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackBishop1.posX+25+7, blackBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(bishop2Black,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishop2Black,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackBishop2.posX+25+7, blackBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackQueen.posX+25+7, blackQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(kingBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(kingBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackKing.posX+25+7, blackKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                for(int o=0; o<8; o++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((blackPawns[o].posX/70)+(blackPawns[o].posY/70)) % 2 == 0)
                                        hBmp = ReplaceColor(pawnBlack,0x110000,0xffffff,hdcMem);
                                    else
                                        hBmp = ReplaceColor(pawnBlack,0x110000,0x000000,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, blackPawns[o].posX+25+7, blackPawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                for(int m=0; m<8; m++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((whiteQueenK[m].posX/70)+(whiteQueenK[m].posY/70)) % 2 == 0)
                                        hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                                    else
                                        hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, whiteQueenK[m].posX+25+7, whiteQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                for(int m=0; m<8; m++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((blackQueenK[m].posX/70)+(blackQueenK[m].posY/70)) % 2 == 0)
                                        hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                                    else
                                        hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, blackQueenK[m].posX+25+7, blackQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                DeleteObject(pawnBlack);
                                DeleteObject(pawnWhite);
                                DeleteObject(knightBlack);
                                DeleteObject(knightWhite);
                                DeleteObject(knight2Black);
                                DeleteObject(knight2White);
                                DeleteObject(rookBlack);
                                DeleteObject(rookWhite);
                                DeleteObject(rook2Black);
                                DeleteObject(rook2White);
                                DeleteObject(bishopBlack);
                                DeleteObject(bishopWhite);
                                DeleteObject(bishop2Black);
                                DeleteObject(bishop2White);
                                DeleteObject(queenBlack);
                                DeleteObject(queenWhite);
                                DeleteObject(kingBlack);
                                DeleteObject(kingWhite);

                                Sleep(1);
                                pawnBlack_s = (HBITMAP)LoadImage(hInst, "pawnblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                pawnWhite_s = (HBITMAP)LoadImage(hInst, "pawnwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knightBlack_s = (HBITMAP)LoadImage(hInst, "knightblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knightWhite_s = (HBITMAP)LoadImage(hInst, "knightwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knight2Black_s = (HBITMAP)LoadImage(hInst, "knightblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                knight2White_s = (HBITMAP)LoadImage(hInst, "knightwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rookBlack_s = (HBITMAP)LoadImage(hInst, "rookblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rookWhite_s = (HBITMAP)LoadImage(hInst, "rookwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rook2Black_s = (HBITMAP)LoadImage(hInst, "rookblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                rook2White_s = (HBITMAP)LoadImage(hInst, "rookwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishopBlack_s = (HBITMAP)LoadImage(hInst, "bishopblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishopWhite_s = (HBITMAP)LoadImage(hInst, "bishopwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishop2Black_s = (HBITMAP)LoadImage(hInst, "bishopblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                bishop2White_s = (HBITMAP)LoadImage(hInst, "bishopwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                queenBlack_s = (HBITMAP)LoadImage(hInst, "queenblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                queenWhite_s = (HBITMAP)LoadImage(hInst, "queenwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                kingBlack_s = (HBITMAP)LoadImage(hInst, "kingblack_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                Sleep(1);
                                kingWhite_s = (HBITMAP)LoadImage(hInst, "kingwhite_s.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                                _y_ = 20;

                                HBRUSH yellow_brush = CreateSolidBrush(RGB(255,255,0));
                                RECT rrect = {635+0, 17, 910, 740};
                                FillRect(hdc, &rrect, yellow_brush);
                                DeleteObject(yellow_brush);

                                if(whiteRook1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rookWhite_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteRook1.from != NULL && whiteRook1.to != NULL) {
                                        if(strlen(whiteRook1.from) >= 2 && strlen(whiteRook1.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteRook1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteRook2.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rook2White_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteRook2.from != NULL && whiteRook2.to != NULL) {
                                        if(strlen(whiteRook2.from) >= 2 && strlen(whiteRook2.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteRook2.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteKnight1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knightWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteKnight1.from != NULL && whiteKnight1.to != NULL) {
                                        if(strlen(whiteKnight1.from) >= 2 && strlen(whiteKnight1.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteKnight1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteKnight2.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knight2White_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteKnight2.from != NULL && whiteKnight2.to != NULL) {
                                        if(strlen(whiteKnight2.from) >= 2 && strlen(whiteKnight2.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteKnight2.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteBishop1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishopWhite_s,0x4cb122,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteBishop1.from != NULL && whiteBishop1.to != NULL) {
                                        if(strlen(whiteBishop1.from) >= 2 && strlen(whiteBishop1.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteBishop1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteBishop2.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishop2White_s,0x4cb122,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteBishop2.from != NULL && whiteBishop2.to != NULL) {
                                        if(strlen(whiteBishop2.from) >= 2 && strlen(whiteBishop2.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteBishop2.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteQueen.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(whiteQueen.from != NULL && whiteQueen.to != NULL) {
                                        if(strlen(whiteQueen.from) >= 2 && strlen(whiteQueen.to) >= 2) {
                                            TextOut(hdc,
                                                    615+50,
                                                    _y_,
                                                    whiteQueen.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(whiteKing.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(kingWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                for(int o=0; o<8; o++) {
                                    if(whitePawns[o].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(pawnWhite_s,0x000000,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(whitePawns[o].from != NULL && whitePawns[o].to != NULL) {
                                            if(strlen(whitePawns[o].from) >= 2 && strlen(whitePawns[o].to) >= 2) {
                                                TextOut(hdc,
                                                        615+50,
                                                        _y_,
                                                        whitePawns[o].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                for(int m=0; m<8; m++) {
                                    if(whiteQueenK[m].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 585+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(whiteQueenK[m].from != NULL && whiteQueenK[m].to != NULL) {
                                            if(strlen(whiteQueenK[m].from) >= 2 && strlen(whiteQueenK[m].to) >= 2) {
                                                TextOut(hdc,
                                                        615+50,
                                                        _y_,
                                                        whiteQueenK[m].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                _y_ = 20;

                                if(blackRook1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rookBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackRook1.from != NULL && blackRook1.to != NULL) {
                                        if(strlen(blackRook1.from) >= 2 && strlen(blackRook1.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackRook1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackRook2.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rook2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackRook2.from != NULL && blackRook2.to != NULL) {
                                        if(strlen(blackRook2.from) >= 2 && strlen(blackRook2.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackRook2.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackKnight1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knightBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackKnight1.from != NULL && blackKnight1.to != NULL) {
                                        if(strlen(blackKnight1.from) >= 2 && strlen(blackKnight1.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackKnight1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackKnight2.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knight2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackKnight2.from != NULL && blackKnight2.to != NULL) {
                                        if(strlen(blackKnight2.from) >= 2 && strlen(blackKnight2.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackKnight2.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackBishop1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishopBlack_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackBishop1.from != NULL && blackBishop1.to != NULL) {
                                        if(strlen(blackBishop1.from) >= 2 && strlen(blackBishop1.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackBishop1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackBishop2.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishop2Black_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackBishop2.from != NULL && blackBishop2.to != NULL) {
                                        if(strlen(blackBishop2.from) >= 2 && strlen(blackBishop2.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackBishop2.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackQueen.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(blackQueen.from != NULL && blackQueen.to != NULL) {
                                        if(strlen(blackQueen.from) >= 2 && strlen(blackQueen.to) >= 2) {
                                            TextOut(hdc,
                                                    690+50,
                                                    _y_,
                                                    blackQueen.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(blackKing.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(kingBlack_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                for(int o=0; o<8; o++) {
                                    if(blackPawns[o].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(pawnBlack_s,0xff0000,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(blackPawns[o].from != NULL && blackPawns[o].to != NULL) {
                                            if(strlen(blackPawns[o].from) >= 2 && strlen(blackPawns[o].to) >= 2) {
                                                TextOut(hdc,
                                                        690+50,
                                                        _y_,
                                                        blackPawns[o].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                for(int m=0; m<8; m++) {
                                    if(blackQueenK[m].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 660+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(blackQueenK[m].from != NULL && blackQueenK[m].to != NULL) {
                                            if(strlen(blackQueenK[m].from) >= 2 && strlen(blackQueenK[m].to) >= 2) {
                                                TextOut(hdc,
                                                        690+50,
                                                        _y_,
                                                        blackQueenK[m].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                DeleteObject(pawnBlack_s);
                                DeleteObject(pawnWhite_s);
                                DeleteObject(knightBlack_s);
                                DeleteObject(knightWhite_s);
                                DeleteObject(knight2Black_s);
                                DeleteObject(knight2White_s);
                                DeleteObject(rookBlack_s);
                                DeleteObject(rookWhite_s);
                                DeleteObject(rook2Black_s);
                                DeleteObject(rook2White_s);
                                DeleteObject(bishopBlack_s);
                                DeleteObject(bishopWhite_s);
                                DeleteObject(bishop2Black_s);
                                DeleteObject(bishop2White_s);
                                DeleteObject(queenBlack_s);
                                DeleteObject(queenWhite_s);
                                DeleteObject(kingBlack_s);
                                DeleteObject(kingWhite_s);

                                if(pcgame) {
                                    if(turn == 'r') {
                                        if(from != NULL && to != NULL) {
                                            SetWindowText(hwnd_timer, "thinking ...");
                                            thread_1 = CreateThread(NULL, 0, callApi, NULL, 0, NULL);
                                        }
                                        break;
                                    }
                                }
                            }
                        } else if(turn == 'r') {

                            for(int k=0; k<8; k++) {

                                if(blackPawns[k].posX == i*70+20 &&
                                   blackPawns[k].posY == j*70+20) {

                                    clickedOne = 'r';
                                    blackPawns[k].clicked = TRUE;
                                    blackPawns[k].from = map(j, i);
                                    from = map(j, i);
                                    turn = 'r';

                                    if(msg == WM_LBUTTONDOWN) {
                                        if(blackPawnsStart == -1 || blackPawnsFunc == -1) {
                                            blackPawnsIndex = k;
                                            blackBishop2Func = -1;
                                            blackBishop1Func = -1;
                                            blackKnight1Func = -1;
                                            blackKnight2Func = -1;
                                            blackPawnsFunc = 0;
                                            blackRook1Func = -1;
                                            blackRook2Func = -1;
                                            blackKingFunc = -1;
                                            blackQueenFunc = -1;
                                            bpThread = CreateThread(NULL, 0, paintBlackPawn, NULL, 0, NULL);
                                            blackPawnsStart = 0;
                                        }
                                    }

                                    strncpy(chosenPiece, "pr", 2);

                                    for(int l=0; l<8; l++) {
                                        whitePawns[l].clicked = FALSE;
                                    }

                                    for(int l=0; l<8; l++) {
                                        if(l != k) {
                                            blackPawns[l].clicked = FALSE;
                                        }
                                    }
                                } else {
                                    if(blackPawns[k].clicked == TRUE) {
                                        blackPawns[k].to = map(j, i);
                                        to = map(j, i);
                                    }
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(clickedOne == 'r' &&
                                       blackPawns[k].clicked == TRUE &&
                                       blackPawns[k].firstTimeMove == TRUE) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

//                                        for(int m=0; m<8; m++) {
//                                            if(blackPawns[m].posY == blackPawns[k].posY + 70 &&
//                                               (blackPawns[m].posX == blackPawns[k].posX + 70 || blackPawns[m].posX == blackPawns[k].posX - 70)) {
//                                                ff = TRUE;
//                                            }
//                                            if(blackPawns[m].posY == blackPawns[k].posY + 70 &&
//                                               blackPawns[m].posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackKnight1.posY == blackPawns[k].posY + 70 &&
//                                               blackKnight1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackKnight2.posY == blackPawns[k].posY + 70 &&
//                                               blackKnight2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackBishop1.posY == blackPawns[k].posY + 70 &&
//                                               blackBishop1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackBishop2.posY == blackPawns[k].posY + 70 &&
//                                               blackBishop2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackRook1.posY == blackPawns[k].posY + 70 &&
//                                               blackRook1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackRook2.posY == blackPawns[k].posY + 70 &&
//                                               blackRook2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackKnight1.posY == blackPawns[k].posY + 70 &&
//                                               blackKnight1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackKnight2.posY == blackPawns[k].posY + 70 &&
//                                               blackKnight2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackBishop1.posY == blackPawns[k].posY + 70 &&
//                                               blackBishop1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackBishop2.posY == blackPawns[k].posY + 70 &&
//                                               blackBishop2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackRook1.posY == blackPawns[k].posY + 70 &&
//                                               blackRook1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(blackRook2.posY == blackPawns[k].posY + 70 &&
//                                               blackRook2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                        }

                                        if(!ff &&
                                           j*70+20 == blackPawns[k].posY + 70 &&
                                          (i*70+20 == blackPawns[k].posX - 70 ||
                                           i*70+20 == blackPawns[k].posX + 70)) {

                                            turn = 'h';

                                            boolean ate = FALSE;

                                            int a0 = blackPawns[k].posX;
                                            int a1 = blackPawns[k].posY;

                                            boxes[j][i].clear = FALSE;
                                            boxes[blackPawns[k].posY/70][blackPawns[k].posX/70].clear = TRUE;
                                            blackPawns[k].posY = j*70+20;
                                            blackPawns[k].posX = i*70+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if((whitePawns[l].posX == blackPawns[k].posX ||
                                                    whitePawns[l].posX == blackPawns[k].posX) &&
                                                    whitePawns[l].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(whiteQueenK[z].posX == i*70+20 &&
                                                   whiteQueenK[z].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(whiteQueen.posX == i*70+20 &&
                                               whiteQueen.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteBishop1.posX == i*70+20 &&
                                               whiteBishop1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteBishop2.posX == i*70+20 &&
                                               whiteBishop2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteKnight1.posX == i*70+20 &&
                                               whiteKnight1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteKnight2.posX == i*70+20 &&
                                               whiteKnight2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteRook1.posX == i*70+20 &&
                                               whiteRook1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteRook2.posX == i*70+20 &&
                                               whiteRook2.posY == j*70+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(whitePawns[u].posX == blackPawns[k].posX &&
                                                   whitePawns[u].posY == blackPawns[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff && fff) {

                                                blackPawns[k].posX = a0;
                                                blackPawns[k].posY = a1;

                                                turn = 'r';
                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackPawns[k].posX ||
                                                        whitePawns[l].posX == blackPawns[k].posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackPawns[k].posX &&
                                                       whitePawns[u].posY == blackPawns[k].posY) {
                                                        whitePawns[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    blackPawns[k].firstTimeMove = FALSE;
                                                    blackPawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                    blackPawnsFunc = -1;
                                                } else {
                                                    blackPawns[k].posX = a0;
                                                    blackPawns[k].posY = a1;

                                                    turn = 'r';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                                j*70+20 == blackPawns[k].posY + 70 &&
                                                i*70+20 == blackPawns[k].posX) {

                                            turn = 'h';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(whitePawns[s].posX == blackPawns[k].posX &&
                                                   whitePawns[s].posY - 70 == blackPawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == blackPawns[k].posX &&
                                                   blackPawns[s].posY - 70 == blackPawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = blackPawns[k].posX;
                                                int a1 = blackPawns[k].posY;

                                                boxes[j][i].clear = FALSE;

                                                boxes[blackPawns[k].posY/70][blackPawns[k].posX/70].clear = TRUE;
                                                blackPawns[k].posY = j*70+20;

                                                boolean ffff = checkCheckBlack(j, i);

                                                if(ffff) {
                                                    blackPawns[k].posX = a0;
                                                    blackPawns[k].posY = a1;

                                                    turn = 'r';
                                                } else {
                                                    blackPawnsFunc = -1;

                                                    blackPawns[k].firstTimeMove = FALSE;

                                                    blackPawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            } else {
                                                turn = 'r';
                                            }
                                        }

                                        else if(!fail &&
                                                j*70+20 == blackPawns[k].posY + 140 &&
                                                i*70+20 == blackPawns[k].posX) {

                                            turn = 'h';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(whitePawns[s].posX == blackPawns[k].posX &&
                                                   whitePawns[s].posY - 70 == blackPawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == blackPawns[k].posX &&
                                                   blackPawns[s].posY - 70 == blackPawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = blackPawns[k].posX;
                                                int a1 = blackPawns[k].posY;

                                                boxes[j][i].clear = FALSE;

                                                boxes[blackPawns[k].posY/70][blackPawns[k].posX/70].clear = TRUE;
                                                blackPawns[k].posY = j*70+20;

                                                boolean ffff = checkCheckBlack(j, i);

                                                if(ffff) {
                                                    blackPawns[k].posX = a0;
                                                    blackPawns[k].posY = a1;

                                                    turn = 'r';
                                                } else {
                                                    blackPawnsFunc = -1;

                                                    blackPawns[k].firstTimeMove = FALSE;

                                                    blackPawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            }
                                        }

                                    } else if(clickedOne == 'r' &&
                                              blackPawns[k].clicked) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

//                                        for(int m=0; m<8; m++) {
//                                            if(blackPawns[m].posY == blackPawns[k].posY + 70 &&
//                                               (blackPawns[m].posX == blackPawns[k].posX + 70 || blackPawns[m].posX == blackPawns[k].posX - 70)) {
//                                                ff = TRUE;
//                                            }
//                                            if(whitePawns[m].posY == blackPawns[k].posY + 70 &&
//                                               whitePawns[m].posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight1.posY == blackPawns[k].posY + 70 &&
//                                               whiteKnight1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight2.posY == blackPawns[k].posY + 70 &&
//                                               whiteKnight2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop1.posY == blackPawns[k].posY + 70 &&
//                                               whiteBishop1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop2.posY == blackPawns[k].posY + 70 &&
//                                               whiteBishop2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook1.posY == blackPawns[k].posY + 70 &&
//                                               whiteRook1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook2.posY == blackPawns[k].posY + 70 &&
//                                               whiteRook2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight1.posY == blackPawns[k].posY + 70 &&
//                                               whiteKnight1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteKnight2.posY == blackPawns[k].posY + 70 &&
//                                               whiteKnight2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop1.posY == blackPawns[k].posY + 70 &&
//                                               whiteBishop1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteBishop2.posY == blackPawns[k].posY + 70 &&
//                                               whiteBishop2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook1.posY == blackPawns[k].posY + 70 &&
//                                               whiteRook1.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                            if(whiteRook2.posY == blackPawns[k].posY + 70 &&
//                                               whiteRook2.posX == blackPawns[k].posX) {
//                                                fail = TRUE;
//                                            }
//                                        }

                                        if(!ff &&
                                           j*70+20 == blackPawns[k].posY + 70 &&
                                          (i*70+20 == blackPawns[k].posX - 70 ||
                                           i*70+20 == blackPawns[k].posX + 70)) {

                                            turn = 'h';

                                            boolean ate = FALSE;

                                            int a0 = blackPawns[k].posX;
                                            int a1 = blackPawns[k].posY;

                                            boxes[blackPawns[k].posY/70][blackPawns[k].posX/70].clear = TRUE;
                                            boxes[j][i].clear = FALSE;
                                            blackPawns[k].posY = j*70+20;
                                            blackPawns[k].posX = i*70+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if((whitePawns[l].posX == blackPawns[k].posX ||
                                                    whitePawns[l].posX == blackPawns[k].posX) &&
                                                    whitePawns[l].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(whiteQueenK[z].posX == i*70+20 &&
                                                   whiteQueenK[z].posY == j*70+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(whiteQueen.posX == i*70+20 &&
                                               whiteQueen.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteBishop1.posX == i*70+20 &&
                                               whiteBishop1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteBishop2.posX == i*70+20 &&
                                               whiteBishop2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteKnight1.posX == i*70+20 &&
                                               whiteKnight1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteKnight2.posX == i*70+20 &&
                                               whiteKnight2.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteRook1.posX == i*70+20 &&
                                               whiteRook1.posY == j*70+20) {
                                                fff = FALSE;
                                            }
                                            if(whiteRook2.posX == i*70+20 &&
                                               whiteRook2.posY == j*70+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(whitePawns[u].posX == blackPawns[k].posX &&
                                                   whitePawns[u].posY == blackPawns[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff && fff) {

                                                blackPawns[k].posX = a0;
                                                blackPawns[k].posY = a1;

                                                turn = 'r';
                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if(whitePawns[l].posX == i*70+20 &&
                                                       whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackPawns[k].posX &&
                                                       whitePawns[u].posY == blackPawns[k].posY) {
                                                        whitePawns[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    blackPawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                    blackPawnsFunc = -1;
                                                } else {

                                                    blackPawns[k].posX = a0;
                                                    blackPawns[k].posY = a1;

                                                    turn = 'r';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                           j*70+20 == blackPawns[k].posY + 70 &&
                                           i*70+20 == blackPawns[k].posX) {

                                            turn = 'h';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(whitePawns[s].posX == blackPawns[k].posX &&
                                                   whitePawns[s].posY - 70 == blackPawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(blackPawns[s].posX == blackPawns[k].posX &&
                                                   blackPawns[s].posY - 70 == blackPawns[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = blackPawns[k].posX;
                                                int a1 = blackPawns[k].posY;

                                                boxes[blackPawns[k].posY/70][blackPawns[k].posX/70].clear = TRUE;
                                                boxes[j][i].clear = FALSE;

                                                blackPawns[k].posY = j*70+20;

                                                boolean ffff = checkCheckBlack(j, i);

                                                if(ffff) {

                                                    blackPawns[k].posX = a0;
                                                    blackPawns[k].posY = a1;

                                                    turn = 'r';
                                                } else {

                                                    blackPawns[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                    blackPawnsFunc = -1;
                                                }
                                            } else {
                                                turn = 'r';
                                            }
                                        }
                                    }
                                }
                            }

                            boolean itdid = FALSE;

                            if(blackKnight1.posX == i*70+20 &&
                               blackKnight1.posY == j*70+20) {

                                clickedOne = 'r';
                                blackKnight1.clicked = TRUE;
                                blackKnight1.from = map(j, i);
                                from = map(j, i);
                                turn = 'r';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackKnight1Start == -1 || blackKnight1Func == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop2Func = -1;
                                        blackBishop1Func = -1;
                                        blackKnight2Func = -1;
                                        blackKnight1Func = 0;
                                        blackRook1Func = -1;
                                        blackRook2Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = -1;
                                        bk1Thread = CreateThread(NULL, 0, paintBlackKnight1, NULL, 0, NULL);
                                        blackKnight1Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "kr", 2);
                            } else if(clickedOne == 'r' &&
                                      blackKnight1.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackKnight1.clicked == TRUE) {
                                    blackKnight1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;

                                    clickedOne = 'r';

                                    blackKnight1.clicked = FALSE;

                                    if(j*70+20 == blackKnight1.posY - 140 &&
                                       i*70+20 == blackKnight1.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                                turn = 'r';

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY - 140 &&
                                              i*70+20 == blackKnight1.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY - 70 &&
                                              i*70+20 == blackKnight1.posX - 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY + 70 &&
                                              i*70+20 == blackKnight1.posX - 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        boolean fff = checkCheckBlack(j, i);

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'g';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY + 140 &&
                                              i*70+20 == blackKnight1.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY + 140 &&
                                              i*70+20 == blackKnight1.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY - 70 &&
                                              i*70+20 == blackKnight1.posX + 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight1.posY + 70 &&
                                              i*70+20 == blackKnight1.posX + 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight1.posY;
                                            int a0 = blackKnight1.posX;

                                            blackKnight1.posX = i*70+20;
                                            blackKnight1.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight1.posY = a1;
                                                blackKnight1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight1Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    }
                                }
                            }

                            itdid = FALSE;

                            if(blackKnight2.posX == i*70+20 &&
                               blackKnight2.posY == j*70+20) {

                                clickedOne = 'r';
                                blackKnight2.clicked = TRUE;
                                blackKnight2.from = map(j, i);
                                from = map(j, i);
                                turn = 'r';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackKnight2Start == -1 || blackKnight2Func == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop2Func = -1;
                                        blackBishop1Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = 0;
                                        blackRook1Func = -1;
                                        blackRook2Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = -1;
                                        bk2Thread = CreateThread(NULL, 0, paintBlackKnight2, NULL, 0, NULL);
                                        blackKnight2Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "kr", 2);
                            } else if(clickedOne == 'r' &&
                                      blackKnight2.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackKnight2.clicked == TRUE) {
                                    blackKnight2.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;

                                    clickedOne = 'r';

                                    blackKnight2.clicked = FALSE;

                                    if(j*70+20 == blackKnight2.posY - 140 &&
                                       i*70+20 == blackKnight2.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY - 140 &&
                                              i*70+20 == blackKnight2.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY - 70 &&
                                              i*70+20 == blackKnight2.posX - 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY + 70 &&
                                              i*70+20 == blackKnight2.posX - 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'g';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY + 140 &&
                                              i*70+20 == blackKnight2.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY + 140 &&
                                              i*70+20 == blackKnight2.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY - 70 &&
                                              i*70+20 == blackKnight2.posX + 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKnight2.posY + 70 &&
                                              i*70+20 == blackKnight2.posX + 140) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKing.posX == i*70+20 &&
                                           blackKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(whiteKing.posX == i*70+20 &&
                                           whiteKing.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKnight2.posY;
                                            int a0 = blackKnight2.posX;

                                            blackKnight2.posX = i*70+20;
                                            blackKnight2.posY = j*70+20;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKnight2.posY = a1;
                                                blackKnight2.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(whitePawns[t].posX == i*70+20 &&
                                                       whitePawns[t].posY == j*70+20) {
                                                        whitePawns[t].posX = 1300;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                                blackKnight2Func = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    }
                                }
                            }

                            itdid = FALSE;

                            if(blackKing.posX == i*70+20 &&
                               blackKing.posY == j*70+20) {

                                clickedOne = 'r';
                                blackKing.clicked = TRUE;
                                turn = 'r';
                                from = map(j, i);
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackKingStart == -1 || blackKingFunc == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop1Func = -1;
                                        blackBishop2Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = -1;
                                        blackRook1Func = -1;
                                        blackRook2Func = -1;
                                        blackKingFunc = 0;
                                        blackQueenFunc = -1;
                                        bkThread = CreateThread(NULL, 0, paintBlackKing, NULL, 0, NULL);
                                        blackKingStart = 0;
                                    }
                                }
                                strncpy(chosenPiece, "cr", 2);
                            } else if(clickedOne == 'r' &&
                                      blackKing.clicked == TRUE) {
                                itdid = TRUE;
                                to = map(j, i);
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;

                                    clickedOne = 'r';

                                    blackKing.clicked = FALSE;

                                    if(j*70+20 == blackKing.posY &&
                                       i*70+20 == blackKing.posX - 140) {
                                        if(blackRook1.posY == 0 &&
                                           blackRook1.posX == 0) {
                                            if(blackKing.posY == 0 &&
                                               blackKing.posX == 280) {
                                                boolean isthere = FALSE;
                                                if(whiteRook1.posX == 210 &&
                                                   whiteRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook1.posX == 140 &&
                                                   whiteRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook1.posX == 70 &&
                                                   whiteRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 210 &&
                                                   whiteRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 140 &&
                                                   whiteRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 70 &&
                                                   whiteRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 210 &&
                                                   blackRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 140 &&
                                                   blackRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 70 &&
                                                   blackRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 210 &&
                                                   blackRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 140 &&
                                                   blackRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 70 &&
                                                   blackRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 210 &&
                                                   whiteBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 140 &&
                                                   whiteBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 70 &&
                                                   whiteBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 210 &&
                                                   whiteBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 140 &&
                                                   whiteBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 70 &&
                                                   whiteBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 210 &&
                                                   blackBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 140 &&
                                                   blackBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 70 &&
                                                   blackBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 210 &&
                                                   blackBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 140 &&
                                                   blackBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 70 &&
                                                   blackBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 210 &&
                                                   whiteKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 140 &&
                                                   whiteKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 70 &&
                                                   whiteKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 210 &&
                                                   whiteKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 140 &&
                                                   whiteKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 70 &&
                                                   whiteKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 210 &&
                                                   blackKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 140 &&
                                                   blackKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 70 &&
                                                   blackKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 210 &&
                                                   blackKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 140 &&
                                                   blackKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 70 &&
                                                   blackKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 210 &&
                                                   whiteQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 140 &&
                                                   whiteQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 70 &&
                                                   whiteQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 210 &&
                                                   blackQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 140 &&
                                                   blackQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 70 &&
                                                   blackQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !blackKingMoved && !blackRook1Moved) {
                                                    blackKing.posX -= 140;
                                                    blackRook1.posX += 210;
                                                    blackKingMoved = TRUE;
                                                    blackRook1Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'h';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*70+20 == blackKing.posY &&
                                       i*70+20 == blackKing.posX + 140) {
                                        if(blackRook2.posY == 0 &&
                                           blackRook2.posX == 490) {
                                            if(blackKing.posY == 0 &&
                                               blackKing.posX == 280) {
                                                boolean isthere = FALSE;
                                                if(whiteRook1.posX == 350 &&
                                                   whiteRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook1.posX == 420 &&
                                                   whiteRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 350 &&
                                                   whiteRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteRook2.posX == 420 &&
                                                   whiteRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 350 &&
                                                   blackRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook1.posX == 420 &&
                                                   blackRook1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 350 &&
                                                   blackRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackRook2.posX == 420 &&
                                                   blackRook2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 350 &&
                                                   whiteBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop1.posX == 420 &&
                                                   whiteBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 350 &&
                                                   whiteBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteBishop2.posX == 420 &&
                                                   whiteBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 350 &&
                                                   blackBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop1.posX == 420 &&
                                                   blackBishop1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 350 &&
                                                   blackBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackBishop2.posX == 420 &&
                                                   blackBishop2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 350 &&
                                                   whiteKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight1.posX == 420 &&
                                                   whiteKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 350 &&
                                                   whiteKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteKnight2.posX == 420 &&
                                                   whiteKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 350 &&
                                                   blackKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight1.posX == 420 &&
                                                   blackKnight1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 350 &&
                                                   blackKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackKnight2.posX == 420 &&
                                                   blackKnight2.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 350 &&
                                                   whiteQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(whiteQueen.posX == 420 &&
                                                   whiteQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 350 &&
                                                   blackQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(blackQueen.posX == 420 &&
                                                   blackQueen.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !blackKingMoved && !blackRook2Moved) {
                                                    blackKing.posX += 140;
                                                    blackRook2.posX -= 140;
                                                    blackKingMoved = TRUE;
                                                    blackRook2Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'h';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*70+20 == blackKing.posY - 70 &&
                                       i*70+20 == blackKing.posX) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posY -= 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY - 70 &&
                                              i*70+20 == blackKing.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posY -= 70;
                                            blackKing.posX += 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY &&
                                              i*70+20 == blackKing.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posX += 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY + 70 &&
                                              i*70+20 == blackKing.posX + 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posX += 70;
                                            blackKing.posY += 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY + 70 &&
                                              i*70+20 == blackKing.posX) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posY += 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY + 70 &&
                                              i*70+20 == blackKing.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posX -= 70;
                                            blackKing.posY += 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY &&
                                              i*70+20 == blackKing.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posX -= 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*70+20 == blackKing.posY - 70 &&
                                              i*70+20 == blackKing.posX - 70) {

                                        for(int t=0; t<8; t++) {
                                            if(blackPawns[t].posX == i*70+20 &&
                                               blackPawns[t].posY == j*70+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(blackQueen.posX == i*70+20 &&
                                           blackQueen.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop1.posX == i*70+20 &&
                                           blackBishop1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackBishop2.posX == i*70+20 &&
                                           blackBishop2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight1.posX == i*70+20 &&
                                           blackKnight1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackKnight2.posX == i*70+20 &&
                                           blackKnight2.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook1.posX == i*70+20 &&
                                           blackRook1.posY == j*70+20) {
                                            failed = TRUE;
                                        }
                                        if(blackRook2.posX == i*70+20 &&
                                           blackRook2.posY == j*70+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = blackKing.posY;
                                            int a0 = blackKing.posX;

                                            blackKing.posX -= 70;
                                            blackKing.posY -= 70;

                                            boolean ffff = checkCheckBlack(j, i);

                                            if(ffff) {

                                                blackKing.posY = a1;
                                                blackKing.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((whitePawns[l].posX == blackKing.posX ||
                                                        whitePawns[l].posX == blackKing.posX) &&
                                                        whitePawns[l].posY == j*70+20) {
                                                        whitePawns[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(whiteQueen.posX == i*70+20 &&
                                                   whiteQueen.posY == j*70+20) {
                                                    whiteQueen.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(whiteQueenK[z].posX == i*70+20 &&
                                                       whiteQueenK[z].posY == j*70+20) {
                                                        whiteQueenK[z].posX = 1300;
                                                    }
                                                }
                                                if(whiteBishop1.posX == i*70+20 &&
                                                   whiteBishop1.posY == j*70+20) {
                                                    whiteBishop1.posX = 1300;
                                                }
                                                if(whiteBishop2.posX == i*70+20 &&
                                                   whiteBishop2.posY == j*70+20) {
                                                    whiteBishop2.posX = 1300;
                                                }
                                                if(whiteKnight1.posX == i*70+20 &&
                                                   whiteKnight1.posY == j*70+20) {
                                                    whiteKnight1.posX = 1300;
                                                }
                                                if(whiteKnight2.posX == i*70+20 &&
                                                   whiteKnight2.posY == j*70+20) {
                                                    whiteKnight2.posX = 1300;
                                                }
                                                if(whiteRook1.posX == i*70+20 &&
                                                   whiteRook1.posY == j*70+20) {
                                                    whiteRook1.posX = 1300;
                                                }
                                                if(whiteRook2.posX == i*70+20 &&
                                                   whiteRook2.posY == j*70+20) {
                                                    whiteRook2.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(whitePawns[u].posX == blackKing.posX &&
                                                       whitePawns[u].posY == blackKing.posY - 70) {
                                                        whitePawns[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                blackKingMoved = TRUE;
                                                done = TRUE;
                                                blackKingFunc = -1;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    }
                                }
                            }

                            boolean changeii = FALSE;

                            for(int z=0; z<8; z++) {
                                if(blackPawns[z].posY == 490+20) {
                                    strncpy(chosenPiece, "qr", 2);
                                    changeii = TRUE;
                                    int x = blackPawns[z].posX;
                                    int y = blackPawns[z].posY;
                                    blackQueenK[z].posX = x;
                                    blackQueenK[z].posY = y;
                                    blackQueenK[z].from = map(j, i);
                                    blackQueenK[z].to = map(j, i);
                                    from = map(j, i);
                                    to = map(j, i);
                                    
                                    blackPawns[z].posX = 1300;
                                    blackPawns[z].posY = -1000;

                                    turn = 'h';
                                }
                            }

                            itdid = FALSE;

                            if(blackQueen.posX == i*70+20 &&
                               blackQueen.posY == j*70+20) {

                                clickedOne = 'r';
                                blackQueen.clicked = TRUE;
                                blackQueen.from = map(j, i);
                                from = map(j, i);
                                turn = 'r';
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackQueenStart == -1 || blackQueenFunc == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop1Func = -1;
                                        blackBishop2Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = -1;
                                        blackRook1Func = -1;
                                        blackRook2Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = 0;
                                        bqThread = CreateThread(NULL, 0, paintBlackQueen, NULL, 0, NULL);
                                        blackQueenStart = 0;
                                    }
                                }
                                strncpy(chosenPiece, "qr", 2);
                            } else if(clickedOne == 'r' &&
                                      blackQueen.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackQueen.clicked == TRUE) {
                                    blackQueen.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    blackQueen.clicked = FALSE;

                                    int a1 = blackQueen.posY;
                                    int a0 = blackQueen.posX;

                                    boxes[blackQueen.posY/70][blackQueen.posX/70].clear = TRUE;

                                    boolean f = FALSE;

                                    blackQueen.failedpath = FALSE;

                                    if(i*70+20 == blackQueen.posX) {
                                        f = moveBlackQueen(msg, j, i, j*70+20 - blackQueen.posY, j*70+20 - blackQueen.posY);
                                        f = blackQueen.failedpath;
                                    } else if(j*70+20 == blackQueen.posY) {
                                        f = moveBlackQueenSide(msg, j, i, i*70+20 - blackQueen.posX, i*70+20 - blackQueen.posX);
                                        f = blackQueen.failedpath;
                                    } else if(i*70+20 != blackQueen.posX &&
                                       j*70+20 != blackQueen.posY) {
                                        f = moveBlackQueenDiagonally(msg, j, i, j*70+20 - blackQueen.posY, i*70+20 - blackQueen.posX, j*70+20 - blackQueen.posY, i*70+20 - blackQueen.posX);
                                        f = blackQueen.failedpath;
                                    }

                                    boolean fff = checkCheckBlack(j, i);

                                    if(f || fff) {

                                        blackQueen.posY = a1;
                                        blackQueen.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            blackPawns[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        blackQueenFunc = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        blackPawns[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            for(int z=0; z<8; z++) {

                                itdid = FALSE;

                                if(changeii == FALSE &&
                                   blackQueenK[z].posX == i*70+20 &&
                                   blackQueenK[z].posY == j*70+20) {

                                    clickedOne = 'r';
                                    blackQueenK[z].clicked = TRUE;
                                    turn = 'r';
                                    from = map(j, i);
                                    strncpy(chosenPiece, "qr", 2);
                                } else if(clickedOne == 'r' &&
                                          blackQueenK[z].clicked == TRUE) {
                                    itdid = TRUE;
                                    to = map(j, i);
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(itdid && changeii == FALSE) {

                                        clickedOne = 'r';
                                        blackQueenK[z].clicked = FALSE;

                                        int a1 = blackQueenK[z].posY;
                                        int a0 = blackQueenK[z].posX;

                                        boolean f = FALSE;

                                        blackQueenK[z].failedpath = FALSE;

                                        if(i*70+20 == blackQueenK[z].posX) {
                                            f = moveBlackQueenK(msg, j, i, j*70+20 - blackQueenK[z].posY, j*70+20 - blackQueenK[z].posY, z);
                                            f = blackQueenK[z].failedpath;
                                        } else if(j*70+20 == blackQueenK[z].posY) {
                                            f = moveBlackQueenSideK(msg, j, i, i*70+20 - blackQueenK[z].posX, i*70+20 - blackQueenK[z].posX, z);
                                            f = blackQueenK[z].failedpath;
                                        } else if(i*70+20 != blackQueenK[z].posX &&
                                           j*70+20 != blackQueenK[z].posY) {
                                            f = moveBlackQueenDiagonallyK(msg, j, i, j*70+20 - blackQueenK[z].posY, i*70+20 - blackQueenK[z].posX, j*70+20 - blackQueenK[z].posY, i*70+20 - blackQueenK[z].posX, z);
                                            f = blackQueenK[z].failedpath;
                                        }

                                        boolean fff = checkCheckBlack(j, i);

                                        if(f || fff) {

                                            blackQueenK[z].posY = a1;
                                            blackQueenK[z].posX = a0;

                                            turn = 'r';
                                        }

                                        else {
                                            for(int a=0; a<8; a++) {
                                                whitePawns[a].clicked = FALSE;
                                            }
                                            for(int a=0; a<8; a++) {
                                                blackPawns[a].clicked = FALSE;
                                            }
                                            boxes[j][i].clear = FALSE;
                                            turn = 'h';
                                            turnChanged = TRUE;
                                            done = TRUE;
                                        }

                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            blackPawns[a].clicked = FALSE;
                                        }

                                        itdid = FALSE;
                                    }
                                }
                            }

                            itdid = FALSE;

                            if(blackBishop1.posX == i*70+20 &&
                               blackBishop1.posY == j*70+20) {

                                clickedOne = 'r';
                                blackBishop1.clicked = TRUE;
                                blackBishop1.from = map(j, i);
                                turn = 'r';
                                from = map(j, i);
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackBishop1Start == -1 || blackBishop1Func == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop1Func = 0;
                                        blackBishop2Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = -1;
                                        blackRook1Func = -1;
                                        blackRook2Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = -1;
                                        bb1Thread = CreateThread(NULL, 0, paintBlackBishop1, NULL, 0, NULL);
                                        blackBishop1Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "br", 2);
                            } else if(clickedOne == 'r' &&
                                      blackBishop1.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackBishop1.clicked == TRUE) {
                                    blackBishop1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    blackBishop1.clicked = FALSE;

                                    int a1 = blackBishop1.posY;
                                    int a0 = blackBishop1.posX;

                                    boolean f = FALSE;

                                    blackBishop1.failedpath = FALSE;

                                    if(i*70+20 != blackBishop1.posX &&
                                       j*70+20 != blackBishop1.posY) {
                                        f = moveBlackBishop1(msg, j, i, j*70+20 - blackBishop1.posY, i*70+20 - blackBishop1.posX, j*70+20 - blackBishop1.posY, i*70+20 - blackBishop1.posX);
                                        f = blackBishop1.failedpath;
                                    } else {
                                        f = blackBishop1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckBlack(j, i);

                                    if(f || fff) {

                                        blackBishop1.posY = a1;
                                        blackBishop1.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            blackPawns[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        blackBishop1Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        blackPawns[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;

                            if(blackBishop2.posX == i*70+20 &&
                               blackBishop2.posY == j*70+20) {

                                clickedOne = 'r';
                                blackBishop2.clicked = TRUE;
                                blackBishop2.from = map(j, i);
                                turn = 'r';
                                from = map(j, i);
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackBishop2Start == -1 || blackBishop2Func == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop2Func = 0;
                                        blackBishop1Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = -1;
                                        blackRook1Func = -1;
                                        blackRook2Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = -1;
                                        bb2Thread = CreateThread(NULL, 0, paintBlackBishop2, NULL, 0, NULL);
                                        blackBishop2Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "br", 2);
                            } else if(clickedOne == 'r' &&
                                      blackBishop2.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackBishop2.clicked == TRUE) {
                                    blackBishop2.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    blackBishop2.clicked = FALSE;

                                    int a1 = blackBishop2.posY;
                                    int a0 = blackBishop2.posX;

                                    boolean f = FALSE;

                                    blackBishop2.failedpath = FALSE;

                                    if(i*70+20 != blackBishop2.posX &&
                                       j*70+20 != blackBishop2.posY) {
                                        f = moveBlackBishop2(msg, j, i, j*70+20 - blackBishop2.posY, i*70+20 - blackBishop2.posX, j*70+20 - blackBishop2.posY, i*70+20 - blackBishop2.posX);
                                        f = blackBishop2.failedpath;
                                    } else {
                                        f = blackBishop2.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckBlack(j, i);

                                    if(f || fff) {

                                        blackBishop2.posY = a1;
                                        blackBishop2.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            blackPawns[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        if(1==2) SetWindowText(hwnd, "Grey move");
                                        turnChanged = TRUE;
                                        done = TRUE;
                                        blackBishop2Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        blackPawns[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;

                            if(blackRook1.posX == i*70+20 &&
                               blackRook1.posY == j*70+20) {

                                clickedOne = 'r';
                                blackRook1.clicked = TRUE;
                                blackRook1.from = map(j, i);
                                turn = 'r';
                                from = map(j, i);
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackRook1Start == -1 || blackRook1Func == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop1Func = -1;
                                        blackBishop2Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = -1;
                                        blackRook1Func = 0;
                                        blackRook2Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = -1;
                                        br1Thread = CreateThread(NULL, 0, paintBlackRook1, NULL, 0, NULL);
                                        blackRook1Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "rr", 2);
                            } else if(clickedOne == 'r' &&
                                      blackRook1.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackRook1.clicked == TRUE) {
                                    blackRook1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    blackRook1.clicked = FALSE;

                                    int a1 = blackRook1.posY;
                                    int a0 = blackRook1.posX;

                                    boxes[blackRook1.posY/70][blackRook1.posX/70].clear = TRUE;

                                    boolean f = FALSE;

                                    blackRook1.failedpath = FALSE;

                                    if(i*70+20 == blackRook1.posX) {
                                        f = moveBlackRook1(msg, j, i, j*70+20 - blackRook1.posY, j*70+20 - blackRook1.posY);
                                        f = blackRook1.failedpath;
                                    } else if(j*70+20 == blackRook1.posY) {
                                        f = moveBlackRook1Side(msg, j, i, i*70+20 - blackRook1.posX, i*70+20 - blackRook1.posX);
                                        f = blackRook1.failedpath;
                                    } else {
                                        f = blackRook1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckBlack(j, i);

                                    if(f || fff) {

                                        blackRook1.posY = a1;
                                        blackRook1.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            blackPawns[a].clicked = FALSE;
                                        }
                                        whiteQueen.clicked = FALSE;
                                        whiteRook2.clicked = FALSE;
                                        whiteQueen.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        blackRook1Moved = TRUE;
                                        done = TRUE;
                                        blackRook1Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        blackPawns[a].clicked = FALSE;
                                    }
                                    whiteQueen.clicked = FALSE;
                                    whiteRook2.clicked = FALSE;
                                    whiteQueen.clicked = FALSE;

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;

                            if(blackRook2.posX == i*70+20 &&
                               blackRook2.posY == j*70+20) {

                                clickedOne = 'r';
                                blackRook2.clicked = TRUE;
                                blackRook2.from = map(j, i);
                                turn = 'r';
                                from = map(j, i);
                                if(msg == WM_LBUTTONDOWN) {
                                    if(blackRook2Start == -1 || blackRook2Func == -1) {
                                        blackPawnsFunc = -1;
                                        blackBishop1Func = -1;
                                        blackBishop2Func = -1;
                                        blackKnight1Func = -1;
                                        blackKnight2Func = -1;
                                        blackRook2Func = 0;
                                        blackRook1Func = -1;
                                        blackKingFunc = -1;
                                        blackQueenFunc = -1;
                                        br2Thread = CreateThread(NULL, 0, paintBlackRook2, NULL, 0, NULL);
                                        blackRook2Start = 0;
                                    }
                                }
                                strncpy(chosenPiece, "rr", 2);
                            } else if(clickedOne == 'r' &&
                                      blackRook2.clicked == TRUE) {
                                itdid = TRUE;
                                if(blackRook2.clicked == TRUE) {
                                    blackRook2.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    blackRook2.clicked = FALSE;

                                    int a1 = blackRook2.posY;
                                    int a0 = blackRook2.posX;

                                    boxes[blackRook2.posY/70][blackRook2.posX/70].clear = TRUE;

                                    boolean f = FALSE;

                                    blackRook2.failedpath = FALSE;

                                    if(i*70+20 == blackRook2.posX) {
                                        f = moveBlackRook2(msg, j, i, j*70+20 - blackRook2.posY, j*70+20 - blackRook2.posY);
                                        f = blackRook2.failedpath;
                                    } else if(j*70+20 == blackRook2.posY) {
                                        f = moveBlackRook2Side(msg, j, i, i*70+20 - blackRook2.posX, i*70+20 - blackRook2.posX);
                                        f = blackRook2.failedpath;
                                    } else {
                                        f = blackRook2.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckBlack(j, i);

                                    if(f || fff) {

                                        blackRook2.posY = a1;
                                        blackRook2.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            whitePawns[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            blackPawns[a].clicked = FALSE;
                                        }
                                        whiteQueen.clicked = FALSE;
                                        whiteRook1.clicked = FALSE;
                                        whiteQueen.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        blackRook2Moved = TRUE;
                                        done = TRUE;
                                        blackRook2Func = -1;
                                    }

                                    for(int a=0; a<8; a++) {
                                        whitePawns[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        blackPawns[a].clicked = FALSE;
                                    }
                                    whiteQueen.clicked = FALSE;
                                    whiteRook1.clicked = FALSE;
                                    whiteQueen.clicked = FALSE;

                                    itdid = FALSE;
                                }
                            }

                            if(!pcgame && done) {
                                getApiUnderwaterChessDotComMove2(from, to);
                            }

                            highlightPossibleMoves(j, i);

                            hdcMem = CreateCompatibleDC(hdc);
                            oldBitmap = SelectObject(hdcMem, hBitmap);

                            GetObject(hBitmap, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

                            SelectObject(hdcMem, oldBitmap);
                            DeleteDC(hdcMem); DeleteObject(hBitmap);

                            Sleep(1);
                            pawnBlack = (HBITMAP)LoadImage(hInst, "pawnblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            pawnWhite = (HBITMAP)LoadImage(hInst, "pawnwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knightBlack = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knightWhite = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knight2Black = (HBITMAP)LoadImage(hInst, "knightblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            knight2White = (HBITMAP)LoadImage(hInst, "knightwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rookBlack = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rookWhite = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rook2Black = (HBITMAP)LoadImage(hInst, "rookblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            rook2White = (HBITMAP)LoadImage(hInst, "rookwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishopBlack = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishopWhite = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishop2Black = (HBITMAP)LoadImage(hInst, "bishopblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            bishop2White = (HBITMAP)LoadImage(hInst, "bishopwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            queenBlack = (HBITMAP)LoadImage(hInst, "queenblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            queenWhite = (HBITMAP)LoadImage(hInst, "queenwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            kingBlack = (HBITMAP)LoadImage(hInst, "kingblack.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            Sleep(1);
                            kingWhite = (HBITMAP)LoadImage(hInst, "kingwhite.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                            hdcMem = CreateCompatibleDC(hdc);
                            HBITMAP hBmp;
                            if(((whiteRook1.posX/70)+(whiteRook1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rookWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rookWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteRook1.posX+25+7, whiteRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteRook2.posX/70)+(whiteRook2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rook2White,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rook2White,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteRook2.posX+25+7, whiteRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteKnight1.posX/70)+(whiteKnight1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knightWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knightWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteKnight1.posX+25+7, whiteKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteKnight2.posX/70)+(whiteKnight2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knight2White,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knight2White,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteKnight2.posX+25+7, whiteKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteBishop1.posX/70)+(whiteBishop1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishopWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishopWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteBishop1.posX+25+7, whiteBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteBishop2.posX/70)+(whiteBishop2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishop2White,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishop2White,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteBishop2.posX+25+7, whiteBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteQueen.posX/70)+(whiteQueen.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteQueen.posX+25+7, whiteQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((whiteKing.posX/70)+(whiteKing.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(kingWhite,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(kingWhite,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, whiteKing.posX+25+7, whiteKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            for(int o=0; o<8; o++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whitePawns[o].posX/70)+(whitePawns[o].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(pawnWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(pawnWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whitePawns[o].posX+25+7, whitePawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackRook1.posX/70)+(blackRook1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rookBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackRook1.posX+25+7, blackRook1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackRook2.posX/70)+(blackRook2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(rook2Black,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(rookBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackRook2.posX+25+7, blackRook2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackKnight1.posX/70)+(blackKnight1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knightBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knightBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackKnight1.posX+25+7, blackKnight1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackKnight2.posX/70)+(blackKnight2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(knight2Black,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(knight2Black,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackKnight2.posX+25+7, blackKnight2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackBishop1.posX/70)+(blackBishop1.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishopBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishopBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackBishop1.posX+25+7, blackBishop1.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackBishop2.posX/70)+(blackBishop2.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(bishop2Black,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(bishop2Black,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackBishop2.posX+25+7, blackBishop2.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackQueen.posX/70)+(blackQueen.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackQueen.posX+25+7, blackQueen.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            hdcMem = CreateCompatibleDC(hdc);
                            if(((blackKing.posX/70)+(blackKing.posY/70)) % 2 == 0)
                                hBmp = ReplaceColor(kingBlack,0x110000,0xffffff,hdcMem);
                            else
                                hBmp = ReplaceColor(kingBlack,0x110000,0x000000,hdcMem);
                            oldBitmap = SelectObject(hdcMem, hBmp);
                            GetObject(hBmp, sizeof(bitmap), &bitmap);
                            BitBlt(hdc, blackKing.posX+25+7, blackKing.posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                            SelectObject(hdcMem, oldBitmap);
                            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                            for(int o=0; o<8; o++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackPawns[o].posX/70)+(blackPawns[o].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(pawnBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(pawnBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackPawns[o].posX+25+7, blackPawns[o].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            for(int m=0; m<8; m++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((whiteQueenK[m].posX/70)+(whiteQueenK[m].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(queenWhite,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenWhite,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, whiteQueenK[m].posX+25+7, whiteQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            for(int m=0; m<8; m++) {
                                hdcMem = CreateCompatibleDC(hdc);
                                if(((blackQueenK[m].posX/70)+(blackQueenK[m].posY/70)) % 2 == 0)
                                    hBmp = ReplaceColor(queenBlack,0x110000,0xffffff,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenBlack,0x110000,0x000000,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, blackQueenK[m].posX+25+7, blackQueenK[m].posY+25, 46, 46, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                            }

                            DeleteObject(pawnBlack);
                            DeleteObject(pawnWhite);
                            DeleteObject(knightBlack);
                            DeleteObject(knightWhite);
                            DeleteObject(knight2Black);
                            DeleteObject(knight2White);
                            DeleteObject(rookBlack);
                            DeleteObject(rookWhite);
                            DeleteObject(rook2Black);
                            DeleteObject(rook2White);
                            DeleteObject(bishopBlack);
                            DeleteObject(bishopWhite);
                            DeleteObject(bishop2Black);
                            DeleteObject(bishop2White);
                            DeleteObject(queenBlack);
                            DeleteObject(queenWhite);
                            DeleteObject(kingBlack);
                            DeleteObject(kingWhite);

                            HBRUSH rBrush;
                            rBrush = CreateSolidBrush(RGB(0, 255, 0));
                            RECT r = {i*70+20+20, j*70+20+20-8, i*70+20+20 + 12, j*70+20+20-8 + 12};
                            for(int t=0; t<8; t++) {
                                if(turn == 'h' && blackPawns[t].posX == i*70+20 &&
                                   blackPawns[t].posY == j*70+20) {
                                    if(TRUE==done) {
                                        int l1_x1 = i*70+20+20;
                                        int l1_y1 = j*70+20 + 8;
                                        int l1_x2 = i*70+20+20 + 8;
                                        int l1_y2 = j*70+20 + 16;
                                        int l2_x1 = i*70+20+20 + 8;
                                        int l2_y1 = j*70+20 + 16;
                                        int l2_x2 = i*70+20+20 + 16;
                                        int l2_y2 = j*70+20;
                                        PAINTSTRUCT pntS;
                                        HPEN pen, oldPen;
                                        pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                        oldPen = (HPEN)SelectObject(hdc, pen);				
                                        MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                        LineTo(hdc, l1_x2, l1_y2);
                                        MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                        LineTo(hdc, l2_x2, l2_y2);
                                        SelectObject(hdc, oldPen); 
                                        DeleteObject(pen);
                                    }
                                }
                            }
                            for(int t=0; t<8; t++) {
                                if(turn == 'r' && blackPawns[t].posX == i*70+20 &&
                                   blackPawns[t].posY == j*70+20) {
                                    FillRect(hdc, &r, rBrush);
                                }
                            }
                            if(turn == 'h' && blackKing.posX == i*70+20 &&
                               blackKing.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackKing.posX == i*70+20 &&
                               blackKing.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && blackQueen.posX == i*70+20 &&
                               blackQueen.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackQueen.posX == i*70+20 &&
                               blackQueen.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            for(int z=0; z<8; z++) {
                                if(turn == 'h' && blackQueenK[z].posX == i*70+20 &&
                                   blackQueenK[z].posY == j*70+20) {
                                    if(TRUE==done) {
                                        int l1_x1 = i*70+20+20;
                                        int l1_y1 = j*70+20 + 8;
                                        int l1_x2 = i*70+20+20 + 8;
                                        int l1_y2 = j*70+20 + 16;
                                        int l2_x1 = i*70+20+20 + 8;
                                        int l2_y1 = j*70+20 + 16;
                                        int l2_x2 = i*70+20+20 + 16;
                                        int l2_y2 = j*70+20;
                                        PAINTSTRUCT pntS;
                                        HPEN pen, oldPen;
                                        pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                        oldPen = (HPEN)SelectObject(hdc, pen);				
                                        MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                        LineTo(hdc, l1_x2, l1_y2);
                                        MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                        LineTo(hdc, l2_x2, l2_y2);
                                        SelectObject(hdc, oldPen); 
                                        DeleteObject(pen);
                                    }
                                }
                                if(turn == 'r' && blackQueenK[z].posX == i*70+20 &&
                                   blackQueenK[z].posY == j*70+20) {
                                    FillRect(hdc, &r, rBrush);
                                }
                            }
                            if(turn == 'h' && blackKnight1.posX == i*70+20 &&
                               blackKnight1.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackKnight1.posX == i*70+20 &&
                               blackKnight1.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && blackKnight2.posX == i*70+20 &&
                               blackKnight2.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackKnight2.posX == i*70+20 &&
                               blackKnight2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && blackBishop1.posX == i*70+20 &&
                               blackBishop1.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackBishop1.posX == i*70+20 &&
                               blackBishop1.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && blackBishop2.posX == i*70+20 &&
                               blackBishop2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && blackBishop2.posX == i*70+20 &&
                               blackBishop2.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackBishop2.posX == i*70+20 &&
                               blackBishop2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && blackRook1.posX == i*70+20 &&
                               blackRook1.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackRook1.posX == i*70+20 &&
                               blackRook1.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && blackRook2.posX == i*70+20 &&
                               blackRook2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && blackRook2.posX == i*70+20 &&
                               blackRook2.posY == j*70+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*70+20+20;
                                    int l1_y1 = j*70+20 + 8;
                                    int l1_x2 = i*70+20+20 + 8;
                                    int l1_y2 = j*70+20 + 16;
                                    int l2_x1 = i*70+20+20 + 8;
                                    int l2_y1 = j*70+20 + 16;
                                    int l2_x2 = i*70+20+20 + 16;
                                    int l2_y2 = j*70+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && blackRook2.posX == i*70+20 &&
                               blackRook2.posY == j*70+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            DeleteObject(rBrush);

                            if(done) {
                                PostMessage(hwnd, WM_NOTIFY, 0, 0);
                            }
                        }
                    }
                }
            }

            break;
        }
        case WM_CREATE:
        {
            hMenu = CreateMenu();

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_CLICK_ME_NEW_GAME, "new game");
            AppendMenu(hSubMenu, MF_STRING, ID_FILE_DOWNLOAD, "get mine");
            AppendMenu(hSubMenu, MF_STRING, ID_CAPTURE_SCREEN, "capture screen");
            AppendMenu(hSubMenu, MF_STRING, ID_CLICK_ME_QUIT, "quit");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "File");
            
            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_PC_GAME, "> 1 PLAYER (HUMAN VERSUS P.C.)");
            AppendMenu(hSubMenu, MF_STRING, ID_HUMAN_GAME, "2 players (human versus human)");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Player Options");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_EASY, "> EASY");
            AppendMenu(hSubMenu, MF_STRING, ID_MEDIUM, "medium");
            AppendMenu(hSubMenu, MF_STRING, ID_HARD, "hard");
            AppendMenu(hSubMenu, MF_STRING, ID_IMPOSSIBLE, "impossible");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "1 Player Difficulty Options");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_0MIN, "> NO TIME (2 PLAYERS)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_5MIN, "5 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_10MIN, "10 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_15MIN, "15 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_20MIN, "20 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_25MIN, "25 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_30MIN, "30 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_35MIN, "35 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_40MIN, "40 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_45MIN, "45 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_50MIN, "50 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_55MIN, "55 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_60MIN, "60 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_65MIN, "65 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_70MIN, "70 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_75MIN, "75 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_80MIN, "80 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_85MIN, "85 mins (2 players)");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_90MIN, "90 mins (2 players)");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Timer Settings");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_ABOUT, "about");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Help");

            SetMenu(hwnd, hMenu);

            hIcon = LoadImage(NULL, "Icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
            if(hIcon)
                SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

            hIconSm = LoadImage(NULL, "Icon.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
            if(hIconSm)
                SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);

            char b[100] = "white versus";
            y = 0; h = 15;
            x = 585+50; w = 120;
            hwnd_white = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
            SetWindowText(hwnd_white, b);

            char c[100] = "black";
            y = 0; h = 15;
            x = 660+60; w = 120;
            hwnd_black = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
            SetWindowText(hwnd_black, c);

            y = 590+50; h = 20;
            x = 10; w = 220;
            hwnd_timer = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);

            y = 570+50; h = 48;
            x = 250; w = 124;
  	    hwnd_newgamebtn = CreateWindowEx(0, "BUTTON", "new game", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
								x, y, w, h, hwnd, (HMENU) IDC_NEW_GAME_BUTTON, GetModuleHandle(NULL), NULL);
            
            y = 570+50; h = 48;
            x = 380; w = 164;
  	    hwnd_quitbtn = CreateWindowEx(0, "BUTTON", "quit", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
								x, y, w, h, hwnd, (HMENU) IDC_QUIT_BUTTON, GetModuleHandle(NULL), NULL);

            hBitmap = (HBITMAP)LoadImage(hInst, "logo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            hBitmapSideLogo = (HBITMAP)LoadImage(hInst, "sidelogo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            pcgame = TRUE;
        }
        break;
        case WM_MOUSEMOVE:
        {
            if(klicked) {
                i__PosX = LOWORD(lParam);
                i__PosY = HIWORD(lParam);
                PostMessage(hwnd, WM_NOTIFY, 0, 0);
            }
        }
        break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_ABOUT:
                    ZeroMemory(&wcfwabout,sizeof(WNDCLASSEX));
                    wcfwabout.cbClsExtra=NULL;
                    wcfwabout.cbSize=sizeof(WNDCLASSEX);
                    wcfwabout.cbWndExtra=NULL;
                    wcfwabout.hbrBackground=(HBRUSH)COLOR_WINDOW;
                    wcfwabout.hCursor=LoadCursor(NULL,IDC_ARROW);
                    wcfwabout.hIcon=NULL;
                    wcfwabout.hIconSm=NULL;
                    wcfwabout.hInstance=hInst;
                    wcfwabout.lpfnWndProc=(WNDPROC)aboutWindowProcess;
                    wcfwabout.lpszClassName="about";
                    wcfwabout.lpszMenuName=NULL;
                    wcfwabout.style=CS_HREDRAW|CS_VREDRAW;

                    if(!RegisterClassEx(&wcfwabout))
                    {
                        int nResult=GetLastError();
                    }
                    
                    HWND h2=CreateWindowEx(NULL,
                            wcfwabout.lpszClassName,
                            "About",
                            WS_OVERLAPPEDWINDOW,
                            200,
                            150,
                            414,
                            359,
                            NULL,
                            NULL,
                            hInst,
                            NULL);

                    hIcon = LoadImage(NULL, "Icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
                    if(hIcon)
                        SendMessage(h2, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

                    hIconSm = LoadImage(NULL, "Icon.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
                    if(hIconSm)
                        SendMessage(h2, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);
                    
                    DisableMaximizeMinimizeButton(h2);
                    
                    ShowWindow(h2,nCmdShow2);
                break;
                case ID_EASY:
                    if(pcgame) {
                        SetMyMenu(3);
                        difficulty = 2.0;
                    }
                break;
                case ID_MEDIUM:
                    if(pcgame) {
                        SetMyMenu(4);
                        difficulty = 4.0;
                    }
                break;
                case ID_HARD:
                    if(pcgame) {
                        SetMyMenu(5);
                        difficulty = 7.0;
                    }
                break;
                case ID_IMPOSSIBLE:
                    if(pcgame) {
                        SetMyMenu(6);
                        difficulty = 13.0;
                    }
                break;
                case ID_PC_GAME:
                    SetMyMenu(1);
                    pcgame = TRUE;
                break;
                case ID_HUMAN_GAME:
                    SetMyMenu(2);
                    pcgame = FALSE;
                break;
                case ID_FILE_DOWNLOAD:
                    if(MessageBox(hwnd,"Would you like to download a copy of this source code?", "Get Mine", MB_YESNO) == IDYES) {
                        ShellExecute(NULL, "open", "https://github.com/OkelyKodely/chess/", NULL, NULL, SW_SHOWNORMAL);
                    }
                break;
                case ID_CAPTURE_SCREEN:
                    if(MessageBox(hwnd,"Would you like to capture the screen?", "Screen Capture", MB_YESNO) == IDYES) {
                        CaptureWindow(hwnd);
                    }
                break;
                case IDC_DOWNLOAD_BUTTON:
                    if(HIWORD(wParam) == BN_CLICKED) {
                        if(MessageBox(hwnd,"Would you like to download a copy of this source code?", "Get Mine", MB_YESNO) == IDYES) {
                            ShellExecute(NULL, "open", "https://github.com/OkelyKodely/chess/", NULL, NULL, SW_SHOWNORMAL);
                        }
                    }
                break;
                case IDC_NEW_GAME_BUTTON:
                    if (HIWORD(wParam) == BN_CLICKED) {
                        if(MessageBox(hwnd,"Would you like to play a new game?", "New Game", MB_YESNO) == IDYES) {
                            GetCurrentDir( buff, FILENAME_MAX );
                            buff[strlen(buff)] = '\0';
                            strcpy(filename,buff);
                            strcat(filename,"\\mychess.exe");
                            filename[strlen(filename)] = '\0';
                            STARTUPINFO startUpInfo = { 0 };
                            PROCESS_INFORMATION procInfo = { 0 };
                            startUpInfo.cb = sizeof( startUpInfo );
                            CreateProcess( filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startUpInfo, &procInfo );
                            if(gettingit) {
                                TerminateThread(callApi, 0);    
                            }
                            TerminateThread(ThreadFunc, 0);
                            exit(0);
                        }
                    }
                break;
                case IDC_QUIT_BUTTON:
                    if(HIWORD(wParam) == BN_CLICKED) {
                        if(MessageBox(hwnd,"Would you like to quit?", "Exit Game", MB_YESNO) == IDYES) {
                            PostMessage(hwnd, WM_CLOSE, 0, 0);
                        }
                    }
                break;
                case ID_TIMER_0MIN:
                    SetMyMenu(7);
                    ttw = 0;
                    timeToWait = 0;
                break;
                case ID_TIMER_5MIN:
                    if(!pcgame) {
                        SetMyMenu(8);
                        ttw = 5;
                        timeToWait = 60*5;
                    }
                break;
                case ID_TIMER_10MIN:
                    if(!pcgame) {
                        SetMyMenu(9);
                        ttw = 10;
                        timeToWait = 60*10;
                    }
                break;
                case ID_TIMER_15MIN:
                    if(!pcgame) {
                        SetMyMenu(10);
                        ttw = 15;
                        timeToWait = 60*15;
                    }
                break;
                case ID_TIMER_20MIN:
                    if(!pcgame) {
                        SetMyMenu(11);
                        ttw = 20;
                        timeToWait = 60*20;
                    }
                break;
                case ID_TIMER_25MIN:
                    if(!pcgame) {
                        SetMyMenu(12);
                        ttw = 25;
                        timeToWait = 60*25;
                    }
                break;
                case ID_TIMER_30MIN:
                    if(!pcgame) {
                        SetMyMenu(13);
                        ttw = 30;
                        timeToWait = 60*30;
                    }
                break;
                case ID_TIMER_35MIN:
                    if(!pcgame) {
                        SetMyMenu(14);
                        ttw = 35;
                        timeToWait = 60*35;
                    }
                break;
                case ID_TIMER_40MIN:
                    if(!pcgame) {
                        SetMyMenu(15);
                        ttw = 40;
                        timeToWait = 60*40;
                    }
                break;
                case ID_TIMER_45MIN:
                    if(!pcgame) {
                        SetMyMenu(16);
                        ttw = 45;
                        timeToWait = 60*45;
                    }
                break;
                case ID_TIMER_50MIN:
                    if(!pcgame) {
                        SetMyMenu(17);
                        ttw = 50;
                        timeToWait = 60*50;
                    }
                break;
                case ID_TIMER_55MIN:
                    if(!pcgame) {
                        SetMyMenu(18);
                        ttw = 55;
                        timeToWait = 60*55;
                    }
                break;
                case ID_TIMER_60MIN:
                    if(!pcgame) {
                        SetMyMenu(19);
                        ttw = 60;
                        timeToWait = 60*60;
                    }
                break;
                case ID_TIMER_65MIN:
                    if(!pcgame) {
                        SetMyMenu(20);
                        ttw = 65;
                        timeToWait = 60*65;
                    }
                break;
                case ID_TIMER_70MIN:
                    if(!pcgame) {
                        SetMyMenu(21);
                        ttw = 70;
                        timeToWait = 60*70;
                    }
                break;
                case ID_TIMER_75MIN:
                    if(!pcgame) {
                        SetMyMenu(22);
                        ttw = 75;
                        timeToWait = 60*75;
                    }
                break;
                case ID_TIMER_80MIN:
                    if(!pcgame) {
                        SetMyMenu(23);
                        ttw = 80;
                        timeToWait = 60*80;
                    }
                break;
                case ID_TIMER_85MIN:
                    if(!pcgame) {
                        SetMyMenu(24);
                        ttw = 85;
                        timeToWait = 60*85;
                    }
                break;
                case ID_TIMER_90MIN:
                    if(!pcgame) {
                        SetMyMenu(25);
                        ttw = 90;
                        timeToWait = 60*90;
                    }
                break;
                case ID_CLICK_ME_NEW_GAME:
                    if(MessageBox(hwnd,"Would you like to play a new game?", "New Game", MB_YESNO) == IDYES) {
                        GetCurrentDir( buff, FILENAME_MAX );
                        buff[strlen(buff)] = '\0';
                        strcpy(filename,buff);
                        strcat(filename,"\\mychess.exe");
                        filename[strlen(filename)] = '\0';
                        STARTUPINFO startUpInfo = { 0 };
                        PROCESS_INFORMATION procInfo = { 0 };
                        startUpInfo.cb = sizeof( startUpInfo );
                        CreateProcess( filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startUpInfo, &procInfo );
                        if(gettingit) {
                            TerminateThread(callApi, 0);    
                        }
                        TerminateThread(ThreadFunc, 0);
                        exit(0);
                    }
                    break;
                case ID_CLICK_ME_QUIT:
                    if(MessageBox(hwnd,"Would you like to quit?", "Exit Game", MB_YESNO) == IDYES) {
                        PostMessage(hwnd, WM_CLOSE, 0, 0);
                    }
                break;
            }
        break;
        case WM_CLOSE:
            TerminateThread(ThreadFunc, 0);
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
  
    nCmdShow2 = nCmdShow;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = CS_NOCLOSE;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    
    if(!RegisterClassEx(&wc)) {
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_LAYERED, 
            g_szClassName, "My Chess by Daniel Cho", 
            WS_OVERLAPPEDWINDOW,
            rect.left, rect.top, 1040, 740, 
            NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        return 0;
    }
    
    SetLayeredWindowAttributes(hwnd, 0, (255 * 100) / 100, LWA_ALPHA);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    RECT rc;
    GetWindowRect(hwnd, &rc);
    int xPos = (GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2;
    int yPos = (GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2;
    SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

    DisableMaximizeMinimizeButton(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}