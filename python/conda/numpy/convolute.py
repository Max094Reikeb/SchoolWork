import numpy as np

image = np.array([[50, 200, 235, 201], [15, 135, 88, 100], [0, 42, 77, 165], [6, 108, 250, 144]])
convolute = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])


def getConvolute(img, kernel):
    """
    Gets the convolute sum for a 3x3 image and convolute
    :param img: Image matrix
    :param kernel: Convolute matrix
    :return: Convolute sum
    """
    kernel_height, kernel_width = kernel.shape
    image_height, image_width = img.shape

    pad_height = kernel_height // 2
    pad_width = kernel_width // 2
    padded_height = image_height - (2 * pad_height)
    padded_width = image_width - (2 * pad_width)
    padded_image = np.zeros((padded_height, padded_width))

    for i in range(1, image_height - 1):
        for j in range(1, image_width - 1):
            padded_image[i-1, j-1] = np.sum(kernel * img[i-1:i+2, j-1:j+2])
    return padded_image


print("Sum convolute", getConvolute(image, convolute))
