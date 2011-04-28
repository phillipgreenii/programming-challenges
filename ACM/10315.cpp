/* @BEGIN_OF_SOURCE_CODE */
/*   @JUDGE_ID:   35114NR   10315   C++   "Poker Hands"  */

#include <iostream>
#include <vector>
#include <algo.h>

int hands[2][15];
int suits[2][5];

enum {white,black};
enum {clubs=1,diamonds,hearts,spades};
enum {ten=10,jack,queen,king,ace};

void displayCards(int color) {
    if (color == white) cout << "White:\t";
    if (color == black) cout << "Black:\t";
    for (int i = 2 ; i < 15;i++)
        if (hands[color][i]>0) cout << i << ":" << hands[color][i] << " ";
    cout << endl;
    cout << "\t";
    for (int i = 1 ; i < 5;i++)
        if (suits[color][i]>0) cout << i << ":" << suits[color][i] << " ";
    cout << endl;
}

int clearCards(int color){
    //clear cards
    for (int i = 0; i < 15; i++)
        hands[color][i]=0;
    //clear suits
    for (int i = 0; i < 5; i++)
        suits[color][i]=0;
}

void getCards(int color){
    char num,suit;
    for (int i = 0; i < 5;i++)
    {
        cin >> num >> suit;
        //set number;
        switch(num)
        {
            case '2': case '3': case '4':
            case '5': case '6': case '7':
            case '8': case '9':
                hands[color][num - '0']++;
                break;
            case 'T':
                hands[color][ten]++;
                break;
            case 'J':
                hands[color][jack]++;
                break;
            case 'Q':
                hands[color][queen]++;
                break;
            case 'K':
                hands[color][king]++;
                break;
            case 'A':
                hands[color][ace]++;
                hands[color][1]++;
                break;
        }
        //set suit
        switch(suit)
        {
            case 'C':
                suits[color][clubs]++;
                break;
            case 'D':
                suits[color][diamonds]++;
                break;
            case 'H':
                suits[color][hearts]++;
                break;
            case 'S':
                suits[color][spades]++;
                break;
        }
    }
}

int nthLargestCard(int color, int n){
    int count = n;
    for (int i = 14;i>=2;i--)
    {
        if (hands[color][i] > 0) n--;
        if (n == 0) return i;
    }
    return 0;
}

int highCard(int color){
    return nthLargestCard(color,1);
}

int Pair(int color, int startCard = 14){
    if (startCard < 2) return 0;
    //highest pair
    for (int i = startCard; i >= 2 ; i--)
        if(hands[color][i] == 2) return i;
    return 0;
}

int TwoPair(int color){
    int highCard = Pair(color);
    int secHighCard = Pair(color,highCard-1);
    if (secHighCard>0) return highCard;
    else return 0;
}

int ThreeOfAKind(int color){
    //highest three of a kind
    for (int i = 14; i >= 2 ; i--)
        if(hands[color][i] == 3) return i;
    return 0;
}

int Straight(int color){
    bool straight;
    for (int i = 14; i >= 5 ; i--)
    {
        if(hands[color][i] > 1) return 0;
        else if(hands[color][i] == 1)
        {
            straight = true;
            for (int j = i; j > i-5; j--)
                if(hands[color][j] != 1)
                {
                    straight = false;
                    break;
                }
            if (straight) return i;
        }
    }
    return 0;
}

int Flush(int color){
    for (int i = 1; i < 5; i++)
        if (suits[color][i] == 5) return highCard(color);
    return 0;
}

int FullHouse(int color){
    int highCard = ThreeOfAKind(color);
    int secHighCard = Pair(color,highCard-1);
    if (secHighCard) return highCard;
    else return 0;
}

int FourOfAKind(int color){
    //find highest four of a kind
    for (int i = 14; i >= 2 ; i--)
        if(hands[color][i] == 4) return i;
    return 0;
}

int StraightFlush(int color){
    int straightHigh = Straight(color);
    int flushHigh = Flush(color);
    if (straightHigh > 0 && flushHigh > 0) return straightHigh;
    else return 0;
}

int score(int color){
    int outScore=0;
    if (outScore==0)
    {
        outScore = StraightFlush(color);
        outScore += (outScore>0?8*15:0);
//cout << "os8:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = FourOfAKind(color);
        outScore += (outScore>0?7*15:0);
//cout << "os7:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = FullHouse(color);
        outScore += (outScore>0?6*15:0);
//cout << "os6:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = Flush(color);
        outScore += (outScore>0?5*15:0);
//cout << "os5:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = Straight(color);
        outScore += (outScore>0?4*15:0);
//cout << "os4:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = ThreeOfAKind(color);
        outScore += (outScore>0?3*15:0);
//cout << "os3:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = TwoPair(color);
        outScore += (outScore>0?2*15:0);
//cout << "os2:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = Pair(color);
        outScore += (outScore>0?1*15:0);
//cout << "os1:" << outScore << endl;
    }
    if (outScore==0)
    {
        outScore = highCard(color);
        outScore += (outScore>0?0*15:0);
//cout << "os0:" << outScore << endl;
    }
    return outScore;
}

int highestCard(){
//cout << "test" << endl;
    int blackHigh,whiteHigh;
    for (int i = 1; i <= 5; i++)
    {
        blackHigh = nthLargestCard(black,i);
        whiteHigh = nthLargestCard(white,i);
        if (blackHigh != whiteHigh) break;
    }
    if (blackHigh > whiteHigh) return 1;
    if (blackHigh < whiteHigh) return -1;
    return 0;
}

int winner(){
    int blackScore = score(black);
    int whiteScore = score(white);
//cout << "Black Score: " << (blackScore)/15 << ":" << (blackScore)%15 << "\t"
//    << "White Score: " << (whiteScore)/15 << ":" << (whiteScore)%15 <<endl;
    if (blackScore > whiteScore) return 1;
    if (blackScore < whiteScore) return -1;
    switch(blackScore/15)
    {
        case 0:
        case 1:
        case 2:
        case 5:
            return highestCard();
        case 3:
        case 4:
        case 6:
        case 7:
        case 8:
            return 0;
    }
}

int main()
{
int tmp = 0;
    while(cin.peek()!=EOF)
    {
//cout << tmp++ << endl;
        clearCards(black);
        clearCards(white);
        getCards(black);
        getCards(white);
//displayCards(white);
//displayCards(black);
        switch(winner())
        {
            case 1:
                cout << "Black wins." << endl;
                break;
            case -1:
                cout << "White wins." << endl;
                break;
            case 0:
                cout << "Tie." << endl;
                break;
            default:
                cout << "bad value: " << winner() << endl;
        }
//cout << endl << endl << endl;
    while(cin.peek()=='\n')cin.get();
    }
    //system("PAUSE");
    return 0;
}
/* @END_OF_SOURCE_CODE */
