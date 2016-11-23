


#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>


int main() {

    int segment_id, segment_id2;
    char *shared_memory;
    char *shared_memories;
    struct shmid_ds shmbuffer;//-->Estructura shmid_ds
    int segment_size;
    const int shared_segment_size = 0x6400;
    
    //Asignar un segmento de memoria a un proceso:
    //shmget()-->SHared_Memory_Get....Devuelve un segment_id
    segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    segment_id2 = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    //Hacer disponible un segmento para un proceso
    //shmat()-->SHared_Memory_Attach..Devuelve una direccion de memoria
    //shmat(1,2,3)-->parametros
    //1.-Identificador segmento de memoria
    //2.-Apunta a la direccion donde voy a mapear el shared segment--si es 0 coge su misma direccion
    //3.-FLAGS
    shared_memory = (char*) shmat(segment_id ,0 ,0);
    printf ("shared memory attachd at address %p\n", shared_memory);

    //Devolver info sobre, y puede modificar un shared segment
    //IPC_STAT-->como argumento, para obtener info del shared segment
    shmctl(segment_id, IPC_STAT, &shmbuffer);
    //de la estructura shmbuffer, el campo shm_segsz es el tamaño del segmento en bytes
    segment_size = shmbuffer.shm_segsz;
    //Mostrar tamaño del segmento
    printf("segment size %d\n", segment_size);
    //Escribir "Hello, Pold" en el shared segment
    sprintf(shared_memory, "Hello, Pold");
    //shmdt()-->SHared_Memory_DEtach
    shmdt(shared_memory);
    
    shared_memories = (char*)shmat (segment_id, 0,0 );
    printf ("shared memory reattachd at address %p\n", shared_memories);
    
    printf("%s\n", shared_memories);
    
    shmdt(shared_memories);
    
    shmctl(segment_id, IPC_RMID, 0 );
    
    return 0;
}
