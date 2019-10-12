function quadratic_zero(a,b,c){
    let d = -b;
    let root = (b*b) - (4*(a*c));
    if(Math.sign(root) === -1){
        console.log("Quadratic doesn't hit the x Axis");
    }else{
        let numerator1 = d + root;
        let numerator2 = d - root;
        let denominator = 2*a;
        let zero1= numerator1/denominator;
        let zero2 = numerator2/denominator;
        console.log("Zeros:"+zero1 +" "+ zero2);
    }
}