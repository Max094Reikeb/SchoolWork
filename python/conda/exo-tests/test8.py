import numpy

vec = numpy.array([[3.0], [1.0]])
vec = 1 + 2 * vec
print(vec.shape)

mat = numpy.random.randn(2, 2)
print(mat.shape)

vec2 = numpy.matmul(mat, vec)
print(vec2.shape)
