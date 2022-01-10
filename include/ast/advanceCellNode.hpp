#pragma once

#include "astNode.hpp"

namespace cbf {

class AdvanceCellNode: public ASTNode {
	size_t distance;
public:
	AdvanceCellNode(size_t distance);
	llvm::Value* codegen() override;
};

}