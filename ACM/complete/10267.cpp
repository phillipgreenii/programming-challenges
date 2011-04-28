/*   @JUDGE_ID:   35114NR   10267   C++   "Graphical Editor"  */

#include <iostream>
#include <string>

char **image = NULL;
int xSize,ySize;

char **newImage(int M, int N){
    char **temp;
    //create image
    temp = new char *[M];
    for (int i = 0;i < M;i++)
        temp[i] = new char [N];
    return temp;
}

void deleteImage(char **imageName,int width){
    for (int i = 0;i < width;i++)
        delete imageName[i];
    delete imageName;
}

void deleteImage(){
    deleteImage(image,xSize);
}

void createImage(int M, int N){
    //check for previous image
    if (image != NULL) deleteImage();
    //set size
    xSize = M; ySize = N;
    //create image
    image = newImage(M,N);
}

void clearImage(){
    for (int i = 0;i < xSize;i++)
        for (int j = 0;j < ySize;j++)
            image[i][j] = 'O';
}

void colorPixel(int X, int Y, char C){
    if ( X < 0 || X >= xSize || Y < 0 || Y >= ySize) return;
    image[X][Y]=C;
}


void drawVert(int X,int Y1,int Y2,char C) {
    int lo,hi;
    if(Y1<Y2)
    {
        lo = Y1;hi=Y2;
    }
    else
    {
        lo = Y2;hi=Y1;
    }
    for (int i = lo; i <= hi; i++)
        colorPixel(X,i,C);
}

void drawHorz(int X1,int X2,int Y,char C){
    int lo,hi;
    if(X1<X2)
    {
        lo = X1;hi=X2;
    }
    else
    {
        lo = X2;hi=X1;
    }
    for (int i = lo; i <= hi; i++)
        colorPixel(i,Y,C);
}

void drawRect(int X1,int Y1,int X2,int Y2,char C){
    int lo,hi;
    if(X1<X2)
    {
        lo = X1;hi=X2;
    }
    else
    {
        lo = X2;hi=X1;
    }
    for (int i = lo; i <= hi; i++)
        drawVert(i,Y1,Y2,C);
}

void print(char **temp, int width,int height){
    for (int i = 0;i < height;i++)
    {
        for (int j = 0;j < width;j++)
            cout << temp[j][i];
        cout << endl;
    }
}

void fillImage(int X,int Y,char C){
    //create temp image
    char ** temp=newImage(xSize,ySize);
    //copy image
    for (int i = 0;i < ySize;i++)
        for (int j = 0;j < xSize;j++)
        {
            if(image[j][i]==image[X][Y]) temp[j][i]=1;
            else temp[j][i]=0;
        }
    //mark starting point
    temp[X][Y]=2;
    //fill temp image
    bool finished = false;
    while(!finished)
    {
        finished = true;
        for (int i = 0;i < ySize;i++)
            for (int j = 0;j < xSize;j++)
                {
                if(temp[j][i]==2)
                {
                    if (j+1<xSize && temp[j+1][i]!=0 && temp[j+1][i]!=2)
                    {
                        temp[j+1][i]=2;
                        finished = false;
                    }
                    if (j-1>=0 && temp[j-1][i]!=0 && temp[j-1][i]!=2)
                    {
                        temp[j-1][i]=2;
                        finished = false;
                    }
                    if (i+1<ySize && temp[j][i+1]!=0 && temp[j][i+1]!=2)
                    {
                        temp[j][i+1]=2;
                        finished = false;
                    }
                    if (i-1>=0 && temp[j][i-1]!=0 && temp[j][i-1]!=2)
                    {
                        temp[j][i-1]=2;
                        finished = false;
                    }
                }
            }
    }
    //fill image file
    for (int i = 0;i < ySize;i++)
        for (int j = 0;j < xSize;j++)
            if (temp[j][i]==2)image[j][i]=C;
    //delete temp image
    deleteImage(temp,xSize);
}

string convertName(string fName){
    string name,ext;
    int decPos=0;
    while(fName[decPos]!='.')decPos++;

    name = fName.substr(0,decPos);
    ext = fName.substr(decPos+1,fName.size());
    name = name.substr(0,8);
    return (name + "." + ext);
}

void saveImage(string name){
    //print file name
    cout << convertName(name) << endl;
    //print image
    for (int i = 0;i < ySize;i++)
    {
        for (int j = 0;j < xSize;j++)
            cout << image[j][i];
        cout << endl;
    }
}

void runCommand(char command){
    int M,N,X,Y,X1,X2,Y1,Y2;
    char C;
    string name;
    switch (command)
    {
        case 'I':
            cin>>M>>N;
            createImage(M,N);
            clearImage();
            break;
        case 'C':
            clearImage();
            break;
        case 'L':
            cin>>X>>Y>>C;
            colorPixel(--X,--Y,C);
            break;
        case 'V':
            cin>>X>>Y1>>Y2>>C;
            drawVert(--X,--Y1,--Y2,C);
            break;
        case 'H':
            cin>>X1>>X2>>Y>>C;
            drawHorz(--X1,--X2,--Y,C);
            break;
        case 'K':
            cin>>X1>>Y1>>X2>>Y2>>C;
            drawRect(--X1,--Y1,--X2,--Y2,C);
            break;
        case 'F':
            cin>>X>>Y>>C;
            fillImage(--X,--Y,C);
            break;
        case 'S':
            cin >> name;
            saveImage(name);
            break;
        default:
            while(cin.get() != '\n');  
    }
}

int main()
{
    char command;

    while(cin>>command)
    {
        if (command == 'X') break;
        runCommand(command);
    }
    deleteImage();
    //system("PAUSE");
    return 0;
}
