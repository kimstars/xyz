#include "diem.cpp"
class hinhtron:public diem
{
    private:
        diem O;
        int r;
    public:
        hinhtron(){};
        hinhtron(diem O,int r)
        {
            this->O=O;
            this->r=r;
        }
        void nhaptdtron()
        {
            O.nhaptd();
            cin>>r;;
        }
        void xuattdtron()
        {
            O.xuattd();
            cout<<"r="<<r<<endl;
        }
        int dttron()
        {
            return 2*3.14*r;
        }
};