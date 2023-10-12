function isPalindrome(str) { 
    var j = str.length-1 
    for(var i=0; i<str.length/2; i++){ 
        if(str[i]!=str[j]){ 
            return false; 
        } 
        j--; 
    } 
    return true; 
} 
  
var str1 = "racecar"; 
var str2 = "nitin"; 
var str3 = "Rama"; 
  
console.log(isPalindrome(str1)); 
console.log(isPalindrome(str2)); 
console.log(isPalindrome(str3));
