function isPalindrome(str) {
    str = str.toLowerCase();
    let strArr = str.split(/\W/);
    let newStr = strArr.join('');
    
    if(newStr === newStr.split('').reverse().join('')) {
        console.log(true);
    } else {
        console.log(false);
    }
}

isPalindrome("Madam, I'm Adam");  // true
isPalindrome("racecar");          // true
isPalindrome("hacktoberfest");    // false
