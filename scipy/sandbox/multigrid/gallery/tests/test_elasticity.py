from scipy.testing import *

from scipy import matrix, array
from scipy.sparse import coo_matrix

from scipy.sandbox.multigrid.gallery.elasticity import linear_elasticity, \
        stima4

class TestLinearElasticity(TestCase):
    def test_1x1(self):
        A_expected = matrix ([[ 230769.23076923,       0.        ],
                              [      0.        ,  230769.23076923]])
        B_expected = array([[1, 0, 0],
                            [0, 1, 0]])

        A,B = linear_elasticity( (1,1), E=1e5, nu=0.3 )
        
        assert_almost_equal(A.todense(),A_expected)
        assert_almost_equal(B,B_expected)
    
    def test_1x1(self):

        data = array([ 230769.23076923,  -76923.07692308,   19230.76923077,
                       -28846.15384615,  -24038.46153846,  230769.23076923,
                        19230.76923077,  -76923.07692308,  -24038.46153846,
                       -28846.15384615,  -76923.07692308,  230769.23076923,
                       -28846.15384615,   24038.46153846,   19230.76923077,
                        19230.76923077,  230769.23076923,   24038.46153846,
                       -28846.15384615,  -76923.07692308,   19230.76923077,
                       -28846.15384615,   24038.46153846,  230769.23076923,
                       -76923.07692308,  -76923.07692308,   24038.46153846,
                       -28846.15384615,  230769.23076923,   19230.76923077,
                       -28846.15384615,  -24038.46153846,   19230.76923077,
                       -76923.07692308,  230769.23076923,  -24038.46153846,
                       -28846.15384615,  -76923.07692308,   19230.76923077,
                       230769.23076923])
        row = array([0, 2, 4, 6, 7, 1, 3, 5, 6, 7, 0, 2, 4, 5, 6, 1, 3, 4, 5, 7, 0, 2, 3, 4, 6, 1, 2, 3, 5, 7, 0, 1, 2, 4, 6, 0, 1, 3, 5, 7])
        col = array([0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7])

        A_expected = coo_matrix((data,(row,col)), shape=(8,8)).todense()
        B_expected = array([[ 1. ,  0. ,  0.5],
                            [ 0. ,  1. , -0.5],
                            [ 1. ,  0. ,  0.5],
                            [ 0. ,  1. ,  0.5],
                            [ 1. ,  0. , -0.5],
                            [ 0. ,  1. , -0.5],
                            [ 1. ,  0. , -0.5],
                            [ 0. ,  1. ,  0.5]])
        
        A,B = linear_elasticity( (2,2), E=1e5, nu=0.3 )

        assert_almost_equal(A.todense(),A_expected)
        assert_almost_equal(B,B_expected)

class TestLocalStiffnessMatrix(TestCase):
    def test_stima4(self):
        L = matrix([[  4,  3, -4,  3, -2, -3,  2, -3],
                    [  3,  4, -3,  2, -3, -2,  3, -4],
                    [ -4, -3,  4, -3,  2,  3, -2,  3],
                    [  3,  2, -3,  4, -3, -4,  3, -2],
                    [ -2, -3,  2, -3,  4,  3, -4,  3],
                    [ -3, -2,  3, -4,  3,  4, -3,  2],
                    [  2,  3, -2,  3, -4, -3,  4, -3],
                    [ -3, -4,  3, -2,  3,  2, -3,  4]]) / 12.0
        
        M = matrix([[  4,  1, -2, -1, -2, -1,  0,  1],
                    [  1,  4,  1,  0, -1, -2, -1, -2],
                    [ -2,  1,  4, -1,  0, -1, -2,  1],
                    [ -1,  0, -1,  4,  1, -2,  1, -2],
                    [ -2, -1,  0,  1,  4,  1, -2, -1],
                    [ -1, -2, -1, -2,  1,  4,  1,  0],
                    [  0, -1, -2,  1, -2,  1,  4, -1],
                    [  1, -2,  1, -2, -1,  0, -1,  4]]) / 4.0
        
        vertices = matrix([[ 0, 0],
                           [ 1, 0],
                           [ 1, 1],
                           [ 0, 1]])
        
        assert_almost_equal( stima4(vertices, 1, 0) , L)
        assert_almost_equal( stima4(vertices, 0, 1) , M)
        assert_almost_equal( stima4(vertices, 1, 1) , L + M)
           
        
           
        L = matrix([[ 2,  3, -2,  3, -1, -3,  1, -3],
                    [ 3,  8, -3,  4, -3, -4,  3, -8],
                    [-2, -3,  2, -3,  1,  3, -1,  3],
                    [ 3,  4, -3,  8, -3, -8,  3, -4],
                    [-1, -3,  1, -3,  2,  3, -2,  3],
                    [-3, -4,  3, -8,  3,  8, -3,  4],
                    [ 1,  3, -1,  3, -2, -3,  2, -3],
                    [-3, -8,  3, -4,  3,  4, -3,  8]]) / 12.0
        
        M = matrix([[ 4,  1,  0, -1, -2, -1, -2,  1],
                    [ 1,  6,  1,  2, -1, -3, -1, -5],
                    [ 0,  1,  4, -1, -2, -1, -2,  1],
                    [-1,  2, -1,  6,  1, -5,  1, -3],
                    [-2, -1, -2,  1,  4,  1,  0, -1],
                    [-1, -3, -1, -5,  1,  6,  1,  2],
                    [-2, -1, -2,  1,  0,  1,  4, -1],
                    [ 1, -5,  1, -3, -1,  2, -1,  6]]) / 4.0
        
        vertices = matrix([[ 0, 0],
                           [ 2, 0],
                           [ 2, 1],
                           [ 0, 1]])
        
        assert_almost_equal( stima4(vertices, 1, 0) , L)
        assert_almost_equal( stima4(vertices, 0, 1) , M)
        assert_almost_equal( stima4(vertices, 1, 1) , L + M)


if __name__ == '__main__':
    nose.run(argv=['', __file__])