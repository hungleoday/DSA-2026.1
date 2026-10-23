## Bài 6 — Tìm mảng con dài nhất gồm các số nguyên liên tiếp (`Ex6.c`)

### Mô tả bài toán

Cho một mảng số nguyên, tìm mảng con liên tiếp dài nhất mà các giá trị trong đó đôi một khác nhau và tạo thành một dãy số nguyên liên tiếp, không cần theo thứ tự tăng dần. Ví dụ, `{0, 2, 1, 4, 3}` thỏa mãn vì gồm đủ các số từ `0` đến `4`.

### Dữ liệu vào

- Dòng 1: số nguyên `n`, số phần tử của mảng.
- Dòng 2: `n` số nguyên.

### Dữ liệu ra

In mảng con tìm được theo dạng `The largest subarray is { ... }`. Nếu có nhiều mảng con cùng độ dài lớn nhất, chương trình giữ mảng con đầu tiên gặp trong thứ tự duyệt.

### Mô tả giải thuật

1. Đọc `n` và các phần tử vào mảng `a`. Khởi tạo độ dài lớn nhất là `1` và mảng con tốt nhất là phần tử đầu tiên.
2. Dùng hai vòng lặp để xét từng đoạn liên tiếp `a[i..j]`.
3. Khi mở rộng đoạn, kiểm tra xem `a[j]` đã xuất hiện trong phần trước `a[i..j-1]` chưa. Nếu đã có, dừng mở rộng đoạn bắt đầu tại `i`, vì đoạn dài hơn cũng sẽ chứa giá trị trùng.
4. Với đoạn không có phần tử trùng, tìm giá trị nhỏ nhất `min_val` và lớn nhất `max_val`.
5. Đoạn gồm các số nguyên liên tiếp khi `max_val - min_val == j - i`. Kết hợp với điều kiện các phần tử đôi một khác nhau ở bước 3, đẳng thức này xác nhận đoạn có đủ mọi giá trị trong khoảng từ nhỏ nhất đến lớn nhất.
6. Nếu đoạn hợp lệ dài hơn kết quả hiện tại, lưu lại vị trí đầu và cuối của đoạn.
7. Sau khi xét hết các đoạn, in mảng con dài nhất đã lưu.

### Độ phức tạp

- Thời gian: `O(n³)` trong trường hợp xấu nhất, do xét `O(n²)` đoạn và mỗi lần kiểm tra trùng lặp hoặc tìm min/max có thể tốn `O(n)`.
- Bộ nhớ phụ: `O(1)` ngoài mảng đầu vào.

### Bộ dữ liệu kiểm thử

#### Test case 1

**Input**

```text
8
2 0 2 1 4 3 1 0
```

**Output**

```text
The largest subarray is { 0, 2, 1, 4, 3 }
```

**Giải thích:** Đoạn `[0, 2, 1, 4, 3]` liên tiếp trong mảng, có đủ các giá trị `0, 1, 2, 3, 4` và có độ dài `5`.

#### Test case 2

**Input**

```text
5
10 12 11 14 13
```

**Output**

```text
The largest subarray is { 10, 12, 11, 14, 13 }
```

**Giải thích:** Các giá trị `10` đến `14` đều xuất hiện đúng một lần trong toàn bộ mảng.

#### Test case 3 

**Input**

```text
4
5 5 5 5
```

**Output**

```text
The largest subarray is { 5 }
```

**Giải thích:** Hai phần tử liền nhau đã bị trùng, nên đoạn hợp lệ dài nhất chỉ gồm một phần tử.