Finding out cache associativity
-------------------------------

$ FRAGMENT=16777216 ./benchmark
+ gcc main.c -O0 -Wno-unused-value
+ ./a.out
[BENCHMARK] Fragment size: 16777216 bytes
[BENCHMARK] Buffer has been allocated with 1073741824 bytes
[BENCHMARK] Cache has been warmed up.
[BENCHMARK] # fragments = 1    access (ns) = 2.329886    elapsed (ns) = 39089000
[BENCHMARK] # fragments = 2    access (ns) = 1.650333    elapsed (ns) = 55376000
[BENCHMARK] # fragments = 3    access (ns) = 1.451592    elapsed (ns) = 73061000
[BENCHMARK] # fragments = 4    access (ns) = 1.625672    elapsed (ns) = 109097000
[BENCHMARK] # fragments = 5    access (ns) = 1.544440    elapsed (ns) = 129557000
[BENCHMARK] # fragments = 6    access (ns) = 1.389235    elapsed (ns) = 139845000
[BENCHMARK] # fragments = 7    access (ns) = 1.373563    elapsed (ns) = 161312000
[BENCHMARK] # fragments = 8    access (ns) = 1.348183    elapsed (ns) = 180950000
[BENCHMARK] # fragments = 9    access (ns) = 1.364569    elapsed (ns) = 206043000
[BENCHMARK] # fragments = 10    access (ns) = 1.304942    elapsed (ns) = 218933000
[BENCHMARK] # fragments = 11    access (ns) = 1.292256    elapsed (ns) = 238485000
[BENCHMARK] # fragments = 12    access (ns) = 1.315574    elapsed (ns) = 264860000
[BENCHMARK] # fragments = 13    access (ns) = 1.416940    elapsed (ns) = 309040000
[BENCHMARK] # fragments = 14    access (ns) = 1.409365    elapsed (ns) = 331033000
[BENCHMARK] # fragments = 15    access (ns) = 1.454278    elapsed (ns) = 365981000
[BENCHMARK] # fragments = 16    access (ns) = 1.456425    elapsed (ns) = 390956000
[BENCHMARK] # fragments = 17    access (ns) = 1.440693    elapsed (ns) = 410904000
[BENCHMARK] # fragments = 18    access (ns) = 1.541922    elapsed (ns) = 465645000
[BENCHMARK] # fragments = 19    access (ns) = 1.495524    elapsed (ns) = 476724000
[BENCHMARK] # fragments = 20    access (ns) = 1.470298    elapsed (ns) = 493350000
[BENCHMARK] # fragments = 21    access (ns) = 1.477718    elapsed (ns) = 520632000
[BENCHMARK] # fragments = 22    access (ns) = 1.488894    elapsed (ns) = 549549000
[BENCHMARK] # fragments = 23    access (ns) = 1.521593    elapsed (ns) = 587146000
[BENCHMARK] # fragments = 24    access (ns) = 1.566219    elapsed (ns) = 630643000
[BENCHMARK] # fragments = 25    access (ns) = 1.540022    elapsed (ns) = 645932000
[BENCHMARK] # fragments = 26    access (ns) = 1.547570    elapsed (ns) = 675062000
[BENCHMARK] # fragments = 27    access (ns) = 1.798689    elapsed (ns) = 814779000
[BENCHMARK] # fragments = 28    access (ns) = 1.600564    elapsed (ns) = 751884000
[BENCHMARK] # fragments = 29    access (ns) = 1.924994    elapsed (ns) = 936585000
[BENCHMARK] # fragments = 30    access (ns) = 1.683338    elapsed (ns) = 847252000
[BENCHMARK] # fragments = 31    access (ns) = 1.893207    elapsed (ns) = 984645000
[BENCHMARK] # fragments = 32    access (ns) = 2.542429    elapsed (ns) = 1364956000
