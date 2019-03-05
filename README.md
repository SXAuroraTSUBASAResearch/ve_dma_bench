```
% ./mkshm.x86
% ./bench.ve
% ipcrm -M 0x19761215
```

```
Initialize:    3.517 ms
read          4096 bytes     4.00 KB    0.078 ms    0.052 GB/s (min    0.043 GB/s max    0.054 GB/s)
read         32768 bytes    32.00 KB    0.080 ms    0.411 GB/s (min    0.393 GB/s max    0.415 GB/s)
read        131072 bytes   128.00 KB    0.097 ms    1.346 GB/s (min    0.807 GB/s max    1.486 GB/s)
read        262144 bytes   256.00 KB    0.101 ms    2.607 GB/s (min    2.522 GB/s max    2.637 GB/s)
read        524288 bytes   512.00 KB    0.125 ms    4.209 GB/s (min    4.013 GB/s max    4.295 GB/s)
read        786432 bytes   768.00 KB    0.148 ms    5.301 GB/s (min    4.938 GB/s max    5.381 GB/s)
read       1048576 bytes     1.00 MB    0.172 ms    6.098 GB/s (min    5.992 GB/s max    6.168 GB/s)
read       1572864 bytes     1.50 MB    0.217 ms    7.232 GB/s (min    7.109 GB/s max    7.290 GB/s)
read       2097152 bytes     2.00 MB    0.264 ms    7.947 GB/s (min    7.649 GB/s max    8.004 GB/s)
read       3145728 bytes     3.00 MB    0.357 ms    8.805 GB/s (min    8.675 GB/s max    8.885 GB/s)
read       4194304 bytes     4.00 MB    0.449 ms    9.351 GB/s (min    9.240 GB/s max    9.403 GB/s)
read       5242880 bytes     5.00 MB    0.541 ms    9.688 GB/s (min    9.557 GB/s max    9.752 GB/s)
read       6291456 bytes     6.00 MB    0.633 ms    9.932 GB/s (min    9.898 GB/s max    9.980 GB/s)
read       7340032 bytes     7.00 MB    0.727 ms   10.102 GB/s (min   10.022 GB/s max   10.147 GB/s)
read       8388608 bytes     8.00 MB    0.819 ms   10.238 GB/s (min   10.187 GB/s max   10.291 GB/s)
read       9437184 bytes     9.00 MB    0.912 ms   10.349 GB/s (min   10.220 GB/s max   10.395 GB/s)
read      10485760 bytes    10.00 MB    1.004 ms   10.443 GB/s (min   10.397 GB/s max   10.477 GB/s)
read      16777216 bytes    16.00 MB    1.558 ms   10.767 GB/s (min   10.737 GB/s max   10.778 GB/s)
read      33554432 bytes    32.00 MB    3.038 ms   11.044 GB/s (min   11.023 GB/s max   11.063 GB/s)
read      67108864 bytes    64.00 MB    5.997 ms   11.190 GB/s (min   11.134 GB/s max   11.212 GB/s)
write         4096 bytes     4.00 KB    0.078 ms    0.052 GB/s (min    0.049 GB/s max    0.054 GB/s)
write        32768 bytes    32.00 KB    0.079 ms    0.414 GB/s (min    0.394 GB/s max    0.423 GB/s)
write       131072 bytes   128.00 KB    0.088 ms    1.483 GB/s (min    1.447 GB/s max    1.494 GB/s)
write       262144 bytes   256.00 KB    0.099 ms    2.660 GB/s (min    2.575 GB/s max    2.708 GB/s)
write       524288 bytes   512.00 KB    0.122 ms    4.302 GB/s (min    3.991 GB/s max    4.407 GB/s)
write       786432 bytes   768.00 KB    0.145 ms    5.441 GB/s (min    5.146 GB/s max    5.581 GB/s)
write      1048576 bytes     1.00 MB    0.165 ms    6.374 GB/s (min    6.203 GB/s max    6.449 GB/s)
write      1572864 bytes     1.50 MB    0.208 ms    7.551 GB/s (min    7.421 GB/s max    7.609 GB/s)
write      2097152 bytes     2.00 MB    0.253 ms    8.299 GB/s (min    8.040 GB/s max    8.369 GB/s)
write      3145728 bytes     3.00 MB    0.342 ms    9.203 GB/s (min    8.988 GB/s max    9.298 GB/s)
write      4194304 bytes     4.00 MB    0.431 ms    9.726 GB/s (min    9.428 GB/s max    9.828 GB/s)
write      5242880 bytes     5.00 MB    0.518 ms   10.115 GB/s (min    9.941 GB/s max   10.209 GB/s)
write      6291456 bytes     6.00 MB    0.605 ms   10.405 GB/s (min   10.369 GB/s max   10.463 GB/s)
write      7340032 bytes     7.00 MB    0.695 ms   10.565 GB/s (min   10.436 GB/s max   10.631 GB/s)
write      8388608 bytes     8.00 MB    0.780 ms   10.754 GB/s (min   10.727 GB/s max   10.789 GB/s)
write      9437184 bytes     9.00 MB    0.871 ms   10.836 GB/s (min   10.744 GB/s max   10.880 GB/s)
write     10485760 bytes    10.00 MB    0.960 ms   10.925 GB/s (min   10.806 GB/s max   10.968 GB/s)
write     16777216 bytes    16.00 MB    1.487 ms   11.279 GB/s (min   11.152 GB/s max   11.322 GB/s)
write     33554432 bytes    32.00 MB    2.895 ms   11.589 GB/s (min   11.557 GB/s max   11.607 GB/s)
write     67108864 bytes    64.00 MB    5.700 ms   11.774 GB/s (min   11.761 GB/s max   11.783 GB/s)
```
