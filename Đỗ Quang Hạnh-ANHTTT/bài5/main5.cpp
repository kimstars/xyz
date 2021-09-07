#include "hcn.cpp"
#include "htg.cpp"
#include "hinhtron.cpp"
using namespace std;
int main()
{
    int max=0;
    int n1,n2,n3; 
    cout<<" hinhtron n1 = "<<endl;
    cin>>n1;
    cout<<"hcn n2 = "<<endl;
    cin>>n2;
    cout<<"htg n3 = "<<endl;
    cin>>n3;
    hinhtron HT[n1];
    hinhchunhat HCN[n2];
    hinhtamgiac HTG[n3];
    for(int i=1;i<=n1;i++)
    {
        cout<<"nhaphinhtron "<<i<<" ="<<endl;
        HT[i].nhaptdtron();
        if(HT[i].dttron()>max)
        {
            max=HT[i].dttron();
        }
    }
    for(int i=1;i<=n2;i++)
    {
        cout<<"nhaphcn "<<i<<"="<<endl;
        HCN[i].nhaptdhcn();
        if(HCN[i].dthcn()>max)
        {
            max=HCN[i].dthcn();
        }
    }
    for(int i=1;i<=n3;i++)
    {
        cout<<"nhaptamgiac "<<i<<"="<<endl;
        HTG[i].nhaptdtamgiac();
        if(HTG[i].dthtg()>max)
        {
            max=HTG[i].dthtg();
        }
    }
    cout<<"dt max = "<<max;
}