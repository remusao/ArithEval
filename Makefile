all:
	@make -C src/	| grep -v make

clean:
	@make -C src/ clean | grep -v make

distclean:
	@make -C src/ distclean | grep -v make
