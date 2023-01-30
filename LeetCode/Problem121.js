var maxProfit = function(prices) {
    let min = {value: prices[0], index: 0}, max = {value: prices[0], index: 0}, result = 0;
    for (let i = 0;i < prices.length;i++) {
        if ((max.index <= min.index && prices[i] > min.value) || (max.index >= min.index && prices[i] > max.value)) {
            max.value = prices[i];
            max.index = i;
        }
        
        if (prices[i] < min.value) {
            min.value = prices[i];
            min.index = i;
        }

        if (max.index > min.index && max.value - min.value > result) {
            result = max.value - min.value;
        }
    }
    return result;
};