#pragma once

#include "llvm/IR/Value.h"

namespace cbf {

class ASTNode {
public:
	virtual llvm::Value* codegen() = 0;
};

}