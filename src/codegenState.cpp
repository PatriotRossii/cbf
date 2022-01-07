#include "codegenState.hpp"

#include <memory>

using namespace llvm;

namespace cbf {

LLVMContext CodegenState::context;
IRBuilder<> CodegenState::builder(context);
std::unique_ptr<Module> CodegenState::module = std::make_unique<Module>("module", context);

}
