#include<iostream>
#include "process.h"
using namespace std;

int main()
{
    cout<<"planing start"<<endl;
    Process pro;
    pro.planProcess();
    cout<<"planning end"<<endl;

    system("pause");//系统pause
    return 0;
}