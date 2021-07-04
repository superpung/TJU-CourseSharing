#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int x[4]={10,20,30,40};
    int *p=x;
    char city[]="dollas";
    char *pcity=new char[10];
    
    cin.getline(city,20);
    gets(pcity);
    
    cout<<atoi(city);
    
    cout<<city<<"  "<<pcity<<endl;
    
    cout<<*++p<<endl;
    cout<<*p++<<endl;
    cout<<++*p<<endl;
    cout<<(*p)++<<endl;
    cout<<*p<<endl;
    
    system("pause");
    return 0;
}
