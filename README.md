# Ý tưởng thực hiện bài code
## Hệ thống quản lí xuất nhập kho
- Tạo một kho lưu trữ các mặt hàng có sẵn bằng mảng((cấp phát động) (Dùng C), còn trong C++ dùng vector cho tiện)
- Kho chứa tối đa được 100 mặt hàng, mỗi mặt hàng có các data( Tên sp, mã sp, số lượng, giá thành/1sp, mã code cập nhật tự động cho sản phẩm)

### Hệ thống sẽ có các chức năng
#### Hiển thị kho  (1)
      - Sử dụng MENU lựa chọn để làm giao diện cho hệ thống
      1. Hiển thị các mặt hàng tồn kho (Hệ thống sẽ thông báo các mặt hàng có số lượng quá ít trong kho( < 20sp )).
      2. Hệ thống tự động tính toán tổng số tiền hàng có trong kho.
#### Xuất kho  (2)
      1. Xuất kho (Bạn sẽ cần nhập mã code sản phẩm, số lượng mặt hàng muốn xuất kho, sau đó hệ thống sẽ yêu cầu nhập thông tin xuất kho của từng loại mặt hàng (mã sp, số lượng))
      2. Nếu số lượng sp xuất kho vượt quá số lượng mặt hàng có trong kho, hệ thống tự động báo lỗi và yêu cầu nhập lại.
      3. Sau khi xuất kho, kho hàng tự động cập nhật thông tin cho người dùng
#### Nhập kho  (3)
      1. Cần chọn nhập vào mặt hàng mới hay nhập thêm hàng của mặt hàng sẵn có
      2. Nhập số lượng chỉ cần nhập mã sẽ hiển thị thông tin mặt hàng sẵn có và chỉ cần nhập thêm số lượng
      3. Nhập măt hàng mới sẽ cần nhập các thông tin đi kèm 
#### Sắp xếp các mặt hàng theo yêu cầu  (4)
      Chức năng này giúp phục vụ việc kiểm tra hàng hoá
      1. Tăng giảm theo giá thành
      2. Tăng giảm theo số lượng
      (Dùng menu tăng giảm để kiểm tra)
#### Nhập mã sản phẩm để hiện thông tin  (5)
    1. Khi bạn nhập code của sản phẩm sẽ hiện ra tên sản phẩm, số lượng, giá thành.
    2. Nếu code sai sẽ in ra không có sản phẩm này.
#### Xem lịch sử thay đổi của kho hàng (6)
    1.Nhập hay xuất hay thay đổi sẽ được ghi vào file và xuất ra bằng chức năng số (6)
#### Xoá mặt hàng có săn trong kho(7)
    1. Nhập mã mặt hàng cần xoá và mặt hàng sẽ bị xoá khỏi kho
#### Chỉnh sửa giá của mặt hàng (8)
    1. Nhập mã của mặt hàng cần thay đổi giá và nhập giá mới
##### Thoát hệ thống (0)
     RETURN 0;
