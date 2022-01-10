#pragma once

#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"

namespace cbf {

constexpr int CPU_SIZE = 30000;

struct BrainfuckState {
	static llvm::GlobalVariable i;
	static llvm::GlobalVariable cpu;
	BrainfuckState();
};

}