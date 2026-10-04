# Tháp Hà Nội — Tuần 4

## 1. Cách 1: đệ quy — `Hanoi_tower_dequy.c`

Gọi hàm `Hanoi_tower(int n, char A, char B, char C)` chuyển n đĩa
từ cột A sang cột B, dùng cột C làm trung gian.
Trong hàm này, tham số thứ hai là cột nguồn, thứ ba là cột đích, thứ tư là cột trung gian.

Các bước thực hiện:

1. Nếu n = 1, in lần chuyển đĩa từ A sang B rồi kết thúc.
2. Gọi `Hanoi_tower(n - 1, A, C, B)` để chuyển n - 1 đĩa từ A sang C.
3. In lần chuyển đĩa n từ A sang B.
4. Gọi `Hanoi_tower(n - 1, C, B, A)` để chuyển n - 1 đĩa từ C sang B.

Trong `main`, chương trình đọc n,
rồi gọi `Hanoi_tower(n, 'A', 'B', 'C')`.


## 2. Cách 2: khử đệ quy — `Hanoi_tower_khongdequy.c`

Gọi hàm `Hanoi_tower(int n, char nguon, char giua, char dich)` chuyển n đĩa
từ cột nguồn sang cột đích, dùng cột giữa làm trung gian.
Trong hàm này, tham số thứ hai là cột nguồn, thứ ba là cột trung gian, thứ tư là cột đích.

Mỗi phần tử kiểu `sapxep` lưu số đĩa `n`, ba cột `nguon`, `giua`, `dich`
và vị trí đang thực hiện `buoc`. Mảng `nganXep` lưu các công việc;
`dinh` là chỉ số phần tử trên cùng, `dinh = -1` nghĩa là ngăn xếp rỗng.

Các bước thực hiện:

1. Đưa công việc ban đầu vào `nganXep[0]`, với `buoc = 0`.
2. Khi `dinh >= 0`, lấy công việc trên cùng vào biến `viec`.
3. Nếu `viec.n == 1`, in lần chuyển đĩa từ `nguon` sang `dich`, rồi giảm `dinh`.
4. Nếu `viec.buoc == 0`, đổi bước của công việc hiện tại thành 1, tăng `dinh`
   và thêm công việc chuyển n - 1 đĩa từ `nguon` sang `giua`, dùng `dich` làm trung gian.
5. Nếu `viec.buoc == 1`, in lần chuyển đĩa n từ `nguon` sang `dich`,
   đổi bước thành 2 và thêm công việc chuyển n - 1 đĩa từ `giua` sang `dich`,
   dùng `nguon` làm trung gian.
6. Khi `buoc` bằng 2, hai công việc con đã xong; giảm `dinh` để lấy công việc ra.
7. Lặp lại đến khi ngăn xếp rỗng.

`buoc` giúp công việc trước nhớ phải làm gì sau khi công việc sau kết thúc.

Mảng `nganXep` có 18 phần tử.
Mỗi lần thêm công việc con, số đĩa giảm một; có tối đa n công việc cùng lúc.
Vì vậy bản này cần input nguyên trong khoảng 1–18.

Trong `main`, chương trình đọc n bằng `scanf`,
rồi gọi `Hanoi_tower(n, 'A', 'B', 'C')`.

## 3. Số bước và độ phức tạp

Với một đĩa, chuyển trực tiếp từ nguồn sang đích là kết quả.
Giả sử chuyển được n - 1 đĩa: trước tiên đưa các đĩa nhỏ sang cột trung gian,
còn lại đĩa n chuyển  sang đích, rồi đưa n - 1 đĩa nhỏ lên trên nó.
Các lần chuyển đều tuân thủ quy tắc không đặt đĩa lớn lên đĩa nhỏ.


Số lần chuyển tối thiểu thỏa `T(n) = 2 * T(n - 1) + 1`, `T(1) = 1`,
suy ra `T(n) = 2^n - 1`.

| Cách | Thời gian | Bộ nhớ phụ |
| --- | --- | --- |
| Đệ quy | O(2^n) | O(n) |
| Khử đệ quy | O(2^n) | O(n) |

Với cách khử đệ quy, mảng được cấp cố định 18 phần tử.
O(n) mô tả số phần tử cần dùng nếu mở rộng giới hạn input.
Khử đệ quy không làm giảm số lần chuyển.

## 4. Test case và input/output

### n = 1

Input:

```text
1
```

Output:

```text
Chuyen dia 1 tu cot A sang cot B
```

### n = 2

Input:

```text
2
```

Output:

```text
Chuyen dia 1 tu cot A sang cot C
Chuyen dia 2 tu cot A sang cot B
Chuyen dia 1 tu cot C sang cot B
```

### n = 3

Input:

```text
3
```

Output:

```text
Chuyen dia 1 tu cot A sang cot B
Chuyen dia 2 tu cot A sang cot C
Chuyen dia 1 tu cot B sang cot C
Chuyen dia 3 tu cot A sang cot B
Chuyen dia 1 tu cot C sang cot A
Chuyen dia 2 tu cot C sang cot B
Chuyen dia 1 tu cot A sang cot B
```

### n = 4

Input:

```text
4
```

Output:

```text
Chuyen dia 1 tu cot A sang cot C
Chuyen dia 2 tu cot A sang cot B
Chuyen dia 1 tu cot C sang cot B
Chuyen dia 3 tu cot A sang cot C
Chuyen dia 1 tu cot B sang cot A
Chuyen dia 2 tu cot B sang cot C
Chuyen dia 1 tu cot A sang cot C
Chuyen dia 4 tu cot A sang cot B
Chuyen dia 1 tu cot C sang cot B
Chuyen dia 2 tu cot C sang cot A
Chuyen dia 1 tu cot B sang cot A
Chuyen dia 3 tu cot C sang cot B
Chuyen dia 1 tu cot A sang cot C
Chuyen dia 2 tu cot A sang cot B
Chuyen dia 1 tu cot C sang cot B
```
