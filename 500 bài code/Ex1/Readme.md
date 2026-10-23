# Mô tả thuật toán và dữ liệu kiểm thử

## Bài 1: Tìm cặp phần tử có tổng bằng giá trị cho trước

### Mô tả bài toán

Cho một mảng số nguyên chưa sắp xếp và số nguyên `target`. In ra mọi cặp phần tử ở hai vị trí khác nhau có tổng bằng `target`. Chương trình duyệt theo thứ tự chỉ số, nên thứ tự các cặp được in phụ thuộc vào thứ tự phần tử trong mảng.

### Dữ liệu vào

- Dòng 1: số nguyên `n`, số phần tử của mảng.
- Dòng 2: `n` số nguyên của mảng.
- Dòng 3: số nguyên `target`.

### Dữ liệu ra

- Với mỗi cặp tìm được, in một dòng theo dạng `Pair found (x, y)`.
- Nếu không có cặp nào, kết quả dự kiến là `Pair not found`.

### Mô tả giải thuật

1. Đọc `n`, sau đó đọc lần lượt `n` phần tử vào mảng `a`.
2. Đọc giá trị cần tìm `target`.
3. Dùng vòng lặp ngoài chọn từng vị trí `i` từ `0` đến `n - 1`.
4. Với mỗi `i`, dùng vòng lặp trong chọn `j` từ `i + 1` đến `n - 1`. Bắt đầu từ `i + 1` để không ghép một phần tử với chính nó và không xét lại cặp theo thứ tự ngược.
5. Nếu `a[i] + a[j] == target`, in cặp `(a[i], a[j])` và tăng biến đếm số cặp.
6. Sau khi duyệt hết mảng, nếu biến đếm bằng `0`, in thông báo không tìm thấy cặp.

### Độ phức tạp

- Thời gian: `O(n²)`, vì xét tối đa mọi cặp chỉ số.
- Bộ nhớ phụ: `O(1)` ngoài mảng lưu dữ liệu đầu vào.

### Bộ dữ liệu kiểm thử

#### Test case 1 - Có nhiều cặp

**Input**

```text
6
8 7 2 5 3 1
10
```

**Output**

```text
Pair found (8, 2)
Pair found (7, 3)
```

**Giải thích:** `8 + 2 = 10` và `7 + 3 = 10`. Các cặp được in theo thứ tự duyệt chỉ số.

#### Test case 2 - Có số âm và số 0

**Input**

```text
5
4 -1 6 0 5
5
```

**Output**

```text
Pair found (-1, 6)
Pair found (0, 5)
```

**Giải thích:** `-1 + 6 = 5` và `0 + 5 = 5`.

#### Test case 3 - Không tồn tại cặp phù hợp

**Input**

```text
4
1 2 4 8
7
```

**Output**

```text
Pair not found
```

**Giải thích:** Không có hai phần tử ở hai vị trí khác nhau nào có tổng bằng `7`.

## Bài 2 — Kiểm tra và in các mảng con có tổng bằng 0 (`Ex2.c`)

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
- Bộ nhớ phụ: `O(1)` ngoài mảng đầu vào.

### Bộ dữ liệu kiểm thử

#### Test case 1 — Nhiều mảng con có tổng bằng 0

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

#### Test case 2 — Không tồn tại mảng con có tổng bằng 0

**Input**

```text
4
1 2 4 8
```

**Output:** Không có dòng nào được in.

**Giải thích:** Mọi phần tử đều dương nên tổng của mọi mảng con liên tiếp đều lớn hơn `0`.

#### Test case 3 — Có mảng con độ dài một và các mảng con chồng lấn

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
