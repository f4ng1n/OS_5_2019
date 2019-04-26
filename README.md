# OS_5_2019
# CREATION AND DESTRUCTION OF PROCESSES   
## Mục đích bài lab:   
Làm quen với các lệnh hệ thống đảm bảo cho việc tạo process.   
## Lý thuyết cơ bản   
* Lệnh cơ bản để tạo một process mới trong hệ điều hành, chuẩn POSIX:   
````pid_t````     ````fork(void)````     
  Lệnh ````fork()````, được tạo trong một process nào đó, mà sẽ gọi là "parents", tạo nên các "process-children". Process con thao táo hoàn toàn sao y theo process "parents" (cha). Khi tạo dữ liệu của process cha được sao chép lại vào process con và cả hai process bắt đầu thực hiện song song. Sự khác biệt quan trọng của process cha so với processc con, chính là giá trị kết quả, trả về của hàm fork(). Giá trị trả về của process con là 0, của process cha trả về identificator của process con, nghĩa là:
  
````pid_t	pid	=	fork();
if (pid == 0) {
	//дочерний процесс
}else{
	//родительский процесс;
}
````
pid – giá trị trả về, 0 – child process, > 0 – parent process, -1 – trường hợp bị lỗi.   
Lược đồ quy trình thực thi cặp parent-child process là sơ đồ mà parent process tạm dừng thực thi cho đến khi hoàn thành child process bằng một hàm đặc biệt:   
````pid_t waitpid(pid_t pid, int *status, int options),````
pid – ID của child process, việc hoàn thành theo dự kiến,   
status – kết quả hoàn thành child-process,  
options – các chế độ của hàm.  
* Trong một vài trường hợp, lệnh fork() được lập trình viên sử dụng để tổ chức thực hiện song song của các processes trong phạm vi cùng một chương trình.  
* Trong trường hợp khác, child process cần phải thực hiện chương trình bên ngoài. Trong trường hợp này, để chạy chươnng trình bên ngoài thì trong child process cần có exec() family of function. Sự đa dạng của hàm này như sau:  
````
1.int execl(const char *path, const char *arg, ...),
2.int execlp(const char *file, const char *arg, ...),
3.int execle(const char *path, const char *arg,..., char * const envp[]),
4.int execlpe(const char *file, const char *arg , ..., NULL, char * const envp[]),
5.int execv(const char *path, char *const argv[]),
6.int execvp(const char *file, char *const argv[]),
7.int execve(const char * path, char *const argv[],char *const envp[]),
8.int execvpe(const char *file, char *const argv[],char *const envp[]).
````

* Nếu ký tự 'l' có trong tên hàm, các đối số arg của dòng lệnh được truyền dưới dạng danh sách arg0, arg1 .... argn, NULL.  
* Nếu ký tự ‘v' có mặt trong tên hàm, các đối số dòng lệnh được truyền dưới dạng một mảng argv []. Các đối số riêng biệt được giải quyết thông qua argv [0], argv [1], ..., argv [n]. Đối số cuối cùng (argv [n]) phải là NULL.  
* Nếu  ký tự 'e' có mặt trong tên hàm, thì đối số cuối cùng của hàm là một mảng các biến môi trường envp [].  
* Nếu ký tự 'p' có mặt trong tên hàm, thì chương trình  với tên file được tìm kiếm không chỉ trong thư mục hiện tại mà còn trong các thư mục được xác định bởi biến môi trường PATH.   
* Nếu ký tự 'p' không có trong tên hàm, thì chương trình với tên path tìm kiếm không chỉ trong thư mục hiện tại, hoặc là tên path phải chỉ đến đường dẫn đầy đủ đến tập tin.   
* Hàm execve() là hàm chính trong family, các hàm còn lại đảm bảo interface cho nó.  
* Trong trường hợp lệnh gọi thành công, hàm không trả về bất kỳ giá trị kết quả nào. Trường hợp lỗi trả về -1, biến toàn cục errno gán một giá trị theo loại lỗi.  
## Yêu cầu thực hiện   
Viết chương trình 1, khi khởi động sẽ có một vài (3 Hay5) đối số trên dòng lệnh và sau đó trong một vòng lặp sẽ hiển thị từng đối số lên màn hình với độ trễ vài giây.  
Chương trình 1 sẽ hiển thị mã định danh và ID tiến trình cha.  
Chương trình 1 sẽ tạo mã thoát.  
Viết chương trình 2, bắt đầu chương trình 1 dưới dạng một tiến trình con bằng cách sử dụng các lệnh gọi fork () và exec ().  
Chương trình 2 sẽ hiển thị ID tiến trình cha, ID của nó và ID tiến trình con.   
Chương trình 2 sẽ tạo thành một tập hợp các tham số để truyền các đối số dòng lệnh cho tiến trình con.  
Chương trình 2 nên chờ hoàn thành quá trình con, kiểm tra sự kiện hoàn thành cứ sau nửa giây và sau khi hoàn thành quá trình con, hiển thị mã thoát.  
