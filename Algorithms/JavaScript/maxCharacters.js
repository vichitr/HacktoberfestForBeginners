const maxCharacter = (string) => {
  const characters = {};

  for (let character of string)
    characters[character] = characters[character] + 1 || 1;

  let maxCount = 0;
  let maxCharacter = null;

  for (let character in characters) {
    if (characters[character] > maxCount) {
      maxCount = characters[character];
      maxCharacter = character;
    }
  }

  return maxCharacter;
};

export default maxCharacter;
