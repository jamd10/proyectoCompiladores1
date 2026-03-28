CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC = src
BUILD = build
TARGET = rust_parser.exe

all: dirs $(TARGET)

dirs:
	mkdir -p $(BUILD)

$(BUILD)/parser.tab.c $(BUILD)/parser.tab.h: $(SRC)/parser.y $(SRC)/ast.hpp $(SRC)/analysis.hpp
	bison -d -o $(BUILD)/parser.tab.c $(SRC)/parser.y

$(BUILD)/lex.yy.c: $(SRC)/lexer.l $(BUILD)/parser.tab.h $(SRC)/analysis.hpp
	flex -o $(BUILD)/lex.yy.c $(SRC)/lexer.l

$(TARGET): $(BUILD)/parser.tab.c $(BUILD)/lex.yy.c $(SRC)/main.cpp $(SRC)/analysis.cpp $(SRC)/analysis.hpp $(SRC)/ast.hpp
	$(CXX) $(CXXFLAGS) -I$(BUILD) -I$(SRC) $(BUILD)/parser.tab.c $(BUILD)/lex.yy.c $(SRC)/analysis.cpp $(SRC)/main.cpp -o $(TARGET)

clean:
	rm -rf $(BUILD) $(TARGET)

.PHONY: all clean dirs
