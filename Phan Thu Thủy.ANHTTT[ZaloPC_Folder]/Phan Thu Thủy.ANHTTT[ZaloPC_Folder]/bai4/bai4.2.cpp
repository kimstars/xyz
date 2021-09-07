#include <iostream>
#include <math.h>

using namespace std;

long n, W;        // n la so mon qua, W la can nang gioi han
long v[200][200]; // luu gia tri cua qua dem ve;
struct Souvenir
{
    long w = 0;
    long val;
};
typedef struct Souvenir souvenir;
souvenir s[200]; // luu goi hang

long Result(long index, long W)
{
    for (int i = 0; i <= index; i++)
    {
        for (size_t j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (j < s[i].w)
            {                          // khoi luong goi hang thu i lon hon
                v[i][j] = v[i - 1][j]; // nếu gói i không được chọn 
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - s[i].w] + s[i].val);
            }
        }
    }
    return v[index][W];
}
void Xuat(long index, long W)
{
    cout << "Chi so cac goi hang duoc chon la: ";
    while (index != 0)
    {
        if (v[index][W] != v[index - 1][W])
        {
            cout << index << " ";
            W = W - s[index].w;
        }
        --index;
    }
}

int main()
{
    long n, W;
    cout << "Nhap vao so luong mon qua va trong luong toi da: \n";
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].w >> s[i].val;
    }
    cout << "index"
         << "\t\tweight"
         << "\t\tvalue" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t\t" << s[i].w << "\t\t" << s[i].val << endl;
    }
  
    cout << "Ket qua: " << Result(n, W)<< endl;
     Xuat(n, W);
}