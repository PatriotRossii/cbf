#include "ast/advanceCellNode.hpp"

#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instruction.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"

#include "brainfuckState.hpp"
#include "codegenState.hpp"

namespace cbf {

AdvanceCellNode::AdvanceCellNode(size_t distance): distance(distance) { }

llvm::Value* AdvanceCellNode::codegen() {
	return llvm::BinaryOperator::Create(
		llvm::Instruction::BinaryOps::Add,
		&BrainfuckState{}.i, llvm::ConstantInt::get(llvm::Type::getInt32Ty(CodegenState{}.context), distance, true)
	);
}

}