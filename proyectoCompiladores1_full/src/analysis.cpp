#include "analysis.hpp"

#include <sstream>

bool g_captureTokens = false;
std::vector<TokenInfo> g_tokens;
std::shared_ptr<ASTNode> g_astRoot;
std::string g_lastError;

void resetAnalysis() {
    g_tokens.clear();
    g_astRoot.reset();
    g_lastError.clear();
}

void addToken(const std::string& type, const std::string& lexeme, int line) {
    if (g_captureTokens) {
        g_tokens.push_back({type, lexeme, line});
    }
}

std::string escapeForDisplay(const std::string& value) {
    std::string result;
    result.reserve(value.size());

    for (char ch : value) {
        switch (ch) {
            case '\n': result += "\\n"; break;
            case '\t': result += "\\t"; break;
            case '\r': result += "\\r"; break;
            default: result += ch; break;
        }
    }

    return result;
}

std::string tokensToString() {
    std::ostringstream out;
    out << "TOKENS DETECTED\n";
    out << "==============================\n";

    if (g_tokens.empty()) {
        out << "(no tokens)\n";
        return out.str();
    }

    for (const auto& token : g_tokens) {
        out << "Line " << token.line << " | "
            << token.type << " | "
            << escapeForDisplay(token.lexeme) << "\n";
    }

    return out.str();
}
