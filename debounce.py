import time
from functools import wraps

def debounce(wait):
    """Decorator that delays function execution until `wait` seconds
    have passed since the last call."""
    def decorator(fn):
        last_call = [0]

        @wraps(fn)
        def wrapper(*args, **kwargs):
            now = time.time()
            if now - last_call[0] >= wait:
                last_call[0] = now
                return fn(*args, **kwargs)
        return wrapper
    return decorator


@debounce(2)
def save_data(x):
    print(f"Saving: {x}")


if __name__ == "__main__":
    for i in range(5):
        save_data(i)
        time.sleep(0.5)