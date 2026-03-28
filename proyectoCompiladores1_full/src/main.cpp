#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "analysis.hpp"
#include "ast.hpp"

extern int yyparse();
extern int yylex();
extern FILE* yyin;
extern int yylineno;
extern void yyrestart(FILE*);

static bool openInputFile(const std::string& path, FILE*& fileHandle) {
    fileHandle = fopen(path.c_str(), "r");
    return fileHandle != nullptr;
}

static int parseFile(FILE* input, bool captureTokens) {
    resetAnalysis();
    g_captureTokens = captureTokens;
    yyrestart(input);
    yylineno = 1;

    const int parseResult = yyparse();
    return parseResult;
}

static int tokenizeFile(FILE* input) {
    resetAnalysis();
    g_captureTokens = true;
    yyrestart(input);
    yylineno = 1;

    while (yylex() != 0) {
    }

    return 0;
}

static void printUsage() {
    std::cout
        << "Usage:\n"
        << "  rust_parser.exe < file.rs\n"
        << "  rust_parser.exe --parse <file>\n"
        << "  rust_parser.exe --tokens <file>\n"
        << "  rust_parser.exe --ast <file>\n"
        << "  rust_parser.exe --all <file>\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        resetAnalysis();
        g_captureTokens = true;
        yyrestart(stdin);
        yylineno = 1;

        std::cout << "Running parser..." << std::endl;
        const int result = yyparse();

        if (result == 0) {
            std::cout << "Parse OK" << std::endl;
        } else {
            if (!g_lastError.empty()) {
                std::cout << g_lastError << std::endl;
            }
            std::cout << "Parse FAILED" << std::endl;
        }
        return result;
    }

    const std::string mode = argv[1];

    if (mode == "--help" || mode == "-h") {
        printUsage();
        return 0;
    }

    if (argc < 3) {
        printUsage();
        return 1;
    }

    const std::string inputPath = argv[2];
    FILE* input = nullptr;

    if (!openInputFile(inputPath, input)) {
        std::cerr << "Could not open file: " << inputPath << std::endl;
        return 1;
    }

    int exitCode = 0;

    if (mode == "--tokens") {
        tokenizeFile(input);
        std::cout << tokensToString();
    } else if (mode == "--parse") {
        std::cout << "Running parser..." << std::endl;
        const int result = parseFile(input, false);
        if (result == 0) {
            std::cout << "Parse OK" << std::endl;
        } else {
            std::cout << g_lastError << std::endl;
            std::cout << "Parse FAILED" << std::endl;
        }
        exitCode = result;
    } else if (mode == "--ast") {
        std::cout << "Running parser..." << std::endl;
        const int result = parseFile(input, false);
        if (result == 0) {
            std::cout << "Parse OK" << std::endl;
            std::cout << "\nABSTRACT SYNTAX TREE\n";
            std::cout << "==============================\n";
            std::cout << astToString(g_astRoot);
        } else {
            std::cout << g_lastError << std::endl;
            std::cout << "Parse FAILED" << std::endl;
        }
        exitCode = result;
    } else if (mode == "--all") {
        tokenizeFile(input);
        std::cout << tokensToString() << "\n";
        fclose(input);

        if (!openInputFile(inputPath, input)) {
            std::cerr << "Could not reopen file: " << inputPath << std::endl;
            return 1;
        }

        std::cout << "PARSER RESULT\n";
        std::cout << "==============================\n";
        const int result = parseFile(input, false);

        if (result == 0) {
            std::cout << "Parse OK\n\n";
            std::cout << "ABSTRACT SYNTAX TREE\n";
            std::cout << "==============================\n";
            std::cout << astToString(g_astRoot);
        } else {
            std::cout << g_lastError << "\n";
            std::cout << "Parse FAILED\n";
        }

        exitCode = result;
    } else {
        printUsage();
        fclose(input);
        return 1;
    }

    fclose(input);
    return exitCode;
}
