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
#define PORT 8080
#define maxi 1024

typedef struct mamang
{
    char id[maxi];
    int check;
    char mantap[maxi];
   
}memeng;
typedef struct ceksitasi
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

// int cekpthread()
// {
//     pthread_t thread1, thread2;//inisialisasi awal
//     const char *message1 = "Thread 1";
//     const char *message2 = "Thread 2";
//     int  iret1, iret2;

//     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1); //membuat thread pertama
//     if(iret1) //jika eror
//     {
//         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
//         exit(EXIT_FAILURE);
//     }

//     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);//membuat thread kedua
//     if(iret2)//jika gagal
//     {
//         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
//         exit(EXIT_FAILURE);
//     }

//     printf("pthread_create() for thread 1 returns: %d\n",iret1);
//     printf("pthread_create() for thread 2 returns: %d\n",iret2);

//     // pthread_join( thread1, NULL);
//     // pthread_join( thread2, NULL); 

//     exit(EXIT_SUCCESS);
// }
void *print_message_function( void *ptr )
{
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);

    for(int i=0;i<10;i++){
        printf("%s %d \n", message, i);
    }
}

int main(int argc, char const *argv[])
{

	int server_fd, new_socket, valread;
	struct sockaddr_in address;
    int cekloginbrow = 0;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("set sock opt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if (!cekloginbrow)
        {
            login login;
            int tmp;
            if (tmp = recv(new_socket,(void*)&login,4*maxi,0) < 0)
            {
                perror("Penerima hal yang diinginkan");
                exit(EXIT_FAILURE);
            }
            if (login.status == 1)
            {
                char pesan[maxi];
                FILE* f;
                f = fopen("akun.txt","a+");
                char buffer[maxi];
                int flag = 0;
                int benar = 0;
                while (fscanf(f,"%s",buffer) != EOF)
                {
                    printf("%s\n",buffer);
                    const char s[2] = ":";
                    char *per;
                    per = strtok(buffer, s);
                    char apa[maxi];
                    char cobacek[maxi];
                    strcpy(apa,per);
                    strcpy(cobacek,"");
                    //char inbuf[MSGSIZE]; 
                    int p[2], i; 

                    if (pipe(p) < 0) 
                        exit(1); 

                    /* continued */
                    /* write pipe */

                    // write(p[1], msg1, MSGSIZE); 
                    // write(p[1], msg2, MSGSIZE); 
                    // write(p[1], msg3, MSGSIZE); 

                    // for (i = 0; i < 3; i++) { 
                    //     /* read pipe */
                    //     //read(p[0], inbuf, MSGSIZE); 
                    //     //printf("%s\n", inbuf); 
                    // }  
                    while(per!=NULL) 
                    {
                        printf( " %s %d\n", per,(int)strlen(cobacek));
                        per = strtok(NULL, s);
                        if (strlen(cobacek) == 0)
                            strcpy(cobacek,per);
                    }
                    if (strcmp(apa,login.id)==0)
                    {
                        flag = 1;
                        printf("%s\n",cobacek);
                        if (strcmp(cobacek,login.password) == 0)
                        {
                            //coba crosscheck
                            benar = 1;
                        }
                            
                        break;
                    }
                }
                pthread_t thread1, thread2;//inisialisasi awal
                const char *message1 = "Thread 1";
                const char *message2 = "Thread 2";
                int  iret1, iret2;

                iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1); //membuat thread pertama
                if(iret1) //jika eror
                {
                    fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
                    exit(EXIT_FAILURE);
                }

                iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);//membuat thread kedua
                if(iret2)//jika gagal
                {
                    fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
                    exit(EXIT_FAILURE);
                }

                // printf("pthread_create() for thread 1 returns: %d\n",iret1);
                // printf("pthread_create() for thread 2 returns: %d\n",iret2);

                // pthread_join( thread1, NULL);
                // pthread_join( thread2, NULL); 

                exit(EXIT_SUCCESS);
                fclose(f);
                if (!flag)
                {
                    strcpy(pesan,"User tidak ditemukan!");
                    continue;
                }
                else if (!benar)
                {
                    strcpy(pesan,"Password yang anda masukkan salah");
                    continue;
                }
                else
                {
                    strcpy(pesan,"Login telah berhasil dilakukan !!");
                }
                if (tmp = send(new_socket, (void*)&pesan,strlen(pesan),0) < 0)
                {
                    perror("Register");
                    exit(EXIT_FAILURE);
                }
                cekloginbrow = 1;
            }
            else if(login.status == 0)
            {
                char pesan[maxi];
                char buffer[1024];
                int flag = 0;
                FILE* f;
                f = fopen("akun.txt","a+");
                // pthread_t thread1, thread2;//inisialisasi awal
                // const char *message1 = "Thread 1";
                // const char *message2 = "Thread 2";
                // int  iret1, iret2;

                // iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1); //membuat thread pertama
                // if(iret1) //jika eror
                // {
                //     fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
                //     exit(EXIT_FAILURE);
                // }

                // iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);//membuat thread kedua
                // if(iret2)//jika gagal
                // {
                //     fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
                //     exit(EXIT_FAILURE);
                // }

                // // printf("pthread_create() for thread 1 returns: %d\n",iret1);
                // // printf("pthread_create() for thread 2 returns: %d\n",iret2);

                // pthread_join( thread1, NULL);
                // pthread_join( thread2, NULL); 

                exit(EXIT_SUCCESS);
                while (fscanf(f,"%s",buffer) != EOF)
                {
                    printf("%s\n",buffer);
                    const char s[2] = ":";
                    char *per;
                    per = strtok(buffer, s);
                    char apa[maxi];
                    char cobacek[maxi];
                    strcpy(apa,per);
                    while(per != NULL ) 
                    {
                        printf( " %s\n", per );
                        per = strtok(NULL, s);
                        if (strlen(cobacek) == 0)
                            strcpy(cobacek,per);
                    }
                    if (strcmp(apa,login.id) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }   
                fclose(f);
                if (flag == 1)
                {
                    strcpy(pesan,"user sudah ada!!!");
                    if (tmp = send(new_socket, (void*)&pesan,strlen(pesan),0) < 0)
                    {
                        perror("Register");
                        exit(EXIT_FAILURE);
                    }
                    // pthread_t thread1, thread2;//inisialisasi awal
                    // const char *message1 = "Thread 1";
                    // const char *message2 = "Thread 2";
                    // int  iret1, iret2;

                    // iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1); //membuat thread pertama
                    // if(iret1) //jika eror
                    // {
                    //     fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
                    //     exit(EXIT_FAILURE);
                    // }

                    // iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);//membuat thread kedua
                    // if(iret2)//jika gagal
                    // {
                    //     fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
                    //     exit(EXIT_FAILURE);
                    // }

                    // printf("pthread_create() for thread 1 returns: %d\n",iret1);
                    // printf("pthread_create() for thread 2 returns: %d\n",iret2);

                    // // pthread_join( thread1, NULL);
                    // // pthread_join( thread2, NULL); 

                    // exit(EXIT_SUCCESS);
                }
                else
                {
                    // char *message;
                    // message = (char *) ptr;
                    //printf("%s \n", message);

                    for(int i=0;i<10;i++){
                        //printf("%s %d \n", message, i);
                    }
                    f = fopen("akun.txt","a");
                    strcpy(pesan,"User Registered!");
                    if (tmp = send(new_socket, (void*)&pesan,strlen(pesan),0) < 0)
                    {
                        perror("Register");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(f,"%s:%s\n",login.id,login.password);
                    fclose(f);
                }
                continue;
            }
        }
    }
	return 0;
}
