#include <iostream>
#include <cmath>

using namespace std;

class Matrix
{
    public:
    void createMatrix()
    {
        ifstream sm;
        sm.open("src/MST_Adjacencies.txt");

        ifstream read;
        read.open("src/MST_Adjacencies.txt");

        ofstream write;
        write.open("src/mst_matrix.txt");

        int size = 0;
        while(!sm.eof())
        {
            string str;
            getline(sm, str);
            size++;
        }
        sm.close();

        float matrix[size][size] {};
        write<<size<<"\n";

        while(!read.eof())
        {
            int x,y;
            float w;
            read>>x>>y>>w;
            w = round(w*1)/1;
            cout<<x<<" "<<y<<" "<<w<<endl;
            matrix[x-1][y-1] = w;
            matrix[y-1][x-1] = w;
        }
        read.close();

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                write<<matrix[i][j]<<"\t";
            }
            write<<"\n\n";
        }
    }
};
