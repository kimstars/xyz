## A. Tìm bao lồi

Khi xử lý một số lớn các điểm, thông thường ta chú ý đến biên của tập các điểm này. Đứng trước biểu đồ các điểm được vẽ trong một mặt phẳng, người xem sẽ khó phân biệt những điểm “nằm trong” với những điểm trên biên. Đây cũng là thuộc tính cơ sở để phân biệt các tập điểm, chúng ta sẽ cùng xét các thuật toán để lấy ra “biên tự nhiên” của các điểm.

Phương pháp toán học để định ra biên tự nhiên của một tập điểm thì dựa vào một tính chất hình học – tính lồi. Cùng quay lại khái niệm về tính lồi như sau: Một đa giác lồi có tính chất là bất kỳ 2 điểm nào nằm trong đa giác này thì đoạn thẳng nối 2 điểm trên phải nằm hoàn toàn trong tam giác đó. Như vậy, mọi hình tam giác hay hình chữ nhật là lồi. Trong toán học, biên tự nhiên của một tập điểm được gọi là bao lồi (convex hull). Bao lồi của một tập điểm được định nghĩa là một đa giác lồi nhỏ nhất chứa toàn bộ tập điểm này. Cũng có thể coi bao lồi là một bao lồi là đường ngắn nhất bao quanh một tập điểm. Một tính chất hiển nhiên của bao lồi là các đỉnh của các đa giác lồi xác định biên thì thuộc vào tập điểm đã cho. Bài toán ở đây là: cho tập N điểm, tìm tập con các điểm xác định bao lồi của N điểm đã cho

Như hình trên, có 8 điểm biên trên biên của một tập các điểm bên trong. Một bao lồi có thể chứa tối thiểu 3 điểm (xác định một tam giác chứa tất cả các điểm khác) và tối đa là toàn bộ tập điểm ( nếu tất cả các điểm này làm thành một đa giác lồi). Số các điểm trên bao lồi của một tập điểm ngẫu nhiên, nằm đâu đó ở các điểm ngoài cùng.

Một tính chất cơ bản của bao lồi là bất kỳ đường thẳng nào nằm ngoài bao, khi được rời về phía bao, sẽ chạm bao tại các đỉnh của nó. Thực tế, có thể dễ dàng tìm vài điểm chắc chắn nằm trên bao lồi bằng quy tắc trên với các đường thẳng ngang và dọc: những điểm có toạ độ x hay y lớn nhất và nhỏ nhất đều nằm trên bao lồi. Điều này được dùng làm khởi điểm cho việc xem xét các thuật toán dưới đây

## B. Các quy luật tính

Với thuật toán tìm bao lồi thì:

- Input: một mảng các điểm;

- Output : một đa giác, cũng được biểu diễn bằng một mảng các điểm với tính chất là khi lần theo các điểm với trật tự mà chúng xuất hiện trong mảng sẽ đổ lại viền của các đa giác trên. Điều này có vẻ đòi hỏi thêm một điều kiện về trật tự khi tìm bao lồi (sao không trả về trật tự bất kỳ của bao?)

Rõ ràng là đầu ra có sắp xếp sẽ dễ sử dụng hơn, và ta sẽ thấy rằng các tính toán không để ý đến các trật tự các điểm cũng không dễ dàng gì hơn. Khi xét các thuật toán, sẽ thuận tiện nếu dùng phép thay thế : mảng dùng cho tập điểm nguồn cũng được dùng để lưu các kết quả. Một cách đơn giản, các thuật toán này sắp xếp lại các điểm trong mảng ban đầu, bao lồi sẽ là M điểm đầu tiên (có thứ tự) trong mảng.

Như vậy việc tính bao lồi có quan hệ gần gũi với việc sắp xếp. Thực tế, thuật toán bao lồi có thể dùng để sắp xếp như sau:

Cho N số để sắp xếp, hãy chuyển chúng thành các điểm bằng cách xem các số như là các góc với một bán kính không đổi.

Bao lồi của các điểm này là một đa giác N đỉnh chứa tất cả các điểm. Vì kết quả được sắp xếp theo thứ tự xuất hiện các đỉnh trên đa giác, nên kết quả này có thể tìm thứ tự của N số đã cho

+ độ phức tạp của thuật toán bao lồi cỡ NlogN (như thuật toán sắp xếp dù các phép tính -hoàn toàn khác nhau)

+ trương hợp xấu nhất thời gian thi hành tỉ lệ với NlogN

Như nhiều thuật toán hình học khác, ta phải chú ý đến các trường hợp đặc biệt có thể có trong đầu vào Input. Ví dụ, nếu các điểm nằm trên cùng một đường thẳng thì bao lồi là gì?...Chúng ta sẽ cùng nhau tìm hiểu các thuật toán dưới đây để có thể hiểu và thấy được các ứng dụng của bao lồi trong như thế nào

Thuật toán bọc gói

Bọc gói là thuật toán tìm bao lồi tự nhiên nhất, giống như cách ta vẽ bao lồi của tập điểm, là phương pháp “bao quanh” tập điểm đã cho. Bắt đầu từ một điểm chắc chắn nằm trên bao lồi, dùng một tia quét ngược chiều kim đồng hồ cho đến khi đụng một điểm khác: điểm mới này phải thuộc bao. Lấy điểm vừa tìm được làm chốt và tiếp tục “quét” cho đến khi đụng một điểm khác…tiếp tục như vậy cho đến khi “gói” được “bọc” hoàn toàn (gặp lại điểm đầu tiên).

Tất nhiên ta không cần quét tất cả các góc có thể, ta chỉ làm các phép tính tối thiểu để tìm điểm bị chạm kế tiếp. Với mỗi điểm thuộc bao, ta cần xét các điểm chưa được đưa vào bao. Như vậy, phương pháp này hoàn toàn tương tự việc bằng cách chọn. Sự di chuyển của dữ liệu được mô tả như ví dụ dưới đây:

Chương trình sau tìm bao lồi của mảng A[1..N] các điểm. Cơ sở của việc cài đặt là hàm Gocgiua chúng ta sẽ xét ở phần dưới, trả lại góc giữa 2 điểm p1, p2 và trục hoành.

```PHP
function Gocgiua(p1, p2: point): real;
Var dx, dy, ax, ay: integer;
Begin

dx:= p2.x – p1.x; ax:= abs(dx);
dy:= p2.y – p1.y; ay: = abs(dy);
if (dx =0) and (dy =0) then t:= 0

else t:= dy/(ax + ay);
if (dx < 0) then t: = 2-t

else if (dy <0) then t:= 4 = t;
Gocgiua := t * 90.0;
end;
Xét hàm Bocgoi sau (A[N+1] được dùng làm biến cầm canh):
function Bocgoi: integer;
var i, min, M: integer;
gocmin, v : real; t : point;
begin

min:=1;
for i:= 2 to N do

if ( A[i].y < A[min].y) then min:= i;
M:= 0;
A[N+1]:= A[min];
gocmin := 0.0;
repeat

M:= M +1 ; t:= A[M]; A[M]:= A[min]; A[min]:= t;
Min:= N+1; v:= gocmin; gocmin:=360.0;
for i:= M +1 to N + 1 do

if (Gocgiua(A[M], A[i]) > v) then

if (Gocgiua(A[M], A[i]) < gocmin ) then

begin

min: = i;
gocmin:= Gocgiua(A[M], A[min])
end;
until min = N +1;
Bocgoi:= M;
end;
```

Từ hàm trên ta thấy rằng, ta tìm điểm có tung độ y nhỏ nhất và lưu trong A[N + 1] để làm chỗ chấm dứt vòng lặp. Biến M cho biết số điểm thuộc bao, và v là giá trị hiện thời của góc “quét”( là góc giữa trục hoành và đường thẳng nối A[M - 1] và A[M]). Vòng lặp repeat đưa điểm vừa được tìm vào bao bằng cách đổi chỗ điểm này với điểm thứ M, và dùng hàm Gocgiua để tính góc giữa truc hoành và đường thẳng nối điểm trên với mỗi điểm còn lại chưa đưa vào bao, tìm điểm có góc nhỏ nhất trong số các góc lớn hơn v. Vòng lặp kết thúc khi điểm đầu tiên (đúng hơn là bản sao của điểm đầu tiên) được đưa vào A[N + 1] được lặp lại.

Chương trình này có thể trả lại hoặc không trả lại các điểm rơi trên một cạnh của bao lồi. Tình thế này xảy ra khi có nhiều hơn một điểm có cùng giá trị Gocgiua với A[M] trong quá trình thực hiện thuật toán. Hàm trên trả lại điểm đầu tiên được gặp trong số các điểm như vậy, dù có thể có những điểm khác gần với A[M] hơn. Khi hàm Gocgiưa để lấy khoảng cách giữa 2 điểm đã cho trong đối số của hàm và gán giá trị nhỏ hơn cho điểm gần hơn khi 2 điểm này có cùng một góc.

### Nhược điểm của thuật toán:

Với thuật toán “bọc goi” này thì trong trường hợp xấu nhất, khi tất cả các điểm thuộc vào bao, thời gian thi hành sẽ tỉ lệ với N*N (tương tự như việc sắp xếp bằng cách chọn). Mặt khác, phương pháp này có thể tổng quát hoá cho trường hợp nhiều chiều hơn. Bao lồi của một tập điểm trong không gian k-chiều là một hình lồi nhỏ nhất chứa tập điểm này. Ví dụ bao lồi của tập điểm trong không gian 3 chiều là một vật thể lồi 3 chiều có các mặt bên là phẳng. chốt các đường biên khác của bao cho đến khi “gói ” được “bọc”.