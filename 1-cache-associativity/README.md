Finding out cache associativity
-------------------------------

```
$ FRAGMENT=16777216 ./benchmark
+ gcc main.c -O0 -Wno-unused-value
+ ./a.out
[1;32m[BENCHMARK][0m Fragment size: 16777216 bytes
[1;32m[BENCHMARK][0m Buffer has been allocated with 1073741824 bytes
[1;32m[BENCHMARK][0m Cache has been warmed up.
[1;32m[BENCHMARK][0m # fragments = 1	access (ns) = 2.259076	elapsed (ns) = 37901000
[1;32m[BENCHMARK][0m # fragments = 2	access (ns) = 1.723856	elapsed (ns) = 57843000
[1;32m[BENCHMARK][0m # fragments = 3	access (ns) = 1.322925	elapsed (ns) = 66585000
[1;32m[BENCHMARK][0m # fragments = 4	access (ns) = 1.507685	elapsed (ns) = 101179000
[1;32m[BENCHMARK][0m # fragments = 5	access (ns) = 1.419294	elapsed (ns) = 119059000
[1;32m[BENCHMARK][0m # fragments = 6	access (ns) = 1.335194	elapsed (ns) = 134405000
[1;32m[BENCHMARK][0m # fragments = 7	access (ns) = 1.318855	elapsed (ns) = 154887000
[1;32m[BENCHMARK][0m # fragments = 8	access (ns) = 1.241975	elapsed (ns) = 166695000
[1;32m[BENCHMARK][0m # fragments = 9	access (ns) = 1.304898	elapsed (ns) = 197033000
[1;32m[BENCHMARK][0m # fragments = 10	access (ns) = 1.254398	elapsed (ns) = 210453000
[1;32m[BENCHMARK][0m # fragments = 11	access (ns) = 1.290798	elapsed (ns) = 238216000
[1;32m[BENCHMARK][0m # fragments = 12	access (ns) = 1.289402	elapsed (ns) = 259591000
[1;32m[BENCHMARK][0m # fragments = 13	access (ns) = 1.324594	elapsed (ns) = 288899000
[1;32m[BENCHMARK][0m # fragments = 14	access (ns) = 1.591350	elapsed (ns) = 373778000
[1;32m[BENCHMARK][0m # fragments = 15	access (ns) = 1.477615	elapsed (ns) = 371854000
[1;32m[BENCHMARK][0m # fragments = 16	access (ns) = 1.480445	elapsed (ns) = 397404000
[1;32m[BENCHMARK][0m # fragments = 17	access (ns) = 1.437966	elapsed (ns) = 410126000
[1;32m[BENCHMARK][0m # fragments = 18	access (ns) = 1.619356	elapsed (ns) = 489029000
[1;32m[BENCHMARK][0m # fragments = 19	access (ns) = 1.630887	elapsed (ns) = 519873000
[1;32m[BENCHMARK][0m # fragments = 20	access (ns) = 1.507375	elapsed (ns) = 505791000
[1;32m[BENCHMARK][0m # fragments = 21	access (ns) = 1.462426	elapsed (ns) = 515244000
[1;32m[BENCHMARK][0m # fragments = 22	access (ns) = 1.493083	elapsed (ns) = 551095000
[1;32m[BENCHMARK][0m # fragments = 23	access (ns) = 1.517436	elapsed (ns) = 585542000
[1;32m[BENCHMARK][0m # fragments = 24	access (ns) = 1.482020	elapsed (ns) = 596740000
[1;32m[BENCHMARK][0m # fragments = 25	access (ns) = 1.516633	elapsed (ns) = 636122000
[1;32m[BENCHMARK][0m # fragments = 26	access (ns) = 1.499875	elapsed (ns) = 654257000
[1;32m[BENCHMARK][0m # fragments = 27	access (ns) = 1.562962	elapsed (ns) = 707998000
[1;32m[BENCHMARK][0m # fragments = 28	access (ns) = 1.614351	elapsed (ns) = 758361000
[1;32m[BENCHMARK][0m # fragments = 29	access (ns) = 1.795545	elapsed (ns) = 873603000
[1;32m[BENCHMARK][0m # fragments = 30	access (ns) = 1.771853	elapsed (ns) = 891803000
[1;32m[BENCHMARK][0m # fragments = 31	access (ns) = 1.819563	elapsed (ns) = 946343000
[1;32m[BENCHMARK][0m # fragments = 32	access (ns) = 2.579607	elapsed (ns) = 1384916000
```
