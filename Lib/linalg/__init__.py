""" Linear algebra routines.

 Solving Linear Systems:

   inv        --- Find the inverse of a square matrix
   solve      --- Solve a linear system of equations
   det        --- determinant of a matrix
   pinv       --- Moore-Penrose pseudo inverse (using least-squares)
   pinv2      --- Moore-Penrose pseudo inverse (using SVD)
   lstsq      --- Least-squares solve

 Matrix Factorizations:
 
   lu         --- LU decomposition
   cholesky   --- Cholesky factorization
   qr         --- QR factorization
   schur      --- Schur decomposition
   rsf2csf    --- Real to complex schur form.
   norm       --- vector and matrix norm
   eig        --- eigenvectors and eigenvalues
   eigvals    --- only eigenvalues
   svd        --- singular value decomposition

 Matrix Functions
 
   expm       --- exponential (using Pade approximation)
   cosm       --- cosine
   sinm       --- sine
   tanm       --- tangent
   coshm      --- hyperbolic cosine
   sinhm      --- hyperbolic sine
   tanhm      --- hyperbolic tangent
   funm       --- arbitrary function 
"""

_modules = ['fblas', 'flapack', 'cblas', 'clapack']
_namespaces = ['linear_algebra']

__all__ = []
import scipy
scipy.modules2all(__all__, _modules, globals())
scipy.names2all(__all__, _namespaces, globals())
