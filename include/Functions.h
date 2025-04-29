#pragma once

#ifdef EXEMPLODLL_EXPORTS
#define EXEMPLODLL_API __declspec(dllexport)
#else
#define EXEMPLODLL_API __declspec(dllimport)
#endif

extern "C" EXEMPLODLL_API int Sumar(int a, int b);
extern "C" EXEMPLODLL_API long Factorial(int n);

//EXEMPLODLL_API int Sumar(int a, int b);
//EXEMPLODLL_API long Factorial(int n);

