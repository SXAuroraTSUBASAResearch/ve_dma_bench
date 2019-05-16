#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char* argv[])
{
    int key = 0x19761215;

    size_t size = 256 * 1024 * 1024;
    int shmid = shmget(key, size, IPC_CREAT | IPC_EXCL | SHM_HUGETLB | 0600);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    fprintf(stderr, "Created shm with key=%x\n", key);

    return 0;
}
