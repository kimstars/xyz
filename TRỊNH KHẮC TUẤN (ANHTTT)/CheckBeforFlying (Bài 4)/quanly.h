#include "monhang.h"

class quanLi
{
private:
    int n; //so loai hang
    int w; //can nang chi dinh
    monHang *hang;

public:
    void setHang(monHang *h)
    {
        this->hang = h;
    }
    int chonHang(int n, int w);
};
int quanLi::chonHang(int n, int w)
{
    int k[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }
            else if (j < hang[i].canNang)
            {
                k[i][j] = k[i - 1][j];
            }
            else
            {
                k[i][j] = max(k[i - 1][j], hang[i].canNang + k[i - 1][j - hang[i].canNang]);
            }
        }
    }
    return k[n][w];
}