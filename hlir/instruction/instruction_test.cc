#include "hlir/instruction/instruction.h"
#include <gtest/gtest.h>

namespace hlir {
namespace instruction {

TEST(Instruction, basic) {
  Shape x_shape({Shape::kDynamicDimValue, 30, 40});
  Shape w_shape({40, 50});

  auto param0 = Instruction::CreateParameter(0, x_shape, "x", {Float(32)});
  auto param1 = Instruction::CreateParameter(1, w_shape, "w0", {Float(32)});

  auto add = Instruction::CreateDot(Shape({Shape::kDynamicDimValue, 30, 50}), param0.get(), param1.get());
  LOG(INFO) << add->to_debug_string();
  ASSERT_TRUE(add);
}

}  // namespace instruction
}  // namespace hlir