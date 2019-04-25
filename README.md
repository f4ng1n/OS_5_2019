# OS_5_2019
# CREATION AND DESTRUCTION OF PROCESSES   
## Mục đích bài lab:   
Làm quen với các lệnh hệ thống đảm bảo cho việc tạo process.   
## Lý thuyết cơ bản   
* Lệnh cơ bản để tạo một process mới trong hệ điều hành, chuẩn POSIX:   
````pid_t````     ````fork(void)````     
  Lệnh ````fork()````, được tạo trong một process nào đó, mà sẽ gọi là "parents", tạo nên các "process-children". Process con thao táo hoàn toàn sao y theo process "parents" (cha). Khi tạo dữ liệu của process cha được sao chép lại vào process con và cả hai process bắt đầu thực hiện song song. Sự khác biệt quan trọng của process cha so với processc con, chính là giá trị kết quả, trả về của hàm fork(). Giá trị trả về của process con là 0, của process cha trả về identificator của process con, nghĩa là:   
  ````pid_t pid = fork();     
  if (pid == 0) {    
	//дочерний процесс````
````}else{   ```` 
	````//родительский процесс; ````  
````}````   
где pid – возвращаемое значение, 0 – дочернему процессу, > 0 – родительскому процессу, -1 – в случае ошибки.   

