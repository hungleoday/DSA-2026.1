## Bài 4 — Sắp xếp mảng nhị phân trong thời gian tuyến tính

### Mô tả bài toán

Cho một mảng nhị phân chỉ gồm `0` và `1`. Sắp xếp mảng sao cho tất cả số `0` đứng trước tất cả số `1`.

### Dữ liệu vào

- Dòng 1: số nguyên `n`, số phần tử của mảng.
- Dòng 2: `n` giá trị nhị phân (`0` hoặc `1`).

### Dữ liệu ra

In mảng sau khi sắp xếp, các phần tử cách nhau bởi dấu cách. Mã nguồn in thêm một dấu cách sau phần tử cuối.

### Mô tả giải thuật

1. Đọc `n` và từng phần tử vào mảng `a`.
2. Trong lúc đọc, đếm số lượng số `0` bằng biến `count`.
3. Sau khi đọc xong, lưu số lượng số `0` vào biến `one` để giữ nguyên giá trị này.
4. Gán `0` vào `count` vị trí đầu mảng. Vòng lặp `while` giảm `count` về `0` trong quá trình gán.
5. Gán `1` vào các vị trí còn lại, từ `n - one` đến `n - 1`.
6. In toàn bộ mảng đã được sắp xếp.

### Độ phức tạp

- Thời gian: `O(n)`, gồm một lượt đọc, các lượt gán và một lượt in.
- Bộ nhớ phụ: `O(1)`; mảng đầu vào được cập nhật trực tiếp.

### Bộ dữ liệu kiểm thử

#### Test case 1 - Mảng gồm cả 0 và 1

**Input**

```text
8
1 0 1 0 1 0 0 1
```

**Output**

```text
0 0 0 0 1 1 1 1
```

**Giải thích:** Mảng có bốn số `0`, nên bốn vị trí đầu được gán `0`, các vị trí còn lại được gán `1`.

#### Test case 2 - Mảng toàn số 0

**Input**

```text
5
0 0 0 0 0
```

**Output**

```text
0 0 0 0 0
```

#### Test case 3 - Mảng toàn số 1

**Input**

```text
4
1 1 1 1
```

**Output**

```text
1 1 1 1
```
