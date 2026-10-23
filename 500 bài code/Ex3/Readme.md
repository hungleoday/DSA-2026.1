## Bài 3 — In tất cả mảng con có tổng bằng 0

### Mô tả bài toán

Cho một mảng số nguyên, in tất cả các mảng con liên tiếp có tổng bằng `0`

### Dữ liệu vào

- Dòng 1: số nguyên `n`, số phần tử của mảng.
- Dòng 2: `n` số nguyên của mảng.

### Dữ liệu ra

- Mỗi mảng con liên tiếp có tổng bằng `0` được in trên một dòng, các phần tử cách nhau bởi dấu cách.
- Nếu không tìm thấy mảng con nào, chương trình không in nội dung nào.

### Mô tả giải thuật

1. Đọc `n` và lưu các phần tử vào mảng `a`.
2. Lần lượt chọn mỗi chỉ số `i` làm điểm bắt đầu của mảng con.
3. Đặt `sum = a[i]`; nếu `sum` bằng `0`, in mảng con một phần tử `[a[i]]`.
4. Duyệt các chỉ số kết thúc `j` từ `i + 1` đến cuối mảng, cộng `a[j]` vào `sum` để tính tổng đoạn `a[i..j]`.
5. Khi `sum == 0`, duyệt từ `i` đến `j` và in các phần tử của đoạn đó.
6. Tiếp tục cho mọi vị trí bắt đầu. Kết quả được in theo thứ tự vị trí đầu tăng dần, sau đó vị trí cuối tăng dần.

### Độ phức tạp

- Thời gian: `O(n³)` trong trường hợp xấu nhất, do có thể phải duyệt và in nhiều đoạn.
- Bộ nhớ phụ: `O(1)` ngoài mảng lưu dữ liệu.

### Bộ dữ liệu kiểm thử

#### Test case 1 

**Input**

```text
6
4 2 -3 -1 0 4
```

**Output**

```text
-3 -1 0 4
0
```

**Giải thích:** `-3 + (-1) + 0 + 4 = 0`; phần tử `0` cũng tự tạo thành một mảng con có tổng bằng `0`.

#### Test case 2 - Không có mảng con tổng bằng 0

**Input**

```text
3
1 2 3
```

**Output:** Không có dòng nào được in.

#### Test case 3 - Có các đoạn chồng lấn và phần tử 0

**Input**

```text
3
1 -1 0
```

**Output**

```text
1 -1
1 -1 0
0
```

**Giải thích:** Hai đoạn bắt đầu ở vị trí đầu tiên có tổng bằng `0`; phần tử cuối bằng `0` tạo thêm một mảng con đơn.