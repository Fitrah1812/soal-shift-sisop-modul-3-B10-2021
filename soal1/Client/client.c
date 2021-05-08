#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <pthread.h>
#include <wait.h>
#include <time.h>
#define maxi 1024
#define PORT 8080


typedef struct mamang
{
    char id[maxi];
    int check;
    char mantap[maxi];
   
}memeng;
typedef struct cekbuku
{
    char publisher[maxi];
    char path[maxi];
    int tahun;
   
}sitasi;
typedef struct loginaja
{
    char id[maxi];
    int status;
    char password[maxi];
    
}login;
void menuutama(){
    puts("Selamat datang di Aplikasi ini");
    puts("Berikut merupakan pilihan aksi yang diberikan");
    puts("1. Melakukan Registrasi");
    puts("2. Melakukan login");
    printf("Silahkan memasukkan pilihan yang sudah tersedia = ");
}
void ambilusername(){
    printf("Masukkan username = ");
}

void menusukseslogin(){
    puts("Selamat datang di halaman utama");
    puts("Silahkan memilih aksi yang diinginkan (add/download/delete/see/find)");
    printf("Jawaban = ");
}
void ambilpassword(){
    printf("Masukkan Password = ");
}
int main(int argc, char const *argv[])
{
	int sock = 0, valread;
    int cekloginbrow = 0;
    login login1;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	// if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	// {
	// 	printf("\nInvalid address/ Address not supported \n");
	// 	return -1;
	// }
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
    //cek perulangan

    while (1)
    {
        if (!cekloginbrow)
        {
            char username1[maxi];
            char password1[maxi];
            char message[maxi];
            int cek;
            char buffer[maxi];
            int flag;
            menuutama();
            scanf("%d",&cek);
            login1.status = cek-1;
            if(cek == 1)
            {
                //cek apabila sudah sesuai
                ambilusername();
                scanf("%s",buffer);
                //copas setiap akun
                strcpy(login1.id,buffer);
                ambilpassword();
                //cek password
                scanf("%s",buffer);
                strcpy(login1.password,buffer);
                int snd = send(sock,(void*)&login1,sizeof(login1),0);
                if (flag = recv(sock,(void*)&message,sizeof(message),0) < 0)
                {
                    perror("Register gagal");
                    exit(EXIT_FAILURE);
                }
                cekloginbrow = 1;
            }
            else if(cek == 2)
            {
                //login
                char usernameusername[maxi];
                char usernamepassword[maxi];
                printf("Masukkan Username =  ");
                scanf("%s", buffer);
                printf("Masukkan Password = ");
                scanf("%s", buffer);
                if (flag = recv(sock,(void*)&message,sizeof(message),0) < 0)
                {
                    perror("Gagal membuat akun");
                    exit(EXIT_FAILURE);
                }
                cekloginbrow=1;
            } 
        }
        else
        {
            int flag1;
            menusukseslogin();
            char pilihan[1024];
            scanf("%s", pilihan);
            if (flag1 = send(sock,(void*)&pilihan,sizeof(pilihan),0) < 0)
            {
                perror("Sedang Mengirimkan");
                exit(EXIT_FAILURE);
            }
            if(strcmp(pilihan, "add") == 0)
            {
                sitasi lah;
                int flag2;
                login1.status = 3;
                printf("Publisher: ");
                scanf("%s",lah.publisher);
                char message[1024]= {};
                printf("Tahun Publikasi: ");
                scanf("%d",&lah.tahun);

                printf("path: ");
                scanf("%s",lah.path);

                char pesan[maxi];
                int pesanditerima;

                if (flag2 = send(sock,(void*)&lah,sizeof(lah),0) < 0)
                {
                    perror("Send add");
                    exit(EXIT_FAILURE);
                }
                if (pesanditerima = recv(sock,(void*)&message,sizeof(message),0) < 0)
                {
                    perror("Add Failed");
                    exit(EXIT_FAILURE);
                }
                printf("%s\n",message);
            }
            else if (strcmp(pilihan, "download") == 0)
            {
                char download[1024]= {};
                int senddownload;
                char message[1024];
                int pesanditerima;

                printf("Masukkan nama file yang ingin didownload = ");
                scanf("%s",download);
                if (senddownload = send(sock,(void*)&download,sizeof(download),0) < 0)
                {
                    perror("Download sudah dikirimkan");
                    exit(EXIT_FAILURE);
                }
                if (pesanditerima = recv(sock,(void*)&message,sizeof(message),0) < 0)
                {
                    perror("Download Failed");
                    exit(EXIT_FAILURE);
                }
                printf("%s\n",message);
            }
            else if (strcmp(pilihan, "delete") == 0)
            {
                char delete[maxi];
                int del;
                char message[maxi];
                int pesanditerima;
                printf("Nama file yang akan dihapus: ");
                scanf("%s",delete);
                if (del = send(sock,(void*)&delete,sizeof(delete),0) < 0)
                {
                    //cek error
                    perror("Mengirimkan delete");
                    exit(EXIT_FAILURE);
                }
                if (pesanditerima = recv(sock,(void*)&message,sizeof(message),0) < 0)
                {
                    perror("download_gagal");
                    exit(EXIT_FAILURE);
                }
                printf("%s\n",message);
            }
            else if (strcmp(pilihan, "find") == 0)
            {
                printf("Masukkan Pola kata: ");
                char pola[maxi];
                sitasi savede[maxi];
                int fndMsg;
                int sendFnd;
                scanf("%s",pola);
                if (sendFnd = send(sock,(void*)&pola,sizeof(pola),0) < 0)
                {
                    perror("Mengirimkan find");
                    exit(EXIT_FAILURE);
                }
                if (fndMsg = recv(sock,(void*)&savede,sizeof(savede),0) < 0)
                {
                    perror("cek gagal");
                    exit(EXIT_FAILURE);
                }
                //cek satu persatu
                for (int i=0; i<maxi; i++)
                {
                    if (savede[i].tahun == 0)
                    {
                        break;
                    } 
                    sitasi rd = savede[i];
                    char cekking[maxi];
                    strcpy(cekking,rd.path);
                    char* oker = strrchr(cekking,'/');
                    //remove
                    memmove(&oker[0],&oker[1],strlen(oker) - 0);
                    //print nama
                    printf("%s\n",oker);
                }
            }
            else if (strcmp(pilihan, "see") == 0)
            {
                sitasi savede[maxi];
                int hore;
                if (hore = recv(sock,(void*)&savede,sizeof(savede),0) < 0)
                {
                    perror("Aksi see error");
                    exit(EXIT_FAILURE);
                }
                for (int i=0 ; i<maxi; i++)
                {
                    sitasi rd = savede[i];
                    char ceke[maxi];
                    char buff2[maxi];
                    char* cekes = strrchr(buff2,'.');
                    char* oker = strrchr(ceke,'/');
                    
                    
                    strcpy(ceke,rd.path);
                    if (savede[i].tahun == 0){
                        break;
                    }
                    memmove(&oker[0],&oker[1],strlen(oker) - 0);
                    printf("Nama: %s\n",oker);

                    printf("Publisher: %s\n",savede[i].publisher);

                    printf("Tahun Publishing: %d\n",savede[i].tahun);
                    strcpy(buff2,oker);

                    memmove(&cekes[0],&cekes[1],strlen(cekes) - 0);

                    printf("Ekstensi File: %s\n",cekes);

                    printf("Filepath: %s\n",savede[i].path);

                    puts("");
                }
            }
        }
    }
	return 0;
}
