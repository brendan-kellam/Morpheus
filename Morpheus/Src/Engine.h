#ifndef ENGINE_H
#define ENGINE_H

#pragma once

#if ASSERTIONS_ENABLED // Used to strip assertions later 
#define MORPH_TRAP(expr) \
if (expr) { } \
else \
{ \
do { \
_CrtDbgReport( \
_CRT_ASSERT, __FILE__, __LINE__, #expr, NULL); \
_CrtDbgBreak(); \
} while (1); \
}
#else
#define MORPH_TRAP(expr) // do nothing
#endif


#endif /* ENGINE_H */