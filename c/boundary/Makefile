all: test pack

test: main.cc
	g++ -o $@ $^

pack: pack.cc
	g++ -o $@ $^

.PHONY:clean
clean:
	@rm test pack
