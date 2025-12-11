#pragma once

#ifdef _MSC_VER
//windows MSVC
//Name: Erin Stacey
//Date:9/24/2024
#include <intrin.h>
#include <immintrin.h>
#else
//linux, windows clang
#include <mmintrin.h> //mmx
#include <xmmintrin.h> //sse
#include <emmintrin.h> //sse2
#include <pmmintrin.h> //sse3
#include <tmmintrin.h> //ssse3
#include <smmintrin.h> //sse4.1
#include <nmmintrin.h> //sse4.2
#include <immintrin.h> //avx, avx2
#endif

class xmm {
public:
    __m128 X;       //actual data that we're storing

    xmm() {}
    xmm(const float* f) {
        this->X = _mm_loadu_ps(f);
    }

    /// @brief  Set all slots of xmm to the given value
    /// @param f The value to set
    xmm(float f) {
        this->X = _mm_load1_ps(&f);
    }
    xmm(__m128 x) {
        this->X = x;
    }
    xmm(float a,  float b, float c, float d) {
        //a -> low slot, d -> high slot
        //_mm_set_ps
        this->X = _mm_set_ps(d,c,b,a);
        
       
        

    }
   
    static xmm zeros() {
        return xmm(_mm_setzero_ps());
    }

    /// @brief Copy constructor: Just copy all the data
    /// @param other  The thing to copy
    xmm(const xmm& other) {
        this->X = other.X;
    }

    /// @brief Assignment operator
    /// @param other 
    xmm operator=(const xmm& other) {
        this->X = other.X;
        return *this;
    }

    /// @brief Casting
    operator __m128() const {
        return this->X;
    }

    /// @brief Store data to RAM
    /// @param f Pointer which will get low slot of X
    void store(float* f) const {
        _mm_storeu_ps(f, this->X);
    }
    void operator+=(const xmm& other) {
        this->X = _mm_add_ps(this->X, other.X);
    }
    operator float() const {
        return _mm_cvtss_f32(this->X);
    }
    
    static xmm setall() {

        return xmm(_mm_cmpeq_ps(_mm_setzero_ps(), _mm_setzero_ps()));

    }
    static xmm ones() {
        return xmm::zeros() - xmm::setall();
    }

    // xmm operator+(xmm b) const {
    //     return xmm( _mm_add_ps( this->X, b.X));
    // }
};
inline xmm operator==(xmm a, xmm b) {
    return xmm(_mm_cmpeq_ps(a, b));
}
inline xmm operator-(xmm a, xmm b)
{
    return xmm(_mm_sub_ps(a.X, b.X));
};

inline xmm operator>(xmm a, xmm b) {
    return xmm(_mm_cmpgt_ps(a, b));
}
inline float dot(xmm a, xmm b) {
    xmm result = _mm_dp_ps(a, b, 0b11110001);
    return _mm_cvtss_f32(result);
};
inline xmm max(xmm a, xmm b) {
    return xmm(_mm_max_ps(a.X, b.X));
}
inline xmm min(xmm a, xmm b) {
    return xmm(_mm_min_ps(a.X, b.X));
}
inline xmm operator+(xmm a, xmm b)
{
    return xmm(_mm_add_ps(a.X, b.X));
}

inline xmm operator*(xmm a, xmm b)
{
    return xmm(_mm_mul_ps(a.X, b.X));
}
inline xmm operator/(xmm a, xmm b)
{
    return xmm(_mm_div_ps(a.X, b.X));
}

#include "xmm-int.h"

