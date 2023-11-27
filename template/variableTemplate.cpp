#include <iostream>
#include <type_traits>

template<typename T>
constexpr auto pi = (T)3.14159265359;

template<typename T>
struct isLValueRef : std::false_type
{};
template<typename T>
struct isLValueRef<T&> : std::true_type
{};
template<typename T>
constexpr bool isLValueRef_v = isLValueRef<T>::value;

template<typename T>
void foo(T x)
{
	static_assert(!std::is_pointer_v<T>, "does not accept pointer.");
}


int main()
{
	constexpr auto x = pi<double>;
	int arr[pi<int>]{};
	constexpr auto val = isLValueRef_v<bool>;
	//foo(arr);
}
