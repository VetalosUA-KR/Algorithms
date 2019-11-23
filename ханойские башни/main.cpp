#include <iostream>
#include <cmath>

using namespace std;


/** Đĺęńóđńč˙ 1
    n - ęîë-âî "áëčíîâ"
    src - ń ęŕęîăî ńňîëáöŕ íŕ÷číŕĺě
    dest - íŕ ęŕęîé íóćíî ďĺđĺëîćčňü
    temp - âńďîěîăŕňĺëüíűé (ďóńňîé) ńňîëáĺö
*/
void tower2(int n, int src, int dest, int temp)
{
    //cout<<"t("<<n<<","<<" src = "<<src<<","<<" dest = "<<dest<<", "<<" temp = "<<temp<<")"<<endl;
    if(n == 0)
    {
        return;
    }
    tower2(n - 1, src, temp, dest);
    cout<<src<<" -> "<<dest<<"**********"<<endl;
    tower2(n - 1, temp, dest, src);
}

/** Đĺęóđńč˙ 2
    r - ęîë-âî "áëčíîâ"
    b - ń ęŕęîăî ńňîëáöŕ íŕ÷číŕĺě
    e - íŕ ęŕęîé íóćíî ďĺđĺëîćčňü
*/
void tower(int r, int b, int e)
{
    int c;
    if((b == 1) && (e == 2) || (b == 2) && (e == 1))
    {
        c = 3;
    }
    else if((b == 1) && (e == 3) || (b == 3) && (e == 1))
    {
        c = 2;
    }
    else if((b == 2) && (e == 3) || (b == 3) && (e == 2))
    {
        c = 1;
    }
    if(r > 1)
    {
        tower(r-1, b, c);
        cout<<b<<" -> "<<e<<endl;
        tower(r-1, c, e);
    }
    else
    {
        cout<<b<<" -> "<<e<<endl;
    }
}

/** Đĺęóđńč˙ 3

*/
void hanoi (int n, int i, int k)
{
    if(n == 1)
    {
                        /// 1
        //cout<<"Move disk   ["<<n<<"]   from pin   "<<i<<"   to   "<<k<<endl;
        cout<<i<<" "<<k<<endl;
    }
    else
    {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp);
        //cout<<"Move disk   ["<<n<<"]   from pin   "<<i<<"   to   "<<k<<endl;
        cout<<i<<" "<<k<<endl;
        hanoi(n - 1, tmp, k);
    }
}

void han1(int n,int a,int b,int c)
{
     if(n == 1)
    {
        cout<<a<<" "<<b<<endl;
    }
    else
    {
        han1(n-1,a,c,b);
        cout<<a<<" "<<b<<endl;
        han1(n-1,c,b,a);
    }
}

void han(int n,int a,int b,int c/*, int d, int e, int f, int g, int h*/)
{
    //cout<<"n = "<<n<<"  a = "<<a<<"  b = "<<b<<"  c = "<<c<<endl;
    if(n == 1)
    {
        cout<<a<<" "<<b<<endl;
    }
    else
    {
        han(n-1,a,b,c);
        cout<<a<<" "<<b<<endl;/// последнее кольцо с первой башни на ту которая нужна
        han(n-1,b,a,c);
    }
}

/**
    number of towers [ 4 - inf. )
*/
void hanArr(int n, int tab[], int size, int &ile)
{
    if(n == 1)
    {
        //cout<<tab[0]<<" "<<tab[1]<<endl;
        ile++;
    }
    else
    {
        int t1[size];
        t1[0] = tab[0];
        t1[1] = tab[size-1];
        t1[2] = tab[2];
        t1[3] = tab[1];
        for(int i = 4; i < size; i++)
        {
            t1[i] = tab[i-1];
        }

        hanArr(n-1, t1, size,ile);
        //cout<<tab[0]<<" "<<tab[1]<<endl;

        ile++;
        int t2[size];
        t2[0] = tab[size-1];
        t2[1] = tab[1];
        t2[2] = tab[0];
        for(int i = 3; i < size; i++)
        {
            t2[i] = tab[i-1];
        }

        hanArr(n-1, t2,size,ile);
    }
}


int main()
{
    int kol = 0;
    int size = 7;
    int arr[size];/// array towers
    for(int i = 0; i < size; i++)
    {
        arr[i] = i+1;
    }

    hanArr(18,arr,size,kol);
    cout<<"ilosc = "<<kol<<endl;

    //tower(3,1,3);
    //tower2(3,1,3,2);
    //hanoi(7,1,2);

    ///han(8,1,2,3,4,5,6);

    //han(3,1,2,3);
    /*for(int i = 4; i > 1; i--)
    {
        float n = i/2.0;
        int rez = 3*(pow(2,n)-1);
        cout<<rez<<endl;
    }*/

    return 0;
}


/*

*/
