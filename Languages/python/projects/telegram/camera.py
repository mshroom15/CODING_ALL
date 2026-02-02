import cv2

def take_photo(filename="photo.jpg"):
    cam = cv2.VideoCapture(0)
    
    # Warmup: Camera sensors need time to adjust light levels (Auto Exposure)
    # Reading a bunch of frames solves the "black image" issue
    for _ in range(30):
        cam.read()

    ret, frame = cam.read()
    if ret:
        cv2.imwrite(filename, frame)
    cam.release()
    return ret
