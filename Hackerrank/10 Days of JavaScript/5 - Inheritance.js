/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
class Rectangle {
    constructor(w, h) {
        this.w = w;
        this.h = h;
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

Rectangle.prototype.area = function () {
    return this.w * this.h;
}

class Square extends Rectangle {
    constructor(sideLength) {
        super(sideLength, sideLength);
    }
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
if (JSON.stringify(Object.getOwnPropertyNames(Square.prototype)) === JSON.stringify([ 'constructor' ])) {
    const rec = new Rectangle(3, 4);
    const sqr = new Square(3);

    console.log(rec.area());
    console.log(sqr.area());
} else {
    console.log(-1);
    console.log(-1);
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
