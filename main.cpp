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
    sorting(vector<int> arr,vector<int> arr2, int n)
    :m_x(arr),m_N(n){
        cout<<"constructor:"<<'\n';
        cout<<"before sorting _arr"<<'\n';
        print_v(arr);
        cout<<"before sorting _arr2"<<'\n';
        print_v(arr2);
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
                if(x.at(h)>x.at(h+1))
                    swa(&x.at(h),&x.at(h+1));
        return x;
    }
    vector <int> choice_sort(vector<int> x,int n){
        for(int k=0;k<n-1;k++)
            for(int h=k+1; h<n;h++)
                if(x.at(k)>x.at(h))
                    swa(&x.at(k),&x.at(h));
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
    vector<int> _arr, _arr2;
    int _n1,_n2;
    cin >> _n1>>_n2;
    _arr.resize(_n1);
    _arr2.resize(_n2);
    //cout<<_arr.size()<<'\n';
    _arr = fill_random(_arr,_n1);
    _arr2 = fill_random(_arr2,_n2);

    sorting _vec(_arr,_arr2,_n1);

    _arr=_vec.buble_sort(_arr,_n1);
    _arr2=_vec.buble_sort(_arr2,_n1);
    cout<<"_arr after bubble sorting"<<'\n';
    _vec.print_v(_arr);
    cout<<"arr2 after choice sorting"<<'\n';
    _vec.print_v(_arr2);
    _arr.~vector();
    _arr2.~vector();
    _vec.~sorting();
    return 0;
}
