

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#else

#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#if PY_VERSION_HEX < 0x02040000
  #define METH_COEXIST 0
  #define PyDict_CheckExact(op) (Py_TYPE(op) == &PyDict_Type)
  #define PyDict_Contains(d,o)   PySequence_Contains(d,o)
#endif

#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PY_FORMAT_SIZE_T ""
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)   PyInt_AsLong(o)
  #define PyNumber_Index(o)    PyNumber_Int(o)
  #define PyIndex_Check(o)     PyNumber_Check(o)
  #define PyErr_WarnEx(category, message, stacklevel) PyErr_Warn(category, message)
#endif

#if PY_VERSION_HEX < 0x02060000
  #define Py_REFCNT(ob) (((PyObject*)(ob))->ob_refcnt)
  #define Py_TYPE(ob)   (((PyObject*)(ob))->ob_type)
  #define Py_SIZE(ob)   (((PyVarObject*)(ob))->ob_size)
  #define PyVarObject_HEAD_INIT(type, size) \
          PyObject_HEAD_INIT(type) size,
  #define PyType_Modified(t)

  typedef struct {
     void *buf;
     PyObject *obj;
     Py_ssize_t len;
     Py_ssize_t itemsize;
     int readonly;
     int ndim;
     char *format;
     Py_ssize_t *shape;
     Py_ssize_t *strides;
     Py_ssize_t *suboffsets;
     void *internal;
  } Py_buffer;

  #define PyBUF_SIMPLE 0
  #define PyBUF_WRITABLE 0x0001
  #define PyBUF_FORMAT 0x0004
  #define PyBUF_ND 0x0008
  #define PyBUF_STRIDES (0x0010 | PyBUF_ND)
  #define PyBUF_C_CONTIGUOUS (0x0020 | PyBUF_STRIDES)
  #define PyBUF_F_CONTIGUOUS (0x0040 | PyBUF_STRIDES)
  #define PyBUF_ANY_CONTIGUOUS (0x0080 | PyBUF_STRIDES)
  #define PyBUF_INDIRECT (0x0100 | PyBUF_STRIDES)

#endif

#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#endif

#if PY_MAJOR_VERSION >= 3
  #define Py_TPFLAGS_CHECKTYPES 0
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif

#if (PY_VERSION_HEX < 0x02060000) || (PY_MAJOR_VERSION >= 3)
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif

#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyString_Type                PyUnicode_Type
  #define PyString_CheckExact          PyUnicode_CheckExact
#else
  #define PyBytes_Type                 PyString_Type
  #define PyBytes_CheckExact           PyString_CheckExact
#endif

#if PY_MAJOR_VERSION >= 3
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)

#endif

#if PY_MAJOR_VERSION >= 3
  #define PyMethod_New(func, self, klass) PyInstanceMethod_New(func)
#endif

#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#else
  #define _USE_MATH_DEFINES
#endif

#if PY_VERSION_HEX < 0x02050000
  #define __Pyx_GetAttrString(o,n)   PyObject_GetAttrString((o),((char *)(n)))
  #define __Pyx_SetAttrString(o,n,a) PyObject_SetAttrString((o),((char *)(n)),(a))
  #define __Pyx_DelAttrString(o,n)   PyObject_DelAttrString((o),((char *)(n)))
#else
  #define __Pyx_GetAttrString(o,n)   PyObject_GetAttrString((o),(n))
  #define __Pyx_SetAttrString(o,n,a) PyObject_SetAttrString((o),(n),(a))
  #define __Pyx_DelAttrString(o,n)   PyObject_DelAttrString((o),(n))
#endif

#if PY_VERSION_HEX < 0x02050000
  #define __Pyx_NAMESTR(n) ((char *)(n))
  #define __Pyx_DOCSTR(n)  ((char *)(n))
#else
  #define __Pyx_NAMESTR(n) (n)
  #define __Pyx_DOCSTR(n)  (n)
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>
#define __PYX_HAVE_API__interpnd
#include "stdlib.h"
#include "stdio.h"
#include "numpy/arrayobject.h"
#include "numpy/ufuncobject.h"
#include "numpy/ndarraytypes.h"
#include "math.h"

#ifndef CYTHON_INLINE
  #if defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #else
    #define CYTHON_INLINE 
  #endif
#endif

typedef struct {PyObject **p; char *s; const long n; const char* encoding; const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry; 




#if PY_MAJOR_VERSION < 3
#define __Pyx_PyBytes_FromString          PyString_FromString
#define __Pyx_PyBytes_FromStringAndSize   PyString_FromStringAndSize
#define __Pyx_PyBytes_AsString            PyString_AsString
#else
#define __Pyx_PyBytes_FromString          PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize   PyBytes_FromStringAndSize
#define __Pyx_PyBytes_AsString            PyBytes_AsString
#endif

#define __Pyx_PyBytes_FromUString(s)      __Pyx_PyBytes_FromString((char*)s)
#define __Pyx_PyBytes_AsUString(s)        ((unsigned char*) __Pyx_PyBytes_AsString(s))

#define __Pyx_PyBool_FromLong(b) ((b) ? (Py_INCREF(Py_True), Py_True) : (Py_INCREF(Py_False), Py_False))
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_Int(PyObject* x);

#if !defined(T_PYSSIZET)
#if PY_VERSION_HEX < 0x02050000
#define T_PYSSIZET T_INT
#elif !defined(T_LONGLONG)
#define T_PYSSIZET \
        ((sizeof(Py_ssize_t) == sizeof(int))  ? T_INT  : \
        ((sizeof(Py_ssize_t) == sizeof(long)) ? T_LONG : -1))
#else
#define T_PYSSIZET \
        ((sizeof(Py_ssize_t) == sizeof(int))          ? T_INT      : \
        ((sizeof(Py_ssize_t) == sizeof(long))         ? T_LONG     : \
        ((sizeof(Py_ssize_t) == sizeof(PY_LONG_LONG)) ? T_LONGLONG : -1)))
#endif
#endif


#if !defined(T_ULONGLONG)
#define __Pyx_T_UNSIGNED_INT(x) \
        ((sizeof(x) == sizeof(unsigned char))  ? T_UBYTE : \
        ((sizeof(x) == sizeof(unsigned short)) ? T_USHORT : \
        ((sizeof(x) == sizeof(unsigned int))   ? T_UINT : \
        ((sizeof(x) == sizeof(unsigned long))  ? T_ULONG : -1))))
#else
#define __Pyx_T_UNSIGNED_INT(x) \
        ((sizeof(x) == sizeof(unsigned char))  ? T_UBYTE : \
        ((sizeof(x) == sizeof(unsigned short)) ? T_USHORT : \
        ((sizeof(x) == sizeof(unsigned int))   ? T_UINT : \
        ((sizeof(x) == sizeof(unsigned long))  ? T_ULONG : \
        ((sizeof(x) == sizeof(unsigned PY_LONG_LONG)) ? T_ULONGLONG : -1)))))
#endif
#if !defined(T_LONGLONG)
#define __Pyx_T_SIGNED_INT(x) \
        ((sizeof(x) == sizeof(char))  ? T_BYTE : \
        ((sizeof(x) == sizeof(short)) ? T_SHORT : \
        ((sizeof(x) == sizeof(int))   ? T_INT : \
        ((sizeof(x) == sizeof(long))  ? T_LONG : -1))))
#else
#define __Pyx_T_SIGNED_INT(x) \
        ((sizeof(x) == sizeof(char))  ? T_BYTE : \
        ((sizeof(x) == sizeof(short)) ? T_SHORT : \
        ((sizeof(x) == sizeof(int))   ? T_INT : \
        ((sizeof(x) == sizeof(long))  ? T_LONG : \
        ((sizeof(x) == sizeof(PY_LONG_LONG))   ? T_LONGLONG : -1)))))
#endif

#define __Pyx_T_FLOATING(x) \
        ((sizeof(x) == sizeof(float)) ? T_FLOAT : \
        ((sizeof(x) == sizeof(double)) ? T_DOUBLE : -1))

#if !defined(T_SIZET)
#if !defined(T_ULONGLONG)
#define T_SIZET \
        ((sizeof(size_t) == sizeof(unsigned int))  ? T_UINT  : \
        ((sizeof(size_t) == sizeof(unsigned long)) ? T_ULONG : -1))
#else
#define T_SIZET \
        ((sizeof(size_t) == sizeof(unsigned int))          ? T_UINT      : \
        ((sizeof(size_t) == sizeof(unsigned long))         ? T_ULONG     : \
        ((sizeof(size_t) == sizeof(unsigned PY_LONG_LONG)) ? T_ULONGLONG : -1)))
#endif
#endif

static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
static CYTHON_INLINE size_t __Pyx_PyInt_AsSize_t(PyObject*);

#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))


#ifdef __GNUC__

#if __GNUC__ > 2 ||               (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)) 
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else 
#define likely(x)   (x)
#define unlikely(x) (x)
#endif 
#else 
#define likely(x)   (x)
#define unlikely(x) (x)
#endif 
    
static PyObject *__pyx_m;
static PyObject *__pyx_b;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;
static const char **__pyx_f;


#if !defined(CYTHON_CCOMPLEX)
  #if defined(__cplusplus)
    #define CYTHON_CCOMPLEX 1
  #elif defined(_Complex_I)
    #define CYTHON_CCOMPLEX 1
  #else
    #define CYTHON_CCOMPLEX 0
  #endif
#endif

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    #include <complex>
  #else
    #include <complex.h>
  #endif
#endif

#if CYTHON_CCOMPLEX && !defined(__cplusplus) && defined(__sun__) && defined(__GNUC__)
  #undef _Complex_I
  #define _Complex_I 1.0fj
#endif

typedef npy_int8 __pyx_t_5numpy_int8_t;

typedef npy_int16 __pyx_t_5numpy_int16_t;

typedef npy_int32 __pyx_t_5numpy_int32_t;

typedef npy_int64 __pyx_t_5numpy_int64_t;

typedef npy_uint8 __pyx_t_5numpy_uint8_t;

typedef npy_uint16 __pyx_t_5numpy_uint16_t;

typedef npy_uint32 __pyx_t_5numpy_uint32_t;

typedef npy_uint64 __pyx_t_5numpy_uint64_t;

typedef npy_float32 __pyx_t_5numpy_float32_t;

typedef npy_float64 __pyx_t_5numpy_float64_t;

typedef npy_long __pyx_t_5numpy_int_t;

typedef npy_longlong __pyx_t_5numpy_long_t;

typedef npy_intp __pyx_t_5numpy_intp_t;

typedef npy_uintp __pyx_t_5numpy_uintp_t;

typedef npy_ulong __pyx_t_5numpy_uint_t;

typedef npy_ulonglong __pyx_t_5numpy_ulong_t;

typedef npy_double __pyx_t_5numpy_float_t;

typedef npy_double __pyx_t_5numpy_double_t;

typedef npy_longdouble __pyx_t_5numpy_longdouble_t;

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    typedef ::std::complex< double > __pyx_t_double_complex;
  #else
    typedef double _Complex __pyx_t_double_complex;
  #endif
#else
    typedef struct { double real, imag; } __pyx_t_double_complex;
#endif

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    typedef ::std::complex< float > __pyx_t_float_complex;
  #else
    typedef float _Complex __pyx_t_float_complex;
  #endif
#else
    typedef struct { float real, imag; } __pyx_t_float_complex;
#endif



typedef npy_cfloat __pyx_t_5numpy_cfloat_t;

typedef npy_cdouble __pyx_t_5numpy_cdouble_t;

typedef npy_clongdouble __pyx_t_5numpy_clongdouble_t;

typedef npy_cdouble __pyx_t_5numpy_complex_t;



typedef struct {
  int ndim;
  int npoints;
  int nsimplex;
  double *points;
  int *vertices;
  int *neighbors;
  double *equations;
  double *transform;
  int *vertex_to_simplex;
  double paraboloid_scale;
  double paraboloid_shift;
  double *max_bound;
  double *min_bound;
} __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t;



typedef struct {
  __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *info;
  int index;
  int vertex;
  int vertex2;
  int triangle;
  int start_triangle;
  int start_index;
  int restart;
} __pyx_t_5scipy_7spatial_5qhull_RidgeIter2D_t;

#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif

#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct * __Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule((char *)modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, (char *)"RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
  end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
  }
  #define __Pyx_RefNannySetupContext(name)           void *__pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
  #define __Pyx_RefNannyFinishContext()           __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r) __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r) __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r) __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XDECREF(r) do { if((r) != NULL) {__Pyx_DECREF(r);} } while(0)
#else
  #define __Pyx_RefNannySetupContext(name)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
#endif 
#define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);} } while(0)
#define __Pyx_XGOTREF(r) do { if((r) != NULL) {__Pyx_GOTREF(r);} } while(0)

static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name, PyObject* kw_name); 

static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found); 

static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],     PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,     const char* function_name); 


static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}


#define __Pyx_GetItemInt_List(o, i, size, to_py_func) ((size <= sizeof(Py_ssize_t)) ? \
                                                    __Pyx_GetItemInt_List_Fast(o, i, size <= sizeof(long)) : \
                                                    __Pyx_GetItemInt_Generic(o, to_py_func(i)))

static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i, int fits_long) {
    if (likely(o != Py_None)) {
        if (likely((0 <= i) & (i < PyList_GET_SIZE(o)))) {
            PyObject *r = PyList_GET_ITEM(o, i);
            Py_INCREF(r);
            return r;
        }
        else if ((-PyList_GET_SIZE(o) <= i) & (i < 0)) {
            PyObject *r = PyList_GET_ITEM(o, PyList_GET_SIZE(o) + i);
            Py_INCREF(r);
            return r;
        }
    }
    return __Pyx_GetItemInt_Generic(o, fits_long ? PyInt_FromLong(i) : PyLong_FromLongLong(i));
}

#define __Pyx_GetItemInt_Tuple(o, i, size, to_py_func) ((size <= sizeof(Py_ssize_t)) ? \
                                                    __Pyx_GetItemInt_Tuple_Fast(o, i, size <= sizeof(long)) : \
                                                    __Pyx_GetItemInt_Generic(o, to_py_func(i)))

static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i, int fits_long) {
    if (likely(o != Py_None)) {
        if (likely((0 <= i) & (i < PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, i);
            Py_INCREF(r);
            return r;
        }
        else if ((-PyTuple_GET_SIZE(o) <= i) & (i < 0)) {
            PyObject *r = PyTuple_GET_ITEM(o, PyTuple_GET_SIZE(o) + i);
            Py_INCREF(r);
            return r;
        }
    }
    return __Pyx_GetItemInt_Generic(o, fits_long ? PyInt_FromLong(i) : PyLong_FromLongLong(i));
}


#define __Pyx_GetItemInt(o, i, size, to_py_func) ((size <= sizeof(Py_ssize_t)) ? \
                                                    __Pyx_GetItemInt_Fast(o, i, size <= sizeof(long)) : \
                                                    __Pyx_GetItemInt_Generic(o, to_py_func(i)))

static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int fits_long) {
    PyObject *r;
    if (PyList_CheckExact(o) && ((0 <= i) & (i < PyList_GET_SIZE(o)))) {
        r = PyList_GET_ITEM(o, i);
        Py_INCREF(r);
    }
    else if (PyTuple_CheckExact(o) && ((0 <= i) & (i < PyTuple_GET_SIZE(o)))) {
        r = PyTuple_GET_ITEM(o, i);
        Py_INCREF(r);
    }
    else if (Py_TYPE(o)->tp_as_sequence && Py_TYPE(o)->tp_as_sequence->sq_item && (likely(i >= 0))) {
        r = PySequence_GetItem(o, i);
    }
    else {
        r = __Pyx_GetItemInt_Generic(o, fits_long ? PyInt_FromLong(i) : PyLong_FromLongLong(i));
    }
    return r;
}

static double __Pyx__PyObject_AsDouble(PyObject* obj); 

#define __Pyx_PyObject_AsDouble(obj) \
    ((likely(PyFloat_CheckExact(obj))) ? \
     PyFloat_AS_DOUBLE(obj) : __Pyx__PyObject_AsDouble(obj))


struct __Pyx_StructField_;

typedef struct {
  const char* name; 
  struct __Pyx_StructField_* fields;
  size_t size;     
  char typegroup; 
} __Pyx_TypeInfo;

typedef struct __Pyx_StructField_ {
  __Pyx_TypeInfo* type;
  const char* name;
  size_t offset;
} __Pyx_StructField;

typedef struct {
  __Pyx_StructField* field;
  size_t parent_offset;
} __Pyx_BufFmt_StackElem;


static CYTHON_INLINE void __Pyx_SafeReleaseBuffer(Py_buffer* info);
static int __Pyx_GetBufferAndValidate(Py_buffer* buf, PyObject* obj, __Pyx_TypeInfo* dtype, int flags, int nd, int cast, __Pyx_BufFmt_StackElem* stack);

static CYTHON_INLINE int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type); 

static void __Pyx_RaiseBufferFallbackError(void); 
#define __Pyx_BufPtrStrided2d(type, buf, i0, s0, i1, s1) (type)((char*)buf + i0 * s0 + i1 * s1)

static CYTHON_INLINE void __Pyx_ErrRestore(PyObject *type, PyObject *value, PyObject *tb); 
static CYTHON_INLINE void __Pyx_ErrFetch(PyObject **type, PyObject **value, PyObject **tb); 
#define __Pyx_BufPtrStrided3d(type, buf, i0, s0, i1, s1, i2, s2) (type)((char*)buf + i0 * s0 + i1 * s1 + i2 * s2)

static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);

static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(void);

static PyObject *__Pyx_UnpackItem(PyObject *, Py_ssize_t index); 
static int __Pyx_EndUnpack(PyObject *); 

static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void);

static void __Pyx_UnpackTupleError(PyObject *, Py_ssize_t index); 

static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed,
    const char *name, int exact); 

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    #define __Pyx_CREAL(z) ((z).real())
    #define __Pyx_CIMAG(z) ((z).imag())
  #else
    #define __Pyx_CREAL(z) (__real__(z))
    #define __Pyx_CIMAG(z) (__imag__(z))
  #endif
#else
    #define __Pyx_CREAL(z) ((z).real)
    #define __Pyx_CIMAG(z) ((z).imag)
#endif

#if defined(_WIN32) && defined(__cplusplus) && CYTHON_CCOMPLEX
    #define __Pyx_SET_CREAL(z,x) ((z).real(x))
    #define __Pyx_SET_CIMAG(z,y) ((z).imag(y))
#else
    #define __Pyx_SET_CREAL(z,x) __Pyx_CREAL(z) = (x)
    #define __Pyx_SET_CIMAG(z,y) __Pyx_CIMAG(z) = (y)
#endif

static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double, double);

#if CYTHON_CCOMPLEX
    #define __Pyx_c_eq(a, b)   ((a)==(b))
    #define __Pyx_c_sum(a, b)  ((a)+(b))
    #define __Pyx_c_diff(a, b) ((a)-(b))
    #define __Pyx_c_prod(a, b) ((a)*(b))
    #define __Pyx_c_quot(a, b) ((a)/(b))
    #define __Pyx_c_neg(a)     (-(a))
  #ifdef __cplusplus
    #define __Pyx_c_is_zero(z) ((z)==(double)0)
    #define __Pyx_c_conj(z)    (::std::conj(z))
    
  #else
    #define __Pyx_c_is_zero(z) ((z)==0)
    #define __Pyx_c_conj(z)    (conj(z))
    
 #endif
#else
    static CYTHON_INLINE int __Pyx_c_eq(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_sum(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_diff(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_prod(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_neg(__pyx_t_double_complex);
    static CYTHON_INLINE int __Pyx_c_is_zero(__pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_conj(__pyx_t_double_complex);
    
#endif
#if PY_MAJOR_VERSION < 3
static int __Pyx_GetBuffer(PyObject *obj, Py_buffer *view, int flags);
static void __Pyx_ReleaseBuffer(Py_buffer *view);
#else
#define __Pyx_GetBuffer PyObject_GetBuffer
#define __Pyx_ReleaseBuffer PyBuffer_Release
#endif

Py_ssize_t __Pyx_zeros[] = {0, 0, 0};
Py_ssize_t __Pyx_minusones[] = {-1, -1, -1};

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); 

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); 

static PyObject *__Pyx_CreateClass(PyObject *bases, PyObject *dict, PyObject *name, const char *modname); 

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); 

static CYTHON_INLINE PyObject *__Pyx_PyInt_to_py_npy_intp(npy_intp);

#ifndef __PYX_FORCE_INIT_THREADS
  #if PY_VERSION_HEX < 0x02040200
    #define __PYX_FORCE_INIT_THREADS 1
  #else
    #define __PYX_FORCE_INIT_THREADS 0
  #endif
#endif

static __pyx_t_double_complex __Pyx_PyComplex_As___pyx_t_double_complex(PyObject*);

static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float, float);

#if CYTHON_CCOMPLEX
    #define __Pyx_c_eqf(a, b)   ((a)==(b))
    #define __Pyx_c_sumf(a, b)  ((a)+(b))
    #define __Pyx_c_difff(a, b) ((a)-(b))
    #define __Pyx_c_prodf(a, b) ((a)*(b))
    #define __Pyx_c_quotf(a, b) ((a)/(b))
    #define __Pyx_c_negf(a)     (-(a))
  #ifdef __cplusplus
    #define __Pyx_c_is_zerof(z) ((z)==(float)0)
    #define __Pyx_c_conjf(z)    (::std::conj(z))
    
  #else
    #define __Pyx_c_is_zerof(z) ((z)==0)
    #define __Pyx_c_conjf(z)    (conjf(z))
    
 #endif
#else
    static CYTHON_INLINE int __Pyx_c_eqf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_sumf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_difff(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_prodf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quotf(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_negf(__pyx_t_float_complex);
    static CYTHON_INLINE int __Pyx_c_is_zerof(__pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_conjf(__pyx_t_float_complex);
    
#endif

static CYTHON_INLINE unsigned char __Pyx_PyInt_AsUnsignedChar(PyObject *);

static CYTHON_INLINE unsigned short __Pyx_PyInt_AsUnsignedShort(PyObject *);

static CYTHON_INLINE unsigned int __Pyx_PyInt_AsUnsignedInt(PyObject *);

static CYTHON_INLINE char __Pyx_PyInt_AsChar(PyObject *);

static CYTHON_INLINE short __Pyx_PyInt_AsShort(PyObject *);

static CYTHON_INLINE int __Pyx_PyInt_AsInt(PyObject *);

static CYTHON_INLINE signed char __Pyx_PyInt_AsSignedChar(PyObject *);

static CYTHON_INLINE signed short __Pyx_PyInt_AsSignedShort(PyObject *);

static CYTHON_INLINE signed int __Pyx_PyInt_AsSignedInt(PyObject *);

static CYTHON_INLINE unsigned long __Pyx_PyInt_AsUnsignedLong(PyObject *);

static CYTHON_INLINE unsigned PY_LONG_LONG __Pyx_PyInt_AsUnsignedLongLong(PyObject *);

static CYTHON_INLINE long __Pyx_PyInt_AsLong(PyObject *);

static CYTHON_INLINE PY_LONG_LONG __Pyx_PyInt_AsLongLong(PyObject *);

static CYTHON_INLINE signed long __Pyx_PyInt_AsSignedLong(PyObject *);

static CYTHON_INLINE signed PY_LONG_LONG __Pyx_PyInt_AsSignedLongLong(PyObject *);

static PyTypeObject *__Pyx_ImportType(const char *module_name, const char *class_name, long size, int strict);  

static PyObject *__Pyx_ImportModule(const char *name); 

static int __Pyx_ImportFunction(PyObject *module, const char *funcname, void (**f)(void), const char *sig); 

static void __Pyx_AddTraceback(const char *funcname); 

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); 












static PyTypeObject *__pyx_ptype_5numpy_dtype = 0;
static PyTypeObject *__pyx_ptype_5numpy_flatiter = 0;
static PyTypeObject *__pyx_ptype_5numpy_broadcast = 0;
static PyTypeObject *__pyx_ptype_5numpy_ndarray = 0;
static PyTypeObject *__pyx_ptype_5numpy_ufunc = 0;
static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew1(PyObject *); 
static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew2(PyObject *, PyObject *); 
static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew3(PyObject *, PyObject *, PyObject *); 
static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew4(PyObject *, PyObject *, PyObject *, PyObject *); 
static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew5(PyObject *, PyObject *, PyObject *, PyObject *, PyObject *); 
static CYTHON_INLINE char *__pyx_f_5numpy__util_dtypestring(PyArray_Descr *, char *, char *, int *); 
static CYTHON_INLINE void __pyx_f_5numpy_set_array_base(PyArrayObject *, PyObject *); 
static CYTHON_INLINE PyObject *__pyx_f_5numpy_get_array_base(PyArrayObject *); 


static __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *(*__pyx_f_5scipy_7spatial_5qhull__get_delaunay_info)(PyObject *, int, int); 
static int (*__pyx_f_5scipy_7spatial_5qhull__barycentric_inside)(int, double *, double *, double *, double); 
static void (*__pyx_f_5scipy_7spatial_5qhull__barycentric_coordinate_single)(int, double *, double *, double *, int); 
static void (*__pyx_f_5scipy_7spatial_5qhull__barycentric_coordinates)(int, double *, double *, double *); 
static void (*__pyx_f_5scipy_7spatial_5qhull__lift_point)(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *); 
static double (*__pyx_f_5scipy_7spatial_5qhull__distplane)(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, int, double *); 
static int (*__pyx_f_5scipy_7spatial_5qhull__is_point_fully_outside)(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double); 
static int (*__pyx_f_5scipy_7spatial_5qhull__find_simplex_bruteforce)(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *, double); 
static int (*__pyx_f_5scipy_7spatial_5qhull__find_simplex_directed)(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *, int *, double); 
static int (*__pyx_f_5scipy_7spatial_5qhull__find_simplex)(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *, int *, double); 
static void (*__pyx_f_5scipy_7spatial_5qhull__RidgeIter2D_init)(__pyx_t_5scipy_7spatial_5qhull_RidgeIter2D_t *, __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, int); 
static void (*__pyx_f_5scipy_7spatial_5qhull__RidgeIter2D_next)(__pyx_t_5scipy_7spatial_5qhull_RidgeIter2D_t *); 




static int __pyx_f_8interpnd__estimate_gradients_2d_global(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, int, double, double *); 
static double __pyx_f_8interpnd__clough_tocher_2d_single_double(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, int, double *, double *, double *); 
static __pyx_t_double_complex __pyx_f_8interpnd__clough_tocher_2d_single_complex(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, int, double *, __pyx_t_double_complex *, __pyx_t_double_complex *); 
static __Pyx_TypeInfo __Pyx_TypeInfo_nn___pyx_t_5numpy_double_t = { "numpy.double_t", NULL, sizeof(__pyx_t_5numpy_double_t), 'R' };
static __Pyx_TypeInfo __Pyx_TypeInfo_nn_npy_int = { "numpy.npy_int", NULL, sizeof(npy_int), 'I' };
static __Pyx_TypeInfo __Pyx_TypeInfo_double = { "double", NULL, sizeof(double), 'R' };
static __Pyx_StructField __Pyx_StructFields_nn___pyx_t_5numpy_complex_t[] = {
  {&__Pyx_TypeInfo_double, "real", offsetof(__pyx_t_5numpy_complex_t, real)},
  {&__Pyx_TypeInfo_double, "imag", offsetof(__pyx_t_5numpy_complex_t, imag)},
  {NULL, NULL, 0}
};
static __Pyx_TypeInfo __Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t = { "numpy.complex_t", __Pyx_StructFields_nn___pyx_t_5numpy_complex_t, sizeof(__pyx_t_5numpy_complex_t), 'C' };
#define __Pyx_MODULE_NAME "interpnd"
int __pyx_module_is_main_interpnd = 0;


static PyObject *__pyx_builtin_object;
static PyObject *__pyx_builtin_Warning;
static PyObject *__pyx_builtin_ValueError;
static PyObject *__pyx_builtin_map;
static PyObject *__pyx_builtin_xrange;
static PyObject *__pyx_builtin_enumerate;
static PyObject *__pyx_builtin_range;
static PyObject *__pyx_builtin_RuntimeError;
static char __pyx_k_2[] = "_ndim_coords_from_arrays";
static char __pyx_k_3[] = "different number of values and points";
static char __pyx_k_4[] = "invalid shape for input data points";
static char __pyx_k_5[] = "input data must be at least 2-D";
static char __pyx_k_6[] = "this mode of interpolation available only for %-D data";
static char __pyx_k_7[] = "number of dimensions in xi does not match x";
static char __pyx_k_8[] = "coordinate arrays do not have the same shape";
static char __pyx_k_11[] = "'y' has a wrong number of items";
static char __pyx_k_12[] = "estimate_gradients_2d_global";
static char __pyx_k_13[] = "Gradient estimation did not converge, the results may be inaccurate";
static char __pyx_k_14[] = "GradientEstimationWarning";
static char __pyx_k_17[] = "ndarray is not C contiguous";
static char __pyx_k_18[] = "ndarray is not Fortran contiguous";
static char __pyx_k_19[] = "Non-native byte order not supported";
static char __pyx_k_20[] = "unknown dtype code in numpy.pxd (%d)";
static char __pyx_k_21[] = "Format string allocated too short, see comment in numpy.pxd";
static char __pyx_k_22[] = "Format string allocated too short.";
static char __pyx_k_23[] = "\nSimple N-D interpolation\n\n.. versionadded:: 0.9\n\n";
static char __pyx_k_24[] = "scipy.spatial.qhull";
static char __pyx_k_25[] = "*";
static char __pyx_k_26[] = "\n    Common routines for interpolators.\n\n    .. versionadded:: 0.9\n\n    ";
static char __pyx_k_27[] = "\n    LinearNDInterpolator(points, values)\n\n    Piecewise linear interpolant in N dimensions. \n\n    .. versionadded:: 0.9\n\n    Parameters\n    ----------\n    points : ndarray of floats, shape (npoints, ndims)\n        Data point coordinates.\n    values : ndarray of float or complex, shape (npoints, ...)\n        Data values.\n    fill_value : float, optional\n        Value used to fill in for requested points outside of the\n        convex hull of the input points.  If not provided, then\n        the default is ``nan``.\n\n    Notes\n    -----\n    The interpolant is constructed by triangulating the input data\n    with Qhull [Qhull]_, and on each triangle performing linear\n    barycentric interpolation.\n\n    References\n    ----------\n    .. [Qhull] http://www.qhull.org/\n\n    ";
static char __pyx_k_28[] = "LinearNDInterpolator";
static char __pyx_k_29[] = "\n    CloughTocher2DInterpolator(points, values, tol=1e-6)\n\n    Piecewise cubic, C1 smooth, curvature-minimizing interpolant in 2D. \n\n    .. versionadded:: 0.9\n\n    Parameters\n    ----------\n    points : ndarray of floats, shape (npoints, ndims)\n        Data point coordinates.\n    values : ndarray of float or complex, shape (npoints, ...)\n        Data values.\n    fill_value : float, optional\n        Value used to fill in for requested points outside of the\n        convex hull of the input points.  If not provided, then\n        the default is ``nan``.\n    tol : float, optional\n        Absolute/relative tolerance for gradient estimation.\n    maxiter : int, optional\n        Maximum number of iterations in gradient estimation.\n\n    Notes\n    -----\n    The interpolant is constructed by triangulating the input data\n    with Qhull [Qhull]_, and constructing a piecewise cubic\n    interpolating Bezier polynomial on each triangle, using a\n    Clough-Tocher scheme [CT]_.  The interpolant is guaranteed to be\n    continuously differentiable.\n\n    The gradients of the interpolant are chosen so that the curvature\n    of the interpolating surface is approximatively minimized. The\n    gradients necessary for this are estimated using the global\n    algorithm described in [Nielson83,Renka84]_.\n\n    References\n    ----------\n\n    .. [Qhull] http://www.qhull.org/\n\n    .. [CT] See, for example,\n       P. Alfeld,\n       ''A trivariate Clough-Tocher scheme for tetrahedral data''.\n       Computer Aided Geometric Design, 1, 169 (1984);\n       G. Farin,\n       ''Triangular Bernstein-Bezier patches''.\n       Computer Aided Geometric Design, 3, 83 (1986).\n\n    .. [Nielson83] G. Nielson,\n       ''A method for interpolating scattered data based upon a minimum norm\n       network''.\n       Math. Comp., 40, 253 (1983).\n\n    .. [Renka84] R. J. Renka and A. K. Cline.\n       ''A Triangle-based C1 interpolation method.'',\n       Rocky Mountain J. Math., 14, 223 (1984).\n\n    ";
static char __pyx_k_30[] = "CloughTocher2DInterpolator";
static char __pyx_k_31[] = "NDInterpolatorBase.__init__ (line 60)";
static char __pyx_k_32[] = "NDInterpolatorBase._check_init_shape (line 93)";
static char __pyx_k_33[] = "NDInterpolatorBase.__call__ (line 114)";
static char __pyx_k_34[] = "_ndim_coords_from_arrays (line 139)";
static char __pyx_k__B[] = "B";
static char __pyx_k__H[] = "H";
static char __pyx_k__I[] = "I";
static char __pyx_k__L[] = "L";
static char __pyx_k__O[] = "O";
static char __pyx_k__Q[] = "Q";
static char __pyx_k__T[] = "T";
static char __pyx_k__b[] = "b";
static char __pyx_k__d[] = "d";
static char __pyx_k__f[] = "f";
static char __pyx_k__g[] = "g";
static char __pyx_k__h[] = "h";
static char __pyx_k__i[] = "i";
static char __pyx_k__l[] = "l";
static char __pyx_k__q[] = "q";
static char __pyx_k__y[] = "y";
static char __pyx_k__Zd[] = "Zd";
static char __pyx_k__Zf[] = "Zf";
static char __pyx_k__Zg[] = "Zg";
static char __pyx_k__np[] = "np";
static char __pyx_k__xi[] = "xi";
static char __pyx_k__buf[] = "buf";
static char __pyx_k__eps[] = "eps";
static char __pyx_k__map[] = "map";
static char __pyx_k__nan[] = "nan";
static char __pyx_k__obj[] = "obj";
static char __pyx_k__tol[] = "tol";
static char __pyx_k__tri[] = "tri";
static char __pyx_k__base[] = "base";
static char __pyx_k__data[] = "data";
static char __pyx_k__grad[] = "grad";
static char __pyx_k__imag[] = "imag";
static char __pyx_k__ndim[] = "ndim";
static char __pyx_k__prod[] = "prod";
static char __pyx_k__real[] = "real";
static char __pyx_k__self[] = "self";
static char __pyx_k__warn[] = "warn";
static char __pyx_k__descr[] = "descr";
static char __pyx_k__dtype[] = "dtype";
static char __pyx_k__empty[] = "empty";
static char __pyx_k__finfo[] = "finfo";
static char __pyx_k__index[] = "index";
static char __pyx_k__names[] = "names";
static char __pyx_k__numpy[] = "numpy";
static char __pyx_k__qhull[] = "qhull";
static char __pyx_k__range[] = "range";
static char __pyx_k__shape[] = "shape";
static char __pyx_k__zeros[] = "zeros";
static char __pyx_k__astype[] = "astype";
static char __pyx_k__double[] = "double";
static char __pyx_k__fields[] = "fields";
static char __pyx_k__format[] = "format";
static char __pyx_k__object[] = "object";
static char __pyx_k__points[] = "points";
static char __pyx_k__values[] = "values";
static char __pyx_k__vertex[] = "vertex";
static char __pyx_k__xrange[] = "xrange";
static char __pyx_k__Warning[] = "Warning";
static char __pyx_k__complex[] = "complex";
static char __pyx_k__maxiter[] = "maxiter";
static char __pyx_k__npoints[] = "npoints";
static char __pyx_k__reshape[] = "reshape";
static char __pyx_k__strides[] = "strides";
static char __pyx_k__vertex2[] = "vertex2";
static char __pyx_k__Delaunay[] = "Delaunay";
static char __pyx_k____call__[] = "__call__";
static char __pyx_k____init__[] = "__init__";
static char __pyx_k____main__[] = "__main__";
static char __pyx_k____test__[] = "__test__";
static char __pyx_k__itemsize[] = "itemsize";
static char __pyx_k__readonly[] = "readonly";
static char __pyx_k__type_num[] = "type_num";
static char __pyx_k__vertices[] = "vertices";
static char __pyx_k__warnings[] = "warnings";
static char __pyx_k__byteorder[] = "byteorder";
static char __pyx_k__enumerate[] = "enumerate";
static char __pyx_k__neighbors[] = "neighbors";
static char __pyx_k__transform[] = "transform";
static char __pyx_k__transpose[] = "transpose";
static char __pyx_k__ValueError[] = "ValueError";
static char __pyx_k__asanyarray[] = "asanyarray";
static char __pyx_k__fill_value[] = "fill_value";
static char __pyx_k__is_complex[] = "is_complex";
static char __pyx_k__issubdtype[] = "issubdtype";
static char __pyx_k__suboffsets[] = "suboffsets";
static char __pyx_k__RuntimeError[] = "RuntimeError";
static char __pyx_k__values_shape[] = "values_shape";
static char __pyx_k__complexfloating[] = "complexfloating";
static char __pyx_k___evaluate_double[] = "_evaluate_double";
static char __pyx_k___check_call_shape[] = "_check_call_shape";
static char __pyx_k___check_init_shape[] = "_check_init_shape";
static char __pyx_k___evaluate_complex[] = "_evaluate_complex";
static char __pyx_k__ascontiguousarray[] = "ascontiguousarray";
static char __pyx_k__NDInterpolatorBase[] = "NDInterpolatorBase";
static PyObject *__pyx_kp_s_11;
static PyObject *__pyx_n_s_12;
static PyObject *__pyx_kp_s_13;
static PyObject *__pyx_n_s_14;
static PyObject *__pyx_kp_u_17;
static PyObject *__pyx_kp_u_18;
static PyObject *__pyx_kp_u_19;
static PyObject *__pyx_n_s_2;
static PyObject *__pyx_kp_u_20;
static PyObject *__pyx_kp_u_21;
static PyObject *__pyx_kp_u_22;
static PyObject *__pyx_n_s_24;
static PyObject *__pyx_n_s_25;
static PyObject *__pyx_kp_s_26;
static PyObject *__pyx_kp_s_27;
static PyObject *__pyx_n_s_28;
static PyObject *__pyx_kp_s_29;
static PyObject *__pyx_kp_s_3;
static PyObject *__pyx_n_s_30;
static PyObject *__pyx_kp_u_31;
static PyObject *__pyx_kp_u_32;
static PyObject *__pyx_kp_u_33;
static PyObject *__pyx_kp_u_34;
static PyObject *__pyx_kp_s_4;
static PyObject *__pyx_kp_s_5;
static PyObject *__pyx_kp_s_6;
static PyObject *__pyx_kp_s_7;
static PyObject *__pyx_kp_s_8;
static PyObject *__pyx_n_s__Delaunay;
static PyObject *__pyx_n_s__NDInterpolatorBase;
static PyObject *__pyx_n_s__RuntimeError;
static PyObject *__pyx_n_s__T;
static PyObject *__pyx_n_s__ValueError;
static PyObject *__pyx_n_s__Warning;
static PyObject *__pyx_n_s____call__;
static PyObject *__pyx_n_s____init__;
static PyObject *__pyx_n_s____main__;
static PyObject *__pyx_n_s____test__;
static PyObject *__pyx_n_s___check_call_shape;
static PyObject *__pyx_n_s___check_init_shape;
static PyObject *__pyx_n_s___evaluate_complex;
static PyObject *__pyx_n_s___evaluate_double;
static PyObject *__pyx_n_s__asanyarray;
static PyObject *__pyx_n_s__ascontiguousarray;
static PyObject *__pyx_n_s__astype;
static PyObject *__pyx_n_s__base;
static PyObject *__pyx_n_s__buf;
static PyObject *__pyx_n_s__byteorder;
static PyObject *__pyx_n_s__complex;
static PyObject *__pyx_n_s__complexfloating;
static PyObject *__pyx_n_s__data;
static PyObject *__pyx_n_s__descr;
static PyObject *__pyx_n_s__double;
static PyObject *__pyx_n_s__dtype;
static PyObject *__pyx_n_s__empty;
static PyObject *__pyx_n_s__enumerate;
static PyObject *__pyx_n_s__eps;
static PyObject *__pyx_n_s__fields;
static PyObject *__pyx_n_s__fill_value;
static PyObject *__pyx_n_s__finfo;
static PyObject *__pyx_n_s__format;
static PyObject *__pyx_n_s__grad;
static PyObject *__pyx_n_s__imag;
static PyObject *__pyx_n_s__index;
static PyObject *__pyx_n_s__is_complex;
static PyObject *__pyx_n_s__issubdtype;
static PyObject *__pyx_n_s__itemsize;
static PyObject *__pyx_n_s__map;
static PyObject *__pyx_n_s__maxiter;
static PyObject *__pyx_n_s__names;
static PyObject *__pyx_n_s__nan;
static PyObject *__pyx_n_s__ndim;
static PyObject *__pyx_n_s__neighbors;
static PyObject *__pyx_n_s__np;
static PyObject *__pyx_n_s__npoints;
static PyObject *__pyx_n_s__numpy;
static PyObject *__pyx_n_s__obj;
static PyObject *__pyx_n_s__object;
static PyObject *__pyx_n_s__points;
static PyObject *__pyx_n_s__prod;
static PyObject *__pyx_n_s__qhull;
static PyObject *__pyx_n_s__range;
static PyObject *__pyx_n_s__readonly;
static PyObject *__pyx_n_s__real;
static PyObject *__pyx_n_s__reshape;
static PyObject *__pyx_n_s__self;
static PyObject *__pyx_n_s__shape;
static PyObject *__pyx_n_s__strides;
static PyObject *__pyx_n_s__suboffsets;
static PyObject *__pyx_n_s__tol;
static PyObject *__pyx_n_s__transform;
static PyObject *__pyx_n_s__transpose;
static PyObject *__pyx_n_s__tri;
static PyObject *__pyx_n_s__type_num;
static PyObject *__pyx_n_s__values;
static PyObject *__pyx_n_s__values_shape;
static PyObject *__pyx_n_s__vertex;
static PyObject *__pyx_n_s__vertex2;
static PyObject *__pyx_n_s__vertices;
static PyObject *__pyx_n_s__warn;
static PyObject *__pyx_n_s__warnings;
static PyObject *__pyx_n_s__xi;
static PyObject *__pyx_n_s__xrange;
static PyObject *__pyx_n_s__y;
static PyObject *__pyx_n_s__zeros;
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_2;
static PyObject *__pyx_int_neg_1;
static PyObject *__pyx_int_15;
static PyObject *__pyx_int_100;
static PyObject *__pyx_int_400;
static PyObject *__pyx_k_1;
static PyObject *__pyx_k_9;
static PyObject *__pyx_k_10;
static PyObject *__pyx_k_15;
static PyObject *__pyx_k_16;



static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static char __pyx_doc_8interpnd_18NDInterpolatorBase___init__[] = "\n        Check shape of points and values arrays, and reshape values to\n        (npoints, nvalues).  Ensure the `points` and values arrays are\n        C-contiguous, and of correct type.\n        ";
static PyMethodDef __pyx_mdef_8interpnd_18NDInterpolatorBase___init__ = {__Pyx_NAMESTR("__init__"), (PyCFunction)__pyx_pf_8interpnd_18NDInterpolatorBase___init__, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(__pyx_doc_8interpnd_18NDInterpolatorBase___init__)};
static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_points = 0;
  PyObject *__pyx_v_values = 0;
  PyObject *__pyx_v_fill_value = 0;
  PyObject *__pyx_v_ndim = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  double __pyx_t_7;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__points,&__pyx_n_s__values,&__pyx_n_s__fill_value,&__pyx_n_s__ndim,0};
  __Pyx_RefNannySetupContext("__init__");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[5] = {0,0,0,0,0};
    values[3] = __pyx_k_1;
    values[4] = ((PyObject *)Py_None);
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
      case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__points);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 5, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  2:
      values[2] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__values);
      if (likely(values[2])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 5, 2); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  3:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__fill_value);
        if (unlikely(value)) { values[3] = value; kw_args--; }
      }
      case  4:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__ndim);
        if (unlikely(value)) { values[4] = value; kw_args--; }
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "__init__") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_points = values[1];
    __pyx_v_values = values[2];
    __pyx_v_fill_value = values[3];
    __pyx_v_ndim = values[4];
  } else {
    __pyx_v_fill_value = __pyx_k_1;
    __pyx_v_ndim = ((PyObject *)Py_None);
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  5:
      __pyx_v_ndim = PyTuple_GET_ITEM(__pyx_args, 4);
      case  4:
      __pyx_v_fill_value = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3:
      __pyx_v_values = PyTuple_GET_ITEM(__pyx_args, 2);
      __pyx_v_points = PyTuple_GET_ITEM(__pyx_args, 1);
      __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
      break;
      default: goto __pyx_L5_argtuple_error;
    }
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 5, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase.__init__");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF(__pyx_v_points);
  __Pyx_INCREF(__pyx_v_values);
  __Pyx_INCREF(__pyx_v_fill_value);
  __Pyx_INCREF(__pyx_v_ndim);

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s_2); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 66; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 66; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_points);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_points);
  __Pyx_GIVEREF(__pyx_v_points);
  __pyx_t_3 = PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 66; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_v_points);
  __pyx_v_points = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s___check_init_shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_points);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_points);
  __Pyx_GIVEREF(__pyx_v_points);
  __Pyx_INCREF(__pyx_v_values);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_v_values);
  __Pyx_GIVEREF(__pyx_v_values);
  __pyx_t_1 = PyDict_New(); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_1));
  if (PyDict_SetItem(__pyx_t_1, ((PyObject *)__pyx_n_s__ndim), __pyx_v_ndim) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = PyEval_CallObjectWithKeywords(__pyx_t_3, __pyx_t_2, ((PyObject *)__pyx_t_1)); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_1)); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__ascontiguousarray); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_points, __pyx_n_s__astype); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__double); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_4, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 70; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_v_points);
  __pyx_v_points = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__ascontiguousarray); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_values);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_values);
  __Pyx_GIVEREF(__pyx_v_values);
  __pyx_t_1 = PyObject_Call(__pyx_t_2, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_v_values);
  __pyx_v_values = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__shape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 73; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PySequence_GetSlice(__pyx_t_1, 1, PY_SSIZE_T_MAX); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 73; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__values_shape, __pyx_t_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 73; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__ndim); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 74; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyObject_RichCompare(__pyx_t_3, __pyx_int_1, Py_EQ); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 74; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_5 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 74; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_5) {

    
    __pyx_t_1 = PySlice_New(Py_None, Py_None, Py_None); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __Pyx_INCREF(Py_None);
    PyTuple_SET_ITEM(__pyx_t_3, 1, Py_None);
    __Pyx_GIVEREF(Py_None);
    __pyx_t_1 = 0;
    __pyx_t_1 = PyObject_GetItem(__pyx_v_values, __pyx_t_3); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__values, __pyx_t_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 75; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    goto __pyx_L6;
  }

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__ndim); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 76; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyObject_RichCompare(__pyx_t_1, __pyx_int_2, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 76; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_5 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 76; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_5) {

    
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__values, __pyx_v_values) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 77; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L6;
  }
   {

    
    __pyx_t_3 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__reshape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__shape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 80; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_4 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__prod); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 80; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__shape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 80; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_6 = PySequence_GetSlice(__pyx_t_1, 1, PY_SSIZE_T_MAX); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 80; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 80; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __pyx_t_6 = 0;
    __pyx_t_6 = PyObject_Call(__pyx_t_4, __pyx_t_1, NULL); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 80; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __pyx_t_2 = 0;
    __pyx_t_6 = 0;
    __pyx_t_6 = PyObject_Call(__pyx_t_3, __pyx_t_1, NULL); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__values, __pyx_t_6) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __pyx_L6:;

  
  __pyx_t_6 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = PyObject_GetAttr(__pyx_t_6, __pyx_n_s__issubdtype); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = PyObject_GetAttr(__pyx_t_6, __pyx_n_s__dtype); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_6, __pyx_n_s__complexfloating); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_t_3 = 0;
  __pyx_t_2 = 0;
  __pyx_t_2 = PyObject_Call(__pyx_t_1, __pyx_t_6, NULL); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__is_complex, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 83; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__is_complex); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_5 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 84; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_5) {

    
    __pyx_t_2 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__astype); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__complex); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;
    __pyx_t_1 = PyObject_Call(__pyx_t_6, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__values, __pyx_t_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 85; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 86; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_fill_value);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_fill_value);
    __Pyx_GIVEREF(__pyx_v_fill_value);
    __pyx_t_2 = PyObject_Call(((PyObject*)&PyComplex_Type), __pyx_t_1, NULL); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 86; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__fill_value, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 86; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    goto __pyx_L7;
  }
   {

    
    __pyx_t_2 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__astype); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__double); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __pyx_t_6 = 0;
    __pyx_t_6 = PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__values, __pyx_t_6) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 88; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

    
    __pyx_t_7 = __Pyx_PyObject_AsDouble(__pyx_v_fill_value); if (unlikely(__pyx_t_7 == ((double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 89; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_6 = PyFloat_FromDouble(__pyx_t_7); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 89; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__fill_value, __pyx_t_6) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 89; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __pyx_L7:;

  
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__points, __pyx_v_points) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 91; __pyx_clineno = __LINE__; goto __pyx_L1_error;}

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase.__init__");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF(__pyx_v_points);
  __Pyx_DECREF(__pyx_v_values);
  __Pyx_DECREF(__pyx_v_fill_value);
  __Pyx_DECREF(__pyx_v_ndim);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase__check_init_shape(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static char __pyx_doc_8interpnd_18NDInterpolatorBase__check_init_shape[] = "\n        Check shape of points and values arrays\n\n        ";
static PyMethodDef __pyx_mdef_8interpnd_18NDInterpolatorBase__check_init_shape = {__Pyx_NAMESTR("_check_init_shape"), (PyCFunction)__pyx_pf_8interpnd_18NDInterpolatorBase__check_init_shape, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(__pyx_doc_8interpnd_18NDInterpolatorBase__check_init_shape)};
static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase__check_init_shape(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_points = 0;
  PyObject *__pyx_v_values = 0;
  PyObject *__pyx_v_ndim = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  int __pyx_t_6;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__points,&__pyx_n_s__values,&__pyx_n_s__ndim,0};
  __Pyx_RefNannySetupContext("_check_init_shape");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[4] = {0,0,0,0};
    values[3] = ((PyObject *)Py_None);
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__points);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_check_init_shape", 0, 3, 4, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  2:
      values[2] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__values);
      if (likely(values[2])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_check_init_shape", 0, 3, 4, 2); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  3:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__ndim);
        if (unlikely(value)) { values[3] = value; kw_args--; }
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "_check_init_shape") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_points = values[1];
    __pyx_v_values = values[2];
    __pyx_v_ndim = values[3];
  } else {
    __pyx_v_ndim = ((PyObject *)Py_None);
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  4:
      __pyx_v_ndim = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3:
      __pyx_v_values = PyTuple_GET_ITEM(__pyx_args, 2);
      __pyx_v_points = PyTuple_GET_ITEM(__pyx_args, 1);
      __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
      break;
      default: goto __pyx_L5_argtuple_error;
    }
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("_check_init_shape", 0, 3, 4, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase._check_init_shape");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF(__pyx_v_points);
  __Pyx_INCREF(__pyx_v_values);
  __Pyx_INCREF(__pyx_v_ndim);

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_values, __pyx_n_s__shape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_points, __pyx_n_s__shape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyObject_RichCompare(__pyx_t_2, __pyx_t_3, Py_NE); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 99; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(((PyObject *)__pyx_kp_s_3));
    PyTuple_SET_ITEM(__pyx_t_1, 0, ((PyObject *)__pyx_kp_s_3));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_3));
    __pyx_t_3 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 99; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_Raise(__pyx_t_3, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 99; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_points, __pyx_n_s__ndim); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyObject_RichCompare(__pyx_t_3, __pyx_int_2, Py_NE); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 101; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(((PyObject *)__pyx_kp_s_4));
    PyTuple_SET_ITEM(__pyx_t_1, 0, ((PyObject *)__pyx_kp_s_4));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_4));
    __pyx_t_3 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 101; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_Raise(__pyx_t_3, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 101; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L7;
  }
  __pyx_L7:;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_points, __pyx_n_s__shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 102; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_3, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 102; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_RichCompare(__pyx_t_1, __pyx_int_2, Py_LT); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 102; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 102; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 103; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(((PyObject *)__pyx_kp_s_5));
    PyTuple_SET_ITEM(__pyx_t_3, 0, ((PyObject *)__pyx_kp_s_5));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_5));
    __pyx_t_1 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 103; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_Raise(__pyx_t_1, 0, 0);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 103; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L8;
  }
  __pyx_L8:;

  
  __pyx_t_4 = (__pyx_v_ndim != Py_None);
  if (__pyx_t_4) {
    __pyx_t_1 = PyObject_GetAttr(__pyx_v_points, __pyx_n_s__shape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 104; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_1, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 104; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyObject_RichCompare(__pyx_t_3, __pyx_v_ndim, Py_NE); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 104; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_5 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 104; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_6 = __pyx_t_5;
  } else {
    __pyx_t_6 = __pyx_t_4;
  }
  if (__pyx_t_6) {

    
    __pyx_t_1 = PyNumber_Remainder(((PyObject *)__pyx_kp_s_6), __pyx_v_ndim); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 106; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 105; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;
    __pyx_t_1 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_3, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 105; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_Raise(__pyx_t_1, 0, 0);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 105; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L9;
  }
  __pyx_L9:;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase._check_init_shape");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF(__pyx_v_points);
  __Pyx_DECREF(__pyx_v_values);
  __Pyx_DECREF(__pyx_v_ndim);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase__check_call_shape(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_18NDInterpolatorBase__check_call_shape = {__Pyx_NAMESTR("_check_call_shape"), (PyCFunction)__pyx_pf_8interpnd_18NDInterpolatorBase__check_call_shape, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase__check_call_shape(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_xi = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__xi,0};
  __Pyx_RefNannySetupContext("_check_call_shape");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[2] = {0,0};
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__xi);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_check_call_shape", 1, 2, 2, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "_check_call_shape") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_xi = values[1];
  } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
    goto __pyx_L5_argtuple_error;
  } else {
    __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
    __pyx_v_xi = PyTuple_GET_ITEM(__pyx_args, 1);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("_check_call_shape", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase._check_call_shape");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF(__pyx_v_xi);

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__asanyarray); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_xi);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_xi);
  __Pyx_GIVEREF(__pyx_v_xi);
  __pyx_t_3 = PyObject_Call(__pyx_t_2, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_v_xi);
  __pyx_v_xi = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_xi, __pyx_n_s__shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_3, -1, sizeof(long), PyInt_FromLong); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__points); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__shape); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyObject_RichCompare(__pyx_t_1, __pyx_t_3, Py_NE); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 111; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(((PyObject *)__pyx_kp_s_7));
    PyTuple_SET_ITEM(__pyx_t_2, 0, ((PyObject *)__pyx_kp_s_7));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_7));
    __pyx_t_3 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 111; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_Raise(__pyx_t_3, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 111; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_xi);
  __pyx_r = __pyx_v_xi;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase._check_call_shape");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF(__pyx_v_xi);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase___call__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static char __pyx_doc_8interpnd_18NDInterpolatorBase___call__[] = "\n        interpolator(xi)\n\n        Evaluate interpolator at given points.\n\n        Parameters\n        ----------\n        xi : ndarray of float, shape (..., ndim)\n            Points where to interpolate data at.\n\n        ";
static PyMethodDef __pyx_mdef_8interpnd_18NDInterpolatorBase___call__ = {__Pyx_NAMESTR("__call__"), (PyCFunction)__pyx_pf_8interpnd_18NDInterpolatorBase___call__, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(__pyx_doc_8interpnd_18NDInterpolatorBase___call__)};
static PyObject *__pyx_pf_8interpnd_18NDInterpolatorBase___call__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_xi = 0;
  PyObject *__pyx_v_shape;
  PyObject *__pyx_v_r;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__xi,0};
  __Pyx_RefNannySetupContext("__call__");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[2] = {0,0};
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__xi);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__call__", 1, 2, 2, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "__call__") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_xi = values[1];
  } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
    goto __pyx_L5_argtuple_error;
  } else {
    __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
    __pyx_v_xi = PyTuple_GET_ITEM(__pyx_args, 1);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__call__", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase.__call__");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF(__pyx_v_xi);
  __pyx_v_shape = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_r = Py_None; __Pyx_INCREF(Py_None);

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s_2); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_xi);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_xi);
  __Pyx_GIVEREF(__pyx_v_xi);
  __pyx_t_3 = PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_v_xi);
  __pyx_v_xi = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s___check_call_shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_xi);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_xi);
  __Pyx_GIVEREF(__pyx_v_xi);
  __pyx_t_1 = PyObject_Call(__pyx_t_3, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_v_xi);
  __pyx_v_xi = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__ascontiguousarray); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_xi, __pyx_n_s__astype); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__double); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  __pyx_t_4 = 0;
  __pyx_t_4 = PyObject_Call(__pyx_t_1, __pyx_t_3, NULL); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  __pyx_t_4 = 0;
  __pyx_t_4 = PyObject_Call(__pyx_t_2, __pyx_t_3, NULL); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_v_xi);
  __pyx_v_xi = __pyx_t_4;
  __pyx_t_4 = 0;

  
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_xi, __pyx_n_s__shape); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 129; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_v_shape);
  __pyx_v_shape = __pyx_t_4;
  __pyx_t_4 = 0;

  
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_xi, __pyx_n_s__reshape); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__prod); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PySequence_GetSlice(__pyx_v_shape, 0, -1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_2, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_shape, -1, sizeof(long), PyInt_FromLong); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = PyObject_Call(__pyx_t_4, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_v_xi);
  __pyx_v_xi = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__is_complex); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 132; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_5 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 132; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_5) {

    
    __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s___evaluate_complex); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 133; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 133; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_v_xi);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_xi);
    __Pyx_GIVEREF(__pyx_v_xi);
    __pyx_t_4 = PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 133; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_v_r);
    __pyx_v_r = __pyx_t_4;
    __pyx_t_4 = 0;
    goto __pyx_L6;
  }
   {

    
    __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s___evaluate_double); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 135; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 135; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_v_xi);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_xi);
    __Pyx_GIVEREF(__pyx_v_xi);
    __pyx_t_1 = PyObject_Call(__pyx_t_4, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 135; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_v_r);
    __pyx_v_r = __pyx_t_1;
    __pyx_t_1 = 0;
  }
  __pyx_L6:;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_r, __pyx_n_s__reshape); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PySequence_GetSlice(__pyx_v_shape, 0, -1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values_shape); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_1, __pyx_t_4, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("interpnd.NDInterpolatorBase.__call__");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(__pyx_v_shape);
  __Pyx_DECREF(__pyx_v_r);
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF(__pyx_v_xi);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd__ndim_coords_from_arrays(PyObject *__pyx_self, PyObject *__pyx_v_points); 
static char __pyx_doc_8interpnd__ndim_coords_from_arrays[] = "\n    Convert a tuple of coordinate arrays to a (..., ndim)-shaped array.\n\n    ";
static PyObject *__pyx_pf_8interpnd__ndim_coords_from_arrays(PyObject *__pyx_self, PyObject *__pyx_v_points) {
  PyObject *__pyx_v_p;
  PyObject *__pyx_v_j;
  PyObject *__pyx_v_item;
  PyObject *__pyx_r = NULL;
  int __pyx_t_1;
  int __pyx_t_2;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  Py_ssize_t __pyx_t_7;
  Py_ssize_t __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  __Pyx_RefNannySetupContext("_ndim_coords_from_arrays");
  __pyx_self = __pyx_self;
  __Pyx_INCREF(__pyx_v_points);
  __pyx_v_p = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_j = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_item = Py_None; __Pyx_INCREF(Py_None);

  
  __pyx_t_1 = PyObject_TypeCheck(__pyx_v_points, ((PyTypeObject *)((PyObject*)&PyTuple_Type))); 
  if (!__pyx_t_1) {
    __pyx_t_2 = PyObject_TypeCheck(__pyx_v_points, ((PyTypeObject *)((PyObject*)&PyList_Type))); 
    __pyx_t_3 = __pyx_t_2;
  } else {
    __pyx_t_3 = __pyx_t_1;
  }
  if (__pyx_t_3) {
    __pyx_t_1 = __Pyx_PyObject_IsTrue(__pyx_v_points); if (unlikely(__pyx_t_1 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 144; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    if (__pyx_t_1) {
      __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_points, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 144; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_2 = PyObject_TypeCheck(__pyx_t_4, ((PyTypeObject *)((PyObject*)__pyx_ptype_5numpy_ndarray))); 
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_5 = __pyx_t_2;
    } else {
      __pyx_t_5 = __pyx_t_1;
    }
    __pyx_t_1 = __pyx_t_5;
  } else {
    __pyx_t_1 = __pyx_t_3;
  }
  if (__pyx_t_1) {

    
    __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_6 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__asanyarray); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __Pyx_INCREF(__pyx_v_points);
    PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_v_points);
    __Pyx_GIVEREF(__pyx_v_points);
    __pyx_t_6 = 0;
    __pyx_t_6 = PyObject_Call(__pyx_builtin_map, __pyx_t_4, NULL); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_v_p);
    __pyx_v_p = __pyx_t_6;
    __pyx_t_6 = 0;

    
    __pyx_t_8 = PyObject_Length(__pyx_v_p); if (unlikely(__pyx_t_8 == -1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_6 = PyInt_FromSsize_t(__pyx_t_8); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_INCREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __pyx_t_6 = 0;
    __pyx_t_6 = PyObject_Call(__pyx_builtin_xrange, __pyx_t_4, NULL); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (PyList_CheckExact(__pyx_t_6) || PyTuple_CheckExact(__pyx_t_6)) {
      __pyx_t_7 = 0; __pyx_t_4 = __pyx_t_6; __Pyx_INCREF(__pyx_t_4);
    } else {
      __pyx_t_7 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_t_6); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    for (;;) {
      if (likely(PyList_CheckExact(__pyx_t_4))) {
        if (__pyx_t_7 >= PyList_GET_SIZE(__pyx_t_4)) break;
        __pyx_t_6 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_7); __Pyx_INCREF(__pyx_t_6); __pyx_t_7++;
      } else if (likely(PyTuple_CheckExact(__pyx_t_4))) {
        if (__pyx_t_7 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
        __pyx_t_6 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_7); __Pyx_INCREF(__pyx_t_6); __pyx_t_7++;
      } else {
        __pyx_t_6 = PyIter_Next(__pyx_t_4);
        if (!__pyx_t_6) {
          if (unlikely(PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
          break;
        }
        __Pyx_GOTREF(__pyx_t_6);
      }
      __Pyx_DECREF(__pyx_v_j);
      __pyx_v_j = __pyx_t_6;
      __pyx_t_6 = 0;

      
      __pyx_t_6 = PyObject_GetItem(__pyx_v_p, __pyx_v_j); if (!__pyx_t_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_9 = PyObject_GetAttr(__pyx_t_6, __pyx_n_s__shape); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = __Pyx_GetItemInt(__pyx_v_p, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_10 = PyObject_GetAttr(__pyx_t_6, __pyx_n_s__shape); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = PyObject_RichCompare(__pyx_t_9, __pyx_t_10, Py_NE); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_t_1 = __Pyx_PyObject_IsTrue(__pyx_t_6); if (unlikely(__pyx_t_1 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (__pyx_t_1) {

        
        __pyx_t_6 = PyTuple_New(1); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_INCREF(((PyObject *)__pyx_kp_s_8));
        PyTuple_SET_ITEM(__pyx_t_6, 0, ((PyObject *)__pyx_kp_s_8));
        __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_8));
        __pyx_t_10 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_6, NULL); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_10);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_Raise(__pyx_t_10, 0, 0);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        goto __pyx_L8;
      }
      __pyx_L8:;
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

    
    __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_10 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__empty); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_10);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_p, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_6 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__shape); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_7 = PyObject_Length(__pyx_v_points); if (unlikely(__pyx_t_7 == -1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_4 = PyInt_FromSsize_t(__pyx_t_7); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_9 = PyTuple_New(1); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_t_4 = PyNumber_Add(__pyx_t_6, __pyx_t_9); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = PyTuple_New(1); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_t_4 = PyDict_New(); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(((PyObject *)__pyx_t_4));
    if (PyDict_SetItem(__pyx_t_4, ((PyObject *)__pyx_n_s__dtype), ((PyObject *)((PyObject*)&PyFloat_Type))) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_6 = PyEval_CallObjectWithKeywords(__pyx_t_10, __pyx_t_9, ((PyObject *)__pyx_t_4)); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(((PyObject *)__pyx_t_4)); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_v_points);
    __pyx_v_points = __pyx_t_6;
    __pyx_t_6 = 0;

    
    __Pyx_INCREF(__pyx_int_0);
    __pyx_t_6 = __pyx_int_0;
    if (PyList_CheckExact(__pyx_v_p) || PyTuple_CheckExact(__pyx_v_p)) {
      __pyx_t_7 = 0; __pyx_t_4 = __pyx_v_p; __Pyx_INCREF(__pyx_t_4);
    } else {
      __pyx_t_7 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_v_p); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 150; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_4);
    }
    for (;;) {
      if (likely(PyList_CheckExact(__pyx_t_4))) {
        if (__pyx_t_7 >= PyList_GET_SIZE(__pyx_t_4)) break;
        __pyx_t_9 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_7); __Pyx_INCREF(__pyx_t_9); __pyx_t_7++;
      } else if (likely(PyTuple_CheckExact(__pyx_t_4))) {
        if (__pyx_t_7 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
        __pyx_t_9 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_7); __Pyx_INCREF(__pyx_t_9); __pyx_t_7++;
      } else {
        __pyx_t_9 = PyIter_Next(__pyx_t_4);
        if (!__pyx_t_9) {
          if (unlikely(PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 150; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
          break;
        }
        __Pyx_GOTREF(__pyx_t_9);
      }
      __Pyx_DECREF(__pyx_v_item);
      __pyx_v_item = __pyx_t_9;
      __pyx_t_9 = 0;
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_v_j);
      __pyx_v_j = __pyx_t_6;
      __pyx_t_9 = PyNumber_Add(__pyx_t_6, __pyx_int_1); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 150; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_6);
      __pyx_t_6 = __pyx_t_9;
      __pyx_t_9 = 0;

      
      __pyx_t_9 = PyTuple_New(2); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 151; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_INCREF(Py_Ellipsis);
      PyTuple_SET_ITEM(__pyx_t_9, 0, Py_Ellipsis);
      __Pyx_GIVEREF(Py_Ellipsis);
      __Pyx_INCREF(__pyx_v_j);
      PyTuple_SET_ITEM(__pyx_t_9, 1, __pyx_v_j);
      __Pyx_GIVEREF(__pyx_v_j);
      if (PyObject_SetItem(__pyx_v_points, __pyx_t_9, __pyx_v_item) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 151; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L5;
  }
   {

    
    __pyx_t_6 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_4 = PyObject_GetAttr(__pyx_t_6, __pyx_n_s__asanyarray); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = PyTuple_New(1); if (unlikely(!__pyx_t_6)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_INCREF(__pyx_v_points);
    PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_v_points);
    __Pyx_GIVEREF(__pyx_v_points);
    __pyx_t_9 = PyObject_Call(__pyx_t_4, __pyx_t_6, NULL); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 153; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_v_points);
    __pyx_v_points = __pyx_t_9;
    __pyx_t_9 = 0;
  }
  __pyx_L5:;

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_points);
  __pyx_r = __pyx_v_points;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("interpnd._ndim_coords_from_arrays");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(__pyx_v_p);
  __Pyx_DECREF(__pyx_v_j);
  __Pyx_DECREF(__pyx_v_item);
  __Pyx_DECREF(__pyx_v_points);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_20LinearNDInterpolator___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_20LinearNDInterpolator___init__ = {__Pyx_NAMESTR("__init__"), (PyCFunction)__pyx_pf_8interpnd_20LinearNDInterpolator___init__, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_20LinearNDInterpolator___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_points = 0;
  PyObject *__pyx_v_values = 0;
  PyObject *__pyx_v_fill_value = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__points,&__pyx_n_s__values,&__pyx_n_s__fill_value,0};
  __Pyx_RefNannySetupContext("__init__");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[4] = {0,0,0,0};
    values[3] = __pyx_k_9;
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__points);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 4, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  2:
      values[2] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__values);
      if (likely(values[2])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 4, 2); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  3:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__fill_value);
        if (unlikely(value)) { values[3] = value; kw_args--; }
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "__init__") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_points = values[1];
    __pyx_v_values = values[2];
    __pyx_v_fill_value = values[3];
  } else {
    __pyx_v_fill_value = __pyx_k_9;
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  4:
      __pyx_v_fill_value = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3:
      __pyx_v_values = PyTuple_GET_ITEM(__pyx_args, 2);
      __pyx_v_points = PyTuple_GET_ITEM(__pyx_args, 1);
      __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
      break;
      default: goto __pyx_L5_argtuple_error;
    }
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 4, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.LinearNDInterpolator.__init__");
  return NULL;
  __pyx_L4_argument_unpacking_done:;

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 192; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s____init__); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 192; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 192; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_self);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_self);
  __Pyx_GIVEREF(__pyx_v_self);
  __Pyx_INCREF(__pyx_v_points);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_v_points);
  __Pyx_GIVEREF(__pyx_v_points);
  __Pyx_INCREF(__pyx_v_values);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_v_values);
  __Pyx_GIVEREF(__pyx_v_values);
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 192; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_n_s__fill_value), __pyx_v_fill_value) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 192; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = PyEval_CallObjectWithKeywords(__pyx_t_2, __pyx_t_1, ((PyObject *)__pyx_t_3)); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 192; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__qhull); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__Delaunay); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_v_points);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_v_points);
  __Pyx_GIVEREF(__pyx_v_points);
  __pyx_t_1 = PyObject_Call(__pyx_t_3, __pyx_t_4, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__tri, __pyx_t_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 193; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("interpnd.LinearNDInterpolator.__init__");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_20LinearNDInterpolator__evaluate_double(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_20LinearNDInterpolator__evaluate_double = {__Pyx_NAMESTR("_evaluate_double"), (PyCFunction)__pyx_pf_8interpnd_20LinearNDInterpolator__evaluate_double, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_20LinearNDInterpolator__evaluate_double(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyArrayObject *__pyx_v_xi = 0;
  PyArrayObject *__pyx_v_values = 0;
  PyArrayObject *__pyx_v_out;
  PyArrayObject *__pyx_v_points = 0;
  PyArrayObject *__pyx_v_vertices = 0;
  double __pyx_v_c[NPY_MAXDIMS];
  double __pyx_v_fill_value;
  int __pyx_v_i;
  int __pyx_v_j;
  int __pyx_v_k;
  int __pyx_v_m;
  int __pyx_v_ndim;
  int __pyx_v_isimplex;
  int __pyx_v_start;
  int __pyx_v_nvalues;
  __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_info;
  PyObject *__pyx_v_eps;
  Py_buffer __pyx_bstruct_xi;
  Py_ssize_t __pyx_bstride_0_xi = 0;
  Py_ssize_t __pyx_bstride_1_xi = 0;
  Py_ssize_t __pyx_bshape_0_xi = 0;
  Py_ssize_t __pyx_bshape_1_xi = 0;
  Py_buffer __pyx_bstruct_vertices;
  Py_ssize_t __pyx_bstride_0_vertices = 0;
  Py_ssize_t __pyx_bstride_1_vertices = 0;
  Py_ssize_t __pyx_bshape_0_vertices = 0;
  Py_ssize_t __pyx_bshape_1_vertices = 0;
  Py_buffer __pyx_bstruct_points;
  Py_ssize_t __pyx_bstride_0_points = 0;
  Py_ssize_t __pyx_bstride_1_points = 0;
  Py_ssize_t __pyx_bshape_0_points = 0;
  Py_ssize_t __pyx_bshape_1_points = 0;
  Py_buffer __pyx_bstruct_values;
  Py_ssize_t __pyx_bstride_0_values = 0;
  Py_ssize_t __pyx_bstride_1_values = 0;
  Py_ssize_t __pyx_bshape_0_values = 0;
  Py_ssize_t __pyx_bshape_1_values = 0;
  Py_buffer __pyx_bstruct_out;
  Py_ssize_t __pyx_bstride_0_out = 0;
  Py_ssize_t __pyx_bstride_1_out = 0;
  Py_ssize_t __pyx_bshape_0_out = 0;
  Py_ssize_t __pyx_bshape_1_out = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyArrayObject *__pyx_t_2 = NULL;
  PyArrayObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyArrayObject *__pyx_t_5 = NULL;
  double __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyArrayObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  npy_intp __pyx_t_15;
  int __pyx_t_16;
  int __pyx_t_17;
  int __pyx_t_18;
  int __pyx_t_19;
  int __pyx_t_20;
  int __pyx_t_21;
  int __pyx_t_22;
  long __pyx_t_23;
  int __pyx_t_24;
  int __pyx_t_25;
  int __pyx_t_26;
  int __pyx_t_27;
  int __pyx_t_28;
  int __pyx_t_29;
  int __pyx_t_30;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__xi,0};
  __Pyx_RefNannySetupContext("_evaluate_double");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[2] = {0,0};
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__xi);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_evaluate_double", 1, 2, 2, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "_evaluate_double") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_xi = ((PyArrayObject *)values[1]);
  } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
    goto __pyx_L5_argtuple_error;
  } else {
    __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
    __pyx_v_xi = ((PyArrayObject *)PyTuple_GET_ITEM(__pyx_args, 1));
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("_evaluate_double", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.LinearNDInterpolator._evaluate_double");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF((PyObject *)__pyx_v_xi);
  __pyx_v_out = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_eps = Py_None; __Pyx_INCREF(Py_None);
  __pyx_bstruct_values.buf = NULL;
  __pyx_bstruct_out.buf = NULL;
  __pyx_bstruct_points.buf = NULL;
  __pyx_bstruct_vertices.buf = NULL;
  __pyx_bstruct_xi.buf = NULL;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_xi), __pyx_ptype_5numpy_ndarray, 1, "xi", 0))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_xi, (PyObject*)__pyx_v_xi, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_bstride_0_xi = __pyx_bstruct_xi.strides[0]; __pyx_bstride_1_xi = __pyx_bstruct_xi.strides[1];
  __pyx_bshape_0_xi = __pyx_bstruct_xi.shape[0]; __pyx_bshape_1_xi = __pyx_bstruct_xi.shape[1];

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_2 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_values, (PyObject*)__pyx_t_2, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_values = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_values.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 197; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_values = __pyx_bstruct_values.strides[0]; __pyx_bstride_1_values = __pyx_bstruct_values.strides[1];
      __pyx_bshape_0_values = __pyx_bstruct_values.shape[0]; __pyx_bshape_1_values = __pyx_bstruct_values.shape[1];
    }
  }
  __pyx_t_2 = 0;
  __pyx_v_values = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__points); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 199; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 199; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_3 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_points, (PyObject*)__pyx_t_3, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_points = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_points.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 199; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_points = __pyx_bstruct_points.strides[0]; __pyx_bstride_1_points = __pyx_bstruct_points.strides[1];
      __pyx_bshape_0_points = __pyx_bstruct_points.shape[0]; __pyx_bshape_1_points = __pyx_bstruct_points.shape[1];
    }
  }
  __pyx_t_3 = 0;
  __pyx_v_points = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__vertices); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (!(likely(((__pyx_t_4) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_4, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_5 = ((PyArrayObject *)__pyx_t_4);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_vertices, (PyObject*)__pyx_t_5, &__Pyx_TypeInfo_nn_npy_int, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_vertices = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_vertices.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_vertices = __pyx_bstruct_vertices.strides[0]; __pyx_bstride_1_vertices = __pyx_bstruct_vertices.strides[1];
      __pyx_bshape_0_vertices = __pyx_bstruct_vertices.shape[0]; __pyx_bshape_1_vertices = __pyx_bstruct_vertices.shape[1];
    }
  }
  __pyx_t_5 = 0;
  __pyx_v_vertices = ((PyArrayObject *)__pyx_t_4);
  __pyx_t_4 = 0;

  
  __pyx_v_ndim = (__pyx_v_xi->dimensions[1]);

  
  __pyx_v_start = 0;

  
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__fill_value); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 208; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = __pyx_PyFloat_AsDouble(__pyx_t_4); if (unlikely((__pyx_t_6 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 208; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_fill_value = __pyx_t_6;

  
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 210; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_v_info = __pyx_f_5scipy_7spatial_5qhull__get_delaunay_info(__pyx_t_4, 1, 0);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__zeros); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyInt_to_py_npy_intp((__pyx_v_xi->dimensions[0])); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = PyObject_GetAttr(__pyx_t_7, __pyx_n_s__shape); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_8, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyTuple_New(2); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  __pyx_t_4 = 0;
  __pyx_t_7 = 0;
  __pyx_t_7 = PyTuple_New(1); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = PyDict_New(); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_8));
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__double); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_8, ((PyObject *)__pyx_n_s__dtype), __pyx_t_9) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyEval_CallObjectWithKeywords(__pyx_t_1, __pyx_t_7, ((PyObject *)__pyx_t_8)); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_8)); __pyx_t_8 = 0;
  if (!(likely(((__pyx_t_9) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_9, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_10 = ((PyArrayObject *)__pyx_t_9);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
    __pyx_t_11 = __Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_t_10, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES| PyBUF_WRITABLE, 2, 0, __pyx_stack);
    if (unlikely(__pyx_t_11 < 0)) {
      PyErr_Fetch(&__pyx_t_12, &__pyx_t_13, &__pyx_t_14);
      if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_v_out, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES| PyBUF_WRITABLE, 2, 0, __pyx_stack) == -1)) {
        Py_XDECREF(__pyx_t_12); Py_XDECREF(__pyx_t_13); Py_XDECREF(__pyx_t_14);
        __Pyx_RaiseBufferFallbackError();
      } else {
        PyErr_Restore(__pyx_t_12, __pyx_t_13, __pyx_t_14);
      }
    }
    __pyx_bstride_0_out = __pyx_bstruct_out.strides[0]; __pyx_bstride_1_out = __pyx_bstruct_out.strides[1];
    __pyx_bshape_0_out = __pyx_bstruct_out.shape[0]; __pyx_bshape_1_out = __pyx_bstruct_out.shape[1];
    if (unlikely(__pyx_t_11 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_t_10 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_v_out));
  __pyx_v_out = ((PyArrayObject *)__pyx_t_9);
  __pyx_t_9 = 0;

  
  __pyx_v_nvalues = (__pyx_v_out->dimensions[1]);

  
  __pyx_t_9 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_8 = PyObject_GetAttr(__pyx_t_9, __pyx_n_s__finfo); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_7 = PyObject_GetAttr(__pyx_t_9, __pyx_n_s__double); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyTuple_New(1); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  __pyx_t_7 = 0;
  __pyx_t_7 = PyObject_Call(__pyx_t_8, __pyx_t_9, NULL); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_7, __pyx_n_s__eps); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = PyNumber_Multiply(__pyx_t_9, __pyx_int_100); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_v_eps);
  __pyx_v_eps = __pyx_t_7;
  __pyx_t_7 = 0;

  
  { PyThreadState *_save;
    Py_UNBLOCK_THREADS
     {

      
      __pyx_t_15 = (__pyx_v_xi->dimensions[0]);
      for (__pyx_t_11 = 0; __pyx_t_11 < __pyx_t_15; __pyx_t_11+=1) {
        __pyx_v_i = __pyx_t_11;

        
        __pyx_t_6 = __pyx_PyFloat_AsDouble(__pyx_v_eps); if (unlikely((__pyx_t_6 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 224; __pyx_clineno = __LINE__; goto __pyx_L7;}
        __pyx_v_isimplex = __pyx_f_5scipy_7spatial_5qhull__find_simplex(__pyx_v_info, __pyx_v_c, (((double *)__pyx_v_xi->data) + (__pyx_v_i * __pyx_v_ndim)), (&__pyx_v_start), __pyx_t_6);

        
        __pyx_t_16 = (__pyx_v_isimplex == -1);
        if (__pyx_t_16) {

          
          __pyx_t_17 = __pyx_v_nvalues;
          for (__pyx_t_18 = 0; __pyx_t_18 < __pyx_t_17; __pyx_t_18+=1) {
            __pyx_v_k = __pyx_t_18;

            
            __pyx_t_19 = __pyx_v_i;
            __pyx_t_20 = __pyx_v_k;
            if (__pyx_t_19 < 0) __pyx_t_19 += __pyx_bshape_0_out;
            if (__pyx_t_20 < 0) __pyx_t_20 += __pyx_bshape_1_out;
            *__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_out.buf, __pyx_t_19, __pyx_bstride_0_out, __pyx_t_20, __pyx_bstride_1_out) = __pyx_v_fill_value;
          }

          
          goto __pyx_L9_continue;
          goto __pyx_L11;
        }
        __pyx_L11:;

        
        __pyx_t_17 = __pyx_v_nvalues;
        for (__pyx_t_18 = 0; __pyx_t_18 < __pyx_t_17; __pyx_t_18+=1) {
          __pyx_v_k = __pyx_t_18;

          
          __pyx_t_21 = __pyx_v_i;
          __pyx_t_22 = __pyx_v_k;
          if (__pyx_t_21 < 0) __pyx_t_21 += __pyx_bshape_0_out;
          if (__pyx_t_22 < 0) __pyx_t_22 += __pyx_bshape_1_out;
          *__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_out.buf, __pyx_t_21, __pyx_bstride_0_out, __pyx_t_22, __pyx_bstride_1_out) = 0;
        }

        
        __pyx_t_23 = (__pyx_v_ndim + 1);
        for (__pyx_t_17 = 0; __pyx_t_17 < __pyx_t_23; __pyx_t_17+=1) {
          __pyx_v_j = __pyx_t_17;

          
          __pyx_t_18 = __pyx_v_nvalues;
          for (__pyx_t_24 = 0; __pyx_t_24 < __pyx_t_18; __pyx_t_24+=1) {
            __pyx_v_k = __pyx_t_24;

            
            __pyx_t_25 = __pyx_v_isimplex;
            __pyx_t_26 = __pyx_v_j;
            if (__pyx_t_25 < 0) __pyx_t_25 += __pyx_bshape_0_vertices;
            if (__pyx_t_26 < 0) __pyx_t_26 += __pyx_bshape_1_vertices;
            __pyx_v_m = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_25, __pyx_bstride_0_vertices, __pyx_t_26, __pyx_bstride_1_vertices));

            
            __pyx_t_27 = __pyx_v_m;
            __pyx_t_28 = __pyx_v_k;
            if (__pyx_t_27 < 0) __pyx_t_27 += __pyx_bshape_0_values;
            if (__pyx_t_28 < 0) __pyx_t_28 += __pyx_bshape_1_values;
            __pyx_t_29 = __pyx_v_i;
            __pyx_t_30 = __pyx_v_k;
            if (__pyx_t_29 < 0) __pyx_t_29 += __pyx_bshape_0_out;
            if (__pyx_t_30 < 0) __pyx_t_30 += __pyx_bshape_1_out;
            *__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_out.buf, __pyx_t_29, __pyx_bstride_0_out, __pyx_t_30, __pyx_bstride_1_out) += ((__pyx_v_c[__pyx_v_j]) * (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_values.buf, __pyx_t_27, __pyx_bstride_0_values, __pyx_t_28, __pyx_bstride_1_values)));
          }
        }
        __pyx_L9_continue:;
      }
    }
     {
      int __pyx_why;
      __pyx_why = 0; goto __pyx_L8;
      __pyx_L7: __pyx_why = 4; goto __pyx_L8;
      __pyx_L8:;

      
      Py_BLOCK_THREADS
      switch (__pyx_why) {
        case 4: goto __pyx_L1_error;
      }
    }
  }

  
  free(((void *)__pyx_v_info));

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(((PyObject *)__pyx_v_out));
  __pyx_r = ((PyObject *)__pyx_v_out);
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  { PyObject *__pyx_type, *__pyx_value, *__pyx_tb;
    __Pyx_ErrFetch(&__pyx_type, &__pyx_value, &__pyx_tb);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
  __Pyx_ErrRestore(__pyx_type, __pyx_value, __pyx_tb);}
  __Pyx_AddTraceback("interpnd.LinearNDInterpolator._evaluate_double");
  __pyx_r = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
  __pyx_L2:;
  __Pyx_XDECREF((PyObject *)__pyx_v_values);
  __Pyx_DECREF((PyObject *)__pyx_v_out);
  __Pyx_XDECREF((PyObject *)__pyx_v_points);
  __Pyx_XDECREF((PyObject *)__pyx_v_vertices);
  __Pyx_DECREF(__pyx_v_eps);
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF((PyObject *)__pyx_v_xi);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_20LinearNDInterpolator__evaluate_complex(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_20LinearNDInterpolator__evaluate_complex = {__Pyx_NAMESTR("_evaluate_complex"), (PyCFunction)__pyx_pf_8interpnd_20LinearNDInterpolator__evaluate_complex, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_20LinearNDInterpolator__evaluate_complex(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyArrayObject *__pyx_v_xi = 0;
  PyArrayObject *__pyx_v_values = 0;
  PyArrayObject *__pyx_v_out;
  PyArrayObject *__pyx_v_points = 0;
  PyArrayObject *__pyx_v_vertices = 0;
  double __pyx_v_c[NPY_MAXDIMS];
  __pyx_t_double_complex __pyx_v_fill_value;
  int __pyx_v_i;
  int __pyx_v_j;
  int __pyx_v_k;
  int __pyx_v_m;
  int __pyx_v_ndim;
  int __pyx_v_isimplex;
  int __pyx_v_start;
  int __pyx_v_nvalues;
  __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_info;
  PyObject *__pyx_v_eps;
  Py_buffer __pyx_bstruct_xi;
  Py_ssize_t __pyx_bstride_0_xi = 0;
  Py_ssize_t __pyx_bstride_1_xi = 0;
  Py_ssize_t __pyx_bshape_0_xi = 0;
  Py_ssize_t __pyx_bshape_1_xi = 0;
  Py_buffer __pyx_bstruct_vertices;
  Py_ssize_t __pyx_bstride_0_vertices = 0;
  Py_ssize_t __pyx_bstride_1_vertices = 0;
  Py_ssize_t __pyx_bshape_0_vertices = 0;
  Py_ssize_t __pyx_bshape_1_vertices = 0;
  Py_buffer __pyx_bstruct_points;
  Py_ssize_t __pyx_bstride_0_points = 0;
  Py_ssize_t __pyx_bstride_1_points = 0;
  Py_ssize_t __pyx_bshape_0_points = 0;
  Py_ssize_t __pyx_bshape_1_points = 0;
  Py_buffer __pyx_bstruct_values;
  Py_ssize_t __pyx_bstride_0_values = 0;
  Py_ssize_t __pyx_bstride_1_values = 0;
  Py_ssize_t __pyx_bshape_0_values = 0;
  Py_ssize_t __pyx_bshape_1_values = 0;
  Py_buffer __pyx_bstruct_out;
  Py_ssize_t __pyx_bstride_0_out = 0;
  Py_ssize_t __pyx_bstride_1_out = 0;
  Py_ssize_t __pyx_bshape_0_out = 0;
  Py_ssize_t __pyx_bshape_1_out = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyArrayObject *__pyx_t_2 = NULL;
  PyArrayObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyArrayObject *__pyx_t_5 = NULL;
  __pyx_t_double_complex __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyArrayObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  npy_intp __pyx_t_15;
  double __pyx_t_16;
  int __pyx_t_17;
  int __pyx_t_18;
  int __pyx_t_19;
  int __pyx_t_20;
  int __pyx_t_21;
  int __pyx_t_22;
  int __pyx_t_23;
  int __pyx_t_24;
  int __pyx_t_25;
  int __pyx_t_26;
  int __pyx_t_27;
  long __pyx_t_28;
  int __pyx_t_29;
  int __pyx_t_30;
  int __pyx_t_31;
  int __pyx_t_32;
  int __pyx_t_33;
  int __pyx_t_34;
  int __pyx_t_35;
  int __pyx_t_36;
  int __pyx_t_37;
  int __pyx_t_38;
  int __pyx_t_39;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__xi,0};
  __Pyx_RefNannySetupContext("_evaluate_complex");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[2] = {0,0};
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__xi);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_evaluate_complex", 1, 2, 2, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "_evaluate_complex") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_xi = ((PyArrayObject *)values[1]);
  } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
    goto __pyx_L5_argtuple_error;
  } else {
    __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
    __pyx_v_xi = ((PyArrayObject *)PyTuple_GET_ITEM(__pyx_args, 1));
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("_evaluate_complex", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.LinearNDInterpolator._evaluate_complex");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF((PyObject *)__pyx_v_xi);
  __pyx_v_out = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_eps = Py_None; __Pyx_INCREF(Py_None);
  __pyx_bstruct_values.buf = NULL;
  __pyx_bstruct_out.buf = NULL;
  __pyx_bstruct_points.buf = NULL;
  __pyx_bstruct_vertices.buf = NULL;
  __pyx_bstruct_xi.buf = NULL;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_xi), __pyx_ptype_5numpy_ndarray, 1, "xi", 0))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_xi, (PyObject*)__pyx_v_xi, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_bstride_0_xi = __pyx_bstruct_xi.strides[0]; __pyx_bstride_1_xi = __pyx_bstruct_xi.strides[1];
  __pyx_bshape_0_xi = __pyx_bstruct_xi.shape[0]; __pyx_bshape_1_xi = __pyx_bstruct_xi.shape[1];

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 246; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 246; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_2 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[2];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_values, (PyObject*)__pyx_t_2, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_values = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_values.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 246; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_values = __pyx_bstruct_values.strides[0]; __pyx_bstride_1_values = __pyx_bstruct_values.strides[1];
      __pyx_bshape_0_values = __pyx_bstruct_values.shape[0]; __pyx_bshape_1_values = __pyx_bstruct_values.shape[1];
    }
  }
  __pyx_t_2 = 0;
  __pyx_v_values = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__points); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 248; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 248; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_3 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_points, (PyObject*)__pyx_t_3, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_points = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_points.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 248; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_points = __pyx_bstruct_points.strides[0]; __pyx_bstride_1_points = __pyx_bstruct_points.strides[1];
      __pyx_bshape_0_points = __pyx_bstruct_points.shape[0]; __pyx_bshape_1_points = __pyx_bstruct_points.shape[1];
    }
  }
  __pyx_t_3 = 0;
  __pyx_v_points = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__vertices); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (!(likely(((__pyx_t_4) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_4, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_5 = ((PyArrayObject *)__pyx_t_4);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_vertices, (PyObject*)__pyx_t_5, &__Pyx_TypeInfo_nn_npy_int, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_vertices = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_vertices.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_vertices = __pyx_bstruct_vertices.strides[0]; __pyx_bstride_1_vertices = __pyx_bstruct_vertices.strides[1];
      __pyx_bshape_0_vertices = __pyx_bstruct_vertices.shape[0]; __pyx_bshape_1_vertices = __pyx_bstruct_vertices.shape[1];
    }
  }
  __pyx_t_5 = 0;
  __pyx_v_vertices = ((PyArrayObject *)__pyx_t_4);
  __pyx_t_4 = 0;

  
  __pyx_v_ndim = (__pyx_v_xi->dimensions[1]);

  
  __pyx_v_start = 0;

  
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__fill_value); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 257; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = __Pyx_PyComplex_As___pyx_t_double_complex(__pyx_t_4); if (unlikely(PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 257; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_fill_value = __pyx_t_6;

  
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 259; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_v_info = __pyx_f_5scipy_7spatial_5qhull__get_delaunay_info(__pyx_t_4, 1, 0);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__zeros); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyInt_to_py_npy_intp((__pyx_v_xi->dimensions[0])); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = PyObject_GetAttr(__pyx_t_7, __pyx_n_s__shape); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_8, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyTuple_New(2); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  __pyx_t_4 = 0;
  __pyx_t_7 = 0;
  __pyx_t_7 = PyTuple_New(1); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = PyDict_New(); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_8));
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__complex); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_8, ((PyObject *)__pyx_n_s__dtype), __pyx_t_9) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyEval_CallObjectWithKeywords(__pyx_t_1, __pyx_t_7, ((PyObject *)__pyx_t_8)); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_8)); __pyx_t_8 = 0;
  if (!(likely(((__pyx_t_9) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_9, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_10 = ((PyArrayObject *)__pyx_t_9);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[2];
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
    __pyx_t_11 = __Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_t_10, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack);
    if (unlikely(__pyx_t_11 < 0)) {
      PyErr_Fetch(&__pyx_t_12, &__pyx_t_13, &__pyx_t_14);
      if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_v_out, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
        Py_XDECREF(__pyx_t_12); Py_XDECREF(__pyx_t_13); Py_XDECREF(__pyx_t_14);
        __Pyx_RaiseBufferFallbackError();
      } else {
        PyErr_Restore(__pyx_t_12, __pyx_t_13, __pyx_t_14);
      }
    }
    __pyx_bstride_0_out = __pyx_bstruct_out.strides[0]; __pyx_bstride_1_out = __pyx_bstruct_out.strides[1];
    __pyx_bshape_0_out = __pyx_bstruct_out.shape[0]; __pyx_bshape_1_out = __pyx_bstruct_out.shape[1];
    if (unlikely(__pyx_t_11 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_t_10 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_v_out));
  __pyx_v_out = ((PyArrayObject *)__pyx_t_9);
  __pyx_t_9 = 0;

  
  __pyx_v_nvalues = (__pyx_v_out->dimensions[1]);

  
  __pyx_t_9 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_8 = PyObject_GetAttr(__pyx_t_9, __pyx_n_s__finfo); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_7 = PyObject_GetAttr(__pyx_t_9, __pyx_n_s__double); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyTuple_New(1); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  __pyx_t_7 = 0;
  __pyx_t_7 = PyObject_Call(__pyx_t_8, __pyx_t_9, NULL); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_7, __pyx_n_s__eps); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = PyNumber_Multiply(__pyx_t_9, __pyx_int_100); if (unlikely(!__pyx_t_7)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_v_eps);
  __pyx_v_eps = __pyx_t_7;
  __pyx_t_7 = 0;

  
  { PyThreadState *_save;
    Py_UNBLOCK_THREADS
     {

      
      __pyx_t_15 = (__pyx_v_xi->dimensions[0]);
      for (__pyx_t_11 = 0; __pyx_t_11 < __pyx_t_15; __pyx_t_11+=1) {
        __pyx_v_i = __pyx_t_11;

        
        __pyx_t_16 = __pyx_PyFloat_AsDouble(__pyx_v_eps); if (unlikely((__pyx_t_16 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 273; __pyx_clineno = __LINE__; goto __pyx_L7;}
        __pyx_v_isimplex = __pyx_f_5scipy_7spatial_5qhull__find_simplex(__pyx_v_info, __pyx_v_c, (((double *)__pyx_v_xi->data) + (__pyx_v_i * __pyx_v_ndim)), (&__pyx_v_start), __pyx_t_16);

        
        __pyx_t_17 = (__pyx_v_isimplex == -1);
        if (__pyx_t_17) {

          
          __pyx_t_18 = __pyx_v_nvalues;
          for (__pyx_t_19 = 0; __pyx_t_19 < __pyx_t_18; __pyx_t_19+=1) {
            __pyx_v_k = __pyx_t_19;

            
            __pyx_t_20 = __pyx_v_i;
            __pyx_t_21 = __pyx_v_k;
            if (__pyx_t_20 < 0) __pyx_t_20 += __pyx_bshape_0_out;
            if (__pyx_t_21 < 0) __pyx_t_21 += __pyx_bshape_1_out;
            (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_20, __pyx_bstride_0_out, __pyx_t_21, __pyx_bstride_1_out)).real = __Pyx_CREAL(__pyx_v_fill_value);

            
            __pyx_t_22 = __pyx_v_i;
            __pyx_t_23 = __pyx_v_k;
            if (__pyx_t_22 < 0) __pyx_t_22 += __pyx_bshape_0_out;
            if (__pyx_t_23 < 0) __pyx_t_23 += __pyx_bshape_1_out;
            (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_22, __pyx_bstride_0_out, __pyx_t_23, __pyx_bstride_1_out)).imag = __Pyx_CIMAG(__pyx_v_fill_value);
          }

          
          goto __pyx_L9_continue;
          goto __pyx_L11;
        }
        __pyx_L11:;

        
        __pyx_t_18 = __pyx_v_nvalues;
        for (__pyx_t_19 = 0; __pyx_t_19 < __pyx_t_18; __pyx_t_19+=1) {
          __pyx_v_k = __pyx_t_19;

          
          __pyx_t_24 = __pyx_v_i;
          __pyx_t_25 = __pyx_v_k;
          if (__pyx_t_24 < 0) __pyx_t_24 += __pyx_bshape_0_out;
          if (__pyx_t_25 < 0) __pyx_t_25 += __pyx_bshape_1_out;
          (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_24, __pyx_bstride_0_out, __pyx_t_25, __pyx_bstride_1_out)).real = 0;

          
          __pyx_t_26 = __pyx_v_i;
          __pyx_t_27 = __pyx_v_k;
          if (__pyx_t_26 < 0) __pyx_t_26 += __pyx_bshape_0_out;
          if (__pyx_t_27 < 0) __pyx_t_27 += __pyx_bshape_1_out;
          (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_26, __pyx_bstride_0_out, __pyx_t_27, __pyx_bstride_1_out)).imag = 0;
        }

        
        __pyx_t_28 = (__pyx_v_ndim + 1);
        for (__pyx_t_18 = 0; __pyx_t_18 < __pyx_t_28; __pyx_t_18+=1) {
          __pyx_v_j = __pyx_t_18;

          
          __pyx_t_19 = __pyx_v_nvalues;
          for (__pyx_t_29 = 0; __pyx_t_29 < __pyx_t_19; __pyx_t_29+=1) {
            __pyx_v_k = __pyx_t_29;

            
            __pyx_t_30 = __pyx_v_isimplex;
            __pyx_t_31 = __pyx_v_j;
            if (__pyx_t_30 < 0) __pyx_t_30 += __pyx_bshape_0_vertices;
            if (__pyx_t_31 < 0) __pyx_t_31 += __pyx_bshape_1_vertices;
            __pyx_v_m = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_30, __pyx_bstride_0_vertices, __pyx_t_31, __pyx_bstride_1_vertices));

            
            __pyx_t_32 = __pyx_v_m;
            __pyx_t_33 = __pyx_v_k;
            if (__pyx_t_32 < 0) __pyx_t_32 += __pyx_bshape_0_values;
            if (__pyx_t_33 < 0) __pyx_t_33 += __pyx_bshape_1_values;
            __pyx_t_34 = __pyx_v_i;
            __pyx_t_35 = __pyx_v_k;
            if (__pyx_t_34 < 0) __pyx_t_34 += __pyx_bshape_0_out;
            if (__pyx_t_35 < 0) __pyx_t_35 += __pyx_bshape_1_out;
            (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_34, __pyx_bstride_0_out, __pyx_t_35, __pyx_bstride_1_out)).real += ((__pyx_v_c[__pyx_v_j]) * (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_values.buf, __pyx_t_32, __pyx_bstride_0_values, __pyx_t_33, __pyx_bstride_1_values)).real);

            
            __pyx_t_36 = __pyx_v_m;
            __pyx_t_37 = __pyx_v_k;
            if (__pyx_t_36 < 0) __pyx_t_36 += __pyx_bshape_0_values;
            if (__pyx_t_37 < 0) __pyx_t_37 += __pyx_bshape_1_values;
            __pyx_t_38 = __pyx_v_i;
            __pyx_t_39 = __pyx_v_k;
            if (__pyx_t_38 < 0) __pyx_t_38 += __pyx_bshape_0_out;
            if (__pyx_t_39 < 0) __pyx_t_39 += __pyx_bshape_1_out;
            (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_38, __pyx_bstride_0_out, __pyx_t_39, __pyx_bstride_1_out)).imag += ((__pyx_v_c[__pyx_v_j]) * (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_values.buf, __pyx_t_36, __pyx_bstride_0_values, __pyx_t_37, __pyx_bstride_1_values)).imag);
          }
        }
        __pyx_L9_continue:;
      }
    }
     {
      int __pyx_why;
      __pyx_why = 0; goto __pyx_L8;
      __pyx_L7: __pyx_why = 4; goto __pyx_L8;
      __pyx_L8:;

      
      Py_BLOCK_THREADS
      switch (__pyx_why) {
        case 4: goto __pyx_L1_error;
      }
    }
  }

  
  free(((void *)__pyx_v_info));

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(((PyObject *)__pyx_v_out));
  __pyx_r = ((PyObject *)__pyx_v_out);
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  { PyObject *__pyx_type, *__pyx_value, *__pyx_tb;
    __Pyx_ErrFetch(&__pyx_type, &__pyx_value, &__pyx_tb);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
  __Pyx_ErrRestore(__pyx_type, __pyx_value, __pyx_tb);}
  __Pyx_AddTraceback("interpnd.LinearNDInterpolator._evaluate_complex");
  __pyx_r = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
  __pyx_L2:;
  __Pyx_XDECREF((PyObject *)__pyx_v_values);
  __Pyx_DECREF((PyObject *)__pyx_v_out);
  __Pyx_XDECREF((PyObject *)__pyx_v_points);
  __Pyx_XDECREF((PyObject *)__pyx_v_vertices);
  __Pyx_DECREF(__pyx_v_eps);
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF((PyObject *)__pyx_v_xi);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static  int __pyx_f_8interpnd__estimate_gradients_2d_global(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_d, double *__pyx_v_data, int __pyx_v_maxiter, double __pyx_v_tol, double *__pyx_v_y) {
  double __pyx_v_Q[(2 * 2)];
  double __pyx_v_s[2];
  double __pyx_v_r[2];
  int __pyx_v_ipoint;
  int __pyx_v_iiter;
  int __pyx_v_k;
  __pyx_t_5scipy_7spatial_5qhull_RidgeIter2D_t __pyx_v_it;
  double __pyx_v_f1;
  double __pyx_v_f2;
  double __pyx_v_df2;
  double __pyx_v_ex;
  double __pyx_v_ey;
  double __pyx_v_L;
  double __pyx_v_L3;
  double __pyx_v_det;
  double __pyx_v_err;
  double __pyx_v_change;
  int __pyx_r;
  long __pyx_t_1;
  int __pyx_t_2;
  int __pyx_t_3;
  int __pyx_t_4;
  int __pyx_t_5;
  int __pyx_t_6;
  int __pyx_t_7;

  
  __pyx_t_1 = (2 * __pyx_v_d->npoints);
  for (__pyx_t_2 = 0; __pyx_t_2 < __pyx_t_1; __pyx_t_2+=1) {
    __pyx_v_ipoint = __pyx_t_2;

    
    (__pyx_v_y[__pyx_v_ipoint]) = 0;
  }

  
  __pyx_t_2 = __pyx_v_maxiter;
  for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
    __pyx_v_iiter = __pyx_t_3;

    
    __pyx_v_err = 0;

    
    __pyx_t_4 = __pyx_v_d->npoints;
    for (__pyx_t_5 = 0; __pyx_t_5 < __pyx_t_4; __pyx_t_5+=1) {
      __pyx_v_ipoint = __pyx_t_5;

      
      for (__pyx_t_6 = 0; __pyx_t_6 < 4; __pyx_t_6+=1) {
        __pyx_v_k = __pyx_t_6;

        
        (__pyx_v_Q[__pyx_v_k]) = 0;
      }

      
      for (__pyx_t_6 = 0; __pyx_t_6 < 2; __pyx_t_6+=1) {
        __pyx_v_k = __pyx_t_6;

        
        (__pyx_v_s[__pyx_v_k]) = 0;
      }

      
      __pyx_f_5scipy_7spatial_5qhull__RidgeIter2D_init((&__pyx_v_it), __pyx_v_d, __pyx_v_ipoint);

      
      while (1) {
        __pyx_t_7 = (__pyx_v_it.index != -1);
        if (!__pyx_t_7) break;

        
        __pyx_v_ex = ((__pyx_v_d->points[((2 * __pyx_v_it.vertex2) + 0)]) - (__pyx_v_d->points[((2 * __pyx_v_it.vertex) + 0)]));

        
        __pyx_v_ey = ((__pyx_v_d->points[((2 * __pyx_v_it.vertex2) + 1)]) - (__pyx_v_d->points[((2 * __pyx_v_it.vertex) + 1)]));

        
        __pyx_v_L = sqrt((pow(__pyx_v_ex, 2) + pow(__pyx_v_ey, 2)));

        
        __pyx_v_L3 = ((__pyx_v_L * __pyx_v_L) * __pyx_v_L);

        
        __pyx_v_f1 = (__pyx_v_data[__pyx_v_it.vertex]);

        
        __pyx_v_f2 = (__pyx_v_data[__pyx_v_it.vertex2]);

        
        __pyx_v_df2 = (((-__pyx_v_ex) * (__pyx_v_y[((__pyx_v_it.vertex2 * 2) + 0)])) - (__pyx_v_ey * (__pyx_v_y[((__pyx_v_it.vertex2 * 2) + 1)])));

        
        (__pyx_v_Q[0]) += (((4 * __pyx_v_ex) * __pyx_v_ex) / __pyx_v_L3);

        
        (__pyx_v_Q[1]) += (((4 * __pyx_v_ex) * __pyx_v_ey) / __pyx_v_L3);

        
        (__pyx_v_Q[3]) += (((4 * __pyx_v_ey) * __pyx_v_ey) / __pyx_v_L3);

        
        (__pyx_v_s[0]) += ((((6 * (__pyx_v_f1 - __pyx_v_f2)) - (2 * __pyx_v_df2)) * __pyx_v_ex) / __pyx_v_L3);

        
        (__pyx_v_s[1]) += ((((6 * (__pyx_v_f1 - __pyx_v_f2)) - (2 * __pyx_v_df2)) * __pyx_v_ey) / __pyx_v_L3);

        
        __pyx_f_5scipy_7spatial_5qhull__RidgeIter2D_next((&__pyx_v_it));
      }

      
      (__pyx_v_Q[2]) = (__pyx_v_Q[1]);

      
      __pyx_v_det = (((__pyx_v_Q[0]) * (__pyx_v_Q[3])) - ((__pyx_v_Q[1]) * (__pyx_v_Q[2])));

      
      (__pyx_v_r[0]) = ((((__pyx_v_Q[3]) * (__pyx_v_s[0])) - ((__pyx_v_Q[1]) * (__pyx_v_s[1]))) / __pyx_v_det);

      
      (__pyx_v_r[1]) = ((((-(__pyx_v_Q[2])) * (__pyx_v_s[0])) + ((__pyx_v_Q[0]) * (__pyx_v_s[1]))) / __pyx_v_det);

      
      __pyx_v_change = fmax(fabs(((__pyx_v_y[((__pyx_v_it.vertex * 2) + 0)]) + (__pyx_v_r[0]))), fabs(((__pyx_v_y[((__pyx_v_it.vertex * 2) + 1)]) + (__pyx_v_r[1]))));

      
      (__pyx_v_y[((__pyx_v_it.vertex * 2) + 0)]) = (-(__pyx_v_r[0]));

      
      (__pyx_v_y[((__pyx_v_it.vertex * 2) + 1)]) = (-(__pyx_v_r[1]));

      
      __pyx_v_change /= fmax(1.0, fmax(fabs((__pyx_v_r[0])), fabs((__pyx_v_r[1]))));

      
      __pyx_v_err = fmax(__pyx_v_err, __pyx_v_change);
    }

    
    __pyx_t_7 = (__pyx_v_err < __pyx_v_tol);
    if (__pyx_t_7) {

      
      __pyx_r = (__pyx_v_iiter + 1);
      goto __pyx_L0;
      goto __pyx_L15;
    }
    __pyx_L15:;
  }

  
  __pyx_r = 0;
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_estimate_gradients_2d_global(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyObject *__pyx_pf_8interpnd_estimate_gradients_2d_global(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_tri = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_maxiter = 0;
  PyObject *__pyx_v_tol = 0;
  PyArrayObject *__pyx_v_data;
  PyArrayObject *__pyx_v_grad;
  __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_info;
  int __pyx_v_k;
  int __pyx_v_ret;
  int __pyx_v_nvalues;
  PyObject *__pyx_v_rg;
  PyObject *__pyx_v_ig;
  PyObject *__pyx_v_r;
  PyObject *__pyx_v_y_shape;
  PyObject *__pyx_v_yi;
  Py_buffer __pyx_bstruct_grad;
  Py_ssize_t __pyx_bstride_0_grad = 0;
  Py_ssize_t __pyx_bstride_1_grad = 0;
  Py_ssize_t __pyx_bstride_2_grad = 0;
  Py_ssize_t __pyx_bshape_0_grad = 0;
  Py_ssize_t __pyx_bshape_1_grad = 0;
  Py_ssize_t __pyx_bshape_2_grad = 0;
  Py_buffer __pyx_bstruct_data;
  Py_ssize_t __pyx_bstride_0_data = 0;
  Py_ssize_t __pyx_bstride_1_data = 0;
  Py_ssize_t __pyx_bshape_0_data = 0;
  Py_ssize_t __pyx_bshape_1_data = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyArrayObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyArrayObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  int __pyx_t_13;
  double __pyx_t_14;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__tri,&__pyx_n_s__y,&__pyx_n_s__maxiter,&__pyx_n_s__tol,0};
  __Pyx_RefNannySetupContext("estimate_gradients_2d_global");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[4] = {0,0,0,0};
    values[2] = ((PyObject *)__pyx_int_400);
    values[3] = __pyx_k_10;
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__tri);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__y);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("estimate_gradients_2d_global", 0, 2, 4, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  2:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__maxiter);
        if (unlikely(value)) { values[2] = value; kw_args--; }
      }
      case  3:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__tol);
        if (unlikely(value)) { values[3] = value; kw_args--; }
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "estimate_gradients_2d_global") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_tri = values[0];
    __pyx_v_y = values[1];
    __pyx_v_maxiter = values[2];
    __pyx_v_tol = values[3];
  } else {
    __pyx_v_maxiter = ((PyObject *)__pyx_int_400);
    __pyx_v_tol = __pyx_k_10;
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  4:
      __pyx_v_tol = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3:
      __pyx_v_maxiter = PyTuple_GET_ITEM(__pyx_args, 2);
      case  2:
      __pyx_v_y = PyTuple_GET_ITEM(__pyx_args, 1);
      __pyx_v_tri = PyTuple_GET_ITEM(__pyx_args, 0);
      break;
      default: goto __pyx_L5_argtuple_error;
    }
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("estimate_gradients_2d_global", 0, 2, 4, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.estimate_gradients_2d_global");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_tri);
  __Pyx_INCREF(__pyx_v_y);
  __Pyx_INCREF(__pyx_v_maxiter);
  __Pyx_INCREF(__pyx_v_tol);
  __pyx_v_data = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_grad = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_rg = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_ig = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_r = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_y_shape = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_yi = Py_None; __Pyx_INCREF(Py_None);
  __pyx_bstruct_data.buf = NULL;
  __pyx_bstruct_grad.buf = NULL;

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 486; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__asanyarray); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 486; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 486; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_y);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_y);
  __Pyx_GIVEREF(__pyx_v_y);
  __pyx_t_3 = PyObject_Call(__pyx_t_2, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 486; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_v_y);
  __pyx_v_y = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_3, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_tri, __pyx_n_s__npoints); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyObject_RichCompare(__pyx_t_1, __pyx_t_3, Py_NE); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(((PyObject *)__pyx_kp_s_11));
    PyTuple_SET_ITEM(__pyx_t_2, 0, ((PyObject *)__pyx_kp_s_11));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_11));
    __pyx_t_3 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_Raise(__pyx_t_3, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  
  __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__issubdtype); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__dtype); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__complexfloating); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  __pyx_t_3 = 0;
  __pyx_t_5 = 0;
  __pyx_t_5 = PyObject_Call(__pyx_t_2, __pyx_t_1, NULL); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s_12); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__real); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_v_tri);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_tri);
    __Pyx_GIVEREF(__pyx_v_tri);
    PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;
    __pyx_t_1 = PyDict_New(); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(((PyObject *)__pyx_t_1));
    if (PyDict_SetItem(__pyx_t_1, ((PyObject *)__pyx_n_s__maxiter), __pyx_v_maxiter) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    if (PyDict_SetItem(__pyx_t_1, ((PyObject *)__pyx_n_s__tol), __pyx_v_tol) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_3 = PyEval_CallObjectWithKeywords(__pyx_t_5, __pyx_t_2, ((PyObject *)__pyx_t_1)); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(((PyObject *)__pyx_t_1)); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_v_rg);
    __pyx_v_rg = __pyx_t_3;
    __pyx_t_3 = 0;

    
    __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s_12); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__imag); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_v_tri);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_tri);
    __Pyx_GIVEREF(__pyx_v_tri);
    PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;
    __pyx_t_1 = PyDict_New(); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(((PyObject *)__pyx_t_1));
    if (PyDict_SetItem(__pyx_t_1, ((PyObject *)__pyx_n_s__maxiter), __pyx_v_maxiter) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    if (PyDict_SetItem(__pyx_t_1, ((PyObject *)__pyx_n_s__tol), __pyx_v_tol) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_5 = PyEval_CallObjectWithKeywords(__pyx_t_3, __pyx_t_2, ((PyObject *)__pyx_t_1)); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(((PyObject *)__pyx_t_1)); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_v_ig);
    __pyx_v_ig = __pyx_t_5;
    __pyx_t_5 = 0;

    
    __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__zeros); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyObject_GetAttr(__pyx_v_rg, __pyx_n_s__shape); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_5);
    __pyx_t_5 = 0;
    __pyx_t_5 = PyDict_New(); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(((PyObject *)__pyx_t_5));
    if (PyDict_SetItem(__pyx_t_5, ((PyObject *)__pyx_n_s__dtype), ((PyObject*)&PyComplex_Type)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_t_3 = PyEval_CallObjectWithKeywords(__pyx_t_1, __pyx_t_2, ((PyObject *)__pyx_t_5)); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 494; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(((PyObject *)__pyx_t_5)); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_v_r);
    __pyx_v_r = __pyx_t_3;
    __pyx_t_3 = 0;

    
    if (PyObject_SetAttr(__pyx_v_r, __pyx_n_s__real, __pyx_v_rg) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 495; __pyx_clineno = __LINE__; goto __pyx_L1_error;}

    
    if (PyObject_SetAttr(__pyx_v_r, __pyx_n_s__imag, __pyx_v_ig) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 496; __pyx_clineno = __LINE__; goto __pyx_L1_error;}

    
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(__pyx_v_r);
    __pyx_r = __pyx_v_r;
    goto __pyx_L0;
    goto __pyx_L7;
  }
  __pyx_L7:;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 499; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_v_y_shape);
  __pyx_v_y_shape = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__ndim); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 501; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = PyObject_RichCompare(__pyx_t_3, __pyx_int_1, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 501; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_4 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 501; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (__pyx_t_4) {

    
    __pyx_t_5 = PySlice_New(Py_None, Py_None, Py_None); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 502; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 502; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_5);
    __Pyx_INCREF(Py_None);
    PyTuple_SET_ITEM(__pyx_t_3, 1, Py_None);
    __Pyx_GIVEREF(Py_None);
    __pyx_t_5 = 0;
    __pyx_t_5 = PyObject_GetItem(__pyx_v_y, __pyx_t_3); if (!__pyx_t_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 502; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_v_y);
    __pyx_v_y = __pyx_t_5;
    __pyx_t_5 = 0;
    goto __pyx_L8;
  }
  __pyx_L8:;

  
  __pyx_t_5 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__reshape); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_tri, __pyx_n_s__npoints); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_int_neg_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_int_neg_1);
  __Pyx_GIVEREF(__pyx_int_neg_1);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_5, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__T); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 504; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_v_y);
  __pyx_v_y = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__ascontiguousarray); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_y);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_y);
  __Pyx_GIVEREF(__pyx_v_y);
  __pyx_t_5 = PyObject_Call(__pyx_t_3, __pyx_t_2, NULL); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__astype); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__double); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 505; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_v_y);
  __pyx_v_y = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__empty); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_3, 0, sizeof(long), PyInt_FromLong); if (!__pyx_t_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_y, __pyx_n_s__shape); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_3, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_2);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_int_2);
  __Pyx_GIVEREF(__pyx_int_2);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_5, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 506; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_v_yi);
  __pyx_v_yi = __pyx_t_3;
  __pyx_t_3 = 0;

  
  if (!(likely(((__pyx_v_y) == Py_None) || likely(__Pyx_TypeTest(__pyx_v_y, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 508; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_6 = ((PyArrayObject *)__pyx_v_y);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_data);
    __pyx_t_7 = __Pyx_GetBufferAndValidate(&__pyx_bstruct_data, (PyObject*)__pyx_t_6, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack);
    if (unlikely(__pyx_t_7 < 0)) {
      PyErr_Fetch(&__pyx_t_8, &__pyx_t_9, &__pyx_t_10);
      if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_data, (PyObject*)__pyx_v_data, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
        Py_XDECREF(__pyx_t_8); Py_XDECREF(__pyx_t_9); Py_XDECREF(__pyx_t_10);
        __Pyx_RaiseBufferFallbackError();
      } else {
        PyErr_Restore(__pyx_t_8, __pyx_t_9, __pyx_t_10);
      }
    }
    __pyx_bstride_0_data = __pyx_bstruct_data.strides[0]; __pyx_bstride_1_data = __pyx_bstruct_data.strides[1];
    __pyx_bshape_0_data = __pyx_bstruct_data.shape[0]; __pyx_bshape_1_data = __pyx_bstruct_data.shape[1];
    if (unlikely(__pyx_t_7 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 508; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_v_y);
  __Pyx_DECREF(((PyObject *)__pyx_v_data));
  __pyx_v_data = ((PyArrayObject *)__pyx_v_y);

  
  if (!(likely(((__pyx_v_yi) == Py_None) || likely(__Pyx_TypeTest(__pyx_v_yi, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_11 = ((PyArrayObject *)__pyx_v_yi);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
    __pyx_t_7 = __Pyx_GetBufferAndValidate(&__pyx_bstruct_grad, (PyObject*)__pyx_t_11, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 3, 0, __pyx_stack);
    if (unlikely(__pyx_t_7 < 0)) {
      PyErr_Fetch(&__pyx_t_10, &__pyx_t_9, &__pyx_t_8);
      if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_grad, (PyObject*)__pyx_v_grad, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 3, 0, __pyx_stack) == -1)) {
        Py_XDECREF(__pyx_t_10); Py_XDECREF(__pyx_t_9); Py_XDECREF(__pyx_t_8);
        __Pyx_RaiseBufferFallbackError();
      } else {
        PyErr_Restore(__pyx_t_10, __pyx_t_9, __pyx_t_8);
      }
    }
    __pyx_bstride_0_grad = __pyx_bstruct_grad.strides[0]; __pyx_bstride_1_grad = __pyx_bstruct_grad.strides[1]; __pyx_bstride_2_grad = __pyx_bstruct_grad.strides[2];
    __pyx_bshape_0_grad = __pyx_bstruct_grad.shape[0]; __pyx_bshape_1_grad = __pyx_bstruct_grad.shape[1]; __pyx_bshape_2_grad = __pyx_bstruct_grad.shape[2];
    if (unlikely(__pyx_t_7 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 509; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_t_11 = 0;
  __Pyx_INCREF(__pyx_v_yi);
  __Pyx_DECREF(((PyObject *)__pyx_v_grad));
  __pyx_v_grad = ((PyArrayObject *)__pyx_v_yi);

  
  __pyx_v_info = __pyx_f_5scipy_7spatial_5qhull__get_delaunay_info(__pyx_v_tri, 0, 1);

  
  __pyx_v_nvalues = (__pyx_v_data->dimensions[0]);

  
  __pyx_t_7 = __pyx_v_nvalues;
  for (__pyx_t_12 = 0; __pyx_t_12 < __pyx_t_7; __pyx_t_12+=1) {
    __pyx_v_k = __pyx_t_12;

    
    { PyThreadState *_save;
      Py_UNBLOCK_THREADS
       {

        
        __pyx_t_13 = __Pyx_PyInt_AsInt(__pyx_v_maxiter); if (unlikely((__pyx_t_13 == (int)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 519; __pyx_clineno = __LINE__; goto __pyx_L14;}

        
        __pyx_t_14 = __pyx_PyFloat_AsDouble(__pyx_v_tol); if (unlikely((__pyx_t_14 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 520; __pyx_clineno = __LINE__; goto __pyx_L14;}

        
        __pyx_v_ret = __pyx_f_8interpnd__estimate_gradients_2d_global(__pyx_v_info, (((double *)__pyx_v_data->data) + (__pyx_v_info->npoints * __pyx_v_k)), __pyx_t_13, __pyx_t_14, (((double *)__pyx_v_grad->data) + ((2 * __pyx_v_info->npoints) * __pyx_v_k)));
      }
       {
        int __pyx_why;
        __pyx_why = 0; goto __pyx_L15;
        __pyx_L14: __pyx_why = 4; goto __pyx_L15;
        __pyx_L15:;

        
        Py_BLOCK_THREADS
        switch (__pyx_why) {
          case 4: goto __pyx_L1_error;
        }
      }
    }

    
    __pyx_t_4 = (__pyx_v_ret == 0);
    if (__pyx_t_4) {

      
      __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s__warnings); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_1 = PyObject_GetAttr(__pyx_t_3, __pyx_n_s__warn); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __pyx_t_3 = __Pyx_GetName(__pyx_m, __pyx_n_s_14); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 526; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_INCREF(((PyObject *)__pyx_kp_s_13));
      PyTuple_SET_ITEM(__pyx_t_5, 0, ((PyObject *)__pyx_kp_s_13));
      __Pyx_GIVEREF(((PyObject *)__pyx_kp_s_13));
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_3 = PyObject_Call(__pyx_t_1, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 524; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      goto __pyx_L17;
    }
    __pyx_L17:;
  }

  
  free(__pyx_v_info);

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_yi, __pyx_n_s__transpose); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_5 = PyTuple_New(3); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_int_1);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_int_1);
  __Pyx_GIVEREF(__pyx_int_1);
  __Pyx_INCREF(__pyx_int_0);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  __Pyx_INCREF(__pyx_int_2);
  PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_int_2);
  __Pyx_GIVEREF(__pyx_int_2);
  __pyx_t_1 = PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__reshape); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_2);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_int_2);
  __Pyx_GIVEREF(__pyx_int_2);
  __pyx_t_3 = PyNumber_Add(__pyx_v_y_shape, __pyx_t_1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = PyObject_Call(__pyx_t_5, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 529; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  { PyObject *__pyx_type, *__pyx_value, *__pyx_tb;
    __Pyx_ErrFetch(&__pyx_type, &__pyx_value, &__pyx_tb);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_data);
  __Pyx_ErrRestore(__pyx_type, __pyx_value, __pyx_tb);}
  __Pyx_AddTraceback("interpnd.estimate_gradients_2d_global");
  __pyx_r = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_data);
  __pyx_L2:;
  __Pyx_DECREF((PyObject *)__pyx_v_data);
  __Pyx_DECREF((PyObject *)__pyx_v_grad);
  __Pyx_DECREF(__pyx_v_rg);
  __Pyx_DECREF(__pyx_v_ig);
  __Pyx_DECREF(__pyx_v_r);
  __Pyx_DECREF(__pyx_v_y_shape);
  __Pyx_DECREF(__pyx_v_yi);
  __Pyx_DECREF(__pyx_v_tri);
  __Pyx_DECREF(__pyx_v_y);
  __Pyx_DECREF(__pyx_v_maxiter);
  __Pyx_DECREF(__pyx_v_tol);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static  double __pyx_f_8interpnd__clough_tocher_2d_single_double(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_d, int __pyx_v_isimplex, double *__pyx_v_b, double *__pyx_v_f, double *__pyx_v_df) {
  double __pyx_v_c3000;
  double __pyx_v_c0300;
  double __pyx_v_c0030;
  double __pyx_v_c0003;
  double __pyx_v_c2100;
  double __pyx_v_c2010;
  double __pyx_v_c2001;
  double __pyx_v_c0210;
  double __pyx_v_c0201;
  double __pyx_v_c0021;
  double __pyx_v_c1200;
  double __pyx_v_c1020;
  double __pyx_v_c1002;
  double __pyx_v_c0120;
  double __pyx_v_c0102;
  double __pyx_v_c0012;
  double __pyx_v_c1101;
  double __pyx_v_c1011;
  double __pyx_v_c0111;
  double __pyx_v_f1;
  double __pyx_v_f2;
  double __pyx_v_f3;
  double __pyx_v_df12;
  double __pyx_v_df13;
  double __pyx_v_df21;
  double __pyx_v_df23;
  double __pyx_v_df31;
  double __pyx_v_df32;
  double __pyx_v_g1;
  double __pyx_v_g2;
  double __pyx_v_g3;
  double __pyx_v_e12x;
  double __pyx_v_e12y;
  double __pyx_v_e23x;
  double __pyx_v_e23y;
  double __pyx_v_e31x;
  double __pyx_v_e31y;
  double __pyx_v_e14x;
  double __pyx_v_e14y;
  double __pyx_v_e24x;
  double __pyx_v_e24y;
  double __pyx_v_e34x;
  double __pyx_v_e34y;
  double __pyx_v_w;
  double __pyx_v_minval;
  double __pyx_v_b1;
  double __pyx_v_b2;
  double __pyx_v_b3;
  double __pyx_v_b4;
  int __pyx_v_k;
  int __pyx_v_itri;
  double __pyx_v_c[3];
  double __pyx_v_y[2];
  double __pyx_r;
  int __pyx_t_1;
  int __pyx_t_2;

  
  __pyx_v_e12x = ((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]) - (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]));

  
  __pyx_v_e12y = ((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]) - (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]));

  
  __pyx_v_e23x = ((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]) - (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]));

  
  __pyx_v_e23y = ((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]) - (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]));

  
  __pyx_v_e31x = ((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]) - (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]));

  
  __pyx_v_e31y = ((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]) - (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]));

  
  __pyx_v_e14x = ((__pyx_v_e12x - __pyx_v_e31x) / 3);

  
  __pyx_v_e14y = ((__pyx_v_e12y - __pyx_v_e31y) / 3);

  
  __pyx_v_e24x = (((-__pyx_v_e12x) + __pyx_v_e23x) / 3);

  
  __pyx_v_e24y = (((-__pyx_v_e12y) + __pyx_v_e23y) / 3);

  
  __pyx_v_e34x = ((__pyx_v_e31x - __pyx_v_e23x) / 3);

  
  __pyx_v_e34y = ((__pyx_v_e31y - __pyx_v_e23y) / 3);

  
  __pyx_v_f1 = (__pyx_v_f[0]);

  
  __pyx_v_f2 = (__pyx_v_f[1]);

  
  __pyx_v_f3 = (__pyx_v_f[2]);

  
  __pyx_v_df12 = (((__pyx_v_df[0]) * __pyx_v_e12x) + ((__pyx_v_df[1]) * __pyx_v_e12y));

  
  __pyx_v_df21 = (-(((__pyx_v_df[2]) * __pyx_v_e12x) + ((__pyx_v_df[3]) * __pyx_v_e12y)));

  
  __pyx_v_df23 = (((__pyx_v_df[2]) * __pyx_v_e23x) + ((__pyx_v_df[3]) * __pyx_v_e23y));

  
  __pyx_v_df32 = (-(((__pyx_v_df[4]) * __pyx_v_e23x) + ((__pyx_v_df[5]) * __pyx_v_e23y)));

  
  __pyx_v_df31 = (((__pyx_v_df[4]) * __pyx_v_e31x) + ((__pyx_v_df[5]) * __pyx_v_e31y));

  
  __pyx_v_df13 = (-(((__pyx_v_df[0]) * __pyx_v_e31x) + ((__pyx_v_df[1]) * __pyx_v_e31y)));

  
  __pyx_v_c3000 = __pyx_v_f1;

  
  __pyx_v_c2100 = ((__pyx_v_df12 + (3 * __pyx_v_c3000)) / 3);

  
  __pyx_v_c2010 = ((__pyx_v_df13 + (3 * __pyx_v_c3000)) / 3);

  
  __pyx_v_c0300 = __pyx_v_f2;

  
  __pyx_v_c1200 = ((__pyx_v_df21 + (3 * __pyx_v_c0300)) / 3);

  
  __pyx_v_c0210 = ((__pyx_v_df23 + (3 * __pyx_v_c0300)) / 3);

  
  __pyx_v_c0030 = __pyx_v_f3;

  
  __pyx_v_c1020 = ((__pyx_v_df31 + (3 * __pyx_v_c0030)) / 3);

  
  __pyx_v_c0120 = ((__pyx_v_df32 + (3 * __pyx_v_c0030)) / 3);

  
  __pyx_v_c2001 = (((__pyx_v_c2100 + __pyx_v_c2010) + __pyx_v_c3000) / 3);

  
  __pyx_v_c0201 = (((__pyx_v_c1200 + __pyx_v_c0300) + __pyx_v_c0210) / 3);

  
  __pyx_v_c0021 = (((__pyx_v_c1020 + __pyx_v_c0120) + __pyx_v_c0030) / 3);

  
  for (__pyx_t_1 = 0; __pyx_t_1 < 3; __pyx_t_1+=1) {
    __pyx_v_k = __pyx_t_1;

    
    __pyx_v_itri = (__pyx_v_d->neighbors[((3 * __pyx_v_isimplex) + __pyx_v_k)]);

    
    __pyx_t_2 = (__pyx_v_itri == -1);
    if (__pyx_t_2) {

      
      switch (__pyx_v_k) {
        case 0:

        
        __pyx_v_g1 = ((-2.0) / 3);
        break;

        
        case 1:

        
        __pyx_v_g2 = ((-2.0) / 3);
        break;

        
        case 2:

        
        __pyx_v_g3 = ((-2.0) / 3);
        break;
      }

      
      goto __pyx_L3_continue;
      goto __pyx_L5;
    }
    __pyx_L5:;

    
    (__pyx_v_y[0]) = ((((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 0)])))]) + (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 1)])))])) + (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 2)])))])) / 3);

    
    (__pyx_v_y[1]) = ((((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 0)])))]) + (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 1)])))])) + (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 2)])))])) / 3);

    
    __pyx_f_5scipy_7spatial_5qhull__barycentric_coordinates(2, (__pyx_v_d->transform + ((__pyx_v_isimplex * 2) * 3)), __pyx_v_y, __pyx_v_c);

    
    switch (__pyx_v_k) {
      case 0:

      
      __pyx_v_g1 = ((((2 * (__pyx_v_c[2])) + (__pyx_v_c[1])) - 1) / ((2 - (3 * (__pyx_v_c[2]))) - (3 * (__pyx_v_c[1]))));
      break;

      
      case 1:

      
      __pyx_v_g2 = ((((2 * (__pyx_v_c[0])) + (__pyx_v_c[2])) - 1) / ((2 - (3 * (__pyx_v_c[0]))) - (3 * (__pyx_v_c[2]))));
      break;

      
      case 2:

      
      __pyx_v_g3 = ((((2 * (__pyx_v_c[1])) + (__pyx_v_c[0])) - 1) / ((2 - (3 * (__pyx_v_c[1]))) - (3 * (__pyx_v_c[0]))));
      break;
    }
    __pyx_L3_continue:;
  }

  
  __pyx_v_c0111 = (((__pyx_v_g1 * ((((-__pyx_v_c0300) + (3 * __pyx_v_c0210)) - (3 * __pyx_v_c0120)) + __pyx_v_c0030)) + (((((-__pyx_v_c0300) + (2 * __pyx_v_c0210)) - __pyx_v_c0120) + __pyx_v_c0021) + __pyx_v_c0201)) / 2);

  
  __pyx_v_c1011 = (((__pyx_v_g2 * ((((-__pyx_v_c0030) + (3 * __pyx_v_c1020)) - (3 * __pyx_v_c2010)) + __pyx_v_c3000)) + (((((-__pyx_v_c0030) + (2 * __pyx_v_c1020)) - __pyx_v_c2010) + __pyx_v_c2001) + __pyx_v_c0021)) / 2);

  
  __pyx_v_c1101 = (((__pyx_v_g3 * ((((-__pyx_v_c3000) + (3 * __pyx_v_c2100)) - (3 * __pyx_v_c1200)) + __pyx_v_c0300)) + (((((-__pyx_v_c3000) + (2 * __pyx_v_c2100)) - __pyx_v_c1200) + __pyx_v_c2001) + __pyx_v_c0201)) / 2);

  
  __pyx_v_c1002 = (((__pyx_v_c1101 + __pyx_v_c1011) + __pyx_v_c2001) / 3);

  
  __pyx_v_c0102 = (((__pyx_v_c1101 + __pyx_v_c0111) + __pyx_v_c0201) / 3);

  
  __pyx_v_c0012 = (((__pyx_v_c1011 + __pyx_v_c0111) + __pyx_v_c0021) / 3);

  
  __pyx_v_c0003 = (((__pyx_v_c1002 + __pyx_v_c0102) + __pyx_v_c0012) / 3);

  
  __pyx_v_minval = (__pyx_v_b[0]);

  
  for (__pyx_t_1 = 0; __pyx_t_1 < 3; __pyx_t_1+=1) {
    __pyx_v_k = __pyx_t_1;

    
    __pyx_t_2 = ((__pyx_v_b[__pyx_v_k]) < __pyx_v_minval);
    if (__pyx_t_2) {

      
      __pyx_v_minval = (__pyx_v_b[__pyx_v_k]);
      goto __pyx_L8;
    }
    __pyx_L8:;
  }

  
  __pyx_v_b1 = ((__pyx_v_b[0]) - __pyx_v_minval);

  
  __pyx_v_b2 = ((__pyx_v_b[1]) - __pyx_v_minval);

  
  __pyx_v_b3 = ((__pyx_v_b[2]) - __pyx_v_minval);

  
  __pyx_v_b4 = (3 * __pyx_v_minval);

  
  __pyx_v_w = (((((((((((((((((((pow(__pyx_v_b1, 3) * __pyx_v_c3000) + (((3 * pow(__pyx_v_b1, 2)) * __pyx_v_b2) * __pyx_v_c2100)) + (((3 * pow(__pyx_v_b1, 2)) * __pyx_v_b3) * __pyx_v_c2010)) + (((3 * pow(__pyx_v_b1, 2)) * __pyx_v_b4) * __pyx_v_c2001)) + (((3 * __pyx_v_b1) * pow(__pyx_v_b2, 2)) * __pyx_v_c1200)) + ((((6 * __pyx_v_b1) * __pyx_v_b2) * __pyx_v_b4) * __pyx_v_c1101)) + (((3 * __pyx_v_b1) * pow(__pyx_v_b3, 2)) * __pyx_v_c1020)) + ((((6 * __pyx_v_b1) * __pyx_v_b3) * __pyx_v_b4) * __pyx_v_c1011)) + (((3 * __pyx_v_b1) * pow(__pyx_v_b4, 2)) * __pyx_v_c1002)) + (pow(__pyx_v_b2, 3) * __pyx_v_c0300)) + (((3 * pow(__pyx_v_b2, 2)) * __pyx_v_b3) * __pyx_v_c0210)) + (((3 * pow(__pyx_v_b2, 2)) * __pyx_v_b4) * __pyx_v_c0201)) + (((3 * __pyx_v_b2) * pow(__pyx_v_b3, 2)) * __pyx_v_c0120)) + ((((6 * __pyx_v_b2) * __pyx_v_b3) * __pyx_v_b4) * __pyx_v_c0111)) + (((3 * __pyx_v_b2) * pow(__pyx_v_b4, 2)) * __pyx_v_c0102)) + (pow(__pyx_v_b3, 3) * __pyx_v_c0030)) + (((3 * pow(__pyx_v_b3, 2)) * __pyx_v_b4) * __pyx_v_c0021)) + (((3 * __pyx_v_b3) * pow(__pyx_v_b4, 2)) * __pyx_v_c0012)) + (pow(__pyx_v_b4, 3) * __pyx_v_c0003));

  
  __pyx_r = __pyx_v_w;
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}



static  __pyx_t_double_complex __pyx_f_8interpnd__clough_tocher_2d_single_complex(__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_d, int __pyx_v_isimplex, double *__pyx_v_b, __pyx_t_double_complex *__pyx_v_f, __pyx_t_double_complex *__pyx_v_df) {
  __pyx_t_double_complex __pyx_v_c3000;
  __pyx_t_double_complex __pyx_v_c0300;
  __pyx_t_double_complex __pyx_v_c0030;
  __pyx_t_double_complex __pyx_v_c0003;
  __pyx_t_double_complex __pyx_v_c2100;
  __pyx_t_double_complex __pyx_v_c2010;
  __pyx_t_double_complex __pyx_v_c2001;
  __pyx_t_double_complex __pyx_v_c0210;
  __pyx_t_double_complex __pyx_v_c0201;
  __pyx_t_double_complex __pyx_v_c0021;
  __pyx_t_double_complex __pyx_v_c1200;
  __pyx_t_double_complex __pyx_v_c1020;
  __pyx_t_double_complex __pyx_v_c1002;
  __pyx_t_double_complex __pyx_v_c0120;
  __pyx_t_double_complex __pyx_v_c0102;
  __pyx_t_double_complex __pyx_v_c0012;
  __pyx_t_double_complex __pyx_v_c1101;
  __pyx_t_double_complex __pyx_v_c1011;
  __pyx_t_double_complex __pyx_v_c0111;
  __pyx_t_double_complex __pyx_v_f1;
  __pyx_t_double_complex __pyx_v_f2;
  __pyx_t_double_complex __pyx_v_f3;
  __pyx_t_double_complex __pyx_v_df12;
  __pyx_t_double_complex __pyx_v_df13;
  __pyx_t_double_complex __pyx_v_df21;
  __pyx_t_double_complex __pyx_v_df23;
  __pyx_t_double_complex __pyx_v_df31;
  __pyx_t_double_complex __pyx_v_df32;
  double __pyx_v_g1;
  double __pyx_v_g2;
  double __pyx_v_g3;
  double __pyx_v_e12x;
  double __pyx_v_e12y;
  double __pyx_v_e23x;
  double __pyx_v_e23y;
  double __pyx_v_e31x;
  double __pyx_v_e31y;
  double __pyx_v_e14x;
  double __pyx_v_e14y;
  double __pyx_v_e24x;
  double __pyx_v_e24y;
  double __pyx_v_e34x;
  double __pyx_v_e34y;
  __pyx_t_double_complex __pyx_v_w;
  double __pyx_v_minval;
  double __pyx_v_b1;
  double __pyx_v_b2;
  double __pyx_v_b3;
  double __pyx_v_b4;
  int __pyx_v_k;
  int __pyx_v_itri;
  double __pyx_v_c[3];
  double __pyx_v_y[2];
  __pyx_t_double_complex __pyx_r;
  int __pyx_t_1;
  int __pyx_t_2;

  
  __pyx_v_e12x = ((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]) - (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]));

  
  __pyx_v_e12y = ((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]) - (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]));

  
  __pyx_v_e23x = ((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]) - (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]));

  
  __pyx_v_e23y = ((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]) - (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 1)])))]));

  
  __pyx_v_e31x = ((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]) - (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]));

  
  __pyx_v_e31y = ((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 0)])))]) - (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_isimplex) + 2)])))]));

  
  __pyx_v_e14x = ((__pyx_v_e12x - __pyx_v_e31x) / 3);

  
  __pyx_v_e14y = ((__pyx_v_e12y - __pyx_v_e31y) / 3);

  
  __pyx_v_e24x = (((-__pyx_v_e12x) + __pyx_v_e23x) / 3);

  
  __pyx_v_e24y = (((-__pyx_v_e12y) + __pyx_v_e23y) / 3);

  
  __pyx_v_e34x = ((__pyx_v_e31x - __pyx_v_e23x) / 3);

  
  __pyx_v_e34y = ((__pyx_v_e31y - __pyx_v_e23y) / 3);

  
  __pyx_v_f1 = (__pyx_v_f[0]);

  
  __pyx_v_f2 = (__pyx_v_f[1]);

  
  __pyx_v_f3 = (__pyx_v_f[2]);

  
  __pyx_v_df12 = __Pyx_c_sum(__Pyx_c_prod((__pyx_v_df[0]), __pyx_t_double_complex_from_parts(__pyx_v_e12x, 0)), __Pyx_c_prod((__pyx_v_df[1]), __pyx_t_double_complex_from_parts(__pyx_v_e12y, 0)));

  
  __pyx_v_df21 = __Pyx_c_neg(__Pyx_c_sum(__Pyx_c_prod((__pyx_v_df[2]), __pyx_t_double_complex_from_parts(__pyx_v_e12x, 0)), __Pyx_c_prod((__pyx_v_df[3]), __pyx_t_double_complex_from_parts(__pyx_v_e12y, 0))));

  
  __pyx_v_df23 = __Pyx_c_sum(__Pyx_c_prod((__pyx_v_df[2]), __pyx_t_double_complex_from_parts(__pyx_v_e23x, 0)), __Pyx_c_prod((__pyx_v_df[3]), __pyx_t_double_complex_from_parts(__pyx_v_e23y, 0)));

  
  __pyx_v_df32 = __Pyx_c_neg(__Pyx_c_sum(__Pyx_c_prod((__pyx_v_df[4]), __pyx_t_double_complex_from_parts(__pyx_v_e23x, 0)), __Pyx_c_prod((__pyx_v_df[5]), __pyx_t_double_complex_from_parts(__pyx_v_e23y, 0))));

  
  __pyx_v_df31 = __Pyx_c_sum(__Pyx_c_prod((__pyx_v_df[4]), __pyx_t_double_complex_from_parts(__pyx_v_e31x, 0)), __Pyx_c_prod((__pyx_v_df[5]), __pyx_t_double_complex_from_parts(__pyx_v_e31y, 0)));

  
  __pyx_v_df13 = __Pyx_c_neg(__Pyx_c_sum(__Pyx_c_prod((__pyx_v_df[0]), __pyx_t_double_complex_from_parts(__pyx_v_e31x, 0)), __Pyx_c_prod((__pyx_v_df[1]), __pyx_t_double_complex_from_parts(__pyx_v_e31y, 0))));

  
  __pyx_v_c3000 = __pyx_v_f1;

  
  __pyx_v_c2100 = __Pyx_c_quot(__Pyx_c_sum(__pyx_v_df12, __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c3000)), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c2010 = __Pyx_c_quot(__Pyx_c_sum(__pyx_v_df13, __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c3000)), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0300 = __pyx_v_f2;

  
  __pyx_v_c1200 = __Pyx_c_quot(__Pyx_c_sum(__pyx_v_df21, __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c0300)), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0210 = __Pyx_c_quot(__Pyx_c_sum(__pyx_v_df23, __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c0300)), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0030 = __pyx_v_f3;

  
  __pyx_v_c1020 = __Pyx_c_quot(__Pyx_c_sum(__pyx_v_df31, __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c0030)), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0120 = __Pyx_c_quot(__Pyx_c_sum(__pyx_v_df32, __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c0030)), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c2001 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c2100, __pyx_v_c2010), __pyx_v_c3000), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0201 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c1200, __pyx_v_c0300), __pyx_v_c0210), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0021 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c1020, __pyx_v_c0120), __pyx_v_c0030), __pyx_t_double_complex_from_parts(3, 0));

  
  for (__pyx_t_1 = 0; __pyx_t_1 < 3; __pyx_t_1+=1) {
    __pyx_v_k = __pyx_t_1;

    
    __pyx_v_itri = (__pyx_v_d->neighbors[((3 * __pyx_v_isimplex) + __pyx_v_k)]);

    
    __pyx_t_2 = (__pyx_v_itri == -1);
    if (__pyx_t_2) {

      
      switch (__pyx_v_k) {
        case 0:

        
        __pyx_v_g1 = ((-2.0) / 3);
        break;

        
        case 1:

        
        __pyx_v_g2 = ((-2.0) / 3);
        break;

        
        case 2:

        
        __pyx_v_g3 = ((-2.0) / 3);
        break;
      }

      
      goto __pyx_L3_continue;
      goto __pyx_L5;
    }
    __pyx_L5:;

    
    (__pyx_v_y[0]) = ((((__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 0)])))]) + (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 1)])))])) + (__pyx_v_d->points[(0 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 2)])))])) / 3);

    
    (__pyx_v_y[1]) = ((((__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 0)])))]) + (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 1)])))])) + (__pyx_v_d->points[(1 + (2 * (__pyx_v_d->vertices[((3 * __pyx_v_itri) + 2)])))])) / 3);

    
    __pyx_f_5scipy_7spatial_5qhull__barycentric_coordinates(2, (__pyx_v_d->transform + ((__pyx_v_isimplex * 2) * 3)), __pyx_v_y, __pyx_v_c);

    
    switch (__pyx_v_k) {
      case 0:

      
      __pyx_v_g1 = ((((2 * (__pyx_v_c[2])) + (__pyx_v_c[1])) - 1) / ((2 - (3 * (__pyx_v_c[2]))) - (3 * (__pyx_v_c[1]))));
      break;

      
      case 1:

      
      __pyx_v_g2 = ((((2 * (__pyx_v_c[0])) + (__pyx_v_c[2])) - 1) / ((2 - (3 * (__pyx_v_c[0]))) - (3 * (__pyx_v_c[2]))));
      break;

      
      case 2:

      
      __pyx_v_g3 = ((((2 * (__pyx_v_c[1])) + (__pyx_v_c[0])) - 1) / ((2 - (3 * (__pyx_v_c[1]))) - (3 * (__pyx_v_c[0]))));
      break;
    }
    __pyx_L3_continue:;
  }

  
  __pyx_v_c0111 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_prod(__pyx_t_double_complex_from_parts(__pyx_v_g1, 0), __Pyx_c_sum(__Pyx_c_diff(__Pyx_c_sum(__Pyx_c_neg(__pyx_v_c0300), __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c0210)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c0120)), __pyx_v_c0030)), __Pyx_c_sum(__Pyx_c_sum(__Pyx_c_diff(__Pyx_c_sum(__Pyx_c_neg(__pyx_v_c0300), __Pyx_c_prod(__pyx_t_double_complex_from_parts(2, 0), __pyx_v_c0210)), __pyx_v_c0120), __pyx_v_c0021), __pyx_v_c0201)), __pyx_t_double_complex_from_parts(2, 0));

  
  __pyx_v_c1011 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_prod(__pyx_t_double_complex_from_parts(__pyx_v_g2, 0), __Pyx_c_sum(__Pyx_c_diff(__Pyx_c_sum(__Pyx_c_neg(__pyx_v_c0030), __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c1020)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c2010)), __pyx_v_c3000)), __Pyx_c_sum(__Pyx_c_sum(__Pyx_c_diff(__Pyx_c_sum(__Pyx_c_neg(__pyx_v_c0030), __Pyx_c_prod(__pyx_t_double_complex_from_parts(2, 0), __pyx_v_c1020)), __pyx_v_c2010), __pyx_v_c2001), __pyx_v_c0021)), __pyx_t_double_complex_from_parts(2, 0));

  
  __pyx_v_c1101 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_prod(__pyx_t_double_complex_from_parts(__pyx_v_g3, 0), __Pyx_c_sum(__Pyx_c_diff(__Pyx_c_sum(__Pyx_c_neg(__pyx_v_c3000), __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c2100)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(3, 0), __pyx_v_c1200)), __pyx_v_c0300)), __Pyx_c_sum(__Pyx_c_sum(__Pyx_c_diff(__Pyx_c_sum(__Pyx_c_neg(__pyx_v_c3000), __Pyx_c_prod(__pyx_t_double_complex_from_parts(2, 0), __pyx_v_c2100)), __pyx_v_c1200), __pyx_v_c2001), __pyx_v_c0201)), __pyx_t_double_complex_from_parts(2, 0));

  
  __pyx_v_c1002 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c1101, __pyx_v_c1011), __pyx_v_c2001), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0102 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c1101, __pyx_v_c0111), __pyx_v_c0201), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0012 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c1011, __pyx_v_c0111), __pyx_v_c0021), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_c0003 = __Pyx_c_quot(__Pyx_c_sum(__Pyx_c_sum(__pyx_v_c1002, __pyx_v_c0102), __pyx_v_c0012), __pyx_t_double_complex_from_parts(3, 0));

  
  __pyx_v_minval = (__pyx_v_b[0]);

  
  for (__pyx_t_1 = 0; __pyx_t_1 < 3; __pyx_t_1+=1) {
    __pyx_v_k = __pyx_t_1;

    
    __pyx_t_2 = ((__pyx_v_b[__pyx_v_k]) < __pyx_v_minval);
    if (__pyx_t_2) {

      
      __pyx_v_minval = (__pyx_v_b[__pyx_v_k]);
      goto __pyx_L8;
    }
    __pyx_L8:;
  }

  
  __pyx_v_b1 = ((__pyx_v_b[0]) - __pyx_v_minval);

  
  __pyx_v_b2 = ((__pyx_v_b[1]) - __pyx_v_minval);

  
  __pyx_v_b3 = ((__pyx_v_b[2]) - __pyx_v_minval);

  
  __pyx_v_b4 = (3 * __pyx_v_minval);

  
  __pyx_v_w = __Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_sum(__Pyx_c_prod(__pyx_t_double_complex_from_parts(pow(__pyx_v_b1, 3), 0), __pyx_v_c3000), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * pow(__pyx_v_b1, 2)) * __pyx_v_b2), 0), __pyx_v_c2100)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * pow(__pyx_v_b1, 2)) * __pyx_v_b3), 0), __pyx_v_c2010)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * pow(__pyx_v_b1, 2)) * __pyx_v_b4), 0), __pyx_v_c2001)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * __pyx_v_b1) * pow(__pyx_v_b2, 2)), 0), __pyx_v_c1200)), __Pyx_c_prod(__pyx_t_double_complex_from_parts((((6 * __pyx_v_b1) * __pyx_v_b2) * __pyx_v_b4), 0), __pyx_v_c1101)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * __pyx_v_b1) * pow(__pyx_v_b3, 2)), 0), __pyx_v_c1020)), __Pyx_c_prod(__pyx_t_double_complex_from_parts((((6 * __pyx_v_b1) * __pyx_v_b3) * __pyx_v_b4), 0), __pyx_v_c1011)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * __pyx_v_b1) * pow(__pyx_v_b4, 2)), 0), __pyx_v_c1002)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(pow(__pyx_v_b2, 3), 0), __pyx_v_c0300)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * pow(__pyx_v_b2, 2)) * __pyx_v_b3), 0), __pyx_v_c0210)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * pow(__pyx_v_b2, 2)) * __pyx_v_b4), 0), __pyx_v_c0201)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * __pyx_v_b2) * pow(__pyx_v_b3, 2)), 0), __pyx_v_c0120)), __Pyx_c_prod(__pyx_t_double_complex_from_parts((((6 * __pyx_v_b2) * __pyx_v_b3) * __pyx_v_b4), 0), __pyx_v_c0111)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * __pyx_v_b2) * pow(__pyx_v_b4, 2)), 0), __pyx_v_c0102)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(pow(__pyx_v_b3, 3), 0), __pyx_v_c0030)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * pow(__pyx_v_b3, 2)) * __pyx_v_b4), 0), __pyx_v_c0021)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(((3 * __pyx_v_b3) * pow(__pyx_v_b4, 2)), 0), __pyx_v_c0012)), __Pyx_c_prod(__pyx_t_double_complex_from_parts(pow(__pyx_v_b4, 3), 0), __pyx_v_c0003));

  
  __pyx_r = __pyx_v_w;
  goto __pyx_L0;

  __pyx_r = __pyx_t_double_complex_from_parts(0, 0);
  __pyx_L0:;
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_26CloughTocher2DInterpolator___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_26CloughTocher2DInterpolator___init__ = {__Pyx_NAMESTR("__init__"), (PyCFunction)__pyx_pf_8interpnd_26CloughTocher2DInterpolator___init__, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_26CloughTocher2DInterpolator___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_points = 0;
  PyObject *__pyx_v_values = 0;
  PyObject *__pyx_v_fill_value = 0;
  PyObject *__pyx_v_tol = 0;
  PyObject *__pyx_v_maxiter = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__points,&__pyx_n_s__values,&__pyx_n_s__fill_value,&__pyx_n_s__tol,&__pyx_n_s__maxiter,0};
  __Pyx_RefNannySetupContext("__init__");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[6] = {0,0,0,0,0,0};
    values[3] = __pyx_k_15;
    values[4] = __pyx_k_16;
    values[5] = ((PyObject *)__pyx_int_400);
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  6: values[5] = PyTuple_GET_ITEM(__pyx_args, 5);
      case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
      case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__points);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 6, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  2:
      values[2] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__values);
      if (likely(values[2])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 6, 2); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
      case  3:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__fill_value);
        if (unlikely(value)) { values[3] = value; kw_args--; }
      }
      case  4:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__tol);
        if (unlikely(value)) { values[4] = value; kw_args--; }
      }
      case  5:
      if (kw_args > 0) {
        PyObject* value = PyDict_GetItem(__pyx_kwds, __pyx_n_s__maxiter);
        if (unlikely(value)) { values[5] = value; kw_args--; }
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "__init__") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_points = values[1];
    __pyx_v_values = values[2];
    __pyx_v_fill_value = values[3];
    __pyx_v_tol = values[4];
    __pyx_v_maxiter = values[5];
  } else {
    __pyx_v_fill_value = __pyx_k_15;
    __pyx_v_tol = __pyx_k_16;
    __pyx_v_maxiter = ((PyObject *)__pyx_int_400);
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  6:
      __pyx_v_maxiter = PyTuple_GET_ITEM(__pyx_args, 5);
      case  5:
      __pyx_v_tol = PyTuple_GET_ITEM(__pyx_args, 4);
      case  4:
      __pyx_v_fill_value = PyTuple_GET_ITEM(__pyx_args, 3);
      case  3:
      __pyx_v_values = PyTuple_GET_ITEM(__pyx_args, 2);
      __pyx_v_points = PyTuple_GET_ITEM(__pyx_args, 1);
      __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
      break;
      default: goto __pyx_L5_argtuple_error;
    }
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 3, 6, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.CloughTocher2DInterpolator.__init__");
  return NULL;
  __pyx_L4_argument_unpacking_done:;

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s____init__); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_self);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_self);
  __Pyx_GIVEREF(__pyx_v_self);
  __Pyx_INCREF(__pyx_v_points);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_v_points);
  __Pyx_GIVEREF(__pyx_v_points);
  __Pyx_INCREF(__pyx_v_values);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_v_values);
  __Pyx_GIVEREF(__pyx_v_values);
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_n_s__ndim), __pyx_int_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}

  
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_n_s__fill_value), __pyx_v_fill_value) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = PyEval_CallObjectWithKeywords(__pyx_t_2, __pyx_t_1, ((PyObject *)__pyx_t_3)); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1050; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__qhull); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1052; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__Delaunay); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1052; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1052; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_v_points);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_v_points);
  __Pyx_GIVEREF(__pyx_v_points);
  __pyx_t_1 = PyObject_Call(__pyx_t_3, __pyx_t_4, NULL); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1052; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__tri, __pyx_t_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1052; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_GetName(__pyx_m, __pyx_n_s_12); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));

  
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_n_s__tol), __pyx_v_tol) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_n_s__maxiter), __pyx_v_maxiter) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = PyEval_CallObjectWithKeywords(__pyx_t_1, __pyx_t_2, ((PyObject *)__pyx_t_3)); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;

  
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_s__grad, __pyx_t_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1053; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("interpnd.CloughTocher2DInterpolator.__init__");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_26CloughTocher2DInterpolator__evaluate_double(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_26CloughTocher2DInterpolator__evaluate_double = {__Pyx_NAMESTR("_evaluate_double"), (PyCFunction)__pyx_pf_8interpnd_26CloughTocher2DInterpolator__evaluate_double, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_26CloughTocher2DInterpolator__evaluate_double(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyArrayObject *__pyx_v_xi = 0;
  PyArrayObject *__pyx_v_values = 0;
  PyArrayObject *__pyx_v_grad = 0;
  PyArrayObject *__pyx_v_out;
  PyArrayObject *__pyx_v_points = 0;
  PyArrayObject *__pyx_v_vertices = 0;
  double __pyx_v_c[NPY_MAXDIMS];
  double __pyx_v_f[(NPY_MAXDIMS + 1)];
  double __pyx_v_df[((2 * NPY_MAXDIMS) + 2)];
  double __pyx_v_w;
  double __pyx_v_fill_value;
  int __pyx_v_i;
  int __pyx_v_j;
  int __pyx_v_k;
  int __pyx_v_ndim;
  int __pyx_v_isimplex;
  int __pyx_v_start;
  int __pyx_v_nvalues;
  __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_info;
  PyObject *__pyx_v_eps;
  Py_buffer __pyx_bstruct_xi;
  Py_ssize_t __pyx_bstride_0_xi = 0;
  Py_ssize_t __pyx_bstride_1_xi = 0;
  Py_ssize_t __pyx_bshape_0_xi = 0;
  Py_ssize_t __pyx_bshape_1_xi = 0;
  Py_buffer __pyx_bstruct_out;
  Py_ssize_t __pyx_bstride_0_out = 0;
  Py_ssize_t __pyx_bstride_1_out = 0;
  Py_ssize_t __pyx_bshape_0_out = 0;
  Py_ssize_t __pyx_bshape_1_out = 0;
  Py_buffer __pyx_bstruct_vertices;
  Py_ssize_t __pyx_bstride_0_vertices = 0;
  Py_ssize_t __pyx_bstride_1_vertices = 0;
  Py_ssize_t __pyx_bshape_0_vertices = 0;
  Py_ssize_t __pyx_bshape_1_vertices = 0;
  Py_buffer __pyx_bstruct_points;
  Py_ssize_t __pyx_bstride_0_points = 0;
  Py_ssize_t __pyx_bstride_1_points = 0;
  Py_ssize_t __pyx_bshape_0_points = 0;
  Py_ssize_t __pyx_bshape_1_points = 0;
  Py_buffer __pyx_bstruct_values;
  Py_ssize_t __pyx_bstride_0_values = 0;
  Py_ssize_t __pyx_bstride_1_values = 0;
  Py_ssize_t __pyx_bshape_0_values = 0;
  Py_ssize_t __pyx_bshape_1_values = 0;
  Py_buffer __pyx_bstruct_grad;
  Py_ssize_t __pyx_bstride_0_grad = 0;
  Py_ssize_t __pyx_bstride_1_grad = 0;
  Py_ssize_t __pyx_bstride_2_grad = 0;
  Py_ssize_t __pyx_bshape_0_grad = 0;
  Py_ssize_t __pyx_bshape_1_grad = 0;
  Py_ssize_t __pyx_bshape_2_grad = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyArrayObject *__pyx_t_2 = NULL;
  PyArrayObject *__pyx_t_3 = NULL;
  PyArrayObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyArrayObject *__pyx_t_6 = NULL;
  double __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyArrayObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  npy_intp __pyx_t_16;
  int __pyx_t_17;
  int __pyx_t_18;
  int __pyx_t_19;
  int __pyx_t_20;
  int __pyx_t_21;
  long __pyx_t_22;
  int __pyx_t_23;
  int __pyx_t_24;
  int __pyx_t_25;
  npy_int __pyx_t_26;
  int __pyx_t_27;
  int __pyx_t_28;
  int __pyx_t_29;
  npy_int __pyx_t_30;
  int __pyx_t_31;
  long __pyx_t_32;
  int __pyx_t_33;
  int __pyx_t_34;
  npy_int __pyx_t_35;
  int __pyx_t_36;
  long __pyx_t_37;
  int __pyx_t_38;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__xi,0};
  __Pyx_RefNannySetupContext("_evaluate_double");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[2] = {0,0};
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__xi);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_evaluate_double", 1, 2, 2, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "_evaluate_double") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_xi = ((PyArrayObject *)values[1]);
  } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
    goto __pyx_L5_argtuple_error;
  } else {
    __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
    __pyx_v_xi = ((PyArrayObject *)PyTuple_GET_ITEM(__pyx_args, 1));
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("_evaluate_double", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.CloughTocher2DInterpolator._evaluate_double");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF((PyObject *)__pyx_v_xi);
  __pyx_v_out = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_eps = Py_None; __Pyx_INCREF(Py_None);
  __pyx_bstruct_values.buf = NULL;
  __pyx_bstruct_grad.buf = NULL;
  __pyx_bstruct_out.buf = NULL;
  __pyx_bstruct_points.buf = NULL;
  __pyx_bstruct_vertices.buf = NULL;
  __pyx_bstruct_xi.buf = NULL;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_xi), __pyx_ptype_5numpy_ndarray, 1, "xi", 0))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_xi, (PyObject*)__pyx_v_xi, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_bstride_0_xi = __pyx_bstruct_xi.strides[0]; __pyx_bstride_1_xi = __pyx_bstruct_xi.strides[1];
  __pyx_bshape_0_xi = __pyx_bstruct_xi.shape[0]; __pyx_bshape_1_xi = __pyx_bstruct_xi.shape[1];

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1059; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1059; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_2 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_values, (PyObject*)__pyx_t_2, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_values = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_values.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1059; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_values = __pyx_bstruct_values.strides[0]; __pyx_bstride_1_values = __pyx_bstruct_values.strides[1];
      __pyx_bshape_0_values = __pyx_bstruct_values.shape[0]; __pyx_bshape_1_values = __pyx_bstruct_values.shape[1];
    }
  }
  __pyx_t_2 = 0;
  __pyx_v_values = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__grad); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1060; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1060; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_3 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_grad, (PyObject*)__pyx_t_3, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 3, 0, __pyx_stack) == -1)) {
      __pyx_v_grad = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_grad.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1060; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_grad = __pyx_bstruct_grad.strides[0]; __pyx_bstride_1_grad = __pyx_bstruct_grad.strides[1]; __pyx_bstride_2_grad = __pyx_bstruct_grad.strides[2];
      __pyx_bshape_0_grad = __pyx_bstruct_grad.shape[0]; __pyx_bshape_1_grad = __pyx_bstruct_grad.shape[1]; __pyx_bshape_2_grad = __pyx_bstruct_grad.shape[2];
    }
  }
  __pyx_t_3 = 0;
  __pyx_v_grad = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__points); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1062; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1062; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_points, (PyObject*)__pyx_t_4, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_points = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_points.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1062; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_points = __pyx_bstruct_points.strides[0]; __pyx_bstride_1_points = __pyx_bstruct_points.strides[1];
      __pyx_bshape_0_points = __pyx_bstruct_points.shape[0]; __pyx_bshape_1_points = __pyx_bstruct_points.shape[1];
    }
  }
  __pyx_t_4 = 0;
  __pyx_v_points = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1063; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__vertices); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1063; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (!(likely(((__pyx_t_5) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_5, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1063; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_6 = ((PyArrayObject *)__pyx_t_5);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_vertices, (PyObject*)__pyx_t_6, &__Pyx_TypeInfo_nn_npy_int, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_vertices = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_vertices.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1063; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_vertices = __pyx_bstruct_vertices.strides[0]; __pyx_bstride_1_vertices = __pyx_bstruct_vertices.strides[1];
      __pyx_bshape_0_vertices = __pyx_bstruct_vertices.shape[0]; __pyx_bshape_1_vertices = __pyx_bstruct_vertices.shape[1];
    }
  }
  __pyx_t_6 = 0;
  __pyx_v_vertices = ((PyArrayObject *)__pyx_t_5);
  __pyx_t_5 = 0;

  
  __pyx_v_ndim = (__pyx_v_xi->dimensions[1]);

  
  __pyx_v_start = 0;

  
  __pyx_t_5 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__fill_value); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1074; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = __pyx_PyFloat_AsDouble(__pyx_t_5); if (unlikely((__pyx_t_7 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1074; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_fill_value = __pyx_t_7;

  
  __pyx_t_5 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1076; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_v_info = __pyx_f_5scipy_7spatial_5qhull__get_delaunay_info(__pyx_t_5, 1, 1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__zeros); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyInt_to_py_npy_intp((__pyx_v_xi->dimensions[0])); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_8 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_8, __pyx_n_s__shape); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_GetItemInt(__pyx_t_9, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyTuple_New(2); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_9, 1, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  __pyx_t_5 = 0;
  __pyx_t_8 = 0;
  __pyx_t_8 = PyTuple_New(1); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_9);
  __pyx_t_9 = 0;
  __pyx_t_9 = PyDict_New(); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_9));
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_10 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__double); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_9, ((PyObject *)__pyx_n_s__dtype), __pyx_t_10) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = PyEval_CallObjectWithKeywords(__pyx_t_1, __pyx_t_8, ((PyObject *)__pyx_t_9)); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_9)); __pyx_t_9 = 0;
  if (!(likely(((__pyx_t_10) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_10, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_11 = ((PyArrayObject *)__pyx_t_10);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
    __pyx_t_12 = __Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_t_11, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES| PyBUF_WRITABLE, 2, 0, __pyx_stack);
    if (unlikely(__pyx_t_12 < 0)) {
      PyErr_Fetch(&__pyx_t_13, &__pyx_t_14, &__pyx_t_15);
      if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_v_out, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES| PyBUF_WRITABLE, 2, 0, __pyx_stack) == -1)) {
        Py_XDECREF(__pyx_t_13); Py_XDECREF(__pyx_t_14); Py_XDECREF(__pyx_t_15);
        __Pyx_RaiseBufferFallbackError();
      } else {
        PyErr_Restore(__pyx_t_13, __pyx_t_14, __pyx_t_15);
      }
    }
    __pyx_bstride_0_out = __pyx_bstruct_out.strides[0]; __pyx_bstride_1_out = __pyx_bstruct_out.strides[1];
    __pyx_bshape_0_out = __pyx_bstruct_out.shape[0]; __pyx_bshape_1_out = __pyx_bstruct_out.shape[1];
    if (unlikely(__pyx_t_12 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1078; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_t_11 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_v_out));
  __pyx_v_out = ((PyArrayObject *)__pyx_t_10);
  __pyx_t_10 = 0;

  
  __pyx_v_nvalues = (__pyx_v_out->dimensions[1]);

  
  __pyx_t_10 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_10, __pyx_n_s__finfo); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_8 = PyObject_GetAttr(__pyx_t_10, __pyx_n_s__double); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = PyTuple_New(1); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = PyObject_Call(__pyx_t_9, __pyx_t_10, NULL); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = PyObject_GetAttr(__pyx_t_8, __pyx_n_s__eps); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyNumber_Multiply(__pyx_t_10, __pyx_int_100); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1081; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __Pyx_DECREF(__pyx_v_eps);
  __pyx_v_eps = __pyx_t_8;
  __pyx_t_8 = 0;

  
  { PyThreadState *_save;
    Py_UNBLOCK_THREADS
     {

      
      __pyx_t_16 = (__pyx_v_xi->dimensions[0]);
      for (__pyx_t_12 = 0; __pyx_t_12 < __pyx_t_16; __pyx_t_12+=1) {
        __pyx_v_i = __pyx_t_12;

        
        __pyx_t_7 = __pyx_PyFloat_AsDouble(__pyx_v_eps); if (unlikely((__pyx_t_7 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1089; __pyx_clineno = __LINE__; goto __pyx_L7;}
        __pyx_v_isimplex = __pyx_f_5scipy_7spatial_5qhull__find_simplex(__pyx_v_info, __pyx_v_c, (((double *)__pyx_v_xi->data) + (__pyx_v_i * __pyx_v_ndim)), (&__pyx_v_start), __pyx_t_7);

        
        __pyx_t_17 = (__pyx_v_isimplex == -1);
        if (__pyx_t_17) {

          
          __pyx_t_18 = __pyx_v_nvalues;
          for (__pyx_t_19 = 0; __pyx_t_19 < __pyx_t_18; __pyx_t_19+=1) {
            __pyx_v_k = __pyx_t_19;

            
            __pyx_t_20 = __pyx_v_i;
            __pyx_t_21 = __pyx_v_k;
            if (__pyx_t_20 < 0) __pyx_t_20 += __pyx_bshape_0_out;
            if (__pyx_t_21 < 0) __pyx_t_21 += __pyx_bshape_1_out;
            *__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_out.buf, __pyx_t_20, __pyx_bstride_0_out, __pyx_t_21, __pyx_bstride_1_out) = __pyx_v_fill_value;
          }

          
          goto __pyx_L9_continue;
          goto __pyx_L11;
        }
        __pyx_L11:;

        
        __pyx_t_18 = __pyx_v_nvalues;
        for (__pyx_t_19 = 0; __pyx_t_19 < __pyx_t_18; __pyx_t_19+=1) {
          __pyx_v_k = __pyx_t_19;

          
          __pyx_t_22 = (__pyx_v_ndim + 1);
          for (__pyx_t_23 = 0; __pyx_t_23 < __pyx_t_22; __pyx_t_23+=1) {
            __pyx_v_j = __pyx_t_23;

            
            __pyx_t_24 = __pyx_v_isimplex;
            __pyx_t_25 = __pyx_v_j;
            if (__pyx_t_24 < 0) __pyx_t_24 += __pyx_bshape_0_vertices;
            if (__pyx_t_25 < 0) __pyx_t_25 += __pyx_bshape_1_vertices;
            __pyx_t_26 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_24, __pyx_bstride_0_vertices, __pyx_t_25, __pyx_bstride_1_vertices));
            __pyx_t_27 = __pyx_v_k;
            if (__pyx_t_26 < 0) __pyx_t_26 += __pyx_bshape_0_values;
            if (__pyx_t_27 < 0) __pyx_t_27 += __pyx_bshape_1_values;
            (__pyx_v_f[__pyx_v_j]) = (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_values.buf, __pyx_t_26, __pyx_bstride_0_values, __pyx_t_27, __pyx_bstride_1_values));

            
            __pyx_t_28 = __pyx_v_isimplex;
            __pyx_t_29 = __pyx_v_j;
            if (__pyx_t_28 < 0) __pyx_t_28 += __pyx_bshape_0_vertices;
            if (__pyx_t_29 < 0) __pyx_t_29 += __pyx_bshape_1_vertices;
            __pyx_t_30 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_28, __pyx_bstride_0_vertices, __pyx_t_29, __pyx_bstride_1_vertices));
            __pyx_t_31 = __pyx_v_k;
            __pyx_t_32 = 0;
            if (__pyx_t_30 < 0) __pyx_t_30 += __pyx_bshape_0_grad;
            if (__pyx_t_31 < 0) __pyx_t_31 += __pyx_bshape_1_grad;
            if (__pyx_t_32 < 0) __pyx_t_32 += __pyx_bshape_2_grad;
            (__pyx_v_df[(2 * __pyx_v_j)]) = (*__Pyx_BufPtrStrided3d(__pyx_t_5numpy_double_t *, __pyx_bstruct_grad.buf, __pyx_t_30, __pyx_bstride_0_grad, __pyx_t_31, __pyx_bstride_1_grad, __pyx_t_32, __pyx_bstride_2_grad));

            
            __pyx_t_33 = __pyx_v_isimplex;
            __pyx_t_34 = __pyx_v_j;
            if (__pyx_t_33 < 0) __pyx_t_33 += __pyx_bshape_0_vertices;
            if (__pyx_t_34 < 0) __pyx_t_34 += __pyx_bshape_1_vertices;
            __pyx_t_35 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_33, __pyx_bstride_0_vertices, __pyx_t_34, __pyx_bstride_1_vertices));
            __pyx_t_36 = __pyx_v_k;
            __pyx_t_37 = 1;
            if (__pyx_t_35 < 0) __pyx_t_35 += __pyx_bshape_0_grad;
            if (__pyx_t_36 < 0) __pyx_t_36 += __pyx_bshape_1_grad;
            if (__pyx_t_37 < 0) __pyx_t_37 += __pyx_bshape_2_grad;
            (__pyx_v_df[((2 * __pyx_v_j) + 1)]) = (*__Pyx_BufPtrStrided3d(__pyx_t_5numpy_double_t *, __pyx_bstruct_grad.buf, __pyx_t_35, __pyx_bstride_0_grad, __pyx_t_36, __pyx_bstride_1_grad, __pyx_t_37, __pyx_bstride_2_grad));
          }

          
          __pyx_v_w = __pyx_f_8interpnd__clough_tocher_2d_single_double(__pyx_v_info, __pyx_v_isimplex, __pyx_v_c, __pyx_v_f, __pyx_v_df);

          
          __pyx_t_23 = __pyx_v_i;
          __pyx_t_38 = __pyx_v_k;
          if (__pyx_t_23 < 0) __pyx_t_23 += __pyx_bshape_0_out;
          if (__pyx_t_38 < 0) __pyx_t_38 += __pyx_bshape_1_out;
          *__Pyx_BufPtrStrided2d(__pyx_t_5numpy_double_t *, __pyx_bstruct_out.buf, __pyx_t_23, __pyx_bstride_0_out, __pyx_t_38, __pyx_bstride_1_out) = __pyx_v_w;
        }
        __pyx_L9_continue:;
      }
    }
     {
      int __pyx_why;
      __pyx_why = 0; goto __pyx_L8;
      __pyx_L7: __pyx_why = 4; goto __pyx_L8;
      __pyx_L8:;

      
      Py_BLOCK_THREADS
      switch (__pyx_why) {
        case 4: goto __pyx_L1_error;
      }
    }
  }

  
  free(((void *)__pyx_v_info));

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(((PyObject *)__pyx_v_out));
  __pyx_r = ((PyObject *)__pyx_v_out);
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  { PyObject *__pyx_type, *__pyx_value, *__pyx_tb;
    __Pyx_ErrFetch(&__pyx_type, &__pyx_value, &__pyx_tb);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
  __Pyx_ErrRestore(__pyx_type, __pyx_value, __pyx_tb);}
  __Pyx_AddTraceback("interpnd.CloughTocher2DInterpolator._evaluate_double");
  __pyx_r = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
  __pyx_L2:;
  __Pyx_XDECREF((PyObject *)__pyx_v_values);
  __Pyx_XDECREF((PyObject *)__pyx_v_grad);
  __Pyx_DECREF((PyObject *)__pyx_v_out);
  __Pyx_XDECREF((PyObject *)__pyx_v_points);
  __Pyx_XDECREF((PyObject *)__pyx_v_vertices);
  __Pyx_DECREF(__pyx_v_eps);
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF((PyObject *)__pyx_v_xi);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_8interpnd_26CloughTocher2DInterpolator__evaluate_complex(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_8interpnd_26CloughTocher2DInterpolator__evaluate_complex = {__Pyx_NAMESTR("_evaluate_complex"), (PyCFunction)__pyx_pf_8interpnd_26CloughTocher2DInterpolator__evaluate_complex, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)};
static PyObject *__pyx_pf_8interpnd_26CloughTocher2DInterpolator__evaluate_complex(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyArrayObject *__pyx_v_xi = 0;
  PyArrayObject *__pyx_v_values = 0;
  PyArrayObject *__pyx_v_grad = 0;
  PyArrayObject *__pyx_v_out;
  PyArrayObject *__pyx_v_points = 0;
  PyArrayObject *__pyx_v_vertices = 0;
  double __pyx_v_c[NPY_MAXDIMS];
  __pyx_t_double_complex __pyx_v_f[(NPY_MAXDIMS + 1)];
  __pyx_t_double_complex __pyx_v_df[((2 * NPY_MAXDIMS) + 2)];
  __pyx_t_double_complex __pyx_v_w;
  __pyx_t_double_complex __pyx_v_fill_value;
  int __pyx_v_i;
  int __pyx_v_j;
  int __pyx_v_k;
  int __pyx_v_ndim;
  int __pyx_v_isimplex;
  int __pyx_v_start;
  int __pyx_v_nvalues;
  __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *__pyx_v_info;
  PyObject *__pyx_v_eps;
  Py_buffer __pyx_bstruct_xi;
  Py_ssize_t __pyx_bstride_0_xi = 0;
  Py_ssize_t __pyx_bstride_1_xi = 0;
  Py_ssize_t __pyx_bshape_0_xi = 0;
  Py_ssize_t __pyx_bshape_1_xi = 0;
  Py_buffer __pyx_bstruct_out;
  Py_ssize_t __pyx_bstride_0_out = 0;
  Py_ssize_t __pyx_bstride_1_out = 0;
  Py_ssize_t __pyx_bshape_0_out = 0;
  Py_ssize_t __pyx_bshape_1_out = 0;
  Py_buffer __pyx_bstruct_vertices;
  Py_ssize_t __pyx_bstride_0_vertices = 0;
  Py_ssize_t __pyx_bstride_1_vertices = 0;
  Py_ssize_t __pyx_bshape_0_vertices = 0;
  Py_ssize_t __pyx_bshape_1_vertices = 0;
  Py_buffer __pyx_bstruct_points;
  Py_ssize_t __pyx_bstride_0_points = 0;
  Py_ssize_t __pyx_bstride_1_points = 0;
  Py_ssize_t __pyx_bshape_0_points = 0;
  Py_ssize_t __pyx_bshape_1_points = 0;
  Py_buffer __pyx_bstruct_values;
  Py_ssize_t __pyx_bstride_0_values = 0;
  Py_ssize_t __pyx_bstride_1_values = 0;
  Py_ssize_t __pyx_bshape_0_values = 0;
  Py_ssize_t __pyx_bshape_1_values = 0;
  Py_buffer __pyx_bstruct_grad;
  Py_ssize_t __pyx_bstride_0_grad = 0;
  Py_ssize_t __pyx_bstride_1_grad = 0;
  Py_ssize_t __pyx_bstride_2_grad = 0;
  Py_ssize_t __pyx_bshape_0_grad = 0;
  Py_ssize_t __pyx_bshape_1_grad = 0;
  Py_ssize_t __pyx_bshape_2_grad = 0;
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyArrayObject *__pyx_t_2 = NULL;
  PyArrayObject *__pyx_t_3 = NULL;
  PyArrayObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyArrayObject *__pyx_t_6 = NULL;
  __pyx_t_double_complex __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyArrayObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  npy_intp __pyx_t_16;
  double __pyx_t_17;
  int __pyx_t_18;
  int __pyx_t_19;
  int __pyx_t_20;
  int __pyx_t_21;
  int __pyx_t_22;
  int __pyx_t_23;
  int __pyx_t_24;
  long __pyx_t_25;
  int __pyx_t_26;
  int __pyx_t_27;
  int __pyx_t_28;
  npy_int __pyx_t_29;
  int __pyx_t_30;
  int __pyx_t_31;
  int __pyx_t_32;
  npy_int __pyx_t_33;
  int __pyx_t_34;
  int __pyx_t_35;
  int __pyx_t_36;
  npy_int __pyx_t_37;
  int __pyx_t_38;
  long __pyx_t_39;
  int __pyx_t_40;
  int __pyx_t_41;
  npy_int __pyx_t_42;
  int __pyx_t_43;
  long __pyx_t_44;
  int __pyx_t_45;
  int __pyx_t_46;
  npy_int __pyx_t_47;
  int __pyx_t_48;
  long __pyx_t_49;
  int __pyx_t_50;
  int __pyx_t_51;
  npy_int __pyx_t_52;
  int __pyx_t_53;
  long __pyx_t_54;
  int __pyx_t_55;
  int __pyx_t_56;
  int __pyx_t_57;
  static PyObject **__pyx_pyargnames[] = {&__pyx_n_s__self,&__pyx_n_s__xi,0};
  __Pyx_RefNannySetupContext("_evaluate_complex");
  __pyx_self = __pyx_self;
  if (unlikely(__pyx_kwds)) {
    Py_ssize_t kw_args = PyDict_Size(__pyx_kwds);
    PyObject* values[2] = {0,0};
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      case  0: break;
      default: goto __pyx_L5_argtuple_error;
    }
    switch (PyTuple_GET_SIZE(__pyx_args)) {
      case  0:
      values[0] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__self);
      if (likely(values[0])) kw_args--;
      else goto __pyx_L5_argtuple_error;
      case  1:
      values[1] = PyDict_GetItem(__pyx_kwds, __pyx_n_s__xi);
      if (likely(values[1])) kw_args--;
      else {
        __Pyx_RaiseArgtupleInvalid("_evaluate_complex", 1, 2, 2, 1); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
      }
    }
    if (unlikely(kw_args > 0)) {
      if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, PyTuple_GET_SIZE(__pyx_args), "_evaluate_complex") < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
    }
    __pyx_v_self = values[0];
    __pyx_v_xi = ((PyArrayObject *)values[1]);
  } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
    goto __pyx_L5_argtuple_error;
  } else {
    __pyx_v_self = PyTuple_GET_ITEM(__pyx_args, 0);
    __pyx_v_xi = ((PyArrayObject *)PyTuple_GET_ITEM(__pyx_args, 1));
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("_evaluate_complex", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L3_error;}
  __pyx_L3_error:;
  __Pyx_AddTraceback("interpnd.CloughTocher2DInterpolator._evaluate_complex");
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_INCREF((PyObject *)__pyx_v_xi);
  __pyx_v_out = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_eps = Py_None; __Pyx_INCREF(Py_None);
  __pyx_bstruct_values.buf = NULL;
  __pyx_bstruct_grad.buf = NULL;
  __pyx_bstruct_out.buf = NULL;
  __pyx_bstruct_points.buf = NULL;
  __pyx_bstruct_vertices.buf = NULL;
  __pyx_bstruct_xi.buf = NULL;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_xi), __pyx_ptype_5numpy_ndarray, 1, "xi", 0))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_xi, (PyObject*)__pyx_v_xi, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_bstride_0_xi = __pyx_bstruct_xi.strides[0]; __pyx_bstride_1_xi = __pyx_bstruct_xi.strides[1];
  __pyx_bshape_0_xi = __pyx_bstruct_xi.shape[0]; __pyx_bshape_1_xi = __pyx_bstruct_xi.shape[1];

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1115; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1115; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_2 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[2];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_values, (PyObject*)__pyx_t_2, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_values = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_values.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1115; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_values = __pyx_bstruct_values.strides[0]; __pyx_bstride_1_values = __pyx_bstruct_values.strides[1];
      __pyx_bshape_0_values = __pyx_bstruct_values.shape[0]; __pyx_bshape_1_values = __pyx_bstruct_values.shape[1];
    }
  }
  __pyx_t_2 = 0;
  __pyx_v_values = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__grad); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1116; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1116; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_3 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[2];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_grad, (PyObject*)__pyx_t_3, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 3, 0, __pyx_stack) == -1)) {
      __pyx_v_grad = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_grad.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1116; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_grad = __pyx_bstruct_grad.strides[0]; __pyx_bstride_1_grad = __pyx_bstruct_grad.strides[1]; __pyx_bstride_2_grad = __pyx_bstruct_grad.strides[2];
      __pyx_bshape_0_grad = __pyx_bstruct_grad.shape[0]; __pyx_bshape_1_grad = __pyx_bstruct_grad.shape[1]; __pyx_bshape_2_grad = __pyx_bstruct_grad.shape[2];
    }
  }
  __pyx_t_3 = 0;
  __pyx_v_grad = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__points); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(((__pyx_t_1) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_1, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = ((PyArrayObject *)__pyx_t_1);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_points, (PyObject*)__pyx_t_4, &__Pyx_TypeInfo_nn___pyx_t_5numpy_double_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_points = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_points.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1118; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_points = __pyx_bstruct_points.strides[0]; __pyx_bstride_1_points = __pyx_bstruct_points.strides[1];
      __pyx_bshape_0_points = __pyx_bstruct_points.shape[0]; __pyx_bshape_1_points = __pyx_bstruct_points.shape[1];
    }
  }
  __pyx_t_4 = 0;
  __pyx_v_points = ((PyArrayObject *)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1119; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = PyObject_GetAttr(__pyx_t_1, __pyx_n_s__vertices); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1119; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (!(likely(((__pyx_t_5) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_5, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1119; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_6 = ((PyArrayObject *)__pyx_t_5);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_vertices, (PyObject*)__pyx_t_6, &__Pyx_TypeInfo_nn_npy_int, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
      __pyx_v_vertices = ((PyArrayObject *)Py_None); __Pyx_INCREF(Py_None); __pyx_bstruct_vertices.buf = NULL;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1119; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    } else {__pyx_bstride_0_vertices = __pyx_bstruct_vertices.strides[0]; __pyx_bstride_1_vertices = __pyx_bstruct_vertices.strides[1];
      __pyx_bshape_0_vertices = __pyx_bstruct_vertices.shape[0]; __pyx_bshape_1_vertices = __pyx_bstruct_vertices.shape[1];
    }
  }
  __pyx_t_6 = 0;
  __pyx_v_vertices = ((PyArrayObject *)__pyx_t_5);
  __pyx_t_5 = 0;

  
  __pyx_v_ndim = (__pyx_v_xi->dimensions[1]);

  
  __pyx_v_start = 0;

  
  __pyx_t_5 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__fill_value); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = __Pyx_PyComplex_As___pyx_t_double_complex(__pyx_t_5); if (unlikely(PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1130; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_fill_value = __pyx_t_7;

  
  __pyx_t_5 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__tri); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1132; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_v_info = __pyx_f_5scipy_7spatial_5qhull__get_delaunay_info(__pyx_t_5, 1, 1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__zeros); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyInt_to_py_npy_intp((__pyx_v_xi->dimensions[0])); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_8 = PyObject_GetAttr(__pyx_v_self, __pyx_n_s__values); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_8, __pyx_n_s__shape); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_GetItemInt(__pyx_t_9, 1, sizeof(long), PyInt_FromLong); if (!__pyx_t_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_9 = PyTuple_New(2); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_9, 1, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  __pyx_t_5 = 0;
  __pyx_t_8 = 0;
  __pyx_t_8 = PyTuple_New(1); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_9);
  __pyx_t_9 = 0;
  __pyx_t_9 = PyDict_New(); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_9));
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_10 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__complex); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_9, ((PyObject *)__pyx_n_s__dtype), __pyx_t_10) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = PyEval_CallObjectWithKeywords(__pyx_t_1, __pyx_t_8, ((PyObject *)__pyx_t_9)); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_9)); __pyx_t_9 = 0;
  if (!(likely(((__pyx_t_10) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_10, __pyx_ptype_5numpy_ndarray))))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_11 = ((PyArrayObject *)__pyx_t_10);
  {
    __Pyx_BufFmt_StackElem __pyx_stack[2];
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
    __pyx_t_12 = __Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_t_11, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack);
    if (unlikely(__pyx_t_12 < 0)) {
      PyErr_Fetch(&__pyx_t_13, &__pyx_t_14, &__pyx_t_15);
      if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_bstruct_out, (PyObject*)__pyx_v_out, &__Pyx_TypeInfo_nn___pyx_t_5numpy_complex_t, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) {
        Py_XDECREF(__pyx_t_13); Py_XDECREF(__pyx_t_14); Py_XDECREF(__pyx_t_15);
        __Pyx_RaiseBufferFallbackError();
      } else {
        PyErr_Restore(__pyx_t_13, __pyx_t_14, __pyx_t_15);
      }
    }
    __pyx_bstride_0_out = __pyx_bstruct_out.strides[0]; __pyx_bstride_1_out = __pyx_bstruct_out.strides[1];
    __pyx_bshape_0_out = __pyx_bstruct_out.shape[0]; __pyx_bshape_1_out = __pyx_bstruct_out.shape[1];
    if (unlikely(__pyx_t_12 < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1134; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  __pyx_t_11 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_v_out));
  __pyx_v_out = ((PyArrayObject *)__pyx_t_10);
  __pyx_t_10 = 0;

  
  __pyx_v_nvalues = (__pyx_v_out->dimensions[1]);

  
  __pyx_t_10 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_9 = PyObject_GetAttr(__pyx_t_10, __pyx_n_s__finfo); if (unlikely(!__pyx_t_9)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_8 = PyObject_GetAttr(__pyx_t_10, __pyx_n_s__double); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = PyTuple_New(1); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = PyObject_Call(__pyx_t_9, __pyx_t_10, NULL); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = PyObject_GetAttr(__pyx_t_8, __pyx_n_s__eps); if (unlikely(!__pyx_t_10)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyNumber_Multiply(__pyx_t_10, __pyx_int_100); if (unlikely(!__pyx_t_8)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1137; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __Pyx_DECREF(__pyx_v_eps);
  __pyx_v_eps = __pyx_t_8;
  __pyx_t_8 = 0;

  
  { PyThreadState *_save;
    Py_UNBLOCK_THREADS
     {

      
      __pyx_t_16 = (__pyx_v_xi->dimensions[0]);
      for (__pyx_t_12 = 0; __pyx_t_12 < __pyx_t_16; __pyx_t_12+=1) {
        __pyx_v_i = __pyx_t_12;

        
        __pyx_t_17 = __pyx_PyFloat_AsDouble(__pyx_v_eps); if (unlikely((__pyx_t_17 == (double)-1) && PyErr_Occurred())) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1145; __pyx_clineno = __LINE__; goto __pyx_L7;}
        __pyx_v_isimplex = __pyx_f_5scipy_7spatial_5qhull__find_simplex(__pyx_v_info, __pyx_v_c, (((double *)__pyx_v_xi->data) + (__pyx_v_i * __pyx_v_ndim)), (&__pyx_v_start), __pyx_t_17);

        
        __pyx_t_18 = (__pyx_v_isimplex == -1);
        if (__pyx_t_18) {

          
          __pyx_t_19 = __pyx_v_nvalues;
          for (__pyx_t_20 = 0; __pyx_t_20 < __pyx_t_19; __pyx_t_20+=1) {
            __pyx_v_k = __pyx_t_20;

            
            __pyx_t_21 = __pyx_v_i;
            __pyx_t_22 = __pyx_v_k;
            if (__pyx_t_21 < 0) __pyx_t_21 += __pyx_bshape_0_out;
            if (__pyx_t_22 < 0) __pyx_t_22 += __pyx_bshape_1_out;
            (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_21, __pyx_bstride_0_out, __pyx_t_22, __pyx_bstride_1_out)).real = __Pyx_CREAL(__pyx_v_fill_value);

            
            __pyx_t_23 = __pyx_v_i;
            __pyx_t_24 = __pyx_v_k;
            if (__pyx_t_23 < 0) __pyx_t_23 += __pyx_bshape_0_out;
            if (__pyx_t_24 < 0) __pyx_t_24 += __pyx_bshape_1_out;
            (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_23, __pyx_bstride_0_out, __pyx_t_24, __pyx_bstride_1_out)).imag = __Pyx_CIMAG(__pyx_v_fill_value);
          }

          
          goto __pyx_L9_continue;
          goto __pyx_L11;
        }
        __pyx_L11:;

        
        __pyx_t_19 = __pyx_v_nvalues;
        for (__pyx_t_20 = 0; __pyx_t_20 < __pyx_t_19; __pyx_t_20+=1) {
          __pyx_v_k = __pyx_t_20;

          
          __pyx_t_25 = (__pyx_v_ndim + 1);
          for (__pyx_t_26 = 0; __pyx_t_26 < __pyx_t_25; __pyx_t_26+=1) {
            __pyx_v_j = __pyx_t_26;

            
            __pyx_t_27 = __pyx_v_isimplex;
            __pyx_t_28 = __pyx_v_j;
            if (__pyx_t_27 < 0) __pyx_t_27 += __pyx_bshape_0_vertices;
            if (__pyx_t_28 < 0) __pyx_t_28 += __pyx_bshape_1_vertices;
            __pyx_t_29 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_27, __pyx_bstride_0_vertices, __pyx_t_28, __pyx_bstride_1_vertices));
            __pyx_t_30 = __pyx_v_k;
            if (__pyx_t_29 < 0) __pyx_t_29 += __pyx_bshape_0_values;
            if (__pyx_t_30 < 0) __pyx_t_30 += __pyx_bshape_1_values;
            __Pyx_SET_CREAL((__pyx_v_f[__pyx_v_j]), (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_values.buf, __pyx_t_29, __pyx_bstride_0_values, __pyx_t_30, __pyx_bstride_1_values)).real);

            
            __pyx_t_31 = __pyx_v_isimplex;
            __pyx_t_32 = __pyx_v_j;
            if (__pyx_t_31 < 0) __pyx_t_31 += __pyx_bshape_0_vertices;
            if (__pyx_t_32 < 0) __pyx_t_32 += __pyx_bshape_1_vertices;
            __pyx_t_33 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_31, __pyx_bstride_0_vertices, __pyx_t_32, __pyx_bstride_1_vertices));
            __pyx_t_34 = __pyx_v_k;
            if (__pyx_t_33 < 0) __pyx_t_33 += __pyx_bshape_0_values;
            if (__pyx_t_34 < 0) __pyx_t_34 += __pyx_bshape_1_values;
            __Pyx_SET_CIMAG((__pyx_v_f[__pyx_v_j]), (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_values.buf, __pyx_t_33, __pyx_bstride_0_values, __pyx_t_34, __pyx_bstride_1_values)).imag);

            
            __pyx_t_35 = __pyx_v_isimplex;
            __pyx_t_36 = __pyx_v_j;
            if (__pyx_t_35 < 0) __pyx_t_35 += __pyx_bshape_0_vertices;
            if (__pyx_t_36 < 0) __pyx_t_36 += __pyx_bshape_1_vertices;
            __pyx_t_37 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_35, __pyx_bstride_0_vertices, __pyx_t_36, __pyx_bstride_1_vertices));
            __pyx_t_38 = __pyx_v_k;
            __pyx_t_39 = 0;
            if (__pyx_t_37 < 0) __pyx_t_37 += __pyx_bshape_0_grad;
            if (__pyx_t_38 < 0) __pyx_t_38 += __pyx_bshape_1_grad;
            if (__pyx_t_39 < 0) __pyx_t_39 += __pyx_bshape_2_grad;
            __Pyx_SET_CREAL((__pyx_v_df[(2 * __pyx_v_j)]), (*__Pyx_BufPtrStrided3d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_grad.buf, __pyx_t_37, __pyx_bstride_0_grad, __pyx_t_38, __pyx_bstride_1_grad, __pyx_t_39, __pyx_bstride_2_grad)).real);

            
            __pyx_t_40 = __pyx_v_isimplex;
            __pyx_t_41 = __pyx_v_j;
            if (__pyx_t_40 < 0) __pyx_t_40 += __pyx_bshape_0_vertices;
            if (__pyx_t_41 < 0) __pyx_t_41 += __pyx_bshape_1_vertices;
            __pyx_t_42 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_40, __pyx_bstride_0_vertices, __pyx_t_41, __pyx_bstride_1_vertices));
            __pyx_t_43 = __pyx_v_k;
            __pyx_t_44 = 0;
            if (__pyx_t_42 < 0) __pyx_t_42 += __pyx_bshape_0_grad;
            if (__pyx_t_43 < 0) __pyx_t_43 += __pyx_bshape_1_grad;
            if (__pyx_t_44 < 0) __pyx_t_44 += __pyx_bshape_2_grad;
            __Pyx_SET_CIMAG((__pyx_v_df[(2 * __pyx_v_j)]), (*__Pyx_BufPtrStrided3d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_grad.buf, __pyx_t_42, __pyx_bstride_0_grad, __pyx_t_43, __pyx_bstride_1_grad, __pyx_t_44, __pyx_bstride_2_grad)).imag);

            
            __pyx_t_45 = __pyx_v_isimplex;
            __pyx_t_46 = __pyx_v_j;
            if (__pyx_t_45 < 0) __pyx_t_45 += __pyx_bshape_0_vertices;
            if (__pyx_t_46 < 0) __pyx_t_46 += __pyx_bshape_1_vertices;
            __pyx_t_47 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_45, __pyx_bstride_0_vertices, __pyx_t_46, __pyx_bstride_1_vertices));
            __pyx_t_48 = __pyx_v_k;
            __pyx_t_49 = 1;
            if (__pyx_t_47 < 0) __pyx_t_47 += __pyx_bshape_0_grad;
            if (__pyx_t_48 < 0) __pyx_t_48 += __pyx_bshape_1_grad;
            if (__pyx_t_49 < 0) __pyx_t_49 += __pyx_bshape_2_grad;
            __Pyx_SET_CREAL((__pyx_v_df[((2 * __pyx_v_j) + 1)]), (*__Pyx_BufPtrStrided3d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_grad.buf, __pyx_t_47, __pyx_bstride_0_grad, __pyx_t_48, __pyx_bstride_1_grad, __pyx_t_49, __pyx_bstride_2_grad)).real);

            
            __pyx_t_50 = __pyx_v_isimplex;
            __pyx_t_51 = __pyx_v_j;
            if (__pyx_t_50 < 0) __pyx_t_50 += __pyx_bshape_0_vertices;
            if (__pyx_t_51 < 0) __pyx_t_51 += __pyx_bshape_1_vertices;
            __pyx_t_52 = (*__Pyx_BufPtrStrided2d(npy_int *, __pyx_bstruct_vertices.buf, __pyx_t_50, __pyx_bstride_0_vertices, __pyx_t_51, __pyx_bstride_1_vertices));
            __pyx_t_53 = __pyx_v_k;
            __pyx_t_54 = 1;
            if (__pyx_t_52 < 0) __pyx_t_52 += __pyx_bshape_0_grad;
            if (__pyx_t_53 < 0) __pyx_t_53 += __pyx_bshape_1_grad;
            if (__pyx_t_54 < 0) __pyx_t_54 += __pyx_bshape_2_grad;
            __Pyx_SET_CIMAG((__pyx_v_df[((2 * __pyx_v_j) + 1)]), (*__Pyx_BufPtrStrided3d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_grad.buf, __pyx_t_52, __pyx_bstride_0_grad, __pyx_t_53, __pyx_bstride_1_grad, __pyx_t_54, __pyx_bstride_2_grad)).imag);
          }

          
          __pyx_v_w = __pyx_f_8interpnd__clough_tocher_2d_single_complex(__pyx_v_info, __pyx_v_isimplex, __pyx_v_c, __pyx_v_f, __pyx_v_df);

          
          __pyx_t_26 = __pyx_v_i;
          __pyx_t_55 = __pyx_v_k;
          if (__pyx_t_26 < 0) __pyx_t_26 += __pyx_bshape_0_out;
          if (__pyx_t_55 < 0) __pyx_t_55 += __pyx_bshape_1_out;
          (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_26, __pyx_bstride_0_out, __pyx_t_55, __pyx_bstride_1_out)).real = __Pyx_CREAL(__pyx_v_w);

          
          __pyx_t_56 = __pyx_v_i;
          __pyx_t_57 = __pyx_v_k;
          if (__pyx_t_56 < 0) __pyx_t_56 += __pyx_bshape_0_out;
          if (__pyx_t_57 < 0) __pyx_t_57 += __pyx_bshape_1_out;
          (*__Pyx_BufPtrStrided2d(__pyx_t_5numpy_complex_t *, __pyx_bstruct_out.buf, __pyx_t_56, __pyx_bstride_0_out, __pyx_t_57, __pyx_bstride_1_out)).imag = __Pyx_CIMAG(__pyx_v_w);
        }
        __pyx_L9_continue:;
      }
    }
     {
      int __pyx_why;
      __pyx_why = 0; goto __pyx_L8;
      __pyx_L7: __pyx_why = 4; goto __pyx_L8;
      __pyx_L8:;

      
      Py_BLOCK_THREADS
      switch (__pyx_why) {
        case 4: goto __pyx_L1_error;
      }
    }
  }

  
  free(((void *)__pyx_v_info));

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(((PyObject *)__pyx_v_out));
  __pyx_r = ((PyObject *)__pyx_v_out);
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  { PyObject *__pyx_type, *__pyx_value, *__pyx_tb;
    __Pyx_ErrFetch(&__pyx_type, &__pyx_value, &__pyx_tb);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
    __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
  __Pyx_ErrRestore(__pyx_type, __pyx_value, __pyx_tb);}
  __Pyx_AddTraceback("interpnd.CloughTocher2DInterpolator._evaluate_complex");
  __pyx_r = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_xi);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_out);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_vertices);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_points);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_values);
  __Pyx_SafeReleaseBuffer(&__pyx_bstruct_grad);
  __pyx_L2:;
  __Pyx_XDECREF((PyObject *)__pyx_v_values);
  __Pyx_XDECREF((PyObject *)__pyx_v_grad);
  __Pyx_DECREF((PyObject *)__pyx_v_out);
  __Pyx_XDECREF((PyObject *)__pyx_v_points);
  __Pyx_XDECREF((PyObject *)__pyx_v_vertices);
  __Pyx_DECREF(__pyx_v_eps);
  __Pyx_DECREF(__pyx_v_self);
  __Pyx_DECREF((PyObject *)__pyx_v_xi);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static int __pyx_pf_5numpy_7ndarray___getbuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info, int __pyx_v_flags); 
static int __pyx_pf_5numpy_7ndarray___getbuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info, int __pyx_v_flags) {
  int __pyx_v_copy_shape;
  int __pyx_v_i;
  int __pyx_v_ndim;
  int __pyx_v_endian_detector;
  int __pyx_v_little_endian;
  int __pyx_v_t;
  char *__pyx_v_f;
  PyArray_Descr *__pyx_v_descr = 0;
  int __pyx_v_offset;
  int __pyx_v_hasfields;
  int __pyx_r;
  int __pyx_t_1;
  int __pyx_t_2;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  char *__pyx_t_9;
  __Pyx_RefNannySetupContext("__getbuffer__");
  if (__pyx_v_info == NULL) return 0;
  __pyx_v_info->obj = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(__pyx_v_info->obj);
  __Pyx_INCREF((PyObject *)__pyx_v_self);

  
  __pyx_v_endian_detector = 1;

  
  __pyx_v_little_endian = ((((char *)(&__pyx_v_endian_detector))[0]) != 0);

  
  __pyx_v_ndim = PyArray_NDIM(((PyArrayObject *)__pyx_v_self));

  
  __pyx_t_1 = ((sizeof(npy_intp)) != (sizeof(Py_ssize_t)));
  if (__pyx_t_1) {

    
    __pyx_v_copy_shape = 1;
    goto __pyx_L5;
  }
   {

    
    __pyx_v_copy_shape = 0;
  }
  __pyx_L5:;

  
  __pyx_t_1 = ((__pyx_v_flags & PyBUF_C_CONTIGUOUS) == PyBUF_C_CONTIGUOUS);
  if (__pyx_t_1) {

    
    __pyx_t_2 = (!PyArray_CHKFLAGS(((PyArrayObject *)__pyx_v_self), NPY_C_CONTIGUOUS));
    __pyx_t_3 = __pyx_t_2;
  } else {
    __pyx_t_3 = __pyx_t_1;
  }
  if (__pyx_t_3) {

    
    __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 205; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_INCREF(((PyObject *)__pyx_kp_u_17));
    PyTuple_SET_ITEM(__pyx_t_4, 0, ((PyObject *)__pyx_kp_u_17));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_u_17));
    __pyx_t_5 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_4, NULL); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 205; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_Raise(__pyx_t_5, 0, 0);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    {__pyx_filename = __pyx_f[1]; __pyx_lineno = 205; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L6;
  }
  __pyx_L6:;

  
  __pyx_t_3 = ((__pyx_v_flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS);
  if (__pyx_t_3) {

    
    __pyx_t_1 = (!PyArray_CHKFLAGS(((PyArrayObject *)__pyx_v_self), NPY_F_CONTIGUOUS));
    __pyx_t_2 = __pyx_t_1;
  } else {
    __pyx_t_2 = __pyx_t_3;
  }
  if (__pyx_t_2) {

    
    __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 209; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_INCREF(((PyObject *)__pyx_kp_u_18));
    PyTuple_SET_ITEM(__pyx_t_5, 0, ((PyObject *)__pyx_kp_u_18));
    __Pyx_GIVEREF(((PyObject *)__pyx_kp_u_18));
    __pyx_t_4 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_5, NULL); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 209; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_Raise(__pyx_t_4, 0, 0);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    {__pyx_filename = __pyx_f[1]; __pyx_lineno = 209; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    goto __pyx_L7;
  }
  __pyx_L7:;

  
  __pyx_v_info->buf = PyArray_DATA(((PyArrayObject *)__pyx_v_self));

  
  __pyx_v_info->ndim = __pyx_v_ndim;

  
  __pyx_t_6 = __pyx_v_copy_shape;
  if (__pyx_t_6) {

    
    __pyx_v_info->strides = ((Py_ssize_t *)malloc((((sizeof(Py_ssize_t)) * __pyx_v_ndim) * 2)));

    
    __pyx_v_info->shape = (__pyx_v_info->strides + __pyx_v_ndim);

    
    __pyx_t_6 = __pyx_v_ndim;
    for (__pyx_t_7 = 0; __pyx_t_7 < __pyx_t_6; __pyx_t_7+=1) {
      __pyx_v_i = __pyx_t_7;

      
      (__pyx_v_info->strides[__pyx_v_i]) = (PyArray_STRIDES(((PyArrayObject *)__pyx_v_self))[__pyx_v_i]);

      
      (__pyx_v_info->shape[__pyx_v_i]) = (PyArray_DIMS(((PyArrayObject *)__pyx_v_self))[__pyx_v_i]);
    }
    goto __pyx_L8;
  }
   {

    
    __pyx_v_info->strides = ((Py_ssize_t *)PyArray_STRIDES(((PyArrayObject *)__pyx_v_self)));

    
    __pyx_v_info->shape = ((Py_ssize_t *)PyArray_DIMS(((PyArrayObject *)__pyx_v_self)));
  }
  __pyx_L8:;

  
  __pyx_v_info->suboffsets = NULL;

  
  __pyx_v_info->itemsize = PyArray_ITEMSIZE(((PyArrayObject *)__pyx_v_self));

  
  __pyx_v_info->readonly = (!PyArray_ISWRITEABLE(((PyArrayObject *)__pyx_v_self)));

  
  __pyx_v_f = NULL;

  
  __Pyx_INCREF(((PyObject *)((PyArrayObject *)__pyx_v_self)->descr));
  __pyx_v_descr = ((PyArrayObject *)__pyx_v_self)->descr;

  
  __pyx_v_hasfields = PyDataType_HASFIELDS(__pyx_v_descr);

  
  __pyx_t_2 = (!__pyx_v_hasfields);
  if (__pyx_t_2) {
    __pyx_t_3 = (!__pyx_v_copy_shape);
    __pyx_t_1 = __pyx_t_3;
  } else {
    __pyx_t_1 = __pyx_t_2;
  }
  if (__pyx_t_1) {

    
    __Pyx_INCREF(Py_None);
    __Pyx_GIVEREF(Py_None);
    __Pyx_GOTREF(__pyx_v_info->obj);
    __Pyx_DECREF(__pyx_v_info->obj);
    __pyx_v_info->obj = Py_None;
    goto __pyx_L11;
  }
   {

    
    __Pyx_INCREF(__pyx_v_self);
    __Pyx_GIVEREF(__pyx_v_self);
    __Pyx_GOTREF(__pyx_v_info->obj);
    __Pyx_DECREF(__pyx_v_info->obj);
    __pyx_v_info->obj = __pyx_v_self;
  }
  __pyx_L11:;

  
  __pyx_t_1 = (!__pyx_v_hasfields);
  if (__pyx_t_1) {

    
    __pyx_v_t = __pyx_v_descr->type_num;

    
    __pyx_t_1 = (__pyx_v_descr->byteorder == '>');
    if (__pyx_t_1) {
      __pyx_t_2 = __pyx_v_little_endian;
    } else {
      __pyx_t_2 = __pyx_t_1;
    }
    if (!__pyx_t_2) {

      
      __pyx_t_1 = (__pyx_v_descr->byteorder == '<');
      if (__pyx_t_1) {
        __pyx_t_3 = (!__pyx_v_little_endian);
        __pyx_t_8 = __pyx_t_3;
      } else {
        __pyx_t_8 = __pyx_t_1;
      }
      __pyx_t_1 = __pyx_t_8;
    } else {
      __pyx_t_1 = __pyx_t_2;
    }
    if (__pyx_t_1) {

      
      __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 247; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_INCREF(((PyObject *)__pyx_kp_u_19));
      PyTuple_SET_ITEM(__pyx_t_4, 0, ((PyObject *)__pyx_kp_u_19));
      __Pyx_GIVEREF(((PyObject *)__pyx_kp_u_19));
      __pyx_t_5 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_4, NULL); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 247; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_Raise(__pyx_t_5, 0, 0);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      {__pyx_filename = __pyx_f[1]; __pyx_lineno = 247; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      goto __pyx_L13;
    }
    __pyx_L13:;

    
    __pyx_t_1 = (__pyx_v_t == NPY_BYTE);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__b;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_UBYTE);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__B;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_SHORT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__h;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_USHORT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__H;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_INT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__i;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_UINT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__I;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_LONG);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__l;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_ULONG);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__L;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_LONGLONG);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__q;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_ULONGLONG);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__Q;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_FLOAT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__f;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_DOUBLE);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__d;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_LONGDOUBLE);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__g;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_CFLOAT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__Zf;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_CDOUBLE);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__Zd;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_CLONGDOUBLE);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__Zg;
      goto __pyx_L14;
    }

    
    __pyx_t_1 = (__pyx_v_t == NPY_OBJECT);
    if (__pyx_t_1) {
      __pyx_v_f = __pyx_k__O;
      goto __pyx_L14;
    }
     {

      
      __pyx_t_5 = PyInt_FromLong(__pyx_v_t); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 266; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_4 = PyNumber_Remainder(((PyObject *)__pyx_kp_u_20), __pyx_t_5); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 266; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 266; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_4);
      __Pyx_GIVEREF(__pyx_t_4);
      __pyx_t_4 = 0;
      __pyx_t_4 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_5, NULL); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 266; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_Raise(__pyx_t_4, 0, 0);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      {__pyx_filename = __pyx_f[1]; __pyx_lineno = 266; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    }
    __pyx_L14:;

    
    __pyx_v_info->format = __pyx_v_f;

    
    __pyx_r = 0;
    goto __pyx_L0;
    goto __pyx_L12;
  }
   {

    
    __pyx_v_info->format = ((char *)malloc(255));

    
    (__pyx_v_info->format[0]) = '^';

    
    __pyx_v_offset = 0;

    
    __pyx_t_9 = __pyx_f_5numpy__util_dtypestring(__pyx_v_descr, (__pyx_v_info->format + 1), (__pyx_v_info->format + 255), (&__pyx_v_offset)); if (unlikely(__pyx_t_9 == NULL)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 273; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __pyx_v_f = __pyx_t_9;

    
    (__pyx_v_f[0]) = 0;
  }
  __pyx_L12:;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("numpy.ndarray.__getbuffer__");
  __pyx_r = -1;
  __Pyx_GOTREF(__pyx_v_info->obj);
  __Pyx_DECREF(__pyx_v_info->obj); __pyx_v_info->obj = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  if (__pyx_v_info->obj == Py_None) {
    __Pyx_GOTREF(Py_None);
    __Pyx_DECREF(Py_None); __pyx_v_info->obj = NULL;
  }
  __pyx_L2:;
  __Pyx_XDECREF((PyObject *)__pyx_v_descr);
  __Pyx_DECREF((PyObject *)__pyx_v_self);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static void __pyx_pf_5numpy_7ndarray___releasebuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info); 
static void __pyx_pf_5numpy_7ndarray___releasebuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info) {
  int __pyx_t_1;
  __Pyx_RefNannySetupContext("__releasebuffer__");
  __Pyx_INCREF((PyObject *)__pyx_v_self);

  
  __pyx_t_1 = PyArray_HASFIELDS(((PyArrayObject *)__pyx_v_self));
  if (__pyx_t_1) {

    
    free(__pyx_v_info->format);
    goto __pyx_L5;
  }
  __pyx_L5:;

  
  __pyx_t_1 = ((sizeof(npy_intp)) != (sizeof(Py_ssize_t)));
  if (__pyx_t_1) {

    
    free(__pyx_v_info->strides);
    goto __pyx_L6;
  }
  __pyx_L6:;

  __Pyx_DECREF((PyObject *)__pyx_v_self);
  __Pyx_RefNannyFinishContext();
}



static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew1(PyObject *__pyx_v_a) {
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew1");

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(1, ((void *)__pyx_v_a)); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 756; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew1");
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew2(PyObject *__pyx_v_a, PyObject *__pyx_v_b) {
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew2");

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(2, ((void *)__pyx_v_a), ((void *)__pyx_v_b)); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 759; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew2");
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew3(PyObject *__pyx_v_a, PyObject *__pyx_v_b, PyObject *__pyx_v_c) {
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew3");

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(3, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c)); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 762; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew3");
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew4(PyObject *__pyx_v_a, PyObject *__pyx_v_b, PyObject *__pyx_v_c, PyObject *__pyx_v_d) {
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew4");

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(4, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d)); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 765; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew4");
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew5(PyObject *__pyx_v_a, PyObject *__pyx_v_b, PyObject *__pyx_v_c, PyObject *__pyx_v_d, PyObject *__pyx_v_e) {
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew5");

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(5, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d), ((void *)__pyx_v_e)); if (unlikely(!__pyx_t_1)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 768; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew5");
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static CYTHON_INLINE char *__pyx_f_5numpy__util_dtypestring(PyArray_Descr *__pyx_v_descr, char *__pyx_v_f, char *__pyx_v_end, int *__pyx_v_offset) {
  PyArray_Descr *__pyx_v_child;
  int __pyx_v_endian_detector;
  int __pyx_v_little_endian;
  PyObject *__pyx_v_fields;
  PyObject *__pyx_v_childname;
  PyObject *__pyx_v_new_offset;
  PyObject *__pyx_v_t;
  char *__pyx_r;
  Py_ssize_t __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  char *__pyx_t_10;
  __Pyx_RefNannySetupContext("_util_dtypestring");
  __Pyx_INCREF((PyObject *)__pyx_v_descr);
  __pyx_v_child = ((PyArray_Descr *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_fields = ((PyObject *)Py_None); __Pyx_INCREF(Py_None);
  __pyx_v_childname = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_new_offset = Py_None; __Pyx_INCREF(Py_None);
  __pyx_v_t = Py_None; __Pyx_INCREF(Py_None);

  
  __pyx_v_endian_detector = 1;

  
  __pyx_v_little_endian = ((((char *)(&__pyx_v_endian_detector))[0]) != 0);

  
  if (likely(((PyObject *)__pyx_v_descr->names) != Py_None)) {
    __pyx_t_1 = 0; __pyx_t_2 = ((PyObject *)__pyx_v_descr->names); __Pyx_INCREF(__pyx_t_2);
  } else {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable"); {__pyx_filename = __pyx_f[1]; __pyx_lineno = 781; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  }
  for (;;) {
    if (__pyx_t_1 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
    __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_1); __Pyx_INCREF(__pyx_t_3); __pyx_t_1++;
    __Pyx_DECREF(__pyx_v_childname);
    __pyx_v_childname = __pyx_t_3;
    __pyx_t_3 = 0;

    
    __pyx_t_3 = PyObject_GetItem(__pyx_v_descr->fields, __pyx_v_childname); if (!__pyx_t_3) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 782; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    if (!(likely(PyTuple_CheckExact(__pyx_t_3))||((__pyx_t_3) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected tuple, got %.200s", Py_TYPE(__pyx_t_3)->tp_name), 0))) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 782; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(((PyObject *)__pyx_v_fields));
    __pyx_v_fields = ((PyObject *)__pyx_t_3);
    __pyx_t_3 = 0;

    
    if (likely(((PyObject *)__pyx_v_fields) != Py_None) && likely(PyTuple_GET_SIZE(((PyObject *)__pyx_v_fields)) == 2)) {
      PyObject* tuple = ((PyObject *)__pyx_v_fields);
      __pyx_t_3 = PyTuple_GET_ITEM(tuple, 0); __Pyx_INCREF(__pyx_t_3);
      if (!(likely(((__pyx_t_3) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_3, __pyx_ptype_5numpy_dtype))))) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 783; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __pyx_t_4 = PyTuple_GET_ITEM(tuple, 1); __Pyx_INCREF(__pyx_t_4);
      __Pyx_DECREF(((PyObject *)__pyx_v_child));
      __pyx_v_child = ((PyArray_Descr *)__pyx_t_3);
      __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_v_new_offset);
      __pyx_v_new_offset = __pyx_t_4;
      __pyx_t_4 = 0;
    } else {
      __Pyx_UnpackTupleError(((PyObject *)__pyx_v_fields), 2);
      {__pyx_filename = __pyx_f[1]; __pyx_lineno = 783; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    }

    
    __pyx_t_4 = PyInt_FromLong((__pyx_v_end - __pyx_v_f)); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 785; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_3 = PyInt_FromLong((__pyx_v_offset[0])); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 785; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = PyNumber_Subtract(__pyx_v_new_offset, __pyx_t_3); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 785; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = PyNumber_Subtract(__pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 785; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyObject_RichCompare(__pyx_t_3, __pyx_int_15, Py_LT); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 785; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 785; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (__pyx_t_6) {

      
      __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 786; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_INCREF(((PyObject *)__pyx_kp_u_21));
      PyTuple_SET_ITEM(__pyx_t_5, 0, ((PyObject *)__pyx_kp_u_21));
      __Pyx_GIVEREF(((PyObject *)__pyx_kp_u_21));
      __pyx_t_3 = PyObject_Call(__pyx_builtin_RuntimeError, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 786; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_Raise(__pyx_t_3, 0, 0);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      {__pyx_filename = __pyx_f[1]; __pyx_lineno = 786; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      goto __pyx_L5;
    }
    __pyx_L5:;

    
    __pyx_t_6 = (__pyx_v_child->byteorder == '>');
    if (__pyx_t_6) {
      __pyx_t_7 = __pyx_v_little_endian;
    } else {
      __pyx_t_7 = __pyx_t_6;
    }
    if (!__pyx_t_7) {

      
      __pyx_t_6 = (__pyx_v_child->byteorder == '<');
      if (__pyx_t_6) {
        __pyx_t_8 = (!__pyx_v_little_endian);
        __pyx_t_9 = __pyx_t_8;
      } else {
        __pyx_t_9 = __pyx_t_6;
      }
      __pyx_t_6 = __pyx_t_9;
    } else {
      __pyx_t_6 = __pyx_t_7;
    }
    if (__pyx_t_6) {

      
      __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 790; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_INCREF(((PyObject *)__pyx_kp_u_19));
      PyTuple_SET_ITEM(__pyx_t_3, 0, ((PyObject *)__pyx_kp_u_19));
      __Pyx_GIVEREF(((PyObject *)__pyx_kp_u_19));
      __pyx_t_5 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_3, NULL); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 790; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_Raise(__pyx_t_5, 0, 0);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      {__pyx_filename = __pyx_f[1]; __pyx_lineno = 790; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      goto __pyx_L6;
    }
    __pyx_L6:;

    
    while (1) {
      __pyx_t_5 = PyInt_FromLong((__pyx_v_offset[0])); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 800; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_t_5, __pyx_v_new_offset, Py_LT); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 800; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 800; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (!__pyx_t_6) break;

      
      (__pyx_v_f[0]) = 120;

      
      __pyx_v_f += 1;

      
      (__pyx_v_offset[0]) += 1;
    }

    
    (__pyx_v_offset[0]) += __pyx_v_child->elsize;

    
    __pyx_t_6 = (!PyDataType_HASFIELDS(__pyx_v_child));
    if (__pyx_t_6) {

      
      __pyx_t_3 = PyInt_FromLong(__pyx_v_child->type_num); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 808; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_v_t);
      __pyx_v_t = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __pyx_t_6 = ((__pyx_v_end - __pyx_v_f) < 5);
      if (__pyx_t_6) {

        
        __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 810; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_INCREF(((PyObject *)__pyx_kp_u_22));
        PyTuple_SET_ITEM(__pyx_t_3, 0, ((PyObject *)__pyx_kp_u_22));
        __Pyx_GIVEREF(((PyObject *)__pyx_kp_u_22));
        __pyx_t_5 = PyObject_Call(__pyx_builtin_RuntimeError, __pyx_t_3, NULL); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 810; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_Raise(__pyx_t_5, 0, 0);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        {__pyx_filename = __pyx_f[1]; __pyx_lineno = 810; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        goto __pyx_L10;
      }
      __pyx_L10:;

      
      __pyx_t_5 = PyInt_FromLong(NPY_BYTE); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 813; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 813; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 813; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 98;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_UBYTE); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 814; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 814; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 814; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 66;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_SHORT); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 815; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 815; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 815; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 104;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_USHORT); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 816; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 816; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 816; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 72;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_INT); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 817; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 817; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 817; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 105;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_UINT); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 818; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 818; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 818; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 73;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_LONG); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 819; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 819; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 819; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 108;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_ULONG); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 820; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 820; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 820; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 76;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_LONGLONG); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 821; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 821; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 821; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 113;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_ULONGLONG); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 822; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 822; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 822; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 81;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_FLOAT); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 823; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 823; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 823; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 102;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_DOUBLE); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 824; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 824; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 824; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 100;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_LONGDOUBLE); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 825; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 825; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 825; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 103;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_CFLOAT); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 826; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 826; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 826; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 90;
        (__pyx_v_f[1]) = 102;
        __pyx_v_f += 1;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_CDOUBLE); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 827; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 827; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 827; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 90;
        (__pyx_v_f[1]) = 100;
        __pyx_v_f += 1;
        goto __pyx_L11;
      }

      
      __pyx_t_3 = PyInt_FromLong(NPY_CLONGDOUBLE); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 828; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 828; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 828; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 90;
        (__pyx_v_f[1]) = 103;
        __pyx_v_f += 1;
        goto __pyx_L11;
      }

      
      __pyx_t_5 = PyInt_FromLong(NPY_OBJECT); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 829; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_5, Py_EQ); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 829; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 829; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 79;
        goto __pyx_L11;
      }
       {

        
        __pyx_t_3 = PyNumber_Remainder(((PyObject *)__pyx_kp_u_20), __pyx_v_t); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 831; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 831; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_5);
        PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
        __Pyx_GIVEREF(__pyx_t_3);
        __pyx_t_3 = 0;
        __pyx_t_3 = PyObject_Call(__pyx_builtin_ValueError, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 831; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_Raise(__pyx_t_3, 0, 0);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        {__pyx_filename = __pyx_f[1]; __pyx_lineno = 831; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      }
      __pyx_L11:;

      
      __pyx_v_f += 1;
      goto __pyx_L9;
    }
     {

      
      __pyx_t_10 = __pyx_f_5numpy__util_dtypestring(__pyx_v_child, __pyx_v_f, __pyx_v_end, __pyx_v_offset); if (unlikely(__pyx_t_10 == NULL)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 836; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
      __pyx_v_f = __pyx_t_10;
    }
    __pyx_L9:;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_r = __pyx_v_f;
  goto __pyx_L0;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("numpy._util_dtypestring");
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF((PyObject *)__pyx_v_child);
  __Pyx_DECREF(__pyx_v_fields);
  __Pyx_DECREF(__pyx_v_childname);
  __Pyx_DECREF(__pyx_v_new_offset);
  __Pyx_DECREF(__pyx_v_t);
  __Pyx_DECREF((PyObject *)__pyx_v_descr);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static CYTHON_INLINE void __pyx_f_5numpy_set_array_base(PyArrayObject *__pyx_v_arr, PyObject *__pyx_v_base) {
  PyObject *__pyx_v_baseptr;
  int __pyx_t_1;
  __Pyx_RefNannySetupContext("set_array_base");
  __Pyx_INCREF((PyObject *)__pyx_v_arr);
  __Pyx_INCREF(__pyx_v_base);

  
  __pyx_t_1 = (__pyx_v_base == Py_None);
  if (__pyx_t_1) {

    
    __pyx_v_baseptr = NULL;
    goto __pyx_L3;
  }
   {

    
    Py_INCREF(__pyx_v_base);

    
    __pyx_v_baseptr = ((PyObject *)__pyx_v_base);
  }
  __pyx_L3:;

  
  Py_XDECREF(__pyx_v_arr->base);

  
  __pyx_v_arr->base = __pyx_v_baseptr;

  __Pyx_DECREF((PyObject *)__pyx_v_arr);
  __Pyx_DECREF(__pyx_v_base);
  __Pyx_RefNannyFinishContext();
}



static CYTHON_INLINE PyObject *__pyx_f_5numpy_get_array_base(PyArrayObject *__pyx_v_arr) {
  PyObject *__pyx_r = NULL;
  int __pyx_t_1;
  __Pyx_RefNannySetupContext("get_array_base");
  __Pyx_INCREF((PyObject *)__pyx_v_arr);

  
  __pyx_t_1 = (__pyx_v_arr->base == NULL);
  if (__pyx_t_1) {

    
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(Py_None);
    __pyx_r = Py_None;
    goto __pyx_L0;
    goto __pyx_L3;
  }
   {

    
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(((PyObject *)__pyx_v_arr->base));
    __pyx_r = ((PyObject *)__pyx_v_arr->base);
    goto __pyx_L0;
  }
  __pyx_L3:;

  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __pyx_L0:;
  __Pyx_DECREF((PyObject *)__pyx_v_arr);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {__Pyx_NAMESTR("_ndim_coords_from_arrays"), (PyCFunction)__pyx_pf_8interpnd__ndim_coords_from_arrays, METH_O, __Pyx_DOCSTR(__pyx_doc_8interpnd__ndim_coords_from_arrays)},
  {__Pyx_NAMESTR("estimate_gradients_2d_global"), (PyCFunction)__pyx_pf_8interpnd_estimate_gradients_2d_global, METH_VARARGS|METH_KEYWORDS, __Pyx_DOCSTR(0)},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); 

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    __Pyx_NAMESTR("interpnd"),
    __Pyx_DOCSTR(__pyx_k_23), 
    -1, 
    __pyx_methods ,
    NULL, 
    NULL, 
    NULL, 
    NULL 
};
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_s_11, __pyx_k_11, sizeof(__pyx_k_11), 0, 0, 1, 0},
  {&__pyx_n_s_12, __pyx_k_12, sizeof(__pyx_k_12), 0, 0, 1, 1},
  {&__pyx_kp_s_13, __pyx_k_13, sizeof(__pyx_k_13), 0, 0, 1, 0},
  {&__pyx_n_s_14, __pyx_k_14, sizeof(__pyx_k_14), 0, 0, 1, 1},
  {&__pyx_kp_u_17, __pyx_k_17, sizeof(__pyx_k_17), 0, 1, 0, 0},
  {&__pyx_kp_u_18, __pyx_k_18, sizeof(__pyx_k_18), 0, 1, 0, 0},
  {&__pyx_kp_u_19, __pyx_k_19, sizeof(__pyx_k_19), 0, 1, 0, 0},
  {&__pyx_n_s_2, __pyx_k_2, sizeof(__pyx_k_2), 0, 0, 1, 1},
  {&__pyx_kp_u_20, __pyx_k_20, sizeof(__pyx_k_20), 0, 1, 0, 0},
  {&__pyx_kp_u_21, __pyx_k_21, sizeof(__pyx_k_21), 0, 1, 0, 0},
  {&__pyx_kp_u_22, __pyx_k_22, sizeof(__pyx_k_22), 0, 1, 0, 0},
  {&__pyx_n_s_24, __pyx_k_24, sizeof(__pyx_k_24), 0, 0, 1, 1},
  {&__pyx_n_s_25, __pyx_k_25, sizeof(__pyx_k_25), 0, 0, 1, 1},
  {&__pyx_kp_s_26, __pyx_k_26, sizeof(__pyx_k_26), 0, 0, 1, 0},
  {&__pyx_kp_s_27, __pyx_k_27, sizeof(__pyx_k_27), 0, 0, 1, 0},
  {&__pyx_n_s_28, __pyx_k_28, sizeof(__pyx_k_28), 0, 0, 1, 1},
  {&__pyx_kp_s_29, __pyx_k_29, sizeof(__pyx_k_29), 0, 0, 1, 0},
  {&__pyx_kp_s_3, __pyx_k_3, sizeof(__pyx_k_3), 0, 0, 1, 0},
  {&__pyx_n_s_30, __pyx_k_30, sizeof(__pyx_k_30), 0, 0, 1, 1},
  {&__pyx_kp_u_31, __pyx_k_31, sizeof(__pyx_k_31), 0, 1, 0, 0},
  {&__pyx_kp_u_32, __pyx_k_32, sizeof(__pyx_k_32), 0, 1, 0, 0},
  {&__pyx_kp_u_33, __pyx_k_33, sizeof(__pyx_k_33), 0, 1, 0, 0},
  {&__pyx_kp_u_34, __pyx_k_34, sizeof(__pyx_k_34), 0, 1, 0, 0},
  {&__pyx_kp_s_4, __pyx_k_4, sizeof(__pyx_k_4), 0, 0, 1, 0},
  {&__pyx_kp_s_5, __pyx_k_5, sizeof(__pyx_k_5), 0, 0, 1, 0},
  {&__pyx_kp_s_6, __pyx_k_6, sizeof(__pyx_k_6), 0, 0, 1, 0},
  {&__pyx_kp_s_7, __pyx_k_7, sizeof(__pyx_k_7), 0, 0, 1, 0},
  {&__pyx_kp_s_8, __pyx_k_8, sizeof(__pyx_k_8), 0, 0, 1, 0},
  {&__pyx_n_s__Delaunay, __pyx_k__Delaunay, sizeof(__pyx_k__Delaunay), 0, 0, 1, 1},
  {&__pyx_n_s__NDInterpolatorBase, __pyx_k__NDInterpolatorBase, sizeof(__pyx_k__NDInterpolatorBase), 0, 0, 1, 1},
  {&__pyx_n_s__RuntimeError, __pyx_k__RuntimeError, sizeof(__pyx_k__RuntimeError), 0, 0, 1, 1},
  {&__pyx_n_s__T, __pyx_k__T, sizeof(__pyx_k__T), 0, 0, 1, 1},
  {&__pyx_n_s__ValueError, __pyx_k__ValueError, sizeof(__pyx_k__ValueError), 0, 0, 1, 1},
  {&__pyx_n_s__Warning, __pyx_k__Warning, sizeof(__pyx_k__Warning), 0, 0, 1, 1},
  {&__pyx_n_s____call__, __pyx_k____call__, sizeof(__pyx_k____call__), 0, 0, 1, 1},
  {&__pyx_n_s____init__, __pyx_k____init__, sizeof(__pyx_k____init__), 0, 0, 1, 1},
  {&__pyx_n_s____main__, __pyx_k____main__, sizeof(__pyx_k____main__), 0, 0, 1, 1},
  {&__pyx_n_s____test__, __pyx_k____test__, sizeof(__pyx_k____test__), 0, 0, 1, 1},
  {&__pyx_n_s___check_call_shape, __pyx_k___check_call_shape, sizeof(__pyx_k___check_call_shape), 0, 0, 1, 1},
  {&__pyx_n_s___check_init_shape, __pyx_k___check_init_shape, sizeof(__pyx_k___check_init_shape), 0, 0, 1, 1},
  {&__pyx_n_s___evaluate_complex, __pyx_k___evaluate_complex, sizeof(__pyx_k___evaluate_complex), 0, 0, 1, 1},
  {&__pyx_n_s___evaluate_double, __pyx_k___evaluate_double, sizeof(__pyx_k___evaluate_double), 0, 0, 1, 1},
  {&__pyx_n_s__asanyarray, __pyx_k__asanyarray, sizeof(__pyx_k__asanyarray), 0, 0, 1, 1},
  {&__pyx_n_s__ascontiguousarray, __pyx_k__ascontiguousarray, sizeof(__pyx_k__ascontiguousarray), 0, 0, 1, 1},
  {&__pyx_n_s__astype, __pyx_k__astype, sizeof(__pyx_k__astype), 0, 0, 1, 1},
  {&__pyx_n_s__base, __pyx_k__base, sizeof(__pyx_k__base), 0, 0, 1, 1},
  {&__pyx_n_s__buf, __pyx_k__buf, sizeof(__pyx_k__buf), 0, 0, 1, 1},
  {&__pyx_n_s__byteorder, __pyx_k__byteorder, sizeof(__pyx_k__byteorder), 0, 0, 1, 1},
  {&__pyx_n_s__complex, __pyx_k__complex, sizeof(__pyx_k__complex), 0, 0, 1, 1},
  {&__pyx_n_s__complexfloating, __pyx_k__complexfloating, sizeof(__pyx_k__complexfloating), 0, 0, 1, 1},
  {&__pyx_n_s__data, __pyx_k__data, sizeof(__pyx_k__data), 0, 0, 1, 1},
  {&__pyx_n_s__descr, __pyx_k__descr, sizeof(__pyx_k__descr), 0, 0, 1, 1},
  {&__pyx_n_s__double, __pyx_k__double, sizeof(__pyx_k__double), 0, 0, 1, 1},
  {&__pyx_n_s__dtype, __pyx_k__dtype, sizeof(__pyx_k__dtype), 0, 0, 1, 1},
  {&__pyx_n_s__empty, __pyx_k__empty, sizeof(__pyx_k__empty), 0, 0, 1, 1},
  {&__pyx_n_s__enumerate, __pyx_k__enumerate, sizeof(__pyx_k__enumerate), 0, 0, 1, 1},
  {&__pyx_n_s__eps, __pyx_k__eps, sizeof(__pyx_k__eps), 0, 0, 1, 1},
  {&__pyx_n_s__fields, __pyx_k__fields, sizeof(__pyx_k__fields), 0, 0, 1, 1},
  {&__pyx_n_s__fill_value, __pyx_k__fill_value, sizeof(__pyx_k__fill_value), 0, 0, 1, 1},
  {&__pyx_n_s__finfo, __pyx_k__finfo, sizeof(__pyx_k__finfo), 0, 0, 1, 1},
  {&__pyx_n_s__format, __pyx_k__format, sizeof(__pyx_k__format), 0, 0, 1, 1},
  {&__pyx_n_s__grad, __pyx_k__grad, sizeof(__pyx_k__grad), 0, 0, 1, 1},
  {&__pyx_n_s__imag, __pyx_k__imag, sizeof(__pyx_k__imag), 0, 0, 1, 1},
  {&__pyx_n_s__index, __pyx_k__index, sizeof(__pyx_k__index), 0, 0, 1, 1},
  {&__pyx_n_s__is_complex, __pyx_k__is_complex, sizeof(__pyx_k__is_complex), 0, 0, 1, 1},
  {&__pyx_n_s__issubdtype, __pyx_k__issubdtype, sizeof(__pyx_k__issubdtype), 0, 0, 1, 1},
  {&__pyx_n_s__itemsize, __pyx_k__itemsize, sizeof(__pyx_k__itemsize), 0, 0, 1, 1},
  {&__pyx_n_s__map, __pyx_k__map, sizeof(__pyx_k__map), 0, 0, 1, 1},
  {&__pyx_n_s__maxiter, __pyx_k__maxiter, sizeof(__pyx_k__maxiter), 0, 0, 1, 1},
  {&__pyx_n_s__names, __pyx_k__names, sizeof(__pyx_k__names), 0, 0, 1, 1},
  {&__pyx_n_s__nan, __pyx_k__nan, sizeof(__pyx_k__nan), 0, 0, 1, 1},
  {&__pyx_n_s__ndim, __pyx_k__ndim, sizeof(__pyx_k__ndim), 0, 0, 1, 1},
  {&__pyx_n_s__neighbors, __pyx_k__neighbors, sizeof(__pyx_k__neighbors), 0, 0, 1, 1},
  {&__pyx_n_s__np, __pyx_k__np, sizeof(__pyx_k__np), 0, 0, 1, 1},
  {&__pyx_n_s__npoints, __pyx_k__npoints, sizeof(__pyx_k__npoints), 0, 0, 1, 1},
  {&__pyx_n_s__numpy, __pyx_k__numpy, sizeof(__pyx_k__numpy), 0, 0, 1, 1},
  {&__pyx_n_s__obj, __pyx_k__obj, sizeof(__pyx_k__obj), 0, 0, 1, 1},
  {&__pyx_n_s__object, __pyx_k__object, sizeof(__pyx_k__object), 0, 0, 1, 1},
  {&__pyx_n_s__points, __pyx_k__points, sizeof(__pyx_k__points), 0, 0, 1, 1},
  {&__pyx_n_s__prod, __pyx_k__prod, sizeof(__pyx_k__prod), 0, 0, 1, 1},
  {&__pyx_n_s__qhull, __pyx_k__qhull, sizeof(__pyx_k__qhull), 0, 0, 1, 1},
  {&__pyx_n_s__range, __pyx_k__range, sizeof(__pyx_k__range), 0, 0, 1, 1},
  {&__pyx_n_s__readonly, __pyx_k__readonly, sizeof(__pyx_k__readonly), 0, 0, 1, 1},
  {&__pyx_n_s__real, __pyx_k__real, sizeof(__pyx_k__real), 0, 0, 1, 1},
  {&__pyx_n_s__reshape, __pyx_k__reshape, sizeof(__pyx_k__reshape), 0, 0, 1, 1},
  {&__pyx_n_s__self, __pyx_k__self, sizeof(__pyx_k__self), 0, 0, 1, 1},
  {&__pyx_n_s__shape, __pyx_k__shape, sizeof(__pyx_k__shape), 0, 0, 1, 1},
  {&__pyx_n_s__strides, __pyx_k__strides, sizeof(__pyx_k__strides), 0, 0, 1, 1},
  {&__pyx_n_s__suboffsets, __pyx_k__suboffsets, sizeof(__pyx_k__suboffsets), 0, 0, 1, 1},
  {&__pyx_n_s__tol, __pyx_k__tol, sizeof(__pyx_k__tol), 0, 0, 1, 1},
  {&__pyx_n_s__transform, __pyx_k__transform, sizeof(__pyx_k__transform), 0, 0, 1, 1},
  {&__pyx_n_s__transpose, __pyx_k__transpose, sizeof(__pyx_k__transpose), 0, 0, 1, 1},
  {&__pyx_n_s__tri, __pyx_k__tri, sizeof(__pyx_k__tri), 0, 0, 1, 1},
  {&__pyx_n_s__type_num, __pyx_k__type_num, sizeof(__pyx_k__type_num), 0, 0, 1, 1},
  {&__pyx_n_s__values, __pyx_k__values, sizeof(__pyx_k__values), 0, 0, 1, 1},
  {&__pyx_n_s__values_shape, __pyx_k__values_shape, sizeof(__pyx_k__values_shape), 0, 0, 1, 1},
  {&__pyx_n_s__vertex, __pyx_k__vertex, sizeof(__pyx_k__vertex), 0, 0, 1, 1},
  {&__pyx_n_s__vertex2, __pyx_k__vertex2, sizeof(__pyx_k__vertex2), 0, 0, 1, 1},
  {&__pyx_n_s__vertices, __pyx_k__vertices, sizeof(__pyx_k__vertices), 0, 0, 1, 1},
  {&__pyx_n_s__warn, __pyx_k__warn, sizeof(__pyx_k__warn), 0, 0, 1, 1},
  {&__pyx_n_s__warnings, __pyx_k__warnings, sizeof(__pyx_k__warnings), 0, 0, 1, 1},
  {&__pyx_n_s__xi, __pyx_k__xi, sizeof(__pyx_k__xi), 0, 0, 1, 1},
  {&__pyx_n_s__xrange, __pyx_k__xrange, sizeof(__pyx_k__xrange), 0, 0, 1, 1},
  {&__pyx_n_s__y, __pyx_k__y, sizeof(__pyx_k__y), 0, 0, 1, 1},
  {&__pyx_n_s__zeros, __pyx_k__zeros, sizeof(__pyx_k__zeros), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_object = __Pyx_GetName(__pyx_b, __pyx_n_s__object); if (!__pyx_builtin_object) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 52; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_builtin_Warning = __Pyx_GetName(__pyx_b, __pyx_n_s__Warning); if (!__pyx_builtin_Warning) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 302; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_builtin_ValueError = __Pyx_GetName(__pyx_b, __pyx_n_s__ValueError); if (!__pyx_builtin_ValueError) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 99; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_builtin_map = __Pyx_GetName(__pyx_b, __pyx_n_s__map); if (!__pyx_builtin_map) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  #if PY_MAJOR_VERSION >= 3
  __pyx_builtin_xrange = __Pyx_GetName(__pyx_b, __pyx_n_s__range); if (!__pyx_builtin_xrange) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  #else
  __pyx_builtin_xrange = __Pyx_GetName(__pyx_b, __pyx_n_s__xrange); if (!__pyx_builtin_xrange) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 146; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  #endif
  __pyx_builtin_enumerate = __Pyx_GetName(__pyx_b, __pyx_n_s__enumerate); if (!__pyx_builtin_enumerate) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 150; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_builtin_range = __Pyx_GetName(__pyx_b, __pyx_n_s__range); if (!__pyx_builtin_range) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 218; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_builtin_RuntimeError = __Pyx_GetName(__pyx_b, __pyx_n_s__RuntimeError); if (!__pyx_builtin_RuntimeError) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 786; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  return 0;
  __pyx_L1_error:;
  return -1;
}

static int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_2 = PyInt_FromLong(2); if (unlikely(!__pyx_int_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_neg_1 = PyInt_FromLong(-1); if (unlikely(!__pyx_int_neg_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_15 = PyInt_FromLong(15); if (unlikely(!__pyx_int_15)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_100 = PyInt_FromLong(100); if (unlikely(!__pyx_int_100)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  __pyx_int_400 = PyInt_FromLong(400); if (unlikely(!__pyx_int_400)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  return 0;
  __pyx_L1_error:;
  return -1;
}

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initinterpnd(void); 
PyMODINIT_FUNC initinterpnd(void)
#else
PyMODINIT_FUNC PyInit_interpnd(void); 
PyMODINIT_FUNC PyInit_interpnd(void)
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  #if CYTHON_REFNANNY
  void* __pyx_refnanny = NULL;
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
  if (!__Pyx_RefNanny) {
      PyErr_Clear();
      __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
      if (!__Pyx_RefNanny)
          Py_FatalError("failed to import 'refnanny' module");
  }
  __pyx_refnanny = __Pyx_RefNanny->SetupContext("PyMODINIT_FUNC PyInit_interpnd(void)", __LINE__, __FILE__);
  #endif
  __pyx_init_filenames();
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  #if PY_MAJOR_VERSION < 3
  __pyx_empty_bytes = PyString_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  #else
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  #endif
  
  
  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD 
  PyEval_InitThreads();
  #endif
  #endif
  
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4(__Pyx_NAMESTR("interpnd"), __pyx_methods, __Pyx_DOCSTR(__pyx_k_23), 0, PYTHON_API_VERSION);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  #if PY_MAJOR_VERSION < 3
  Py_INCREF(__pyx_m);
  #endif
  __pyx_b = PyImport_AddModule(__Pyx_NAMESTR(__Pyx_BUILTIN_MODULE_NAME));
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  if (__Pyx_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  
  if (unlikely(__Pyx_InitGlobals() < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__pyx_module_is_main_interpnd) {
    if (__Pyx_SetAttrString(__pyx_m, "__name__", __pyx_n_s____main__) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;};
  }
  
  if (unlikely(__Pyx_InitCachedBuiltins() < 0)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  
  
  
  
  __pyx_ptype_5numpy_dtype = __Pyx_ImportType("numpy", "dtype", sizeof(PyArray_Descr), 0); if (unlikely(!__pyx_ptype_5numpy_dtype)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 148; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_ptype_5numpy_flatiter = __Pyx_ImportType("numpy", "flatiter", sizeof(PyArrayIterObject), 0); if (unlikely(!__pyx_ptype_5numpy_flatiter)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 158; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_ptype_5numpy_broadcast = __Pyx_ImportType("numpy", "broadcast", sizeof(PyArrayMultiIterObject), 0); if (unlikely(!__pyx_ptype_5numpy_broadcast)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 162; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_ptype_5numpy_ndarray = __Pyx_ImportType("numpy", "ndarray", sizeof(PyArrayObject), 0); if (unlikely(!__pyx_ptype_5numpy_ndarray)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 171; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_ptype_5numpy_ufunc = __Pyx_ImportType("numpy", "ufunc", sizeof(PyUFuncObject), 0); if (unlikely(!__pyx_ptype_5numpy_ufunc)) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 848; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  
  __pyx_t_1 = __Pyx_ImportModule("scipy.spatial.qhull"); if (!__pyx_t_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_get_delaunay_info", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__get_delaunay_info, "__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *(PyObject *, int, int)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_barycentric_inside", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__barycentric_inside, "int (int, double *, double *, double *, double)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_barycentric_coordinate_single", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__barycentric_coordinate_single, "void (int, double *, double *, double *, int)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_barycentric_coordinates", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__barycentric_coordinates, "void (int, double *, double *, double *)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_lift_point", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__lift_point, "void (__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_distplane", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__distplane, "double (__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, int, double *)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_is_point_fully_outside", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__is_point_fully_outside, "int (__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_find_simplex_bruteforce", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__find_simplex_bruteforce, "int (__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *, double)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_find_simplex_directed", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__find_simplex_directed, "int (__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *, int *, double)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_find_simplex", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__find_simplex, "int (__pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, double *, double *, int *, double)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_RidgeIter2D_init", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__RidgeIter2D_init, "void (__pyx_t_5scipy_7spatial_5qhull_RidgeIter2D_t *, __pyx_t_5scipy_7spatial_5qhull_DelaunayInfo_t *, int)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  if (__Pyx_ImportFunction(__pyx_t_1, "_RidgeIter2D_next", (void (**)(void))&__pyx_f_5scipy_7spatial_5qhull__RidgeIter2D_next, "void (__pyx_t_5scipy_7spatial_5qhull_RidgeIter2D_t *)") < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  Py_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  

  
  __pyx_t_2 = __Pyx_Import(((PyObject *)__pyx_n_s__numpy), 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s__np, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 20; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_2));
  __Pyx_INCREF(((PyObject *)__pyx_n_s_25));
  PyList_SET_ITEM(__pyx_t_2, 0, ((PyObject *)__pyx_n_s_25));
  __Pyx_GIVEREF(((PyObject *)__pyx_n_s_25));
  __pyx_t_3 = __Pyx_Import(((PyObject *)__pyx_n_s_24), ((PyObject *)__pyx_t_2)); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(((PyObject *)__pyx_t_2)); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s__qhull, __pyx_t_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 23; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_Import(((PyObject *)__pyx_n_s__warnings), 0); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 28; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s__warnings, __pyx_t_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 28; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 52; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 52; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_builtin_object);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_builtin_object);
  __Pyx_GIVEREF(__pyx_builtin_object);
  if (PyDict_SetItemString(((PyObject *)__pyx_t_3), "__doc__", ((PyObject *)__pyx_kp_s_26)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 52; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = __Pyx_CreateClass(__pyx_t_2, ((PyObject *)__pyx_t_3), __pyx_n_s__NDInterpolatorBase, "interpnd"); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 52; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = PyObject_GetAttr(__pyx_t_2, __pyx_n_s__nan); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_k_1 = __pyx_t_5;
  __Pyx_GIVEREF(__pyx_t_5);
  __pyx_t_5 = 0;
  __pyx_t_5 = PyCFunction_New(&__pyx_mdef_8interpnd_18NDInterpolatorBase___init__, 0); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = PyMethod_New(__pyx_t_5, 0, __pyx_t_4); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s____init__, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 60; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_New(&__pyx_mdef_8interpnd_18NDInterpolatorBase__check_init_shape, 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = PyMethod_New(__pyx_t_2, 0, __pyx_t_4); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s___check_init_shape, __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = PyCFunction_New(&__pyx_mdef_8interpnd_18NDInterpolatorBase__check_call_shape, 0); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = PyMethod_New(__pyx_t_5, 0, __pyx_t_4); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s___check_call_shape, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_New(&__pyx_mdef_8interpnd_18NDInterpolatorBase___call__, 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = PyMethod_New(__pyx_t_2, 0, __pyx_t_4); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s____call__, __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s__NDInterpolatorBase, __pyx_t_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 52; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  __pyx_t_4 = 0;
  if (PyDict_SetItemString(((PyObject *)__pyx_t_3), "__doc__", ((PyObject *)__pyx_kp_s_27)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_4 = __Pyx_CreateClass(__pyx_t_5, ((PyObject *)__pyx_t_3), __pyx_n_s_28, "interpnd"); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s__nan); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_k_9 = __pyx_t_2;
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_t_2 = PyCFunction_New(&__pyx_mdef_8interpnd_20LinearNDInterpolator___init__, 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = PyMethod_New(__pyx_t_2, 0, __pyx_t_4); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s____init__, __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = PyCFunction_New(&__pyx_mdef_8interpnd_20LinearNDInterpolator__evaluate_double, 0); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = PyMethod_New(__pyx_t_5, 0, __pyx_t_4); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s___evaluate_double, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 196; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_New(&__pyx_mdef_8interpnd_20LinearNDInterpolator__evaluate_complex, 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = PyMethod_New(__pyx_t_2, 0, __pyx_t_4); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_t_4, __pyx_n_s___evaluate_complex, __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s_28, __pyx_t_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 302; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 302; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_builtin_Warning);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_builtin_Warning);
  __Pyx_GIVEREF(__pyx_builtin_Warning);
  __pyx_t_5 = __Pyx_CreateClass(__pyx_t_4, ((PyObject *)__pyx_t_3), __pyx_n_s_14, "interpnd"); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 302; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s_14, __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 302; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyFloat_FromDouble(9.9999999999999995e-07); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_k_10 = __pyx_t_3;
  __Pyx_GIVEREF(__pyx_t_3);
  __pyx_t_3 = 0;

  
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 988; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  __pyx_t_5 = __Pyx_GetName(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 988; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = PyTuple_New(1); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 988; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  __pyx_t_5 = 0;
  if (PyDict_SetItemString(((PyObject *)__pyx_t_3), "__doc__", ((PyObject *)__pyx_kp_s_29)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 988; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __pyx_t_5 = __Pyx_CreateClass(__pyx_t_4, ((PyObject *)__pyx_t_3), __pyx_n_s_30, "interpnd"); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 988; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_GetName(__pyx_m, __pyx_n_s__np); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = PyObject_GetAttr(__pyx_t_4, __pyx_n_s__nan); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_k_15 = __pyx_t_2;
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_2 = PyFloat_FromDouble(9.9999999999999995e-07); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1049; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_k_16 = __pyx_t_2;
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_New(&__pyx_mdef_8interpnd_26CloughTocher2DInterpolator___init__, 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyMethod_New(__pyx_t_2, 0, __pyx_t_5); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_t_5, __pyx_n_s____init__, __pyx_t_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1048; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = PyCFunction_New(&__pyx_mdef_8interpnd_26CloughTocher2DInterpolator__evaluate_double, 0); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = PyMethod_New(__pyx_t_4, 0, __pyx_t_5); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyObject_SetAttr(__pyx_t_5, __pyx_n_s___evaluate_double, __pyx_t_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1058; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_New(&__pyx_mdef_8interpnd_26CloughTocher2DInterpolator__evaluate_complex, 0); if (unlikely(!__pyx_t_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyMethod_New(__pyx_t_2, 0, __pyx_t_5); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyObject_SetAttr(__pyx_t_5, __pyx_n_s___evaluate_complex, __pyx_t_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1114; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s_30, __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 988; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyDict_New(); if (unlikely(!__pyx_t_3)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(((PyObject *)__pyx_t_3));
  __pyx_t_5 = PyObject_GetAttr(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s____init__); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetAttrString(__pyx_t_4, "__doc__");
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_kp_u_31), __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyObject_GetAttr(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s___check_init_shape); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetAttrString(__pyx_t_4, "__doc__");
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_kp_u_32), __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyObject_GetAttr(__pyx_m, __pyx_n_s__NDInterpolatorBase); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = PyObject_GetAttr(__pyx_t_5, __pyx_n_s____call__); if (unlikely(!__pyx_t_4)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_GetAttrString(__pyx_t_4, "__doc__");
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_kp_u_33), __pyx_t_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyObject_GetAttr(__pyx_m, __pyx_n_s_2); if (unlikely(!__pyx_t_5)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = __Pyx_GetAttrString(__pyx_t_5, "__doc__");
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_3, ((PyObject *)__pyx_kp_u_34), __pyx_t_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s____test__, ((PyObject *)__pyx_t_3)) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1_error;}
  __Pyx_DECREF(((PyObject *)__pyx_t_3)); __pyx_t_3 = 0;

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  if (__pyx_m) {
    __Pyx_AddTraceback("init interpnd");
    Py_DECREF(__pyx_m); __pyx_m = 0;
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init interpnd");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if PY_MAJOR_VERSION < 3
  return;
  #else
  return __pyx_m;
  #endif
}

static const char *__pyx_filenames[] = {
  "interpnd.pyx",
  "numpy.pxd",
};



static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AS_STRING(kw_name));
        #endif
}

static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *number, *more_or_less;

    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    number = (num_expected == 1) ? "" : "s";
    PyErr_Format(PyExc_TypeError,
        #if PY_VERSION_HEX < 0x02050000
            "%s() takes %s %d positional argument%s (%d given)",
        #else
            "%s() takes %s %zd positional argument%s (%zd given)",
        #endif
        func_name, more_or_less, num_expected, number, num_found);
}

static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;

    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
        } else {
            #if PY_MAJOR_VERSION < 3
            if (unlikely(!PyString_CheckExact(key)) && unlikely(!PyString_Check(key))) {
            #else
            if (unlikely(!PyUnicode_CheckExact(key)) && unlikely(!PyUnicode_Check(key))) {
            #endif
                goto invalid_keyword_type;
            } else {
                for (name = first_kw_arg; *name; name++) {
                    #if PY_MAJOR_VERSION >= 3
                    if (PyUnicode_GET_SIZE(**name) == PyUnicode_GET_SIZE(key) &&
                        PyUnicode_Compare(**name, key) == 0) break;
                    #else
                    if (PyString_GET_SIZE(**name) == PyString_GET_SIZE(key) &&
                        _PyString_Eq(**name, key)) break;
                    #endif
                }
                if (*name) {
                    values[name-argnames] = value;
                } else {
                    
                    for (name=argnames; name != first_kw_arg; name++) {
                        if (**name == key) goto arg_passed_twice;
                        #if PY_MAJOR_VERSION >= 3
                        if (PyUnicode_GET_SIZE(**name) == PyUnicode_GET_SIZE(key) &&
                            PyUnicode_Compare(**name, key) == 0) goto arg_passed_twice;
                        #else
                        if (PyString_GET_SIZE(**name) == PyString_GET_SIZE(key) &&
                            _PyString_Eq(**name, key)) goto arg_passed_twice;
                        #endif
                    }
                    if (kwds2) {
                        if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
                    } else {
                        goto invalid_keyword;
                    }
                }
            }
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, **name);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%s() got an unexpected keyword argument '%s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}


static double __Pyx__PyObject_AsDouble(PyObject* obj) {
    PyObject* float_value;
    if (Py_TYPE(obj)->tp_as_number && Py_TYPE(obj)->tp_as_number->nb_float) {
        return PyFloat_AsDouble(obj);
    } else if (PyUnicode_CheckExact(obj) || PyBytes_CheckExact(obj)) {
#if PY_MAJOR_VERSION >= 3
        float_value = PyFloat_FromString(obj);
#else
        float_value = PyFloat_FromString(obj, 0);
#endif
    } else {
        PyObject* args = PyTuple_New(1);
        if (unlikely(!args)) goto bad;
        PyTuple_SET_ITEM(args, 0, obj);
        float_value = PyObject_Call((PyObject*)&PyFloat_Type, args, 0);
        PyTuple_SET_ITEM(args, 0, 0);
        Py_DECREF(args);
    }
    if (likely(float_value)) {
        double value = PyFloat_AS_DOUBLE(float_value);
        Py_DECREF(float_value);
        return value;
    }
bad:
    return (double)-1;
}

static CYTHON_INLINE int __Pyx_IsLittleEndian(void) {
  unsigned int n = 1;
  return *(unsigned char*)(&n) != 0;
}

typedef struct {
  __Pyx_StructField root;
  __Pyx_BufFmt_StackElem* head;
  size_t fmt_offset;
  int new_count, enc_count;
  int is_complex;
  char enc_type;
  char packmode;
} __Pyx_BufFmt_Context;

static void __Pyx_BufFmt_Init(__Pyx_BufFmt_Context* ctx,
                              __Pyx_BufFmt_StackElem* stack,
                              __Pyx_TypeInfo* type) {
  stack[0].field = &ctx->root;
  stack[0].parent_offset = 0;
  ctx->root.type = type;
  ctx->root.name = "buffer dtype";
  ctx->root.offset = 0;
  ctx->head = stack;
  ctx->head->field = &ctx->root;
  ctx->fmt_offset = 0;
  ctx->head->parent_offset = 0;
  ctx->packmode = '@';
  ctx->new_count = 1;
  ctx->enc_count = 0;
  ctx->enc_type = 0;
  ctx->is_complex = 0;
  while (type->typegroup == 'S') {
    ++ctx->head;
    ctx->head->field = type->fields;
    ctx->head->parent_offset = 0;
    type = type->fields->type;
  }
}

static int __Pyx_BufFmt_ParseNumber(const char** ts) {
    int count;
    const char* t = *ts;
    if (*t < '0' || *t > '9') {
      return -1;
    } else {
        count = *t++ - '0';
        while (*t >= '0' && *t < '9') {
            count *= 10;
            count += *t++ - '0';
        }
    }
    *ts = t;
    return count;
}

static void __Pyx_BufFmt_RaiseUnexpectedChar(char ch) {
  char msg[] = {ch, 0};
  PyErr_Format(PyExc_ValueError, "Unexpected format string character: '%s'", msg);
}

static const char* __Pyx_BufFmt_DescribeTypeChar(char ch, int is_complex) {
  switch (ch) {
    case 'b': return "'char'";
    case 'B': return "'unsigned char'";
    case 'h': return "'short'";
    case 'H': return "'unsigned short'";
    case 'i': return "'int'";
    case 'I': return "'unsigned int'";
    case 'l': return "'long'";
    case 'L': return "'unsigned long'";
    case 'q': return "'long long'";
    case 'Q': return "'unsigned long long'";
    case 'f': return (is_complex ? "'complex float'" : "'float'");
    case 'd': return (is_complex ? "'complex double'" : "'double'");
    case 'g': return (is_complex ? "'complex long double'" : "'long double'");
    case 'T': return "a struct";
    case 'O': return "Python object";
    case 'P': return "a pointer";
    case 0: return "end";
    default: return "unparseable format string";
  }
}

static size_t __Pyx_BufFmt_TypeCharToStandardSize(char ch, int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': return 1;
    case 'h': case 'H': return 2;
    case 'i': case 'I': case 'l': case 'L': return 4;
    case 'q': case 'Q': return 8;
    case 'f': return (is_complex ? 8 : 4);
    case 'd': return (is_complex ? 16 : 8);
    case 'g': {
      PyErr_SetString(PyExc_ValueError, "Python does not define a standard format string size for long double ('g')..");
      return 0;
    }
    case 'O': case 'P': return sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}

static size_t __Pyx_BufFmt_TypeCharToNativeSize(char ch, int is_complex) {
  switch (ch) {
    case 'c': case 'b': case 'B': return 1;
    case 'h': case 'H': return sizeof(short);
    case 'i': case 'I': return sizeof(int);
    case 'l': case 'L': return sizeof(long);
    #ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(PY_LONG_LONG);
    #endif
    case 'f': return sizeof(float) * (is_complex ? 2 : 1);
    case 'd': return sizeof(double) * (is_complex ? 2 : 1);
    case 'g': return sizeof(long double) * (is_complex ? 2 : 1);
    case 'O': case 'P': return sizeof(void*);
    default: {
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }    
  }
}

typedef struct { char c; short x; } __Pyx_st_short;
typedef struct { char c; int x; } __Pyx_st_int;
typedef struct { char c; long x; } __Pyx_st_long;
typedef struct { char c; float x; } __Pyx_st_float;
typedef struct { char c; double x; } __Pyx_st_double;
typedef struct { char c; long double x; } __Pyx_st_longdouble;
typedef struct { char c; void *x; } __Pyx_st_void_p;
#ifdef HAVE_LONG_LONG
typedef struct { char c; PY_LONG_LONG x; } __Pyx_s_long_long;
#endif

static size_t __Pyx_BufFmt_TypeCharToAlignment(char ch, int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': return 1;
    case 'h': case 'H': return sizeof(__Pyx_st_short) - sizeof(short);
    case 'i': case 'I': return sizeof(__Pyx_st_int) - sizeof(int);
    case 'l': case 'L': return sizeof(__Pyx_st_long) - sizeof(long);
#ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(__Pyx_s_long_long) - sizeof(PY_LONG_LONG);
#endif
    case 'f': return sizeof(__Pyx_st_float) - sizeof(float);
    case 'd': return sizeof(__Pyx_st_double) - sizeof(double);
    case 'g': return sizeof(__Pyx_st_longdouble) - sizeof(long double);
    case 'P': case 'O': return sizeof(__Pyx_st_void_p) - sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}

static size_t __Pyx_BufFmt_TypeCharToGroup(char ch, int is_complex) {
  switch (ch) {
    case 'c': case 'b': case 'h': case 'i': case 'l': case 'q': return 'I';
    case 'B': case 'H': case 'I': case 'L': case 'Q': return 'U';
    case 'f': case 'd': case 'g': return (is_complex ? 'C' : 'R');
    case 'O': return 'O';
    case 'P': return 'P';
    default: {
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }    
  }
}

static void __Pyx_BufFmt_RaiseExpected(__Pyx_BufFmt_Context* ctx) {
  if (ctx->head == NULL || ctx->head->field == &ctx->root) {
    const char* expected;
    const char* quote;
    if (ctx->head == NULL) {
      expected = "end";
      quote = "";
    } else {
      expected = ctx->head->field->type->name;
      quote = "'";
    }
    PyErr_Format(PyExc_ValueError,
                 "Buffer dtype mismatch, expected %s%s%s but got %s",
                 quote, expected, quote,
                 __Pyx_BufFmt_DescribeTypeChar(ctx->enc_type, ctx->is_complex));
  } else {
    __Pyx_StructField* field = ctx->head->field;
    __Pyx_StructField* parent = (ctx->head - 1)->field;
    PyErr_Format(PyExc_ValueError,
                 "Buffer dtype mismatch, expected '%s' but got %s in '%s.%s'",
                 field->type->name, __Pyx_BufFmt_DescribeTypeChar(ctx->enc_type, ctx->is_complex),
                 parent->type->name, field->name);
  }
}

static int __Pyx_BufFmt_ProcessTypeChunk(__Pyx_BufFmt_Context* ctx) {
  char group;
  size_t size, offset;
  if (ctx->enc_type == 0) return 0;
  group = __Pyx_BufFmt_TypeCharToGroup(ctx->enc_type, ctx->is_complex);
  do {
    __Pyx_StructField* field = ctx->head->field;
    __Pyx_TypeInfo* type = field->type;
  
    if (ctx->packmode == '@' || ctx->packmode == '^') {
      size = __Pyx_BufFmt_TypeCharToNativeSize(ctx->enc_type, ctx->is_complex);
    } else {
      size = __Pyx_BufFmt_TypeCharToStandardSize(ctx->enc_type, ctx->is_complex);
    }
    if (ctx->packmode == '@') {
      int align_at = __Pyx_BufFmt_TypeCharToAlignment(ctx->enc_type, ctx->is_complex);
      int align_mod_offset;
      if (align_at == 0) return -1;
      align_mod_offset = ctx->fmt_offset % align_at;
      if (align_mod_offset > 0) ctx->fmt_offset += align_at - align_mod_offset;
    }

    if (type->size != size || type->typegroup != group) {
      if (type->typegroup == 'C' && type->fields != NULL) {
        
        size_t parent_offset = ctx->head->parent_offset + field->offset;
        ++ctx->head;
        ctx->head->field = type->fields;
        ctx->head->parent_offset = parent_offset;
        continue;
      }
    
      __Pyx_BufFmt_RaiseExpected(ctx);
      return -1;
    }

    offset = ctx->head->parent_offset + field->offset;
    if (ctx->fmt_offset != offset) {
      PyErr_Format(PyExc_ValueError,
                   "Buffer dtype mismatch; next field is at offset %"PY_FORMAT_SIZE_T"d "
                   "but %"PY_FORMAT_SIZE_T"d expected", ctx->fmt_offset, offset);
      return -1;
    }

    ctx->fmt_offset += size;
  
    --ctx->enc_count; 

    
    while (1) {
      if (field == &ctx->root) {
        ctx->head = NULL;
        if (ctx->enc_count != 0) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return -1;
        }
        break; 
      }
      ctx->head->field = ++field;
      if (field->type == NULL) {
        --ctx->head;
        field = ctx->head->field;
        continue;
      } else if (field->type->typegroup == 'S') {
        size_t parent_offset = ctx->head->parent_offset + field->offset;
        if (field->type->fields->type == NULL) continue; 
        field = field->type->fields;
        ++ctx->head;
        ctx->head->field = field;
        ctx->head->parent_offset = parent_offset;
        break;
      } else {
        break;
      }
    }
  } while (ctx->enc_count);
  ctx->enc_type = 0;
  ctx->is_complex = 0;
  return 0;    
}

static int __Pyx_BufFmt_FirstPack(__Pyx_BufFmt_Context* ctx) {
  if (ctx->enc_type != 0 || ctx->packmode != '@') {
    PyErr_SetString(PyExc_ValueError, "Buffer packing mode currently only allowed at beginning of format string (this is a defect)");
    return -1;
  }
  return 0;
}

static const char* __Pyx_BufFmt_CheckString(__Pyx_BufFmt_Context* ctx, const char* ts) {
  int got_Z = 0;
  while (1) {
    switch(*ts) {
      case 0:
        if (ctx->enc_type != 0 && ctx->head == NULL) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return NULL;
        }
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        if (ctx->head != NULL) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return NULL;
        }
        return ts;
      case ' ':
      case 10:
      case 13:
        ++ts;
        break;
      case '<':
        if (!__Pyx_IsLittleEndian()) {
          PyErr_SetString(PyExc_ValueError, "Little-endian buffer not supported on big-endian compiler");
          return NULL;
        }
        if (__Pyx_BufFmt_FirstPack(ctx) == -1) return NULL;
        ctx->packmode = '=';
        ++ts;
        break;
      case '>':
      case '!':
        if (__Pyx_IsLittleEndian()) {
          PyErr_SetString(PyExc_ValueError, "Big-endian buffer not supported on little-endian compiler");
          return NULL;
        }
        if (__Pyx_BufFmt_FirstPack(ctx) == -1) return NULL;
        ctx->packmode = '=';
        ++ts;
        break;
      case '=':
      case '@':
      case '^':
        if (__Pyx_BufFmt_FirstPack(ctx) == -1) return NULL;
        ctx->packmode = *ts++;
        break;
      case 'T': 
        {
          int i;
          const char* ts_after_sub;
          int struct_count = ctx->new_count;
          ctx->new_count = 1;
          ++ts;
          if (*ts != '{') {
            PyErr_SetString(PyExc_ValueError, "Buffer acquisition: Expected '{' after 'T'");
            return NULL;
          }
          ++ts;
          ts_after_sub = ts;
          for (i = 0; i != struct_count; ++i) {
            ts_after_sub = __Pyx_BufFmt_CheckString(ctx, ts);
            if (!ts_after_sub) return NULL;
          }
          ts = ts_after_sub;
        }
        break;
      case '}': 
        ++ts;
        return ts;
      case 'x':
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        ctx->fmt_offset += ctx->new_count;
        ctx->new_count = 1;
        ctx->enc_count = 0;
        ctx->enc_type = 0;
        ++ts;
        break;
      case 'Z':
        got_Z = 1;
        ++ts;
        if (*ts != 'f' && *ts != 'd' && *ts != 'g') {
          __Pyx_BufFmt_RaiseUnexpectedChar('Z');
          return NULL;
        }        
      case 'c': case 'b': case 'B': case 'h': case 'H': case 'i': case 'I':
      case 'l': case 'L': case 'q': case 'Q':
      case 'f': case 'd': case 'g':
      case 'O':
        if (ctx->enc_type == *ts && got_Z == ctx->is_complex) {
          
          ctx->enc_count += ctx->new_count;
        } else {
          
          if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
          ctx->enc_count = ctx->new_count;
          ctx->enc_type = *ts;
          ctx->is_complex = got_Z;
        }
        ++ts;
        ctx->new_count = 1;
        got_Z = 0;
        break;
      default:
        {
          ctx->new_count = __Pyx_BufFmt_ParseNumber(&ts);
          if (ctx->new_count == -1) { 
            char msg[2] = { *ts, 0 };
            PyErr_Format(PyExc_ValueError,
                         "Does not understand character buffer dtype format string ('%s')", msg);
            return NULL;
          }
        }
      
    }
  }
}

static CYTHON_INLINE void __Pyx_ZeroBuffer(Py_buffer* buf) {
  buf->buf = NULL;
  buf->obj = NULL;
  buf->strides = __Pyx_zeros;
  buf->shape = __Pyx_zeros;
  buf->suboffsets = __Pyx_minusones;
}

static int __Pyx_GetBufferAndValidate(Py_buffer* buf, PyObject* obj, __Pyx_TypeInfo* dtype, int flags, int nd, int cast, __Pyx_BufFmt_StackElem* stack) {
  if (obj == Py_None) {
    __Pyx_ZeroBuffer(buf);
    return 0;
  }
  buf->buf = NULL;
  if (__Pyx_GetBuffer(obj, buf, flags) == -1) goto fail;
  if (buf->ndim != nd) {
    PyErr_Format(PyExc_ValueError,
                 "Buffer has wrong number of dimensions (expected %d, got %d)",
                 nd, buf->ndim);
    goto fail;
  }
  if (!cast) {
    __Pyx_BufFmt_Context ctx;
    __Pyx_BufFmt_Init(&ctx, stack, dtype);
    if (!__Pyx_BufFmt_CheckString(&ctx, buf->format)) goto fail;
  }
  if ((unsigned)buf->itemsize != dtype->size) {
    PyErr_Format(PyExc_ValueError,
      "Item size of buffer (%"PY_FORMAT_SIZE_T"d byte%s) does not match size of '%s' (%"PY_FORMAT_SIZE_T"d byte%s)",
      buf->itemsize, (buf->itemsize > 1) ? "s" : "",
      dtype->name,
      dtype->size, (dtype->size > 1) ? "s" : "");
    goto fail;
  }
  if (buf->suboffsets == NULL) buf->suboffsets = __Pyx_minusones;
  return 0;
fail:;
  __Pyx_ZeroBuffer(buf);
  return -1;
}

static CYTHON_INLINE void __Pyx_SafeReleaseBuffer(Py_buffer* info) {
  if (info->buf == NULL) return;
  if (info->suboffsets == __Pyx_minusones) info->suboffsets = NULL;
  __Pyx_ReleaseBuffer(info);
}

static CYTHON_INLINE int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type) {
    if (unlikely(!type)) {
        PyErr_Format(PyExc_SystemError, "Missing type object");
        return 0;
    }
    if (likely(PyObject_TypeCheck(obj, type)))
        return 1;
    PyErr_Format(PyExc_TypeError, "Cannot convert %.200s to %.200s",
                 Py_TYPE(obj)->tp_name, type->tp_name);
    return 0;
}

static void __Pyx_RaiseBufferFallbackError(void) {
  PyErr_Format(PyExc_ValueError,
     "Buffer acquisition failed on assignment; and then reacquiring the old buffer failed too!");
}


static CYTHON_INLINE void __Pyx_ErrRestore(PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyThreadState *tstate = PyThreadState_GET();

    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}

static CYTHON_INLINE void __Pyx_ErrFetch(PyObject **type, PyObject **value, PyObject **tb) {
    PyThreadState *tstate = PyThreadState_GET();
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;

    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}


static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
        #if PY_VERSION_HEX < 0x02050000
                 "need more than %d value%s to unpack", (int)index,
        #else
                 "need more than %zd value%s to unpack", index,
        #endif
                 (index == 1) ? "" : "s");
}

static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(void) {
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
}

static PyObject *__Pyx_UnpackItem(PyObject *iter, Py_ssize_t index) {
    PyObject *item;
    if (!(item = PyIter_Next(iter))) {
        if (!PyErr_Occurred()) {
            __Pyx_RaiseNeedMoreValuesError(index);
        }
    }
    return item;
}

static int __Pyx_EndUnpack(PyObject *iter) {
    PyObject *item;
    if ((item = PyIter_Next(iter))) {
        Py_DECREF(item);
        __Pyx_RaiseTooManyValuesError();
        return -1;
    }
    else if (!PyErr_Occurred())
        return 0;
    else
        return -1;
}

static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
}

static void __Pyx_UnpackTupleError(PyObject *t, Py_ssize_t index) {
    if (t == Py_None) {
      __Pyx_RaiseNoneNotIterableError();
    } else if (PyTuple_GET_SIZE(t) < index) {
      __Pyx_RaiseNeedMoreValuesError(PyTuple_GET_SIZE(t));
    } else {
      __Pyx_RaiseTooManyValuesError();
    }
}

static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed,
    const char *name, int exact)
{
    if (!type) {
        PyErr_Format(PyExc_SystemError, "Missing type object");
        return 0;
    }
    if (none_allowed && obj == Py_None) return 1;
    else if (exact) {
        if (Py_TYPE(obj) == type) return 1;
    }
    else {
        if (PyObject_TypeCheck(obj, type)) return 1;
    }
    PyErr_Format(PyExc_TypeError,
        "Argument '%s' has incorrect type (expected %s, got %s)",
        name, type->tp_name, Py_TYPE(obj)->tp_name);
    return 0;
}

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      return ::std::complex< double >(x, y);
    }
  #else
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      return x + y*(__pyx_t_double_complex)_Complex_I;
    }
  #endif
#else
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      __pyx_t_double_complex z;
      z.real = x;
      z.imag = y;
      return z;
    }
#endif

#if CYTHON_CCOMPLEX
#else
    static CYTHON_INLINE int __Pyx_c_eq(__pyx_t_double_complex a, __pyx_t_double_complex b) {
       return (a.real == b.real) && (a.imag == b.imag);
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_sum(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real + b.real;
        z.imag = a.imag + b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_diff(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real - b.real;
        z.imag = a.imag - b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_prod(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real * b.real - a.imag * b.imag;
        z.imag = a.real * b.imag + a.imag * b.real;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        double denom = b.real * b.real + b.imag * b.imag;
        z.real = (a.real * b.real + a.imag * b.imag) / denom;
        z.imag = (a.imag * b.real - a.real * b.imag) / denom;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_neg(__pyx_t_double_complex a) {
        __pyx_t_double_complex z;
        z.real = -a.real;
        z.imag = -a.imag;
        return z;
    }
    static CYTHON_INLINE int __Pyx_c_is_zero(__pyx_t_double_complex a) {
       return (a.real == 0) && (a.imag == 0);
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_conj(__pyx_t_double_complex a) {
        __pyx_t_double_complex z;
        z.real =  a.real;
        z.imag = -a.imag;
        return z;
    }

#endif

#if PY_MAJOR_VERSION < 3
static int __Pyx_GetBuffer(PyObject *obj, Py_buffer *view, int flags) {
  #if PY_VERSION_HEX >= 0x02060000
  if (Py_TYPE(obj)->tp_flags & Py_TPFLAGS_HAVE_NEWBUFFER)
      return PyObject_GetBuffer(obj, view, flags);
  #endif
  if (PyObject_TypeCheck(obj, __pyx_ptype_5numpy_ndarray)) return __pyx_pf_5numpy_7ndarray___getbuffer__(obj, view, flags);
  else {
  PyErr_Format(PyExc_TypeError, "'%100s' does not have the buffer interface", Py_TYPE(obj)->tp_name);
  return -1;
    }
}

static void __Pyx_ReleaseBuffer(Py_buffer *view) {
  PyObject* obj = view->obj;
  if (obj) {
if (PyObject_TypeCheck(obj, __pyx_ptype_5numpy_ndarray)) __pyx_pf_5numpy_7ndarray___releasebuffer__(obj, view);
    Py_DECREF(obj);
    view->obj = NULL;
  }
}

#endif

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list) {
    PyObject *__import__ = 0;
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    __import__ = __Pyx_GetAttrString(__pyx_b, "__import__");
    if (!__import__)
        goto bad;
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    module = PyObject_CallFunctionObjArgs(__import__,
        name, global_dict, empty_dict, list, NULL);
bad:
    Py_XDECREF(empty_list);
    Py_XDECREF(__import__);
    Py_XDECREF(empty_dict);
    return module;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
    PyObject *result;
    result = PyObject_GetAttr(dict, name);
    if (!result)
        PyErr_SetObject(PyExc_NameError, name);
    return result;
}

static PyObject *__Pyx_CreateClass(
    PyObject *bases, PyObject *dict, PyObject *name, const char *modname)
{
    PyObject *py_modname;
    PyObject *result = 0;

    #if PY_MAJOR_VERSION < 3
    py_modname = PyString_FromString(modname);
    #else
    py_modname = PyUnicode_FromString(modname);
    #endif
    if (!py_modname)
        goto bad;
    if (PyDict_SetItemString(dict, "__module__", py_modname) < 0)
        goto bad;
    #if PY_MAJOR_VERSION < 3
    result = PyClass_New(bases, dict, name);
    #else
    result = PyObject_CallFunctionObjArgs((PyObject *)&PyType_Type, name, bases, dict, NULL);
    #endif
bad:
    Py_XDECREF(py_modname);
    return result;
}

#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    Py_XINCREF(type);
    Py_XINCREF(value);
    Py_XINCREF(tb);
    
    if (tb == Py_None) {
        Py_DECREF(tb);
        tb = 0;
    }
    else if (tb != NULL && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto raise_error;
    }
    
    if (value == NULL) {
        value = Py_None;
        Py_INCREF(value);
    }
    #if PY_VERSION_HEX < 0x02050000
    if (!PyClass_Check(type))
    #else
    if (!PyType_Check(type))
    #endif
    {
        
        if (value != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        
        Py_DECREF(value);
        value = type;
        #if PY_VERSION_HEX < 0x02050000
            if (PyInstance_Check(type)) {
                type = (PyObject*) ((PyInstanceObject*)type)->in_class;
                Py_INCREF(type);
            }
            else {
                type = 0;
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception must be an old-style class or instance");
                goto raise_error;
            }
        #else
            type = (PyObject*) Py_TYPE(type);
            Py_INCREF(type);
            if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception class must be a subclass of BaseException");
                goto raise_error;
            }
        #endif
    }

    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}

#else 

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;

    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (!PyExceptionClass_Check(type)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }

    PyErr_SetObject(type, value);

    if (tb) {
        PyThreadState *tstate = PyThreadState_GET();
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
    }

bad:
    return;
}
#endif

static CYTHON_INLINE PyObject *__Pyx_PyInt_to_py_npy_intp(npy_intp val) {
    const npy_intp neg_one = (npy_intp)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(npy_intp) <  sizeof(long)) {
        return PyInt_FromLong((long)val);
    } else if (sizeof(npy_intp) == sizeof(long)) {
        if (is_unsigned)
            return PyLong_FromUnsignedLong((unsigned long)val);
        else
            return PyInt_FromLong((long)val);
    } else { 
        if (is_unsigned)
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG)val);
        else
            return PyLong_FromLongLong((PY_LONG_LONG)val);
    }
}

static __pyx_t_double_complex __Pyx_PyComplex_As___pyx_t_double_complex(PyObject* o) {
    Py_complex cval;
    if (PyComplex_CheckExact(o))
        cval = ((PyComplexObject *)o)->cval;
    else
        cval = PyComplex_AsCComplex(o);
    return __pyx_t_double_complex_from_parts(
               (double)cval.real,
               (double)cval.imag);
}

#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      return ::std::complex< float >(x, y);
    }
  #else
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      return x + y*(__pyx_t_float_complex)_Complex_I;
    }
  #endif
#else
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      __pyx_t_float_complex z;
      z.real = x;
      z.imag = y;
      return z;
    }
#endif

#if CYTHON_CCOMPLEX
#else
    static CYTHON_INLINE int __Pyx_c_eqf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
       return (a.real == b.real) && (a.imag == b.imag);
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_sumf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real + b.real;
        z.imag = a.imag + b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_difff(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real - b.real;
        z.imag = a.imag - b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_prodf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real * b.real - a.imag * b.imag;
        z.imag = a.real * b.imag + a.imag * b.real;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quotf(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        float denom = b.real * b.real + b.imag * b.imag;
        z.real = (a.real * b.real + a.imag * b.imag) / denom;
        z.imag = (a.imag * b.real - a.real * b.imag) / denom;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_negf(__pyx_t_float_complex a) {
        __pyx_t_float_complex z;
        z.real = -a.real;
        z.imag = -a.imag;
        return z;
    }
    static CYTHON_INLINE int __Pyx_c_is_zerof(__pyx_t_float_complex a) {
       return (a.real == 0) && (a.imag == 0);
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_conjf(__pyx_t_float_complex a) {
        __pyx_t_float_complex z;
        z.real =  a.real;
        z.imag = -a.imag;
        return z;
    }

#endif

static CYTHON_INLINE unsigned char __Pyx_PyInt_AsUnsignedChar(PyObject* x) {
    const unsigned char neg_one = (unsigned char)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(unsigned char) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(unsigned char)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to unsigned char" :
                    "value too large to convert to unsigned char");
            }
            return (unsigned char)-1;
        }
        return (unsigned char)val;
    }
    return (unsigned char)__Pyx_PyInt_AsUnsignedLong(x);
}

static CYTHON_INLINE unsigned short __Pyx_PyInt_AsUnsignedShort(PyObject* x) {
    const unsigned short neg_one = (unsigned short)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(unsigned short) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(unsigned short)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to unsigned short" :
                    "value too large to convert to unsigned short");
            }
            return (unsigned short)-1;
        }
        return (unsigned short)val;
    }
    return (unsigned short)__Pyx_PyInt_AsUnsignedLong(x);
}

static CYTHON_INLINE unsigned int __Pyx_PyInt_AsUnsignedInt(PyObject* x) {
    const unsigned int neg_one = (unsigned int)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(unsigned int) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(unsigned int)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to unsigned int" :
                    "value too large to convert to unsigned int");
            }
            return (unsigned int)-1;
        }
        return (unsigned int)val;
    }
    return (unsigned int)__Pyx_PyInt_AsUnsignedLong(x);
}

static CYTHON_INLINE char __Pyx_PyInt_AsChar(PyObject* x) {
    const char neg_one = (char)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(char) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(char)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to char" :
                    "value too large to convert to char");
            }
            return (char)-1;
        }
        return (char)val;
    }
    return (char)__Pyx_PyInt_AsLong(x);
}

static CYTHON_INLINE short __Pyx_PyInt_AsShort(PyObject* x) {
    const short neg_one = (short)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(short) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(short)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to short" :
                    "value too large to convert to short");
            }
            return (short)-1;
        }
        return (short)val;
    }
    return (short)__Pyx_PyInt_AsLong(x);
}

static CYTHON_INLINE int __Pyx_PyInt_AsInt(PyObject* x) {
    const int neg_one = (int)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(int) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(int)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to int" :
                    "value too large to convert to int");
            }
            return (int)-1;
        }
        return (int)val;
    }
    return (int)__Pyx_PyInt_AsLong(x);
}

static CYTHON_INLINE signed char __Pyx_PyInt_AsSignedChar(PyObject* x) {
    const signed char neg_one = (signed char)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(signed char) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(signed char)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to signed char" :
                    "value too large to convert to signed char");
            }
            return (signed char)-1;
        }
        return (signed char)val;
    }
    return (signed char)__Pyx_PyInt_AsSignedLong(x);
}

static CYTHON_INLINE signed short __Pyx_PyInt_AsSignedShort(PyObject* x) {
    const signed short neg_one = (signed short)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(signed short) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(signed short)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to signed short" :
                    "value too large to convert to signed short");
            }
            return (signed short)-1;
        }
        return (signed short)val;
    }
    return (signed short)__Pyx_PyInt_AsSignedLong(x);
}

static CYTHON_INLINE signed int __Pyx_PyInt_AsSignedInt(PyObject* x) {
    const signed int neg_one = (signed int)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
    if (sizeof(signed int) < sizeof(long)) {
        long val = __Pyx_PyInt_AsLong(x);
        if (unlikely(val != (long)(signed int)val)) {
            if (!unlikely(val == -1 && PyErr_Occurred())) {
                PyErr_SetString(PyExc_OverflowError,
                    (is_unsigned && unlikely(val < 0)) ?
                    "can't convert negative value to signed int" :
                    "value too large to convert to signed int");
            }
            return (signed int)-1;
        }
        return (signed int)val;
    }
    return (signed int)__Pyx_PyInt_AsSignedLong(x);
}

static CYTHON_INLINE unsigned long __Pyx_PyInt_AsUnsignedLong(PyObject* x) {
    const unsigned long neg_one = (unsigned long)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_VERSION_HEX < 0x03000000
    if (likely(PyInt_Check(x))) {
        long val = PyInt_AS_LONG(x);
        if (is_unsigned && unlikely(val < 0)) {
            PyErr_SetString(PyExc_OverflowError,
                            "can't convert negative value to unsigned long");
            return (unsigned long)-1;
        }
        return (unsigned long)val;
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
            if (unlikely(Py_SIZE(x) < 0)) {
                PyErr_SetString(PyExc_OverflowError,
                                "can't convert negative value to unsigned long");
                return (unsigned long)-1;
            }
            return PyLong_AsUnsignedLong(x);
        } else {
            return PyLong_AsLong(x);
        }
    } else {
        unsigned long val;
        PyObject *tmp = __Pyx_PyNumber_Int(x);
        if (!tmp) return (unsigned long)-1;
        val = __Pyx_PyInt_AsUnsignedLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static CYTHON_INLINE unsigned PY_LONG_LONG __Pyx_PyInt_AsUnsignedLongLong(PyObject* x) {
    const unsigned PY_LONG_LONG neg_one = (unsigned PY_LONG_LONG)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_VERSION_HEX < 0x03000000
    if (likely(PyInt_Check(x))) {
        long val = PyInt_AS_LONG(x);
        if (is_unsigned && unlikely(val < 0)) {
            PyErr_SetString(PyExc_OverflowError,
                            "can't convert negative value to unsigned PY_LONG_LONG");
            return (unsigned PY_LONG_LONG)-1;
        }
        return (unsigned PY_LONG_LONG)val;
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
            if (unlikely(Py_SIZE(x) < 0)) {
                PyErr_SetString(PyExc_OverflowError,
                                "can't convert negative value to unsigned PY_LONG_LONG");
                return (unsigned PY_LONG_LONG)-1;
            }
            return PyLong_AsUnsignedLongLong(x);
        } else {
            return PyLong_AsLongLong(x);
        }
    } else {
        unsigned PY_LONG_LONG val;
        PyObject *tmp = __Pyx_PyNumber_Int(x);
        if (!tmp) return (unsigned PY_LONG_LONG)-1;
        val = __Pyx_PyInt_AsUnsignedLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static CYTHON_INLINE long __Pyx_PyInt_AsLong(PyObject* x) {
    const long neg_one = (long)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_VERSION_HEX < 0x03000000
    if (likely(PyInt_Check(x))) {
        long val = PyInt_AS_LONG(x);
        if (is_unsigned && unlikely(val < 0)) {
            PyErr_SetString(PyExc_OverflowError,
                            "can't convert negative value to long");
            return (long)-1;
        }
        return (long)val;
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
            if (unlikely(Py_SIZE(x) < 0)) {
                PyErr_SetString(PyExc_OverflowError,
                                "can't convert negative value to long");
                return (long)-1;
            }
            return PyLong_AsUnsignedLong(x);
        } else {
            return PyLong_AsLong(x);
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_Int(x);
        if (!tmp) return (long)-1;
        val = __Pyx_PyInt_AsLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static CYTHON_INLINE PY_LONG_LONG __Pyx_PyInt_AsLongLong(PyObject* x) {
    const PY_LONG_LONG neg_one = (PY_LONG_LONG)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_VERSION_HEX < 0x03000000
    if (likely(PyInt_Check(x))) {
        long val = PyInt_AS_LONG(x);
        if (is_unsigned && unlikely(val < 0)) {
            PyErr_SetString(PyExc_OverflowError,
                            "can't convert negative value to PY_LONG_LONG");
            return (PY_LONG_LONG)-1;
        }
        return (PY_LONG_LONG)val;
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
            if (unlikely(Py_SIZE(x) < 0)) {
                PyErr_SetString(PyExc_OverflowError,
                                "can't convert negative value to PY_LONG_LONG");
                return (PY_LONG_LONG)-1;
            }
            return PyLong_AsUnsignedLongLong(x);
        } else {
            return PyLong_AsLongLong(x);
        }
    } else {
        PY_LONG_LONG val;
        PyObject *tmp = __Pyx_PyNumber_Int(x);
        if (!tmp) return (PY_LONG_LONG)-1;
        val = __Pyx_PyInt_AsLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static CYTHON_INLINE signed long __Pyx_PyInt_AsSignedLong(PyObject* x) {
    const signed long neg_one = (signed long)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_VERSION_HEX < 0x03000000
    if (likely(PyInt_Check(x))) {
        long val = PyInt_AS_LONG(x);
        if (is_unsigned && unlikely(val < 0)) {
            PyErr_SetString(PyExc_OverflowError,
                            "can't convert negative value to signed long");
            return (signed long)-1;
        }
        return (signed long)val;
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
            if (unlikely(Py_SIZE(x) < 0)) {
                PyErr_SetString(PyExc_OverflowError,
                                "can't convert negative value to signed long");
                return (signed long)-1;
            }
            return PyLong_AsUnsignedLong(x);
        } else {
            return PyLong_AsLong(x);
        }
    } else {
        signed long val;
        PyObject *tmp = __Pyx_PyNumber_Int(x);
        if (!tmp) return (signed long)-1;
        val = __Pyx_PyInt_AsSignedLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static CYTHON_INLINE signed PY_LONG_LONG __Pyx_PyInt_AsSignedLongLong(PyObject* x) {
    const signed PY_LONG_LONG neg_one = (signed PY_LONG_LONG)-1, const_zero = 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_VERSION_HEX < 0x03000000
    if (likely(PyInt_Check(x))) {
        long val = PyInt_AS_LONG(x);
        if (is_unsigned && unlikely(val < 0)) {
            PyErr_SetString(PyExc_OverflowError,
                            "can't convert negative value to signed PY_LONG_LONG");
            return (signed PY_LONG_LONG)-1;
        }
        return (signed PY_LONG_LONG)val;
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
            if (unlikely(Py_SIZE(x) < 0)) {
                PyErr_SetString(PyExc_OverflowError,
                                "can't convert negative value to signed PY_LONG_LONG");
                return (signed PY_LONG_LONG)-1;
            }
            return PyLong_AsUnsignedLongLong(x);
        } else {
            return PyLong_AsLongLong(x);
        }
    } else {
        signed PY_LONG_LONG val;
        PyObject *tmp = __Pyx_PyNumber_Int(x);
        if (!tmp) return (signed PY_LONG_LONG)-1;
        val = __Pyx_PyInt_AsSignedLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

#ifndef __PYX_HAVE_RT_ImportType
#define __PYX_HAVE_RT_ImportType
static PyTypeObject *__Pyx_ImportType(const char *module_name, const char *class_name,
    long size, int strict)
{
    PyObject *py_module = 0;
    PyObject *result = 0;
    PyObject *py_name = 0;
    char warning[200];

    py_module = __Pyx_ImportModule(module_name);
    if (!py_module)
        goto bad;
    #if PY_MAJOR_VERSION < 3
    py_name = PyString_FromString(class_name);
    #else
    py_name = PyUnicode_FromString(class_name);
    #endif
    if (!py_name)
        goto bad;
    result = PyObject_GetAttr(py_module, py_name);
    Py_DECREF(py_name);
    py_name = 0;
    Py_DECREF(py_module);
    py_module = 0;
    if (!result)
        goto bad;
    if (!PyType_Check(result)) {
        PyErr_Format(PyExc_TypeError, 
            "%s.%s is not a type object",
            module_name, class_name);
        goto bad;
    }
    if (!strict && ((PyTypeObject *)result)->tp_basicsize > size) {
        PyOS_snprintf(warning, sizeof(warning), 
            "%s.%s size changed, may indicate binary incompatibility",
            module_name, class_name);
        PyErr_WarnEx(NULL, warning, 0);
    }
    else if (((PyTypeObject *)result)->tp_basicsize != size) {
        PyErr_Format(PyExc_ValueError, 
            "%s.%s has the wrong size, try recompiling",
            module_name, class_name);
        goto bad;
    }
    return (PyTypeObject *)result;
bad:
    Py_XDECREF(py_module);
    Py_XDECREF(result);
    return 0;
}
#endif

#ifndef __PYX_HAVE_RT_ImportModule
#define __PYX_HAVE_RT_ImportModule
static PyObject *__Pyx_ImportModule(const char *name) {
    PyObject *py_name = 0;
    PyObject *py_module = 0;

    #if PY_MAJOR_VERSION < 3
    py_name = PyString_FromString(name);
    #else
    py_name = PyUnicode_FromString(name);
    #endif
    if (!py_name)
        goto bad;
    py_module = PyImport_Import(py_name);
    Py_DECREF(py_name);
    return py_module;
bad:
    Py_XDECREF(py_name);
    return 0;
}
#endif

#ifndef __PYX_HAVE_RT_ImportFunction
#define __PYX_HAVE_RT_ImportFunction
static int __Pyx_ImportFunction(PyObject *module, const char *funcname, void (**f)(void), const char *sig) {
    PyObject *d = 0;
    PyObject *cobj = 0;
    union {
        void (*fp)(void);
        void *p;
    } tmp;
#if PY_VERSION_HEX < 0x03010000
    const char *desc, *s1, *s2;
#endif

    d = PyObject_GetAttrString(module, (char *)"__pyx_capi__");
    if (!d)
        goto bad;
    cobj = PyDict_GetItemString(d, funcname);
    if (!cobj) {
        PyErr_Format(PyExc_ImportError,
            "%s does not export expected C function %s",
                PyModule_GetName(module), funcname);
        goto bad;
    }
#if PY_VERSION_HEX < 0x03010000
    desc = (const char *)PyCObject_GetDesc(cobj);
    if (!desc)
        goto bad;
    s1 = desc; s2 = sig;
    while (*s1 != '\0' && *s1 == *s2) { s1++; s2++; }
    if (*s1 != *s2) {
        PyErr_Format(PyExc_TypeError,
            "C function %s.%s has wrong signature (expected %s, got %s)",
             PyModule_GetName(module), funcname, sig, desc);
        goto bad;
    }
    tmp.p = PyCObject_AsVoidPtr(cobj);
#else
    if (!PyCapsule_IsValid(cobj, sig)) {
        PyErr_Format(PyExc_TypeError,
            "C function %s.%s has wrong signature (expected %s, got %s)",
             PyModule_GetName(module), funcname, sig, PyCapsule_GetName(cobj));
        goto bad;
    }
    tmp.p = PyCapsule_GetPointer(cobj, sig);
#endif
    *f = tmp.fp;
    if (!(*f))
        goto bad;
    Py_DECREF(d);
    return 0;
bad:
    Py_XDECREF(d);
    return -1;
}
#endif

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(const char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;

    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(__pyx_filename);
    #else
    py_srcfile = PyUnicode_FromString(__pyx_filename);
    #endif
    if (!py_srcfile) goto bad;
    if (__pyx_clineno) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, __pyx_clineno);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, __pyx_clineno);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    py_code = PyCode_New(
        0,            
        #if PY_MAJOR_VERSION >= 3
        0,            
        #endif
        0,            
        0,            
        0,            
        __pyx_empty_bytes, 
        __pyx_empty_tuple,  
        __pyx_empty_tuple,  
        __pyx_empty_tuple,  
        __pyx_empty_tuple,  
        __pyx_empty_tuple,  
        py_srcfile,   
        py_funcname,  
        __pyx_lineno,   
        __pyx_empty_bytes  
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_GET(), 
        py_code,             
        py_globals,          
        0                    
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else  
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}



static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   if (x == Py_True) return 1;
   else if ((x == Py_False) | (x == Py_None)) return 0;
   else return PyObject_IsTrue(x);
}

static CYTHON_INLINE PyObject* __Pyx_PyNumber_Int(PyObject* x) {
  PyNumberMethods *m;
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_VERSION_HEX < 0x03000000
  if (PyInt_Check(x) || PyLong_Check(x))
#else
  if (PyLong_Check(x))
#endif
    return Py_INCREF(x), x;
  m = Py_TYPE(x)->tp_as_number;
#if PY_VERSION_HEX < 0x03000000
  if (m && m->nb_int) {
    name = "int";
    res = PyNumber_Int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = PyNumber_Long(x);
  }
#else
  if (m && m->nb_int) {
    name = "int";
    res = PyNumber_Long(x);
  }
#endif
  if (res) {
#if PY_VERSION_HEX < 0x03000000
    if (!PyInt_Check(res) && !PyLong_Check(res)) {
#else
    if (!PyLong_Check(res)) {
#endif
      PyErr_Format(PyExc_TypeError,
                   "__%s__ returned non-%s (type %.200s)",
                   name, name, Py_TYPE(res)->tp_name);
      Py_DECREF(res);
      return NULL;
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}

static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject* x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}

static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
#if PY_VERSION_HEX < 0x02050000
   if (ival <= LONG_MAX)
       return PyInt_FromLong((long)ival);
   else {
       unsigned char *bytes = (unsigned char *) &ival;
       int one = 1; int little = (int)*(unsigned char*)&one;
       return _PyLong_FromByteArray(bytes, sizeof(size_t), little, 0);
   }
#else
   return PyInt_FromSize_t(ival);
#endif
}

static CYTHON_INLINE size_t __Pyx_PyInt_AsSize_t(PyObject* x) {
   unsigned PY_LONG_LONG val = __Pyx_PyInt_AsUnsignedLongLong(x);
   if (unlikely(val == (unsigned PY_LONG_LONG)-1 && PyErr_Occurred())) {
       return (size_t)-1;
   } else if (unlikely(val != (unsigned PY_LONG_LONG)(size_t)val)) {
       PyErr_SetString(PyExc_OverflowError,
                       "value too large to convert to size_t");
       return (size_t)-1;
   }
   return (size_t)val;
}


#endif 
