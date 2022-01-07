#include "brainfuckState.hpp"
#include "codegenState.hpp"

using namespace llvm;

namespace cbf {

static auto iType = Type::getInt32Ty(CodegenState{}.context);
static auto iNullVal = ConstantAggregateZero::get(iType);

static auto cpuType = ArrayType::get(Type::getInt8Ty(CodegenState{}.context), 30000);
static auto cpuNullVal = ConstantAggregateZero::get(cpuType);

GlobalVariable BrainfuckState::i(
	iType, false, GlobalValue::LinkageTypes::InternalLinkage,
	nullptr, "i"
);
GlobalVariable BrainfuckState::cpu(
	cpuType, false, GlobalValue::LinkageTypes::InternalLinkage,
	nullptr, "cpu"
);

BrainfuckState::BrainfuckState() {
	i.setInitializer(iNullVal);
	cpu.setInitializer(cpuNullVal);
}

}
