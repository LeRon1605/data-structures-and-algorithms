var countOdds = function(low, high) {
    return Math.floor((high - low) / 2) + ((high % 2 == 1 || low % 2 == 1) ? 1 : 0);
};