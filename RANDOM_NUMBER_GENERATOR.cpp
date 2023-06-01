#include<iostream>
#include <bits/stdc++.h>

using namespace std;
class ICG
{
public :
    ICG(float x0,float a,float m,int n)
    {
        X0=x0;
        A=a;
        M=m;
        N=n;
    }
    void calcICG()
    {
        cout << "X 0 = " << X0 << "\n";
        cout << "R 0 = " << (X0/M)<< "\n";
        for(int i=0; i<N; i++)
        {
            X0=fmod((A / X0), M);
            cout << "X"<<(i+1)<<" = "<<X0<<"\n";
            cout << "R" << (i+1) << " = " << (X0/M) <<"\n";
        }
    }
private:
    float X0;
    float A;
    float M;
    int N;
};
void inputICG()
{
    float x0,a,m;
    int n;
    cout<<"Enter X0:\n";
    cin>>x0;
    cout<<"Enter a:\n";
    cin>>a;
    cout<<"Enter m:\n";
    cin>>m;
    cout<<"Enter n:\n";
    cin>>n;
    ICG ziad(x0,a,m,n);
    ziad.calcICG();
}


class LFG
{
public:
    LFG(double x0,char sign,double x1, int m, int n)
    {
        X0 = x0;
        X1 = x1;
        M = m;
        N = n;
        SIGN=sign;
    }

    void CalcLFG()
    {
        double arr1[N];
        double arr2[N];

        arr1[0] = X0;
        arr1[1] = X1;

        for (int i = 2; i <= N-1; i++)
        {
            if (SIGN == '+')
            {
                arr1[i] = fmod(arr1[i - 2] + arr1[i - 1], M);
            }
            else if (SIGN == '-')
            {
                arr1[i] = fmod(arr1[i - 2] - arr1[i - 1], M);
            }
            else if (SIGN == '*')
            {
                arr1[i] = fmod(arr1[i - 2] * arr1[i - 1], M);
            }
            else if (SIGN == '/')
            {
                arr1[i] = fmod(arr1[i - 2] / arr1[i - 1], M);
            }
            else
            {
                cout << "Incorrect sign" << endl;
                return;
            }
        }

        for (int i = 0; i < N; i++)
        {
            cout << "X" << i << " = " << arr1[i];
            cout << "\t R" << i << " = " << arr1[i] / M << endl;
        }
    }




private:
    double X0;
    double X1;
    int M;
    int N;
    char SIGN;
};


void inputLFG()
{
    double x0, x1;
    int m, n;
    char sign;
    cout << "Enter the X0: ";
    cin >> x0;

    cout << "Enter the X1: ";
    cin >> x1;

    cout << "Enter the sign (+, -, *, /): ";
    cin >> sign;

    cout << "Enter the M: ";
    cin >> m;

    cout << "Enter the number: ";
    cin >> n;

    LFG obj(x0, sign, x1, m, n);
    obj.CalcLFG();
}




class MRG
{
private:
    int gen_num;
    float m;
    int num_given;
    float* given;
    float* x;

public:
    void input()
    {
        cout << "Enter number of generated number of MRG: ";
        cin >> gen_num;

        cout << "Enter m number: ";
        cin >> m;

        cout << "How many numbers given: ";
        cin >> num_given;

        given = new float[num_given];
        x = new float[gen_num + num_given];

        for(int i = 0; i < num_given; i++)
        {
            cout << "Enter the given number " << i + 1 << ": ";
            cin >> given[i];
        }

        for(int i = 0; i < num_given; i++)
        {
            cout << "Enter the number of x " << i + 1 << ": ";
            cin >> x[i];
        }
    }

    void generateNumbers()
    {


        for(int u = 0; u < gen_num; u++)
        {
            for(int w = 0; w < num_given; w++)
            {
                x[u + num_given] = x[u + num_given] + (x[u + num_given-1-w] * given[w]);
            }
            x[u + num_given] = fmod(x[u + num_given], m);
        }

        for(int t = 0; t < gen_num + num_given; t++)
        {
            cout << "x" << t + 1 << "=" << x[t] << "            ";
            cout << "rn" << t + 1 << "=" << x[t] / m << "\n";
        }
    }

    ~MRG()
    {
        delete[] given;
        delete[] x;
    }
};


class MidSquare
{
private:
    int gen_num;
    int n;
    int* x;

public:
    void input()
    {
        cout << "Enter number of generated numbers: ";
        cin >> gen_num;

        cout << "Enter x0 value: ";
        cin >> n;

        x = new int[gen_num + 1];
        x[0] = n;

    }

    void generateNumbers()
    {int squared;

        for (int i = 0; i < gen_num; i++)
        {   string s ,re="";
             squared = x[i] * x[i];
         int v=(log10(squared) + 1);
            if(v==8){
              
              s=to_string(squared);
              for(int w=2;w<=5;w++){
            re+=s[w];	
			}
			x[i+1]=stoi(re);}
         else if ((v + 1)<8){
           squared+=10000000;
           s=to_string(squared);
              for(int w=2;w<=5;w++){
            re+=s[w];	
			}
			x[i+1]=stoi(re);
            
            
			}
			else{
             cout<<"enter correct number";
           }
           
         }
           
            
        

        for (int i = 0; i < gen_num; i++)
        {
            cout << "x" << i  << "=" << x[i] << "\n";
            cout << "rn" << i  << "=" << x[i+1] / 10000.0 << "\n";

        }
    }

    ~MidSquare()
    {
        delete[] x;
    }
};

int main()
{
    int x;
    cout<<"Enter 1 if you want ICG \nEnter 2 if you want MRG \nEnter 3 if you want LFG \nEnter 4 if you want MSM \nWhat do you want: ";
    cin>>x;
    if (x==1)
    {
        inputICG();
    }
    else if(x==2)
    {
        MRG mrg;
        mrg.input();
        mrg.generateNumbers();

    }
    else if(x==3)
    {
        inputLFG();
    }
    else if(x==4)
    {
        MidSquare MSM;
        MSM.input();
        MSM.generateNumbers();
    }
    else
    {
        cout<<"Enter a correct number";
    }
}