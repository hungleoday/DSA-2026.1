## Bài 2: Kiểm tra và in các mảng con có tổng bằng 0

### Mô tả bài toán

Cho một mảng số nguyên, tìm và in mọi mảng con liên tiếp có tổng bằng `0`. Mảng con phải gồm các phần tử liền nhau trong mảng ban đầu.

### Dữ liệu vào

- Dòng 1: số nguyên `n`, số phần tử của mảng.
- Dòng 2: `n` số nguyên của mảng.

### Dữ liệu ra

- Mỗi mảng con có tổng bằng `0` được in trên một dòng, các phần tử cách nhau bởi dấu cách.
- Nếu không tồn tại mảng con nào, chương trình không in nội dung nào.
- Chương trình chỉ in các mảng con, không in thêm thông báo “tồn tại” hoặc “không tồn tại”.

### Mô tả giải thuật

1. Đọc `n` và các phần tử của mảng `a`.
2. Dùng vòng lặp ngoài chọn vị trí bắt đầu `i` của mảng con.
3. Khởi tạo `sum = a[i]`. Nếu tổng này bằng `0`, in riêng phần tử `a[i]`.
4. Dùng vòng lặp trong lần lượt mở rộng mảng con từ `i + 1` đến từng vị trí `j`, đồng thời cộng `a[j]` vào `sum`.
5. Mỗi khi `sum == 0`, duyệt lại từ `i` đến `j` và in toàn bộ mảng con liên tiếp `a[i..j]` trên một dòng.
6. Tiếp tục với vị trí bắt đầu tiếp theo để tìm các mảng con khác. Các kết quả được in theo thứ tự tăng dần của `i`, rồi theo thứ tự tăng dần của `j`.

### Độ phức tạp

- Thời gian: `O(n³)` trong trường hợp xấu nhất, do có hai vòng lặp tìm các đoạn và một vòng lặp để in mỗi đoạn được tìm thấy.
- Bộ nhớ phụ: `O(1)

### Bộ dữ liệu kiểm thử

#### Test case 1 - Nhiều mảng con có tổng bằng 0

**Input**

```text
10
3 4 -7 3 1 3 1 -4 -2 -2
```

**Output**

```text
3 4 -7
3 4 -7 3 1 3 1 -4 -2 -2
4 -7 3
-7 3 1 3
3 1 3 1 -4 -2 -2
3 1 -4
```

**Giải thích:** Có sáu đoạn liên tiếp có tổng bằng `0`. Chương trình in theo vị trí bắt đầu rồi vị trí kết thúc, nên thứ tự có thể khác thứ tự liệt kê trong ví dụ đề bài.

#### Test case 2 - Không tồn tại mảng con có tổng bằng 0

**Input**

```text
4
1 2 4 8
```

**Output:** Không có dòng nào được in.

**Giải thích:** Mọi phần tử đều dương nên tổng của mọi mảng con liên tiếp đều lớn hơn `0`.

#### Test case 3 - Có mảng con độ dài một và các mảng con chồng lấn

**Input**

```text
3
0 1 -1
```

**Output**

```text
0
0 1 -1
1 -1
```

**Giải thích:** Phần tử `0` tự nó là mảng con có tổng bằng `0`; ngoài ra `[0, 1, -1]` và `[1, -1]` cũng có tổng bằng `0`.