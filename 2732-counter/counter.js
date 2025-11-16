/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    var c=0;
    return function() {

        c+=1;
        return n+c-1;
    };
   
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */