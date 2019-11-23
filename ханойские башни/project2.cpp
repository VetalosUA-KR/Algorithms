#include<iostream>
#include<stdexcept>
using namespace std;

// nDisk llosc dysków, from początkowy słupek, to docelowy słupek,
// buf pomocniczy słupek, step licznik kroków
void Haanoi(int nDisk, int  from, int  to, int  buf, int &step)
{
    if (nDisk!=0)
    {
        Haanoi(nDisk-1, from, buf, to, step);
        ++step;
        cout << from << " " << to << endl;
        Haanoi(nDisk-1, buf, to, from, step);
    }
}

int HHanoi(int nDisk, int kPeg)  		// nDisk ilość dysków, kPeg ilość słupków
{
    //sprawdzianie dannych na wyjątki
    if(nDisk>0 && kPeg==0)
        throw invalid_argument( "received negative value" );
    if(nDisk>1 && kPeg==1)
        throw invalid_argument( "received negative value" );
    if(nDisk>1 && kPeg==2)
        throw invalid_argument( "received negative value" );
    if(nDisk==0 || kPeg==1)
        return 0;
    if(kPeg==2)
    {
        cout << 1 << " " << 2 << endl;
        return 1;
    }

    int step=0; 					// licznik kroków
    int n=nDisk, l, m,  j=2*(kPeg-2)-1; 		// j ilość wywołań funkcji Haanoi
    if(nDisk<=kPeg-2)
    {
        for(int i=1; i<nDisk; i++)
        {
            Haanoi(1, 1, i+1, i+2, step);
        }
        Haanoi(1, 1, kPeg, kPeg-1, step);
        for(int i=nDisk; i>1; i--)
        {
            Haanoi(1, i, kPeg, 1, step);
        }
    }
    else
    {
        while(n%(kPeg-2)!=0)
            n--; 			// wyszukiwanie wielokrotności liczby n
        l=n/(kPeg-2); 				// l ilość krążków w stopkach
        m=nDisk-(kPeg-3)*l; 			// m ilość krążków w najniższej stopce
        for(int i=1; i<=j/2; i++) 			// przesuwanie powyższych stopek
        {
            Haanoi(l, 1, i+1, i+2, step);   //krążków na pośrednie słupki
        }
        Haanoi(m, 1, kPeg, kPeg-1, step);
        for(int i=2; i<=j/2+1; i++)				// przesuwanie stopek z
        {
            Haanoi(l, kPeg-i, kPeg, 1, step);   //pośrednich  słupków na
        }
//docelowy
    }
    return step;
}

int main()
{
    int n=-1, k=-1;
    while(n<0 || k<0)
    {
cout << "Liczba dysków: ";
        cin >> n;
cout << "Liczba słupków: ";
        cin >> k;
    }
cout << "liczba kroków: "<< HHanoi(n, k);
    return 0;
}
