#include <stdio.h>
#include <stdlib.h>
#include <vedma.h>
#include <vhshm.h>

#include <time.h>

double second() {
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    return t.tv_sec + t.tv_nsec * 1e-9;
}

int main(int argc, char* argv[])
{
    double ti0 = second();

    int key = 0x19761215;
    size_t size = 256 * 1024 * 1024;
    size_t align = 64 * 1024 * 1024;

    // Attach shm on VH to VE
    int shmid = vh_shmget(key, size, SHM_HUGETLB);
    if (shmid == -1) {
        perror("vh_shmget");
        return 1;
    }

#ifdef DEBUG
    fprintf(stderr, "shmid=%d\n", shmid);
#endif

    void* vehva_vh = NULL;
    void* p = vh_shmat(shmid, NULL, 0, &vehva_vh);
    if (p == (void*)-1) {
        perror("vh_shmat");
        return 1;
    }
#ifdef DEBUG
    fprintf(stderr, "vehva_vh=%p\n", vehva_vh);
#endif

    if (ve_dma_init() != 0) {
        perror("ve_dma_init");
        return 1;
    }

    void* vemva;
    if (posix_memalign(&vemva, align, size) != 0) {
        perror("posix_memalign");
        return 1;
    }
#ifdef DEBUG
    fprintf(stderr, "vemva=%p\n", vemva);
#endif
    uint64_t vehva_ve = ve_register_mem_to_dmaatb(vemva, size);
    if (vehva_ve == (uint64_t)-1) {
        perror("ve_register_mem_to_dmaatb");
        return 1;
    }
#ifdef DEBUG
    fprintf(stderr, "vehva_ve=%p\n", vehva_ve);
    fprintf(stderr, "p=%p\n", p);
#endif

    double ti1 = second();

    fprintf(stdout, "Initialize: %8.3lf ms\n", (ti1 - ti0) * 1e3);

    size_t ary[] = { 
        4 * 1024,
        32 * 1024,
        128 * 1024,
        256 * 1024,
        512 * 1024,
        768 * 1024,
        1 * 1024 * 1024,
        1.5 * 1024 * 1024,
        2 * 1024 * 1024,
        3 * 1024 * 1024,
        4 * 1024 * 1024,
        5 * 1024 * 1024,
        6 * 1024 * 1024,
        7 * 1024 * 1024,
        8 * 1024 * 1024,
        9 * 1024 * 1024,
        10 * 1024 * 1024,
        16 * 1024 * 1024,
        32 * 1024 * 1024,
        64 * 1024 * 1024,
    };

    int n = 10;

    // read
    for (size_t i = 0; i < sizeof(ary) / sizeof(size_t); ++i) {
        size_t transfer_size = ary[i];

        double min = 1e9;
        double max = 0.0;
        double sum = 0.0;

        for (int j = 0; j < n; ++j) {
            double t0 = second();
            int ret = ve_dma_post_wait(vehva_ve, (uint64_t)vehva_vh, transfer_size);
            if (ret != 0) {
                perror("ve_dma_post_wait");
                return 1;
            }
            double t1 = second();
            double e = t1 - t0;

            min = min < e ? min : e;
            max = max < e ? e : max;
            sum += e;
        }

        double ave = sum / n;
        double sz = transfer_size * 1.0;

        fprintf(stdout, "read  %12d bytes %8.2f %s %8.3lf ms %8.3lf GB/s (min %8.3lf GB/s max %8.3lf GB/s)\n",
                transfer_size, 
                sz >= 1024 * 1024 ? sz * 1.0 / 1024 / 1024 : sz * 1.0 / 1024,
                sz >= 1024 * 1024 ? "MB" : "KB",
                ave * 1e3, 
                sz / ave / 1e9,
                sz / max / 1e9,
                sz / min / 1e9);
    }

    // write
    for (size_t i = 0; i < sizeof(ary) / sizeof(size_t); ++i) {
        size_t transfer_size = ary[i];

        double min = 1e9;
        double max = 0.0;
        double sum = 0.0;

        for (int j = 0; j < n; ++j) {
            double t0 = second();
            int ret = ve_dma_post_wait((uint64_t)vehva_vh, vehva_ve, transfer_size);
            if (ret != 0) {
                perror("ve_dma_post_wait");
                return 1;
            }
            double t1 = second();
            double e = t1 - t0;

            min = min < e ? min : e;
            max = max < e ? e : max;
            sum += e;
        }

        double ave = sum / n;
        double sz = transfer_size * 1.0;

        fprintf(stdout, "write %12d bytes %8.2f %s %8.3lf ms %8.3lf GB/s (min %8.3lf GB/s max %8.3lf GB/s)\n",
                transfer_size, 
                sz >= 1024 * 1024 ? sz * 1.0 / 1024 / 1024 : sz * 1.0 / 1024,
                sz >= 1024 * 1024 ? "MB" : "KB",
                ave * 1e3, 
                sz / ave / 1e9,
                sz / max / 1e9,
                sz / min / 1e9);
    }

    vh_shmdt(p);
    ve_unregister_mem_from_dmaatb(vehva_ve);

    return 0;
}
