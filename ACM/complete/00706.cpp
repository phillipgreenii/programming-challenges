/*   @JUDGE_ID:   35114NR   706   C++   "LCD Display"  */

#include <iostream>
#include <cmath>
#include <string>
int size;

/*
    0
    -
5  | |  1
    - 6
4  | |  2
    _
    3
#  0654 3210   hex
0: 0011 1111 : 0x3F
1: 0000 0110 : 0x06
2: 0101 1011 : 0x5B
3: 0100 1111 : 0x4F
4: 0110 0110 : 0x66
5: 0110 1101 : 0x6D
6: 0111 1101 : 0x7D
7: 0000 0111 : 0x07
8: 0111 1111 : 0x7F
9: 0110 1111 : 0x6F
*/
int displayFormat[] = { 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

char **createNumber(char num){
    int rows = (2*size+3),
        cols = (size+2)+1;//+1 is blank col

    //make spot for number
    char **number = new char *[rows];
    for (int i= 0; i < rows; i++) {
        number[i] = new char [cols];
    }

    //clear number
    for (int i= 0; i < rows; i++)
        for (int j= 0; j < cols; j++)
            number[i][j]=' ';

    //fill number
    int numConfig = displayFormat[num-'0'];

    //0 (horizontal)
    if (numConfig & (int)pow(2,0))
    {
        for (int i = 0;i < size;i++)
            number[0][1+i] = '-';
    }
    //1 (vertical)
    if (numConfig & (int)pow(2,1))
    {
        for (int i = 0;i < size;i++)
            number[1+i][size+1] = '|';
    }
    //2 (vertical)
    if (numConfig & (int)pow(2,2))
    {
        for (int i = 0;i < size;i++)
            number[1+(size+1)+i][size+1] = '|';
    }
    //3 (horizontal)
    if (numConfig & (int)pow(2,3))
    {
        for (int i = 0;i < size;i++)
            number[2*(size+1)][1+i] = '-';
    }
    //4 (vertical)
    if (numConfig & (int)pow(2,4))
    {
        for (int i = 0;i < size;i++)
            number[1+(size+1)+i][0] = '|';
    }
    //5 (vertical)
    if (numConfig & (int)pow(2,5))
    {
        for (int i = 0;i < size;i++)
            number[1+i][0] = '|';
    }
    //6 (horizontal)
    if (numConfig & (int)pow(2,6))
    {
        for (int i = 0;i < size;i++)
            number[size+1][1+i] = '-';
    }

    return number;
}

void printNumber(char **num){
    int rows = 2*size+3,
        cols = (size+2)+1;
    for (int i= 0; i < rows; i++)
    {
        for (int j= 0; j < cols; j++)
            cout << num[i][j];
        cout << endl;
    }
}

void deleteNumber(char **num){
    int rows = 2*size+3;
    for (int i= 0; i < rows; i++)
        delete num[i];
    delete num;
}

char **createNumberLine(string numbers,int &n){
    n = numbers.length();
    char ***digitsToPrint = new char **[n];

    //convert string into LCD array
    for (int i = 0; i< n;i++)
        digitsToPrint[i] = createNumber(numbers[i]);

    //create number line
    int rows = (2*size+3),
        cols = n*((size+2)+1);
    char **numberLine = new char *[rows];
    for (int i= 0; i < rows; i++) {
        numberLine[i] = new char [cols];
    }


    //combine LCD array into numberLine
    for (int i= 0; i < rows; i++)
        for (int j= 0; j < cols; j++)
            numberLine[i][j]= digitsToPrint[j/(size+2+1)][i][j%(size+2+1)];


    delete digitsToPrint;

    return numberLine;
}

void printNumberLine(char **numLine, int n){
    int rows = (2*size+3),
        cols = n*((size+2)+1);
    for (int i= 0; i < rows; i++)
    {
        for (int j= 0; j < cols; j++)
            cout << numLine[i][j];
        cout << endl;
    }
    cout << endl;
}

void deleteNumberLine(char **numLine,int n){
    int rows = (2*size+3);
    for (int i= 0; i < rows; i++)
        delete numLine[i];
    delete numLine;
}

void solve(string lineOfNumbers){
    int n;

    char **tmp = createNumberLine(lineOfNumbers,n);
    printNumberLine(tmp,n);
    deleteNumberLine(tmp,n);
}


int main()
{
    string lineOfNumbers;
    while(cin >> size >> lineOfNumbers)
    {
        if(size == 0) break;
        solve(lineOfNumbers);
    }

    return 0;
}
