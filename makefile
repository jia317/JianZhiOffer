Getstatus:Getstatus.c
	gcc $^ -o $@

waitIsHang:waitIsHang.c
	gcc $^ -o $@

waitpid_nohang:waitpid_nohang.c
	gcc $^ -o $@

waitpid_hang:waitpid_hang.c
	gcc $^ -o $@

wait1:wait_test1.c
	gcc $^ -o $@

wait:wait_test.c
	gcc $^ -o $@

