#include "diem.cpp"

class hinhtamgiac:public diem
{
    private:
        diem A;
        diem B;
        diem C;
    public:
    hinhtamgiac(){};
    hinhtamgiac(diem A,diem B,diem C)
    {
        this->A=A;
        this->B=B;
        this->C=C;
    }
    void nhaptdtamgiac()
    {
       do
       {
        A.nhaptd();
        B.nhaptd();
        C.nhaptd();
       }while(A.getX()==B.getX()||A.getX()==C.getX()||A.getY()==B.getY()||A.getY()==C.getY());
    }
    void xuathtg()
    {
        A.xuattd();
        B.xuattd();
        C.xuattd();
    }
    int dthtg()
    {
        return (1/2)* (abs((A.getX()-A.getX())*(C.getY()-A.getY())-(C.getX()-A.getX())*(B.getY()-A.getY())));
    }
};