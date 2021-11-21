produce_test_files() {
	make -s
}

execute_test_files() {
	for f in targets/* ; do
		echo "$f"
		./$f
	done
}

produce_test_files
execute_test_files | grep -v -e ":PASS" -e "------" -e "OK" -e "^$" -e "0 Failures 0 Ignored"
