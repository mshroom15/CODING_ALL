from camera import take_photo
from telegram import send_photo, wait_for_reply, ask_yes_no, flush_updates
import os

if __name__ == "__main__":
    if os.path.exists("photo.jpg"):
        os.remove("photo.jpg")
    input("Press ENTER to take photo...")

    try:
        if take_photo():
            flush_updates()
            send_photo("photo.jpg")
            ask_yes_no()
            result = wait_for_reply()

            print("Telegram decision:", result)
        else:
            print("Camera failed")
    except Exception as e:
        print(f"An error occurred: {e}")
