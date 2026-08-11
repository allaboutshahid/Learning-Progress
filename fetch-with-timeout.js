async function fetchWithTimeout(url, options = {}, timeout = 5000) {
  const controller = new AbortController();
  const id = setTimeout(() => controller.abort(), timeout);

  try {
    const response = await fetch(url, {
      ...options,
      signal: controller.signal,
    });
    clearTimeout(id);
    return response;
  } catch (err) {
    clearTimeout(id);
    if (err.name === "AbortError") {
      throw new Error(`Request timed out after ${timeout}ms`);
    }
    throw err;
  }
}

// Example usage
fetchWithTimeout("https://api.example.com/data", {}, 3000)
  .then((res) => res.json())
  .then((data) => console.log(data))
  .catch((err) => console.error(err.message));

module.exports = fetchWithTimeout;