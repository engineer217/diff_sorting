#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::vector;

class sorting{
private:
    vector <int> m_x;
    int m_N;
public:
    sorting(vector<int> arr, int n)
    :m_x(arr),m_N(n){
        cout<<"before sorting"<<'\n';
        print_v(m_x);
    }
    void swa(int *a,int *b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }
    void print_v(vector<int> x){
        for (int i=0;i<x.size();i++)
            cout<<x.at(i)<<' ';
        cout<<'\n';
    }
    vector <int> buble_sort(vector<int> x,int n){
        for(int j=0;j<n-1;j++)
            for(int h=0; h<n-j-1;h++)
                if(&x.at(h),&x.at(h+1));
        return x;
    }
    ~sorting(){
        cout<<"\n"<<"destructor";
    }


};
vector<int> fill_random(vector<int> _ar,int n){
    int a=0;
    srand(time(NULL));
    while(a<n){
        _ar.at(a)=rand()%100;
        a++;
    }
    return _ar;
}

int main()
{
    vector<int> _arr;
    int _n;
    cin >> _n;
    _arr.resize(_n);
    cout<<_arr.size()<<'\n';
    _arr = fill_random(_arr,_n);
    sorting _vec(_arr,_n);
    _arr=_vec.buble_sort(_arr,_n);
    cout<<"after bubble sorting"<<'\n';
    _vec.print_v(_arr);
    _arr.~vector();
    _vec.~sorting();
    return 0;
}
