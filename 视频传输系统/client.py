import socket
import cv2
import numpy as np

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = "192.168.1.108"  # 服务器地址
port = 9999  # 服务器端口
addc = (host, port)

cap = cv2.VideoCapture(0)
quality = 95  # 图像的质量
encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), quality]

while (cap.isOpened()):
    ret, frame = cap.read()

    if ret == True:
        img_encode = cv2.imencode(".jpg", frame, encode_param)[1]
        data_encode = np.array(img_encode)
        str_encode = data_encode.tostring()
        print(len(str_encode))
        client_socket.sendto(str_encode, addc)
    else:
        break

client_socket.close()