produce_test_files() {
	make -s
}

execute_test_files() {
	for f in targets/* ; do
		echo "$f"
		leaks -q --atExit -- ./$f
	done
}

produce_test_files
execute_test_files 2>&1 \
| grep -v -e ":PASS" -e "------" -e "OK" -e "^$" -e "0 Failures 0 Ignored" \
| grep -v -e "0 leaks for 0 total leaked bytes." \
| grep -v -e "is not debuggable. Due to security restrictions," \
| grep -v -e "leaks Report Version: 4.0" \
| grep -v -e "nodes malloced for"
