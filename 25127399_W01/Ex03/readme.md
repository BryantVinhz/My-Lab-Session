# Assignment 3 
- The steps I followed to complete this assignment:
    - Firstly, I read the requirement of assignment and give it to Chatbot: Gemini and ChatGPT
    - Secondly, I asked Gemini and ChatGPT to help me generate a structured prompt. This prompt was then used with AI agents (GitHub Copilot and Antigravity) to assist in refactoring the project
    - Prompting: 

        - Vai trò: Bạn là một Senior C++ Developer. Tôi cần bạn giúp refactor lại toàn bộ thư mục dự án quản lý LibManagement từ phương pháp lập trình sử dụng các struct và hàm rời rạc sang mô hình Lập trình Hướng đối tượng (OOP) chuẩn mực của C++.

        - Yêu cầu Kiến trúc (Cực kỳ quan trọng):

            1. GIỮ NGUYÊN cấu trúc file hiện tại:
                - Không gộp file
                - Tiếp tục tách .h (class declaration) và .cpp (implementation)

            2. Chuyển đổi Thực thể (Entity):
                - book → class Book
                - reader → class Reader
                - Chuyển struct → class
                - Thuộc tính private/protected
                - Có constructor, getter/setter đầy đủ

            3. Chuyển đổi Trình quản lý (Manager):
                - borrow + return → class BorrowManager
                - statistics → class Statistics
                - menu → class MenuController
                - Các hàm rời rạc phải trở thành methods

            4. BẮT BUỘC thêm lớp trung tâm:
                - Tạo class Library (core class)
                - Library sẽ quản lý:

                    - danh sách Book
                    - danh sách Reader
                - Tất cả các Manager class phải tương tác thông qua Library (KHÔNG dùng global data)

            5. Quản lý dữ liệu (RẤT QUAN TRỌNG):
                - Việc đọc/ghi file (listBook.txt, listReader.txt) phải nằm trong:

                    - Library hoặc một lớp riêng như DataManager
                - Không để file I/O rải rác nhiều nơi

            6. Ràng buộc thiết kế:
                - Không dùng biến global
                - Tránh circular dependency giữa các class
                - Ưu tiên composition hơn là dependency trực tiếp
                - Đảm bảo mỗi class có một trách nhiệm rõ ràng (SRP)

            7. Kế hoạch Thực thi:

            Bước 1:
                - Đọc toàn bộ file .h/.cpp
                - Phân tích luồng dữ liệu và cách các hàm đang tương tác

            Bước 2:

                - Đề xuất Class Diagram dạng text:

                    - Class nào nằm ở file nào
                    - Thuộc tính chính
                    - Method chính
                    - Quan hệ giữa các class (composition / dependency)
            Bước 3:

                - Dừng lại và chờ tôi xác nhận thiết kế
            Bước 4:

                - Sau khi được duyệt, refactor từng cặp file và chờ xác nhận sau mỗi phần.

        - Nguyên tắc quan trọng:

            - Không thay đổi logic chương trình
            - Không viết lại toàn bộ code một cách mù quáng
            - Code phải dễ đọc, dễ mở rộng
    - Finally, I used the AI agents to iteratively refactor and complete the program based on the approved design