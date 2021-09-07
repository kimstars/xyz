#include "Vecto.h"

typedef vector<int> vi;
typedef long long int64;
#define int int64


// chọn một điểm xp (y max, nếu nhiều ymax thì lấy thêm xmax)
// từ điểm đó đi ngược chiều kim đồng hồ(đi về bên trái theo hướng vecto), 
// kiểm tra ba điểm w,u,v. đẩy chỉ số 2 điểm vào stack. stack.push(k++);
// ccw(a[stack.below()] , a[stack.top], a[k])
// nếu ccw <= 0 :rẽ phải(hoặc đi thẳng) thì sẽ tạo bao lõm (ko thỏa). pop khỏi stack
// nếu ccw > 0: rẽ trái, stack.push(k++);
// thực hiện tới khi k = n

// mảng a[n] lưu tọa độ Point,



int64 ccw(Point w, Point u, Point v) //counterclockwise : ngược chiều kim đồng hồ 
{ // Xem từ w --> u --> v là rẽ trái (>0), đi thẳng (0) hay rẽ phải (<0)
    u -= w;
    v -= w;
    return (int64)u.x * v.y - (int64)u.y * v.x;
}

class halfStack : public vi //stack lưu điểm bao lồi
{
public:
    void pop() { pop_back(); }
    void push(int v) { push_back(v); }
    int below() { return at(size() - 2); }
    int top() { return at(size() - 1); }
};





Point a[10000];
int n;
halfStack hs;

bool cmp(Point u, Point v) //
{
    return ccw(a[1], u, v) > 0;
}


void graham(){
    int k = 1;
    while(k <= n+1){
        if(hs.size() < 2){
            hs.push(k++);
        }else{
            if(ccw(a[hs.below()], a[hs.top()], a[k]) <= 0){
                hs.pop();
            }else{
                hs.push(k++);
            }
        }
    }
}

main()
{

    srand(time(NULL));
    cout << "Nhap so luong diem: ";
    cin >> n;

    if(n <= 2){
        cout << "khong co bao loi\n";
        return 0;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Nhap diem thu " << i <<" : \n";
    //     cin >> a[i];
    // }
    cout << "Gen toa do \n";
    for (int i = 1; i <= n; i++)
    {
        int x = rand()%20+1;
        int y = rand()%20+1;
        Point temp(x,y);
        a[i] = temp;
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    for (int i = 1; i <= n; i++){ // tìm ra phần tử a[1] : có tọa độ y max ( và x max nếu nhiều y max )
        if (a[i] > a[1])
        {
            Point z = a[i];
            a[i] = a[1];
            a[1] = z;
        }
    }

    sort(a + 2, a + n + 1, cmp);

    graham();
    
    cout << "List cac diem bao loi\n";
    for (int i = 0; i < hs.size()-1; i++)
    {
        a[hs[i]].show();
    }
    

    
}