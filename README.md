# soal-shift-sisop-modul-3-B10-2021

Kelompok B10 
Nama Kelompok :
1. Fitrah Arie Ramadhan 05111940000025
2. Yusrill Zubaydi 05111940000160
3. Lathifa Itqonina M 05111940000176


# Soal No 1
Keverk adalah orang yang cukup ambisius dan terkenal di angkatannya. Sebelum dia menjadi ketua departemen di HMTC, dia pernah mengerjakan suatu proyek dimana keverk tersebut meminta untuk membuat server database buku. Proyek ini diminta agar dapat digunakan oleh pemilik aplikasi dan diharapkan bantuannya dari pengguna aplikasi ini. 

Di dalam proyek itu, Keverk diminta: 

A. Pada saat client tersambung dengan server, terdapat dua pilihan pertama, yaitu register dan login. Jika memilih register, client akan diminta input id dan passwordnya untuk dikirimkan ke server. User juga dapat melakukan login. Login berhasil jika id dan password yang dikirim dari aplikasi client sesuai dengan list akun yang ada didalam aplikasi server. Sistem ini juga dapat menerima multi-connections. Koneksi terhitung ketika aplikasi client tersambung dengan server. Jika terdapat 2 koneksi atau lebih maka harus menunggu sampai client pertama keluar untuk bisa melakukan login dan mengakses aplikasinya. Keverk menginginkan lokasi penyimpanan id dan password pada file bernama akun.txt dengan format :

akun.txt

id:password

id2:password2


Jawaban : Pada saat penggunaan yang menginginkan multi-connections maka kita membutuhkan thread sebagai alat untuk melakukan aktifitas tersebut. Oleh karena itu disini saya membuat dua buah thread untuk mengakomodasi hal tersebut untuk menyimpan username dan password. 

Hasilnya adalah sebagai berikut :

![image1A](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1A.jpeg)

![image1AA](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1AA.jpeg)

B. Sistem memiliki sebuah database yang bernama files.tsv. Isi dari files.tsv ini adalah path file saat berada di server, publisher, dan tahun publikasi. Setiap penambahan dan penghapusan file pada folder file yang bernama  FILES pada server akan memengaruhi isi dari files.tsv. Folder FILES otomatis dibuat saat server dijalankan. 

Jawaban : Setiap memasukkan sesuatu akan dideteksi dan akan dimasukkan ke database 

Hasilnya adalah sebagai berikut :


![image1B](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1B.jpeg)


C. Tidak hanya itu, Keverk juga diminta membuat fitur agar client dapat menambah file baru ke dalam server. Direktori FILES memiliki struktur direktori di bawah ini : 

Direktori FILES 

File1.ekstensi

File2.ekstensi



Pertama client mengirimkan input ke server dengan struktur sebagai berikut :
Contoh Command Client :
		
add
		
Output Client Console:
		
Publisher:

Tahun Publikasi:

Filepath:



Kemudian, dari aplikasi client akan dimasukan data buku tersebut (perlu diingat bahwa Filepath ini merupakan path file yang akan dikirim ke server). Lalu client nanti akan melakukan pengiriman file ke aplikasi server dengan menggunakan socket. Ketika file diterima di server, maka row dari files.tsv akan bertambah sesuai dengan data terbaru yang ditambahkan

Jawaban : 

Hasilnya adalah sebagai berikut :

![image1C](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1C.jpeg)


D. Dan client dapat mendownload file yang telah ada dalam folder FILES di server, sehingga sistem harus dapat mengirim file ke client. Server harus melihat dari files.tsv untuk melakukan pengecekan apakah file tersebut valid. Jika tidak valid, maka mengirimkan pesan error balik ke client. Jika berhasil, file akan dikirim dan akan diterima ke client di folder client tersebut. 

Contoh Command client

download TEMPfile.pdf

Jawaban :

Hasilnya adalah sebagai berikut :

![image1DA](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1DA.jpeg)

![image1DB](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1DB.jpeg)

E. Setelah itu, client juga dapat menghapus file yang tersimpan di server. Akan tetapi, Keverk takut file yang dibuang adalah file yang penting, maka file hanya akan diganti namanya menjadi ‘old-NamaFile.ekstensi’. Ketika file telah diubah namanya, maka row dari file tersebut di file.tsv akan terhapus.

Contoh Command Client:

delete TEMPfile.pdf

Jawaban :

Hasilnya adalah sebagai berikut :

![image1E](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1E.jpeg)

F. Client dapat melihat semua isi files.tsv dengan memanggil suatu perintah yang bernama see. Output dari perintah tersebut keluar dengan format. 

Contoh Command Client :

see


Contoh Format Output pada Client:

Nama:

Publisher:

Tahun publishing:

Ekstensi File :

Filepath : 

Nama:

Publisher:

Tahun publishing:

Ekstensi File : 

Filepath : 

Jawaban :

Hasilnya adalah sebagai berikut :

![image1F](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1F.jpeg)

G. Aplikasi client juga dapat melakukan pencarian dengan memberikan suatu string. Hasilnya adalah semua nama file yang mengandung string tersebut. Format output seperti format output f.

Contoh Client Command:

find TEMP

Jawaban :

Hasilnya adalah sebagai berikut :

![image1G](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1G.jpeg)

H. Dikarenakan Keverk waspada dengan pertambahan dan penghapusan file di server, maka Keverk membuat suatu log untuk server yang bernama running.log. Contoh isi dari log ini adalah

running.log

Tambah : File1.ektensi (id:pass)

Hapus : File2.ektensi (id:pass)

Jawaban :

Hasilnya adalah sebagai berikut :

![image1H](https://github.com/Fitrah1812/soal-shift-sisop-modul-3-B10-2021/blob/main/Dokumentasi/Nomor1H.jpeg)

Kendala :

Kendala pada saat pengerjaan nomor 1 adalah dengan waktu yang terbatas diminta untuk melakukan beberapa komponen yang membuat agak kesulitan karena diminta melakukan beberapa fitur dan kendala lainnya pada syntax yang selalu segmentation fault. Beberapa hal sudah saya lakukan dengan pembuatan thread sebagai akses untuk menyelesaikannya tetapi ada beberapa hal yang membuat socket tidak terhubung dengan sempurna dan menyebabkan beberap hal error. Sehingga belum menyelesaikannya secara sempurna.

  
# Soal No 2
Crypto (kamu) adalah teman Loba. Suatu pagi, Crypto melihat Loba yang sedang kewalahan mengerjakan tugas dari bosnya. Karena Crypto adalah orang yang sangat menyukai tantangan, dia ingin membantu Loba mengerjakan tugasnya. Detil dari tugas tersebut adalah:  
**a.** Membuat program perkalian matrix (4x3 dengan 3x6) dan menampilkan hasilnya. Matriks nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).    

**b.** Membuat program dengan menggunakan matriks output dari program sebelumnya (program soal2a.c) (Catatan!: gunakan shared memory). Kemudian matriks tersebut akan dilakukan perhitungan dengan matrix baru (input user) sebagai berikut contoh perhitungan untuk matriks yang ada. Perhitungannya adalah setiap cel yang berasal dari matriks A menjadi angka untuk faktorial, lalu cel dari matriks B menjadi batas maksimal faktorialnya (dari paling besar ke paling kecil) (Catatan!: gunakan thread untuk perhitungan di setiap cel).   
**Ketentuan :**  
![image](https://user-images.githubusercontent.com/55240758/118424735-f5137a00-b6f1-11eb-8730-985d5a458ed0.png)
   
**c.** Karena takut lag dalam pengerjaannya membantu Loba, Crypto juga membuat program (soal2c.c) untuk mengecek 5 proses teratas apa saja yang memakan resource komputernya dengan command “ps aux | sort -nrk 3,3 | head -5” (Catatan!: Harus menggunakan IPC Pipes)  
**Note:**  
Semua matriks berasal dari input ke program.
Dilarang menggunakan system()   

**Penjelasan :**
  
**No. 2a**  
Membuat program yang dapat melakukan perkalian matriks 4x3 dengan matriks 3x6. Maka terlebih dahulu dilakukan penginputan kedalam matriks yang telah ditentukan. Pada program ini dilakukan penginputan secara manual. Lalu dilakukan perkalian dengan melibatkan array dua dimensi dan tread untuk menjalankan proses perkalian kedua matriks tersebut. Namun sebetulnya dalam perkalian matriks tersebut, dapat dilakukan tanpa membuat thread. Thread tersebut dibuat dengan ```pthread_create(&tid[i][j], NULL, &perkalianmatrix, NULL)``` dan berjalan dengan tid a yang di increment setiap perulangannya. Selanjutnya dilakukan join setiap thread yang sudah dibuat dengan ```pthread_join(tid[a], NULL)```.
  
 ```c
      #include<stdio.h>
      #include<sys/shm.h>
      #include<sys/ipc.h>
      #include<sys/wait.h>
      #include<sys/types.h>
      #include<unistd.h>
      #include<stdlib.h>
      #include<pthread.h>
      #include<string.h>

      int row=0;
      int matriksA[4][3] ;
      int matriksB[3][6];
      int hasil[4][6];

      void inputMatrix(){

        printf("Input matriks 4x3 :\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matriksA[i][j]);
            }
          }
        printf("\nInput matriks 3x6 :\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &matriksB[i][j]);
            }
          }
      }

      void* perkalianmatrix(void* arg){

        int x=row++;

        for(int y=0; y<6; y++){
          for(int z=0; z<3; z++){
            hasil[x][y] += matriksA[x][z] * matriksB[z][y];
          }
        }
      }

      int main(){
        int i=4,j=6;
        int (*matriks)[j];

        pthread_t tid[4];
        inputMatrix();

        for(int a=0; a<4; a++){
          pthread_create(&tid[a], NULL, &perkalianmatrix, NULL);
        }
        for (int a=0; a<4; a++){
          pthread_join(tid[a], NULL);
        }

      key_t key = 1234;
      int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
      matriks =  shmat(shmid, NULL, 0);

      printf("\nHasil Perkalian Matrix: \n");
      for(int b=0; b<i; b++){
        for(int c=0; c<j ; c++){
          printf("%d\t", hasil[b][c]);
        }
        printf("\n");
      }

      int* p = (int *)matriks;

      memcpy(p, hasil, sizeof(int)*i*j);

      shmdt(matriks);
      }
 ```
  
 Hasil yang telah didapatkan akan ditampilkan dan dilakukan share memory dikarenakan hasil perkalian tersebut akan digunakan pada poin selanjutnya yaitu 2b. Share memory sebagai berikut :  
```c
     int (*matriks)[j];
     key_t key = 1234;
     int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
     matriks =  shmat(shmid, NULL, 0);
     
     int* p = (int *)matriks;

     memcpy(p, hasil, sizeof(int)*i*j);

     shmdt(matriks);
```  
Pada share memory ini saya menggunakan template yang ada pada modul 3 yang telah diberikan dengan beberapa penyesuaian. Tahap yang dilakukan dalam melakukan share memory ini yakni membuat terlebih dahulu key nya. Kemudian pada variable matriks tersebut akan berisi segmen memori bersama yang terkait dengan pengidentifikasi memori bersama (key), shmid, ke ruang alamat proses pemanggilan sesuai dengan fungsi ```shmat```. Terdapat pointer p yang akan menunjuk pada setiap isi dalam array matriks dan dilakukan pengcopyan data dengan menggunakan ```memcpy``` melalui variable pointer p terhadap variable hasil agar variable matriks (memori yang di share) akan berisi hasil dari matriks yang telah dikalikan.  

**Screenshot Output:**  
![image](https://user-images.githubusercontent.com/55240758/118431274-1ed39d80-b700-11eb-893c-38f255e00796.png)
  
**No. 2b**  
Berdasarkan hasil perkalian matriks pada poin 2a, dilakukan perhitungan dengan matriks baru yang mana telah dijelaskan ketentuaannya pada soal. Dimana pada setiap perhitungan  cel matriks harus menggunakan thread. terlbih dahulu dilakukan pendeklarasian array dua dimensi pada program ini dan saya menggunakan struct dalam program ini untuk mempermudah perolehan data yang saya ingin kan. Program sebagai berikut :  
```c
      #include <stdio.h>
      #include <sys/ipc.h>
      #include <sys/shm.h>
      #include <unistd.h>
      #include <string.h>
      #include <pthread.h>
      #include <stdlib.h>

      int matriksInput[4][6];
      int matriks[4][6];
      unsigned long long hasilOperasi[4][6];

      typedef struct data {
        int matriksA;
        int matriksB;
        int x,y;
      }data;
```  
Pada fungsi main di bawah ini progam dapat mengakses hasil dari operasi pekalian matriks pada program poin 2a melalui share memory dengan key yang telah ditentukan yaitu 1234, dimana nilai tersebut disimpan dalam variable hasil. Kemudian terdapat variable hasil yang akan mencopy data dari variable hasil dengan ```memcpy```  untuk proses operasi yang akan dilakukan selanjutnya. Terdapat fungsi input yang tepisah dari fungsi main, sehingga dilakukan pemanggilan terhadap fungsi tersebut untuk melakukan penginputan. Selanjutnya dilakukan pembuatan pointer index terhadap struct. Setiap operasi sel pada matriks, thread akan dibuat. Maka proses looping pertama thread akan menjalankan **fungsi operation** sebagai routine dengan atribut index sebagai variabel yang digunakan. Thread tersebut dibuat dengan ```pthread_create(&tid[i][j], NULL, &perkalianmatrix, NULL)``` dan berjalan dengan tid i j yang di increment setiap perulangannya. Kemudian dilakukan join terhadap setiap thread yang sudah dibuat dengan ```pthread_join(tid[a], NULL)```. Agar thread berjalan dengan teratur (berurutan) digunakan ```sleep(1)``` dengan begitu antar thread terdapat jeda waktu 1 detik. Setelah fungsi operasi selesai dilakukan penampilan data hasil perolehan operasi. Dan untuk mengakhiri share memory yang sedang berlangsung digunakan ```shmctl```.
```c
      void main(){
        key_t key = 1234;
        int i=4,j=6;
        int (*hasil)[j];
        int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
        hasil = shmat(shmid, NULL, 0);

        int* p = (int *)hasil;
        memcpy(matriks,hasil,sizeof(int)*i*j);

        pthread_t tid[i][j];
        inputMatrix();

        for(int i= 0;i<4;i++)
        {
              for(int j=0;j<6;j++){
                data *index = (data *)malloc(sizeof(data));
                index->matriksA = matriks[i][j];
                index->matriksB = matriksInput[i][j];
                index->x = i;
                index->y = j;
                // printf("matriks A : %d",index->matriksA);
                // printf("matriks B : %d",index->matriksB);
                // printf("baris : %d",index->x);
                // printf("kolom : %d",index->y);
                pthread_create(&tid[i][j],NULL, &operation, (void*)index);
                sleep(1);
              }

        }
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 6; j++) {
            pthread_join(tid[i][j], NULL);
          }
        }

        printf("\nHasil Operasi Matrix : \n");
        for(int b=0; b<i; b++){
          for(int c=0; c<j ; c++){
            printf("%llu\t", hasilOperasi[b][c]);
          }
          printf("\n");
        }
        printf("\n");
        shmdt(hasil);
        shmctl(shmid, IPC_RMID, NULL);
      }
```  
Ada pung fungsi terkait sebaik berikut :    
***Fungsi Input***
```c
        void inputMatrix(){
            printf("Input matriks 4x6 :\n");
          for (int i = 0; i < 4; i++) {
              for (int j = 0; j < 6; j++) {
                  scanf("%d", & matriksInput[i][j]);
              }
            }
        }
```
  
***Fungsi Operation***  
Pada fungsi ini struct digunakan untuk memudahkan dalam pencarian kondisi sesuai dengan perintah soal melalui statement if else.
```c
      void *operation(void* arg){
        data* d = (data*) arg;
        int a = d->matriksA;
        //printf("a :%d\n",a);
        int b = d->matriksB;
        //printf("b :%d\n",b);
        int x = d->x;
        //printf("x :%d\n",x);
        int y = d->y;
        //printf("y :%d\n",y);

        if(a==0 || b==0){
          hasilOperasi[x][y] = 0;
          //printf("hasil if 3: %llu\n",hasilOperasi[x][y]);
        }
        else if (a>=b){
          int temp = a-b;
          hasilOperasi[x][y] = factorial(a)/factorial(temp);
          //printf("hasil if 1: %llu\n",hasilOperasi[x][y]);
        }
        else if(b>a){
          hasilOperasi[x][y] = factorial(a);
          //printf("hasil if 2: %llu\n",hasilOperasi[x][y]);
        }
      }
```

***Fungsi Factorial***  
```c
      unsigned long long factorial(int n) 
      { 
        if(n==0)return 1;
        else
          return n*factorial(n-1);
      }
```
**Screenshot Output :**    
![image](https://user-images.githubusercontent.com/55240758/118435283-e2f10600-b708-11eb-81ae-14a312ea3953.png)
  
**No. 2c**    
Pada poin ini diminta untuk mengecek 5 proses teratas apa saja yang memakan resource komputernya dengan command ```ps aux | sort -nrk 3,3 | head -5```. Dimana command tersebut harus dijalankan melalui IPC Pipes. Program sebagai berikut :  
```c
      #include <stdlib.h>
      #include <stdio.h>
      #include <unistd.h>
      #include <errno.h>

      int pid;
      int pipe1[2];
      int pipe2[2];

      void exec1() {
        // input from stdin (already done)
        // output to pipe1
        dup2(pipe1[1], 1);
        // close fds
        close(pipe1[0]);
        close(pipe1[1]);
        // exec
        execlp("ps", "ps", "aux", NULL);
        // exec didn't work, exit
        perror("bad exec ps");
        _exit(1);
      }

      void exec2() {
        // input from pipe1
        dup2(pipe1[0], 0);
        // output to pipe2
        dup2(pipe2[1], 1);
        // close fds
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        // exec
        execlp("sort", "sort", "-nrk", "3.3", NULL);
        // exec didn't work, exit
        perror("bad exec grep root");
        _exit(1);
      }

      void exec3() {
        // input from pipe2
        dup2(pipe2[0], 0);
        // output to stdout (already done)
        // close fds
        close(pipe2[0]);
        close(pipe2[1]);
        // exec
        execlp("head", "head", "-5", NULL);
        // exec didn't work, exit
        perror("bad exec grep sbin");
        _exit(1);
      }

      void main() {

        // create pipe1
        if (pipe(pipe1) == -1) {
          perror("bad pipe1");
          exit(1);
        }

        // fork (ps aux)
        if ((pid = fork()) == -1) {
          perror("bad fork1");
          exit(1);
        } else if (pid == 0) {
          // stdin --> ps --> pipe1
          exec1();
        }
        // parent

        // create pipe2
        if (pipe(pipe2) == -1) {
          perror("bad pipe2");
          exit(1);
        }

        // fork (grep root)
        if ((pid = fork()) == -1) {
          perror("bad fork2");
          exit(1);
        } else if (pid == 0) {
          // pipe1 --> grep --> pipe2
          exec2();
        }
        // parent

        // close unused fds
        close(pipe1[0]);
        close(pipe1[1]);

        // fork (grep sbin)
        if ((pid = fork()) == -1) {
          perror("bad fork3");
          exit(1);
        } else if (pid == 0) {
          // pipe2 --> grep --> stdout
          exec3();
        }
        // parent
      }
```  
Berdasarkan program tersebut setiap command dibagi menjadi beberapa fungsi yaitu ***fungsi exec1*** yang berisi command ```ps aux```, ***fungsi exec2*** yang berisi command  ``` sort -nrk 3,3```, dan ***fungsi exec3*** yang berisi command ``` head -5 ```. Yang mana pada setiap fungsi main tersebut dilakukan pembuatan pipe sekaligus pemanggilan setiap fungsi exec yang apabila gagal maka akan dilakukan exit dan menampilkan pesan errornya. Pemanggilan setiap fungsi tersebut dengan menerapkan pembuatan fork yang apabila ``` if(pid == 0)``` terpenuhi, maka fungsi exec akan berjalan. Sehingga dapat disimpulkan bahwa setiap fungsi yang dipanggil merupakan child. Dapat diketahui pula command ```ps aux ``` digunakan untuk menampilkan semua proses yang sedang berjalan, command ```sort -nrk 3,3 ``` untuk melakukan sorting berdasarkan ***memory usage*** nya, dan command ```head -5``` agar proses yang ditampilkan merupakan proses 5 teraratas.
  
**Screenshot Output :**  
![image](https://user-images.githubusercontent.com/55240758/118438222-2f8b1000-b70e-11eb-881f-d1caa635e447.png)

# Soal No 3
Seorang mahasiswa bernama Alex sedang mengalami masa gabut. Di saat masa gabutnya, ia memikirkan untuk merapikan sejumlah file yang ada di laptopnya. Karena jumlah filenya terlalu banyak, Alex meminta saran ke Ayub. Ayub menyarankan untuk membuat sebuah program C agar file-file dapat dikategorikan. Program ini akan memindahkan file sesuai ekstensinya ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working directory ketika program kategori tersebut dijalankan.

Diminta terdapat 3 opsi yang bisa dilakukan, yaitu :
1. -f untuk mengkategorikan file yang diminta melalui argumen dari program yang dijalankan
2. -d untuk mengaktegorikan file yang ada di suatu directory tertentu ke folder program yg dijalankan
3. \* untuk mengkategorikan file yang ada di direktory saat ini

Untuk argumen -f, hanya perlu membua thread untuk tiap file yang ingin dikategorikan dan melakuka thread join agar bisa berjalan bersamaan. untuk kodenya seperti dibawah ini
```c
for(int i=2; i<argc; i++) {
		err = pthread_create(&tid[i], NULL, move, (void *)argv[i]);
		if(err != 0) printf("File %d : Sad, gagal :(\n", i-1);
        else printf("File %d : Berhasil Dikategorikan\n", i-1);
}
for(int j=2; j<argc; j++) pthread_join(tid[j], NULL);
```

Untuk argumen -d dan \* sebenarnya sama, hanya berbeda pada direktory yang dibuka. Untuk -d, direktory yang dibuka adalah direktory yang ada di argomen
```c
if(strcmp(argv[1], "-d") == 0) {
    dir = opendir(argv[2]);
		strcpy(folder, argv[2]);
}
```
Untuk \*, direktory yang dibuka adalah direktory saat ini
```c
else if((argv[1][0]=='*') && (strlen(argv[1])==1)) {
		dir = opendir(cwd);
		strcpy(folder, cwd);
}
```
Lalu, untuk setiap file yang ada di direktory tersebut akan diperiksa satu per satu, apakah mereka file atau bukan, jika mereka bukan file maka akan di ignore, sementara jika mereka adalah file, maka akan dibuat thread baru untuk mengkategorikan file tersebut dan akan thread join agar bisa berjalan secara bersamaan
```c
while((dir!=NULL) && (tmp=readdir(dir))) {
		if(tmp->d_type==DT_DIR && strcmp(tmp->d_name, ".")!=0 && strcmp(tmp->d_name, "..")!=0){
			strcpy(deepfolder,folder);
			strcat(deepfolder,"/");
			strcat(deepfolder,tmp->d_name);
			strcat(deepfolder,"/");
			deep();
		}
        if(strcmp(tmp->d_name, ".")==0 || strcmp(tmp->d_name, "..")==0 || strcmp(tmp->d_name, "soal3.c")==0 || strcmp(tmp->d_name, "soal3")==0 || tmp->d_type==DT_DIR) 
		continue;
        err = pthread_create(&tid[i], NULL, move, tmp->d_name);
        if(err != 0) printf("Yah, gagal disimpan :(\n");
        else printf("Direktori sukses disimpan!\n");
        i++;
    }
    for(int j=0; j<i; j++) pthread_join(tid[j], NULL);
    closedir(dir);
}
```
Untuk memindahkan file tersebut dan menkategorikannya, maka akan diambil ekstensi dari file tersebut dengan mengambilnya dari nama lengkap file tersebut menggunakan ```strchr``` dengan pemisah ".", jika ekstension file tidak ada, maka dia akan disimpan ke folder Unknown. Selanjutnya kita perlu membuat folder dengan nama ekstension dari file tersebut dan memindahkan file tersebut ke folder yang sudah dibuat. Di sini saya tidak memindah, melainkan merename filenya agar terpindah.
```c
void *move(void *arg) {
	char *filepath = (char *)arg;
	char *extension = NULL;
	extension = strchr(filepath, '.');
	char ext[1000];
	memset(ext, '\0', sizeof(ext));
	if((extension-filepath-strlen(cwd)+1)==2 || (extension-filepath+1)==1) strcpy(ext, "Hidden");
	else if(extension) {
		extension++;
        for(int i=0; i<strlen(extension); i++) {
               	ext[i] = tolower(extension[i]);
    	}
	}
	else strcpy(ext, "Unknown");
    char *filename = NULL;
    filename = strrchr(filepath, '/');
    if(filename) filename++;
	else filename = filepath;

	char folderpath[1000];
	strcpy(folderpath, cwd);
	strcat(folderpath, "/");
	strcat(folderpath, ext);
	mkdir(folderpath, S_IRWXU);
	if(strlen(deepfolder2)>1){
		char fullname[1000];
		strcpy(fullname, deepfolder2);
		strcat(fullname, "/");
		strcat(fullname, filename);
		strcat(folderpath, "/");
        strcat(folderpath, filename);
        rename(fullname, folderpath);
	}
	else if(strlen(folder) > 1) {
		char fullname[1000];
		strcpy(fullname, folder);
		strcat(fullname, "/");
		strcat(fullname, filename);
		strcat(folderpath, "/");
        strcat(folderpath, filename);
        rename(fullname, folderpath);
	}
	else {					
	    strcat(folderpath, "/");
        strcat(folderpath, filename);
		rename(filepath, folderpath);
	}
	return NULL;
}
````
Kendala yang saya alami untuk menyelesaikan kode ini adalah untuk mengkatorikan file yang ada difolder didalam direktory yg sudah ada secara rekursif. Namun kendala tersebut sudah teratasi di bagian fungsi deep.

Berikut Kode saya secara lengkap
```c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>

pthread_t tid[1000000];
pid_t child;
char cwd[1000];
char folder[1000];
char deepfolder[1000];
char deepfolder2[1000];
int err;

void *move(void *arg) {
	char *filepath = (char *)arg;
	char *extension = NULL;
	extension = strchr(filepath, '.');
	char ext[1000];
	memset(ext, '\0', sizeof(ext));
	if((extension-filepath-strlen(cwd)+1)==2 || (extension-filepath+1)==1) strcpy(ext, "Hidden");
	else if(extension) {
		extension++;
        for(int i=0; i<strlen(extension); i++) {
               	ext[i] = tolower(extension[i]);
    	}
	}
	else strcpy(ext, "Unknown");
    char *filename = NULL;
    filename = strrchr(filepath, '/');
    if(filename) filename++;
	else filename = filepath;

	char folderpath[1000];
	strcpy(folderpath, cwd);
	strcat(folderpath, "/");
	strcat(folderpath, ext);
	mkdir(folderpath, S_IRWXU);
	if(strlen(deepfolder2)>1){
		char fullname[1000];
		strcpy(fullname, deepfolder2);
		strcat(fullname, "/");
		strcat(fullname, filename);
		strcat(folderpath, "/");
        strcat(folderpath, filename);
        rename(fullname, folderpath);
	}
	else if(strlen(folder) > 1) {
		char fullname[1000];
		strcpy(fullname, folder);
		strcat(fullname, "/");
		strcat(fullname, filename);
		strcat(folderpath, "/");
        strcat(folderpath, filename);
        rename(fullname, folderpath);
	}
	else {					
	    strcat(folderpath, "/");
        strcat(folderpath, filename);
		rename(filepath, folderpath);
	}
	return NULL;
}

void minf(int argc, char *argv[]){
    for(int i=2; i<argc; i++) {
		err = pthread_create(&tid[i], NULL, move, (void *)argv[i]);
		if(err != 0) printf("File %d : Sad, gagal :(\n", i-1);
        else printf("File %d : Berhasil Dikategorikan\n", i-1);
	}
	for(int j=2; j<argc; j++) pthread_join(tid[j], NULL);
    return;
}

void deep(){
	DIR *dir;
	struct dirent *tmp;
	int i=0;
	memset(deepfolder2, '\0', sizeof(deepfolder2));
	strcpy(deepfolder2,deepfolder);
	printf("%s\n", deepfolder2);
	dir = opendir(deepfolder2);
	while((dir!=NULL) && (tmp=readdir(dir))) {
		if(tmp->d_type==DT_DIR && strcmp(tmp->d_name, ".")!=0 && strcmp(tmp->d_name, "..")!=0){
			strcat(deepfolder2,tmp->d_name);
			strcat(deepfolder2,"/");
			deep();
		}
        if(strcmp(tmp->d_name, ".")==0 || strcmp(tmp->d_name, "..")==0 || strcmp(tmp->d_name, "soal3.c")==0 || strcmp(tmp->d_name, "soal3")==0 || tmp->d_type==DT_DIR) 
		continue;
        err = pthread_create(&tid[i], NULL, move, tmp->d_name);
        if(err != 0) printf("Yah, gagal disimpan :(\n");
        else printf("Direktori sukses disimpan!\n");
        i++;
    }
    for(int j=0; j<i; j++) pthread_join(tid[j], NULL);
    closedir(dir);
    return;
}

void other(int argc, char *argv[]){
    DIR *dir;
	struct dirent *tmp;
	int i=0;
	if(strcmp(argv[1], "-d") == 0) {
    	dir = opendir(argv[2]);
		strcpy(folder, argv[2]);
	}
	else if((argv[1][0]=='*') && (strlen(argv[1])==1)) {
		dir = opendir(cwd);
		strcpy(folder, cwd);
	}
	else {
		printf("Butuh Argumen -f atau -d atau \\*\n");
        return;
	}
	while((dir!=NULL) && (tmp=readdir(dir))) {
		if(tmp->d_type==DT_DIR && strcmp(tmp->d_name, ".")!=0 && strcmp(tmp->d_name, "..")!=0){
			strcpy(deepfolder,folder);
			strcat(deepfolder,"/");
			strcat(deepfolder,tmp->d_name);
			strcat(deepfolder,"/");
			deep();
		}
        if(strcmp(tmp->d_name, ".")==0 || strcmp(tmp->d_name, "..")==0 || strcmp(tmp->d_name, "soal3.c")==0 || strcmp(tmp->d_name, "soal3")==0 || tmp->d_type==DT_DIR) 
		continue;
        err = pthread_create(&tid[i], NULL, move, tmp->d_name);
        if(err != 0) printf("Yah, gagal disimpan :(\n");
        else printf("Direktori sukses disimpan!\n");
        i++;
    }
    for(int j=0; j<i; j++) pthread_join(tid[j], NULL);
    closedir(dir);
    return;
}

int main(int argc, char *argv[]) {
	getcwd(cwd, sizeof(cwd));
	memset(folder, '\0', sizeof(folder));
	memset(deepfolder, '\0', sizeof(deepfolder));
	memset(deepfolder2, '\0', sizeof(deepfolder2));
	if(argc < 2) {
		printf("Butuh Argumen -f atau -d atau \\*\n");
		return 0;
	}
	if(strcmp(argv[1], "-f") == 0) {
		minf(argc,argv);
	}
	else {
		other(argc,argv);
	}
	return 0;
}
```
