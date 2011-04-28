/*   @JUDGE_ID:   35114NR   10195   C++   "Check the Check"  */

#include <iostream>
#include <string>
#include <cctype>


#define BOARDLENGTH 8


char board[BOARDLENGTH][BOARDLENGTH];

void printBoard(){
    for(int i = 0; i < BOARDLENGTH; i++)
    {
        for(int j = 0; j < BOARDLENGTH; j++)
            cout << board[i][j];
        cout << endl;
    }
}

bool getColor(int row,int col){
    return isupper(board[row][col]);
}

bool withInBoard(int row,int col){
    return (
            row >= 0 &&
            row < BOARDLENGTH &&
            col >= 0 &&
            col < BOARDLENGTH
            );
}

bool isCheck(int row, int col, bool color){
    if (!isalpha(board[row][col]))return false;
    if(toupper(board[row][col])=='K' && getColor(row,col)!=color) return true;
    else return false;
}

//pawn
bool checkP(int row,int col){
    bool color = getColor(row,col);
    //white
    if (color)
    {
        if(withInBoard(row-1,col-1) &&  isCheck(row-1,col-1,color)) return true;
        if(withInBoard(row-1,col+1) &&  isCheck(row-1,col+1,color)) return true;
    }
    //black
    else
    {
        if(withInBoard(row+1,col-1) &&  isCheck(row+1,col-1,color)) return true;
        if(withInBoard(row+1,col+1) &&  isCheck(row+1,col+1,color)) return true;
    }
    return false;
}

//rook
bool checkR(int row,int col){
    bool color = getColor(row,col);
    //down
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row+i,col)) break;
        if(board[row+i][col] != '.')
        {
            if(isCheck(row+i,col,color)) return true;
            break;
        }
    }
    //up
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row-i,col)) break;
        if(board[row-i][col] != '.')
        {
            if(isCheck(row-i,col,color)) return true;
            break;
        }
    }
    //right
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row,col+i)) break;
        if(board[row][col+i] != '.')
        {
            if(isCheck(row,col+i,color)) return true;
            break;
        }
    }
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row,col-i)) break;
        if(board[row][col-i] != '.')
        {
            if(isCheck(row,col-i,color)) return true;
            break;
        }
    }

    return false;
}

//knight
bool checkN(int row,int col){
    bool color = getColor(row,col);
    if(withInBoard(row+1,col+2) &&  isCheck(row+1,col+2,color)) return true;
    if(withInBoard(row+1,col-2) &&  isCheck(row+1,col-2,color)) return true;
    if(withInBoard(row-1,col+2) &&  isCheck(row-1,col+2,color)) return true;
    if(withInBoard(row-1,col-2) &&  isCheck(row-1,col-2,color)) return true;
    if(withInBoard(row+2,col+1) &&  isCheck(row+2,col+1,color)) return true;
    if(withInBoard(row+2,col-1) &&  isCheck(row+2,col-1,color)) return true;
    if(withInBoard(row-2,col+1) &&  isCheck(row-2,col+1,color)) return true;
    if(withInBoard(row-2,col-1) &&  isCheck(row-2,col-1,color)) return true;
    return false;
}

//bishop
bool checkB(int row,int col){
    bool color = getColor(row,col);
    //down-right
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row+i,col+i)) break;
        if(board[row+i][col+i] != '.')
        {
            if(isCheck(row+i,col+i,color)) return true;
            break;
        }
    }
    //down-left
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row+i,col-i)) break;
        if(board[row+i][col-i] != '.')
        {
            if(isCheck(row+i,col-i,color)) return true;
            break;
        }
    }
    //up-right
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row-i,col+i)) break;
        if(board[row-i][col+i] != '.')
        {
            if(isCheck(row-i,col+i,color)) return true;
            break;
        }
    }
    //up-left
    for (int i = 1;i<BOARDLENGTH;i++)
    {
        if(!withInBoard(row-i,col-i)) break;
        if(board[row-i][col-i] != '.')
        {
            if(isCheck(row-i,col-i,color)) return true;
            break;
        }
    }
    return false;
}

//queen
bool checkQ(int row,int col){
    if(checkB(row,col) || checkR(row,col)) return true;
    return false;
}

//king
bool checkK(int row,int col){
    return false;
}

bool check(int row,int col){
    switch(board[row][col])
    {
        case 'K': case 'k':
            return checkK(row,col);
            break;
        case 'Q': case 'q':
            return checkQ(row,col);
            break;
        case 'B': case 'b':
            return checkB(row,col);
            break;
        case 'N': case 'n':
            return checkN(row,col);
            break;
        case 'R': case 'r':
            return checkR(row,col);
            break;
        case 'P': case 'p':
            return checkP(row,col);
            break;
        default:
            return false;
    }
}

string solve(){
    for(int i = 0; i < BOARDLENGTH; i++)
        for(int j = 0; j < BOARDLENGTH; j++)
            if(check(i,j)) return (isupper(board[i][j])?"black":"white");
    return "no";
}

int main()
{
    bool finished = false;
    int gameNum = 0;
    while(!finished)
    {
        //get board
        for(int i = 0; i < BOARDLENGTH; i++)
        {
            cin.getline(board[i],20);
            if(cin.peek() == '\n') cin.get();
        }
        //check for end
        finished = true;
        for(int i = 0; i < BOARDLENGTH; i++)
        {
            for(int j = 0; j < BOARDLENGTH; j++)
                if (board[i][j] != '.')
                {
                    finished = false;
                    break;
                }
            if (!finished) break;
        }

        if (!finished) cout << "Game #" << ++gameNum << ": " << solve() << " king is in check." << endl;


    }

    //system("PAUSE");
    return 0;
}
