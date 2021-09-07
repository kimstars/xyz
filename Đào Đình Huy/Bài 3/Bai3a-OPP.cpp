//bài toán xếp hậu
#include<iostream>
#include<math.h>

using namespace std;

//bài toán in ra vị trí của các con hậu trên từng hàng
int a[20];
//hàm bool Ok kiểm tra xem con hậu thêm vào có ăn con nào có trước đó hay không
//cùng nằm trên 1 cột hay trên đường chéo của những con trước
bool Ok(int x2, int y2){
    for(int i = 1; i < x2; i++){
        if(a[i] == y2 || abs(i - x2) == abs(a[i] - y2)){
            return false;
        }
    }
    return true;
}

void xuat(int n){
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int i, int n){
    //thử đặt các con hậu từ 1 đến n
    for(int j = 1; j <= n; j++){
        //kiểm tra xem hậu mới thêm có ăn con nào trc đó khô
        if(Ok(i, j)){
            //nếu cách đặt thỏa mãn thì lưu vị trí, sau đó kiểm tra tiếp các con tiếp theo
            a[i] = j;
            if(i == n){//khi i(chỉ số hàng) bằng n thì xuất ra trường hợp
                xuat(n);
            }
            Try(i + 1, n);//thử tiếp trên hàng tiếp theo nếu i < n
        }
    }
}

int main(){
    int n = 8;
    Try(1, n);

    return 0;
}