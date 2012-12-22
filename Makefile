FILES=CMakeLists.txt AUTHORS ChangeLog Makefile configure README TODO src/ test/ doc/
TARBALL=berson_r-42SH.tar.bz2

ERROR="<It seems that the build/ directory is missing\nMaybe you forgot to execute the configure ?>"

.PHONY: test doc


all:
	@echo -e "\033[33m< ---------- >\033[37m"
	@echo -e "\033[33m< Generating >\033[37m"
	@echo -e "\033[33m< ---------- >\033[37m"
	@if [ -e build/ ] ; then make -C build/; fi
	@echo -e "\033[34m"
	@if [ ! -e build/ ] ; then echo -e $(ERROR) ; fi
	@echo -e "\033[37m"

clean:
	@echo -e "\033[33m< -------- >\033[37m"
	@echo -e "\033[33m< Cleaning >\033[37m"
	@echo -e "\033[33m< -------- >\033[37m"
	@if [ -e build/ ] ; then make -C build/ clean ; fi 1>/dev/null

distclean: clean
	@echo -e "\033[34m< Preparing directory for dist >\033[37m"
	@if [ -e bistro ] ; then rm -fr bistro ; fi 1>/dev/null
	@if [ -e build/ ] ; then rm -fr build/ ; fi 1>/dev/null
	@if test -e $(TARBALL) ; then rm -fr $(TARBALL) ; fi 1>/dev/null

check:
	@echo -e "\033[33m< -------------------- >\033[37m"
	@echo -e "\033[33m< Launching test_suite >\033[37m"
	@echo -e "\033[33m< -------------------- >\033[37m"
	@echo -e "\033[34m- Generating Makefile\033[37m"
	@bash configure 	1>/dev/null 2>/dev/null
	@echo -e "\033[34m- Building project\033[37m"
	@make 			1>/dev/null 2>/dev/null
	@echo -e "\033[34m- launching test script ..\033[37m"
	@make -C test/rep_test/	| grep -v make
	@make distclean		1>/dev/null 2>/dev/null

doc:
	@make -C doc/	| grep -v make

dist: distclean
	@mkdir berson_r
	@cp -r $(FILES) berson_r/
	@tar cjvf $(TARBALL) berson_r/
	@rm -fr berson_r

distcheck: dist
	@tar -xjvf $(TARBALL)
	@make -C berson_r/ check
	@make distclean
	@rm -fr berson_r
