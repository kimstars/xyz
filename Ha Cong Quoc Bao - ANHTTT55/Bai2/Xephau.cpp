#include<iostream>

using namespace std;


void result(int n, int a[][100]){

    for(int i=0;i<n;i++)
    {
        cout<<endl;

        for(int j=0;j<n;j++)
        {

            cout<<a[i][j]<<" ";
        }
    }

    cout<<endl<<endl;

}

void cpy(int a[][100],int b[][100], int xuoi[],int cxuoi[],int nguoc[],int cnguoc[],int doc[],int cdoc[],int ngang[],int cngang[],int n){

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=a[i][j];
        }
    }
    for(int i=0;i<=2*n;i++){

        cxuoi[i]=xuoi[i]; cnguoc[i]=nguoc[i]; cdoc[i]=doc[i]; cngang[i]=ngang[i];

    }

}

int xep(int i,int a[][100],int xuoi[],int nguoc[], int doc[], int ngang[], int n){

    for(int j=0;j<n;j++)
    {

        int b[100][100],xuoi1[100],nguoc1[100],doc1[100],ngang1[100];

        cpy(a,b,xuoi,xuoi1,nguoc,nguoc1,doc,doc1,ngang,ngang1,n);

        if(!xuoi[j-i+n]&&!nguoc[i+j]&&!doc[j]&&!ngang[i])
        {

            b[i][j]=1;

            xuoi1[j-i+n]=1;nguoc1[i+j]=1;doc1[j]=1;ngang1[i]=1;

            if(i==n-1) 
            {
                result(n,b);
            }

            xep(i+1,b,xuoi1,nguoc1,doc1,ngang1, n);
          
        }

    }

}

int main(){
    int n = 8;

    int a[100][100], xuoi[100],nguoc[100],doc[100],ngang[100];

    
    xep(0,a,xuoi,nguoc,doc,ngang, n);

    cout << "Co toi da 8 quan hau tren ban co  8 * 8" << endl;
    return 0;

}