/**
 * Triggers ICE(segmentation fault) on x86-64 clang 11.0 with flag "-std=c++17 -O3".
 * No bug when compiled with opt level "-O2".
 * https://godbolt.org/z/8az9zC
 * The bug is introduced in x86-64 clang 5.0.0 (the patch which clang first support c++17 standard).
 */

#include <variant>

template <typename T>
struct type_tag {
  using type = T;
};

template <typename... PossibleTypeTs>
auto unwrap(std::variant<type_tag<PossibleTypeTs>...> ts)
    -> std::variant<PossibleTypeTs...> {};

int main() {
  std::variant<type_tag<int>, type_tag<unsigned int>> wrapped_variant =
      type_tag<int>{};

  return std::visit(
      [&](auto &&arg) -> decltype(unwrap(wrapped_variant)) {
        using T = std::decay_t<decltype(arg)>;
        return 0;
      },
      wrapped_variant);
};
