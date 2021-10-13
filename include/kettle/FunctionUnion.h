#ifndef FUNCTIONUNION_H
#define FUNCTIONUNION_H

namespace kettle
{
template<typename... F>
struct FunctionUnion: F ...
{
  using F::operator()...;
};

template<typename... F>
FunctionUnion<F...> function_union(F... f) {
  return FunctionUnion<F...>{f...};
}
}


#endif //FUNCTIONUNION_H
