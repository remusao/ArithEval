all:
	@make -C src/	| grep -v make

clean:
	@find . -name "*.o" -delete

distclean:
	@make -C src/ distclean | grep -v make
