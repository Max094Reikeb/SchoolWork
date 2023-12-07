import numpy as np
import time

large_array1 = range(1000000000)
large_array2 = range(1000000000)

start_time = time.time()
result_python = [x + y for x, y in zip(large_array1, large_array2)]
end_time = time.time()
python_time = end_time - start_time

print(f"Temps pour l'addition avec Python : {python_time:.6f} secondes")

large_np_array1 = np.array(large_array1)
large_np_array2 = np.array(large_array2)

start_time = time.time()
result_numpy = large_np_array1 + large_np_array2
end_time = time.time()
numpy_time = end_time - start_time

print(f"Temps pour l'addition avec NumPy : {numpy_time:.6f} secondes")
