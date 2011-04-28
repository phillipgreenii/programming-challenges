/*   @JUDGE_ID:   35114NR   10189   C++   "Minesweeper"  */

#include <iostream>

#define MAXFIELDDIM 110

//variables
int rows,cols;
char field[MAXFIELDDIM][MAXFIELDDIM];

//input the field
void inputField(){
    //clear board
    for (int i = 0; i < MAXFIELDDIM;i++)
        for (int j = 0; j < MAXFIELDDIM; j++)
            field[i][j] = '.';
    //input board using 1 space buffer on sides
    for (int i = 1; i <= rows;i++)
        for (int j = 1; j <= cols; j++)
            cin >> field[i][j];
}

//count the number of bombs
char count(int i, int j){
    int counter = 0;
    char tmp = field[i][j];
    if (tmp == '*') return '*';

    //vertical
    if (field[i+1][j]=='*')counter++;
    if (field[i-1][j]=='*')counter++;
    //horizontal
    if (field[i][j+1]=='*')counter++;
    if (field[i][j-1]=='*')counter++;
    //diaganol
    if (field[i+1][j+1]=='*')counter++;
    if (field[i+1][j-1]=='*')counter++;
    if (field[i-1][j+1]=='*')counter++;
    if (field[i-1][j-1]=='*')counter++;

    //convert to character
    return ('0' + counter);
}

//call count on each spot
void solve(){
    for (int i = 1; i <= rows;i++)
        for (int j = 1; j <= cols; j++) 
            field[i][j] = count(i,j);
}

//output field
void printField(){
    //input board
    for (int i = 1; i <= rows;i++)
    {
        for (int j = 1; j <= cols; j++)
            cout << field[i][j];
        cout << endl;
    }
}

int main()
{
    int counter=0;
    while(cin>>rows>>cols)
    {
        //break on 0 0 input
        if (rows == 0 && cols == 0) break;
        inputField();
        solve();
        cout << "Field #" << ++counter << ":" << endl;
        printField();
        cout << endl;
    }

    return 0;
}
