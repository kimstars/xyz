
#include "diem.cpp"

class hinhchunhat:public diem
{
    private:
       diem A;
       diem B;
       diem C;
       diem D;
    public:
    hinhchunhat(){};
    hinhchunhat(diem A ,diem B, diem C, diem D)
    {
        this->A=A;
        this->B=B;
        this->C=C;
        this->D=D;
    }
    hinhchunhat(int x1, int x2, int y1, int y2)
    {
        A.setdiem(x1,y2);
        B.setdiem(x2,y2);
        C.setdiem(x2,y1);
        D.setdiem(x1,y1);
    }
    void nhaptdhcn()
    {
        int x1,x2,y1,y2;
        cout<<"nhap x1,x2,y1,y2="<<endl;
        cin>>x1>>x2>>y1>>y2;
        A.setdiem(x1,y2);
        B.setdiem(x2,y2);
        C.setdiem(x1,y1);
        D.setdiem(x2,y1);
    }
    void xuattdhcn()
    {
        cout<<"HCN:";
        A.xuattd();
        B.xuattd();
        C.xuattd();
        D.xuattd();
    }
    int dthcn()
    {
        return (((B.getX()-A.getX())*(B.getY()-D.getY())));
    }
};