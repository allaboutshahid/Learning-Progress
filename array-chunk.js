function chunkArray(arr, size) {
  if (size <= 0) throw new Error("Size must be greater than 0");
  const result = [];
  for (let i = 0; i < arr.length; i += size) {
    result.push(arr.slice(i, i + size));
  }
  return result;
}

// Example
console.log(chunkArray([1, 2, 3, 4, 5, 6, 7], 3));
// [[1,2,3],[4,5,6],[7]]

module.exports = chunkArray;