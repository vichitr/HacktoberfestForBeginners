class Polygon {
    constructor(sideLengths) {
        this.sideLengths = sideLengths;
    }

    perimeter() {
        return this.sideLengths.reduce((a, b) => a + b);
    }
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
const rectangle = new Polygon([10, 20, 10, 20]);
const square = new Polygon([10, 10, 10, 10]);
const pentagon = new Polygon([10, 20, 30, 40, 43]);

console.log(rectangle.perimeter());
console.log(square.perimeter());
console.log(pentagon.perimeter());
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
