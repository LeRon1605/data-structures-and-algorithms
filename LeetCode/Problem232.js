var MyQueue = function() {
    this.left = [];
    this.right = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    let length = this.left.length;
    for (let i = 0;i < length;i++) {
        this.right.push(this.left.pop());
    }
    this.right.push(x);
};

/**
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    let length = this.right.length;
    for (let i = 0;i < length;i++) {
        this.left.push(this.right.pop());
    }
    return this.left.pop();
};

/**
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    let length = this.right.length;
    for (let i = 0;i < length;i++) {
        this.left.push(this.right.pop());
    }
    return this.left[this.left.length - 1];
};

/**
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    return (this.right.length == 0 && this.left.length == 0);
};