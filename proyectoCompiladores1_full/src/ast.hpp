#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <vector>

struct ASTNode {
    std::string label;
    std::vector<std::shared_ptr<ASTNode>> children;

    explicit ASTNode(const std::string& value) : label(value) {}
};

inline std::shared_ptr<ASTNode> makeNode(const std::string& label) {
    return std::make_shared<ASTNode>(label);
}

inline std::shared_ptr<ASTNode> makeNode(
    const std::string& label,
    const std::vector<std::shared_ptr<ASTNode>>& children
) {
    auto node = std::make_shared<ASTNode>(label);
    for (const auto& child : children) {
        if (child) {
            node->children.push_back(child);
        }
    }
    return node;
}

inline void appendChild(const std::shared_ptr<ASTNode>& parent, const std::shared_ptr<ASTNode>& child) {
    if (parent && child) {
        parent->children.push_back(child);
    }
}

inline void astToStringImpl(const std::shared_ptr<ASTNode>& node, std::ostringstream& out, int depth) {
    if (!node) {
        return;
    }

    for (int i = 0; i < depth; ++i) {
        out << "  ";
    }
    out << node->label << "\n";

    for (const auto& child : node->children) {
        astToStringImpl(child, out, depth + 1);
    }
}

inline std::string astToString(const std::shared_ptr<ASTNode>& root) {
    std::ostringstream out;
    if (!root) {
        out << "(no AST generated)\n";
        return out.str();
    }

    astToStringImpl(root, out, 0);
    return out.str();
}
