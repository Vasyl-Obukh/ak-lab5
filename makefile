OUT ?= target

compile:
	mkdir -p $(OUT)
	g++ -o $(OUT)/main parcer.cpp

run:
	./$(OUT)/main -h

clean:
	rm -rf $(OUT)