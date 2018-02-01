.PHONY: fmt

fmt:
	@clang-format -style=file -i $(wildcard *.c) $(wildcard *.h)

