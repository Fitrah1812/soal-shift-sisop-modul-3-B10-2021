# soal-shift-sisop-modul-3-B10-2021

Kelompok B10 
Nama Kelompok :
1. Fitrah Arie Ramadhan 05111940000025
2. Yusrill Zubaydi 05111940000160
3. Lathifa Itqonina M 05111940000176


# Soal No 1

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

**Screenshot Hasil :**  
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
**Screenshot Hasil :**    
![image](https://user-images.githubusercontent.com/55240758/118435283-e2f10600-b708-11eb-81ae-14a312ea3953.png)

  
