#include <fstream>
#include <string>
#include <iostream>
#include <type_traits>

#include "CopyMoveSemanticsHelpers.h"

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
    E2& operator=(const E2&) {return *this;}
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
    F2& operator=(F2&&) {return *this;}
};

struct F3
{
	F3& operator=(F3&&) = delete;
};


template<typename T>
struct Check
{
    //static_assert(std::is_copy_constructible_v<T>);
    //static_assert(std::is_move_constructible_v<T>);
    static_assert(std::is_copy_assignable_v<T>);
    static_assert(std::is_move_assignable_v<T>);
};


class Test1
{
public:
//private:
    ENABLE_COPY(Test1)
    CHECK_COPY_ENABLED(Test1)
    //CHECK_COPY_DISABLED(Test1)
};

class Test2
{
public:
private:
    DISABLE_COPY(Test2)
    CHECK_COPY_DISABLED(Test2)
};

class Test3
{
public:
//private:
    ENABLE_MOVE(Test3)
    CHECK_MOVE_ENABLED(Test3)
};

class Test4
{
public:
private:
    DISABLE_MOVE(Test4)
    CHECK_MOVE_DISABLED(Test4)
};


class T1
{
public:
//private:
    COPYABLE_MOVABLE(T1)
};

class T2
{
public:
//private:
    NONCOPYABLE_MOVABLE(T2)
};

class T3
{
public:
//private:
    COPYABLE_NONMOVABLE(T3)
};

class T4
{
public:
//private:
    NONCOPYABLE_NONMOVABLE(T4)
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

    print<Test1>();
    print<Test2>();
    print<Test3>();
    print<Test4>();

    print<T1>();
    print<T2>();
    print<T3>();
    print<T4>();

	return 0;
}
