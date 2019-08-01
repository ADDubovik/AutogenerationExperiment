#include <fstream>
#include <string>
#include <iostream>
#include <type_traits>


template<typename T>
void print()
{
	std::cout << typeid(T).name() << '\n'
		<< "is_copy_constructible: " << std::is_copy_constructible_v<T> << '\n'
		<< "is_move_constructible: " << std::is_move_constructible_v<T> << '\n'
		<< "is_copy_assignable:    " << std::is_copy_assignable_v<T>    << '\n'
		<< "is_move_assignable:    " << std::is_move_assignable_v<T>    << '\n';
}


struct A1
{
	A1() = default;
};

struct A2
{
	A2() {}
};

struct A3
{
	A3() = delete;
};


struct B1
{
	~B1() = default;
};

struct B2
{
	~B2() {}
};

struct B3
{
	~B3() = delete;
};


struct C1
{
	C1(const C1&) = default;
};

struct C2
{
	C2(const C2&) {}
};

struct C3
{
	C3(const C3&) = delete;
};


struct D1
{
	D1(D1&&) = default;
};

struct D2
{
	D2(D2&&) {}
};

struct D3
{
	D3(D3&&) = delete;
};


struct E1
{
	E1& operator=(const E1&) = default;
};

struct E2
{
	E2& operator=(const E2&) {}
};

struct E3
{
	E3& operator=(const E3&) = delete;
};


struct F1
{
	F1& operator=(F1&&) = default;
};

struct F2
{
	F2& operator=(F2&&) {}
};

struct F3
{
	F3& operator=(F3&&) = delete;
};


int main() {
	print<A1>();
	print<A2>();
	print<A3>();

	print<B1>();
	print<B2>();
	print<B3>();

	print<C1>();
	print<C2>();
	print<C3>();

	print<D1>();
	print<D2>();
	print<D3>();

	print<E1>();
	print<E2>();
	print<E3>();

	print<F1>();
	print<F2>();
	print<F3>();

	return 0;
}
