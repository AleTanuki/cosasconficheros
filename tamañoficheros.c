#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc ,char*argv[]) {
    //setear como obligatorio el 1º parametro
    char *fichero1,*fichero2,*fichero3;
    int i,fd1,fd2,fd3,longi1,longi2,longi3;

    if (argc >= 3)//comprobamos el numero de argumentos pasados por parametro
    {
        if (argc <=4) //guardamos en variables los datos
        {
            fichero1= argv[1];
            fichero2= argv[2];
            fichero3 = argv[3];
        } else {
            fprintf(stderr, "error,demasiados argumentos\n");
            return 1;
        }
    } else {
        fprintf(stderr, "error,faltan argumentos\n");
        return 2;
    }
    fd1= open(fichero1,0);
    fd2= open(fichero2,0);
    fd3 = open(fichero3,0);
    if((fd1==-1 )|| (fd2==-1)|| (fd3==-1)){
        perror("error con los ficheros");
        return 0;
    }
    longi1= lseek(fd1,0,SEEK_END);
    longi2= lseek(fd2,0,SEEK_END);
    longi3= lseek(fd3,0,SEEK_END);
    if((longi1==-1)||(longi2==-1)||(longi3==-1)){
        fprintf(stderr,"algun fichero no se puede ver su tamaño");
        return 0;
    }
    close(fd1);
    close(fd2);
    close(fd3);

    printf("El fichero %s pesa %d bytes\n",argv[1],longi1);
    printf("El fichero %s pesa %d bytes\n",argv[2],longi2);
    printf("El fichero %s pesa %d bytes\n",argv[3],longi3);


    return 0;
}

