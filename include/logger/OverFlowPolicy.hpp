#pragma once
namespace Logger
{
enum class OverflowPolicy {
    BLOCK,
    DROP_NEW,
    DROP_OLD
};
}