#include <iostream>
#include <ctime>


using namespace std;

struct node
{
    int num;
    node * next;

};

void add(node * &h, int n)
{
   node * temp = new node();
   temp->num = n;
   temp->next = h;

   h = temp;
}

void print(node * h)
{
    node * temp = h;
    while(temp != nullptr)
    {
        cout<<temp->num<<" ";
        temp = temp->next;
    }
}

int get(node *&w)
{
    node * tmp = w;
    w = w->next;
    int res = tmp->num;
    delete tmp;
    return res;
}

/**void printR(node * h)
{
    if(!h) return;
}*/

int summa(node * h, int s)
{
    if(!h) return s;
    else
    {
        s += h->num;
        summa(h,s);
    }
}


void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void insertSort(int tab[], int roz)
{
    int tmp = tab[0];

    for(int i = 1; i < roz; i++)
    {
        int index = i-1;
        tmp = tab[i];
        while(tab[index] > tmp && index >= 0)
        {
            tab[index+1] = tab[index];
            index--;
        }
        tab[index+1] = tmp;
    }
}

void bucketSort(int tab[], int roz)
{
    node * bucket[10];
    for(int i = 0; i < 10; i++) bucket[i] = NULL;

    for(int i = 0; i < roz; i++)
    {
        int k;
        k = tab[i] / 100;
        add(bucket[k], tab[i]);
        /**for(int j = 0; j < 10; j++) /// выписание каждого прохода который добавляет элементы в массив Buckets
        {
            cout<<" k = "<<j<<"  || ";
            print(bucket[j]);
            cout<<endl;
        }
        cout<<endl;*/
        //cout<<k<<" ";
    }

    /// Записываем все наши элементы из buckets обратно в основной массив
    int index = 0;
    for(int i = 0; i < 10; i++)
    {
        while(bucket[i] != nullptr)
        {
            tab[index] = get(bucket[i]);
            index++;
        }
    }

    /// вызываем функцию сортировки
    insertSort(tab, roz);
    /*for(int i = 0; i < roz; i++)
    {
        cout<<tab[i]<<" ";
    }*/

}


void shellsort(int a[], int r)
{
    int i, j, k, h;
    int v;
    int incs[16] = { 1391376, 463792, 198768, 86961, 33936, 13776, 4592, 1968, 861, 336, 112, 48, 21, 7, 5, 1 };
    for ( k = 0; k < 16; k++)
    {
        for (h = incs[k], i = incs[k]; i <= r; i++)
        {
            v = a[i];
            j = i;
            //cout<<"pod = "<<incs[k]<<"  v = "<<v<<"  i = "<<i<<endl;
            while (j >= h && a[j-h] > v)
            {
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = v;
        }
    }
}


int main ()
{
    srand(time(0));
    node * head = nullptr;
    int s = 100000;
    /*int arr1[s];
    int arr2[s];*/

    int *arr1 = new int [s];
    int *arr2 = new int [s];

    for(int i = 0; i < s; i++)
    {
        arr1[i] = arr2[i] = rand() % 1000;
    }
    int c1 = clock();
    shellsort(arr1,s);
    int c2 = clock();
    bucketSort(arr2, s);
    int c3 = clock();
    cout<<"shellsort = "<<c2-c1<<endl;
    cout<<"bucket = "<<c3-c2<<endl;
    /*cout<<"source array -> ";
    for(int i = 0; i < s; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    cout<<"bucket sort -> ";*/


    cout<<endl;



    return 0;
}
