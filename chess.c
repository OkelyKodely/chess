/* 
 * Application: chess.exe
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
#include "chess.h"

boolean checkmate = FALSE;

#define IDC_HAND MAKEINTRESOURCE(32649)

boolean fart = FALSE;

char filename[FILENAME_MAX];
char buff[FILENAME_MAX];

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

int begin = 1;

int iResult = -10;
int iresult = -10;

char *from;
char *to;

char *gt = "GET /game?fen=";
char *initfn = "rnbqkbnr%2Fpppppppp%2F8%2F8%2F8%2F8%2FPPPPPPPP%2FRNBQKBNR+w+KQkq+-+0+1";
char *hstt = "&format=json HTTP/1.0\r\nHost: api.underwaterchess.com\r\nContent-Type: application/json; charset=UTF-8\r\n\r\n";
char *fen = "rnbqkbnr%2Fpppppppp%2F8%2F8%2F8%2F8%2FPPPPPPPP%2FRNBQKBNR+w+KQkq+-+0+1";

boolean pcgame = FALSE;

HINSTANCE hInsta_nce;

HBITMAP hbit;

boolean INTRODUCTION = FALSE;

#define ID_CAPTURE_SCREEN 16001

#define IDC_DOWNLOAD_BUTTON 16002

#define ID_FILE_DOWNLOAD 16003

boolean fftime = TRUE;

int deathed = -1;

int _y_ = 20;

char chosenPiece[2] = "";

#define COLORREF2RGB(Color) (Color & 0xff00) | ((Color >> 16) & 0xff) | ((Color << 16) & 0xfe0000)

#define IDC_QUIT_BUTTON 101

#define IDC_NEW_GAME_BUTTON 102

boolean klicked = FALSE;

int i__PosX = 0;

int i__PosY = 0;
            
boolean done = FALSE;

boolean greyKingMoved = FALSE;

boolean redKingMoved = FALSE;

boolean greyRook1Moved = FALSE;

boolean redRook1Moved = FALSE;

boolean greyRook2Moved = FALSE;

boolean redRook2Moved = FALSE;

MSG msg;

RECT rect;

HINSTANCE hInst;
HINSTANCE g_hinstance;
HBITMAP hBitmap;
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

LPSTR TextArray [] = {
    "    CHECK"
};

#define			BUTTON_IDENTIFIER	1

boolean gettingit = FALSE;

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

void getApiUnderwaterChessDotComMove(char *frm, char *too) {

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 2, 2 );

    err = WSAStartup( wVersionRequested, &wsaData );
    if(err != 0) {
        error("no winsock.");
        return;
    }

    int portno = 80;
    char *host = "api.underwaterchess.com";

    char *str_2 = (char*) malloc(1 + strlen(gt)+ strlen(fen)+ strlen("&move=")+ strlen(frm)+ strlen(too)+ strlen(hstt) );
    strcpy(str_2, gt);
    strcat(str_2, fen);
    strcat(str_2, "&move=");
    strcat(str_2, frm);
    strcat(str_2, too);
    strcat(str_2, hstt);
    char *str = (char *) malloc(1 + strlen(str_2) );
    strcpy(str, str_2);

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char message[1024],response[8192];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(host);
    if(server == NULL) {
        error("ERROR, no such host");
    }

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    int length = strlen(str);
    int x = send(sockfd, str, length, 0);
    if(x == SOCKET_ERROR) {
        error("socket error");
    }
    
    do {
        iResult = recv(sockfd, response, 8192, 0);
    } while(iResult > 0);

    char *a = strstr(response, "fen\": \"");
    char *fee = (char*) malloc(100);
    strncpy(fee, a+7, 93);

    int i = 0;
    i = strcspn(fee,",");
    
    fen = (char*) malloc(i);
    strncpy(fen, fee, i-1);
    fen[i-1] = '\0';

    char *aaa = NULL;
    aaa = replaceWord(fen, "/", "%2F");
    fen = aaa;
    aaa = replaceWord(fen, " ", "+");
    fen = aaa;

    char *aab = strstr(response, "color\": \"");

    char *taf = malloc(5);
    strncpy(taf, aab+9, 5);

    char *ab = strstr(response, "isCheckmate\": ");

    char *tf = malloc(4);
    strncpy(tf, ab+14, 4);
    
    if(tf[0]=='f' &&
       tf[1]=='a' &&
       tf[2]=='l' &&
       tf[3]=='s') {

        char *b = strstr(response, "bestMove\": \"");
        strncpy(bestMove, b+12, 4);
    }
    else {
        checkmate = TRUE;
        if(taf[0]=='w')
            MessageBox(hwnd,"Checkmate!","Black Wins",MB_OK);
        else if(taf[0]=='b')
            MessageBox(hwnd,"Checkmate!","White Wins",MB_OK);
    }

    /* close the socket */
    close(sockfd);
    
    WSACleanup();
}

DWORD WINAPI callApi(void *data) {

    gettingit = TRUE;
    
    fart = TRUE;

    getApiUnderwaterChessDotComMove(from, to);

    boolean refreshme = FALSE;

    if(bestMove != NULL &&
       redKnight1Rectangle1.posX == 20+reMap(bestMove,0)) {
        if(redKnight1Rectangle1.posY == 20+reMap(bestMove,1)) {
            redKnight1Rectangle1.from = map(redKnight1Rectangle1.posY/100, redKnight1Rectangle1.posX/100);
            redKnight1Rectangle1.posY = 20+re_Map(bestMove,1);
            redKnight1Rectangle1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redKnight1Rectangle1.posX == greyPawnsBase[z].posX &&
                   redKnight1Rectangle1.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redKnight1Rectangle1.posX == greyRook1Rectangle1.posX &&
               redKnight1Rectangle1.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redKnight1Rectangle1.posX == greyRook2Rectangle1.posX &&
               redKnight1Rectangle1.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redKnight1Rectangle1.posX == greyKnight1Rectangle1.posX &&
               redKnight1Rectangle1.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redKnight1Rectangle1.posX == greyKnight2Rectangle1.posX &&
               redKnight1Rectangle1.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redKnight1Rectangle1.posX == greyBishop1Square.posX &&
               redKnight1Rectangle1.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redKnight1Rectangle1.posX == greyBishop2Square.posX &&
               redKnight1Rectangle1.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redKnight1Rectangle1.posX == greyQueenSquare.posX &&
               redKnight1Rectangle1.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redKnight1Rectangle1.to = map(redKnight1Rectangle1.posY/100, redKnight1Rectangle1.posX/100);
            getApiUnderwaterChessDotComMove(
                  redKnight1Rectangle1.from,
                  redKnight1Rectangle1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redKnight2Rectangle1.posX == 20+reMap(bestMove,0)) {
        if(redKnight2Rectangle1.posY == 20+reMap(bestMove,1)) {
            redKnight2Rectangle1.from = map(redKnight2Rectangle1.posY/100, redKnight2Rectangle1.posX/100);
            redKnight2Rectangle1.posY = 20+re_Map(bestMove,1);
            redKnight2Rectangle1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redKnight2Rectangle1.posX == greyPawnsBase[z].posX &&
                   redKnight2Rectangle1.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redKnight2Rectangle1.posX == greyRook1Rectangle1.posX &&
               redKnight2Rectangle1.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redKnight2Rectangle1.posX == greyRook2Rectangle1.posX &&
               redKnight2Rectangle1.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redKnight2Rectangle1.posX == greyKnight1Rectangle1.posX &&
               redKnight2Rectangle1.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redKnight2Rectangle1.posX == greyKnight2Rectangle1.posX &&
               redKnight2Rectangle1.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redKnight2Rectangle1.posX == greyBishop1Square.posX &&
               redKnight2Rectangle1.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redKnight2Rectangle1.posX == greyBishop2Square.posX &&
               redKnight2Rectangle1.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redKnight2Rectangle1.posX == greyQueenSquare.posX &&
               redKnight2Rectangle1.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redKnight2Rectangle1.to = map(redKnight2Rectangle1.posY/100, redKnight2Rectangle1.posX/100);
            getApiUnderwaterChessDotComMove(
                  redKnight2Rectangle1.from,
                  redKnight2Rectangle1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redBishop1Square.posX == 20+reMap(bestMove,0)) {
        if(redBishop1Square.posY == 20+reMap(bestMove,1)) {
            redBishop1Square.from = map(redBishop1Square.posY/100, redBishop1Square.posX/100);
            redBishop1Square.posY = 20+re_Map(bestMove,1);
            redBishop1Square.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redBishop1Square.posX == greyPawnsBase[z].posX &&
                   redBishop1Square.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redBishop1Square.posX == greyRook1Rectangle1.posX &&
               redBishop1Square.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redBishop1Square.posX == greyRook2Rectangle1.posX &&
               redBishop1Square.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redBishop1Square.posX == greyKnight1Rectangle1.posX &&
               redBishop1Square.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redBishop1Square.posX == greyKnight2Rectangle1.posX &&
               redBishop1Square.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redBishop1Square.posX == greyBishop1Square.posX &&
               redBishop1Square.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redBishop1Square.posX == greyBishop2Square.posX &&
               redBishop1Square.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redBishop1Square.posX == greyQueenSquare.posX &&
               redBishop1Square.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redBishop1Square.to = map(redBishop1Square.posY/100, redBishop1Square.posX/100);
            getApiUnderwaterChessDotComMove(
                  redBishop1Square.from,
                  redBishop1Square.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redBishop2Square.posX == 20+reMap(bestMove,0)) {
        if(redBishop2Square.posY == 20+reMap(bestMove,1)) {
            redBishop2Square.from = map(redBishop2Square.posY/100, redBishop2Square.posX/100);
            redBishop2Square.posY = 20+re_Map(bestMove,1);
            redBishop2Square.posX = 20+re_Map(bestMove,0);
                for(int z=0; z<8; z++) {
                    if(redBishop2Square.posX == greyPawnsBase[z].posX &&
                       redBishop2Square.posY == greyPawnsBase[z].posY) {
                        greyPawnsBase[z].posX = 1300;
                    }
                }
                if(redBishop2Square.posX == greyRook1Rectangle1.posX &&
                   redBishop2Square.posY == greyRook1Rectangle1.posY) {
                    greyRook1Rectangle1.posX = 1300;
                }
                if(redBishop2Square.posX == greyRook2Rectangle1.posX &&
                   redBishop2Square.posY == greyRook2Rectangle1.posY) {
                    greyRook2Rectangle1.posX = 1300;
                }
                if(redBishop2Square.posX == greyKnight1Rectangle1.posX &&
                   redBishop2Square.posY == greyKnight1Rectangle1.posY) {
                    greyKnight1Rectangle1.posX = 1300;
                }
                if(redBishop2Square.posX == greyKnight2Rectangle1.posX &&
                   redBishop2Square.posY == greyKnight2Rectangle1.posY) {
                    greyKnight2Rectangle1.posX = 1300;
                }
                if(redBishop2Square.posX == greyBishop1Square.posX &&
                   redBishop2Square.posY == greyBishop1Square.posY) {
                    greyBishop1Square.posX = 1300;
                }
                if(redBishop2Square.posX == greyBishop2Square.posX &&
                   redBishop2Square.posY == greyBishop2Square.posY) {
                    greyBishop2Square.posX = 1300;
                }
                if(redBishop2Square.posX == greyQueenSquare.posX &&
                   redBishop2Square.posY == greyQueenSquare.posY) {
                    greyQueenSquare.posX = 1300;
                }
            redBishop2Square.to = map(redBishop2Square.posY/100, redBishop2Square.posX/100);
            getApiUnderwaterChessDotComMove(
                  redBishop2Square.from,
                  redBishop2Square.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redRook1Rectangle1.posX == 20+reMap(bestMove,0)) {
        if(redRook1Rectangle1.posY == 20+reMap(bestMove,1)) {
            redRook1Rectangle1.from = map(redRook1Rectangle1.posY/100, redRook1Rectangle1.posX/100);
            redRook1Rectangle1.posY = 20+re_Map(bestMove,1);
            redRook1Rectangle1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redRook1Rectangle1.posX == greyPawnsBase[z].posX &&
                   redRook1Rectangle1.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redRook1Rectangle1.posX == greyRook1Rectangle1.posX &&
               redRook1Rectangle1.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redRook1Rectangle1.posX == greyRook2Rectangle1.posX &&
               redRook1Rectangle1.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redRook1Rectangle1.posX == greyKnight1Rectangle1.posX &&
               redRook1Rectangle1.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redRook1Rectangle1.posX == greyKnight2Rectangle1.posX &&
               redRook1Rectangle1.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redRook1Rectangle1.posX == greyBishop1Square.posX &&
               redRook1Rectangle1.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redRook1Rectangle1.posX == greyBishop2Square.posX &&
               redRook1Rectangle1.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redRook1Rectangle1.posX == greyQueenSquare.posX &&
               redRook1Rectangle1.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redRook1Rectangle1.to = map(redRook1Rectangle1.posY/100, redRook1Rectangle1.posX/100);
            getApiUnderwaterChessDotComMove(
                  redRook1Rectangle1.from,
                  redRook1Rectangle1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redRook2Rectangle1.posX == 20+reMap(bestMove,0)) {
        if(redRook2Rectangle1.posY == 20+reMap(bestMove,1)) {
            redRook2Rectangle1.from = map(redRook2Rectangle1.posY/100, redRook2Rectangle1.posX/100);
            redRook2Rectangle1.posY = 20+re_Map(bestMove,1);
            redRook2Rectangle1.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redRook2Rectangle1.posX == greyPawnsBase[z].posX &&
                   redRook2Rectangle1.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redRook2Rectangle1.posX == greyRook1Rectangle1.posX &&
               redRook2Rectangle1.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redRook2Rectangle1.posX == greyRook2Rectangle1.posX &&
               redRook2Rectangle1.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redRook2Rectangle1.posX == greyKnight1Rectangle1.posX &&
               redRook2Rectangle1.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redRook2Rectangle1.posX == greyKnight2Rectangle1.posX &&
               redRook2Rectangle1.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redRook2Rectangle1.posX == greyBishop1Square.posX &&
               redRook2Rectangle1.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redRook2Rectangle1.posX == greyBishop2Square.posX &&
               redRook2Rectangle1.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redRook2Rectangle1.posX == greyQueenSquare.posX &&
               redRook2Rectangle1.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redRook2Rectangle1.to = map(redRook2Rectangle1.posY/100, redRook2Rectangle1.posX/100);
            getApiUnderwaterChessDotComMove(
                  redRook2Rectangle1.from,
                  redRook2Rectangle1.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redQueenSquare.posX == 20+reMap(bestMove,0)) {
        if(redQueenSquare.posY == 20+reMap(bestMove,1)) {
            redQueenSquare.from = map(redQueenSquare.posY/100, redQueenSquare.posX/100);
            redQueenSquare.posY = 20+re_Map(bestMove,1);
            redQueenSquare.posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redQueenSquare.posX == greyPawnsBase[z].posX &&
                   redQueenSquare.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redQueenSquare.posX == greyRook1Rectangle1.posX &&
               redQueenSquare.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redQueenSquare.posX == greyRook2Rectangle1.posX &&
               redQueenSquare.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redQueenSquare.posX == greyKnight1Rectangle1.posX &&
               redQueenSquare.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redQueenSquare.posX == greyKnight2Rectangle1.posX &&
               redQueenSquare.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redQueenSquare.posX == greyBishop1Square.posX &&
               redQueenSquare.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redQueenSquare.posX == greyBishop2Square.posX &&
               redQueenSquare.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redQueenSquare.posX == greyQueenSquare.posX &&
               redQueenSquare.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redQueenSquare.to = map(redQueenSquare.posY/100, redQueenSquare.posX/100);
            getApiUnderwaterChessDotComMove(
                  redQueenSquare.from,
                  redQueenSquare.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redKingSquare.posX == 20+reMap(bestMove,0)) {
        if(redKingSquare.posY == 20+reMap(bestMove,1)) {
            redKingSquare.from = map(redKingSquare.posY/100, redKingSquare.posX/100);
            int xxxx = redKingSquare.posX;
            int yyyy = redKingSquare.posY;
            redKingSquare.posY = 20+re_Map(bestMove,1);
            redKingSquare.posX = 20+re_Map(bestMove,0);
            if(xxxx - redKingSquare.posX == 200) {
                redRook1Rectangle1.posX += 300;
            }
            if(redKingSquare.posX - xxxx == 200) {
                redRook2Rectangle1.posX -= 200;
            }
            for(int z=0; z<8; z++) {
                if(redKingSquare.posX == greyPawnsBase[z].posX &&
                   redKingSquare.posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redKingSquare.posX == greyRook1Rectangle1.posX &&
               redKingSquare.posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redKingSquare.posX == greyRook2Rectangle1.posX &&
               redKingSquare.posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redKingSquare.posX == greyKnight1Rectangle1.posX &&
               redKingSquare.posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redKingSquare.posX == greyKnight2Rectangle1.posX &&
               redKingSquare.posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redKingSquare.posX == greyBishop1Square.posX &&
               redKingSquare.posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redKingSquare.posX == greyBishop2Square.posX &&
               redKingSquare.posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redKingSquare.posX == greyQueenSquare.posX &&
               redKingSquare.posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redKingSquare.to = map(redKingSquare.posY/100, redKingSquare.posX/100);
            getApiUnderwaterChessDotComMove(
                  redKingSquare.from,
                  redKingSquare.to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[0].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[0].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[0].from = map(redPawnsBase[0].posY/100, redPawnsBase[0].posX/100);
            redPawnsBase[0].posY = 20+re_Map(bestMove,1);
            redPawnsBase[0].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[0].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[0].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[0].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[0].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[0].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[0].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[0].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[0].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[0].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[0].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[0].posX == greyBishop1Square.posX &&
               redPawnsBase[0].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[0].posX == greyBishop2Square.posX &&
               redPawnsBase[0].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[0].posX == greyQueenSquare.posX &&
               redPawnsBase[0].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[0].to = map(redPawnsBase[0].posY/100, redPawnsBase[0].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[0].from,
                  redPawnsBase[0].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[1].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[1].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[1].from = map(redPawnsBase[1].posY/100, redPawnsBase[1].posX/100);
            redPawnsBase[1].posY = 20+re_Map(bestMove,1);
            redPawnsBase[1].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[1].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[1].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[1].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[1].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[1].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[1].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[1].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[1].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[1].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[1].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[1].posX == greyBishop1Square.posX &&
               redPawnsBase[1].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[1].posX == greyBishop2Square.posX &&
               redPawnsBase[1].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[1].posX == greyQueenSquare.posX &&
               redPawnsBase[1].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[1].to = map(redPawnsBase[1].posY/100, redPawnsBase[1].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[1].from,
                  redPawnsBase[1].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[2].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[2].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[2].from = map(redPawnsBase[2].posY/100, redPawnsBase[2].posX/100);
            redPawnsBase[2].posY = 20+re_Map(bestMove,1);
            redPawnsBase[2].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[2].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[2].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[2].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[2].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[2].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[2].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[2].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[2].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[2].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[2].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[2].posX == greyBishop1Square.posX &&
               redPawnsBase[2].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[2].posX == greyBishop2Square.posX &&
               redPawnsBase[2].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[2].posX == greyQueenSquare.posX &&
               redPawnsBase[2].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[2].to = map(redPawnsBase[2].posY/100, redPawnsBase[2].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[2].from,
                  redPawnsBase[2].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[3].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[3].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[3].from = map(redPawnsBase[3].posY/100, redPawnsBase[3].posX/100);
            redPawnsBase[3].posY = 20+re_Map(bestMove,1);
            redPawnsBase[3].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[3].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[3].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[3].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[3].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[3].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[3].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[3].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[3].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[3].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[3].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[3].posX == greyBishop1Square.posX &&
               redPawnsBase[3].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[3].posX == greyBishop2Square.posX &&
               redPawnsBase[3].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[3].posX == greyQueenSquare.posX &&
               redPawnsBase[3].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[3].to = map(redPawnsBase[3].posY/100, redPawnsBase[3].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[3].from,
                  redPawnsBase[3].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[4].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[4].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[4].from = map(redPawnsBase[4].posY/100, redPawnsBase[4].posX/100);
            redPawnsBase[4].posY = 20+re_Map(bestMove,1);
            redPawnsBase[4].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[4].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[4].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[4].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[4].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[4].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[4].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[4].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[4].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[4].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[4].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[4].posX == greyBishop1Square.posX &&
               redPawnsBase[4].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[4].posX == greyBishop2Square.posX &&
               redPawnsBase[4].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[4].posX == greyQueenSquare.posX &&
               redPawnsBase[4].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[4].to = map(redPawnsBase[4].posY/100, redPawnsBase[4].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[4].from,
                  redPawnsBase[4].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[5].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[5].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[5].from = map(redPawnsBase[5].posY/100, redPawnsBase[5].posX/100);
            redPawnsBase[5].posY = 20+re_Map(bestMove,1);
            redPawnsBase[5].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[5].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[5].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[5].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[5].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[5].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[5].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[5].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[5].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[5].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[5].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[5].posX == greyBishop1Square.posX &&
               redPawnsBase[5].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[5].posX == greyBishop2Square.posX &&
               redPawnsBase[5].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[5].posX == greyQueenSquare.posX &&
               redPawnsBase[5].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[5].to = map(redPawnsBase[5].posY/100, redPawnsBase[5].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[5].from,
                  redPawnsBase[5].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[6].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[6].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[6].from = map(redPawnsBase[6].posY/100, redPawnsBase[6].posX/100);
            redPawnsBase[6].posY = 20+re_Map(bestMove,1);
            redPawnsBase[6].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[6].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[6].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[6].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[6].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[6].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[6].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[6].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[6].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[6].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[6].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[6].posX == greyBishop1Square.posX &&
               redPawnsBase[6].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[6].posX == greyBishop2Square.posX &&
               redPawnsBase[6].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[6].posX == greyQueenSquare.posX &&
               redPawnsBase[6].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[6].to = map(redPawnsBase[6].posY/100, redPawnsBase[6].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[6].from,
                  redPawnsBase[6].to);
            refreshme = TRUE;
        }
    }
    if(bestMove != NULL &&
       redPawnsBase[7].posX == 20+reMap(bestMove,0)) {
        if(redPawnsBase[7].posY == 20+reMap(bestMove,1)) {
            redPawnsBase[7].from = map(redPawnsBase[7].posY/100, redPawnsBase[7].posX/100);
            redPawnsBase[7].posY = 20+re_Map(bestMove,1);
            redPawnsBase[7].posX = 20+re_Map(bestMove,0);
            for(int z=0; z<8; z++) {
                if(redPawnsBase[7].posX == greyPawnsBase[z].posX &&
                   redPawnsBase[7].posY == greyPawnsBase[z].posY) {
                    greyPawnsBase[z].posX = 1300;
                }
            }
            if(redPawnsBase[7].posX == greyRook1Rectangle1.posX &&
               redPawnsBase[7].posY == greyRook1Rectangle1.posY) {
                greyRook1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[7].posX == greyRook2Rectangle1.posX &&
               redPawnsBase[7].posY == greyRook2Rectangle1.posY) {
                greyRook2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[7].posX == greyKnight1Rectangle1.posX &&
               redPawnsBase[7].posY == greyKnight1Rectangle1.posY) {
                greyKnight1Rectangle1.posX = 1300;
            }
            if(redPawnsBase[7].posX == greyKnight2Rectangle1.posX &&
               redPawnsBase[7].posY == greyKnight2Rectangle1.posY) {
                greyKnight2Rectangle1.posX = 1300;
            }
            if(redPawnsBase[7].posX == greyBishop1Square.posX &&
               redPawnsBase[7].posY == greyBishop1Square.posY) {
                greyBishop1Square.posX = 1300;
            }
            if(redPawnsBase[7].posX == greyBishop2Square.posX &&
               redPawnsBase[7].posY == greyBishop2Square.posY) {
                greyBishop2Square.posX = 1300;
            }
            if(redPawnsBase[7].posX == greyQueenSquare.posX &&
               redPawnsBase[7].posY == greyQueenSquare.posY) {
                greyQueenSquare.posX = 1300;
            }
            redPawnsBase[7].to = map(redPawnsBase[7].posY/100, redPawnsBase[7].posX/100);
            getApiUnderwaterChessDotComMove(
                  redPawnsBase[7].from,
                  redPawnsBase[7].to);
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
        if(((greyRook1Rectangle1.posX/100)+(greyRook1Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(rookWhite,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(rookWhite,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyRook1Rectangle1.posX+25+7, greyRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((greyRook2Rectangle1.posX/100)+(greyRook2Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(rook2White,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(rook2White,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyRook2Rectangle1.posX+25+7, greyRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((greyKnight1Rectangle1.posX/100)+(greyKnight1Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(knightWhite,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(knightWhite,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyKnight1Rectangle1.posX+25+7, greyKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((greyKnight2Rectangle1.posX/100)+(greyKnight2Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(knight2White,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(knight2White,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyKnight2Rectangle1.posX+25+7, greyKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((greyBishop1Square.posX/100)+(greyBishop1Square.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(bishopWhite,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(bishopWhite,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyBishop1Square.posX+25+7, greyBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((greyBishop2Square.posX/100)+(greyBishop2Square.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(bishop2White,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(bishop2White,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyBishop2Square.posX+25+7, greyBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((greyQueenSquare.posX/100)+(greyQueenSquare.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyQueenSquare.posX+25+7, greyQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        
        hdcMem = CreateCompatibleDC(hdc);
        if(((greyKingSquare.posX/100)+(greyKingSquare.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(kingWhite,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(kingWhite,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, greyKingSquare.posX+25+7, greyKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        for(int o=0; o<8; o++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((greyPawnsBase[o].posX/100)+(greyPawnsBase[o].posY/100)) % 2 == 0)
                hBmp = ReplaceColor(pawnWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(pawnWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyPawnsBase[o].posX+25+7, greyPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        hdcMem = CreateCompatibleDC(hdc);
        if(((redRook1Rectangle1.posX/100)+(redRook1Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(rookBlack,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redRook1Rectangle1.posX+25+7, redRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redRook2Rectangle1.posX/100)+(redRook2Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(rook2Black,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redRook2Rectangle1.posX+25+7, redRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redKnight1Rectangle1.posX/100)+(redKnight1Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(knightBlack,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(knightBlack,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redKnight1Rectangle1.posX+25+7, redKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redKnight2Rectangle1.posX/100)+(redKnight2Rectangle1.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(knight2Black,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(knight2Black,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redKnight2Rectangle1.posX+25+7, redKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redBishop1Square.posX/100)+(redBishop1Square.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(bishopBlack,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(bishopBlack,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redBishop1Square.posX+25+7, redBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redBishop2Square.posX/100)+(redBishop2Square.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(bishop2Black,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(bishop2Black,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redBishop2Square.posX+25+7, redBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redQueenSquare.posX/100)+(redQueenSquare.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redQueenSquare.posX+25+7, redQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        hdcMem = CreateCompatibleDC(hdc);
        if(((redKingSquare.posX/100)+(redKingSquare.posY/100)) % 2 == 0)
            hBmp = ReplaceColor(kingBlack,0x110000,0xe1f4fc,hdcMem);
        else
            hBmp = ReplaceColor(kingBlack,0x110000,0x377105,hdcMem);
        oldBitmap = SelectObject(hdcMem, hBmp);
        GetObject(hBmp, sizeof(bitmap), &bitmap);
        BitBlt(hdc, redKingSquare.posX+25+7, redKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
        SelectObject(hdcMem, oldBitmap);
        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

        for(int o=0; o<8; o++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((redPawnsBase[o].posX/100)+(redPawnsBase[o].posY/100)) % 2 == 0)
                hBmp = ReplaceColor(pawnBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(pawnBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redPawnsBase[o].posX+25+7, redPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        for(int m=0; m<8; m++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((greyQueenSquareK[m].posX/100)+(greyQueenSquareK[m].posY/100)) % 2 == 0)
                hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyQueenSquareK[m].posX+25+7, greyQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
        }

        for(int m=0; m<8; m++) {
            hdcMem = CreateCompatibleDC(hdc);
            if(((redQueenSquareK[m].posX/100)+(redQueenSquareK[m].posY/100)) % 2 == 0)
                hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redQueenSquareK[m].posX+25+7, redQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
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

        HBRUSH white_brush = CreateSolidBrush(RGB(255,200,200));
        RECT rrect = {820+50, 20, 1120, 810};
        FillRect(hdc, &rrect, white_brush);
        DeleteObject(white_brush);

        if(greyRook1Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rookWhite_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyRook1Rectangle1.from != NULL && greyRook1Rectangle1.to != NULL) {
                if(strlen(greyRook1Rectangle1.from) >= 2 && strlen(greyRook1Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyRook1Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyRook2Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rook2White_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyRook2Rectangle1.from != NULL && greyRook2Rectangle1.to != NULL) {
                if(strlen(greyRook2Rectangle1.from) >= 2 && strlen(greyRook2Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyRook2Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyKnight1Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knightWhite_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyKnight1Rectangle1.from != NULL && greyKnight1Rectangle1.to != NULL) {
                if(strlen(greyKnight1Rectangle1.from) >= 2 && strlen(greyKnight1Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyKnight1Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyKnight2Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knight2White_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyKnight2Rectangle1.from != NULL && greyKnight2Rectangle1.to != NULL) {
                if(strlen(greyKnight2Rectangle1.from) >= 2 && strlen(greyKnight2Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyKnight2Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyBishop1Square.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishopWhite_s,0x4cb122,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyBishop1Square.from != NULL && greyBishop1Square.to != NULL) {
                if(strlen(greyBishop1Square.from) >= 2 && strlen(greyBishop1Square.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyBishop1Square.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyBishop2Square.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishop2White_s,0x4cb122,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyBishop2Square.from != NULL && greyBishop2Square.to != NULL) {
                if(strlen(greyBishop2Square.from) >= 2 && strlen(greyBishop2Square.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyBishop2Square.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyQueenSquare.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(greyQueenSquare.from != NULL && greyQueenSquare.to != NULL) {
                if(strlen(greyQueenSquare.from) >= 2 && strlen(greyQueenSquare.to) >= 2) {
                    TextOut(hdc,
                            855+50,
                            _y_,
                            greyQueenSquare.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(greyKingSquare.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(kingWhite_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        for(int o=0; o<8; o++) {
            if(greyPawnsBase[o].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(pawnWhite_s,0x000000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyPawnsBase[o].from != NULL && greyPawnsBase[o].to != NULL) {
                    if(strlen(greyPawnsBase[o].from) >= 2 && strlen(greyPawnsBase[o].to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyPawnsBase[o].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        for(int m=0; m<8; m++) {
            if(greyQueenSquareK[m].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyQueenSquareK[m].from != NULL && greyQueenSquareK[m].to != NULL) {
                    if(strlen(greyQueenSquareK[m].from) >= 2 && strlen(greyQueenSquareK[m].to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyQueenSquareK[m].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        _y_ = 20;

        if(redRook1Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rookBlack_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redRook1Rectangle1.from != NULL && redRook1Rectangle1.to != NULL) {
                if(strlen(redRook1Rectangle1.from) >= 2 && strlen(redRook1Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redRook1Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redRook2Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(rook2Black_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redRook2Rectangle1.from != NULL && redRook2Rectangle1.to != NULL) {
                if(strlen(redRook2Rectangle1.from) >= 2 && strlen(redRook2Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redRook2Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redKnight1Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knightBlack_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redKnight1Rectangle1.from != NULL && redKnight1Rectangle1.to != NULL) {
                if(strlen(redKnight1Rectangle1.from) >= 2 && strlen(redKnight1Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redKnight1Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redKnight2Rectangle1.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(knight2Black_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redKnight2Rectangle1.from != NULL && redKnight2Rectangle1.to != NULL) {
                if(strlen(redKnight2Rectangle1.from) >= 2 && strlen(redKnight2Rectangle1.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redKnight2Rectangle1.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redBishop1Square.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishopBlack_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redBishop1Square.from != NULL && redBishop1Square.to != NULL) {
                if(strlen(redBishop1Square.from) >= 2 && strlen(redBishop1Square.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redBishop1Square.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redBishop2Square.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(bishop2Black_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redBishop2Square.from != NULL && redBishop2Square.to != NULL) {
                if(strlen(redBishop2Square.from) >= 2 && strlen(redBishop2Square.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redBishop2Square.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redQueenSquare.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            if(redQueenSquare.from != NULL && redQueenSquare.to != NULL) {
                if(strlen(redQueenSquare.from) >= 2 && strlen(redQueenSquare.to) >= 2) {
                    TextOut(hdc,
                            930+50,
                            _y_,
                            redQueenSquare.to,
                            GetTextSize("za"));
                }
            }
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        if(redKingSquare.posX == 1300) {
            hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hBmp = ReplaceColor(kingBlack_s,0xff0000,0xc8c8ff,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            _y_ += 31;
        }

        for(int o=0; o<8; o++) {
            if(redPawnsBase[o].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(pawnBlack_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redPawnsBase[o].from != NULL && redPawnsBase[o].to != NULL) {
                    if(strlen(redPawnsBase[o].from) >= 2 && strlen(redPawnsBase[o].to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redPawnsBase[o].to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }
        }

        for(int m=0; m<8; m++) {
            if(redQueenSquareK[m].posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redQueenSquareK[m].from != NULL && redQueenSquareK[m].to != NULL) {
                    if(strlen(redQueenSquareK[m].from) >= 2 && strlen(redQueenSquareK[m].to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redQueenSquareK[m].to,
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
    
    return 0;
}

void error(char *t) {
    printf("ERROR=");
    printf(t);
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

                sprintf(b, "white to move - out of %d mins %d mins and %d secs elapsed",ttw, min, sec);
            } else {

                sprintf(b, "black to move - out of %d mins %d mins and %d secs elapsed",ttw, min, sec);
            }
        } else {
            
            if(!pcgame) {
                
                if(turn == 'h') {

                    sprintf(b, "white to move - no time");

                } else {

                    sprintf(b, "black to move - no time");
                }
                
            } else {
                
                if(turn == 'h') {

                    sprintf(b, "white to move");
                
                } else {

                    sprintf(b, "black to move");
                }
                
            }
            
        }
        if(ls != cs) {
            SetWindowText(hwnd_timer, b);
            if(gettingit) {
                SetWindowText(hwnd_timer, "black player thinking ...");
            } else {
                if(pcgame && fart) {
                    TerminateThread(callApi, 0);
                    fart = FALSE;
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
    greyKingMoved = FALSE;
    redKingMoved = FALSE;
    greyRook1Moved = FALSE;
    redRook1Moved = FALSE;
    greyRook2Moved = FALSE;
    redRook2Moved = FALSE;
    greyKingSquare.posX = 4*100+20;
    greyKingSquare.posY = 7*100+20;
    redKingSquare.posX = 4*100+20;
    redKingSquare.posY = 0*100+20;
    greyQueenSquare.posX = 3*100+20;
    greyQueenSquare.posY = 7*100+20;
    greyQueenSquare.from = map(7, 3);
    greyQueenSquare.to = map(7, 3);
    greyBishop1Square.posX = 2*100+20;
    greyBishop1Square.posY = 7*100+20;
    greyBishop1Square.from = map(7, 2);
    greyBishop1Square.to = map(7, 2);
    greyBishop2Square.posX = 5*100+20;
    greyBishop2Square.posY = 7*100+20;
    greyBishop2Square.from = map(7, 5);
    greyBishop2Square.to = map(7, 5);
    redRook1Rectangle1.posX = 0*100+20;
    redRook1Rectangle1.posY = 0*100+20;
    redRook1Rectangle1.from = map(0, 0);
    redRook1Rectangle1.to = map(0, 0);
    redRook2Rectangle1.posX = 7*100+20;
    redRook2Rectangle1.posY = 0*100+20;
    redRook2Rectangle1.from = map(0, 7);
    redRook2Rectangle1.to = map(0, 7);
    greyRook1Rectangle1.posX = 0*100+20;
    greyRook1Rectangle1.posY = 7*100+20;
    greyRook1Rectangle1.from = map(7, 0);
    greyRook1Rectangle1.to = map(7, 0);
    greyRook2Rectangle1.posX = 7*100+20;
    greyRook2Rectangle1.posY = 7*100+20;
    greyRook2Rectangle1.from = map(7, 7);
    greyRook2Rectangle1.to = map(7, 7);
    greyKnight2Rectangle1.posX = 1*100+20;
    greyKnight2Rectangle1.posY = 7*100+20;
    greyKnight2Rectangle1.from = map(7, 1);
    greyKnight2Rectangle1.to = map(7, 1);
    greyKnight1Rectangle1.posX = 6*100+20;
    greyKnight1Rectangle1.posY = 7*100+20;
    greyKnight1Rectangle1.from = map(7, 6);
    greyKnight1Rectangle1.to = map(7, 6);
    redKnight2Rectangle1.posX = 1*100+20;
    redKnight2Rectangle1.posY = 0*100+20;
    redKnight2Rectangle1.from = map(0, 1);
    redKnight2Rectangle1.to = map(0, 1);
    redKnight1Rectangle1.posX = 6*100+20;
    redKnight1Rectangle1.posY = 0*100+20;
    redKnight1Rectangle1.from = map(0, 6);
    redKnight1Rectangle1.to = map(0, 6);
    redQueenSquare.posX = 3*100+20;
    redQueenSquare.posY = 0*100+20;
    redQueenSquare.from = map(0, 3);
    redQueenSquare.to = map(0, 3);
    for(int p=0; p<8; p++) {
        redQueenSquareK[p].posX = 1200;
    }
    for(int p=0; p<8; p++) {
        greyQueenSquareK[p].posX = 1200;
    }
    redBishop1Square.posX = 2*100+20;
    redBishop1Square.posY = 0*100+20;
    redBishop1Square.from = map(0, 2);
    redBishop1Square.to = map(0, 2);
    redBishop2Square.posX = 5*100+20;
    redBishop2Square.posY = 0*100+20;
    redBishop2Square.from = map(0, 5);
    redBishop2Square.to = map(0, 5);
    redKingSquare.posX = 4*100+20;
    redKingSquare.posY = 0*100+20;
    for(int i=0; i<8; i++) {
        greyPawnsBase[i].posX = i*100+20;
        greyPawnsBase[i].posY = 600+20;
        greyPawnsBase[i].from = map(6, i);
        greyPawnsBase[i].to = map(6, i);
    }
    for(int i=0; i<8; i++) {
        redPawnsBase[i].posX = i*100+20;
        redPawnsBase[i].posY = 100+20;
        redPawnsBase[i].from = map(1, i);
        redPawnsBase[i].to = map(1, i);
    }
    for(int i=0; i<8; i++) {
        redPawnsBase[i].firstTimeMove = TRUE;
    }
    for(int i=0; i<8; i++) {
        greyPawnsBase[i].firstTimeMove = TRUE;
    }
    for(int j=0; j<8; j++) {
        for(int i=0; i<8; i++) {
            boxes[j][i].posX = i*100+20;
            boxes[j][i].posY = j*100+20;
            boxes[j][i].clear = TRUE;
        }
    }
    turn = 'h';
}

boolean checkQueenCheckRed(int j, int i) {

    int a1 = greyQueenSquare.posY;
    int a0 = greyQueenSquare.posX;

    boolean f = FALSE;

    greyQueenSquare.failedpath = FALSE;

    if(redKingSquare.posX == greyQueenSquare.posX) {
        f = moveGreyQueen(0, -666, i, redKingSquare.posY - greyQueenSquare.posY, redKingSquare.posY - greyQueenSquare.posY);
        f = greyQueenSquare.failedpath;
    } else if(redKingSquare.posY == greyQueenSquare.posY) {
        f = moveGreyQueenSide(0, -666, i, redKingSquare.posX - greyQueenSquare.posX, redKingSquare.posX - greyQueenSquare.posX);
        f = greyQueenSquare.failedpath;
    } else if(redKingSquare.posX != greyQueenSquare.posX &&
       redKingSquare.posY != greyQueenSquare.posY) {
        if(redKingSquare.posY - greyQueenSquare.posY == redKingSquare.posX - greyQueenSquare.posX ||
           redKingSquare.posY - greyQueenSquare.posY == -1 * (redKingSquare.posX - greyQueenSquare.posX)) {
            f = moveGreyQueenDiagonally(0, -666, i, redKingSquare.posY - greyQueenSquare.posY, redKingSquare.posX - greyQueenSquare.posX, redKingSquare.posY - greyQueenSquare.posY, redKingSquare.posX - greyQueenSquare.posX);
            f = greyQueenSquare.failedpath;
        } else {
            f = greyQueenSquare.failedpath = TRUE;
        }
    } else {
        f = greyQueenSquare.failedpath = TRUE;
    }

    greyQueenSquare.posY = a1;
    greyQueenSquare.posX = a0;

    if(!f) {
        greyQueenSquare.failedpath = FALSE;
        return TRUE;
    }
    
    greyQueenSquare.failedpath = FALSE;
    return FALSE;
}

boolean checkRookCheckGrey(int j, int i) {

    int a1 = redRook1Rectangle1.posY;
    int a0 = redRook1Rectangle1.posX;

    boolean f = FALSE;

    redRook1Rectangle1.failedpath = FALSE;

    if(greyKingSquare.posX == redRook1Rectangle1.posX) {
        f = moveRedRook1(0, j, i, greyKingSquare.posY - redRook1Rectangle1.posY, greyKingSquare.posY - redRook1Rectangle1.posY);
        f = redRook1Rectangle1.failedpath;
    } else if(greyKingSquare.posY == redRook1Rectangle1.posY) {
        f = moveRedRook1Side(0, j, i, greyKingSquare.posX - redRook1Rectangle1.posX, greyKingSquare.posX - redRook1Rectangle1.posX);
        f = redRook1Rectangle1.failedpath;
    } else {
        f = redRook1Rectangle1.failedpath = TRUE;
    }

    redRook1Rectangle1.posY = a1;
    redRook1Rectangle1.posX = a0;

    a1 = redRook2Rectangle1.posY;
    a0 = redRook2Rectangle1.posX;

    boolean f2 = FALSE;

    redRook2Rectangle1.failedpath = FALSE;

    if(greyKingSquare.posX == redRook2Rectangle1.posX) {
        f2 = moveRedRook2(0, j, i, greyKingSquare.posY - redRook2Rectangle1.posY, greyKingSquare.posY - redRook2Rectangle1.posY);
        f2 = redRook2Rectangle1.failedpath;
    } else if(greyKingSquare.posY == redRook2Rectangle1.posY) {
        f2 = moveRedRook2Side(0, j, i, greyKingSquare.posX - redRook2Rectangle1.posX, greyKingSquare.posX - redRook2Rectangle1.posX);
        f2 = redRook2Rectangle1.failedpath;
    } else {
        f2 = redRook2Rectangle1.failedpath = TRUE;
    }

    redRook2Rectangle1.posY = a1;
    redRook2Rectangle1.posX = a0;

    if(!f || !f2) {
        redRook1Rectangle1.failedpath = FALSE;
        redRook2Rectangle1.failedpath = FALSE;
        return TRUE;
    }
    
    redRook1Rectangle1.failedpath = FALSE;
    redRook2Rectangle1.failedpath = FALSE;
    return FALSE;
}

boolean checkRookCheckRed(int j, int i) {

    int a1 = greyRook1Rectangle1.posY;
    int a0 = greyRook1Rectangle1.posX;

    boolean f = FALSE;

    greyRook1Rectangle1.failedpath = FALSE;

    if(redKingSquare.posX == greyRook1Rectangle1.posX) {
        f = moveGreyRook1(0, j, i, redKingSquare.posY - greyRook1Rectangle1.posY, redKingSquare.posY - greyRook1Rectangle1.posY);
        f = greyRook1Rectangle1.failedpath;
    } else if(redKingSquare.posY == greyRook1Rectangle1.posY) {
        f = moveGreyRook1Side(0, j, i, redKingSquare.posX - greyRook1Rectangle1.posX, redKingSquare.posX - greyRook1Rectangle1.posX);
        f = greyRook1Rectangle1.failedpath;
    } else {
        f = greyRook1Rectangle1.failedpath = TRUE;
    }

    greyRook1Rectangle1.posY = a1;
    greyRook1Rectangle1.posX = a0;

    a1 = greyRook2Rectangle1.posY;
    a0 = greyRook2Rectangle1.posX;

    boolean f2 = FALSE;

    greyRook2Rectangle1.failedpath = FALSE;

    if(redKingSquare.posX == greyRook2Rectangle1.posX) {
        f2 = moveGreyRook2(0, j, i, redKingSquare.posY - greyRook2Rectangle1.posY, redKingSquare.posY - greyRook2Rectangle1.posY);
        f2 = greyRook2Rectangle1.failedpath;
    } else if(redKingSquare.posY == greyRook2Rectangle1.posY) {
        f2 = moveGreyRook2Side(0, j, i, redKingSquare.posX - greyRook2Rectangle1.posX, redKingSquare.posX - greyRook2Rectangle1.posX);
        f2 = greyRook2Rectangle1.failedpath;
    } else {
        f2 = greyRook2Rectangle1.failedpath = TRUE;
    }

    greyRook2Rectangle1.posY = a1;
    greyRook2Rectangle1.posX = a0;

    if(!f || !f2) {
        greyRook1Rectangle1.failedpath = FALSE;
        greyRook2Rectangle1.failedpath = FALSE;
        return TRUE;
    }
    
    greyRook1Rectangle1.failedpath = FALSE;
    greyRook2Rectangle1.failedpath = FALSE;
    return FALSE;
}

boolean checkQueenCheckGrey(int j, int i) {

    int a1 = redQueenSquare.posY;
    int a0 = redQueenSquare.posX;

    boolean f = FALSE;

    redQueenSquare.failedpath = FALSE;

    if(greyKingSquare.posX == redQueenSquare.posX) {
        f = moveRedQueen(0, -666, i, greyKingSquare.posY - redQueenSquare.posY, greyKingSquare.posY - redQueenSquare.posY);
        f = redQueenSquare.failedpath;
        if(greyKingSquare.posY - redQueenSquare.posY == 0) {
            f = redQueenSquare.failedpath = TRUE;
        }
    } else if(greyKingSquare.posY == redQueenSquare.posY) {
        f = moveRedQueenSide(0, -666, i, greyKingSquare.posX - redQueenSquare.posX, greyKingSquare.posX - redQueenSquare.posX);
        f = redQueenSquare.failedpath;
    } else if(greyKingSquare.posX != redQueenSquare.posX &&
       greyKingSquare.posY != redQueenSquare.posY) {
        if(greyKingSquare.posY - redQueenSquare.posY == greyKingSquare.posX - redQueenSquare.posX ||
           greyKingSquare.posY - redQueenSquare.posY == -1 * (greyKingSquare.posX - redQueenSquare.posX)) {
            f = moveRedQueenDiagonally(0, -666, i, greyKingSquare.posY - redQueenSquare.posY, greyKingSquare.posX - redQueenSquare.posX, greyKingSquare.posY - redQueenSquare.posY, greyKingSquare.posX - redQueenSquare.posX);
            f = redQueenSquare.failedpath;
        } else {
            f = redQueenSquare.failedpath = TRUE;
        }
    } else {
        f = redQueenSquare.failedpath = TRUE;
    }

    redQueenSquare.posY = a1;
    redQueenSquare.posX = a0;

    if(!f) {
        redQueenSquare.failedpath = FALSE;
        return TRUE;
    }
    
    redQueenSquare.failedpath = FALSE;
    return FALSE;
}

boolean checkQueenCheckGreyK(int j, int i) {

  for(int z=0; z<8; z++) {
  
        int a1 = redQueenSquareK[z].posY;
        int a0 = redQueenSquareK[z].posX;

        if(redQueenSquareK[z].posX > 800)
            continue;

        boolean f = FALSE;

        redQueenSquareK[z].failedpath = FALSE;

        if(greyKingSquare.posX == redQueenSquareK[z].posX) {
            f = moveRedQueenK(0, -666, i, greyKingSquare.posY - redQueenSquareK[z].posY, greyKingSquare.posY - redQueenSquareK[z].posY, z);
            f = redQueenSquareK[z].failedpath;
        } else if(greyKingSquare.posY == redQueenSquareK[z].posY) {
            f = moveRedQueenSideK(0, -666, i, greyKingSquare.posX - redQueenSquareK[z].posX, greyKingSquare.posX - redQueenSquareK[z].posX, z);
            f = redQueenSquareK[z].failedpath;
        } else if(greyKingSquare.posX != redQueenSquareK[z].posX &&
           greyKingSquare.posY != redQueenSquareK[z].posY) {
            if(greyKingSquare.posY - redQueenSquareK[z].posY == greyKingSquare.posX - redQueenSquareK[z].posX ||
               greyKingSquare.posY - redQueenSquareK[z].posY == -1 * (greyKingSquare.posX - redQueenSquareK[z].posX)) {
                f = moveRedQueenDiagonallyK(0, -666, i, greyKingSquare.posY - redQueenSquareK[z].posY, greyKingSquare.posX - redQueenSquareK[z].posX, greyKingSquare.posY - redQueenSquareK[z].posY, greyKingSquare.posX - redQueenSquareK[z].posX, z);
                f = redQueenSquareK[z].failedpath;
            } else {
                f = redQueenSquareK[z].failedpath = TRUE;
            }
        } else {
            f = redQueenSquareK[z].failedpath = TRUE;
        }

        redQueenSquareK[z].posY = a1;
        redQueenSquareK[z].posX = a0;

        if(!f) {
            redQueenSquareK[z].failedpath = FALSE;
            return TRUE;
        }

        redQueenSquareK[z].failedpath = FALSE;
    }

    return FALSE;
}

boolean checkQueenCheckRedK(int j, int i) {

    for(int z=0; z<8; z++) {
  
        int a1 = greyQueenSquareK[z].posY;
        int a0 = greyQueenSquareK[z].posX;

        if(greyQueenSquareK[z].posX > 800)
            continue;
        
        boolean f = FALSE;

        greyQueenSquareK[z].failedpath = FALSE;

        if(redKingSquare.posX == greyQueenSquareK[z].posX) {
            f = moveGreyQueenK(0, -666, i, redKingSquare.posY - greyQueenSquareK[z].posY, redKingSquare.posY - greyQueenSquareK[z].posY, z);
            f = greyQueenSquareK[z].failedpath;
        } else if(redKingSquare.posY == greyQueenSquareK[z].posY) {
            f = moveGreyQueenSideK(0, -666, i, redKingSquare.posX - greyQueenSquareK[z].posX, redKingSquare.posX - greyQueenSquareK[z].posX, z);
            f = greyQueenSquareK[z].failedpath;
        } else if(redKingSquare.posX != greyQueenSquareK[z].posX &&
           redKingSquare.posY != greyQueenSquareK[z].posY) {
            if(redKingSquare.posY - greyQueenSquareK[z].posY == redKingSquare.posX - greyQueenSquareK[z].posX ||
               redKingSquare.posY - greyQueenSquareK[z].posY == -1 * (redKingSquare.posX - greyQueenSquareK[z].posX)) {
                f = moveGreyQueenDiagonallyK(0, -666, i, redKingSquare.posY - greyQueenSquareK[z].posY, redKingSquare.posX - greyQueenSquareK[z].posX, redKingSquare.posY - greyQueenSquareK[z].posY, redKingSquare.posX - greyQueenSquareK[z].posX, z);
                f = greyQueenSquareK[z].failedpath;
            } else {
                f = greyQueenSquareK[z].failedpath = TRUE;
            }
        } else {
            f = greyQueenSquareK[z].failedpath = TRUE;
        }

        greyQueenSquareK[z].posY = a1;
        greyQueenSquareK[z].posX = a0;

        if(!f) {
            greyQueenSquareK[z].failedpath = FALSE;
            return TRUE;
        }

        greyQueenSquareK[z].failedpath = FALSE;
    }

    return FALSE;
}

boolean checkBishopCheckRed(int j, int i) {

    int a1 = greyBishop1Square.posY;
    int a0 = greyBishop1Square.posX;

    boolean f = FALSE;

    greyBishop1Square.failedpath = FALSE;

    if(redKingSquare.posX != greyBishop1Square.posX &&
       redKingSquare.posY != greyBishop1Square.posY) {
        f = moveGreyBishop1(0, -666, i, redKingSquare.posY - greyBishop1Square.posY, redKingSquare.posX - greyBishop1Square.posX, redKingSquare.posY - greyBishop1Square.posY, redKingSquare.posX - greyBishop1Square.posX);
        f = greyBishop1Square.failedpath;
    } else {
        f = greyBishop1Square.failedpath = TRUE;
    }

    greyBishop1Square.posY = a1;
    greyBishop1Square.posX = a0;

    a1 = greyBishop2Square.posY;
    a0 = greyBishop2Square.posX;

    boolean f2 = FALSE;
    
    greyBishop2Square.failedpath = FALSE;

    if(redKingSquare.posX != greyBishop2Square.posX &&
       redKingSquare.posY != greyBishop2Square.posY) {
        f2 = moveGreyBishop2(0, -666, i, redKingSquare.posY - greyBishop2Square.posY, redKingSquare.posX - greyBishop2Square.posX, redKingSquare.posY - greyBishop2Square.posY, redKingSquare.posX - greyBishop2Square.posX);
        f2 = greyBishop2Square.failedpath;
    } else {
        f2 = greyBishop2Square.failedpath = TRUE;
    }

    greyBishop2Square.posY = a1;
    greyBishop2Square.posX = a0;

    if(!f || !f2) {
        greyBishop1Square.failedpath = FALSE;
        greyBishop2Square.failedpath = FALSE;
        return TRUE;
    }
    
    greyBishop1Square.failedpath = FALSE;
    greyBishop2Square.failedpath = FALSE;
    return FALSE;
}

boolean checkBishopCheckGrey(int j, int i) {

    int a1 = redBishop1Square.posY;
    int a0 = redBishop1Square.posX;

    boolean f = FALSE;

    redBishop1Square.failedpath = FALSE;

    if(greyKingSquare.posX != redBishop1Square.posX &&
       greyKingSquare.posY != redBishop1Square.posY) {
        f = moveRedBishop1(0, -666, i, greyKingSquare.posY - redBishop1Square.posY, greyKingSquare.posX - redBishop1Square.posX, greyKingSquare.posY - redBishop1Square.posY, greyKingSquare.posX - redBishop1Square.posX);
        f = redBishop1Square.failedpath;
    } else {
        f = redBishop1Square.failedpath = TRUE;
    }

    redBishop1Square.posY = a1;
    redBishop1Square.posX = a0;

    a1 = redBishop2Square.posY;
    a0 = redBishop2Square.posX;

    boolean f2 = FALSE;
    
    redBishop2Square.failedpath = FALSE;

    if(greyKingSquare.posX != redBishop2Square.posX &&
       greyKingSquare.posY != redBishop2Square.posY) {
        f2 = moveRedBishop2(0, -666, i, greyKingSquare.posY - redBishop2Square.posY, greyKingSquare.posX - redBishop2Square.posX, greyKingSquare.posY - redBishop2Square.posY, greyKingSquare.posX - redBishop2Square.posX);
        f2 = redBishop2Square.failedpath;
    } else {
        f2 = redBishop2Square.failedpath = TRUE;
    }

    redBishop2Square.posY = a1;
    redBishop2Square.posX = a0;

    if(!f || !f2) {
        redBishop1Square.failedpath = FALSE;
        redBishop2Square.failedpath = FALSE;
        return TRUE;
    }
    
    redBishop1Square.failedpath = FALSE;
    redBishop2Square.failedpath = FALSE;
    return FALSE;
}

boolean checkKnightCheckGrey(int j, int i) {

    if(greyKnight1Rectangle1.posX == redKnight1Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redKnight1Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight2Rectangle1.posX == redKnight2Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redKnight2Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight1Rectangle1.posX == redKnight2Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redKnight2Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight2Rectangle1.posX == redKnight1Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redKnight1Rectangle1.posY) {
        return FALSE;
    }
    if(redKnight1Rectangle1.posX - 100 == greyKingSquare.posX &&
       redKnight1Rectangle1.posY - 200 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX - 200 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY - 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX - 200 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY + 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX - 100 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY + 200 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX + 100 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY + 200 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX + 200 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY + 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX + 200 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY - 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight1Rectangle1.posX + 100 == greyKingSquare.posX &&
              redKnight1Rectangle1.posY - 200 == greyKingSquare.posY) {
        return TRUE;
    }
    if(redKnight2Rectangle1.posX - 100 == greyKingSquare.posX &&
       redKnight2Rectangle1.posY - 200 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX - 200 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY - 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX - 200 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY + 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX - 100 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY + 200 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX + 100 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY + 200 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX + 200 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY + 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX + 200 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY - 100 == greyKingSquare.posY) {
        return TRUE;
    } else if(redKnight2Rectangle1.posX + 100 == greyKingSquare.posX &&
              redKnight2Rectangle1.posY - 200 == greyKingSquare.posY) {
        return TRUE;
    }
    return FALSE;
}

boolean checkPawnsCheckGrey(int j, int i) {
    
    for(int t=0; t<8; t++) {
        if(redPawnsBase[t].posX + 100 == greyKingSquare.posX &&
           redPawnsBase[t].posY + 100 == greyKingSquare.posY) {
            return TRUE;
        }

        if(redPawnsBase[t].posX - 100 == greyKingSquare.posX &&
           redPawnsBase[t].posY + 100 == greyKingSquare.posY) {
            return TRUE;
        }
    }
    return FALSE;
}

boolean checkPawnsCheckRed(int j, int i) {
    
    for(int t=0; t<8; t++) {
        if(greyPawnsBase[t].posX + 100 == redKingSquare.posX &&
           greyPawnsBase[t].posY - 100 == redKingSquare.posY) {
            return TRUE;
        }
        if(greyPawnsBase[t].posX - 100 == redKingSquare.posX &&
           greyPawnsBase[t].posY - 100 == redKingSquare.posY) {
            return TRUE;
        }
    }
    return FALSE;
}

boolean checkKnightCheckRed(int j, int i) {
    
    if(greyKnight1Rectangle1.posX == redKnight1Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redKnight1Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight2Rectangle1.posX == redKnight2Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redKnight2Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight1Rectangle1.posX == redKnight2Rectangle1.posX &&
       greyKnight1Rectangle1.posY == redKnight2Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight2Rectangle1.posX == redKnight1Rectangle1.posX &&
       greyKnight2Rectangle1.posY == redKnight1Rectangle1.posY) {
        return FALSE;
    }
    if(greyKnight1Rectangle1.posX - 100 == redKingSquare.posX &&
       greyKnight1Rectangle1.posY - 200 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX - 200 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY - 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX - 200 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY + 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX - 100 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY + 200 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX + 100 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY + 200 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX + 200 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY + 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX + 200 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY - 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight1Rectangle1.posX + 100 == redKingSquare.posX &&
              greyKnight1Rectangle1.posY - 200 == redKingSquare.posY) {
        return TRUE;
    }
    if(greyKnight2Rectangle1.posX - 100 == redKingSquare.posX &&
       greyKnight2Rectangle1.posY - 200 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX - 200 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY - 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX - 200 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY + 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX - 100 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY + 200 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX + 100 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY + 200 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX + 200 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY + 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX + 200 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY - 100 == redKingSquare.posY) {
        return TRUE;
    } else if(greyKnight2Rectangle1.posX + 100 == redKingSquare.posX &&
              greyKnight2Rectangle1.posY - 200 == redKingSquare.posY) {
        return TRUE;
    }
    return FALSE;
}

boolean checkCheckGrey(int j, int i) {
    if(checkKnightCheckGrey(j, i) ||
       checkBishopCheckGrey(j, i) ||
       checkQueenCheckGrey(j, i) ||
       checkQueenCheckGreyK(j, i) ||
       checkRookCheckGrey(j, i) ||
       checkPawnsCheckGrey(j, i)) {
        return TRUE;
    }
    return FALSE;
}

boolean checkCheckRed(int j, int i) {
    if(checkKnightCheckRed(j, i) ||
       checkBishopCheckRed(j, i) ||
       checkQueenCheckRed(j, i) ||
       checkQueenCheckRedK(j, i) ||
       checkRookCheckRed(j, i) ||
       checkPawnsCheckRed(j, i)) {
        return TRUE;
    }
    return FALSE;
}

int GetTextSize(LPSTR a0) {
    for(int iLoopCounter = 0;;iLoopCounter++) {
        if(a0[iLoopCounter] == '\0') {
            return iLoopCounter;
        }
    }
}

void DisableMaximizeMinimizeButton(HWND hwnd) {
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_PAINT:
        {
            if(deathed == -1) {

                hdc = BeginPaint(hwnd, &ps);
                hdcMem = CreateCompatibleDC(hdc);
                
                oldBitmap = SelectObject(hdcMem, hBitmap);

                GetObject(hBitmap, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 0, 0, 1170, 950, hdcMem, 0, 0, SRCCOPY);

                SelectObject(hdcMem, oldBitmap);
                DeleteDC(hdcMem); DeleteObject(hBitmap);

                EndPaint(hwnd, &ps);

                hdc = GetDC(hwnd);
                
                deathed = 0;
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
                if(((greyRook1Rectangle1.posX/100)+(greyRook1Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(rookWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(rookWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyRook1Rectangle1.posX+25+7, greyRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyRook2Rectangle1.posX/100)+(greyRook2Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(rook2White,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(rook2White,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyRook2Rectangle1.posX+25+7, greyRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyKnight1Rectangle1.posX/100)+(greyKnight1Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(knightWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(knightWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyKnight1Rectangle1.posX+25+7, greyKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyKnight2Rectangle1.posX/100)+(greyKnight2Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(knight2White,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(knight2White,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyKnight2Rectangle1.posX+25+7, greyKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyBishop1Square.posX/100)+(greyBishop1Square.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(bishopWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(bishopWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyBishop1Square.posX+25+7, greyBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyBishop2Square.posX/100)+(greyBishop2Square.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(bishop2White,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(bishop2White,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyBishop2Square.posX+25+7, greyBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyQueenSquare.posX/100)+(greyQueenSquare.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyQueenSquare.posX+25+7, greyQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((greyKingSquare.posX/100)+(greyKingSquare.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(kingWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(kingWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyKingSquare.posX+25+7, greyKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                for(int o=0; o<8; o++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((greyPawnsBase[o].posX/100)+(greyPawnsBase[o].posY/100)) % 2 == 0)
                        hBmp = ReplaceColor(pawnWhite,0x110000,0xe1f4fc,hdcMem);
                    else
                        hBmp = ReplaceColor(pawnWhite,0x110000,0x377105,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, greyPawnsBase[o].posX+25+7, greyPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }

                hdcMem = CreateCompatibleDC(hdc);
                if(((redRook1Rectangle1.posX/100)+(redRook1Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(rookBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redRook1Rectangle1.posX+25+7, redRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redRook2Rectangle1.posX/100)+(redRook2Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(rook2Black,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redRook2Rectangle1.posX+25+7, redRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redKnight1Rectangle1.posX/100)+(redKnight1Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(knightBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(knightBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redKnight1Rectangle1.posX+25+7, redKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redKnight2Rectangle1.posX/100)+(redKnight2Rectangle1.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(knight2Black,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(knight2Black,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redKnight2Rectangle1.posX+25+7, redKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redBishop1Square.posX/100)+(redBishop1Square.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(bishopBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(bishopBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redBishop1Square.posX+25+7, redBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redBishop2Square.posX/100)+(redBishop2Square.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(bishop2Black,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(bishop2Black,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redBishop2Square.posX+25+7, redBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redQueenSquare.posX/100)+(redQueenSquare.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redQueenSquare.posX+25+7, redQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                hdcMem = CreateCompatibleDC(hdc);
                if(((redKingSquare.posX/100)+(redKingSquare.posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(kingBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(kingBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redKingSquare.posX+25+7, redKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                for(int o=0; o<8; o++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((redPawnsBase[o].posX/100)+(redPawnsBase[o].posY/100)) % 2 == 0)
                        hBmp = ReplaceColor(pawnBlack,0x110000,0xe1f4fc,hdcMem);
                    else
                        hBmp = ReplaceColor(pawnBlack,0x110000,0x377105,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, redPawnsBase[o].posX+25+7, redPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }

                for(int m=0; m<8; m++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((greyQueenSquareK[m].posX/100)+(greyQueenSquareK[m].posY/100)) % 2 == 0)
                        hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
                    else
                        hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, greyQueenSquareK[m].posX+25+7, greyQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                }

                for(int m=0; m<8; m++) {
                    hdcMem = CreateCompatibleDC(hdc);
                    if(((redQueenSquareK[m].posX/100)+(redQueenSquareK[m].posY/100)) % 2 == 0)
                        hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
                    else
                        hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, redQueenSquareK[m].posX+25+7, redQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
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

            HBRUSH white_brush = CreateSolidBrush(RGB(255,200,200));
            RECT rrect = {820+50, 20, 1120, 810};
            FillRect(hdc, &rrect, white_brush);
            DeleteObject(white_brush);

            if(greyRook1Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rookWhite_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyRook1Rectangle1.from != NULL && greyRook1Rectangle1.to != NULL) {
                    if(strlen(greyRook1Rectangle1.from) >= 2 && strlen(greyRook1Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyRook1Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyRook2Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rook2White_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyRook2Rectangle1.from != NULL && greyRook2Rectangle1.to != NULL) {
                    if(strlen(greyRook2Rectangle1.from) >= 2 && strlen(greyRook2Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyRook2Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyKnight1Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knightWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyKnight1Rectangle1.from != NULL && greyKnight1Rectangle1.to != NULL) {
                    if(strlen(greyKnight1Rectangle1.from) >= 2 && strlen(greyKnight1Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyKnight1Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyKnight2Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knight2White_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyKnight2Rectangle1.from != NULL && greyKnight2Rectangle1.to != NULL) {
                    if(strlen(greyKnight2Rectangle1.from) >= 2 && strlen(greyKnight2Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyKnight2Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyBishop1Square.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishopWhite_s,0x4cb122,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyBishop1Square.from != NULL && greyBishop1Square.to != NULL) {
                    if(strlen(greyBishop1Square.from) >= 2 && strlen(greyBishop1Square.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyBishop1Square.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyBishop2Square.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishop2White_s,0x4cb122,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyBishop2Square.from != NULL && greyBishop2Square.to != NULL) {
                    if(strlen(greyBishop2Square.from) >= 2 && strlen(greyBishop2Square.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyBishop2Square.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyQueenSquare.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(greyQueenSquare.from != NULL && greyQueenSquare.to != NULL) {
                    if(strlen(greyQueenSquare.from) >= 2 && strlen(greyQueenSquare.to) >= 2) {
                        TextOut(hdc,
                                855+50,
                                _y_,
                                greyQueenSquare.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(greyKingSquare.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(kingWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            for(int o=0; o<8; o++) {
                if(greyPawnsBase[o].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(pawnWhite_s,0x000000,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(greyPawnsBase[o].from != NULL && greyPawnsBase[o].to != NULL) {
                        if(strlen(greyPawnsBase[o].from) >= 2 && strlen(greyPawnsBase[o].to) >= 2) {
                            TextOut(hdc,
                                    855+50,
                                    _y_,
                                    greyPawnsBase[o].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            for(int m=0; m<8; m++) {
                if(greyQueenSquareK[m].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(greyQueenSquareK[m].from != NULL && greyQueenSquareK[m].to != NULL) {
                        if(strlen(greyQueenSquareK[m].from) >= 2 && strlen(greyQueenSquareK[m].to) >= 2) {
                            TextOut(hdc,
                                    855+50,
                                    _y_,
                                    greyQueenSquareK[m].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            _y_ = 20;

            if(redRook1Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rookBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redRook1Rectangle1.from != NULL && redRook1Rectangle1.to != NULL) {
                    if(strlen(redRook1Rectangle1.from) >= 2 && strlen(redRook1Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redRook1Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redRook2Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(rook2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redRook2Rectangle1.from != NULL && redRook2Rectangle1.to != NULL) {
                    if(strlen(redRook2Rectangle1.from) >= 2 && strlen(redRook2Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redRook2Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redKnight1Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knightBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redKnight1Rectangle1.from != NULL && redKnight1Rectangle1.to != NULL) {
                    if(strlen(redKnight1Rectangle1.from) >= 2 && strlen(redKnight1Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redKnight1Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redKnight2Rectangle1.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(knight2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redKnight2Rectangle1.from != NULL && redKnight2Rectangle1.to != NULL) {
                    if(strlen(redKnight2Rectangle1.from) >= 2 && strlen(redKnight2Rectangle1.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redKnight2Rectangle1.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redBishop1Square.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishopBlack_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redBishop1Square.from != NULL && redBishop1Square.to != NULL) {
                    if(strlen(redBishop1Square.from) >= 2 && strlen(redBishop1Square.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redBishop1Square.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redBishop2Square.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(bishop2Black_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redBishop2Square.from != NULL && redBishop2Square.to != NULL) {
                    if(strlen(redBishop2Square.from) >= 2 && strlen(redBishop2Square.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redBishop2Square.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redQueenSquare.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                if(redQueenSquare.from != NULL && redQueenSquare.to != NULL) {
                    if(strlen(redQueenSquare.from) >= 2 && strlen(redQueenSquare.to) >= 2) {
                        TextOut(hdc,
                                930+50,
                                _y_,
                                redQueenSquare.to,
                                GetTextSize("za"));
                    }
                }
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            if(redKingSquare.posX == 1300) {
                hdcMem = CreateCompatibleDC(hdc);
                HBITMAP hBmp = ReplaceColor(kingBlack_s,0xff0000,0xc8c8ff,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                _y_ += 31;
            }

            for(int o=0; o<8; o++) {
                if(redPawnsBase[o].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(pawnBlack_s,0xff0000,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(redPawnsBase[o].from != NULL && redPawnsBase[o].to != NULL) {
                        if(strlen(redPawnsBase[o].from) >= 2 && strlen(redPawnsBase[o].to) >= 2) {
                            TextOut(hdc,
                                    930+50,
                                    _y_,
                                    redPawnsBase[o].to,
                                    GetTextSize("za"));
                        }
                    }
                    SelectObject(hdcMem, oldBitmap);
                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                    _y_ += 31;
                }
            }

            for(int m=0; m<8; m++) {
                if(redQueenSquareK[m].posX == 1300) {
                    hdcMem = CreateCompatibleDC(hdc);
                    HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                    oldBitmap = SelectObject(hdcMem, hBmp);
                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                    if(redQueenSquareK[m].from != NULL && redQueenSquareK[m].to != NULL) {
                        if(strlen(redQueenSquareK[m].from) >= 2 && strlen(redQueenSquareK[m].to) >= 2) {
                            TextOut(hdc,
                                    930+50,
                                    _y_,
                                    redQueenSquareK[m].to,
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
            if(((greyRook1Rectangle1.posX/100)+(greyRook1Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(rookWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(rookWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyRook1Rectangle1.posX+25+7, greyRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((greyRook2Rectangle1.posX/100)+(greyRook2Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(rook2White,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(rook2White,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyRook2Rectangle1.posX+25+7, greyRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((greyKnight1Rectangle1.posX/100)+(greyKnight1Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(knightWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(knightWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyKnight1Rectangle1.posX+25+7, greyKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((greyKnight2Rectangle1.posX/100)+(greyKnight2Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(knight2White,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(knight2White,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyKnight2Rectangle1.posX+25+7, greyKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((greyBishop1Square.posX/100)+(greyBishop1Square.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(bishopWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(bishopWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyBishop1Square.posX+25+7, greyBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((greyBishop2Square.posX/100)+(greyBishop2Square.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(bishop2White,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(bishop2White,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyBishop2Square.posX+25+7, greyBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((greyQueenSquare.posX/100)+(greyQueenSquare.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyQueenSquare.posX+25+7, greyQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            
            hdcMem = CreateCompatibleDC(hdc);
            if(((greyKingSquare.posX/100)+(greyKingSquare.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(kingWhite,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(kingWhite,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, greyKingSquare.posX+25+7, greyKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            for(int o=0; o<8; o++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((greyPawnsBase[o].posX/100)+(greyPawnsBase[o].posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(pawnWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(pawnWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyPawnsBase[o].posX+25+7, greyPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }

            hdcMem = CreateCompatibleDC(hdc);
            if(((redRook1Rectangle1.posX/100)+(redRook1Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(rookBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redRook1Rectangle1.posX+25+7, redRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((redRook2Rectangle1.posX/100)+(redRook2Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(rook2Black,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(rook2Black,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redRook2Rectangle1.posX+25+7, redRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((redKnight1Rectangle1.posX/100)+(redKnight1Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(knightBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(knightBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redKnight1Rectangle1.posX+25+7, redKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((redKnight2Rectangle1.posX/100)+(redKnight2Rectangle1.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(knight2Black,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(knight2Black,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redKnight2Rectangle1.posX+25+7, redKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((redBishop1Square.posX/100)+(redBishop1Square.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(bishopBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(bishopBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redBishop1Square.posX+25+7, redBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((redBishop2Square.posX/100)+(redBishop2Square.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(bishop2Black,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(bishop2Black,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redBishop2Square.posX+25+7, redBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            hdcMem = CreateCompatibleDC(hdc);
            if(((redQueenSquare.posX/100)+(redQueenSquare.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redQueenSquare.posX+25+7, redQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            
            hdcMem = CreateCompatibleDC(hdc);
            if(((redKingSquare.posX/100)+(redKingSquare.posY/100)) % 2 == 0)
                hBmp = ReplaceColor(kingBlack,0x110000,0xe1f4fc,hdcMem);
            else
                hBmp = ReplaceColor(kingBlack,0x110000,0x377105,hdcMem);
            oldBitmap = SelectObject(hdcMem, hBmp);
            GetObject(hBmp, sizeof(bitmap), &bitmap);
            BitBlt(hdc, redKingSquare.posX+25+7, redKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

            for(int o=0; o<8; o++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((redPawnsBase[o].posX/100)+(redPawnsBase[o].posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(pawnBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(pawnBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redPawnsBase[o].posX+25+7, redPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }

            for(int m=0; m<8; m++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((greyQueenSquareK[m].posX/100)+(greyQueenSquareK[m].posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, greyQueenSquareK[m].posX+25+7, greyQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                SelectObject(hdcMem, oldBitmap);
                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
            }

            //draw grey queen
            for(int m=0; m<8; m++) {
                hdcMem = CreateCompatibleDC(hdc);
                if(((redQueenSquareK[m].posX/100)+(redQueenSquareK[m].posY/100)) % 2 == 0)
                    hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
                else
                    hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
                oldBitmap = SelectObject(hdcMem, hBmp);
                GetObject(hBmp, sizeof(bitmap), &bitmap);
                BitBlt(hdc, redQueenSquareK[m].posX+25+7, redQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
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
                    if(iPosX >= i*100+20+20 &&
                       iPosY >= j*100+20+20 &&
                       iPosX < i*100+20+20+100 &&
                       iPosY < j*100+20+20+100) {
                        
                        for(int k=0; k<8; k++) {
                            for(int l=0; l<8; l++) {
                                boxes[k][l].clicked = FALSE;
                            }
                        }
                        boxes[j][i].clicked = TRUE;

                        if(turn == 'h') {
                            
                            for(int k=0; k<8; k++) {
                            
                                if(greyPawnsBase[k].posX == i*100+20 &&
                                   greyPawnsBase[k].posY == j*100+20) {

                                    clickedOne = 'g';
                                    greyPawnsBase[k].clicked = TRUE;
                                    greyPawnsBase[k].from = map(j, i);
                                    from = map(j, i);
                                    turn = 'h';
                                    
                                    strncpy(chosenPiece, "pw", 2);

                                    for(int l=0; l<8; l++) {
                                        redPawnsBase[l].clicked = FALSE;
                                    }

                                    for(int l=0; l<8; l++) {
                                        if(l != k) {
                                            greyPawnsBase[l].clicked = FALSE;
                                        }
                                    }
                                } else {
                                    if(greyPawnsBase[k].clicked == TRUE) {
                                        greyPawnsBase[k].to = map(j, i);
                                        to = map(j, i);
                                    }
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(clickedOne == 'g' &&
                                       greyPawnsBase[k].clicked == TRUE && 
                                       greyPawnsBase[k].firstTimeMove == TRUE) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

                                        for(int m=0; m<8; m++) {
                                            if(greyPawnsBase[m].posY == greyPawnsBase[k].posY - 100 &&
                                               (greyPawnsBase[m].posX == greyPawnsBase[k].posX + 100 || greyPawnsBase[m].posX == greyPawnsBase[k].posX - 100)) {
                                                ff = TRUE;
                                            }
                                            if(greyPawnsBase[m].posY == greyPawnsBase[k].posY - 100 &&
                                               greyPawnsBase[m].posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyPawnsBase[m].posY == greyPawnsBase[k].posY - 100 &&
                                               greyPawnsBase[m].posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop1Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop1Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop2Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop2Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop1Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop1Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop2Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop2Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                        }
                                        
                                        if(!ff &&
                                           j*100+20 == greyPawnsBase[k].posY - 100 &&
                                          (i*100+20 == greyPawnsBase[k].posX + 100 ||
                                           i*100+20 == greyPawnsBase[k].posX - 100)) {

                                            turn = 'r';

                                            boolean ate = FALSE;
                                            
                                            int a0 = greyPawnsBase[k].posX;
                                            int a1 = greyPawnsBase[k].posY;

                                            boxes[j][i].clear = FALSE;
                                            boxes[greyPawnsBase[k].posY/100][greyPawnsBase[k].posX/100].clear = TRUE;
                                            greyPawnsBase[k].posY = j*100+20;
                                            greyPawnsBase[k].posX = i*100+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if(redPawnsBase[l].posX == i*100+20 &&
                                                   redPawnsBase[l].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(redQueenSquareK[z].posX == i*100+20 &&
                                                   redQueenSquareK[z].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(redQueenSquare.posX == i*100+20 &&
                                               redQueenSquare.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redBishop1Square.posX == i*100+20 &&
                                               redBishop1Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redBishop2Square.posX == i*100+20 &&
                                               redBishop2Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redKnight1Rectangle1.posX == i*100+20 &&
                                               redKnight1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redKnight2Rectangle1.posX == i*100+20 &&
                                               redKnight2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redRook1Rectangle1.posX == i*100+20 &&
                                               redRook1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redRook2Rectangle1.posX == i*100+20 &&
                                               redRook2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(redPawnsBase[u].posX == greyPawnsBase[k].posX &&
                                                   redPawnsBase[u].posY == greyPawnsBase[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckGrey(j, i);

                                            if(ffff && fff) {
                                                greyPawnsBase[k].posX = a0;
                                                greyPawnsBase[k].posY = a1;

                                                turn = 'h';

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if(redPawnsBase[l].posX == i*100+20 &&
                                                       redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyPawnsBase[k].posX &&
                                                       redPawnsBase[u].posY == greyPawnsBase[k].posY) {
                                                        redPawnsBase[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    greyPawnsBase[k].firstTimeMove = FALSE;

                                                    greyPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                } else {
                                                    greyPawnsBase[k].posX = a0;
                                                    greyPawnsBase[k].posY = a1;

                                                    turn = 'h';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                                j*100+20 == greyPawnsBase[k].posY - 100 &&
                                                i*100+20 == greyPawnsBase[k].posX) {

                                            turn = 'r';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(greyPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY + 100 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY + 100 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = greyPawnsBase[k].posX;
                                                int a1 = greyPawnsBase[k].posY;
                                                
                                                boxes[j][i].clear = FALSE;
                                                boxes[greyPawnsBase[k].posY/100][greyPawnsBase[k].posX/100].clear = TRUE;

                                                greyPawnsBase[k].posY = j*100+20;

                                                boolean ffff = checkCheckGrey(j, i);
                                                
                                                if(ffff) {
                                                    greyPawnsBase[k].posX = a0;
                                                    greyPawnsBase[k].posY = a1;

                                                    turn = 'h';
                                                } else {
                                                    greyPawnsBase[k].firstTimeMove = FALSE;

                                                    greyPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            } else {
                                                turn = 'h';
                                            }
                                        }

                                        else if(!fail &&
                                                j*100+20 == greyPawnsBase[k].posY - 200 &&
                                                i*100+20 == greyPawnsBase[k].posX) {

                                            turn = 'r';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(greyPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY + 100 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(greyPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY + 200 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY + 100 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY + 200 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = greyPawnsBase[k].posX;
                                                int a1 = greyPawnsBase[k].posY;
                                                
                                                greyPawnsBase[k].posX = a0;
                                                greyPawnsBase[k].posY = a1;

                                                boxes[j][i].clear = FALSE;
                                                boxes[greyPawnsBase[k].posY/100][greyPawnsBase[k].posX/100].clear = TRUE;

                                                greyPawnsBase[k].posY = j*100+20;

                                                boolean ffff = checkCheckGrey(j, i);
                                                
                                                if(ffff) {

                                                    greyPawnsBase[k].posX = a0;
                                                    greyPawnsBase[k].posY = a1;

                                                    turn = 'h';
                                                } else {
                                                    greyPawnsBase[k].firstTimeMove = FALSE;

                                                    greyPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }                       
                                            } else {
                                                turn = 'h';
                                            }
                                        }

                                    } else if(clickedOne == 'g' &&
                                              greyPawnsBase[k].clicked) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

                                        for(int m=0; m<8; m++) {
                                            if(greyPawnsBase[m].posY == greyPawnsBase[k].posY - 100 &&
                                               (greyPawnsBase[m].posX == greyPawnsBase[k].posX + 100 || greyPawnsBase[m].posX == greyPawnsBase[k].posX - 100)) {
                                                ff = TRUE;
                                            }
                                            if(greyPawnsBase[m].posY == greyPawnsBase[k].posY - 100 &&
                                               greyPawnsBase[m].posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyPawnsBase[m].posY == greyPawnsBase[k].posY - 100 &&
                                               greyPawnsBase[m].posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop1Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop1Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop2Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop2Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyKnight2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop1Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop1Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop2Square.posY == greyPawnsBase[k].posY - 100 &&
                                               greyBishop2Square.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook1Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook1Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook2Rectangle1.posY == greyPawnsBase[k].posY - 100 &&
                                               greyRook2Rectangle1.posX == greyPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                        }
                                        
                                        if(!ff &&
                                           j*100+20 == greyPawnsBase[k].posY - 100 &&
                                          (i*100+20 == greyPawnsBase[k].posX - 100 ||
                                           i*100+20 == greyPawnsBase[k].posX + 100)) {

                                            turn = 'r';

                                            boolean ate = FALSE;

                                            int a0 = greyPawnsBase[k].posX;
                                            int a1 = greyPawnsBase[k].posY;

                                            boxes[j][i].clear = FALSE;
                                            boxes[greyPawnsBase[k].posY/100][greyPawnsBase[k].posX/100].clear = TRUE;

                                            greyPawnsBase[k].posY = j*100+20;
                                            greyPawnsBase[k].posX = i*100+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if(redPawnsBase[l].posX == i*100+20 &&
                                                   redPawnsBase[l].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(redQueenSquareK[z].posX == i*100+20 &&
                                                   redQueenSquareK[z].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(redQueenSquare.posX == i*100+20 &&
                                               redQueenSquare.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redBishop1Square.posX == i*100+20 &&
                                               redBishop1Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redBishop2Square.posX == i*100+20 &&
                                               redBishop2Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redKnight1Rectangle1.posX == i*100+20 &&
                                               redKnight1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redKnight2Rectangle1.posX == i*100+20 &&
                                               redKnight2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redRook1Rectangle1.posX == i*100+20 &&
                                               redRook1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(redRook2Rectangle1.posX == i*100+20 &&
                                               redRook2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(redPawnsBase[u].posX == greyPawnsBase[k].posX &&
                                                   redPawnsBase[u].posY == greyPawnsBase[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckGrey(j, i);

                                            if(ffff && fff) {
                                                greyPawnsBase[k].posX = a0;
                                                greyPawnsBase[k].posY = a1;

                                                turn = 'h';
                                            
                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyPawnsBase[k].posX ||
                                                        redPawnsBase[l].posX == greyPawnsBase[k].posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyPawnsBase[k].posX &&
                                                       redPawnsBase[u].posY == greyPawnsBase[k].posY) {
                                                        redPawnsBase[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    greyPawnsBase[k].firstTimeMove = FALSE;
                                                    greyPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                } else {
                                                    greyPawnsBase[k].posX = a0;
                                                    greyPawnsBase[k].posY = a1;

                                                    turn = 'h';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                           j*100+20 == greyPawnsBase[k].posY - 100 &&
                                           i*100+20 == greyPawnsBase[k].posX) {

                                            turn = 'r';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(greyPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY + 100 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == greyPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY + 100 == greyPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = greyPawnsBase[k].posX;
                                                int a1 = greyPawnsBase[k].posY;
                                                
                                                boxes[j][i].clear = FALSE;
                                                boxes[greyPawnsBase[k].posY/100][greyPawnsBase[k].posX/100].clear = TRUE;

                                                greyPawnsBase[k].posY = j*100+20;

                                                boolean ffff = checkCheckGrey(j, i);
                                                
                                                if(ffff) {
                                                    greyPawnsBase[k].posX = a0;
                                                    greyPawnsBase[k].posY = a1;

                                                    turn = 'h';
                                                } else {
                                                    greyPawnsBase[k].clicked = FALSE;
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
                            
                            if(greyKnight2Rectangle1.posX == i*100+20 &&
                               greyKnight2Rectangle1.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyKnight2Rectangle1.clicked = TRUE;
                                greyKnight2Rectangle1.from = (char*) malloc(2);
                                greyKnight2Rectangle1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "kw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyKnight2Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyKnight2Rectangle1.clicked == TRUE) {
                                    greyKnight2Rectangle1.to = (char*) malloc(2);
                                    greyKnight2Rectangle1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;
                                    
                                    clickedOne = 'g';

                                    greyKnight2Rectangle1.clicked = FALSE;

                                    if(j*100+20 == greyKnight2Rectangle1.posY - 200 &&
                                       i*100+20 == greyKnight2Rectangle1.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        int a1 = greyKnight2Rectangle1.posY;
                                        int a0 = greyKnight2Rectangle1.posX;

                                        greyKnight2Rectangle1.posX = i*100+20;
                                        greyKnight2Rectangle1.posY = j*100+20;

                                        if(!failed) {

                                            boolean ffff = checkCheckGrey(j, i);

                                            if(ffff) {

                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY - 200 &&
                                              i*100+20 == greyKnight2Rectangle1.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY - 100 &&
                                              i*100+20 == greyKnight2Rectangle1.posX - 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);

                                            if(ffff) {
                                                
                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY + 100 &&
                                              i*100+20 == greyKnight2Rectangle1.posX - 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                                
                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY + 200 &&
                                              i*100+20 == greyKnight2Rectangle1.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                                
                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;
                                                
                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY + 200 &&
                                              i*100+20 == greyKnight2Rectangle1.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);

                                            if(ffff) {

                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY - 100 &&
                                              i*100+20 == greyKnight2Rectangle1.posX + 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                            
                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight2Rectangle1.posY + 100 &&
                                              i*100+20 == greyKnight2Rectangle1.posX + 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight2Rectangle1.posY;
                                            int a0 = greyKnight2Rectangle1.posX;

                                            greyKnight2Rectangle1.posX = i*100+20;
                                            greyKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                                
                                                greyKnight2Rectangle1.posY = a1;
                                                greyKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    }
                                }
                            }

                            itdid = FALSE;
                            
                            if(greyKnight1Rectangle1.posX == i*100+20 &&
                               greyKnight1Rectangle1.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyKnight1Rectangle1.clicked = TRUE;
                                greyKnight1Rectangle1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "kw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyKnight1Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyKnight1Rectangle1.clicked == TRUE) {
                                    greyKnight1Rectangle1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;
                                    
                                    clickedOne = 'g';

                                    greyKnight1Rectangle1.clicked = FALSE;

                                    if(j*100+20 == greyKnight1Rectangle1.posY - 200 &&
                                       i*100+20 == greyKnight1Rectangle1.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;
                                                
                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY - 200 &&
                                              i*100+20 == greyKnight1Rectangle1.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY - 100 &&
                                              i*100+20 == greyKnight1Rectangle1.posX - 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;

                                            } else {
                                            
                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY + 100 &&
                                              i*100+20 == greyKnight1Rectangle1.posX - 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                            
                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;

                                            } else {
                                            
                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY + 200 &&
                                              i*100+20 == greyKnight1Rectangle1.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                            
                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;
                                                
                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY + 200 &&
                                              i*100+20 == greyKnight1Rectangle1.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;

                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                                
                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;

                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY - 100 &&
                                              i*100+20 == greyKnight1Rectangle1.posX + 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                                
                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;

                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKnight1Rectangle1.posY + 100 &&
                                              i*100+20 == greyKnight1Rectangle1.posX + 200) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = greyKnight1Rectangle1.posY;
                                            int a0 = greyKnight1Rectangle1.posX;
                                            
                                            greyKnight1Rectangle1.posX = i*100+20;
                                            greyKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckGrey(j, i);

                                            if(ffff) {
                                                
                                                greyKnight1Rectangle1.posY = a1;
                                                greyKnight1Rectangle1.posX = a0;

                                            } else {

                                                done = TRUE;

                                                for(int t=0; t<8; t++) {
                                                    if(redPawnsBase[t].posX == i*100+20 &&
                                                       redPawnsBase[t].posY == j*100+20) {
                                                        redPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    }
                                }
                            }
                            
                            itdid = FALSE;
                            
                            if(greyKingSquare.posX == i*100+20 &&
                               greyKingSquare.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyKingSquare.clicked = TRUE;
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "cw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyKingSquare.clicked == TRUE) {
                                itdid = TRUE;
                                to = map(j, i);
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;
                                    
                                    clickedOne = 'g';

                                    greyKingSquare.clicked = FALSE;

                                    if(j*100+20 == greyKingSquare.posY &&
                                       i*100+20 == greyKingSquare.posX - 200) {
                                        if(greyRook1Rectangle1.posY == 700+20 &&
                                           greyRook1Rectangle1.posX == 0+20) {
                                            if(greyKingSquare.posY == 700+20 &&
                                               greyKingSquare.posX == 400+20) {
                                                boolean isthere = FALSE;
                                                if(greyRook1Rectangle1.posX == 300+20 &&
                                                   greyRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == 200+20 &&
                                                   greyRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == 100+20 &&
                                                   greyRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 300+20 &&
                                                   greyRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 200+20 &&
                                                   greyRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 100+20 &&
                                                   greyRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 300+20 &&
                                                   redRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 200+20 &&
                                                   redRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 100+20 &&
                                                   redRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 300+20 &&
                                                   redRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 200+20 &&
                                                   redRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 100+20 &&
                                                   redRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 300+20 &&
                                                   greyBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 200+20 &&
                                                   greyBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 100+20 &&
                                                   greyBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 300+20 &&
                                                   greyBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 200+20 &&
                                                   greyBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 100+20 &&
                                                   greyBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 300+20 &&
                                                   redBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 200+20 &&
                                                   redBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 100+20 &&
                                                   redBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 300+20 &&
                                                   redBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 200+20 &&
                                                   redBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 100+20 &&
                                                   redBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 300+20 &&
                                                   greyKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 200+20 &&
                                                   greyKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 100+20 &&
                                                   greyKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 300+20 &&
                                                   greyKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 200+20 &&
                                                   greyKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 100+20 &&
                                                   greyKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 300+20 &&
                                                   redKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 200+20 &&
                                                   redKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 100+20 &&
                                                   redKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 300+20 &&
                                                   redKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 200+20 &&
                                                   redKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 100+20 &&
                                                   redKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 300+20 &&
                                                   greyQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 200+20 &&
                                                   greyQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 100+20 &&
                                                   greyQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 300+20 &&
                                                   redQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 200+20 &&
                                                   redQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 100+20 &&
                                                   redQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !greyKingMoved && !greyRook1Moved) {
                                                    greyKingSquare.posX -= 200;
                                                    greyRook1Rectangle1.posX += 300;
                                                    greyKingMoved = TRUE;
                                                    greyRook1Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'r';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*100+20 == greyKingSquare.posY &&
                                       i*100+20 == greyKingSquare.posX + 200) {
                                        if(greyRook2Rectangle1.posY == 700+20 &&
                                           greyRook2Rectangle1.posX == 700+20) {
                                            if(greyKingSquare.posY == 700+20 &&
                                               greyKingSquare.posX == 400+20) {
                                                boolean isthere = FALSE;
                                                if(greyRook1Rectangle1.posX == 500+20 &&
                                                   greyRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == 600+20 &&
                                                   greyRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 500+20 &&
                                                   greyRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 600+20 &&
                                                   greyRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 500+20 &&
                                                   redRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 600+20 &&
                                                   redRook1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 500+20 &&
                                                   redRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 600+20 &&
                                                   redRook2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 500+20 &&
                                                   greyBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 600+20 &&
                                                   greyBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 500+20 &&
                                                   greyBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 600+20 &&
                                                   greyBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 500+20 &&
                                                   redBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 600+20 &&
                                                   redBishop1Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 500+20 &&
                                                   redBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 600+20 &&
                                                   redBishop2Square.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 500+20 &&
                                                   greyKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 600+20 &&
                                                   greyKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 500+20 &&
                                                   greyKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 600+20 &&
                                                   greyKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 500+20 &&
                                                   redKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 600+20 &&
                                                   redKnight1Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 500+20 &&
                                                   redKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 600+20 &&
                                                   redKnight2Rectangle1.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 500+20 &&
                                                   greyQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 600+20 &&
                                                   greyQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 500+20 &&
                                                   redQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 600+20 &&
                                                   redQueenSquare.posY == 700+20) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !greyKingMoved && !greyRook2Moved) {
                                                    greyKingSquare.posX += 200;
                                                    greyRook2Rectangle1.posX -= 200;
                                                    greyKingMoved = TRUE;
                                                    greyRook2Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'r';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*100+20 == greyKingSquare.posY - 100 &&
                                       i*100+20 == greyKingSquare.posX) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;

                                            greyKingSquare.posY -= 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY - 100 &&
                                              i*100+20 == greyKingSquare.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;

                                            greyKingSquare.posY -= 100;
                                            greyKingSquare.posX += 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {
                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {
                                            
                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY &&
                                              i*100+20 == greyKingSquare.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;

                                            greyKingSquare.posX += 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY + 100 &&
                                              i*100+20 == greyKingSquare.posX + 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;

                                            greyKingSquare.posX += 100;
                                            greyKingSquare.posY += 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY + 100 &&
                                              i*100+20 == greyKingSquare.posX) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;
                                            
                                            greyKingSquare.posY += 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY + 100 &&
                                              i*100+20 == greyKingSquare.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;
                                            
                                            greyKingSquare.posX -= 100;
                                            greyKingSquare.posY += 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY &&
                                              i*100+20 == greyKingSquare.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {

                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;
                                            
                                            greyKingSquare.posX -= 100;

                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == greyKingSquare.posY - 100 &&
                                              i*100+20 == greyKingSquare.posX - 100) {
                                        
                                        for(int t=0; t<8; t++) {
                                            if(greyPawnsBase[t].posX == i*100+20 &&
                                               greyPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(greyQueenSquare.posX == i*100+20 &&
                                           greyQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop1Square.posX == i*100+20 &&
                                           greyBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyBishop2Square.posX == i*100+20 &&
                                           greyBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight1Rectangle1.posX == i*100+20 &&
                                           greyKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKnight2Rectangle1.posX == i*100+20 &&
                                           greyKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook1Rectangle1.posX == i*100+20 &&
                                           greyRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyRook2Rectangle1.posX == i*100+20 &&
                                           greyRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        
                                        if(!failed) {
                                            
                                            int a1 = greyKingSquare.posY;
                                            int a0 = greyKingSquare.posX;
                                            
                                            greyKingSquare.posX -= 100;
                                            greyKingSquare.posY -= 100;
                                            
                                            boolean ffff = checkCheckGrey(j, i);
                                            
                                            if(ffff) {

                                                greyKingSquare.posY = a1;
                                                greyKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((redPawnsBase[l].posX == greyKingSquare.posX ||
                                                        redPawnsBase[l].posX == greyKingSquare.posX) && 
                                                        redPawnsBase[l].posY == j*100+20) {
                                                        redPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(redQueenSquare.posX == i*100+20 &&
                                                   redQueenSquare.posY == j*100+20) {
                                                    redQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(redQueenSquareK[z].posX == i*100+20 &&
                                                       redQueenSquareK[z].posY == j*100+20) {
                                                        redQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(redBishop1Square.posX == i*100+20 &&
                                                   redBishop1Square.posY == j*100+20) {
                                                    redBishop1Square.posX = 1300;
                                                }
                                                if(redBishop2Square.posX == i*100+20 &&
                                                   redBishop2Square.posY == j*100+20) {
                                                    redBishop2Square.posX = 1300;
                                                }
                                                if(redKnight1Rectangle1.posX == i*100+20 &&
                                                   redKnight1Rectangle1.posY == j*100+20) {
                                                    redKnight1Rectangle1.posX = 1300;
                                                }
                                                if(redKnight2Rectangle1.posX == i*100+20 &&
                                                   redKnight2Rectangle1.posY == j*100+20) {
                                                    redKnight2Rectangle1.posX = 1300;
                                                }
                                                if(redRook1Rectangle1.posX == i*100+20 &&
                                                   redRook1Rectangle1.posY == j*100+20) {
                                                    redRook1Rectangle1.posX = 1300;
                                                }
                                                if(redRook2Rectangle1.posX == i*100+20 &&
                                                   redRook2Rectangle1.posY == j*100+20) {
                                                    redRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(redPawnsBase[u].posX == greyKingSquare.posX &&
                                                       redPawnsBase[u].posY == greyKingSquare.posY + 100) {
                                                        redPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                greyKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    }
                                }
                            }

                            boolean changeii = FALSE;
                            
                            for(int z=0; z<8; z++) {
                                if(greyPawnsBase[z].posY == 0) {
                                    strncpy(chosenPiece, "qw", 2);
                                    changeii = TRUE;
                                    int x = greyPawnsBase[z].posX;
                                    int y = greyPawnsBase[z].posY;
                                    greyQueenSquareK[z].posX = x;
                                    greyQueenSquareK[z].posY = y;
                                    greyQueenSquareK[z].from = map(j, i);
                                    greyQueenSquareK[z].to = map(j, i);
                                    
                                    greyPawnsBase[z].posX = 1300;
                                    greyPawnsBase[z].posY = -1000;
                                    
                                    turn = 'r';
                                }
                            }

                            itdid = FALSE;
                            
                            if(greyQueenSquare.posX == i*100+20 &&
                               greyQueenSquare.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyQueenSquare.clicked = TRUE;
                                greyQueenSquare.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "qw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyQueenSquare.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyQueenSquare.clicked == TRUE) {
                                    greyQueenSquare.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    greyQueenSquare.clicked = FALSE;

                                    int a1 = greyQueenSquare.posY;
                                    int a0 = greyQueenSquare.posX;

                                    boxes[greyQueenSquare.posY/100][greyQueenSquare.posX/100].clear = TRUE;
                                    boolean f = FALSE;
                                    
                                    greyQueenSquare.failedpath = FALSE;

                                    if(i*100+20 == greyQueenSquare.posX) {
                                        f = moveGreyQueen(msg, j, i, j*100+20 - greyQueenSquare.posY, j*100+20 - greyQueenSquare.posY);
                                        f = greyQueenSquare.failedpath;
                                    } else if(j*100+20 == greyQueenSquare.posY) {
                                        f = moveGreyQueenSide(msg, j, i, i*100+20 - greyQueenSquare.posX, i*100+20 - greyQueenSquare.posX);
                                        f = greyQueenSquare.failedpath;
                                    } else if(i*100+20 != greyQueenSquare.posX &&
                                       j*100+20 != greyQueenSquare.posY) {
                                        f = moveGreyQueenDiagonally(msg, j, i, j*100+20 - greyQueenSquare.posY, i*100+20 - greyQueenSquare.posX, j*100+20 - greyQueenSquare.posY, i*100+20 - greyQueenSquare.posX);
                                        f = greyQueenSquare.failedpath;
                                    }

                                    boolean fff = checkCheckGrey(j, i);

                                    if(f || fff) {

                                        greyQueenSquare.posY = a1;
                                        greyQueenSquare.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    
                                    itdid = FALSE;
                                }
                            }

                            for(int z=0; z<8; z++) {

                                itdid = FALSE;

                                if(changeii == FALSE &&
                                   greyQueenSquareK[z].posX == i*100+20 &&
                                   greyQueenSquareK[z].posY == j*100+20) {

                                    clickedOne = 'h';
                                    greyQueenSquareK[z].clicked = TRUE;
                                    greyQueenSquareK[z].from = map(j, i);
                                    turn = 'h';
                                    strncpy(chosenPiece, "qw", 2);
                                } else if(clickedOne == 'h' &&
                                          greyQueenSquareK[z].clicked == TRUE) {
                                    itdid = TRUE;
                                    if(greyQueenSquareK[z].clicked == TRUE) {
                                        greyQueenSquareK[z].to = map(j, i);
                                    }
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(itdid && changeii == FALSE) {

                                        clickedOne = 'h';
                                        greyQueenSquareK[z].clicked = FALSE;

                                        int a1 = greyQueenSquareK[z].posY;
                                        int a0 = greyQueenSquareK[z].posX;

                                        boolean f = FALSE;

                                        greyQueenSquareK[z].failedpath = FALSE;

                                        if(i*100+20 == greyQueenSquareK[z].posX) {
                                            f = moveGreyQueenK(msg, j, i, j*100+20 - greyQueenSquareK[z].posY, j*100+20 - greyQueenSquareK[z].posY, z);
                                            f = greyQueenSquareK[z].failedpath;
                                        } else if(j*100+20 == greyQueenSquareK[z].posY) {
                                            f = moveGreyQueenSideK(msg, j, i, i*100+20 - greyQueenSquareK[z].posX, i*100+20 - greyQueenSquareK[z].posX, z);
                                            f = greyQueenSquareK[z].failedpath;
                                        } else if(i*100+20 != greyQueenSquareK[z].posX &&
                                           j*100+20 != greyQueenSquareK[z].posY) {
                                            if(j*100+20 - greyQueenSquareK[z].posY == i*100+20 - greyQueenSquareK[z].posX ||
                                               j*100+20 - greyQueenSquareK[z].posY == -1 * (i*100+20 - greyQueenSquareK[z].posX)) {
                                                f = moveGreyQueenDiagonallyK(msg, j, i, j*100+20 - greyQueenSquareK[z].posY, i*100+20 - greyQueenSquareK[z].posX, j*100+20 - greyQueenSquareK[z].posY, i*100+20 - greyQueenSquareK[z].posX, z);
                                                f = greyQueenSquareK[z].failedpath;
                                            } else {
                                                f = greyQueenSquareK[z].failedpath = TRUE;
                                            }
                                        }
                                        
                                        boolean fff = checkCheckGrey(j, i);

                                        if(f || fff) {

                                            greyQueenSquareK[z].posY = a1;
                                            greyQueenSquareK[z].posX = a0;

                                            turn = 'h';
                                        }

                                        else {
                                            for(int a=0; a<8; a++) {
                                                greyPawnsBase[a].clicked = FALSE;
                                            }
                                            for(int a=0; a<8; a++) {
                                                greyPawnsBase[a].clicked = FALSE;
                                            }
                                            boxes[j][i].clear = FALSE;
                                            turn = 'r';
                                            turnChanged = TRUE;
                                            done = TRUE;
                                        }

                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }

                                        itdid = FALSE;
                                    }
                                }
                            }

                            itdid = FALSE;
                            
                            if(greyBishop1Square.posX == i*100+20 &&
                               greyBishop1Square.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyBishop1Square.clicked = TRUE;
                                greyBishop1Square.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "bw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyBishop1Square.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyBishop1Square.clicked == TRUE) {
                                    greyBishop1Square.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    greyBishop1Square.clicked = FALSE;

                                    int a1 = greyBishop1Square.posY;
                                    int a0 = greyBishop1Square.posX;

                                    boolean f = FALSE;

                                    greyBishop1Square.failedpath = FALSE;

                                    if(i*100+20 != greyBishop1Square.posX &&
                                       j*100+20 != greyBishop1Square.posY) {
                                        f = moveGreyBishop1(msg, j, i, j*100+20 - greyBishop1Square.posY, i*100+20 - greyBishop1Square.posX, j*100+20 - greyBishop1Square.posY, i*100+20 - greyBishop1Square.posX);
                                        f = greyBishop1Square.failedpath;
                                    } else {
                                        f = greyBishop1Square.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckGrey(j, i);
                                    
                                    if(f || fff) {

                                        greyBishop1Square.posY = a1;
                                        greyBishop1Square.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;
                            
                            if(greyBishop2Square.posX == i*100+20 &&
                               greyBishop2Square.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyBishop2Square.clicked = TRUE;
                                greyBishop2Square.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "bw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyBishop2Square.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyBishop2Square.clicked == TRUE) {
                                    greyBishop2Square.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    greyBishop2Square.clicked = FALSE;

                                    int a1 = greyBishop2Square.posY;
                                    int a0 = greyBishop2Square.posX;

                                    boolean f = FALSE;

                                    greyBishop2Square.failedpath = FALSE;
                                    
                                    if(i*100+20 != greyBishop2Square.posX &&
                                       j*100+20 != greyBishop2Square.posY) {
                                        f = moveGreyBishop2(msg, j, i, j*100+20 - greyBishop2Square.posY, i*100+20 - greyBishop2Square.posX, j*100+20 - greyBishop2Square.posY, i*100+20 - greyBishop2Square.posX);
                                        f = greyBishop2Square.failedpath;
                                    } else {
                                        f = greyBishop2Square.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckGrey(j, i);

                                    if(f || fff) {
                                        
                                        greyBishop2Square.posY = a1;
                                        greyBishop2Square.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;
                            
                            if(greyRook1Rectangle1.posX == i*100+20 &&
                               greyRook1Rectangle1.posY == j*100+20) {
                                
                                clickedOne = 'g';
                                greyRook1Rectangle1.clicked = TRUE;
                                greyRook1Rectangle1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "rw", 2);
                            } else if(clickedOne == 'g' &&
                                      greyRook1Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyRook1Rectangle1.clicked == TRUE) {
                                    greyRook1Rectangle1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'g';
                                    greyRook1Rectangle1.clicked = FALSE;

                                    int a1 = greyRook1Rectangle1.posY;
                                    int a0 = greyRook1Rectangle1.posX;

                                    boxes[greyRook1Rectangle1.posY/100][greyRook1Rectangle1.posX/100].clear = TRUE;

                                    boolean f = FALSE;

                                    greyRook1Rectangle1.failedpath = FALSE;

                                    if(i*100+20 == greyRook1Rectangle1.posX) {
                                        f = moveGreyRook1(msg, j, i, j*100+20 - greyRook1Rectangle1.posY, j*100+20 - greyRook1Rectangle1.posY);
                                        f = greyRook1Rectangle1.failedpath;
                                    } else if(j*100+20 == greyRook1Rectangle1.posY) {
                                        f = moveGreyRook1Side(msg, j, i, i*100+20 - greyRook1Rectangle1.posX, i*100+20 - greyRook1Rectangle1.posX);
                                        f = greyRook1Rectangle1.failedpath;
                                    } else {
                                        f = greyRook1Rectangle1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckGrey(j, i);

                                    if(f || fff) {

                                        greyRook1Rectangle1.posY = a1;
                                        greyRook1Rectangle1.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        greyQueenSquare.clicked = FALSE;
                                        greyRook2Rectangle1.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        greyRook1Moved = TRUE;
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    greyQueenSquare.clicked = FALSE;
                                    greyRook2Rectangle1.clicked = FALSE;
                                    
                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;
                            
                            if(greyRook2Rectangle1.posX == i*100+20 &&
                               greyRook2Rectangle1.posY == j*100+20) {
                                
                                clickedOne = 'h';
                                greyRook2Rectangle1.clicked = TRUE;
                                greyRook2Rectangle1.from = map(j, i);
                                from = map(j, i);
                                turn = 'h';
                                strncpy(chosenPiece, "rw", 2);
                            } else if(clickedOne == 'h' &&
                                      greyRook2Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(greyRook2Rectangle1.clicked == TRUE) {
                                    greyRook2Rectangle1.to = map(j, i);
                                    to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'h';
                                    greyRook2Rectangle1.clicked = FALSE;

                                    int a1 = greyRook2Rectangle1.posY;
                                    int a0 = greyRook2Rectangle1.posX;

                                    boxes[greyRook2Rectangle1.posY/100][greyRook2Rectangle1.posX/100].clear = TRUE;

                                    boolean f = FALSE;

                                    greyRook2Rectangle1.failedpath = FALSE;

                                    if(i*100+20 == greyRook2Rectangle1.posX) {
                                        f = moveGreyRook2(msg, j, i, j*100+20 - greyRook2Rectangle1.posY, j*100+20 - greyRook2Rectangle1.posY);
                                        f = greyRook2Rectangle1.failedpath;
                                    } else if(j*100+20 == greyRook2Rectangle1.posY) {
                                        f = moveGreyRook2Side(msg, j, i, i*100+20 - greyRook2Rectangle1.posX, i*100+20 - greyRook2Rectangle1.posX);
                                        f = greyRook2Rectangle1.failedpath;
                                    } else {
                                        f = greyRook2Rectangle1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckGrey(j, i);
                                    
                                    if(f || fff) {

                                        greyRook2Rectangle1.posY = a1;
                                        greyRook2Rectangle1.posX = a0;

                                        turn = 'h';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        greyQueenSquare.clicked = FALSE;
                                        greyRook1Rectangle1.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'r';
                                        greyRook2Moved = TRUE;
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    greyQueenSquare.clicked = FALSE;
                                    greyRook1Rectangle1.clicked = FALSE;
                                    
                                    itdid = FALSE;
                                }
                            }
 
                            boolean efe = checkCheckRed(j, i);

                            boolean checked = FALSE;

                            int ppx = greyKingSquare.posX;
                            int ppy = greyKingSquare.posY;

                            if(!efe) {
                                checked = FALSE;
                                greyKingSquare.posX -= 100;
                                efe = checkCheckRed(j, i);
                                if(!efe) {
                                    checked = FALSE;
                                    greyKingSquare.posX += 100;
                                } else {
                                    checked = TRUE;
                                    greyKingSquare.posX += 100;
                                    greyKingSquare.posY -= 100;
                                    greyKingSquare.posX -= 100;
                                    efe = checkCheckRed(j, i);
                                    if(!efe) {
                                        checked = FALSE;
                                        greyKingSquare.posY += 100;
                                        greyKingSquare.posX += 100;
                                    } else {
                                        checked = TRUE;
                                        greyKingSquare.posY += 100;
                                        greyKingSquare.posX += 100;
                                        greyKingSquare.posY -= 100;
                                        efe = checkCheckRed(j, i);
                                        if(!efe) {
                                            checked = FALSE;
                                            greyKingSquare.posY += 100;
                                        } else {
                                            checked = TRUE;
                                            greyKingSquare.posY += 100;
                                            greyKingSquare.posY -= 100;
                                            greyKingSquare.posX += 100;
                                            efe = checkCheckRed(j, i);
                                            if(!efe) {
                                                checked = FALSE;
                                                greyKingSquare.posY += 100;
                                                greyKingSquare.posX -= 100;
                                            } else {
                                                checked = TRUE;
                                                greyKingSquare.posY += 100;
                                                greyKingSquare.posX -= 100;
                                                greyKingSquare.posX += 100;
                                                efe = checkCheckRed(j, i);
                                                if(!efe) {
                                                    checked = FALSE;
                                                    greyKingSquare.posX -= 100;
                                                    greyKingSquare.posY += 100;
                                                    greyKingSquare.posX += 100;
                                                } else {
                                                    checked = TRUE;
                                                    greyKingSquare.posX -= 100;
                                                    greyKingSquare.posY += 100;
                                                    greyKingSquare.posX += 100;
                                                    efe = checkCheckRed(j, i);
                                                    if(!efe) {
                                                        checked = FALSE;
                                                        greyKingSquare.posY -= 100;
                                                        greyKingSquare.posX -= 100;
                                                    } else {
                                                        checked = TRUE;
                                                        greyKingSquare.posY -= 100;
                                                        greyKingSquare.posX -= 100;
                                                        greyKingSquare.posY += 100;
                                                        efe = checkCheckRed(j, i);
                                                        if(!efe) {
                                                            checked = FALSE;
                                                            greyKingSquare.posY -= 100;
                                                            greyKingSquare.posY += 100;
                                                            greyKingSquare.posX -= 100;
                                                        } else {
                                                            checked = TRUE;
                                                            greyKingSquare.posY -= 100;
                                                            greyKingSquare.posY += 100;
                                                            greyKingSquare.posX -= 100;
                                                            efe = checkCheckRed(j, i);
                                                            if(!efe) {
                                                                checked = FALSE;
                                                                greyKingSquare.posY -= 100;
                                                                greyKingSquare.posX += 100;
                                                            } else {
                                                                checked = TRUE;
                                                                greyKingSquare.posY -= 100;
                                                                greyKingSquare.posX += 100;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                checked = TRUE;
                                greyKingSquare.posX -= 100;
                                efe = checkCheckRed(j, i);
                                if(!efe) {
                                    checked = FALSE;
                                    greyKingSquare.posX += 100;
                                } else {
                                    checked = TRUE;
                                    greyKingSquare.posX += 100;
                                    greyKingSquare.posY -= 100;
                                    greyKingSquare.posX -= 100;
                                    efe = checkCheckRed(j, i);
                                    if(!efe) {
                                        checked = FALSE;
                                        greyKingSquare.posY += 100;
                                        greyKingSquare.posX += 100;
                                    } else {
                                        checked = TRUE;
                                        greyKingSquare.posY += 100;
                                        greyKingSquare.posX += 100;
                                        greyKingSquare.posY -= 100;
                                        efe = checkCheckRed(j, i);
                                        if(!efe) {
                                            checked = FALSE;
                                            greyKingSquare.posY += 100;
                                        } else {
                                            checked = TRUE;
                                            greyKingSquare.posY += 100;
                                            greyKingSquare.posY -= 100;
                                            greyKingSquare.posX += 100;
                                            efe = checkCheckRed(j, i);
                                            if(!efe) {
                                                checked = FALSE;
                                                greyKingSquare.posY += 100;
                                                greyKingSquare.posX -= 100;
                                            } else {
                                                checked = TRUE;
                                                greyKingSquare.posY += 100;
                                                greyKingSquare.posX -= 100;
                                                greyKingSquare.posX += 100;
                                                efe = checkCheckRed(j, i);
                                                if(!efe) {
                                                    checked = FALSE;
                                                    greyKingSquare.posX -= 100;
                                                    greyKingSquare.posY += 100;
                                                    greyKingSquare.posX += 100;
                                                } else {
                                                    checked = TRUE;
                                                    greyKingSquare.posX -= 100;
                                                    greyKingSquare.posY += 100;
                                                    greyKingSquare.posX += 100;
                                                    efe = checkCheckRed(j, i);
                                                    if(!efe) {
                                                        checked = FALSE;
                                                        greyKingSquare.posY -= 100;
                                                        greyKingSquare.posX -= 100;
                                                    } else {
                                                        checked = TRUE;
                                                        greyKingSquare.posY -= 100;
                                                        greyKingSquare.posX -= 100;
                                                        greyKingSquare.posY += 100;
                                                        efe = checkCheckRed(j, i);
                                                        if(!efe) {
                                                            checked = FALSE;
                                                            greyKingSquare.posY -= 100;
                                                            greyKingSquare.posY += 100;
                                                            greyKingSquare.posX -= 100;
                                                        } else {
                                                            checked = TRUE;
                                                            greyKingSquare.posY -= 100;
                                                            greyKingSquare.posY += 100;
                                                            greyKingSquare.posX -= 100;
                                                            efe = checkCheckRed(j, i);
                                                            if(!efe) {
                                                                checked = FALSE;
                                                                greyKingSquare.posY -= 100;
                                                                greyKingSquare.posX += 100;
                                                            } else {
                                                                checked = TRUE;
                                                                greyKingSquare.posY -= 100;
                                                                greyKingSquare.posX += 100;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            HBRUSH rBrush;
                            rBrush = CreateSolidBrush(RGB(155, 100, 100));
                            RECT r = {i*100+20, j*100+20, i*100+20 + 16, j*100+20 + 16};
                            for(int t=0; t<8; t++) {
                                if(turn == 'r' && greyPawnsBase[t].posX == i*100+20 &&
                                   greyPawnsBase[t].posY == j*100+20) {
                                    if(TRUE==done) {
                                        int l1_x1 = i*100+20;
                                        int l1_y1 = j*100+20 + 8;
                                        int l1_x2 = i*100+20 + 8;
                                        int l1_y2 = j*100+20 + 16;
                                        int l2_x1 = i*100+20 + 8;
                                        int l2_y1 = j*100+20 + 16;
                                        int l2_x2 = i*100+20 + 16;
                                        int l2_y2 = j*100+20;
                                        PAINTSTRUCT pntS;
                                        HPEN pen, oldPen;
                                        pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
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
                                if(turn == 'h' && greyPawnsBase[t].posX == i*100+20 &&
                                   greyPawnsBase[t].posY == j*100+20) {
                                    FillRect(hdc, &r, rBrush);
                                }
                            }
                            if(turn == 'r' && greyKingSquare.posX == i*100+20 &&
                               greyKingSquare.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyKingSquare.posX == i*100+20 &&
                               greyKingSquare.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyQueenSquare.posX == i*100+20 &&
                               greyQueenSquare.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyQueenSquare.posX == i*100+20 &&
                               greyQueenSquare.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyKnight1Rectangle1.posX == i*100+20 &&
                               greyKnight1Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyKnight1Rectangle1.posX == i*100+20 &&
                               greyKnight1Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyKnight2Rectangle1.posX == i*100+20 &&
                               greyKnight2Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyKnight2Rectangle1.posX == i*100+20 &&
                               greyKnight2Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyBishop1Square.posX == i*100+20 &&
                               greyBishop1Square.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyBishop1Square.posX == i*100+20 &&
                               greyBishop1Square.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyBishop2Square.posX == i*100+20 &&
                               greyBishop2Square.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyBishop2Square.posX == i*100+20 &&
                               greyBishop2Square.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyRook1Rectangle1.posX == i*100+20 &&
                               greyRook1Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyRook1Rectangle1.posX == i*100+20 &&
                               greyRook1Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && greyRook2Rectangle1.posX == i*100+20 &&
                               greyRook2Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && greyRook2Rectangle1.posX == i*100+20 &&
                               greyRook2Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            DeleteObject(rBrush);

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
                                if(((greyRook1Rectangle1.posX/100)+(greyRook1Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(rookWhite,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(rookWhite,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyRook1Rectangle1.posX+25+7, greyRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyRook2Rectangle1.posX/100)+(greyRook2Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(rook2White,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(rook2White,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyRook2Rectangle1.posX+25+7, greyRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyKnight1Rectangle1.posX/100)+(greyKnight1Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(knightWhite,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(knightWhite,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyKnight1Rectangle1.posX+25+7, greyKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyKnight2Rectangle1.posX/100)+(greyKnight2Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(knight2White,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(knight2White,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyKnight2Rectangle1.posX+25+7, greyKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyBishop1Square.posX/100)+(greyBishop1Square.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(bishopWhite,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishopWhite,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyBishop1Square.posX+25+7, greyBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyBishop2Square.posX/100)+(greyBishop2Square.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(bishop2White,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishop2White,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyBishop2Square.posX+25+7, greyBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyQueenSquare.posX/100)+(greyQueenSquare.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyQueenSquare.posX+25+7, greyQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((greyKingSquare.posX/100)+(greyKingSquare.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(kingWhite,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(kingWhite,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, greyKingSquare.posX+25+7, greyKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                for(int o=0; o<8; o++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((greyPawnsBase[o].posX/100)+(greyPawnsBase[o].posY/100)) % 2 == 0)
                                        hBmp = ReplaceColor(pawnWhite,0x110000,0xe1f4fc,hdcMem);
                                    else
                                        hBmp = ReplaceColor(pawnWhite,0x110000,0x377105,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, greyPawnsBase[o].posX+25+7, greyPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redRook1Rectangle1.posX/100)+(redRook1Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(rookBlack,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redRook1Rectangle1.posX+25+7, redRook1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redRook2Rectangle1.posX/100)+(redRook2Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(rook2Black,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(rookBlack,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redRook2Rectangle1.posX+25+7, redRook2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redKnight1Rectangle1.posX/100)+(redKnight1Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(knightBlack,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(knightBlack,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redKnight1Rectangle1.posX+25+7, redKnight1Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redKnight2Rectangle1.posX/100)+(redKnight2Rectangle1.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(knight2Black,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(knight2Black,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redKnight2Rectangle1.posX+25+7, redKnight2Rectangle1.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redBishop1Square.posX/100)+(redBishop1Square.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(bishopBlack,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishopBlack,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redBishop1Square.posX+25+7, redBishop1Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redBishop2Square.posX/100)+(redBishop2Square.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(bishop2Black,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(bishop2Black,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redBishop2Square.posX+25+7, redBishop2Square.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redQueenSquare.posX/100)+(redQueenSquare.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redQueenSquare.posX+25+7, redQueenSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                hdcMem = CreateCompatibleDC(hdc);
                                if(((redKingSquare.posX/100)+(redKingSquare.posY/100)) % 2 == 0)
                                    hBmp = ReplaceColor(kingBlack,0x110000,0xe1f4fc,hdcMem);
                                else
                                    hBmp = ReplaceColor(kingBlack,0x110000,0x377105,hdcMem);
                                oldBitmap = SelectObject(hdcMem, hBmp);
                                GetObject(hBmp, sizeof(bitmap), &bitmap);
                                BitBlt(hdc, redKingSquare.posX+25+7, redKingSquare.posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                SelectObject(hdcMem, oldBitmap);
                                ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);

                                for(int o=0; o<8; o++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((redPawnsBase[o].posX/100)+(redPawnsBase[o].posY/100)) % 2 == 0)
                                        hBmp = ReplaceColor(pawnBlack,0x110000,0xe1f4fc,hdcMem);
                                    else
                                        hBmp = ReplaceColor(pawnBlack,0x110000,0x377105,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, redPawnsBase[o].posX+25+7, redPawnsBase[o].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                for(int m=0; m<8; m++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((greyQueenSquareK[m].posX/100)+(greyQueenSquareK[m].posY/100)) % 2 == 0)
                                        hBmp = ReplaceColor(queenWhite,0x110000,0xe1f4fc,hdcMem);
                                    else
                                        hBmp = ReplaceColor(queenWhite,0x110000,0x377105,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, greyQueenSquareK[m].posX+25+7, greyQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                }

                                for(int m=0; m<8; m++) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    if(((redQueenSquareK[m].posX/100)+(redQueenSquareK[m].posY/100)) % 2 == 0)
                                        hBmp = ReplaceColor(queenBlack,0x110000,0xe1f4fc,hdcMem);
                                    else
                                        hBmp = ReplaceColor(queenBlack,0x110000,0x377105,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, redQueenSquareK[m].posX+25+7, redQueenSquareK[m].posY+25, 65, 65, hdcMem, 0, 0, SRCCOPY);
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

                                HBRUSH white_brush = CreateSolidBrush(RGB(255,200,200));
                                RECT rrect = {820+50, 20, 1120, 810};
                                FillRect(hdc, &rrect, white_brush);
                                DeleteObject(white_brush);

                                if(greyRook1Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rookWhite_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyRook1Rectangle1.from != NULL && greyRook1Rectangle1.to != NULL) {
                                        if(strlen(greyRook1Rectangle1.from) >= 2 && strlen(greyRook1Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyRook1Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyRook2Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rook2White_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyRook2Rectangle1.from != NULL && greyRook2Rectangle1.to != NULL) {
                                        if(strlen(greyRook2Rectangle1.from) >= 2 && strlen(greyRook2Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyRook2Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyKnight1Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knightWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyKnight1Rectangle1.from != NULL && greyKnight1Rectangle1.to != NULL) {
                                        if(strlen(greyKnight1Rectangle1.from) >= 2 && strlen(greyKnight1Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyKnight1Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyKnight2Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knight2White_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyKnight2Rectangle1.from != NULL && greyKnight2Rectangle1.to != NULL) {
                                        if(strlen(greyKnight2Rectangle1.from) >= 2 && strlen(greyKnight2Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyKnight2Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyBishop1Square.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishopWhite_s,0x4cb122,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyBishop1Square.from != NULL && greyBishop1Square.to != NULL) {
                                        if(strlen(greyBishop1Square.from) >= 2 && strlen(greyBishop1Square.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyBishop1Square.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyBishop2Square.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishop2White_s,0x4cb122,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyBishop2Square.from != NULL && greyBishop2Square.to != NULL) {
                                        if(strlen(greyBishop2Square.from) >= 2 && strlen(greyBishop2Square.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyBishop2Square.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyQueenSquare.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(greyQueenSquare.from != NULL && greyQueenSquare.to != NULL) {
                                        if(strlen(greyQueenSquare.from) >= 2 && strlen(greyQueenSquare.to) >= 2) {
                                            TextOut(hdc,
                                                    855+50,
                                                    _y_,
                                                    greyQueenSquare.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(greyKingSquare.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(kingWhite_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                for(int o=0; o<8; o++) {
                                    if(greyPawnsBase[o].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(pawnWhite_s,0x000000,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(greyPawnsBase[o].from != NULL && greyPawnsBase[o].to != NULL) {
                                            if(strlen(greyPawnsBase[o].from) >= 2 && strlen(greyPawnsBase[o].to) >= 2) {
                                                TextOut(hdc,
                                                        855+50,
                                                        _y_,
                                                        greyPawnsBase[o].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                for(int m=0; m<8; m++) {
                                    if(greyQueenSquareK[m].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(queenWhite_s,0xff0000,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 825+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(greyQueenSquareK[m].from != NULL && greyQueenSquareK[m].to != NULL) {
                                            if(strlen(greyQueenSquareK[m].from) >= 2 && strlen(greyQueenSquareK[m].to) >= 2) {
                                                TextOut(hdc,
                                                        855+50,
                                                        _y_,
                                                        greyQueenSquareK[m].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                _y_ = 20;

                                if(redRook1Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rookBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redRook1Rectangle1.from != NULL && redRook1Rectangle1.to != NULL) {
                                        if(strlen(redRook1Rectangle1.from) >= 2 && strlen(redRook1Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redRook1Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redRook2Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(rook2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redRook2Rectangle1.from != NULL && redRook2Rectangle1.to != NULL) {
                                        if(strlen(redRook2Rectangle1.from) >= 2 && strlen(redRook2Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redRook2Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redKnight1Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knightBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redKnight1Rectangle1.from != NULL && redKnight1Rectangle1.to != NULL) {
                                        if(strlen(redKnight1Rectangle1.from) >= 2 && strlen(redKnight1Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redKnight1Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redKnight2Rectangle1.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(knight2Black_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redKnight2Rectangle1.from != NULL && redKnight2Rectangle1.to != NULL) {
                                        if(strlen(redKnight2Rectangle1.from) >= 2 && strlen(redKnight2Rectangle1.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redKnight2Rectangle1.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redBishop1Square.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishopBlack_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redBishop1Square.from != NULL && redBishop1Square.to != NULL) {
                                        if(strlen(redBishop1Square.from) >= 2 && strlen(redBishop1Square.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redBishop1Square.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redBishop2Square.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(bishop2Black_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redBishop2Square.from != NULL && redBishop2Square.to != NULL) {
                                        if(strlen(redBishop2Square.from) >= 2 && strlen(redBishop2Square.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redBishop2Square.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redQueenSquare.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    if(redQueenSquare.from != NULL && redQueenSquare.to != NULL) {
                                        if(strlen(redQueenSquare.from) >= 2 && strlen(redQueenSquare.to) >= 2) {
                                            TextOut(hdc,
                                                    930+50,
                                                    _y_,
                                                    redQueenSquare.to,
                                                    GetTextSize("za"));
                                        }
                                    }
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                if(redKingSquare.posX == 1300) {
                                    hdcMem = CreateCompatibleDC(hdc);
                                    HBITMAP hBmp = ReplaceColor(kingBlack_s,0xff0000,0xc8c8ff,hdcMem);
                                    oldBitmap = SelectObject(hdcMem, hBmp);
                                    GetObject(hBmp, sizeof(bitmap), &bitmap);
                                    BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                    SelectObject(hdcMem, oldBitmap);
                                    ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                    _y_ += 31;
                                }

                                for(int o=0; o<8; o++) {
                                    if(redPawnsBase[o].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(pawnBlack_s,0xff0000,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(redPawnsBase[o].from != NULL && redPawnsBase[o].to != NULL) {
                                            if(strlen(redPawnsBase[o].from) >= 2 && strlen(redPawnsBase[o].to) >= 2) {
                                                TextOut(hdc,
                                                        930+50,
                                                        _y_,
                                                        redPawnsBase[o].to,
                                                        GetTextSize("za"));
                                            }
                                        }
                                        SelectObject(hdcMem, oldBitmap);
                                        ReleaseDC(hwnd, hdcMem); DeleteDC(hdcMem); DeleteObject(hBmp);
                                        _y_ += 31;
                                    }
                                }

                                for(int m=0; m<8; m++) {
                                    if(redQueenSquareK[m].posX == 1300) {
                                        hdcMem = CreateCompatibleDC(hdc);
                                        HBITMAP hBmp = ReplaceColor(queenBlack_s,0x00ff00,0xc8c8ff,hdcMem);
                                        oldBitmap = SelectObject(hdcMem, hBmp);
                                        GetObject(hBmp, sizeof(bitmap), &bitmap);
                                        BitBlt(hdc, 900+50, _y_, 30, 30, hdcMem, 0, 0, SRCCOPY);
                                        if(redQueenSquareK[m].from != NULL && redQueenSquareK[m].to != NULL) {
                                            if(strlen(redQueenSquareK[m].from) >= 2 && strlen(redQueenSquareK[m].to) >= 2) {
                                                TextOut(hdc,
                                                        930+50,
                                                        _y_,
                                                        redQueenSquareK[m].to,
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
                                            SetWindowText(hwnd_timer, "black player thinking ...");
                                            thread_1 = CreateThread(NULL, 0, callApi, NULL, 0, NULL);
                                        }
                                        break;
                                    }
                                }
                            }
                        } else if(turn == 'r') {

                            for(int k=0; k<8; k++) {

                                if(redPawnsBase[k].posX == i*100+20 &&
                                   redPawnsBase[k].posY == j*100+20) {

                                    clickedOne = 'r';
                                    redPawnsBase[k].clicked = TRUE;
                                    redPawnsBase[k].from = map(j, i);
                                    turn = 'r';

                                    strncpy(chosenPiece, "pr", 2);

                                    for(int l=0; l<8; l++) {
                                        greyPawnsBase[l].clicked = FALSE;
                                    }

                                    for(int l=0; l<8; l++) {
                                        if(l != k) {
                                            redPawnsBase[l].clicked = FALSE;
                                        }
                                    }
                                } else {
                                    if(redPawnsBase[k].clicked == TRUE) {
                                        redPawnsBase[k].to = map(j, i);
                                    }
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(clickedOne == 'r' &&
                                       redPawnsBase[k].clicked == TRUE &&
                                       redPawnsBase[k].firstTimeMove == TRUE) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

                                        for(int m=0; m<8; m++) {
                                            if(redPawnsBase[m].posY == redPawnsBase[k].posY + 100 &&
                                               (redPawnsBase[m].posX == redPawnsBase[k].posX + 100 || redPawnsBase[m].posX == redPawnsBase[k].posX - 100)) {
                                                ff = TRUE;
                                            }
                                            if(redPawnsBase[m].posY == redPawnsBase[k].posY + 100 &&
                                               redPawnsBase[m].posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redKnight1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redKnight1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redKnight2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redKnight2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redBishop1Square.posY == redPawnsBase[k].posY + 100 &&
                                               redBishop1Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redBishop2Square.posY == redPawnsBase[k].posY + 100 &&
                                               redBishop2Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redRook1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redRook1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redRook2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redRook2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redKnight1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redKnight1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redKnight2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redKnight2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redBishop1Square.posY == redPawnsBase[k].posY + 100 &&
                                               redBishop1Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redBishop2Square.posY == redPawnsBase[k].posY + 100 &&
                                               redBishop2Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redRook1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redRook1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(redRook2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               redRook2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                        }

                                        if(!ff &&
                                           j*100+20 == redPawnsBase[k].posY + 100 &&
                                          (i*100+20 == redPawnsBase[k].posX - 100 ||
                                           i*100+20 == redPawnsBase[k].posX + 100)) {

                                            turn = 'h';

                                            boolean ate = FALSE;

                                            int a0 = redPawnsBase[k].posX;
                                            int a1 = redPawnsBase[k].posY;

                                            boxes[j][i].clear = FALSE;
                                            boxes[redPawnsBase[k].posY/100][redPawnsBase[k].posX/100].clear = TRUE;
                                            redPawnsBase[k].posY = j*100+20;
                                            redPawnsBase[k].posX = i*100+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if((greyPawnsBase[l].posX == redPawnsBase[k].posX ||
                                                    greyPawnsBase[l].posX == redPawnsBase[k].posX) &&
                                                    greyPawnsBase[l].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(greyQueenSquareK[z].posX == i*100+20 &&
                                                   greyQueenSquareK[z].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(greyQueenSquare.posX == i*100+20 &&
                                               greyQueenSquare.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyBishop1Square.posX == i*100+20 &&
                                               greyBishop1Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyBishop2Square.posX == i*100+20 &&
                                               greyBishop2Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyKnight1Rectangle1.posX == i*100+20 &&
                                               greyKnight1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyKnight2Rectangle1.posX == i*100+20 &&
                                               greyKnight2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyRook1Rectangle1.posX == i*100+20 &&
                                               greyRook1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyRook2Rectangle1.posX == i*100+20 &&
                                               greyRook2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(greyPawnsBase[u].posX == redPawnsBase[k].posX &&
                                                   greyPawnsBase[u].posY == redPawnsBase[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff && fff) {

                                                redPawnsBase[k].posX = a0;
                                                redPawnsBase[k].posY = a1;

                                                turn = 'r';
                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redPawnsBase[k].posX ||
                                                        greyPawnsBase[l].posX == redPawnsBase[k].posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redPawnsBase[k].posX &&
                                                       greyPawnsBase[u].posY == redPawnsBase[k].posY) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    redPawnsBase[k].firstTimeMove = FALSE;
                                                    redPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                } else {
                                                    redPawnsBase[k].posX = a0;
                                                    redPawnsBase[k].posY = a1;

                                                    turn = 'r';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                                j*100+20 == redPawnsBase[k].posY + 100 &&
                                                i*100+20 == redPawnsBase[k].posX) {

                                            turn = 'h';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(greyPawnsBase[s].posX == redPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY - 100 == redPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == redPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY - 100 == redPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = redPawnsBase[k].posX;
                                                int a1 = redPawnsBase[k].posY;

                                                boxes[j][i].clear = FALSE;

                                                boxes[redPawnsBase[k].posY/100][redPawnsBase[k].posX/100].clear = TRUE;
                                                redPawnsBase[k].posY = j*100+20;

                                                boolean ffff = checkCheckRed(j, i);

                                                if(ffff) {
                                                    redPawnsBase[k].posX = a0;
                                                    redPawnsBase[k].posY = a1;

                                                    turn = 'r';
                                                } else {

                                                    redPawnsBase[k].firstTimeMove = FALSE;

                                                    redPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            } else {
                                                turn = 'r';
                                            }
                                        }

                                        else if(!fail &&
                                                j*100+20 == redPawnsBase[k].posY + 200 &&
                                                i*100+20 == redPawnsBase[k].posX) {

                                            turn = 'h';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(greyPawnsBase[s].posX == redPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY - 100 == redPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == redPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY - 100 == redPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = redPawnsBase[k].posX;
                                                int a1 = redPawnsBase[k].posY;

                                                boxes[j][i].clear = FALSE;

                                                boxes[redPawnsBase[k].posY/100][redPawnsBase[k].posX/100].clear = TRUE;
                                                redPawnsBase[k].posY = j*100+20;

                                                boolean ffff = checkCheckRed(j, i);

                                                if(ffff) {
                                                    redPawnsBase[k].posX = a0;
                                                    redPawnsBase[k].posY = a1;

                                                    turn = 'r';
                                                } else {

                                                    redPawnsBase[k].firstTimeMove = FALSE;

                                                    redPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            }
                                        }

                                    } else if(clickedOne == 'r' &&
                                              redPawnsBase[k].clicked) {

                                        boolean fail = FALSE;
                                        boolean ff = FALSE;

                                        for(int m=0; m<8; m++) {
                                            if(redPawnsBase[m].posY == redPawnsBase[k].posY + 100 &&
                                               (redPawnsBase[m].posX == redPawnsBase[k].posX + 100 || redPawnsBase[m].posX == redPawnsBase[k].posX - 100)) {
                                                ff = TRUE;
                                            }
                                            if(greyPawnsBase[m].posY == redPawnsBase[k].posY + 100 &&
                                               greyPawnsBase[m].posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyKnight1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyKnight2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop1Square.posY == redPawnsBase[k].posY + 100 &&
                                               greyBishop1Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop2Square.posY == redPawnsBase[k].posY + 100 &&
                                               greyBishop2Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyRook1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyRook2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyKnight1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyKnight2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyKnight2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop1Square.posY == redPawnsBase[k].posY + 100 &&
                                               greyBishop1Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyBishop2Square.posY == redPawnsBase[k].posY + 100 &&
                                               greyBishop2Square.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook1Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyRook1Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                            if(greyRook2Rectangle1.posY == redPawnsBase[k].posY + 100 &&
                                               greyRook2Rectangle1.posX == redPawnsBase[k].posX) {
                                                fail = TRUE;
                                            }
                                        }

                                        if(!ff &&
                                           j*100+20 == redPawnsBase[k].posY + 100 &&
                                          (i*100+20 == redPawnsBase[k].posX - 100 ||
                                           i*100+20 == redPawnsBase[k].posX + 100)) {

                                            turn = 'h';

                                            boolean ate = FALSE;

                                            int a0 = redPawnsBase[k].posX;
                                            int a1 = redPawnsBase[k].posY;

                                            boxes[redPawnsBase[k].posY/100][redPawnsBase[k].posX/100].clear = TRUE;
                                            boxes[j][i].clear = FALSE;
                                            redPawnsBase[k].posY = j*100+20;
                                            redPawnsBase[k].posX = i*100+20;

                                            boolean fff = TRUE;

                                            for(int l=0; l<8; l++) {
                                                if((greyPawnsBase[l].posX == redPawnsBase[k].posX ||
                                                    greyPawnsBase[l].posX == redPawnsBase[k].posX) &&
                                                    greyPawnsBase[l].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            for(int z=0; z<8; z++) {
                                                if(greyQueenSquareK[z].posX == i*100+20 &&
                                                   greyQueenSquareK[z].posY == j*100+20) {
                                                    fff = FALSE;
                                                }
                                            }
                                            if(greyQueenSquare.posX == i*100+20 &&
                                               greyQueenSquare.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyBishop1Square.posX == i*100+20 &&
                                               greyBishop1Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyBishop2Square.posX == i*100+20 &&
                                               greyBishop2Square.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyKnight1Rectangle1.posX == i*100+20 &&
                                               greyKnight1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyKnight2Rectangle1.posX == i*100+20 &&
                                               greyKnight2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyRook1Rectangle1.posX == i*100+20 &&
                                               greyRook1Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }
                                            if(greyRook2Rectangle1.posX == i*100+20 &&
                                               greyRook2Rectangle1.posY == j*100+20) {
                                                fff = FALSE;
                                            }

                                            for(int u=0; u<8; u++) {
                                                if(greyPawnsBase[u].posX == redPawnsBase[k].posX &&
                                                   greyPawnsBase[u].posY == redPawnsBase[k].posY) {
                                                    fff = FALSE;
                                                }
                                            }

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff && fff) {

                                                redPawnsBase[k].posX = a0;
                                                redPawnsBase[k].posY = a1;

                                                turn = 'r';
                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if(greyPawnsBase[l].posX == i*100+20 &&
                                                       greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                        ate = TRUE;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                    ate = TRUE;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redPawnsBase[k].posX &&
                                                       greyPawnsBase[u].posY == redPawnsBase[k].posY) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        ate = TRUE;
                                                        break;
                                                    }
                                                }

                                                if(ate) {
                                                    redPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                } else {

                                                    redPawnsBase[k].posX = a0;
                                                    redPawnsBase[k].posY = a1;

                                                    turn = 'r';
                                                }
                                            }
                                        }

                                        else if(!fail &&
                                           j*100+20 == redPawnsBase[k].posY + 100 &&
                                           i*100+20 == redPawnsBase[k].posX) {

                                            turn = 'h';

                                            boolean cant = FALSE;
                                            for(int s=0; s<8; s++) {
                                                if(greyPawnsBase[s].posX == redPawnsBase[k].posX &&
                                                   greyPawnsBase[s].posY - 100 == redPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                                if(redPawnsBase[s].posX == redPawnsBase[k].posX &&
                                                   redPawnsBase[s].posY - 100 == redPawnsBase[k].posY) {
                                                    cant = TRUE;
                                                }
                                            }
                                            if(!cant) {

                                                int a0 = redPawnsBase[k].posX;
                                                int a1 = redPawnsBase[k].posY;

                                                boxes[redPawnsBase[k].posY/100][redPawnsBase[k].posX/100].clear = TRUE;
                                                boxes[j][i].clear = FALSE;

                                                redPawnsBase[k].posY = j*100+20;

                                                boolean ffff = checkCheckRed(j, i);

                                                if(ffff) {

                                                    redPawnsBase[k].posX = a0;
                                                    redPawnsBase[k].posY = a1;

                                                    turn = 'r';
                                                } else {

                                                    redPawnsBase[k].clicked = FALSE;
                                                    turnChanged = TRUE;
                                                    done = TRUE;
                                                }
                                            } else {
                                                turn = 'r';
                                            }
                                        }
                                    }
                                }
                            }

                            boolean itdid = FALSE;

                            if(redKnight1Rectangle1.posX == i*100+20 &&
                               redKnight1Rectangle1.posY == j*100+20) {

                                clickedOne = 'r';
                                redKnight1Rectangle1.clicked = TRUE;
                                redKnight1Rectangle1.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "kr", 2);
                            } else if(clickedOne == 'r' &&
                                      redKnight1Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(redKnight1Rectangle1.clicked == TRUE) {
                                    redKnight1Rectangle1.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;

                                    clickedOne = 'r';

                                    redKnight1Rectangle1.clicked = FALSE;

                                    if(j*100+20 == redKnight1Rectangle1.posY - 200 &&
                                       i*100+20 == redKnight1Rectangle1.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                                turn = 'r';

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY - 200 &&
                                              i*100+20 == redKnight1Rectangle1.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY - 100 &&
                                              i*100+20 == redKnight1Rectangle1.posX - 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY + 100 &&
                                              i*100+20 == redKnight1Rectangle1.posX - 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        boolean fff = checkCheckRed(j, i);

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'g';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY + 200 &&
                                              i*100+20 == redKnight1Rectangle1.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY + 200 &&
                                              i*100+20 == redKnight1Rectangle1.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY - 100 &&
                                              i*100+20 == redKnight1Rectangle1.posX + 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight1Rectangle1.posY + 100 &&
                                              i*100+20 == redKnight1Rectangle1.posX + 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight1Rectangle1.posY;
                                            int a0 = redKnight1Rectangle1.posX;

                                            redKnight1Rectangle1.posX = i*100+20;
                                            redKnight1Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight1Rectangle1.posY = a1;
                                                redKnight1Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    }
                                }
                            }

                            itdid = FALSE;

                            if(redKnight2Rectangle1.posX == i*100+20 &&
                               redKnight2Rectangle1.posY == j*100+20) {

                                clickedOne = 'r';
                                redKnight2Rectangle1.clicked = TRUE;
                                redKnight2Rectangle1.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "kr", 2);
                            } else if(clickedOne == 'r' &&
                                      redKnight2Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(redKnight2Rectangle1.clicked == TRUE) {
                                    redKnight2Rectangle1.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;

                                    clickedOne = 'r';

                                    redKnight2Rectangle1.clicked = FALSE;

                                    if(j*100+20 == redKnight2Rectangle1.posY - 200 &&
                                       i*100+20 == redKnight2Rectangle1.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY - 200 &&
                                              i*100+20 == redKnight2Rectangle1.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY - 100 &&
                                              i*100+20 == redKnight2Rectangle1.posX - 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'r';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'h';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY + 100 &&
                                              i*100+20 == redKnight2Rectangle1.posX - 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'g';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY + 200 &&
                                              i*100+20 == redKnight2Rectangle1.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY + 200 &&
                                              i*100+20 == redKnight2Rectangle1.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY - 100 &&
                                              i*100+20 == redKnight2Rectangle1.posX + 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKnight2Rectangle1.posY + 100 &&
                                              i*100+20 == redKnight2Rectangle1.posX + 200) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKingSquare.posX == i*100+20 &&
                                           redKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(greyKingSquare.posX == i*100+20 &&
                                           greyKingSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKnight2Rectangle1.posY;
                                            int a0 = redKnight2Rectangle1.posX;

                                            redKnight2Rectangle1.posX = i*100+20;
                                            redKnight2Rectangle1.posY = j*100+20;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKnight2Rectangle1.posY = a1;
                                                redKnight2Rectangle1.posX = a0;

                                            } else {

                                                for(int t=0; t<8; t++) {
                                                    if(greyPawnsBase[t].posX == i*100+20 &&
                                                       greyPawnsBase[t].posY == j*100+20) {
                                                        greyPawnsBase[t].posX = 1300;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    }
                                }
                            }

                            itdid = FALSE;

                            if(redKingSquare.posX == i*100+20 &&
                               redKingSquare.posY == j*100+20) {

                                clickedOne = 'r';
                                redKingSquare.clicked = TRUE;
                                turn = 'r';
                                strncpy(chosenPiece, "cr", 2);
                            } else if(clickedOne == 'r' &&
                                      redKingSquare.clicked == TRUE) {
                                itdid = TRUE;
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    boolean failed = FALSE;

                                    clickedOne = 'r';

                                    redKingSquare.clicked = FALSE;

                                    if(j*100+20 == redKingSquare.posY &&
                                       i*100+20 == redKingSquare.posX - 200) {
                                        if(redRook1Rectangle1.posY == 0 &&
                                           redRook1Rectangle1.posX == 0) {
                                            if(redKingSquare.posY == 0 &&
                                               redKingSquare.posX == 400) {
                                                boolean isthere = FALSE;
                                                if(greyRook1Rectangle1.posX == 300 &&
                                                   greyRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == 200 &&
                                                   greyRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == 100 &&
                                                   greyRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 300 &&
                                                   greyRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 200 &&
                                                   greyRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 100 &&
                                                   greyRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 300 &&
                                                   redRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 200 &&
                                                   redRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 100 &&
                                                   redRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 300 &&
                                                   redRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 200 &&
                                                   redRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 100 &&
                                                   redRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 300 &&
                                                   greyBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 200 &&
                                                   greyBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 100 &&
                                                   greyBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 300 &&
                                                   greyBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 200 &&
                                                   greyBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 100 &&
                                                   greyBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 300 &&
                                                   redBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 200 &&
                                                   redBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 100 &&
                                                   redBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 300 &&
                                                   redBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 200 &&
                                                   redBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 100 &&
                                                   redBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 300 &&
                                                   greyKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 200 &&
                                                   greyKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 100 &&
                                                   greyKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 300 &&
                                                   greyKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 200 &&
                                                   greyKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 100 &&
                                                   greyKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 300 &&
                                                   redKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 200 &&
                                                   redKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 100 &&
                                                   redKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 300 &&
                                                   redKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 200 &&
                                                   redKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 100 &&
                                                   redKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 300 &&
                                                   greyQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 200 &&
                                                   greyQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 100 &&
                                                   greyQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 300 &&
                                                   redQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 200 &&
                                                   redQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 100 &&
                                                   redQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !redKingMoved && !redRook1Moved) {
                                                    redKingSquare.posX -= 200;
                                                    redRook1Rectangle1.posX += 300;
                                                    redKingMoved = TRUE;
                                                    redRook1Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'h';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*100+20 == redKingSquare.posY &&
                                       i*100+20 == redKingSquare.posX + 200) {
                                        if(redRook2Rectangle1.posY == 0 &&
                                           redRook2Rectangle1.posX == 700) {
                                            if(redKingSquare.posY == 0 &&
                                               redKingSquare.posX == 400) {
                                                boolean isthere = FALSE;
                                                if(greyRook1Rectangle1.posX == 500 &&
                                                   greyRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook1Rectangle1.posX == 600 &&
                                                   greyRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 500 &&
                                                   greyRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyRook2Rectangle1.posX == 600 &&
                                                   greyRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 500 &&
                                                   redRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook1Rectangle1.posX == 600 &&
                                                   redRook1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 500 &&
                                                   redRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redRook2Rectangle1.posX == 600 &&
                                                   redRook2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 500 &&
                                                   greyBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop1Square.posX == 600 &&
                                                   greyBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 500 &&
                                                   greyBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyBishop2Square.posX == 600 &&
                                                   greyBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 500 &&
                                                   redBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop1Square.posX == 600 &&
                                                   redBishop1Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 500 &&
                                                   redBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redBishop2Square.posX == 600 &&
                                                   redBishop2Square.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 500 &&
                                                   greyKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight1Rectangle1.posX == 600 &&
                                                   greyKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 500 &&
                                                   greyKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyKnight2Rectangle1.posX == 600 &&
                                                   greyKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 500 &&
                                                   redKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight1Rectangle1.posX == 600 &&
                                                   redKnight1Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 500 &&
                                                   redKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redKnight2Rectangle1.posX == 600 &&
                                                   redKnight2Rectangle1.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 500 &&
                                                   greyQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(greyQueenSquare.posX == 600 &&
                                                   greyQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 500 &&
                                                   redQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(redQueenSquare.posX == 600 &&
                                                   redQueenSquare.posY == 0) {
                                                    isthere = TRUE;
                                                }
                                                if(!isthere && !redKingMoved && !redRook2Moved) {
                                                    redKingSquare.posX += 200;
                                                    redRook2Rectangle1.posX -= 200;
                                                    redKingMoved = TRUE;
                                                    redRook2Moved = TRUE;
                                                    turnChanged = TRUE;
                                                    turn = 'h';
                                                    done = TRUE;
                                                }
                                            }
                                        }
                                    }

                                    if(j*100+20 == redKingSquare.posY - 100 &&
                                       i*100+20 == redKingSquare.posX) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posY -= 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY - 100 &&
                                              i*100+20 == redKingSquare.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posY -= 100;
                                            redKingSquare.posX += 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY &&
                                              i*100+20 == redKingSquare.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posX += 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY + 100 &&
                                              i*100+20 == redKingSquare.posX + 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posX += 100;
                                            redKingSquare.posY += 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY + 100 &&
                                              i*100+20 == redKingSquare.posX) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posY += 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY + 100 &&
                                              i*100+20 == redKingSquare.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posX -= 100;
                                            redKingSquare.posY += 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY &&
                                              i*100+20 == redKingSquare.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posX -= 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    } else if(j*100+20 == redKingSquare.posY - 100 &&
                                              i*100+20 == redKingSquare.posX - 100) {

                                        for(int t=0; t<8; t++) {
                                            if(redPawnsBase[t].posX == i*100+20 &&
                                               redPawnsBase[t].posY == j*100+20) {
                                                failed = TRUE;
                                            }
                                        }
                                        if(redQueenSquare.posX == i*100+20 &&
                                           redQueenSquare.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop1Square.posX == i*100+20 &&
                                           redBishop1Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redBishop2Square.posX == i*100+20 &&
                                           redBishop2Square.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight1Rectangle1.posX == i*100+20 &&
                                           redKnight1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redKnight2Rectangle1.posX == i*100+20 &&
                                           redKnight2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook1Rectangle1.posX == i*100+20 &&
                                           redRook1Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }
                                        if(redRook2Rectangle1.posX == i*100+20 &&
                                           redRook2Rectangle1.posY == j*100+20) {
                                            failed = TRUE;
                                        }

                                        if(!failed) {

                                            int a1 = redKingSquare.posY;
                                            int a0 = redKingSquare.posX;

                                            redKingSquare.posX -= 100;
                                            redKingSquare.posY -= 100;

                                            boolean ffff = checkCheckRed(j, i);

                                            if(ffff) {

                                                redKingSquare.posY = a1;
                                                redKingSquare.posX = a0;

                                            } else {

                                                for(int l=0; l<8; l++) {
                                                    if((greyPawnsBase[l].posX == redKingSquare.posX ||
                                                        greyPawnsBase[l].posX == redKingSquare.posX) &&
                                                        greyPawnsBase[l].posY == j*100+20) {
                                                        greyPawnsBase[l].posX = 1300;
                                                        break;
                                                    }
                                                }
                                                if(greyQueenSquare.posX == i*100+20 &&
                                                   greyQueenSquare.posY == j*100+20) {
                                                    greyQueenSquare.posX = 1300;
                                                }
                                                for(int z=0; z<8; z++) {
                                                    if(greyQueenSquareK[z].posX == i*100+20 &&
                                                       greyQueenSquareK[z].posY == j*100+20) {
                                                        greyQueenSquareK[z].posX = 1300;
                                                    }
                                                }
                                                if(greyBishop1Square.posX == i*100+20 &&
                                                   greyBishop1Square.posY == j*100+20) {
                                                    greyBishop1Square.posX = 1300;
                                                }
                                                if(greyBishop2Square.posX == i*100+20 &&
                                                   greyBishop2Square.posY == j*100+20) {
                                                    greyBishop2Square.posX = 1300;
                                                }
                                                if(greyKnight1Rectangle1.posX == i*100+20 &&
                                                   greyKnight1Rectangle1.posY == j*100+20) {
                                                    greyKnight1Rectangle1.posX = 1300;
                                                }
                                                if(greyKnight2Rectangle1.posX == i*100+20 &&
                                                   greyKnight2Rectangle1.posY == j*100+20) {
                                                    greyKnight2Rectangle1.posX = 1300;
                                                }
                                                if(greyRook1Rectangle1.posX == i*100+20 &&
                                                   greyRook1Rectangle1.posY == j*100+20) {
                                                    greyRook1Rectangle1.posX = 1300;
                                                }
                                                if(greyRook2Rectangle1.posX == i*100+20 &&
                                                   greyRook2Rectangle1.posY == j*100+20) {
                                                    greyRook2Rectangle1.posX = 1300;
                                                }

                                                for(int u=0; u<8; u++) {
                                                    if(greyPawnsBase[u].posX == redKingSquare.posX &&
                                                       greyPawnsBase[u].posY == redKingSquare.posY - 100) {
                                                        greyPawnsBase[u].posX = 1300;
                                                        break;
                                                    }
                                                }

                                                turn = 'h';
                                                turnChanged = TRUE;
                                                redKingMoved = TRUE;
                                                done = TRUE;
                                            }
                                        } else {
                                            turn = 'r';
                                        }
                                    }
                                }
                            }

                            boolean changeii = FALSE;

                            for(int z=0; z<8; z++) {
                                if(redPawnsBase[z].posY == 700) {
                                    strncpy(chosenPiece, "qr", 2);
                                    changeii = TRUE;
                                    int x = redPawnsBase[z].posX;
                                    int y = redPawnsBase[z].posY;
                                    redQueenSquareK[z].posX = x;
                                    redQueenSquareK[z].posY = y;
                                    redQueenSquareK[z].from = map(j, i);
                                    redQueenSquareK[z].to = map(j, i);

                                    redPawnsBase[z].posX = 1300;
                                    redPawnsBase[z].posY = -1000;

                                    turn = 'h';
                                }
                            }

                            itdid = FALSE;

                            if(redQueenSquare.posX == i*100+20 &&
                               redQueenSquare.posY == j*100+20) {

                                clickedOne = 'r';
                                redQueenSquare.clicked = TRUE;
                                redQueenSquare.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "qr", 2);
                            } else if(clickedOne == 'r' &&
                                      redQueenSquare.clicked == TRUE) {
                                itdid = TRUE;
                                if(redQueenSquare.clicked == TRUE) {
                                    redQueenSquare.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    redQueenSquare.clicked = FALSE;

                                    int a1 = redQueenSquare.posY;
                                    int a0 = redQueenSquare.posX;

                                    boxes[redQueenSquare.posY/100][redQueenSquare.posX/100].clear = TRUE;

                                    boolean f = FALSE;

                                    redQueenSquare.failedpath = FALSE;

                                    if(i*100+20 == redQueenSquare.posX) {
                                        f = moveRedQueen(msg, j, i, j*100+20 - redQueenSquare.posY, j*100+20 - redQueenSquare.posY);
                                        f = redQueenSquare.failedpath;
                                    } else if(j*100+20 == redQueenSquare.posY) {
                                        f = moveRedQueenSide(msg, j, i, i*100+20 - redQueenSquare.posX, i*100+20 - redQueenSquare.posX);
                                        f = redQueenSquare.failedpath;
                                    } else if(i*100+20 != redQueenSquare.posX &&
                                       j*100+20 != redQueenSquare.posY) {
                                        f = moveRedQueenDiagonally(msg, j, i, j*100+20 - redQueenSquare.posY, i*100+20 - redQueenSquare.posX, j*100+20 - redQueenSquare.posY, i*100+20 - redQueenSquare.posX);
                                        f = redQueenSquare.failedpath;
                                    }

                                    boolean fff = checkCheckRed(j, i);

                                    if(f || fff) {

                                        redQueenSquare.posY = a1;
                                        redQueenSquare.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            redPawnsBase[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        redPawnsBase[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            for(int z=0; z<8; z++) {

                                itdid = FALSE;

                                if(changeii == FALSE &&
                                   redQueenSquareK[z].posX == i*100+20 &&
                                   redQueenSquareK[z].posY == j*100+20) {

                                    clickedOne = 'r';
                                    redQueenSquareK[z].clicked = TRUE;
                                    turn = 'r';
                                    strncpy(chosenPiece, "qr", 2);
                                } else if(clickedOne == 'r' &&
                                          redQueenSquareK[z].clicked == TRUE) {
                                    itdid = TRUE;
                                }

                                if(boxes[j][i].clicked == TRUE) {

                                    if(itdid && changeii == FALSE) {

                                        clickedOne = 'r';
                                        redQueenSquareK[z].clicked = FALSE;

                                        int a1 = redQueenSquareK[z].posY;
                                        int a0 = redQueenSquareK[z].posX;

                                        boolean f = FALSE;

                                        redQueenSquareK[z].failedpath = FALSE;

                                        if(i*100+20 == redQueenSquareK[z].posX) {
                                            f = moveRedQueenK(msg, j, i, j*100+20 - redQueenSquareK[z].posY, j*100+20 - redQueenSquareK[z].posY, z);
                                            f = redQueenSquareK[z].failedpath;
                                        } else if(j*100+20 == redQueenSquareK[z].posY) {
                                            f = moveRedQueenSideK(msg, j, i, i*100+20 - redQueenSquareK[z].posX, i*100+20 - redQueenSquareK[z].posX, z);
                                            f = redQueenSquareK[z].failedpath;
                                        } else if(i*100+20 != redQueenSquareK[z].posX &&
                                           j*100+20 != redQueenSquareK[z].posY) {
                                            f = moveRedQueenDiagonallyK(msg, j, i, j*100+20 - redQueenSquareK[z].posY, i*100+20 - redQueenSquareK[z].posX, j*100+20 - redQueenSquareK[z].posY, i*100+20 - redQueenSquareK[z].posX, z);
                                            f = redQueenSquareK[z].failedpath;
                                        }

                                        boolean fff = checkCheckRed(j, i);

                                        if(f || fff) {

                                            redQueenSquareK[z].posY = a1;
                                            redQueenSquareK[z].posX = a0;

                                            turn = 'r';
                                        }

                                        else {
                                            for(int a=0; a<8; a++) {
                                                greyPawnsBase[a].clicked = FALSE;
                                            }
                                            for(int a=0; a<8; a++) {
                                                redPawnsBase[a].clicked = FALSE;
                                            }
                                            boxes[j][i].clear = FALSE;
                                            turn = 'h';
                                            turnChanged = TRUE;
                                            done = TRUE;
                                        }

                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            redPawnsBase[a].clicked = FALSE;
                                        }

                                        itdid = FALSE;
                                    }
                                }
                            }

                            itdid = FALSE;

                            if(redBishop1Square.posX == i*100+20 &&
                               redBishop1Square.posY == j*100+20) {

                                clickedOne = 'r';
                                redBishop1Square.clicked = TRUE;
                                redBishop1Square.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "br", 2);
                            } else if(clickedOne == 'r' &&
                                      redBishop1Square.clicked == TRUE) {
                                itdid = TRUE;
                                if(redBishop1Square.clicked == TRUE) {
                                    redBishop1Square.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    redBishop1Square.clicked = FALSE;

                                    int a1 = redBishop1Square.posY;
                                    int a0 = redBishop1Square.posX;

                                    boolean f = FALSE;

                                    redBishop1Square.failedpath = FALSE;

                                    if(i*100+20 != redBishop1Square.posX &&
                                       j*100+20 != redBishop1Square.posY) {
                                        f = moveRedBishop1(msg, j, i, j*100+20 - redBishop1Square.posY, i*100+20 - redBishop1Square.posX, j*100+20 - redBishop1Square.posY, i*100+20 - redBishop1Square.posX);
                                        f = redBishop1Square.failedpath;
                                    } else {
                                        f = redBishop1Square.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckRed(j, i);

                                    if(f || fff) {

                                        redBishop1Square.posY = a1;
                                        redBishop1Square.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            redPawnsBase[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        redPawnsBase[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;

                            if(redBishop2Square.posX == i*100+20 &&
                               redBishop2Square.posY == j*100+20) {

                                clickedOne = 'r';
                                redBishop2Square.clicked = TRUE;
                                redBishop2Square.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "br", 2);
                            } else if(clickedOne == 'r' &&
                                      redBishop2Square.clicked == TRUE) {
                                itdid = TRUE;
                                if(redBishop2Square.clicked == TRUE) {
                                    redBishop2Square.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    redBishop2Square.clicked = FALSE;

                                    int a1 = redBishop2Square.posY;
                                    int a0 = redBishop2Square.posX;

                                    boolean f = FALSE;

                                    redBishop2Square.failedpath = FALSE;

                                    if(i*100+20 != redBishop2Square.posX &&
                                       j*100+20 != redBishop2Square.posY) {
                                        f = moveRedBishop2(msg, j, i, j*100+20 - redBishop2Square.posY, i*100+20 - redBishop2Square.posX, j*100+20 - redBishop2Square.posY, i*100+20 - redBishop2Square.posX);
                                        f = redBishop2Square.failedpath;
                                    } else {
                                        f = redBishop2Square.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckRed(j, i);

                                    if(f || fff) {

                                        redBishop2Square.posY = a1;
                                        redBishop2Square.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            redPawnsBase[a].clicked = FALSE;
                                        }
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        if(1==2) SetWindowText(hwnd, "Grey move");
                                        turnChanged = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        redPawnsBase[a].clicked = FALSE;
                                    }

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;

                            if(redRook1Rectangle1.posX == i*100+20 &&
                               redRook1Rectangle1.posY == j*100+20) {

                                clickedOne = 'r';
                                redRook1Rectangle1.clicked = TRUE;
                                redRook1Rectangle1.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "rr", 2);
                            } else if(clickedOne == 'r' &&
                                      redRook1Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(redRook1Rectangle1.clicked == TRUE) {
                                    redRook1Rectangle1.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    redRook1Rectangle1.clicked = FALSE;

                                    int a1 = redRook1Rectangle1.posY;
                                    int a0 = redRook1Rectangle1.posX;

                                    boxes[redRook1Rectangle1.posY/100][redRook1Rectangle1.posX/100].clear = TRUE;

                                    boolean f = FALSE;

                                    redRook1Rectangle1.failedpath = FALSE;

                                    if(i*100+20 == redRook1Rectangle1.posX) {
                                        f = moveRedRook1(msg, j, i, j*100+20 - redRook1Rectangle1.posY, j*100+20 - redRook1Rectangle1.posY);
                                        f = redRook1Rectangle1.failedpath;
                                    } else if(j*100+20 == redRook1Rectangle1.posY) {
                                        f = moveRedRook1Side(msg, j, i, i*100+20 - redRook1Rectangle1.posX, i*100+20 - redRook1Rectangle1.posX);
                                        f = redRook1Rectangle1.failedpath;
                                    } else {
                                        f = redRook1Rectangle1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckRed(j, i);

                                    if(f || fff) {

                                        redRook1Rectangle1.posY = a1;
                                        redRook1Rectangle1.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            redPawnsBase[a].clicked = FALSE;
                                        }
                                        greyQueenSquare.clicked = FALSE;
                                        greyRook2Rectangle1.clicked = FALSE;
                                        greyQueenSquare.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        redRook1Moved = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        redPawnsBase[a].clicked = FALSE;
                                    }
                                    greyQueenSquare.clicked = FALSE;
                                    greyRook2Rectangle1.clicked = FALSE;
                                    greyQueenSquare.clicked = FALSE;

                                    itdid = FALSE;
                                }
                            }

                            itdid = FALSE;

                            if(redRook2Rectangle1.posX == i*100+20 &&
                               redRook2Rectangle1.posY == j*100+20) {

                                clickedOne = 'r';
                                redRook2Rectangle1.clicked = TRUE;
                                redRook2Rectangle1.from = map(j, i);
                                turn = 'r';
                                strncpy(chosenPiece, "rr", 2);
                            } else if(clickedOne == 'r' &&
                                      redRook2Rectangle1.clicked == TRUE) {
                                itdid = TRUE;
                                if(redRook2Rectangle1.clicked == TRUE) {
                                    redRook2Rectangle1.to = map(j, i);
                                }
                            }

                            if(boxes[j][i].clicked == TRUE) {

                                if(itdid) {

                                    clickedOne = 'r';
                                    redRook2Rectangle1.clicked = FALSE;

                                    int a1 = redRook2Rectangle1.posY;
                                    int a0 = redRook2Rectangle1.posX;

                                    boxes[redRook2Rectangle1.posY/100][redRook2Rectangle1.posX/100].clear = TRUE;

                                    boolean f = FALSE;

                                    redRook2Rectangle1.failedpath = FALSE;

                                    if(i*100+20 == redRook2Rectangle1.posX) {
                                        f = moveRedRook2(msg, j, i, j*100+20 - redRook2Rectangle1.posY, j*100+20 - redRook2Rectangle1.posY);
                                        f = redRook2Rectangle1.failedpath;
                                    } else if(j*100+20 == redRook2Rectangle1.posY) {
                                        f = moveRedRook2Side(msg, j, i, i*100+20 - redRook2Rectangle1.posX, i*100+20 - redRook2Rectangle1.posX);
                                        f = redRook2Rectangle1.failedpath;
                                    } else {
                                        f = redRook2Rectangle1.failedpath = TRUE;
                                    }

                                    boolean fff = checkCheckRed(j, i);

                                    if(f || fff) {

                                        redRook2Rectangle1.posY = a1;
                                        redRook2Rectangle1.posX = a0;

                                        turn = 'r';
                                    }

                                    else {
                                        for(int a=0; a<8; a++) {
                                            greyPawnsBase[a].clicked = FALSE;
                                        }
                                        for(int a=0; a<8; a++) {
                                            redPawnsBase[a].clicked = FALSE;
                                        }
                                        greyQueenSquare.clicked = FALSE;
                                        greyRook1Rectangle1.clicked = FALSE;
                                        greyQueenSquare.clicked = FALSE;
                                        boxes[j][i].clear = FALSE;
                                        turn = 'h';
                                        turnChanged = TRUE;
                                        redRook2Moved = TRUE;
                                        done = TRUE;
                                    }

                                    for(int a=0; a<8; a++) {
                                        greyPawnsBase[a].clicked = FALSE;
                                    }
                                    for(int a=0; a<8; a++) {
                                        redPawnsBase[a].clicked = FALSE;
                                    }
                                    greyQueenSquare.clicked = FALSE;
                                    greyRook1Rectangle1.clicked = FALSE;
                                    greyQueenSquare.clicked = FALSE;

                                    itdid = FALSE;
                                }
                            }

                            boolean efe = checkCheckRed(j, i);

                            boolean checked = FALSE;

                            int ppx = redKingSquare.posX;
                            int ppy = redKingSquare.posY;

                            if(!efe) {
                                checked = FALSE;
                                redKingSquare.posX -= 100;
                                efe = checkCheckRed(j, i);
                                if(!efe) {
                                    checked = FALSE;
                                    redKingSquare.posX += 100;
                                } else {
                                    checked = TRUE;
                                    redKingSquare.posX += 100;
                                    redKingSquare.posY -= 100;
                                    redKingSquare.posX -= 100;
                                    efe = checkCheckRed(j, i);
                                    if(!efe) {
                                        checked = FALSE;
                                        redKingSquare.posY += 100;
                                        redKingSquare.posX += 100;
                                    } else {
                                        checked = TRUE;
                                        redKingSquare.posY += 100;
                                        redKingSquare.posX += 100;
                                        redKingSquare.posY -= 100;
                                        efe = checkCheckRed(j, i);
                                        if(!efe) {
                                            checked = FALSE;
                                            redKingSquare.posY += 100;
                                        } else {
                                            checked = TRUE;
                                            redKingSquare.posY += 100;
                                            redKingSquare.posY -= 100;
                                            redKingSquare.posX += 100;
                                            efe = checkCheckRed(j, i);
                                            if(!efe) {
                                                checked = FALSE;
                                                redKingSquare.posY += 100;
                                                redKingSquare.posX -= 100;
                                            } else {
                                                checked = TRUE;
                                                redKingSquare.posY += 100;
                                                redKingSquare.posX -= 100;
                                                redKingSquare.posX += 100;
                                                efe = checkCheckRed(j, i);
                                                if(!efe) {
                                                    checked = FALSE;
                                                    redKingSquare.posX -= 100;
                                                    redKingSquare.posY += 100;
                                                    redKingSquare.posX += 100;
                                                } else {
                                                    checked = TRUE;
                                                    redKingSquare.posX -= 100;
                                                    redKingSquare.posY += 100;
                                                    redKingSquare.posX += 100;
                                                    efe = checkCheckRed(j, i);
                                                    if(!efe) {
                                                        checked = FALSE;
                                                        redKingSquare.posY -= 100;
                                                        redKingSquare.posX -= 100;
                                                    } else {
                                                        checked = TRUE;
                                                        redKingSquare.posY -= 100;
                                                        redKingSquare.posX -= 100;
                                                        redKingSquare.posY += 100;
                                                        efe = checkCheckRed(j, i);
                                                        if(!efe) {
                                                            checked = FALSE;
                                                            redKingSquare.posY -= 100;
                                                            redKingSquare.posY += 100;
                                                            redKingSquare.posX -= 100;
                                                        } else {
                                                            checked = TRUE;
                                                            redKingSquare.posY -= 100;
                                                            redKingSquare.posY += 100;
                                                            redKingSquare.posX -= 100;
                                                            efe = checkCheckRed(j, i);
                                                            if(!efe) {
                                                                checked = FALSE;
                                                                redKingSquare.posY -= 100;
                                                                redKingSquare.posX += 100;
                                                            } else {
                                                                checked = TRUE;
                                                                redKingSquare.posY -= 100;
                                                                redKingSquare.posX += 100;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                checked = TRUE;
                                redKingSquare.posX -= 100;
                                efe = checkCheckRed(j, i);
                                if(!efe) {
                                    checked = FALSE;
                                    redKingSquare.posX += 100;
                                } else {
                                    checked = TRUE;
                                    redKingSquare.posX += 100;
                                    redKingSquare.posY -= 100;
                                    redKingSquare.posX -= 100;
                                    efe = checkCheckRed(j, i);
                                    if(!efe) {
                                        checked = FALSE;
                                        redKingSquare.posY += 100;
                                        redKingSquare.posX += 100;
                                    } else {
                                        checked = TRUE;
                                        redKingSquare.posY += 100;
                                        redKingSquare.posX += 100;
                                        redKingSquare.posY -= 100;
                                        efe = checkCheckRed(j, i);
                                        if(!efe) {
                                            checked = FALSE;
                                            redKingSquare.posY += 100;
                                        } else {
                                            checked = TRUE;
                                            redKingSquare.posY += 100;
                                            redKingSquare.posY -= 100;
                                            redKingSquare.posX += 100;
                                            efe = checkCheckRed(j, i);
                                            if(!efe) {
                                                checked = FALSE;
                                                redKingSquare.posY += 100;
                                                redKingSquare.posX -= 100;
                                            } else {
                                                checked = TRUE;
                                                redKingSquare.posY += 100;
                                                redKingSquare.posX -= 100;
                                                redKingSquare.posX += 100;
                                                efe = checkCheckRed(j, i);
                                                if(!efe) {
                                                    checked = FALSE;
                                                    redKingSquare.posX -= 100;
                                                    redKingSquare.posY += 100;
                                                    redKingSquare.posX += 100;
                                                } else {
                                                    checked = TRUE;
                                                    redKingSquare.posX -= 100;
                                                    redKingSquare.posY += 100;
                                                    redKingSquare.posX += 100;
                                                    efe = checkCheckRed(j, i);
                                                    if(!efe) {
                                                        checked = FALSE;
                                                        redKingSquare.posY -= 100;
                                                        redKingSquare.posX -= 100;
                                                    } else {
                                                        checked = TRUE;
                                                        redKingSquare.posY -= 100;
                                                        redKingSquare.posX -= 100;
                                                        redKingSquare.posY += 100;
                                                        efe = checkCheckRed(j, i);
                                                        if(!efe) {
                                                            checked = FALSE;
                                                            redKingSquare.posY -= 100;
                                                            redKingSquare.posY += 100;
                                                            redKingSquare.posX -= 100;
                                                        } else {
                                                            checked = TRUE;
                                                            redKingSquare.posY -= 100;
                                                            redKingSquare.posY += 100;
                                                            redKingSquare.posX -= 100;
                                                            efe = checkCheckRed(j, i);
                                                            if(!efe) {
                                                                checked = FALSE;
                                                                redKingSquare.posY -= 100;
                                                                redKingSquare.posX += 100;
                                                            } else {
                                                                checked = TRUE;
                                                                redKingSquare.posY -= 100;
                                                                redKingSquare.posX += 100;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            HBRUSH rBrush;
                            rBrush = CreateSolidBrush(RGB(155, 100, 100));
                            RECT r = {i*100+20, j*100+20, i*100+20 + 16, j*100+20 + 16};
                            for(int t=0; t<8; t++) {
                                if(turn == 'h' && redPawnsBase[t].posX == i*100+20 &&
                                   redPawnsBase[t].posY == j*100+20) {
                                    if(TRUE==done) {
                                        int l1_x1 = i*100+20;
                                        int l1_y1 = j*100+20 + 8;
                                        int l1_x2 = i*100+20 + 8;
                                        int l1_y2 = j*100+20 + 16;
                                        int l2_x1 = i*100+20 + 8;
                                        int l2_y1 = j*100+20 + 16;
                                        int l2_x2 = i*100+20 + 16;
                                        int l2_y2 = j*100+20;
                                        PAINTSTRUCT pntS;
                                        HPEN pen, oldPen;
                                        pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));
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
                                if(turn == 'r' && redPawnsBase[t].posX == i*100+20 &&
                                   redPawnsBase[t].posY == j*100+20) {
                                    FillRect(hdc, &r, rBrush);
                                }
                            }
                            if(turn == 'h' && redKingSquare.posX == i*100+20 &&
                               redKingSquare.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redKingSquare.posX == i*100+20 &&
                               redKingSquare.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && redQueenSquare.posX == i*100+20 &&
                               redQueenSquare.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redQueenSquare.posX == i*100+20 &&
                               redQueenSquare.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && redKnight1Rectangle1.posX == i*100+20 &&
                               redKnight1Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redKnight1Rectangle1.posX == i*100+20 &&
                               redKnight1Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && redKnight2Rectangle1.posX == i*100+20 &&
                               redKnight2Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redKnight2Rectangle1.posX == i*100+20 &&
                               redKnight2Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && redBishop1Square.posX == i*100+20 &&
                               redBishop1Square.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redBishop1Square.posX == i*100+20 &&
                               redBishop1Square.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && redBishop2Square.posX == i*100+20 &&
                               redBishop2Square.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && redBishop2Square.posX == i*100+20 &&
                               redBishop2Square.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redBishop2Square.posX == i*100+20 &&
                               redBishop2Square.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'h' && redRook1Rectangle1.posX == i*100+20 &&
                               redRook1Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redRook1Rectangle1.posX == i*100+20 &&
                               redRook1Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                            }
                            if(turn == 'r' && redRook2Rectangle1.posX == i*100+20 &&
                               redRook2Rectangle1.posY == j*100+20) {
                                FillRect(hdc, &r, rBrush);
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'h' && redRook2Rectangle1.posX == i*100+20 &&
                               redRook2Rectangle1.posY == j*100+20) {
                                if(TRUE==done) {
                                    int l1_x1 = i*100+20;
                                    int l1_y1 = j*100+20 + 8;
                                    int l1_x2 = i*100+20 + 8;
                                    int l1_y2 = j*100+20 + 16;
                                    int l2_x1 = i*100+20 + 8;
                                    int l2_y1 = j*100+20 + 16;
                                    int l2_x2 = i*100+20 + 16;
                                    int l2_y2 = j*100+20;
                                    PAINTSTRUCT pntS;
                                    HPEN pen, oldPen;
                                    pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 200));	
                                    oldPen = (HPEN)SelectObject(hdc, pen);				
                                    MoveToEx(hdc, l1_x1, l1_y1, NULL);
                                    LineTo(hdc, l1_x2, l1_y2);
                                    MoveToEx(hdc, l2_x1, l2_y1, NULL);
                                    LineTo(hdc, l2_x2, l2_y2);
                                    SelectObject(hdc, oldPen); 
                                    DeleteObject(pen);
                                }
                            }
                            if(turn == 'r' && redRook2Rectangle1.posX == i*100+20 &&
                               redRook2Rectangle1.posY == j*100+20) {
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
            HMENU hMenu, hSubMenu;
            HICON hIcon, hIconSm;
            
            hMenu = CreateMenu();

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_CLICK_ME_NEW_GAME, "play game");
            AppendMenu(hSubMenu, MF_STRING, ID_FILE_DOWNLOAD, "get mine");
            AppendMenu(hSubMenu, MF_STRING, ID_CAPTURE_SCREEN, "snapshot");
            AppendMenu(hSubMenu, MF_STRING, ID_CLICK_ME_QUIT, "exit game");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Chess");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_PC_GAME, "1 player (versus expert)");
            AppendMenu(hSubMenu, MF_STRING, ID_HUMAN_GAME, "2 players (versus eachother)");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Options");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_0MIN, "no time");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_5MIN, "5 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_10MIN, "10 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_15MIN, "15 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_20MIN, "20 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_25MIN, "25 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_30MIN, "30 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_35MIN, "35 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_40MIN, "40 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_45MIN, "45 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_50MIN, "50 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_55MIN, "55 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_60MIN, "60 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_65MIN, "65 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_70MIN, "70 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_75MIN, "75 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_80MIN, "80 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_85MIN, "85 mins");
            AppendMenu(hSubMenu, MF_STRING, ID_TIMER_90MIN, "90 mins");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Timer (2 player menu)");

            SetMenu(hwnd, hMenu);

            hIcon = LoadImage(NULL, "Icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
            if(hIcon)
                SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

            hIconSm = LoadImage(NULL, "Icon.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
            if(hIconSm)
                SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);

            char b[100] = "white";
            y = 0; h = 15;
            x = 825+50; w = 120;
            hwnd_white = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
            SetWindowText(hwnd_white, b);

            char c[100] = "black";
            y = 0; h = 15;
            x = 900+50; w = 120;
            hwnd_black = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
            SetWindowText(hwnd_black, c);

            y = 850+50; h = 20;
            x = 10; w = 420;
            hwnd_timer = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);

            y = 830+50; h = 48;
            x = 450; w = 124;
  	    hwnd_newgamebtn = CreateWindowEx(0, "BUTTON", "new game", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
								x, y, w, h, hwnd, (HMENU) IDC_NEW_GAME_BUTTON, GetModuleHandle(NULL), NULL);
            hbit = (HBITMAP)LoadImage(hInst, "play.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            SendMessage(hwnd_newgamebtn, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hbit);
            
            y = 830+50; h = 48;
            x = 828; w = 144;
            hwnd_downloadbtn = CreateWindowEx(0, "BUTTON", "download source", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP, 
                                 x, y, w, h, hwnd, (HMENU) IDC_DOWNLOAD_BUTTON, GetModuleHandle(NULL), NULL);
            hbit = (HBITMAP)LoadImage(hInst, "download.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            SendMessage(hwnd_downloadbtn, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hbit);

            y = 830+50; h = 48;
            x = 580; w = 164;
  	    hwnd_quitbtn = CreateWindowEx(0, "BUTTON", "quit", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,
								x, y, w, h, hwnd, (HMENU) IDC_QUIT_BUTTON, GetModuleHandle(NULL), NULL);
            hbit = (HBITMAP)LoadImage(hInst, "quit.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            SendMessage(hwnd_quitbtn, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hbit);

            hBitmap = (HBITMAP)LoadImage(hInst, "logo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            if(!INTRODUCTION) {
                thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
                Play();
                PostMessage(hwnd, WM_NOTIFY, 0, 0);
            }
            
            pcgame = TRUE;
            
            break;
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
                case ID_HUMAN_GAME:
                  pcgame = FALSE;
                break;
                case ID_PC_GAME:
                  pcgame = TRUE;
                break;
                case ID_FILE_DOWNLOAD:
                    if(MessageBox(hwnd,"Would you like to download a copy of this source code?", "Get Mine", MB_YESNO) == IDYES) {
                        ShellExecute(NULL, "open", "https://github.com/OkelyKodely/chess/", NULL, NULL, SW_SHOWNORMAL);
                    }
                break;
                case ID_CAPTURE_SCREEN:
                    if(MessageBox(hwnd,"Would you like to take a screen shot of the game?", "Screenshot", MB_YESNO) == IDYES) {
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
                            strcat(filename,"\\chess.exe");
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
                    ttw = 0;
                    timeToWait = 0;
                break;
                case ID_TIMER_5MIN:
                    if(!pcgame) {
                        ttw = 5;
                        timeToWait = 60*5;
                    }
                break;
                case ID_TIMER_10MIN:
                    if(!pcgame) {
                        ttw = 10;
                        timeToWait = 60*10;
                    }
                break;
                case ID_TIMER_15MIN:
                    if(!pcgame) {
                        ttw = 15;
                        timeToWait = 60*15;
                    }
                break;
                case ID_TIMER_20MIN:
                    if(!pcgame) {
                        ttw = 20;
                        timeToWait = 60*20;
                    }
                break;
                case ID_TIMER_25MIN:
                    if(!pcgame) {
                        ttw = 25;
                        timeToWait = 60*25;
                    }
                break;
                case ID_TIMER_30MIN:
                    if(!pcgame) {
                        ttw = 30;
                        timeToWait = 60*30;
                    }
                break;
                case ID_TIMER_35MIN:
                    if(!pcgame) {
                        ttw = 35;
                        timeToWait = 60*35;
                    }
                break;
                case ID_TIMER_40MIN:
                    if(!pcgame) {
                        ttw = 40;
                        timeToWait = 60*40;
                    }
                break;
                case ID_TIMER_45MIN:
                    if(!pcgame) {
                        ttw = 45;
                        timeToWait = 60*45;
                    }
                break;
                case ID_TIMER_50MIN:
                    if(!pcgame) {
                        ttw = 50;
                        timeToWait = 60*50;
                    }
                break;
                case ID_TIMER_55MIN:
                    if(!pcgame) {
                        ttw = 55;
                        timeToWait = 60*55;
                    }
                break;
                case ID_TIMER_60MIN:
                    if(!pcgame) {
                        ttw = 60;
                        timeToWait = 60*60;
                    }
                break;
                case ID_TIMER_65MIN:
                    if(!pcgame) {
                        ttw = 65;
                        timeToWait = 60*65;
                    }
                break;
                case ID_TIMER_70MIN:
                    if(!pcgame) {
                        ttw = 70;
                        timeToWait = 60*70;
                    }
                break;
                case ID_TIMER_75MIN:
                    if(!pcgame) {
                        ttw = 75;
                        timeToWait = 60*75;
                    }
                break;
                case ID_TIMER_80MIN:
                    if(!pcgame) {
                        ttw = 80;
                        timeToWait = 60*80;
                    }
                break;
                case ID_TIMER_85MIN:
                    if(!pcgame) {
                        ttw = 85;
                        timeToWait = 60*85;
                    }
                break;
                case ID_TIMER_90MIN:
                    if(!pcgame) {
                        ttw = 90;
                        timeToWait = 60*90;
                    }
                break;
                case ID_CLICK_ME_NEW_GAME:
                    if(MessageBox(hwnd,"Would you like to play a new game?", "New Game", MB_YESNO) == IDYES) {
                        GetCurrentDir( buff, FILENAME_MAX );
                        buff[strlen(buff)] = '\0';
                        strcpy(filename,buff);
                        strcat(filename,"\\chess.exe");
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

//    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
//                        g_szClassName,
//                        "Chess",
//                        WS_TILEDWINDOW,
//                        rect.left, rect.top, 1200, 1000,
//                        NULL, NULL, hInstance, NULL);
    
    hwnd = CreateWindowEx(WS_EX_LAYERED, 
            g_szClassName, "Chess", 
            WS_OVERLAPPEDWINDOW,
            rect.left, rect.top, 1200, 1000, 
            NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        return 0;
    }
    
    SetLayeredWindowAttributes(hwnd,  0,  
				(255 * 83) / 100, LWA_ALPHA);

    DisableMaximizeMinimizeButton(hwnd);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    RECT rc;
    GetWindowRect(hwnd, &rc) ;

    int xPos = (GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2;
    int yPos = (GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2;

    SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}