// Generate a psuedo-random integer array of a given length and maximum value for rapid testing purposes.
function makeArrayN(length, max) {
  const arr = [];
  for (let i = 0; i < length; i++) {
      arr.push(Math.round(Math.random() * max));
  }
  return arr;
}