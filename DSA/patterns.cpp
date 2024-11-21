#include <iostream>
using namespace std;


int main(){
//1
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<" * ";
        }
        cout<<"\n";
    }

    cout<<"\n";
//2
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<" * ";
        }
        cout<<"\n";
    } 
    cout<<"\n";
//3
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<< j<< " ";
        }
        cout<<"\n";
    }
    cout << endl; 
//4
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<< i+1<< " ";
        }
        cout<<"\n";
    }

    cout << endl; 
//5
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }

    cout << endl; 
//6
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            cout<<(5+1) - j<<" ";
        }
        cout<<"\n";
    }

    cout<<endl;
//7
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            cout<<"- ";
        }
        for (int j = 0; j < 2*i+1; j++)
        {
            cout<<"* ";
        }
        for (int j = 5; j > i; j--)
        {
            cout<<"- ";
        }
        cout<<"\n";
    }
    cout<<endl;
//8
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"- ";
        }
        for (int j = 0; j < 2*(5-i)-1; j++)
        {
            cout<<"* ";
        }
        for (int j = 0; j < i; j++)
        {
            cout<<"- ";
        }
        cout<<"\n";
    }
    cout<<endl;
//9
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            cout<<" ";
        }
        for (int j = 0; j < 2*i+1; j++)
        {
            cout<<"*";
        }
        for (int j = 5; j > i; j--)
        {
            cout<<" ";
        }
        cout<<"\n";
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < 2*(5-i)-1; j++)
        {
            cout<<"*";
        }
        for (int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
//10
    for (int i = 1; i <= 2*5 -1; i++)
    {
        int stars = i;
        if (i>5) stars = 2*5 - i;
        for (int j = 1; j <= stars ; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < i; k++)
        {
            cout<<" ";
        }
        
        for (int j = 65; j < 69-i; j++)
        {
            cout<<char(j+i);
        }
        cout<<endl;
    }
    


    return 0;
}