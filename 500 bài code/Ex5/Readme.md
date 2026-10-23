## Bài 5 — Tìm phần tử trùng lặp trong mảng giới hạn

### Mô tả bài toán

Mảng có `n` phần tử, mỗi giá trị thuộc đoạn từ `1` đến `n - 1`; một giá trị xuất hiện lặp lại. Tìm và in giá trị trùng lặp. Cách tính em sử dụng trong chương trình áp dụng khi mảng gồm đủ các giá trị `1..n-1` và có đúng một phần tử bị lặp thêm một lần.

### Dữ liệu vào

- Dòng 1: số nguyên `n`, kích thước mảng.
- Dòng 2: `n` số nguyên thuộc đoạn `1..n-1`.

### Dữ liệu ra

In kết quả theo dạng `The duplicate number is X`, trong đó `X` là giá trị trùng lặp.

### Mô tả giải thuật

1. Đọc `n` và các phần tử của mảng; đồng thời tính tổng tất cả phần tử, gọi là `sum`.
2. Tính tổng các số nguyên từ `1` đến `n - 1` theo công thức `sum_id = n * (n - 1) / 2`.
3. Lấy `sum - sum_id`. Vì mảng có đủ một bản sao của mỗi số `1..n-1` và có thêm một lần xuất hiện của số trùng, hiệu này chính là giá trị trùng lặp.
4. In giá trị tìm được.

### Độ phức tạp

- Thời gian: `O(n)`, đọc mảng và tính tổng trong một lượt.
- Bộ nhớ phụ: `O(1)` ngoài mảng lưu dữ liệu.

### Bộ dữ liệu kiểm thử

#### Test case 1

**Input**

```text
5
1 2 3 4 4
```

**Output**

```text
The duplicate number is 4
```

#### Test case 2 

**Input**

```text
5
1 3 2 4 2
```

**Output**

```text
The duplicate number is 2
```

#### Test case 3

**Input**

```text
5
4 1 3 2 3
```

**Output**

```
The duplicate number is 3