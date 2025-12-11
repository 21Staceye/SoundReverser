
fp = open("xmm-int.h","w")

print("// This file is auto-generated. Do not edit",file=fp)

print("""
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

""",file=fp)


def makeClass(signed, bits):
    #signed = 'i' or 'u'
    #bits = 8, 16, 32, or 64
    
    #ctype = uint8_t, int8_t, uint16_t, ...etc...
    if signed == "i":
        ctype = f"std::int{bits}_t"
    else:
        ctype = f"std::uint{bits}_t"

    #ex: xmmi8 or xmmu16
    classname = f"xmm{signed}{bits}"

    print("class",classname, "{", file=fp)

    print("  public:",file=fp)
    print("    __m128i X;",file=fp)

    #parameterless constructor
    print(f"    {classname}(){{ }}", file=fp)

    print(f"    {classname}(__m128i x) {{ this->X = x; }}",file=fp)

    #constructor that takes pointer to data
    print(f"    {classname}(const {ctype}* p){{",file=fp)
    print("         this->X = _mm_loadu_si128( (__m128i*) p);",file=fp)
    print("    }",file=fp)

    #constructor that takes a bunch of scalars
    numParms = 128 // bits
    parameterList = [ f"{ctype} v{i}" for i in range(numParms)]
    parameterList2 = [ f"v{i}" for i in range(numParms)]

    suffix = "x" if bits == 64 else ""

    print(f"    {classname}( {' , '.join(parameterList)} ){{",file=fp)
    print(f"        this->X = _mm_set_epi{bits}{suffix}( {','.join(reversed(parameterList2))} );",file=fp)
    print("    }",file=fp)
    print(f"void store({ctype}* i) const{{",file=fp)

    print(f"_mm_storeu_epi{bits}(i,this->X);", file=fp)
    print(" }",file=fp)

    #cast to other types
    for b in [8,16,32,64]:
        for s in ["i","u"]:
            if b == bits and s == signed:
                pass
            else:
                
                print(f"    operator xmm{s}{b}() const ;",file=fp)


    print("};  //",classname, file=fp)
    print(file=fp)

    #binary functions go here
    print(f"""
inline {classname} operator+({classname} a, {classname} b){{
    return {classname} ( _mm_add_epi{bits}(a.X, b.X) );
}}""",file=fp)
    print(file=fp)
    print(f"""
        inline {classname} operator-({classname} a, {classname} b){{
        return {classname} (_mm_sub_epi{bits}(a.X,b.X));}}""",file=fp)
        
      
      
      
    
def store(signed,bits):
     print(f"void store({signed}{bits}*i) const{{",file=fp)
     
    # void store(float* f) const {
   #     _mm_storeu_ps(f, this->X);
   # }
def makeCastFunction(signed,bits):
    #signed is u or i, bits is 8, 16, 32, or 64
    fromclassname = f"xmm{signed}{bits}"
    for b in [8,16,32,64]:
        for s in ["i","u"]:
            if b == bits and s == signed:
                pass
            else:
                toclassname = f"xmm{s}{b}"
                print(f"inline {fromclassname}::operator {toclassname}() const {{",file=fp)
                print(f"    return {toclassname}(this->X);",file=fp)
                print("}",file=fp)

for bits in [8,16,32,64]:
    for signed in ["u","i"]:
        makeClass(signed,bits)

for bits in [8,16,32,64]:
    for signed in ["u","i"]:
        makeCastFunction(signed,bits)



fp.close()
 