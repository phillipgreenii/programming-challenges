/*   @JUDGE_ID:   35114NR   10033   C++   "Interpreter"  */

#include <iostream>
#include <string>
#define RAMMAXSIZE 1000
#define REGMAXSIZE 10

int RAM[RAMMAXSIZE];
int REG[REGMAXSIZE];
int numberOfOperations;

void init(){
    for (int i = 0;i<RAMMAXSIZE;i++)
        RAM[i] = 0;
    for (int i = 0;i<REGMAXSIZE;i++)
        REG[i] = 0;
    numberOfOperations = 0;
}


void runInstr(int address){
    if (address >= RAMMAXSIZE) return;
    int instruction = RAM[address];
    int command = instruction/100,
        param1 = (instruction%100)/10,
        param2 = instruction%10;

    numberOfOperations++;
    switch(command)
    {
        case 1:
            if (instruction == 100) return;
            break;
        case 2:
            REG[param1] = param2;
            break;
        case 3:
            REG[param1] += param2;
            REG[param1] %= 1000;
            break;
        case 4:
            REG[param1] *= param2;
            REG[param1] %= 1000;
            break;
        case 5:
            REG[param1] = REG[param2];
            break;
        case 6:
            REG[param1] += REG[param2];
            REG[param1] %= 1000;
            break;
        case 7:
            REG[param1] *= REG[param2];
            REG[param1] %= 1000;
            break;
        case 8:
            REG[param1] = RAM[REG[param2]];
            break;
        case 9:
            RAM[REG[param2]] = REG[param1];
            break;
        case 0:
            if (REG[param2] !=0) return runInstr(REG[param1]);
            break;
    }
    return runInstr(address + 1);
}

int main()
{
    int numberOfCases,tempNum;
    int tmp;

    cin >> numberOfCases;

    for (int i = 0; i < numberOfCases;i++)
    {
            //initialize ram and registers
            init();
            //read in RAM
            for (int j = 0;j<RAMMAXSIZE;j++)
            {
                cin >> RAM[j];
                cin.get();
                if (  cin.peek()<'0' ||  cin.peek()>'9') break;
            }
            runInstr(0);
            cout << numberOfOperations << endl << endl;


    }


    //system("PAUSE");
    return 0;
}
