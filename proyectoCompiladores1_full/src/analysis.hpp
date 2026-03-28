#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ast.hpp"

struct TokenInfo {
    std::string type;
    std::string lexeme;
    int line;
};

extern bool g_captureTokens;
extern std::vector<TokenInfo> g_tokens;
extern std::shared_ptr<ASTNode> g_astRoot;
extern std::string g_lastError;

void resetAnalysis();
void addToken(const std::string& type, const std::string& lexeme, int line);
std::string escapeForDisplay(const std::string& value);
std::string tokensToString();
