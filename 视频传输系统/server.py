import socket
import cv2
import numpy as np

serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = "192.168.1.108"  # 服务器地址
port = 9999  # 服务器端口
serversocket.bind((host, port))

while True:
    bufSize = 1024 * 1024
    image_buf, _ = serversocket.recvfrom(bufSize)
    print(len(image_buf))
    data = np.fromstring(image_buf, np.uint8)
    img_decode = cv2.imdecode(data, cv2.IMREAD_COLOR)
    cv2.imshow('SERVER', img_decode)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

serversocket.close()