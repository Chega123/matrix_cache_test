# matrix_cache_test  
g++ -g cache_matrix.cpp -o cache.exe  
valgrind --tool=cachegrind ./cache.exe  
kcachegrind cachegrind.out."numero del archivo"  
