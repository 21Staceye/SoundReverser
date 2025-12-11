// This file is auto-generated. Do not edit

#pragma once

#ifdef _MSC_VER
    //windows MSVC
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
#include <cstdint>
      

class xmmi8;
class xmmi16;
class xmmi32;
class xmmi64;
class xmmu8;
class xmmu16;
class xmmu32;
class xmmu64;


class xmmu8 {
  public:
    __m128i X;
    xmmu8(){ }
    xmmu8(__m128i x) { this->X = x; }
    xmmu8(const std::uint8_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmu8( std::uint8_t v0 , std::uint8_t v1 , std::uint8_t v2 , std::uint8_t v3 , std::uint8_t v4 , std::uint8_t v5 , std::uint8_t v6 , std::uint8_t v7 , std::uint8_t v8 , std::uint8_t v9 , std::uint8_t v10 , std::uint8_t v11 , std::uint8_t v12 , std::uint8_t v13 , std::uint8_t v14 , std::uint8_t v15 ){
        this->X = _mm_set_epi8( v15,v14,v13,v12,v11,v10,v9,v8,v7,v6,v5,v4,v3,v2,v1,v0 );
    }
void store(std::uint8_t* i) const{
_mm_storeu_epi8(i,this->X);
 }
xmmu8 shuffle(xmmu8 mask) const {
    return xmmu8(_mm_shuffle_epi8(this->X, mask.X));
}
    operator xmmi8() const ;
    operator xmmi16() const ;
    operator xmmu16() const ;
    operator xmmi32() const ;
    operator xmmu32() const ;
    operator xmmi64() const ;
    operator xmmu64() const ;
};  // xmmu8


inline xmmu8 operator+(xmmu8 a, xmmu8 b){
    return xmmu8 ( _mm_add_epi8(a.X, b.X) );
}


        inline xmmu8 operator-(xmmu8 a, xmmu8 b){
        return xmmu8 (_mm_sub_epi8(a.X,b.X));}
class xmmi8 {
  public:
    __m128i X;
    xmmi8(){ }
    xmmi8(__m128i x) { this->X = x; }
    xmmi8(const std::int8_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmi8( std::int8_t v0 , std::int8_t v1 , std::int8_t v2 , std::int8_t v3 , std::int8_t v4 , std::int8_t v5 , std::int8_t v6 , std::int8_t v7 , std::int8_t v8 , std::int8_t v9 , std::int8_t v10 , std::int8_t v11 , std::int8_t v12 , std::int8_t v13 , std::int8_t v14 , std::int8_t v15 ){
        this->X = _mm_set_epi8( v15,v14,v13,v12,v11,v10,v9,v8,v7,v6,v5,v4,v3,v2,v1,v0 );
    }
void store(std::int8_t* i) const{
_mm_storeu_epi8(i,this->X);
 }
    operator xmmu8() const ;
    operator xmmi16() const ;
    operator xmmu16() const ;
    operator xmmi32() const ;
    operator xmmu32() const ;
    operator xmmi64() const ;
    operator xmmu64() const ;
};  // xmmi8


inline xmmi8 operator+(xmmi8 a, xmmi8 b){
    return xmmi8 ( _mm_add_epi8(a.X, b.X) );
}


        inline xmmi8 operator-(xmmi8 a, xmmi8 b){
        return xmmi8 (_mm_sub_epi8(a.X,b.X));}
class xmmu16 {
  public:
    __m128i X;
    xmmu16(){ }
    xmmu16(__m128i x) { this->X = x; }
    xmmu16(const std::uint16_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmu16( std::uint16_t v0 , std::uint16_t v1 , std::uint16_t v2 , std::uint16_t v3 , std::uint16_t v4 , std::uint16_t v5 , std::uint16_t v6 , std::uint16_t v7 ){
        this->X = _mm_set_epi16( v7,v6,v5,v4,v3,v2,v1,v0 );
    }
void store(std::uint16_t* i) const{
_mm_storeu_epi16(i,this->X);
 }
    operator xmmi8() const ;
    operator xmmu8() const ;
    operator xmmi16() const ;
    operator xmmi32() const ;
    operator xmmu32() const ;
    operator xmmi64() const ;
    operator xmmu64() const ;
};  // xmmu16


inline xmmu16 operator+(xmmu16 a, xmmu16 b){
    return xmmu16 ( _mm_add_epi16(a.X, b.X) );
}


        inline xmmu16 operator-(xmmu16 a, xmmu16 b){
        return xmmu16 (_mm_sub_epi16(a.X,b.X));}
class xmmi16 {
  public:
    __m128i X;
    xmmi16(){ }
    xmmi16(__m128i x) { this->X = x; }
    xmmi16(const std::int16_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmi16( std::int16_t v0 , std::int16_t v1 , std::int16_t v2 , std::int16_t v3 , std::int16_t v4 , std::int16_t v5 , std::int16_t v6 , std::int16_t v7 ){
        this->X = _mm_set_epi16( v7,v6,v5,v4,v3,v2,v1,v0 );
    }
void store(std::int16_t* i) const{
_mm_storeu_epi16(i,this->X);
 }
    operator xmmi8() const ;
    operator xmmu8() const ;
    operator xmmu16() const ;
    operator xmmi32() const ;
    operator xmmu32() const ;
    operator xmmi64() const ;
    operator xmmu64() const ;
};  // xmmi16


inline xmmi16 operator+(xmmi16 a, xmmi16 b){
    return xmmi16 ( _mm_add_epi16(a.X, b.X) );
}


        inline xmmi16 operator-(xmmi16 a, xmmi16 b){
        return xmmi16 (_mm_sub_epi16(a.X,b.X));}
class xmmu32 {
  public:
    __m128i X;
    xmmu32(){ }
    xmmu32(__m128i x) { this->X = x; }
    xmmu32(const std::uint32_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmu32( std::uint32_t v0 , std::uint32_t v1 , std::uint32_t v2 , std::uint32_t v3 ){
        this->X = _mm_set_epi32( v3,v2,v1,v0 );
    }
void store(std::uint32_t* i) const{
_mm_storeu_epi32(i,this->X);
 }
    operator xmmi8() const ;
    operator xmmu8() const ;
    operator xmmi16() const ;
    operator xmmu16() const ;
    operator xmmi32() const ;
    operator xmmi64() const ;
    operator xmmu64() const ;
};  // xmmu32


inline xmmu32 operator+(xmmu32 a, xmmu32 b){
    return xmmu32 ( _mm_add_epi32(a.X, b.X) );
}


        inline xmmu32 operator-(xmmu32 a, xmmu32 b){
        return xmmu32 (_mm_sub_epi32(a.X,b.X));}
class xmmi32 {
  public:
    __m128i X;
    xmmi32(){ }
    xmmi32(__m128i x) { this->X = x; }
    xmmi32(const std::int32_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmi32( std::int32_t v0 , std::int32_t v1 , std::int32_t v2 , std::int32_t v3 ){
        this->X = _mm_set_epi32( v3,v2,v1,v0 );
    }
void store(std::int32_t* i) const{
_mm_storeu_epi32(i,this->X);
 }
    operator xmmi8() const ;
    operator xmmu8() const ;
    operator xmmi16() const ;
    operator xmmu16() const ;
    operator xmmu32() const ;
    operator xmmi64() const ;
    operator xmmu64() const ;
};  // xmmi32


inline xmmi32 operator+(xmmi32 a, xmmi32 b){
    return xmmi32 ( _mm_add_epi32(a.X, b.X) );
}


        inline xmmi32 operator-(xmmi32 a, xmmi32 b){
        return xmmi32 (_mm_sub_epi32(a.X,b.X));}
class xmmu64 {
  public:
    __m128i X;
    xmmu64(){ }
    xmmu64(__m128i x) { this->X = x; }
    xmmu64(const std::uint64_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmu64( std::uint64_t v0 , std::uint64_t v1 ){
        this->X = _mm_set_epi64x( v1,v0 );
    }
void store(std::uint64_t* i) const{
_mm_storeu_epi64(i,this->X);
 }
    operator xmmi8() const ;
    operator xmmu8() const ;
    operator xmmi16() const ;
    operator xmmu16() const ;
    operator xmmi32() const ;
    operator xmmu32() const ;
    operator xmmi64() const ;
};  // xmmu64


inline xmmu64 operator+(xmmu64 a, xmmu64 b){
    return xmmu64 ( _mm_add_epi64(a.X, b.X) );
}


        inline xmmu64 operator-(xmmu64 a, xmmu64 b){
        return xmmu64 (_mm_sub_epi64(a.X,b.X));}
class xmmi64 {
  public:
    __m128i X;
    xmmi64(){ }
    xmmi64(__m128i x) { this->X = x; }
    xmmi64(const std::int64_t* p){
         this->X = _mm_loadu_si128( (__m128i*) p);
    }
    xmmi64( std::int64_t v0 , std::int64_t v1 ){
        this->X = _mm_set_epi64x( v1,v0 );
    }
void store(std::int64_t* i) const{
_mm_storeu_epi64(i,this->X);
 }
    operator xmmi8() const ;
    operator xmmu8() const ;
    operator xmmi16() const ;
    operator xmmu16() const ;
    operator xmmi32() const ;
    operator xmmu32() const ;
    operator xmmu64() const ;
};  // xmmi64


inline xmmi64 operator+(xmmi64 a, xmmi64 b){
    return xmmi64 ( _mm_add_epi64(a.X, b.X) );
}


        inline xmmi64 operator-(xmmi64 a, xmmi64 b){
        return xmmi64 (_mm_sub_epi64(a.X,b.X));}
inline xmmu8::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmu8::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmu8::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmu8::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmu8::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmu8::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmu8::operator xmmu64() const {
    return xmmu64(this->X);
}
inline xmmi8::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmi8::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmi8::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmi8::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmi8::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmi8::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmi8::operator xmmu64() const {
    return xmmu64(this->X);
}
inline xmmu16::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmu16::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmu16::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmu16::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmu16::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmu16::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmu16::operator xmmu64() const {
    return xmmu64(this->X);
}
inline xmmi16::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmi16::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmi16::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmi16::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmi16::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmi16::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmi16::operator xmmu64() const {
    return xmmu64(this->X);
}
inline xmmu32::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmu32::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmu32::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmu32::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmu32::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmu32::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmu32::operator xmmu64() const {
    return xmmu64(this->X);
}
inline xmmi32::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmi32::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmi32::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmi32::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmi32::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmi32::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmi32::operator xmmu64() const {
    return xmmu64(this->X);
}
inline xmmu64::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmu64::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmu64::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmu64::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmu64::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmu64::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmu64::operator xmmi64() const {
    return xmmi64(this->X);
}
inline xmmi64::operator xmmi8() const {
    return xmmi8(this->X);
}
inline xmmi64::operator xmmu8() const {
    return xmmu8(this->X);
}
inline xmmi64::operator xmmi16() const {
    return xmmi16(this->X);
}
inline xmmi64::operator xmmu16() const {
    return xmmu16(this->X);
}
inline xmmi64::operator xmmi32() const {
    return xmmi32(this->X);
}
inline xmmi64::operator xmmu32() const {
    return xmmu32(this->X);
}
inline xmmi64::operator xmmu64() const {
    return xmmu64(this->X);
}
