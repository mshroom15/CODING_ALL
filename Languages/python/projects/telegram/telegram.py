import requests
import time

BOT_TOKEN = "token"
CHAT_ID = "id"

def send_photo(photo_path):
    url = f"https://api.telegram.org/bot{BOT_TOKEN}/sendPhoto"
    with open(photo_path, "rb") as photo:
        requests.post(url, data={"chat_id": CHAT_ID}, files={"photo": photo})

def ask_yes_no():
    url = f"https://api.telegram.org/bot{BOT_TOKEN}/sendMessage"
    requests.post(url, data={
        "chat_id": CHAT_ID,
        "text": "Do you approve? Reply with YES or NO."
    })

def flush_updates():
    url = f"https://api.telegram.org/bot{BOT_TOKEN}/getUpdates"
    # Fetch updates to see the latest ID
    response = requests.get(url).json()
    if "result" in response and response["result"]:
        last_update_id = response["result"][-1]["update_id"]
        # Call again with offset to mark them as read
        requests.get(url, params={"offset": last_update_id + 1})

def wait_for_reply():
    url = f"https://api.telegram.org/bot{BOT_TOKEN}/getUpdates"
    last_update_id = None

    while True:
        try:
            params = {"timeout": 10}
            if last_update_id:
                params["offset"] = last_update_id + 1
            
            response = requests.get(url, params=params).json()
            
            if "result" in response:
                for update in response["result"]:
                    last_update_id = update["update_id"]

                    if "message" in update:
                        text = update["message"].get("text", "").lower().strip()
                        if text in ["yes", "y"]:
                            return True
                        if text in ["no", "n"]:
                            return False
        except Exception as e:
            print(f"Error checking Telegram: {e}")
            time.sleep(2)  # Avoid hammering the API on failure

        time.sleep(1)
