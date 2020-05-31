#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
# define M_PI           3.14159265358979323846

using namespace std;
int p[100000];
int rk[100000];

float** getMatrix(int &matrixSize)
{
    ifstream fin;
    fin.open("miasta.txt");
    string all;
    int max = 0;
    if(!fin.is_open())
    {
        cout<<"can't open file"<<endl;
    }
    else
    {
        string str;
        while(!fin.eof())
        {
            str="";
            getline(fin, str);
            int px = str.find(" ");
            string posX = str.substr(0, px);
            string posY = str.substr(px+1, str.find(" "));
            int x = stoi(posX);
            int y = stoi(posY);
            if(x > max) max = x;
            if(y > max) max = y;
        }
    }
    cout<<"max = "<<max<<endl;
    matrixSize = max;
    fin.close();

    float **graph = new float*[max]{};
    for(int i = 0; i < max; i++)
    {
        graph[i] = new float[max]{};
    }

    fin.open("miasta.txt");
    if(!fin.is_open())
    {
        cout<<"can't open file"<<endl;
    }
    else
    {
        string str;
        while(!fin.eof())
        {
            str="";
            getline(fin, str);
            int px = str.find(" ");
            string posX = str.substr(0, px);
            string posY = str.substr(px+1, str.find(" "));
            int x = stoi(posX);
            int y = stoi(posY);
            graph[x-1][y-1] = sqrt( pow(abs(x-y), 2) + pow(cos((x*M_PI)/180.0) * abs(y-x), 2) ) * 4075.704/360;
            graph[y-1][x-1] = sqrt( pow(abs(x-y), 2) + pow(cos((x*M_PI)/180.0) * abs(y-x), 2) ) * 4075.704/360;
        }

    }
    cout<<"max = "<<max<<endl;
    fin.close();
    return graph;
}

int main ()
{

    int matrixSize = 0;
    float ** graph = getMatrix(matrixSize);
    cout<<"size: "<<matrixSize<<endl;

    ofstream cout ("output.txt");
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {
            cout<<"["<<graph[i][j]<<"]";
        }
        cout<<"\n";
    }
    /*string str = "52.12 21.02 Warszawa";
    int px = str.find(" ");
    string posX = str.substr(0, px);
    string posY = str.substr(px+1, str.find(" "));
    int X = stoi(posX);
    int Y = stoi(posY);
    cout<<X<<endl;
    cout<<Y;*/

    /*cout<<endl;
    cout<<endl;
    cout<<endl;
    /// *************************************************************** ///
    int x1,x2,y1,y2;
    cout<<"podaj x1 ";cin>>x1;
    cout<<"podaj x2 ";cin>>x2;
    cout<<"podaj y1 ";cin>>y1;
    cout<<"podaj y2 ";cin>>y2;

    int rez = sqrt( pow((x2-x1), 2) + pow(cos((x1*M_PI)/180.0) * (y2-y1), 2) ) * 4075.704/360;

    cout<<"rez = "<<rez<<endl;*/



    return 0;
}































