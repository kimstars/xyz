//Xếp hậu sao cho không quân nào ăn được lân nhau

#include<stdio.h>
#include<math.h>
int a[20];
bool Check(int x,int y){
    //kiểm tra cách đặt có thỏa mãn không
    for(int i = 1; i <x ;i++)
        if(a[i] == y || abs(i-x) == abs(a[i] - y) )
            return false;
    //Nếu kiểm tra hết các trường hợp vẫn không sai thì trả về true
    return true;
}
 
void Xuat(int n){
    //in ra một kết quả
    for(int i=1;i<=n;i++){
         printf(" %d ",a[i]); }
		 printf("\n");
}
 
void Test(int i,int n){
    for(int j = 1;j<=n;j++){
        // thử đặt quân hậu vào các cột từ 1 đến n
        if(Check(i,j)){
            //nếu cách đặt này thỏa mãn thì lưu lại vị trí
            a[i] = j;
                        //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
            if(i==n) Xuat(n);
            Test(i+1,n);
        }
    }
}
 
int main(){
    int n = 8;
    Test(1,n);
    return 0;
}
