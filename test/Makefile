helpers : test_lines.c test_lines.c randomTest.c checksumTest.c ../helpers.c 
	gcc -std=gnu99 -I ../include ../helpers.c sub_test.c -g -o sub_test
	gcc -std=gnu99 -I ../include ../helpers.c test_lines.c -g -o test_lines
	gcc -std=gnu99 -I ../include ../helpers.c randomTest.c -g -o randomTest
	gcc -std=gnu99 -I ../include ../helpers.c checksumTest.c -g -o checksumTest
	
clean :
	rm sub_test
	rm test_lines
	rm randomTest
	rm checksumTest