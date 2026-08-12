import time

class TTLCache:
    """A simple cache with time-to-live expiration."""

    def __init__(self, ttl=60):
        self.ttl = ttl
        self.store = {}

    def set(self, key, value):
        self.store[key] = (value, time.time())

    def get(self, key):
        if key not in self.store:
            return None
        value, timestamp = self.store[key]
        if time.time() - timestamp > self.ttl:
            del self.store[key]
            return None
        return value

    def clear_expired(self):
        now = time.time()
        expired = [k for k, (_, t) in self.store.items() if now - t > self.ttl]
        for k in expired:
            del self.store[k]


if __name__ == "__main__":
    cache = TTLCache(ttl=5)
    cache.set("user_1", {"name": "Abdul"})
    print(cache.get("user_1"))