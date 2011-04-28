/*   @JUDGE_ID:   35114NR   100   C++   "3n+1"  */

#include <iostream.h>
#include <stdlib.h>

//calculate the number of cycles
unsigned int calcMaxCycleLen(unsigned long num){
    //counter
    unsigned int count = 1;
    //loop until end point
    while (num > 1)
    {
        //even
        if (num % 2 == 0) num /= 2;
        //odd
        else num = 3*num + 1;
        //increase counter
        count++;
    }
    return count;
}

unsigned int solve(unsigned int low, unsigned int high){
    unsigned int tmp, max = 0;
    for(unsigned long i = low;i<=high;i++)
    {
        //get current cycle lenth
        tmp = calcMaxCycleLen(i);
        //compare to current max
        if (tmp > max) max = tmp;
    }
    return max;
}

int main()
{
    unsigned long lo,hi;
    while(cin >> lo >> hi)
    {
        cout << lo << " " << hi << " " << ((lo<hi)?solve(lo,hi):solve(hi,lo)) << endl;
    }

    return 0;
}
