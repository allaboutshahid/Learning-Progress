import time
import functools

def retry(max_attempts=3, delay=1, exceptions=(Exception,)):
    def decorator(fn):
        @functools.wraps(fn)
        def wrapper(*args, **kwargs):
            attempts = 0
            while attempts < max_attempts:
                try:
                    return fn(*args, **kwargs)
                except exceptions as e:
                    attempts += 1
                    if attempts == max_attempts:
                        raise
                    print(f"Attempt {attempts} failed: {e}. Retrying in {delay}s...")
                    time.sleep(delay)
        return wrapper
    return decorator


@retry(max_attempts=3, delay=1, exceptions=(ValueError,))
def flaky_function(x):
    if x < 0:
        raise ValueError("Negative value!")
    return x * 2


if __name__ == "__main__":
    print(flaky_function(5))