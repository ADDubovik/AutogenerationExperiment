#pragma once

#include <type_traits>


#define ENABLE_COPY(Class) \
    Class(const Class&) = default; \
    Class& operator=(const Class&) = default;

#define CHECK_COPY_ENABLED(Class) \
    void ___checkCopyEnabled() \
    { \
        static_assert(std::is_copy_constructible_v<Class> \
            , "Copy c-tor should be enabled and public"); \
        static_assert(std::is_copy_assignable_v<Class> \
            , "Copy operator= should be enabled and public"); \
    }


#define DISABLE_COPY(Class) \
    Class(const Class&) = delete; \
    Class& operator=(const Class&) = delete;

#define CHECK_COPY_DISABLED(Class) \
    void ___checkCopyDisabled() \
    { \
        static_assert(!std::is_copy_constructible_v<Class>); \
        static_assert(!std::is_copy_assignable_v<Class>); \
    }


#define ENABLE_MOVE(Class) \
    Class(Class&&) = default; \
    Class& operator=(Class&&) = default;

#define CHECK_MOVE_ENABLED(Class) \
    void ___checkMoveEnabled() \
    { \
        static_assert(std::is_move_constructible_v<Class> \
            , "Move c-tor should be enabled and public"); \
        static_assert(std::is_move_assignable_v<Class> \
            , "Move operator= should be enabled and public"); \
    }


#define DISABLE_MOVE(Class) \
    Class(Class&&) = delete; \
    Class& operator=(Class&&) = delete;

#define CHECK_MOVE_DISABLED(Class) \
    void ___checkMoveDisabled() \
    { \
        static_assert(!std::is_move_constructible_v<Class>); \
        static_assert(!std::is_move_assignable_v<Class>); \
    }


#define COPYABLE(Class) \
    ENABLE_COPY(Class) \
    CHECK_COPY_ENABLED(Class)

#define MOVABLE(Class) \
    ENABLE_MOVE(Class) \
    CHECK_MOVE_ENABLED(Class)

#define NONCOPYABLE(Class) \
    DISABLE_COPY(Class) \
    CHECK_COPY_DISABLED(Class)

#define NONMOVABLE(Class) \
    DISABLE_MOVE(Class) \
    CHECK_MOVE_DISABLED(Class)


#define COPYABLE_MOVABLE(Class) \
    COPYABLE(Class) \
    MOVABLE(Class)

#define NONCOPYABLE_MOVABLE(Class) \
    NONCOPYABLE(Class) \
    MOVABLE(Class)

#define COPYABLE_NONMOVABLE(Class) \
    COPYABLE(Class) \
    NONMOVABLE(Class)

#define NONCOPYABLE_NONMOVABLE(Class) \
    NONCOPYABLE(Class) \
    NONMOVABLE(Class)
