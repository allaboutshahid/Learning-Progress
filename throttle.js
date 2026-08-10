function throttle(fn, limit) {
  let inThrottle = false;
  return function (...args) {
    if (!inThrottle) {
      fn.apply(this, args);
      inThrottle = true;
      setTimeout(() => (inThrottle = false), limit);
    }
  };
}

// Example usage
window.addEventListener(
  "scroll",
  throttle(() => console.log("Scroll event:", Date.now()), 300)
);
module.exports = throttle;