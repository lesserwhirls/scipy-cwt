import _minpack
from common_routines import *

def fsolve(func,x0,args=(),Dfun=None,full_output=0,col_deriv=0,xtol=1.49012e-8,maxfev=0,band=None,epsfcn=0.0,factor=100,diag=None):
    """
 fsolve(func, x0, args=(), Dfun=None, full_output=0, col_deriv=0,
        xtol=1.49012e-8, maxfev=0, band=None, epsfcn=0.0, factor=100,
        diag=None)

  Description:

    Return the roots of the (non-linear) equations defined by
    func(x)=0 given a starting estimate.

  Inputs:

    func -- A Python function or method which takes at least one
            (possibly vector) argument.
    x0 -- The starting estimate for the roots of func(x)=0.
    args -- Any extra arguments to func are placed in this tuple.
    Dfun -- A function or method to compute the Jacobian of func with
            derivatives across the rows. If this is None, the
            Jacobian will be estimated.
    full_output -- non-zero to return the optional outputs.
    col_deriv -- non-zero to specify that the Jacobian function
                 computes derivatives down the columns (faster, because
                 there is no transpose operation).

  Outputs: (x, {infodict, ier, mesg})

    x -- the solution (or the result of the last iteration for an
         unsuccessful call.

    infodict -- a dictionary of optional outputs with the keys:
                'nfev' : the number of function calls
                'njev' : the number of jacobian calls
                'fvec' : the function evaluated at the output
                'fjac' : the orthogonal matrix, q, produced by the
                         QR facotrization of the final approximate
                         Jacobi matrix, stored column wise.
                'r'    : upper triangular matrix produced by QR
                         factorization of same matrix.
                'qtf'  : the vector (transpose(q) * fvec).
    ier -- an integer flag.  If it is equal to 1 the solution was
           found.  If it is not equal to 1, the solution was not
           found and the following message gives more information.
    mesg -- a string message giving information about the cause of
            failure.

  Extended Inputs:
  
   xtol -- The calculation will terminate if the relative error
           between two consecutive iterates is at most xtol.
   maxfev -- The maximum number of calls to the function. If zero,
             then 100*(N+1) is the maximum where N is the number
             of elements in x0.
   band -- If set to a two-sequence containing the number of sub-
           and superdiagonals within the band of the Jacobi matrix,
           the Jacobi matrix is considered banded (only for Dfun=None).
   epsfcn -- A suitable step length for the forward-difference
             approximation of the Jacobian (for Dfun=None). If
             epsfcn is less than the machine precision, it is assumed
             that the relative errors in the functions are of
             the order of the machine precision.
   factor -- A parameter determining the initial step bound
             (factor * || diag * x||). Should be in interval (0.1,100).
   diag -- A sequency of N positive entries that serve as a
           scale factors for the variables.

  Remarks:

    "fsolve" is a wrapper around MINPACK's hybrd and hybrj algorithms.

    """
    x0 = myasarray(x0)
    n = len(x0)
    if type(args) != type(()): args = (args,)
    check_func(func,x0,args,n,(n,))
    if Dfun == None:
        if band == None:
            ml,mu = -10,-10
        else:
            ml,mu = band[:2]
        if (maxfev == 0):
            maxfev = 200*(n+1)
        retval = _minpack._hybrd(func,x0,args,full_output,xtol,maxfev,ml,mu,epsfcn,factor,diag)
    else:
        check_func(Dfun,x0,args,n,(n,n))
        if (maxfev == 0):
            maxfev = 100*(n+1)
        retval = _minpack._hybrj(func,Dfun,x0,args,full_output,col_deriv,xtol,maxfev,factor,diag)

    errors = {0:["Improper input parameters were entered.",TypeError],
              1:["The solution converged.",None],
              2:["The number of calls to function has reached maxfev = %d." % maxfev, ValueError],
              3:["xtol=%f is too small, no further improvement in the approximate\n  solution is possible." % xtol, ValueError],
              4:["The iteration is not making good progress, as measured by the \n  improvement from the last five Jacobian evaluations.", ValueError],
              5:["The iteration is not making good progress, as measured by the \n  improvement from the last ten iterations.", ValueError],
              'unknown': ["An error occurred.", TypeError]}

    info = retval[-1]    # The FORTRAN return value
    if (info != 1 and not full_output):
        if info in [2,3,4,5]:
            print "Warning: " + errors[info][0]
        else:
            try:
                raise errors[info][1], errors[info][0]
            except KeyError:
                raise errors['unknown'][1], errors['unknown'][0]

    if n == 1:
        retval = (retval[0][0],) + retval[1:]

    if full_output:
        try:
            return retval + (errors[info][0],)  # Return all + the message
        except KeyError:
            return retval + (errors['unknown'][0],)
    else:
        return retval[0]


def leastsq(func,x0,args=(),Dfun=None,full_output=0,col_deriv=0,ftol=1.49012e-8,xtol=1.49012e-8,gtol=0.0,maxfev=0,epsfcn=0.0,factor=100,diag=None):
    """
 leastsq(func, x0, args=(), Dfun=None, full_output=0, col_deriv=0,
         ftol=1.49012e-8, xtol=1.49012e-8, gtol=0.0, maxfev=0,
         epsfcn=0.0, factor=100, diag=None)

  Description:

    Return the point which minimizes the sum of squares of M
    (non-linear) equations in N unknowns given a starting estimate, x0,
    using a modification of the Levenberg-Marquardt algorithm.

                    x = arg min(sum(func(y)**2))
                             y

  Inputs:

    func -- A Python function or method which takes at least one
            (possibly length N vector) argument and returns M
            floating point numbers.
    x0 -- The starting estimate for the minimization.
    args -- Any extra arguments to func are placed in this tuple.
    Dfun -- A function or method to compute the Jacobian of func with
            derivatives across the rows. If this is None, the
            Jacobian will be estimated.
    full_output -- non-zero to return the optional outputs.
    col_deriv -- non-zero to specify that the Jacobian function
                 computes derivatives down the columns (faster, because
                 there is no transpose operation).

  
  Outputs: (x, {infodict, ier, mesg})

    x -- the solution (or the result of the last iteration for an
         unsuccessful call.

    infodict -- a dictionary of optional outputs with the keys:
                'nfev' : the number of function calls
                'njev' : the number of jacobian calls
                'fvec' : the function evaluated at the output
                'fjac' : the orthogonal matrix, q, produced by the
                         QR facotrization of the final approximate
                         Jacobi matrix, stored column wise.
                'ipvt' : an integer array of length N which defines
                         a permutation matrix, p, such that
                         fjac*p = q*r, where r is upper triangular
                         with diagonal elements of nonincreasing
                         magnitude. Column j of p is column ipvt(j)
                         of the identity matrix.
                'qtf'  : the vector (transpose(q) * fvec).
    ier -- an integer flag.  If it is equal to 1 the solution was
           found.  If it is not equal to 1, the solution was not
           found and the following message gives more information.
    mesg -- a string message giving information about the cause of
            failure.

  Extended Inputs:
  
   ftol -- Relative error desired in the sum of squares.
   xtol -- Relative error desired in the approximate solution.
   gtol -- Orthogonality desired between the function vector
           and the columns of the Jacobian.
   maxfev -- The maximum number of calls to the function. If zero,
             then 100*(N+1) is the maximum where N is the number
             of elements in x0.
   epsfcn -- A suitable step length for the forward-difference
             approximation of the Jacobian (for Dfun=None). If
             epsfcn is less than the machine precision, it is assumed
             that the relative errors in the functions are of
             the order of the machine precision.
   factor -- A parameter determining the initial step bound
             (factor * || diag * x||). Should be in interval (0.1,100).
   diag -- A sequency of N positive entries that serve as a
           scale factors for the variables.

  Remarks:

    "leastsq" is a wrapper around MINPACK's lmdif and lmder algorithms.

    """
    x0 = myasarray(x0)
    n = len(x0)
    if type(args) != type(()): args = (args,)
    m = check_func(func,x0,args,n)[0]
    if Dfun == None:
        if (maxfev == 0):
            maxfev = 200*(n+1)
        retval = _minpack._lmdif(func,x0,args,full_output,ftol,xtol,gtol,maxfev,epsfcn,factor,diag)
    else:
        if col_deriv:
            check_func(func,x0,args,n,(n,m))
        else:
            check_func(func,x0,args,n,(m,n))
        if (maxfev == 0):
            maxfev = 100*(n+1)
        retval = _minpack._lmder(func,Dfun,x0,args,full_output,col_deriv,ftol,xtol,gtol,maxfev,factor,diag)

    errors = {0:["Improper input parameters.", TypeError],
              1:["Both actual and predicted relative reductions in the sum of squares\n  are at most %f" % ftol, None],
              2:["The relative error between two consecutive iterates is at most %f" % xtol, None],
              3:["Both actual and predicted relative reductions in the sum of squares\n  are at most %f and the relative error between two consecutive iterates is at \n  most %f" % (ftol,xtol), None],
              4:["The cosine of the angle between func(x) and any column of the\n  Jacobian is at most %f in absolute value", gtol, None],
              5:["Number of calls to function has reached maxfev = %d." % maxfev, ValueError],
              6:["ftol=%f is too small, no further reduction in the sum of squares\n  is possible.""" % ftol, ValueError],
              7:["xtol=%f is too small, no further improvement in the approximate\n  solution is possible." % xtol, ValueError],
              8:["gtol=%f is too small, func(x) is orthogonal to the columns of\n  the Jacobian to machine precision." % gtol, ValueError],
              'unknown':["Unknown error.", TypeError]}

    info = retval[-1]    # The FORTRAN return value

    if (info not in [1,2,3,4] and not full_output):
        if info in [5,6,7,8]:
            print "Warning: " + errors[info][0]
        else:
            try:
                raise errors[info][1], errors[info][0]
            except KeyError:
                raise errors['unknown'][1], errors['unknown'][0]

    if n == 1:
        retval = (retval[0][0],) + retval[1:]

    if full_output:
        return retval + (errors[info][0],)
    else:
        return retval[:-1] + (errors[info][0],)


def check_gradient(fcn,Dfcn,x0,col_deriv=0):
    """good,err = check_gradient(fun,Dfun,x0,col_deriv=0)"""

    x = myasarray(x0)
    n = len(x)
    x.shape = (n,)
    fvec = myasarray(fcn(x))
    if 1 not in fvec.shape:
        raise ValueError, "Function does not return a 1-D array."
    m = len(fvec)
    fvec.shape = (m,)
    ldfjac = m
    fjac = myasarray(Dfcn(x))
    fjac.shape = (m,n)
    if col_deriv == 0:
        fjac = transpose(fjac)

    xp = zeros((n,),Float64)
    err = zeros((m,),Float64)
    fvecp = None
    _minpack._chkder(m,n,x,fvec,fjac,ldfjac,xp,fvecp,1,err)
    
    fvecp = myasarray(fcn(xp))
    fvecp.shape = (m,)
    _minpack._chkder(m,n,x,fvec,fjac,ldfjac,xp,fvecp,2,err)
    
    good = (product(greater(err,0.5)))

    return (good,err)













